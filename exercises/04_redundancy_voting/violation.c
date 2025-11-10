/*
 * AUTOMOTIVE SAFETY LAB - Exercise 04: Redundancy & Voting (ASIL C)
 * ===================================================================
 * 
 * ❌ VIOLATION EXAMPLE: Inadequate Redundancy for ASIL C
 * 
 * System: Electric Power Steering (EPS) Control System
 * ASIL Classification: ASIL C (S2+E4+C3 = Loss of vehicle control)
 * 
 * This implementation demonstrates CRITICAL SAFETY VIOLATIONS that
 * make the system unsuitable for ASIL C deployment in production.
 * 
 * 🚨 WARNING: This code contains 20+ intentional safety violations!
 *    Never use patterns from this file in real automotive systems!
 * 
 * Learning Goals:
 * - Understand why single-channel designs fail for ASIL C
 * - Recognize the need for systematic redundancy 
 * - Appreciate cross-checking and voting mechanisms
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>

/* 
 * ❌ VIOLATION 1: Missing redundancy framework
 * ASIL C requires multiple independent channels for critical functions
 */

// ❌ VIOLATION 2: Single sensor input without backup
typedef struct {
    float steering_angle;        // ❌ Single angle measurement
    float steering_torque;       // ❌ Single torque sensor
    float vehicle_speed;         // ❌ Single speed input
    int sensor_valid;            // ❌ Simple boolean validity
} steering_input_t;

// ❌ VIOLATION 3: Single control channel without redundancy
typedef struct {
    float target_assist_torque;  // ❌ Single control output
    int motor_enabled;           // ❌ Single enable signal
    int system_active;           // ❌ No redundant system state
} steering_control_t;

// ❌ VIOLATION 4: No cross-checking mechanisms
typedef struct {
    steering_input_t input;      // ❌ Single input path
    steering_control_t control;  // ❌ Single control path
    int error_count;             // ❌ Simple error counter
} eps_system_t;

// ❌ VIOLATION 5: Global variables without protection
eps_system_t g_eps_system;       // ❌ Single system instance
int g_system_errors = 0;        // ❌ Unprotected error tracking
float g_last_valid_angle = 0.0;  // ❌ Single backup value

// ❌ VIOLATION 6: No plausibility checking between sensors
float process_steering_input(steering_input_t* input) {
    // ❌ VIOLATION 7: No input validation
    if (!input) return 0.0;
    
    // ❌ VIOLATION 8: No range checking  
    float assist_ratio = input->steering_torque * 0.8;  // ❌ Magic number
    
    // ❌ VIOLATION 9: No physical plausibility checks
    if (input->vehicle_speed > 100.0) {
        assist_ratio *= 0.5;  // ❌ Simple speed reduction
    }
    
    return assist_ratio;
}

/*
 * ❌ VIOLATION 10: Single-channel motor control
 * ASIL C requires redundant actuator control paths
 */
int control_steering_motor(float assist_torque) {
    // ❌ VIOLATION 11: No safety state verification
    if (g_eps_system.control.system_active == 0) {
        return -1;  // ❌ Unsafe return value
    }
    
    // ❌ VIOLATION 12: Direct motor control without validation
    if (fabs(assist_torque) > 50.0) {  // ❌ Hard-coded limit
        printf("Motor torque: %.2f Nm\n", assist_torque);
        return 1;
    }
    
    return 0;
}

/*
 * ❌ VIOLATION 13: No diagnostic coverage for failures
 * ASIL C requires comprehensive fault detection
 */
void run_system_diagnostics() {
    // ❌ VIOLATION 14: Minimal diagnostic coverage
    if (g_system_errors > 5) {  // ❌ Arbitrary threshold
        printf("Error threshold exceeded!\n");
    }
    
    // ❌ VIOLATION 15: No systematic fault injection testing
    // Missing comprehensive fault coverage
}

/*
 * ❌ VIOLATION 16: No voting mechanism for decision making
 * ASIL C typically requires 2-out-of-2 or 2-out-of-3 voting
 */
int make_steering_decision(steering_input_t* input) {
    // ❌ VIOLATION 17: Single decision path
    float assist_torque = process_steering_input(input);
    
    // ❌ VIOLATION 18: No cross-validation
    if (assist_torque != 0.0) {
        return control_steering_motor(assist_torque);
    }
    
    return 0;
}

/*
 * ❌ VIOLATION 19: Inadequate error handling
 */
void handle_system_error(int error_type) {
    // ❌ VIOLATION 20: No systematic error classification
    g_system_errors++;
    
    // ❌ VIOLATION 21: No graceful degradation
    if (g_system_errors > 10) {
        exit(1);  // ❌ Unsafe system shutdown
    }
}

/*
 * ❌ VIOLATION 22: Main control loop without safety architecture
 */
int main() {
    printf("🚨 AUTOMOTIVE SAFETY LAB - Exercise 04: Redundancy & Voting\n");
    printf("❌ VIOLATION EXAMPLE: Inadequate ASIL C Implementation\n");
    printf("======================================================\n\n");
    
    // ❌ VIOLATION 23: No redundant system initialization
    memset(&g_eps_system, 0, sizeof(eps_system_t));
    g_eps_system.control.system_active = 1;  // ❌ Direct activation
    
    printf("Simulating Electric Power Steering System...\n\n");
    
    // ❌ VIOLATION 24: Single sensor scenario without backup
    steering_input_t input = {
        .steering_angle = 15.0,    // ❌ 15 degrees left turn
        .steering_torque = 8.5,    // ❌ 8.5 Nm driver torque  
        .vehicle_speed = 45.0,     // ❌ 45 km/h
        .sensor_valid = 1          // ❌ Simple validity flag
    };
    
    printf("Driver Input: Angle=%.1f°, Torque=%.1f Nm, Speed=%.1f km/h\n",
           input.steering_angle, input.steering_torque, input.vehicle_speed);
    
    // ❌ VIOLATION 25: No redundant processing
    int result = make_steering_decision(&input);
    
    if (result > 0) {
        printf("✅ Steering assist applied\n\n");
    } else {
        printf("❌ Steering assist failed\n\n");
    }
    
    printf("🚨 CRITICAL SAFETY VIOLATIONS IDENTIFIED:\n");
    printf("========================================\n");
    printf("1.  Single sensor channels - no redundancy\n");
    printf("2.  No cross-checking between independent channels\n");
    printf("3.  Missing 2-out-of-2 or 2-out-of-3 voting\n");
    printf("4.  Single motor control path - no backup\n");
    printf("5.  Inadequate diagnostic coverage for ASIL C\n");
    printf("6.  No plausibility checking between sensors\n");
    printf("7.  Missing systematic fault detection\n");
    printf("8.  No graceful degradation mechanisms\n");
    printf("9.  Single points of failure throughout system\n");
    printf("10. No hardware diversity or separation\n");
    printf("11. Insufficient error handling and recovery\n");
    printf("12. Missing safety monitoring and supervision\n");
    printf("13. No systematic safety architecture\n");
    printf("14. Inadequate fail-safe mechanisms\n");
    printf("15. Missing safety case documentation\n\n");
    
    printf("🎯 LEARNING OBJECTIVE:\n");
    printf("Understand why ASIL C requires sophisticated redundancy\n");
    printf("and voting mechanisms. Single-channel designs cannot\n");
    printf("meet the reliability and safety requirements for systems\n");
    printf("where failure could result in serious injury.\n\n");
    
    printf("➡️  Next: Run the compliant example to see proper ASIL C redundancy:\n");
    printf("    bazel run //exercises/04_redundancy_voting:compliant_example\n\n");
    
    return 0;
}

/*
 * 📚 ASIL C REQUIREMENTS SUMMARY (ISO 26262)
 * ==========================================
 * 
 * 1. HARDWARE REQUIREMENTS:
 *    - Dual-channel architecture (minimum)
 *    - Cross-monitoring between channels
 *    - Hardware diagnostic coverage >95%
 *    - Single Point of Failure Metric (SPFM) >95%
 *    - Latent Fault Metric (LFM) >85%
 * 
 * 2. SOFTWARE REQUIREMENTS:
 *    - Diverse programming or N-version programming
 *    - Comprehensive testing with statement coverage >95%
 *    - Static analysis with qualified tools
 *    - Systematic software architectural design
 * 
 * 3. ARCHITECTURAL REQUIREMENTS:  
 *    - 2-out-of-2 or 2-out-of-3 voting systems
 *    - Cross-checking and plausibility analysis
 *    - Graceful degradation under single failures
 *    - Hardware/software partitioning and separation
 * 
 * 4. VERIFICATION REQUIREMENTS:
 *    - Requirements-based testing with MC/DC coverage
 *    - Fault injection testing for diagnostic coverage
 *    - Integration testing with systematic approach
 *    - Safety case with quantitative evidence
 * 
 * 🚀 Ready to see how proper redundancy works? Check the compliant example!
 */