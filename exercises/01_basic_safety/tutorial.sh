#!/bin/bash
# Interactive Tutorial for Exercise 01: Basic Safety Concepts
# ===========================================================

set -e

# Colors for better user experience
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Tutorial state
EXERCISE_DIR="$(dirname "$0")"
PROGRESS_FILE="$HOME/.iso26262_progress"

clear

echo -e "${BLUE}╔═══════════════════════════════════════════════════════════════════════════════╗"
echo -e "║                    ISO 26262 Exercise 01: Basic Safety Concepts              ║"
echo -e "║                           Interactive Learning Tutorial                        ║"
echo -e "╚═══════════════════════════════════════════════════════════════════════════════╝${NC}"
echo ""

# Check if this is first time running
if [[ ! -f "$PROGRESS_FILE" ]]; then
    echo "# ISO 26262 Learning Progress" > "$PROGRESS_FILE"
    echo "start_date=$(date)" >> "$PROGRESS_FILE"
    echo ""
    echo -e "${GREEN}🎓 Welcome to your ISO 26262 Safety Engineering journey!${NC}"
    echo ""
    echo "This interactive tutorial will guide you through:"
    echo "• Understanding functional safety principles"
    echo "• Identifying common safety violations"  
    echo "• Learning defensive programming techniques"
    echo "• Building quality automotive software"
    echo ""
    read -p "Press Enter to begin your safety engineering adventure..."
    echo ""
fi

# Function to wait for user input
wait_for_user() {
    echo -e "\n${YELLOW}➤ Press Enter to continue...${NC}"
    read
}

# Function to run and show command
run_command() {
    echo -e "${BLUE}Running: $1${NC}"
    echo "----------------------------------------"
    eval "$1"
    echo "----------------------------------------"
}

echo -e "${GREEN}📚 Step 1: Understanding the Context${NC}"
echo ""
echo "You're working as a Safety Engineer on an automotive battery monitoring system."
echo "The system displays battery voltage to the driver - currently ASIL QM (Quality Managed)."
echo ""
echo "Let's start by examining a POOR implementation with safety violations..."
echo ""

wait_for_user

echo -e "${RED}🚫 Running the VIOLATION example:${NC}"
echo ""
run_command "bazel run //exercises/01_basic_safety:violation_example"

echo ""
echo -e "${YELLOW}❓ Questions for Reflection:${NC}"
echo "1. What problems did you notice in the output?"
echo "2. What could go wrong with this approach in a real vehicle?"
echo "3. How might these issues affect driver safety?"
echo ""

wait_for_user

echo -e "${GREEN}✅ Step 2: Learning from Good Implementation${NC}"
echo ""
echo "Now let's see how the SAME functionality should be implemented properly..."
echo ""

wait_for_user

echo -e "${GREEN}✅ Running the COMPLIANT example:${NC}"
echo ""
run_command "bazel run //exercises/01_basic_safety:compliant_example"

echo ""
echo -e "${YELLOW}❓ Compare and Analyze:${NC}"
echo "1. How is the error handling different?"
echo "2. What additional information does the compliant version provide?"
echo "3. Which version would you trust in your own vehicle?"
echo ""

wait_for_user

echo -e "${BLUE}🔍 Step 3: Interactive Code Analysis${NC}"
echo ""
echo "Let's examine the source code differences side by side..."
echo ""

# Show code snippets for comparison
echo -e "${RED}Violation Example (violation.c):${NC}"
echo "----------------------------------------"
head -n 30 "$EXERCISE_DIR/violation.c" | grep -A 5 -B 5 "VIOLATION"
echo "... (see full file for more violations)"
echo ""

echo -e "${GREEN}Compliant Example (compliant.c):${NC}" 
echo "----------------------------------------"
head -n 30 "$EXERCISE_DIR/compliant.c" | grep -A 5 -B 5 "GOOD PRACTICE"
echo "... (see full file for more good practices)"
echo ""

wait_for_user

echo -e "${BLUE}🧪 Step 4: Safety Analysis Tools${NC}"
echo ""
echo "Real automotive development uses static analysis tools to catch safety issues."
echo "Let's run safety analysis on both examples..."
echo ""

wait_for_user

run_command "bazel run //exercises/01_basic_safety:safety_check"

echo ""
echo -e "${YELLOW}Understanding Static Analysis:${NC}"
echo "• Static analysis finds potential problems WITHOUT running the code"
echo "• MISRA C rules enforce automotive coding standards"  
echo "• These tools are REQUIRED for ASIL B and higher systems"
echo ""

wait_for_user

echo -e "${GREEN}🛠️ Step 5: Your Turn - Interactive Challenges${NC}"
echo ""
echo "Now it's time to apply what you've learned!"
echo ""

# Challenge 1
echo -e "${BLUE}Challenge 1: Fix the Bug${NC}"
echo "----------------------------------------"
echo "We've introduced a NEW bug in the violation code."
echo "Can you identify what's wrong with this function?"
echo ""

cat << 'EOF'
float convert_voltage(int adc_reading) {
    // BUG: What's wrong here?
    if (adc_reading > 4095) {
        printf("Error: ADC reading too high\n");
        // Missing return statement!
    }
    return (float)adc_reading * 0.00122;  // What happens if adc_reading > 4095?
}
EOF

echo ""
echo -e "${YELLOW}What's the problem? (Type your answer)${NC}"
read user_answer
echo "Your answer: $user_answer"
echo ""
echo -e "${GREEN}Correct Answer: Missing return statement after error detection!${NC}"
echo "The function continues executing and returns garbage data even after detecting an error."
echo "In automotive systems, this could cause incorrect voltage readings!"
echo ""

wait_for_user

# Challenge 2  
echo -e "${BLUE}Challenge 2: Choose the Safety Mechanism${NC}"
echo "----------------------------------------"
echo "For a battery voltage monitor, which safety mechanism is MOST important?"
echo ""
echo "A) Encryption of voltage data"
echo "B) Input validation and range checking" 
echo "C) Graphical user interface design"
echo "D) Network security protocols"
echo ""
echo -n "Your choice (A/B/C/D): "
read choice

case $choice in
    [Bb])
        echo -e "${GREEN}✅ CORRECT!${NC} Input validation prevents incorrect data from propagating."
        ;;
    *)
        echo -e "${RED}❌ Not quite.${NC} While others may be important, input validation is fundamental for safety."
        echo "Input validation catches bad data BEFORE it can cause problems."
        ;;
esac

echo ""
wait_for_user

# Progress tracking
echo -e "${GREEN}🎉 Congratulations! Exercise 01 Complete!${NC}"
echo ""
echo "You've successfully learned:"
echo "✅ Basic ISO 26262 concepts and terminology"
echo "✅ How to identify common safety violations"
echo "✅ The importance of defensive programming"  
echo "✅ How static analysis tools help ensure safety"
echo ""

# Update progress
echo "exercise_01_completed=$(date)" >> "$PROGRESS_FILE"

echo -e "${BLUE}📈 Your Learning Progress:${NC}"
echo "🟢 Exercise 01: Basic Safety Concepts - COMPLETED"
echo "⚪ Exercise 02: Watchdog Timer Systems - Next"
echo "⚪ Exercise 03: Memory Protection - Locked"
echo "⚪ Exercise 04: Dual-Channel Systems - Locked"
echo "⚪ Exercise 05: Autonomous Emergency Braking - Locked"
echo ""

echo -e "${YELLOW}🔗 What's Next?${NC}"
echo ""
echo "Ready for the next challenge? Exercise 02 covers timing safety:"
echo ""
echo -e "${BLUE}bazel run //exercises/02_watchdog_timer:interactive_tutorial${NC}"
echo ""
echo "Or review what you learned:"
echo "• Read the detailed analysis: exercises/01_basic_safety/README.md"
echo "• Study the ISO 26262 guide: docs/iso26262_guide.md" 
echo "• Explore the source code in your editor"
echo ""

echo -e "${GREEN}Keep up the great work on your safety engineering journey! 🚗⚡${NC}"