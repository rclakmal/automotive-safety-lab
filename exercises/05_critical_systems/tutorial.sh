#!/bin/bash

# AUTOMOTIVE SAFETY LAB - Exercise 05: Critical Systems (ASIL D)
# Interactive Tutorial: Mastering the Highest Automotive Safety Integrity
# ========================================================================

# Color definitions for premium UX
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[1;37m'
GOLD='\033[1;33m'
NC='\033[0m' # No Color

# Tutorial progress tracking
STEP=1
TOTAL_STEPS=9

print_header() {
    clear
    echo -e "${WHITE}╔══════════════════════════════════════════════════════════════╗${NC}"
    echo -e "${WHITE}║                AUTOMOTIVE SAFETY LAB                         ║${NC}"
    echo -e "${WHITE}║         Exercise 05: Critical Systems (ASIL D)               ║${NC}"
    echo -e "${WHITE}║                                                              ║${NC}"
    echo -e "${WHITE}║  🎖️  Master the Highest Automotive Safety Integrity Level   ║${NC}"
    echo -e "${WHITE}╚══════════════════════════════════════════════════════════════╝${NC}"
    echo ""
    echo -e "${GOLD}Step ${STEP} of ${TOTAL_STEPS} - Ultimate Safety Mastery${NC}"
    echo ""
}

wait_for_user() {
    echo ""
    echo -e "${YELLOW}Press Enter to continue your journey to ASIL D mastery...${NC}"
    read
}

step_introduction() {
    print_header
    echo -e "${WHITE}🎖️ Welcome to ASIL D - The Ultimate Safety Challenge!${NC}"
    echo ""
    echo "Congratulations on reaching the pinnacle of automotive safety engineering!"
    echo "ASIL D represents the highest safety integrity level - reserved for"
    echo "life-critical functions where failure could result in fatalities."
    echo ""
    echo -e "${GOLD}What makes ASIL D special:${NC}"
    echo "• Life-critical automotive functions (AEB, primary steering, brake-by-wire)"
    echo "• Requires mathematical proof of safety properties"
    echo "• Triple Modular Redundancy (TMR) with diverse implementations"
    echo "• Fail-operational design - system continues after failures"
    echo "• Formal verification and comprehensive V&V documentation"
    echo ""
    echo -e "${BLUE}Real-world context:${NC}"
    echo "🚗 Autonomous Emergency Braking (AEB) at highway speeds"
    echo "🎯 Preventing fatal collisions through mathematical certainty"
    echo "⚡ System must work perfectly when human lives depend on it"
    
    wait_for_user
    ((STEP++))
}

step_asil_d_overview() {
    print_header
    echo -e "${WHITE}📚 Understanding ASIL D Requirements - The Gold Standard${NC}"
    echo ""
    echo -e "${GOLD}ASIL D Characteristics:${NC}"
    echo "• Severity: S3 (Life-threatening - potential for fatalities)"
    echo "• Exposure: E4 (Very high probability - highway driving)"
    echo "• Controllability: C3 (Difficult/impossible to control by driver)"
    echo "• Result: S3 + E4 + C3 = ASIL D (Highest integrity level)"
    echo ""
    echo -e "${YELLOW}ASIL D Requirements (ISO 26262):${NC}"
    echo "1. 🏛️ Triple Modular Redundancy (TMR) - 3 independent channels"
    echo "2. 📐 Formal Verification - Mathematical proof of safety properties"
    echo "3. 🔬 Diverse Programming - Multiple implementations prevent systematic failures"
    echo "4. 🛡️ Fail-Operational Design - System continues safe operation after failures"
    echo "5. 📊 Hardware Diagnostic Coverage: >99%"
    echo "6. 🎯 Single Point of Failure Metric (SPFM): >99%"
    echo "7. 📈 Latent Fault Metric (LFM): >90%"
    echo "8. 🔢 Random Hardware Failure Rate: <10 FIT"
    echo ""
    echo -e "${PURPLE}Why ASIL D is the Ultimate Challenge:${NC}"
    echo "• Only ~5% of automotive functions require ASIL D"
    echo "• Represents the apex of safety engineering expertise"
    echo "• Requires formal methods and mathematical rigor"
    echo "• Complete V&V documentation with quantified evidence"
    
    wait_for_user
    ((STEP++))
}

step_tmr_architecture() {
    print_header
    echo -e "${WHITE}🏛️ Triple Modular Redundancy (TMR) Architecture${NC}"
    echo ""
    echo -e "${GREEN}TMR Fundamentals:${NC}"
    echo ""
    echo "1. 🎯 Three Independent Channels:"
    echo "   • Channel 1: ARM Cortex-R52 (lockstep) + conservative algorithm"
    echo "   • Channel 2: Infineon AURIX TC3xx + sensor fusion algorithm"
    echo "   • Channel 3: Kalray MPPA + formal verification runtime checks"
    echo ""
    echo "2. 🗳️ 2-out-of-3 Voting System:"
    echo "   • Majority vote determines final decision"
    echo "   • Single channel failure doesn't compromise safety"
    echo "   • Voting algorithm includes confidence weighting"
    echo ""
    echo "3. 🔬 Diverse Implementations:"
    echo "   • Different algorithms solve same problem"
    echo "   • Prevents systematic software failures"
    echo "   • Different hardware architectures"
    echo ""
    echo -e "${BLUE}📊 TMR Decision Matrix Example:${NC}"
    echo "Channel A: BRAKE    | Channel B: BRAKE    | Channel C: NO_BRAKE"
    echo "Result:    BRAKE (2-out-of-3 majority)"
    echo ""
    echo "Channel A: NO_BRAKE | Channel B: BRAKE    | Channel C: BRAKE"  
    echo "Result:    BRAKE (2-out-of-3 majority)"
    echo ""
    echo "Channel A: NO_BRAKE | Channel B: NO_BRAKE | Channel C: NO_BRAKE"
    echo "Result:    NO_BRAKE (3-out-of-3 consensus)"
    
    wait_for_user
    ((STEP++))
}

step_formal_verification() {
    print_header
    echo -e "${WHITE}📐 Formal Verification - Mathematical Safety Proofs${NC}"
    echo ""
    echo -e "${GREEN}Formal Methods in ASIL D:${NC}"
    echo ""
    echo "1. 🔢 Safety Property Specification:"
    echo "   • Mathematical specification of safety requirements"
    echo "   • Temporal logic for time-based properties"
    echo "   • State-based invariants for system behavior"
    echo ""
    echo "2. 🎯 Model Checking:"
    echo "   • Exhaustive state space exploration"
    echo "   • Automatic verification of safety properties"
    echo "   • Counter-example generation for violations"
    echo ""
    echo "3. 🏗️ Theorem Proving:"
    echo "   • Mathematical proof of correctness"
    echo "   • Formal specification languages (TLA+, Coq)"
    echo "   • Machine-checked proofs"
    echo ""
    echo -e "${YELLOW}Example Formal Safety Property:${NC}"
    echo "∀t: CollisionDetected(t) → BrakeApplied(t + Δt)"
    echo "(For all times t: If collision is detected at time t,"
    echo " then brakes are applied by time t + Δt)"
    echo ""
    echo -e "${BLUE}Benefits of Formal Verification:${NC}"
    echo "• Mathematical certainty of safety properties"
    echo "• Eliminates entire classes of systematic failures"
    echo "• Required evidence for ASIL D safety case"
    echo "• Builds ultimate confidence in life-critical systems"
    
    wait_for_user
    ((STEP++))
}

step_violation_analysis() {
    print_header
    echo -e "${WHITE}❌ Analyzing Inadequate ASIL D Implementation${NC}"
    echo ""
    echo "Let's examine an autonomous emergency braking system with"
    echo "dangerous inadequacies that prevent ASIL D compliance:"
    echo ""
    
    echo -e "${RED}Running violation example...${NC}"
    echo ""
    
    # Run the violation example
    if bazel run //exercises/05_critical_systems:violation_example 2>/dev/null; then
        echo ""
        echo -e "${YELLOW}🚨 Critical ASIL D Violations Identified:${NC}"
        echo ""
        echo "1. 🔴 No Triple Modular Redundancy (TMR)"
        echo "2. ❌ Missing formal verification of safety properties"
        echo "3. 💥 Single points of failure throughout system"
        echo "4. 🚫 No hardware diversity or architectural separation"
        echo "5. 📉 Inadequate diagnostic coverage (<99% required)"
        echo "6. ⚠️  No fail-operational design - system fails unsafe"
        echo "7. 🕳️  Missing systematic fault injection testing"
        echo "8. 🔍 No diverse programming techniques applied"
        echo "9. 📊 Insufficient sensor fusion and validation"
        echo "10. 📋 No comprehensive V&V documentation"
    else
        echo -e "${RED}Note: Run 'bazel run //exercises/05_critical_systems:violation_example' separately to see violations${NC}"
    fi
    
    echo ""
    echo -e "${PURPLE}💀 Real-World Impact:${NC}"
    echo "These violations could cause:"
    echo "• Fatal collision due to brake system failure"
    echo "• Systematic software failures under stress"
    echo "• Inability to meet <10 FIT failure rate requirement"
    echo "• Regulatory rejection and legal liability"
    echo "• Loss of human life in critical scenarios"
    
    wait_for_user
    ((STEP++))
}

step_compliant_solution() {
    print_header
    echo -e "${WHITE}✅ Complete ASIL D Safety Architecture${NC}"
    echo ""
    echo "Now witness the power of a fully compliant ASIL D system:"
    echo ""
    
    echo -e "${GREEN}Running compliant ASIL D example...${NC}"
    echo ""
    
    # Run the compliant example  
    if bazel run //exercises/05_critical_systems:compliant_example 2>/dev/null; then
        echo ""
        echo -e "${GOLD}🛡️ ASIL D Protection Mechanisms:${NC}"
        echo ""
        echo "1. 🏛️ Triple Modular Redundancy with diverse architectures"
        echo "2. 📐 Formal verification with runtime property checking"
        echo "3. 🔬 N-version programming with diverse algorithms"
        echo "4. 🛡️ Fail-operational design with graceful degradation"
        echo "5. 📊 >99% diagnostic coverage with comprehensive monitoring"
        echo "6. 🎯 Hardware diversity prevents common-mode failures"
        echo "7. 🔄 2-out-of-3 voting with confidence weighting"
        echo "8. ✅ Mathematical proof of safety properties"
    else
        echo -e "${RED}Note: Run 'bazel run //exercises/05_critical_systems:compliant_example' separately${NC}"
    fi
    
    echo ""
    echo -e "${BLUE}🎖️ ASIL D Achievement Benefits:${NC}"
    echo "• Mathematical certainty of safety behavior"
    echo "• Fault tolerance to single and multiple failures"
    echo "• Regulatory compliance for life-critical functions"
    echo "• Ultimate confidence for autonomous vehicle deployment"
    echo "• Industry-leading safety engineering expertise"
    
    wait_for_user
    ((STEP++))
}

step_diverse_programming() {
    print_header
    echo -e "${WHITE}🔬 Diverse Programming & N-Version Development${NC}"
    echo ""
    echo -e "${GREEN}Systematic Diversity Techniques:${NC}"
    echo ""
    echo "1. 🧠 N-Version Programming:"
    echo "   • Multiple independent teams develop same function"
    echo "   • Different algorithms, data structures, programming languages"
    echo "   • Prevents systematic design and coding errors"
    echo ""
    echo "2. 🏗️ Architectural Diversity:"
    echo "   • Different processor families (ARM, x86, RISC-V)"
    echo "   • Different operating systems (RTOS, Linux, bare metal)"
    echo "   • Different development toolchains and compilers"
    echo ""
    echo "3. 🎯 Algorithmic Diversity:"
    echo "   • Conservative vs. aggressive collision detection"
    echo "   • Time-based vs. distance-based triggering"
    echo "   • Kalman filter vs. particle filter sensor fusion"
    echo ""
    echo -e "${YELLOW}Example: AEB Collision Detection Diversity${NC}"
    echo "Channel 1: Conservative physics-based (kinematic equations)"
    echo "Channel 2: AI/ML-based pattern recognition" 
    echo "Channel 3: Statistical sensor fusion with uncertainty quantification"
    echo ""
    echo -e "${BLUE}Benefits of Diversity:${NC}"
    echo "• Eliminates common-mode systematic failures"
    echo "• Required for ASIL D systematic capability"
    echo "• Increases overall system reliability"
    echo "• Provides multiple perspectives on safety decisions"
    
    wait_for_user
    ((STEP++))
}

step_hands_on_mastery() {
    print_header
    echo -e "${WHITE}🏆 Master-Level Challenge: Build ASIL D Architecture${NC}"
    echo ""
    echo "Time to demonstrate your mastery of the highest safety standards!"
    echo ""
    echo -e "${GOLD}Ultimate Challenge: Complete ASIL D AEB System${NC}"
    echo ""
    echo "Your mission:"
    echo "1. Implement Triple Modular Redundancy with diverse channels"
    echo "2. Add formal verification of safety properties"
    echo "3. Create 2-out-of-3 voting with confidence weighting"
    echo "4. Implement fail-operational behavior"
    echo "5. Achieve >99% diagnostic coverage"
    echo "6. Generate comprehensive V&V documentation"
    echo ""
    echo -e "${YELLOW}Master-Level Commands:${NC}"
    echo "• bazel run //exercises/05_critical_systems:build_challenge"
    echo "• bazel run //exercises/05_critical_systems:formal_verification"
    echo "• bazel run //exercises/05_critical_systems:debug_tmr"
    echo "• bazel run //exercises/05_critical_systems:diverse_programming"
    echo "• bazel run //exercises/05_critical_systems:safety_case"
    echo ""
    echo -e "${BLUE}Success Criteria (ASIL D Mastery):${NC}"
    echo "✅ TMR implementation with 3 diverse channels"
    echo "✅ Formal safety properties verified mathematically"
    echo "✅ 2-out-of-3 voting with fault tolerance"
    echo "✅ Fail-operational design validated"
    echo "✅ >99% diagnostic coverage achieved"
    echo "✅ Complete safety case documentation"
    echo ""
    echo -e "${PURPLE}💡 Master's Guidance:${NC}"
    echo "• Start with formal property specification"
    echo "• Use model checking for exhaustive verification"
    echo "• Implement hardware diversity across channels"
    echo "• Test with systematic fault injection"
    echo "• Document everything for regulatory compliance"
    
    wait_for_user
    ((STEP++))
}

step_completion() {
    print_header
    echo -e "${WHITE}🎖️ ASIL D MASTERY ACHIEVED - Ultimate Safety Engineering!${NC}"
    echo ""
    echo -e "${GOLD}🏆 LEGENDARY ACHIEVEMENT UNLOCKED!${NC}"
    echo ""
    echo "You have successfully completed the most challenging exercise"
    echo "in automotive functional safety engineering!"
    echo ""
    echo -e "${GREEN}🎯 ASIL D Mastery Includes:${NC}"
    echo ""
    echo "✅ Triple Modular Redundancy (TMR) architecture"
    echo "✅ Formal verification and mathematical proofs"
    echo "✅ Diverse programming and N-version development"
    echo "✅ Fail-operational design patterns"
    echo "✅ Hardware diversity and separation"
    echo "✅ >99% diagnostic coverage implementation"
    echo "✅ 2-out-of-3 voting with sophisticated algorithms"
    echo "✅ Complete V&V documentation and safety case"
    echo "✅ Life-critical system design expertise"
    echo ""
    echo -e "${YELLOW}🚀 Elite Skills Acquired:${NC}"
    echo "• Lead ASIL D automotive safety projects"
    echo "• Architect life-critical autonomous vehicle systems" 
    echo "• Apply formal methods to safety-critical software"
    echo "• Design fault-tolerant redundant architectures"
    echo "• Conduct comprehensive safety assessments"
    echo "• Guide regulatory compliance for critical functions"
    echo "• Mentor other safety engineers in advanced techniques"
    echo ""
    echo -e "${BLUE}📈 Complete Learning Journey:${NC}"
    echo "✅ Exercise 01: Basic Safety (ASIL QM) - Foundation"
    echo "✅ Exercise 02: Watchdog Timers (ASIL A) - Timing supervision"
    echo "✅ Exercise 03: Memory Protection (ASIL B) - Interference freedom"
    echo "✅ Exercise 04: Redundancy & Voting (ASIL C) - Fault tolerance"
    echo "✅ Exercise 05: Critical Systems (ASIL D) - Ultimate mastery ← MASTERED!"
    echo ""
    echo -e "${PURPLE}🌟 You Are Now:${NC}"
    echo "• An expert in automotive functional safety (ISO 26262)"
    echo "• Qualified to lead ASIL D project teams"
    echo "• Capable of designing life-critical automotive systems"
    echo "• Ready for senior safety engineering roles"
    echo "• Prepared for functional safety certification"
    echo ""
    echo -e "${CYAN}🔗 Continue Your Journey:${NC}"
    echo "• Explore advanced formal verification tools"
    echo "• Study real-world ASIL D case studies"
    echo "• Contribute to open-source safety projects"
    echo "• Pursue functional safety certification (TÜV, etc.)"
    echo "• Share your knowledge with the safety community"
    echo ""
    echo -e "${WHITE}🏅 CONGRATULATIONS - You are now an automotive safety master!${NC}"
    
    wait_for_user
}

# Main tutorial execution
main() {
    step_introduction
    step_asil_d_overview
    step_tmr_architecture
    step_formal_verification
    step_violation_analysis
    step_compliant_solution
    step_diverse_programming
    step_hands_on_mastery
    step_completion
    
    echo ""
    echo -e "${GOLD}🎖️ ASIL D mastery tutorial complete! You have achieved the ultimate level of automotive safety expertise! 🎖️${NC}"
}

# Handle Ctrl+C gracefully
trap 'echo -e "\n${YELLOW}Tutorial interrupted. Restart anytime with ./tutorial.sh to continue your path to ASIL D mastery${NC}"; exit 0' INT

# Run the tutorial
main