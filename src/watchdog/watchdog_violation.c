/*
 * Watchdog Timer Implementation - Safety Violation Example
 * =======================================================
 * 
 * ⚠️  WARNING: This code contains intentional ISO 26262 violations for educational purposes
 * ⚠️  DO NOT use this code in production automotive systems
 * 
 * Educational Purpose: Demonstrates common watchdog timer implementation mistakes
 * that violate ISO 26262 requirements for timing supervision.
 * 
 * ASIL Context: ASIL A - Basic timing supervision for non-critical functions
 * 
 * Violations Demonstrated:
 * 1. No proper watchdog initialization sequence
 * 2. Missing watchdog kick validation
 * 3. No timeout handling mechanism
 * 4. Lack of diagnostic information
 * 5. No safe state transition on failure
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

// ❌ VIOLATION 1: No proper type definitions for safety-critical data
typedef struct {
    int timeout_ms;           // Should be uint32_t with validation
    int kick_counter;         // Should track kick patterns
    bool enabled;             // Should have safety state validation
} unsafe_watchdog_t;

// ❌ VIOLATION 2: Global variable without protection
unsafe_watchdog_t g_watchdog;

// ❌ VIOLATION 3: No return codes for error handling
void unsafe_watchdog_init(int timeout_ms) {
    printf("❌ Initializing UNSAFE watchdog (timeout: %d ms)\n", timeout_ms);
    
    // ❌ VIOLATION 4: No parameter validation
    g_watchdog.timeout_ms = timeout_ms;  // What if timeout_ms is negative?
    g_watchdog.kick_counter = 0;
    g_watchdog.enabled = true;
    
    // ❌ VIOLATION 5: No hardware watchdog configuration
    // Real systems need to configure hardware watchdog registers
    
    // ❌ VIOLATION 6: No initialization verification
    // Should verify watchdog is actually working
}

// ❌ VIOLATION 7: No pattern-based watchdog kicking
void unsafe_watchdog_kick(void) {
    // ❌ VIOLATION 8: No timing validation
    // Should check if kick is happening within acceptable window
    
    g_watchdog.kick_counter++;
    
    printf("  🦵 Kicked watchdog (count: %d) - NO SAFETY CHECKS\n", 
           g_watchdog.kick_counter);
    
    // ❌ VIOLATION 9: No actual hardware watchdog reset
    // Real implementation would reset hardware watchdog timer
    
    // ❌ VIOLATION 10: No diagnostic data collection
    // Should log timing information for analysis
}

// ❌ VIOLATION 11: No proper timeout detection
bool unsafe_check_watchdog_status(void) {
    // ❌ VIOLATION 12: Always returns success (no real monitoring)
    return true;  // Lie about watchdog status
    
    // ❌ VIOLATION 13: No actual timeout detection logic
    // Real implementation would check elapsed time since last kick
}

// ❌ VIOLATION 14: No safe state handling
void unsafe_watchdog_timeout_handler(void) {
    printf("🚨 WATCHDOG TIMEOUT - but no safe actions taken!\n");
    
    // ❌ VIOLATION 15: No immediate safety actions
    // Should disable actuators, set safe outputs, etc.
    
    // ❌ VIOLATION 16: No system reset or recovery
    // Automotive systems typically reset on watchdog timeout
    
    // ❌ VIOLATION 17: No fault logging
    // Should record timeout event for diagnostic analysis
}

// ❌ VIOLATION 18: Main function without proper safety framework
int main(void) {
    printf("❌ ISO 26262 WATCHDOG VIOLATION EXAMPLE\n");
    printf("======================================\n");
    printf("⚠️  This demonstrates UNSAFE watchdog patterns\n");
    printf("⚠️  Contains multiple violations of ISO 26262\n");
    printf("⚠️  DO NOT USE in production systems!\n");
    printf("======================================\n\n");
    
    // ❌ VIOLATION 19: No system safety checks before starting
    unsafe_watchdog_init(1000);  // 1 second timeout
    
    printf("Running unsafe watchdog demo for 5 iterations...\n");
    
    for (int i = 0; i < 5; i++) {
        printf("Iteration %d:\n", i + 1);
        
        // ❌ VIOLATION 20: No controlled timing for kicks
        sleep(1);  // Might exceed watchdog timeout
        
        unsafe_watchdog_kick();
        
        // ❌ VIOLATION 21: No status monitoring
        bool status = unsafe_check_watchdog_status();
        printf("  Watchdog status: %s (but this is fake!)\n", 
               status ? "OK" : "FAULT");
        
        printf("\n");
    }
    
    // ❌ VIOLATION 22: Simulate timeout without proper handling
    printf("Simulating watchdog timeout...\n");
    unsafe_watchdog_timeout_handler();
    
    printf("\n❌ Unsafe watchdog demo completed\n");
    printf("📚 Study watchdog_compliant.c for proper implementation!\n");
    
    return 0;
}

/*
 * Educational Analysis - Violations Summary:
 * ==========================================
 * 
 * 1. Initialization Failures (Violations 1-6):
 *    - No type safety or parameter validation
 *    - Missing hardware configuration
 *    - No self-test or verification
 * 
 * 2. Runtime Monitoring Failures (Violations 7-13):
 *    - No timing window validation
 *    - No pattern-based kicking
 *    - No real status monitoring
 * 
 * 3. Safety Response Failures (Violations 14-17):
 *    - No timeout detection
 *    - No safe state transitions
 *    - No fault recording
 * 
 * 4. System Integration Failures (Violations 18-22):
 *    - No safety framework
 *    - No controlled execution
 *    - No proper shutdown sequence
 * 
 * ISO 26262 Requirements Violated:
 * - Part 6, Clause 7: Software safety requirements
 * - Part 6, Clause 9: Software architectural design
 * - Part 4, Clause 7: Safety mechanisms
 * - Part 8, Clause 14: Validation of safety requirements
 */