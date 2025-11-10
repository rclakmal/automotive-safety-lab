/**
 * @file violation.c  
 * @brief DANGEROUS Watchdog Implementation - Multiple Timing Safety Violations
 * @author Automotive Safety Lab
 * @warning THIS CODE CONTAINS INTENTIONAL SAFETY VIOLATIONS - DO NOT USE IN PRODUCTION
 * 
 * Learning Exercise: Identify timing safety violations in this engine control watchdog
 * Real-world scenario: ECM (Engine Control Module) fuel injection timing
 * HARA: S2+E4+C2 = ASIL A - Engine stall at highway speeds
 * 
 * Expected Violations to Find:
 * - Inconsistent watchdog timing
 * - No safe state implementation  
 * - Missing diagnostic coverage
 * - Race conditions in timing logic
 * - No timeout validation
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// VIOLATION 1: No timing constants defined - magic numbers throughout code
#define MAX_FUEL_PRESSURE 250

// VIOLATION 2: Global variables without protection
static uint32_t watchdog_counter = 0;
static bool system_active = true;
volatile uint32_t fuel_injection_timing = 0;
static uint32_t last_kick_time = 0;

// VIOLATION 3: No diagnostic or monitoring interface
// Missing: Safety state reporting, fault counters, diagnostic coverage

/**
 * @brief Engine Control Main Loop - VIOLATION EXAMPLES
 * @warning Multiple timing safety violations present
 */
void engine_control_loop(void)
{
    printf("🔥 VIOLATION ENGINE: Starting Dangerous Watchdog Implementation\n");
    printf("   System: ECM (Engine Control Module)\n");
    printf("   Function: Fuel injection timing control\n");
    printf("   Failure Risk: Engine stall at highway speeds\n\n");
    
    // VIOLATION 4: No initialization of timing systems
    // Missing: Watchdog timer setup, safe state validation
    
    for (int cycle = 1; cycle <= 10; cycle++) {
        printf("--- Engine Cycle %d ---\n", cycle);
        
        // VIOLATION 5: Inconsistent cycle timing - random delays
        if (cycle % 3 == 0) {
            printf("  💀 Simulating system delay... (network request)\n");
            usleep(75000);  // 75ms delay - exceeds 10ms requirement!
        }
        
        // VIOLATION 6: Complex fuel calculation without timing protection
        uint32_t fuel_amount = calculate_fuel_injection();
        
        // VIOLATION 7: Watchdog kick at wrong time - should be at cycle start
        kick_watchdog();
        
        // VIOLATION 8: No timeout checking before critical operation
        inject_fuel(fuel_amount);
        
        // VIOLATION 9: Variable timing between cycles (1-5 seconds!)
        sleep(cycle % 5 + 1);
        
        printf("  Fuel injected: %d units\n", fuel_amount);
    }
    
    // VIOLATION 10: No final safety check or safe state transition
    printf("\n💥 Engine control ending - NO SAFE STATE IMPLEMENTATION!\n");
}

/**
 * @brief Fuel Calculation - TIMING VIOLATIONS
 */
uint32_t calculate_fuel_injection(void)
{
    // VIOLATION 11: Blocking operation without timeout
    printf("  🧮 Calculating fuel injection (blocking operation)...\n");
    
    // VIOLATION 12: Non-deterministic timing - depends on system load
    for (volatile int i = 0; i < rand() % 1000000; i++) {
        // Simulates variable computation time
    }
    
    // VIOLATION 13: No input validation or bounds checking
    uint32_t throttle_position = rand() % 500;  // Could exceed valid range!
    uint32_t engine_rpm = rand() % 8000;
    
    // VIOLATION 14: Complex calculation without timing supervision
    uint32_t fuel_amount = (throttle_position * engine_rpm) / 100;
    
    // VIOLATION 15: No result validation before returning
    return fuel_amount;  // Could be dangerously high!
}

/**
 * @brief Fuel Injection - NO SAFETY MECHANISMS
 */
void inject_fuel(uint32_t amount)
{
    // VIOLATION 16: No safety limits checking
    printf("  ⛽ Injecting %d units of fuel (no limits check)\n", amount);
    
    // VIOLATION 17: No feedback or confirmation of operation
    fuel_injection_timing = amount;  // Just set global variable
    
    // VIOLATION 18: Missing critical failure detection
    if (amount > 1000) {
        printf("  ⚠️  WARNING: Excessive fuel amount detected!\n");
        // VIOLATION 19: Warning only - no corrective action taken
    }
}

/**
 * @brief Dangerous Watchdog Implementation
 */
void kick_watchdog(void)
{
    watchdog_counter++;
    
    // VIOLATION 20: No timing validation
    uint32_t current_time = (uint32_t)time(NULL);
    
    // VIOLATION 21: No check if kick is too early or too late
    printf("  🐕 Kicking watchdog (#%d) - no timing validation\n", watchdog_counter);
    
    // VIOLATION 22: No pattern validation - accepts any kick
    last_kick_time = current_time;
    
    // VIOLATION 23: Missing safety state check before kick
    // Should verify system health before watchdog reset
}

/**
 * @brief Missing Watchdog Timeout Handler
 * VIOLATION 24: This function should exist but doesn't!
 */
// void watchdog_timeout_handler(void) { /* NOT IMPLEMENTED */ }

/**
 * @brief Missing Safe State Implementation  
 * VIOLATION 25: No safe state function defined
 */
// void enter_safe_state(void) { /* NOT IMPLEMENTED */ }

/**
 * @brief Main Function - Integration of Violations
 */
int main(void)
{
    printf("=== ISO 26262 Exercise 02: Watchdog Violations ===\n");
    printf("🎯 Challenge: Find 25+ timing safety violations\n");
    printf("🚗 Context: Engine Control Module (ASIL A)\n");
    printf("⚠️  Risk: Engine stall at highway speeds\n\n");
    
    // VIOLATION 26: No system initialization or self-test
    
    // VIOLATION 27: No watchdog timer hardware setup
    printf("⏰ Missing: Watchdog timer initialization\n");
    
    // VIOLATION 28: No diagnostic system initialization
    printf("📊 Missing: Safety diagnostic setup\n");
    
    printf("\n");
    engine_control_loop();
    
    // VIOLATION 29: No system shutdown procedure
    printf("\n⚠️  System ending without proper shutdown sequence\n");
    printf("💀 DANGEROUS: No safe state achieved\n\n");
    
    printf("🎓 LEARNING CHALLENGE:\n");
    printf("   → Count the timing safety violations you found\n");
    printf("   → Expected: 25+ violations of ISO 26262 timing requirements\n");
    printf("   → Compare with compliant implementation\n");
    
    return 0;
}

/**
 * SUMMARY OF MAJOR VIOLATION CATEGORIES:
 * 
 * 1. TIMING VIOLATIONS (Most Critical):
 *    - Inconsistent watchdog kick timing
 *    - Variable cycle timing (1-5 seconds vs 10ms requirement)  
 *    - No timeout validation or deadline monitoring
 *    - Blocking operations without time bounds
 *    - Non-deterministic computation timing
 * 
 * 2. WATCHDOG IMPLEMENTATION FAILURES:
 *    - No watchdog timer hardware setup
 *    - Missing timeout handler implementation
 *    - No pattern-based validation
 *    - Watchdog kick at wrong time in cycle
 *    - No early/late kick detection
 * 
 * 3. SAFE STATE VIOLATIONS:
 *    - No safe state function implemented
 *    - No safe state transition on failures  
 *    - No system shutdown procedure
 *    - Missing critical failure detection
 *    - No corrective actions on violations
 * 
 * 4. DIAGNOSTIC COVERAGE GAPS:
 *    - No fault detection mechanisms
 *    - Missing safety monitoring interface
 *    - No diagnostic self-tests
 *    - No fault counters or logging
 *    - Insufficient input validation
 * 
 * 5. ASIL A REQUIREMENT VIOLATIONS:
 *    - Missing single-point fault tolerance
 *    - Inadequate diagnostic coverage (<90%)
 *    - No requirements traceability
 *    - Missing verification evidence
 *    - No systematic safety analysis
 */