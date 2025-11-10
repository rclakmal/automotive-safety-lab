/*
 * AUTOMOTIVE SAFETY LAB - Exercise 05: Critical Systems (ASIL D)
 * =================================================================
 * 
 * ❌ VIOLATION EXAMPLE: Inadequate Safety Architecture for ASIL D
 * 
 * System: Autonomous Emergency Braking (AEB) for Highway Scenarios
 * ASIL Classification: ASIL D (S3+E4+C3 = Potentially Fatal)
 * 
 * This implementation demonstrates CRITICAL SAFETY VIOLATIONS that
 * make the system unsuitable for ASIL D deployment in production.
 * 
 * 🚨 WARNING: This code contains 25+ intentional safety violations!
 *    Never use patterns from this file in real automotive systems!
 * 
 * Learning Goals:
 * - Understand what makes ASIL D requirements so stringent
 * - Recognize systematic failure modes in safety-critical systems
 * - Appreciate the complexity of life-critical automotive functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <math.h>

/* 
 * ❌ VIOLATION 1: Missing safety-critical includes
 * ASIL D requires comprehensive safety headers for:
 * - Hardware abstraction layer
 * - Safety monitoring
 * - Diagnostic services
 * - Memory protection
 */

// ❌ VIOLATION 2: No safety lifecycle management
// Missing ISO 26262 safety lifecycle declarations

// ❌ VIOLATION 3: Inadequate data types for safety-critical operations
typedef struct {
    float distance;           // ❌ Should use fixed-point for deterministic behavior
    float relative_speed;     // ❌ Float precision issues in critical calculations
    int confidence;           // ❌ No safety validation or range checking
    char sensor_status;       // ❌ Single byte status insufficient for ASIL D
} sensor_data_t;

// ❌ VIOLATION 4: No redundancy in critical data structures
typedef struct {
    sensor_data_t radar;      // ❌ Single sensor path - no redundancy
    sensor_data_t camera;     // ❌ No cross-validation between sensors
    int brake_command;        // ❌ Single brake command path
    int system_active;        // ❌ No safety state machine
} aeb_system_t;

// ❌ VIOLATION 5: Global variables without protection
aeb_system_t g_aeb_system;    // ❌ No memory protection or access control
int g_system_errors = 0;     // ❌ Error handling without safety mechanisms
float g_last_brake_time = 0; // ❌ Critical timing data unprotected

// ❌ VIOLATION 6: No formal safety properties defined
// Missing mathematical specification of safety requirements

/*
 * ❌ VIOLATION 7: Inadequate sensor fusion
 * Real ASIL D systems require sophisticated sensor fusion with:
 * - Multiple independent sensor channels
 * - Cross-validation algorithms
 * - Fault detection and isolation
 */
float calculate_collision_risk(sensor_data_t* sensors) {
    // ❌ VIOLATION 8: No input validation
    if (!sensors) return 0.0;  // ❌ Silent failure mode
    
    // ❌ VIOLATION 9: Unsafe floating-point arithmetic
    float time_to_collision = sensors->distance / sensors->relative_speed;
    
    // ❌ VIOLATION 10: No overflow/underflow protection
    if (sensors->relative_speed < 0.1) {
        return 0.0;  // ❌ Division by near-zero without proper handling
    }
    
    // ❌ VIOLATION 11: Magic numbers without safety justification
    if (time_to_collision < 2.5) {  // ❌ Hard-coded threshold
        return 1.0;  // ❌ Binary decision instead of graduated response
    }
    
    return 0.0;
}

/*
 * ❌ VIOLATION 12: Single-channel brake control
 * ASIL D requires multiple independent brake control channels
 */
int apply_emergency_brake(float risk_level) {
    // ❌ VIOLATION 13: No safety state verification
    if (g_aeb_system.system_active == 0) {
        return -1;  // ❌ Unsafe error return
    }
    
    // ❌ VIOLATION 14: Direct hardware control without safety monitoring
    if (risk_level > 0.5) {
        // ❌ VIOLATION 15: No gradual brake application
        printf("EMERGENCY BRAKE ACTIVATED!\n");  // ❌ Simple print instead of hardware control
        g_last_brake_time = clock();             // ❌ No atomic operations
        return 1;
    }
    
    return 0;
}

/*
 * ❌ VIOLATION 16: Inadequate diagnostic coverage
 * ASIL D requires >99% diagnostic coverage with specified latency
 */
void run_diagnostics() {
    // ❌ VIOLATION 17: Incomplete diagnostic suite
    if (g_system_errors > 10) {  // ❌ Arbitrary threshold
        printf("Too many errors!\n");  // ❌ No proper fault handling
        exit(1);  // ❌ Unsafe system shutdown
    }
    
    // ❌ VIOLATION 18: No systematic fault injection testing
    // Missing comprehensive fault coverage analysis
}

/*
 * ❌ VIOLATION 19: No voting mechanism for redundant channels
 * ASIL D typically requires 2-out-of-3 voting for critical decisions
 */
int make_brake_decision(sensor_data_t* radar, sensor_data_t* camera) {
    // ❌ VIOLATION 20: Simple OR logic instead of sophisticated voting
    float radar_risk = calculate_collision_risk(radar);
    float camera_risk = calculate_collision_risk(camera);
    
    // ❌ VIOLATION 21: No plausibility checking between sensors
    if (radar_risk > 0.5 || camera_risk > 0.5) {
        return 1;  // ❌ Brake decision without proper validation
    }
    
    return 0;
}

/*
 * ❌ VIOLATION 22: Main control loop without safety framework
 */
int main() {
    printf("🚨 AUTOMOTIVE SAFETY LAB - Exercise 05: Critical Systems\n");
    printf("❌ VIOLATION EXAMPLE: Inadequate ASIL D Implementation\n");
    printf("====================================================\n\n");
    
    // ❌ VIOLATION 23: No safety initialization sequence
    memset(&g_aeb_system, 0, sizeof(aeb_system_t));
    g_aeb_system.system_active = 1;  // ❌ Direct activation without safety checks
    
    printf("Simulating Autonomous Emergency Braking System...\n\n");
    
    // ❌ VIOLATION 24: Hardcoded test scenarios instead of formal verification
    sensor_data_t radar_data = {50.0, 30.0, 85, 'O'};     // ❌ No validation
    sensor_data_t camera_data = {52.0, 28.0, 90, 'O'};    // ❌ No cross-checking
    
    printf("Scenario: Vehicle approaching at 30 m/s, distance 50m\n");
    printf("Radar:  Distance=%.1fm, Speed=%.1fm/s, Confidence=%d%%\n", 
           radar_data.distance, radar_data.relative_speed, radar_data.confidence);
    printf("Camera: Distance=%.1fm, Speed=%.1fm/s, Confidence=%d%%\n\n", 
           camera_data.distance, camera_data.relative_speed, camera_data.confidence);
    
    // ❌ VIOLATION 25: No formal safety analysis
    int brake_decision = make_brake_decision(&radar_data, &camera_data);
    
    if (brake_decision) {
        apply_emergency_brake(1.0);
        printf("✅ Emergency braking applied!\n\n");
    } else {
        printf("❌ No braking action taken!\n\n");
    }
    
    // ❌ VIOLATION 26: No safety case documentation generated
    printf("🚨 CRITICAL SAFETY VIOLATIONS IDENTIFIED:\n");
    printf("=========================================\n");
    printf("1.  No triple modular redundancy (TMR)\n");
    printf("2.  Missing formal verification of safety properties\n");
    printf("3.  Single points of failure throughout system\n");
    printf("4.  No hardware diversity or architectural separation\n");
    printf("5.  Inadequate diagnostic coverage (<99%% required)\n");
    printf("6.  No fail-operational design - system fails unsafe\n");
    printf("7.  Missing systematic fault injection testing\n");
    printf("8.  No diverse programming techniques applied\n");
    printf("9.  Insufficient sensor fusion and plausibility checking\n");
    printf("10. No safety lifecycle management per ISO 26262\n");
    printf("11. Missing comprehensive V&V documentation\n");
    printf("12. No quantified safety analysis (FIT rates, SFF, etc.)\n");
    printf("13. Unsafe error handling and degradation modes\n");
    printf("14. No freedom from interference between safety functions\n");
    printf("15. Missing safety monitoring and health management\n\n");
    
    printf("🎯 LEARNING OBJECTIVE:\n");
    printf("Understand why ASIL D requires the most sophisticated safety\n");
    printf("architectures in automotive engineering. Every aspect must be\n");
    printf("formally verified, redundant, and designed for fail-operational\n");
    printf("behavior to protect human life in critical scenarios.\n\n");
    
    printf("➡️  Next: Run the compliant example to see proper ASIL D implementation:\n");
    printf("    bazel run //exercises/05_critical_systems:compliant_example\n\n");
    
    return 0;
}

/*
 * 📚 ASIL D REQUIREMENTS SUMMARY (ISO 26262)
 * ==========================================
 * 
 * 1. HARDWARE REQUIREMENTS:
 *    - Hardware architectural metrics must be satisfied
 *    - Diverse hardware platforms for redundant channels  
 *    - Comprehensive diagnostic coverage (>99%)
 *    - Single Point of Failure Metric (SPFM) >99%
 *    - Latent Fault Metric (LFM) >90%
 * 
 * 2. SOFTWARE REQUIREMENTS:
 *    - Formal methods for specification and verification
 *    - Diverse programming (multiple independent implementations)
 *    - Comprehensive unit/integration/system testing
 *    - Static analysis with tool qualification (ASIL D)
 *    - Model-based development with automatic code generation
 * 
 * 3. ARCHITECTURAL REQUIREMENTS:
 *    - Freedom from interference between safety elements
 *    - Fail-operational or fail-silent behavior
 *    - Multiple independent processing channels
 *    - 2-out-of-3 voting for critical decisions
 *    - Hardware/software architectural separation
 * 
 * 4. VERIFICATION REQUIREMENTS:
 *    - Formal verification of safety properties
 *    - Comprehensive fault injection testing
 *    - Requirements-based testing with full traceability
 *    - Safety case with quantified evidence
 *    - Independent assessment by competent authority
 * 
 * 🚀 Ready to see how it's done right? Check the compliant example!
 */