#!/usr/bin/env bash
# Quick Build Test - Verify Bazel build system works
# ===================================================

set -e

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
NC='\033[0m'

echo ""
echo -e "${CYAN}========================================${NC}"
echo -e "${CYAN}  Quick Build Test${NC}"
echo -e "${CYAN}========================================${NC}"
echo ""

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

cd "$PROJECT_ROOT"

# Test 1: Build Exercise 01
echo -e "${YELLOW}📦 Building Exercise 01 (Basic Safety)...${NC}"
if bazel build //exercises/01_basic_safety:all; then
    echo -e "${GREEN}✓ Exercise 01 build successful${NC}"
else
    echo -e "${RED}✗ Exercise 01 build failed${NC}"
    exit 1
fi

# Test 2: Run violation example
echo ""
echo -e "${YELLOW}🔍 Testing violation example...${NC}"
if bazel run //exercises/01_basic_safety:violation_example > /dev/null 2>&1; then
    echo -e "${GREEN}✓ Violation example runs successfully${NC}"
else
    echo -e "${RED}✗ Violation example failed${NC}"
    exit 1
fi

# Test 3: Run compliant example
echo ""
echo -e "${YELLOW}✅ Testing compliant example...${NC}"
if bazel run //exercises/01_basic_safety:compliant_example > /dev/null 2>&1; then
    echo -e "${GREEN}✓ Compliant example runs successfully${NC}"
else
    echo -e "${RED}✗ Compliant example failed${NC}"
    exit 1
fi

# Success
echo ""
echo -e "${CYAN}========================================${NC}"
echo -e "${GREEN}✅ All quick tests passed!${NC}"
echo -e "${CYAN}========================================${NC}"
echo ""
echo -e "${GREEN}🎉 Your build system is working correctly!${NC}"
echo ""
echo -e "${YELLOW}Next steps:${NC}"
echo "  • Run full test suite: bazel test //..."
echo "  • Start Exercise 01: cd exercises/01_basic_safety"
echo "  • Read GETTING_STARTED.md for detailed instructions"
echo ""
