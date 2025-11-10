#!/bin/bash

# ============================================================================= 
# Automotive Safety Lab - Exercise 02: Interactive Watchdog Timer Tutorial
# System: Engine Control Module (ECM) - ASIL A
# Focus: Timing supervision and failure detection in safety-critical systems
# =============================================================================

# Color definitions for enhanced learning experience
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[1;37m'
BOLD='\033[1m'
NC='\033[0m' # No Color

# Unicode symbols for visual enhancement
CHECKMARK="✅"
CROSSMARK="❌"
WARNING="⚠️"
ROCKET="🚀"
GEAR="⚙️"
TIMER="⏰"
DOG="🐕"
SHIELD="🛡️"
CAR="🚗"
FIRE="🔥"
WRENCH="🔧"

# Progress tracking
CURRENT_STEP=0
TOTAL_STEPS=8

# =============================================================================
# UTILITY FUNCTIONS
# =============================================================================

print_header() {
    clear
    echo -e "${CYAN}╔══════════════════════════════════════════════════════════════╗${NC}"
    echo -e "${CYAN}║${BOLD}    Automotive Safety Lab - Exercise 02: Watchdog Timers    ${NC}${CYAN}║${NC}"
    echo -e "${CYAN}║${WHITE}              Interactive Learning Tutorial                   ${NC}${CYAN}║${NC}"
    echo -e "${CYAN}╚══════════════════════════════════════════════════════════════╝${NC}"
    echo ""
    echo -e "${WHITE}${CAR} System:${NC} Engine Control Module (ECM)"
    echo -e "${WHITE}${SHIELD} ASIL Level:${NC} A (S2 + E4 + C2)"
    echo -e "${WHITE}${TIMER} Focus:${NC} Timing supervision and failure detection"
    echo ""
}

print_progress() {
    local step=$1
    local description=$2
    CURRENT_STEP=$step
    
    echo -e "${CYAN}┌─────────────────────────────────────────────────────────────┐${NC}"
    echo -e "${CYAN}│${WHITE} Step ${step}/${TOTAL_STEPS}: ${description}${NC}"
    
    # Progress bar
    local filled=$((step * 50 / TOTAL_STEPS))
    local empty=$((50 - filled))
    
    echo -ne "${CYAN}│ Progress: [${NC}"
    for ((i=1; i<=filled; i++)); do echo -ne "${GREEN}█${NC}"; done
    for ((i=1; i<=empty; i++)); do echo -ne "${WHITE}░${NC}"; done
    echo -e "${CYAN}] ${step}/${TOTAL_STEPS}${NC}"
    echo -e "${CYAN}└─────────────────────────────────────────────────────────────┘${NC}"
    echo ""
}

wait_for_user() {
    echo -e "${YELLOW}${ROCKET} Press ENTER to continue...${NC}"
    read -r
}

print_challenge() {
    local title=$1
    local description=$2
    
    echo -e "${MAGENTA}╭─────────────────────────────────────────────────────────────╮${NC}"
    echo -e "${MAGENTA}│${BOLD} 🎯 CHALLENGE: ${title}${NC}"
    echo -e "${MAGENTA}│${NC} ${description}"
    echo -e "${MAGENTA}╰─────────────────────────────────────────────────────────────╯${NC}"
    echo ""
}

print_safety_note() {
    local message=$1
    echo -e "${RED}╔═══════════════════════════════════════════════════════════════╗${NC}"
    echo -e "${RED}║${BOLD} ${WARNING} SAFETY-CRITICAL INSIGHT${NC}${RED}                                  ║${NC}"
    echo -e "${RED}║${NC} ${message}"
    echo -e "${RED}╚═══════════════════════════════════════════════════════════════╝${NC}"
    echo ""
}

run_with_highlight() {
    local command=$1
    local description=$2
    
    echo -e "${BLUE}${WRENCH} Running:${NC} ${description}"
    echo -e "${GRAY}Command: ${command}${NC}"
    echo ""
    
    # Execute the command
    eval "$command"
    local exit_code=$?
    
    echo ""
    if [ $exit_code -eq 0 ]; then
        echo -e "${GREEN}${CHECKMARK} Command completed successfully${NC}"
    else
        echo -e "${RED}${CROSSMARK} Command failed with exit code: $exit_code${NC}"
    fi
    echo ""
    
    return $exit_code
}

# =============================================================================
# TUTORIAL STEPS
# =============================================================================

step1_introduction() {
    print_header
    print_progress 1 "Understanding Watchdog Timers in Automotive Systems"
    
    echo -e "${WHITE}${DOG} What is a Watchdog Timer?${NC}"
    echo "A watchdog timer is a safety mechanism that monitors system operation"
    echo "and takes corrective action if the system becomes unresponsive."
    echo ""
    
    echo -e "${WHITE}${CAR} Automotive Context: Engine Control Module (ECM)${NC}"
    echo "• Function: Controls fuel injection timing for optimal engine performance"
    echo "• Critical Requirement: Must respond within 10ms to prevent engine stall"
    echo "• Failure Scenario: Software hang could cause engine stall at highway speeds"
    echo "• Safety Goal: 'Engine control shall not hang or become unresponsive'"
    echo ""
    
    print_safety_note "In automotive systems, a hung ECM can lead to sudden engine shutdown,    creating a dangerous situation, especially at high speeds. Watchdogs     provide an essential safety net."
    
    echo -e "${WHITE}${TIMER} ASIL A Requirements for Watchdog Systems:${NC}"
    echo "✅ Single-point fault tolerance (hardware + software supervision)"
    echo "✅ Diagnostic coverage ≥90% (detect timing violations)"  
    echo "✅ Safe state implementation (limp-home mode)"
    echo "✅ Requirements traceability and verification evidence"
    echo ""
    
    wait_for_user
}

step2_examine_violations() {
    print_header
    print_progress 2 "Analyzing Dangerous Watchdog Implementation"
    
    print_challenge "Violation Analysis" "Find 25+ timing safety violations in the dangerous code"
    
    echo -e "${WHITE}${FIRE} Let's examine a DANGEROUS watchdog implementation:${NC}"
    echo "This code contains intentional violations of ISO 26262 timing requirements."
    echo ""
    
    run_with_highlight "bazel run //exercises/02_watchdog_timer:violation_example" \
                      "Running dangerous watchdog implementation"
    
    echo -e "${RED}${CROSSMARK} Critical Issues You Should Have Observed:${NC}"
    echo ""
    echo -e "${YELLOW}🎯 Timing Violations:${NC}"
    echo "  • Variable cycle times (1-5 seconds vs 10ms requirement)"
    echo "  • Random delays exceeding safety deadlines"
    echo "  • No timeout validation before critical operations"
    echo ""
    echo -e "${YELLOW}🎯 Watchdog Implementation Failures:${NC}"
    echo "  • No watchdog timer hardware initialization"
    echo "  • Missing timeout handler implementation"
    echo "  • Watchdog kick at wrong time in cycle"
    echo "  • No pattern-based validation"
    echo ""
    echo -e "${YELLOW}🎯 Safe State Violations:${NC}"
    echo "  • No safe state function implemented"
    echo "  • No safe state transition on failures"
    echo "  • Missing critical failure detection"
    echo ""
    
    print_safety_note "Each violation represents a potential single-point failure that could   lead to engine stall. In ASIL A systems, we must detect and handle     these failures systematically."
    
    wait_for_user
}

step3_compliant_implementation() {
    print_header
    print_progress 3 "Studying ASIL A Compliant Watchdog System"
    
    echo -e "${WHITE}${SHIELD} Now let's examine a PROPER ASIL A implementation:${NC}"
    echo "This code demonstrates correct watchdog supervision with safety features."
    echo ""
    
    run_with_highlight "bazel run //exercises/02_watchdog_timer:compliant_example" \
                      "Running compliant ASIL A watchdog implementation"
    
    echo -e "${GREEN}${CHECKMARK} Key Safety Improvements You Should Have Observed:${NC}"
    echo ""
    echo -e "${YELLOW}🎯 Proper Timing Management:${NC}"
    echo "  • Fixed 10ms cycle time with deadline monitoring"
    echo "  • Bounded execution time for all operations"
    echo "  • Controlled delays with emergency override"
    echo "  • Cycle overrun detection and reporting"
    echo ""
    echo -e "${YELLOW}🎯 Advanced Watchdog Features:${NC}"
    echo "  • Pattern-based kick validation (alternating 0x5A5A/0xA5A5)"
    echo "  • Timing window enforcement (8-12ms kick window)"
    echo "  • Hardware watchdog initialization (50ms timeout)"
    echo "  • Comprehensive diagnostic counters"
    echo ""
    echo -e "${YELLOW}🎯 Safe State Management:${NC}"
    echo "  • Hierarchical safety states (normal → degraded → limp-home → stop)"
    echo "  • Automatic state transitions based on fault conditions"
    echo "  • Fuel injection limiting in degraded modes"
    echo "  • Emergency stop with complete shutdown"
    echo ""
    
    wait_for_user
}

step4_timing_analysis() {
    print_header
    print_progress 4 "Timing Analysis and Diagnostic Coverage"
    
    print_challenge "Timing Analysis" "Understand how timing violations are detected and handled"
    
    echo -e "${WHITE}${TIMER} Let's analyze the timing behavior in detail:${NC}"
    echo ""
    
    run_with_highlight "bazel run //exercises/02_watchdog_timer:timing_analysis" \
                      "Running detailed timing analysis"
    
    echo -e "${WHITE}${GEAR} Understanding Watchdog Timing Windows:${NC}"
    echo ""
    echo "┌─────────────────────────────────────────────────────────────┐"
    echo "│                 Watchdog Timing Window                      │"
    echo "├─────────────────────────────────────────────────────────────┤"
    echo "│  0ms    8ms              12ms                    50ms       │"
    echo "│   │      │                │                       │        │"
    echo "│   │      ├─ Valid Kick ────┤                       │        │"
    echo "│   │      │   Window        │                       │        │"
    echo "│   │  Too Early        Too Late              Timeout Reset   │"
    echo "│   │    (Error)        (Error)               (System Reset)  │"
    echo "└─────────────────────────────────────────────────────────────┘"
    echo ""
    
    echo -e "${WHITE}Key Timing Principles:${NC}"
    echo "• ${GREEN}Valid Window${NC}: 8-12ms after previous kick"
    echo "• ${RED}Too Early${NC}: Kick before 8ms indicates timing error"
    echo "• ${RED}Too Late${NC}: Kick after 12ms indicates system delay"
    echo "• ${RED}Timeout${NC}: No kick within 50ms triggers hardware reset"
    echo ""
    
    print_safety_note "Timing windows prevent both 'runaway' systems (kicking too fast)    and 'sluggish' systems (kicking too slow). Both conditions indicate  potential safety hazards."
    
    wait_for_user
}

step5_debug_challenge() {
    print_header
    print_progress 5 "Interactive Debugging Challenge"
    
    print_challenge "Debug Timing Issues" "Fix timing bugs in a broken watchdog implementation"
    
    echo -e "${WHITE}${WRENCH} Ready for hands-on debugging?${NC}"
    echo "We'll present you with code that has timing issues to fix."
    echo ""
    
    # Create a simple timing challenge
    echo -e "${YELLOW}Debugging Scenario:${NC}"
    echo "An ECM is experiencing intermittent watchdog resets during high-load conditions."
    echo "The fuel injection timing becomes erratic, causing engine roughness."
    echo ""
    
    run_with_highlight "bazel run //exercises/02_watchdog_timer:debug_challenge" \
                      "Running interactive debugging challenge"
    
    echo -e "${WHITE}🎯 Debugging Skills Practiced:${NC}"
    echo "• Identifying timing deadline violations"
    echo "• Measuring execution time of critical sections"
    echo "• Implementing timeout protection for blocking operations"
    echo "• Validating watchdog kick timing"
    echo "• Adding diagnostic instrumentation"
    echo ""
    
    echo -e "${GREEN}${CHECKMARK} Debugging Complete!${NC}"
    echo "You've now experienced the process of diagnosing and fixing"
    echo "timing-related safety issues in watchdog systems."
    echo ""
    
    wait_for_user
}

step6_build_challenge() {
    print_header
    print_progress 6 "Build Your Own Watchdog System"
    
    print_challenge "Implementation Challenge" "Design a watchdog system for transmission control"
    
    echo -e "${WHITE}${GEAR} Design Challenge: Transmission Control Module${NC}"
    echo ""
    echo -e "${CYAN}System Requirements:${NC}"
    echo "• Function: Automatic transmission gear shifting"
    echo "• Timing: 5ms maximum shift decision time"  
    echo "• Safety: Prevent gear shifts during acceleration"
    echo "• ASIL Level: A (transmission malfunction during overtaking)"
    echo ""
    
    echo -e "${CYAN}Your Watchdog Must Implement:${NC}"
    echo "1. ${WHITE}Timing Supervision${NC}: 5ms cycle monitoring"
    echo "2. ${WHITE}Pattern Validation${NC}: Secure kick sequence"
    echo "3. ${WHITE}Safe State${NC}: Lock in current gear on failure"
    echo "4. ${WHITE}Diagnostics${NC}: Track timing violations"
    echo ""
    
    run_with_highlight "bazel run //exercises/02_watchdog_timer:build_challenge" \
                      "Starting watchdog implementation framework"
    
    echo -e "${WHITE}🏗️ Implementation Guidance:${NC}"
    echo ""
    echo -e "${YELLOW}Step 1:${NC} Define timing constants and safety limits"
    echo -e "${YELLOW}Step 2:${NC} Implement watchdog initialization"
    echo -e "${YELLOW}Step 3:${NC} Create timing validation functions"
    echo -e "${YELLOW}Step 4:${NC} Add pattern-based kick validation"
    echo -e "${YELLOW}Step 5:${NC} Implement safe state management"
    echo -e "${YELLOW}Step 6:${NC} Add comprehensive diagnostics"
    echo ""
    
    print_safety_note "Remember: In transmission control, a timing failure during gear      shifting can leave the vehicle stranded or cause dangerous behavior   during overtaking maneuvers."
    
    wait_for_user
}

step7_advanced_patterns() {
    print_header
    print_progress 7 "Advanced Watchdog Patterns"
    
    echo -e "${WHITE}${SHIELD} Advanced Safety Patterns for Complex Systems${NC}"
    echo ""
    
    echo -e "${CYAN}1. Dual Watchdog Architecture:${NC}"
    echo "   • Hardware watchdog (50ms timeout)"
    echo "   • Software watchdog (independent supervision)"
    echo "   • Cross-monitoring between watchdogs"
    echo ""
    
    echo -e "${CYAN}2. Hierarchical Watchdog Systems:${NC}"
    echo "   • System-level watchdog (monitors overall health)"
    echo "   • Function-level watchdogs (monitor specific tasks)"
    echo "   • Task-level supervision (monitors individual operations)"
    echo ""
    
    echo -e "${CYAN}3. Adaptive Timing Windows:${NC}"
    echo "   • Dynamic timing adjustment based on load"
    echo "   • Separate windows for startup vs. normal operation"
    echo "   • Temperature-compensated timing for extreme conditions"
    echo ""
    
    run_with_highlight "bazel run //exercises/02_watchdog_timer:advanced_patterns" \
                      "Exploring advanced watchdog architectures"
    
    echo -e "${WHITE}🎯 Real-World Applications:${NC}"
    echo ""
    echo -e "${YELLOW}Autonomous Driving Systems (ASIL D):${NC}"
    echo "• Multiple redundant watchdogs for path planning"
    echo "• Cross-validation between perception and control"
    echo "• Fail-operational requirements with graceful degradation"
    echo ""
    echo -e "${YELLOW}Battery Management Systems (ASIL C):${NC}"
    echo "• Thermal runaway prevention with rapid response"
    echo "• Cell monitoring with microsecond precision"
    echo "• Emergency disconnect with hardware backup"
    echo ""
    echo -e "${YELLOW}Brake Control Systems (ASIL D):${NC}"
    echo "• Dual-channel monitoring with voter logic"
    echo "• Hardware diversity (different architectures)"
    echo "• Mechanical backup systems for ultimate safety"
    echo ""
    
    wait_for_user
}

step8_completion() {
    print_header
    print_progress 8 "Exercise Completion and Next Steps"
    
    echo -e "${GREEN}${CHECKMARK} Congratulations! You've completed Exercise 02${NC}"
    echo ""
    
    echo -e "${WHITE}🏆 Skills Mastered:${NC}"
    echo "✅ Understanding of watchdog timer principles in automotive systems"
    echo "✅ Identification of timing safety violations in code"
    echo "✅ Implementation of ASIL A compliant watchdog systems"
    echo "✅ Debugging timing-related failures with diagnostic tools"
    echo "✅ Design of watchdog architecture for specific automotive functions"
    echo "✅ Knowledge of advanced watchdog patterns for complex systems"
    echo ""
    
    echo -e "${WHITE}🎯 Key Takeaways:${NC}"
    echo ""
    echo -e "${CYAN}Timing is Safety-Critical:${NC}"
    echo "  In automotive systems, timing violations can lead to catastrophic failures."
    echo "  Every function must have well-defined timing requirements and supervision."
    echo ""
    echo -e "${CYAN}Defense in Depth:${NC}"
    echo "  • Hardware watchdog provides ultimate backup"
    echo "  • Software monitoring catches early warning signs"
    echo "  • Pattern validation prevents false positives"
    echo "  • Diagnostic coverage enables continuous improvement"
    echo ""
    echo -e "${CYAN}Graceful Degradation:${NC}"
    echo "  Safe states allow systems to continue operation with reduced functionality"
    echo "  rather than complete failure, improving overall system availability."
    echo ""
    
    echo -e "${WHITE}📚 Learning Path Progression:${NC}"
    echo ""
    echo "✅ ${GREEN}Exercise 01: Basic Safety Concepts${NC} (Completed)"
    echo "✅ ${GREEN}Exercise 02: Watchdog Timer Systems${NC} (Just Completed)"
    echo "🔄 ${YELLOW}Exercise 03: Memory Protection (ASIL B)${NC} (Ready to Start)"
    echo "⏳ ${BLUE}Exercise 04: Redundancy and Voting (ASIL C)${NC} (Coming Next)"
    echo "⏳ ${BLUE}Exercise 05: Autonomous Systems (ASIL D)${NC} (Advanced)"
    echo ""
    
    echo -e "${MAGENTA}╭─────────────────────────────────────────────────────────────╮${NC}"
    echo -e "${MAGENTA}│${BOLD} 🚀 Ready for the Next Challenge?${NC}"
    echo -e "${MAGENTA}│${NC}"
    echo -e "${MAGENTA}│${NC} Exercise 03 focuses on memory protection mechanisms in"
    echo -e "${MAGENTA}│${NC} safety-critical software - preventing buffer overflows,"
    echo -e "${MAGENTA}│${NC} stack corruption, and unauthorized memory access that"
    echo -e "${MAGENTA}│${NC} could compromise vehicle safety systems."
    echo -e "${MAGENTA}│${NC}"
    echo -e "${MAGENTA}│${BOLD} Start Exercise 03:${NC}"
    echo -e "${MAGENTA}│${NC} cd ../03_memory_protection && bazel run :interactive_tutorial"
    echo -e "${MAGENTA}╰─────────────────────────────────────────────────────────────╯${NC}"
    echo ""
    
    echo -e "${WHITE}📖 Additional Resources:${NC}"
    echo "• Review the compliant.c implementation for reference patterns"
    echo "• Examine BUILD file for safety-focused compilation flags"
    echo "• Study timing_analysis output for diagnostic techniques"
    echo "• Read ../../docs/watchdog_patterns.md for advanced concepts"
    echo ""
    
    echo -e "${GREEN}${ROCKET} Excellent work on mastering watchdog timer safety!${NC}"
    echo ""
}

# =============================================================================
# MAIN TUTORIAL EXECUTION
# =============================================================================

main() {
    # Check if we're in the right directory
    if [[ ! -f "BUILD" ]] || [[ ! -f "violation.c" ]]; then
        echo -e "${RED}Error: Please run this tutorial from the exercises/02_watchdog_timer directory${NC}"
        echo "Expected files: BUILD, violation.c, compliant.c"
        exit 1
    fi
    
    # Welcome message
    echo -e "${CYAN}${ROCKET} Welcome to the Automotive Safety Lab Interactive Platform!${NC}"
    echo ""
    sleep 1
    
    # Execute tutorial steps
    step1_introduction
    step2_examine_violations  
    step3_compliant_implementation
    step4_timing_analysis
    step5_debug_challenge
    step6_build_challenge
    step7_advanced_patterns
    step8_completion
    
    # Final message
    echo -e "${GREEN}Tutorial completed successfully!${NC}"
    echo -e "${CYAN}Continue your ISO 26262 journey with Exercise 03: Memory Protection${NC}"
}

# Run the main tutorial
main "$@"