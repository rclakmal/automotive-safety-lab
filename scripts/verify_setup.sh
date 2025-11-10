#!/usr/bin/env bash
# Automotive Safety Lab - Setup Verification Script (Bash)
# ==========================================================
# This script verifies that your development environment is properly
# configured for the ISO 26262 Safety Lab exercises.

set -e

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
GRAY='\033[0;90m'
NC='\033[0m' # No Color

ALL_CHECKS_PASS=true

echo ""
echo -e "${CYAN}================================================${NC}"
echo -e "${CYAN}  Automotive Safety Lab - Setup Verification${NC}"
echo -e "${CYAN}================================================${NC}"
echo ""

# Function to check if a command exists
command_exists() {
    command -v "$1" &> /dev/null
}

# Function to print check result
check_result() {
    local name="$1"
    local success="$2"
    local details="$3"
    
    if [ "$success" = "true" ]; then
        echo -e "[${GREEN}✓${NC}] $name${details:+ - ${GRAY}$details${NC}}"
    else
        echo -e "[${RED}✗${NC}] $name${details:+ - ${RED}$details${NC}}"
        ALL_CHECKS_PASS=false
    fi
}

# Check 1: Bazel
echo -e "\n${YELLOW}📦 Checking Build System...${NC}"
if command_exists bazel; then
    BAZEL_VERSION=$(bazel --version 2>&1 | sed 's/bazel //')
    check_result "Bazel installation" "true" "version $BAZEL_VERSION"
else
    check_result "Bazel installation" "false" "Not found. Install from https://bazel.build/install"
fi

# Check 2: C/C++ Compiler
echo -e "\n${YELLOW}🔨 Checking C/C++ Compiler...${NC}"
COMPILER_FOUND=false

if command_exists gcc; then
    GCC_VERSION=$(gcc --version 2>&1 | head -n1 | sed 's/gcc //' | sed 's/ .*//')
    check_result "GCC compiler" "true" "version $GCC_VERSION"
    COMPILER_FOUND=true
elif command_exists clang; then
    CLANG_VERSION=$(clang --version 2>&1 | head -n1 | sed 's/clang version //' | sed 's/ .*//')
    check_result "Clang compiler" "true" "version $CLANG_VERSION"
    COMPILER_FOUND=true
else
    check_result "C/C++ compiler" "false" "Neither GCC nor Clang found"
fi

# Check 3: Git
echo -e "\n${YELLOW}🌿 Checking Version Control...${NC}"
if command_exists git; then
    GIT_VERSION=$(git --version 2>&1 | sed 's/git version //')
    check_result "Git installation" "true" "version $GIT_VERSION"
else
    check_result "Git installation" "false" "Not found. Install from https://git-scm.com/"
fi

# Check 4: Project Structure
echo -e "\n${YELLOW}📁 Checking Project Structure...${NC}"
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

REQUIRED_DIRS=("exercises" "docs" "tests" "tools")
for dir in "${REQUIRED_DIRS[@]}"; do
    if [ -d "$PROJECT_ROOT/$dir" ]; then
        check_result "Directory: $dir" "true" ""
    else
        check_result "Directory: $dir" "false" "Missing"
    fi
done

# Check 5: Bazel Configuration
echo -e "\n${YELLOW}⚙️  Checking Bazel Configuration...${NC}"
if [ -f "$PROJECT_ROOT/WORKSPACE" ]; then
    check_result "WORKSPACE file" "true" ""
else
    check_result "WORKSPACE file" "false" "Missing"
fi

if [ -f "$PROJECT_ROOT/BUILD" ]; then
    check_result "BUILD file" "true" ""
else
    check_result "BUILD file" "false" "Missing"
fi

# Check 6: Exercise Files
echo -e "\n${YELLOW}📚 Checking Exercise Files...${NC}"
EXERCISE_DIRS=(
    "exercises/01_basic_safety"
    "exercises/02_watchdog_timer"
    "exercises/03_memory_protection"
    "exercises/04_redundancy_voting"
    "exercises/05_critical_systems"
)

EXERCISE_COUNT=0
for ex_dir in "${EXERCISE_DIRS[@]}"; do
    if [ -d "$PROJECT_ROOT/$ex_dir" ]; then
        ((EXERCISE_COUNT++))
    fi
done

if [ $EXERCISE_COUNT -eq 5 ]; then
    check_result "Exercise directories" "true" "Found $EXERCISE_COUNT/5"
else
    check_result "Exercise directories" "false" "Found $EXERCISE_COUNT/5"
fi

# Check 7: Optional Tools
echo -e "\n${YELLOW}🔧 Checking Optional Tools...${NC}"
if command_exists python3 || command_exists python; then
    PYTHON_CMD=$(command_exists python3 && echo "python3" || echo "python")
    PYTHON_VERSION=$($PYTHON_CMD --version 2>&1 | sed 's/Python //')
    echo -e "[${BLUE}i${NC}] Python (optional) - ${GRAY}version $PYTHON_VERSION${NC}"
else
    echo -e "[${BLUE}i${NC}] ${GRAY}Python (optional) - Not found (recommended for analysis tools)${NC}"
fi

if command_exists cppcheck; then
    echo -e "[${BLUE}i${NC}] ${GRAY}cppcheck (optional) - Found (great for static analysis!)${NC}"
else
    echo -e "[${BLUE}i${NC}] ${GRAY}cppcheck (optional) - Not found (recommended for code quality)${NC}"
fi

# Final Summary
echo ""
echo -e "${CYAN}================================================${NC}"
if [ "$ALL_CHECKS_PASS" = "true" ]; then
    echo -e "${GREEN}  ✅ Setup Verification: PASSED${NC}"
    echo -e "${CYAN}================================================${NC}"
    echo ""
    echo -e "${GREEN}🎉 Your environment is ready!${NC}"
    echo ""
    echo -e "${YELLOW}Next Steps:${NC}"
    echo -e "  1. ${NC}Read GETTING_STARTED.md for detailed instructions"
    echo -e "  2. ${NC}Run: ${CYAN}bazel build //exercises/01_basic_safety:all${NC}"
    echo -e "  3. ${NC}Start learning with Exercise 01!"
    echo ""
    exit 0
else
    echo -e "${RED}  ❌ Setup Verification: FAILED${NC}"
    echo -e "${CYAN}================================================${NC}"
    echo ""
    echo -e "${RED}⚠️  Some checks failed. Please review the errors above.${NC}"
    echo ""
    echo -e "${YELLOW}Need help? Check:${NC}"
    echo -e "  • ${NC}GETTING_STARTED.md - Installation instructions"
    echo -e "  • ${NC}docs/TROUBLESHOOTING.md - Common issues and solutions"
    echo -e "  • ${NC}GitHub Issues: https://github.com/rclakmal/automotive-safety-lab/issues"
    echo ""
    exit 1
fi
