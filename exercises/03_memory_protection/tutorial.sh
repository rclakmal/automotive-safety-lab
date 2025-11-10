#!/bin/bash

# AUTOMOTIVE SAFETY LAB - Exercise 03: Memory Protection (ASIL B)
# Interactive Tutorial: Freedom from Interference in Safety Systems
# ================================================================

# Color definitions for better UX
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[1;37m'
NC='\033[0m' # No Color

# Tutorial progress tracking
STEP=1
TOTAL_STEPS=8

print_header() {
    clear
    echo -e "${WHITE}╔══════════════════════════════════════════════════════════════╗${NC}"
    echo -e "${WHITE}║                AUTOMOTIVE SAFETY LAB                         ║${NC}"
    echo -e "${WHITE}║         Exercise 03: Memory Protection (ASIL B)              ║${NC}"
    echo -e "${WHITE}║                                                              ║${NC}"
    echo -e "${WHITE}║  🛡️  Learn Freedom from Interference in Safety Systems      ║${NC}"
    echo -e "${WHITE}╚══════════════════════════════════════════════════════════════╝${NC}"
    echo ""
    echo -e "${CYAN}Step ${STEP} of ${TOTAL_STEPS}${NC}"
    echo ""
}

wait_for_user() {
    echo ""
    echo -e "${YELLOW}Press Enter to continue...${NC}"
    read
}

step_introduction() {
    print_header
    echo -e "${WHITE}🎯 Welcome to ASIL B Memory Protection!${NC}"
    echo ""
    echo "In this exercise, you'll master memory protection techniques"
    echo "essential for ASIL B automotive safety systems."
    echo ""
    echo -e "${GREEN}What you'll learn:${NC}"
    echo "• Memory Protection Unit (MPU) configuration"
    echo "• Stack overflow protection and detection"
    echo "• Heap isolation and safety boundaries"
    echo "• Freedom from interference between components"
    echo "• Component integrity validation"
    echo ""
    echo -e "${BLUE}Real-world context:${NC}"
    echo "🚗 Electronic Brake System (EBS) with ASIL B requirements"
    echo "🎯 Preventing memory corruption that could cause brake failure"
    echo "⚡ Ensuring safety functions remain unaffected by QM functions"
    
    wait_for_user
    ((STEP++))
}

step_asil_b_overview() {
    print_header
    echo -e "${WHITE}📚 Understanding ASIL B Requirements${NC}"
    echo ""
    echo -e "${GREEN}ASIL B Characteristics:${NC}"
    echo "• Moderate severity + exposure + controllability"
    echo "• Hardware diagnostic coverage: >90%"
    echo "• Single Point of Failure Metric (SPFM): >90%"
    echo "• Latent Fault Metric (LFM): >80%"
    echo ""
    echo -e "${YELLOW}Memory Protection Requirements for ASIL B:${NC}"
    echo "1. Freedom from interference between safety elements"
    echo "2. Memory protection to prevent corruption"
    echo "3. Stack monitoring and overflow detection"
    echo "4. Heap boundaries and allocation controls"
    echo "5. Component isolation and integrity checking"
    echo ""
    echo -e "${PURPLE}Why Memory Protection Matters:${NC}"
    echo "• Software defects are the #1 cause of automotive recalls"
    echo "• Memory corruption can cause unpredictable safety failures"
    echo "• ASIL B requires systematic protection against interference"
    echo "• Real-time constraints demand efficient protection mechanisms"
    
    wait_for_user
    ((STEP++))
}

step_violation_analysis() {
    print_header
    echo -e "${WHITE}❌ Analyzing Unsafe Memory Practices${NC}"
    echo ""
    echo "Let's examine a brake control system with dangerous memory issues:"
    echo ""
    
    echo -e "${RED}Running violation example...${NC}"
    echo ""
    
    # Run the violation example
    if bazel run //exercises/03_memory_protection:violation_example 2>/dev/null; then
        echo ""
        echo -e "${YELLOW}🔍 Key Violations Identified:${NC}"
        echo ""
        echo "1. 📍 Buffer overflows without bounds checking"
        echo "2. 🎯 Uncontrolled pointer arithmetic"
        echo "3. 🔥 Stack smashing vulnerabilities"
        echo "4. 💥 Heap corruption possibilities"
        echo "5. 🚫 No memory protection boundaries"
        echo "6. ⚠️  Shared memory without access control"
        echo "7. 🔓 Missing component isolation"
        echo "8. 🕳️  Memory leaks in safety-critical paths"
    else
        echo -e "${RED}Note: Run 'bazel run //exercises/03_memory_protection:violation_example' separately to see violations${NC}"
    fi
    
    echo ""
    echo -e "${PURPLE}💡 Real-World Impact:${NC}"
    echo "These violations could cause:"
    echo "• Brake commands to be corrupted or lost"
    echo "• Safety monitoring to be bypassed"
    echo "• Critical timing deadlines to be missed"
    echo "• System crashes during emergency braking"
    
    wait_for_user
    ((STEP++))
}

step_compliant_solution() {
    print_header
    echo -e "${WHITE}✅ ASIL B Compliant Memory Protection${NC}"
    echo ""
    echo "Now let's see how proper memory protection works:"
    echo ""
    
    echo -e "${GREEN}Running compliant example...${NC}"
    echo ""
    
    # Run the compliant example  
    if bazel run //exercises/03_memory_protection:compliant_example 2>/dev/null; then
        echo ""
        echo -e "${YELLOW}🛡️ Protection Mechanisms:${NC}"
        echo ""
        echo "1. 🏛️ MPU configuration with region protection"
        echo "2. 🥞 Stack guards and overflow detection" 
        echo "3. 🏠 Heap isolation with safety boundaries"
        echo "4. 🔒 Component access control"
        echo "5. ✅ Memory integrity validation"
        echo "6. 🚧 Runtime bounds checking"
        echo "7. 📊 Memory usage monitoring"
        echo "8. 🔄 Safe memory allocation patterns"
    else
        echo -e "${RED}Note: Run 'bazel run //exercises/03_memory_protection:compliant_example' separately to see protection${NC}"
    fi
    
    echo ""
    echo -e "${BLUE}🎯 Key Benefits:${NC}"
    echo "• Memory corruption cannot affect brake safety functions"
    echo "• Component isolation prevents interference"
    echo "• Stack overflows are detected before damage"
    echo "• Heap allocation is controlled and monitored" 
    echo "• Runtime validation ensures memory integrity"
    
    wait_for_user
    ((STEP++))
}

step_mpu_deep_dive() {
    print_header
    echo -e "${WHITE}🏛️ Memory Protection Unit (MPU) Deep Dive${NC}"
    echo ""
    echo -e "${GREEN}MPU Configuration Concepts:${NC}"
    echo ""
    echo "1. 📍 Memory Regions:"
    echo "   • Safety Code Region (Read/Execute only)"
    echo "   • Safety Data Region (Read/Write, protected)"
    echo "   • QM Code Region (Isolated from safety)"
    echo "   • Shared Communication Region (Controlled access)"
    echo ""
    echo "2. 🔐 Access Permissions:"
    echo "   • Privileged vs User mode separation"
    echo "   • Execute Never (XN) for data regions"
    echo "   • Read-only for code and constants"
    echo "   • Write protection for critical data"
    echo ""
    echo "3. 🚨 Fault Handling:"
    echo "   • Memory Protection Fault interrupts"
    echo "   • Fault address and type logging"
    echo "   • Safe degradation responses"
    echo "   • Diagnostic counter updates"
    echo ""
    echo -e "${YELLOW}📊 Example MPU Memory Map:${NC}"
    echo "0x00000000-0x0007FFFF: Safety Code (R/X)"
    echo "0x20000000-0x2000FFFF: Safety Data (R/W)"
    echo "0x20010000-0x2001FFFF: QM Data (R/W, isolated)"
    echo "0x40000000-0x400003FF: Shared Comm (Controlled)"
    
    wait_for_user
    ((STEP++))
}

step_stack_protection() {
    print_header
    echo -e "${WHITE}🥞 Stack Protection Mechanisms${NC}"
    echo ""
    echo -e "${GREEN}Stack Guard Implementation:${NC}"
    echo ""
    echo "1. 🛡️ Guard Pages:"
    echo "   • Unmapped pages at stack boundaries"
    echo "   • Hardware-triggered faults on overflow"
    echo "   • Immediate detection of stack corruption"
    echo ""
    echo "2. 🎯 Canary Values:"
    echo "   • Random values at function boundaries"
    echo "   • Checked on function return"
    echo "   • Detect buffer overflow attacks"
    echo ""
    echo "3. 📏 Stack Usage Monitoring:"
    echo "   • Runtime stack depth tracking"
    echo "   • Watermark analysis for sizing"
    echo "   • Preemptive warning before overflow"
    echo ""
    echo -e "${BLUE}🔧 Implementation Example:${NC}"
    echo ""
    echo "// Stack guard initialization"
    echo "void setup_stack_protection() {"
    echo "    mpu_configure_region(STACK_GUARD_REGION,"
    echo "                        stack_base - PAGE_SIZE,"  
    echo "                        PAGE_SIZE,"
    echo "                        MPU_REGION_NO_ACCESS);"
    echo "}"
    
    wait_for_user
    ((STEP++))
}

step_hands_on_challenge() {
    print_header
    echo -e "${WHITE}🏗️ Hands-On Challenge: Build Your Own Memory Protection${NC}"
    echo ""
    echo "Time to put your knowledge into practice!"
    echo ""
    echo -e "${GREEN}Challenge: Implement Memory Protection for Brake Controller${NC}"
    echo ""
    echo "Your task:"
    echo "1. Configure MPU regions for brake safety functions"
    echo "2. Implement stack overflow protection"
    echo "3. Add heap boundary validation"
    echo "4. Create component isolation mechanisms"
    echo "5. Validate memory integrity at runtime"
    echo ""
    echo -e "${YELLOW}Available commands:${NC}"
    echo "• bazel run //exercises/03_memory_protection:build_challenge"
    echo "• bazel run //exercises/03_memory_protection:debug_challenge"
    echo "• bazel run //exercises/03_memory_protection:memory_analysis"
    echo ""
    echo -e "${BLUE}Success Criteria:${NC}"
    echo "✅ All MPU regions configured correctly"
    echo "✅ Stack overflow detection working"
    echo "✅ Heap boundaries enforced"
    echo "✅ Component isolation verified"
    echo "✅ Memory integrity checks passing"
    echo ""
    echo -e "${PURPLE}💡 Hints:${NC}"
    echo "• Start with the basic MPU configuration"
    echo "• Use the memory analysis tool to validate your setup"
    echo "• Test with intentional violations to verify protection"
    
    wait_for_user
    ((STEP++))
}

step_completion() {
    print_header
    echo -e "${WHITE}🎖️ Exercise 03 Complete - Memory Protection Mastery!${NC}"
    echo ""
    echo -e "${GREEN}🎉 Congratulations! You have mastered:${NC}"
    echo ""
    echo "✅ ASIL B memory protection requirements"
    echo "✅ Memory Protection Unit (MPU) configuration" 
    echo "✅ Stack overflow protection and detection"
    echo "✅ Heap isolation and safety boundaries"
    echo "✅ Freedom from interference principles"
    echo "✅ Component integrity validation"
    echo "✅ Runtime memory safety monitoring"
    echo ""
    echo -e "${YELLOW}🚀 Skills Acquired:${NC}"
    echo "• Design memory-safe automotive software architectures"
    echo "• Configure hardware memory protection mechanisms"
    echo "• Implement systematic protection against interference"
    echo "• Validate memory safety in real-time systems"
    echo "• Apply ASIL B memory protection best practices"
    echo ""
    echo -e "${BLUE}📈 Learning Progression:${NC}"
    echo "✅ Exercise 01: Basic Safety (ASIL QM)"
    echo "✅ Exercise 02: Watchdog Timers (ASIL A)"
    echo "✅ Exercise 03: Memory Protection (ASIL B) ← Completed!"
    echo "➡️  Exercise 04: Redundancy & Voting (ASIL C)"
    echo "🎯 Exercise 05: Critical Systems (ASIL D)"
    echo ""
    echo -e "${PURPLE}🔗 Next Steps:${NC}"
    echo "Ready for ASIL C redundancy systems?"
    echo "Run: cd ../04_redundancy_voting && ./tutorial.sh"
    echo ""
    echo -e "${CYAN}Or continue exploring Exercise 03:${NC}"
    echo "• bazel test //exercises/03_memory_protection:all_tests"
    echo "• bazel run //exercises/03_memory_protection:advanced_analysis"
    echo ""
    echo -e "${WHITE}🏆 You're now qualified for ASIL B memory protection design!${NC}"
    
    wait_for_user
}

# Main tutorial execution
main() {
    step_introduction
    step_asil_b_overview
    step_violation_analysis
    step_compliant_solution
    step_mpu_deep_dive
    step_stack_protection
    step_hands_on_challenge
    step_completion
    
    echo ""
    echo -e "${GREEN}Tutorial complete! 🎉${NC}"
}

# Handle Ctrl+C gracefully
trap 'echo -e "\n${YELLOW}Tutorial interrupted. You can restart anytime with ./tutorial.sh${NC}"; exit 0' INT

# Run the tutorial
main