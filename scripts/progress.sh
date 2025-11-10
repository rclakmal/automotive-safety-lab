#!/usr/bin/env bash
# Learning Progress Dashboard
# ===========================
# Track your journey through the ISO 26262 Safety Lab

set -e

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
GRAY='\033[0;90m'
NC='\033[0m'

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

echo ""
echo -e "${CYAN}╔════════════════════════════════════════════════╗${NC}"
echo -e "${CYAN}║                                                ║${NC}"
echo -e "${CYAN}║    ${NC}${YELLOW}Automotive Safety Lab${NC}${CYAN}                  ║${NC}"
echo -e "${CYAN}║    ${NC}${GRAY}ISO 26262 Learning Progress${NC}${CYAN}             ║${NC}"
echo -e "${CYAN}║                                                ║${NC}"
echo -e "${CYAN}╚════════════════════════════════════════════════╝${NC}"
echo ""

# Function to check if exercise is complete
check_exercise() {
    local ex_num="$1"
    local ex_name="$2"
    local ex_dir="$PROJECT_ROOT/exercises/$ex_num"
    
    # Check if both violation and compliant examples can be built
    if [ -d "$ex_dir" ]; then
        cd "$PROJECT_ROOT"
        if bazel build "//$ex_dir:all" &> /dev/null; then
            return 0  # Complete
        fi
    fi
    return 1  # Incomplete
}

# Exercise definitions
declare -A exercises=(
    ["01_basic_safety"]="ASIL QM|Basic Safety Concepts|Battery Monitoring"
    ["02_watchdog_timer"]="ASIL A|Watchdog Timer Systems|Engine Control"
    ["03_memory_protection"]="ASIL B|Memory Protection|Electronic Brake System"
    ["04_redundancy_voting"]="ASIL C|Redundancy & Voting|Power Steering"
    ["05_critical_systems"]="ASIL D|Critical Systems|Autonomous Braking"
)

total_exercises=5
completed=0
current_exercise=""

# Check each exercise
for ex_id in "01_basic_safety" "02_watchdog_timer" "03_memory_protection" "04_redundancy_voting" "05_critical_systems"; do
    IFS='|' read -r asil name scenario <<< "${exercises[$ex_id]}"
    
    if check_exercise "$ex_id" "$name"; then
        echo -e "${GREEN}✓${NC} ${BLUE}$asil${NC} - ${NC}$name ($scenario)"
        ((completed++))
    else
        if [ -z "$current_exercise" ]; then
            echo -e "${YELLOW}→${NC} ${BLUE}$asil${NC} - ${NC}$name ($scenario) ${YELLOW}← NEXT${NC}"
            current_exercise="$ex_id"
        else
            echo -e "${GRAY}○${NC} ${GRAY}$asil - $name ($scenario)${NC}"
        fi
    fi
done

# Progress bar
echo ""
echo -e "${CYAN}Progress:${NC}"
progress_percent=$((completed * 100 / total_exercises))
bar_length=40
filled_length=$((completed * bar_length / total_exercises))
bar=""
for ((i=0; i<bar_length; i++)); do
    if [ $i -lt $filled_length ]; then
        bar+="█"
    else
        bar+="░"
    fi
done
echo -e "[${GREEN}$bar${NC}] $completed/$total_exercises exercises ($progress_percent%)"

# Status message
echo ""
if [ $completed -eq 0 ]; then
    echo -e "${YELLOW}🚀 Ready to start your journey!${NC}"
    echo ""
    echo -e "${NC}Your first step:${NC}"
    echo -e "  cd exercises/01_basic_safety"
    echo -e "  cat README.md"
    echo ""
elif [ $completed -eq $total_exercises ]; then
    echo -e "${GREEN}🎉 Congratulations! You've completed all exercises!${NC}"
    echo ""
    echo -e "${YELLOW}What's next:${NC}"
    echo "  • Review your notes and learnings"
    echo "  • Try the integration test suite: bazel test //tests/integration:all"
    echo "  • Apply for ISO 26262 certification"
    echo "  • Contribute back to the project!"
    echo ""
else
    echo -e "${YELLOW}💪 Keep going! You're making great progress!${NC}"
    echo ""
    echo -e "${NC}Next exercise:${NC}"
    echo -e "  cd exercises/$current_exercise"
    echo -e "  cat README.md"
    echo ""
fi

# Quick stats
echo -e "${CYAN}═══════════════════════════════════════════════${NC}"
echo -e "${GRAY}Time invested: ~$((completed * 4)) hours | Remaining: ~$((($total_exercises - completed) * 4)) hours${NC}"
echo -e "${CYAN}═══════════════════════════════════════════════${NC}"
echo ""
