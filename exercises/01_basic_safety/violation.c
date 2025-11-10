/*
 * Exercise 01: Basic Safety - Violation Example
 * ============================================
 * 
 * ⚠️  This code demonstrates poor quality practices in automotive software
 * ⚠️  While ASIL QM (non-safety), these practices would be catastrophic in higher ASIL systems
 * 
 * System: Battery voltage monitoring for dashboard display
 * ASIL Level: QM (Quality Managed - no safety impact)
 * 
 * Poor Practices Demonstrated:
 * 1. No input validation
 * 2. Missing error handling
 * 3. No diagnostic information
 * 4. Potential undefined behavior
 * 5. Poor maintainability
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

// ❌ POOR PRACTICE 1: Magic numbers without explanation
#define SOME_VALUE 12
#define ANOTHER_VALUE 800

// ❌ POOR PRACTICE 2: Unclear global variables
int battery_reading;
float voltage_value;
int status;

// ❌ POOR PRACTICE 3: No input validation
float read_battery_voltage(void) {
    // Simulate reading from ADC
    // In real system: would read from analog-to-digital converter
    
    // ❌ POOR PRACTICE 4: Hardcoded simulation without bounds checking
    battery_reading = rand() % 1000;  // Random value 0-999
    
    // ❌ POOR PRACTICE 5: Unsafe type conversion
    voltage_value = (float)battery_reading / 100;  // Could be any value!
    
    return voltage_value;
}

// ❌ POOR PRACTICE 6: No return codes or error indication
void check_battery_status(void) {
    float voltage = read_battery_voltage();
    
    // ❌ POOR PRACTICE 7: Magic number comparisons without documentation
    if (voltage > SOME_VALUE) {
        status = 1;  // What does 1 mean?
        printf("Battery OK\n");
    } else if (voltage < 10.5) {
        status = 2;  // What does 2 mean?
        printf("Battery Low\n");
    } else {
        status = 0;  // What does 0 mean?
        printf("Battery Critical\n");
    }
    
    // ❌ POOR PRACTICE 8: No diagnostic data collection
    // Missing: timestamp, raw ADC values, conversion factors, etc.
}

// ❌ POOR PRACTICE 9: No parameter validation or bounds checking
void display_battery_info(int display_mode) {
    // ❌ POOR PRACTICE 10: Assumes display_mode is always valid
    switch (display_mode) {
        case 1:
            printf("Voltage: %.1f V\n", voltage_value);
            break;
        case 2:
            printf("Raw ADC: %d\n", battery_reading);
            break;
        default:
            // ❌ POOR PRACTICE 11: Default case does nothing - silent failure
            break;
    }
    
    // ❌ POOR PRACTICE 12: No error reporting if display fails
}

// ❌ POOR PRACTICE 13: No initialization or self-test
int main(void) {
    printf("❌ Battery Monitor - Poor Quality Example\n");
    printf("========================================\n");
    printf("⚠️  This code demonstrates BAD practices\n");
    printf("⚠️  Do not use these patterns in automotive software!\n");
    printf("========================================\n\n");
    
    // ❌ POOR PRACTICE 14: No system initialization checks
    
    printf("Running battery monitoring simulation...\n");
    
    for (int i = 0; i < 5; i++) {
        printf("\nReading %d:\n", i + 1);
        
        // ❌ POOR PRACTICE 15: No error checking on critical operations
        check_battery_status();
        
        // ❌ POOR PRACTICE 16: Hardcoded display mode without validation
        display_battery_info(1);  // What if this is not supported?
        
        printf("Status code: %d (meaning unclear)\n", status);
        
        // ❌ POOR PRACTICE 17: Fixed timing without consideration for system loading
        sleep(1);
    }
    
    // ❌ POOR PRACTICE 18: Simulate some "problematic" scenarios
    printf("\nSimulating edge cases...\n");
    
    // Force some unusual values
    battery_reading = -50;  // ❌ Negative ADC reading?
    voltage_value = (float)battery_reading / 100;
    printf("Negative voltage: %.1f V (This should never happen!)\n", voltage_value);
    
    battery_reading = 2000;  // ❌ ADC overflow?
    voltage_value = (float)battery_reading / 100;
    printf("Excessive voltage: %.1f V (This could damage electronics!)\n", voltage_value);
    
    // ❌ POOR PRACTICE 19: No graceful shutdown or cleanup
    printf("\n❌ Poor quality demo completed\n");
    printf("📚 Compare with compliant.c to see better practices!\n");
    
    return 0;
}

/*
 * Educational Analysis - What's Wrong Here?
 * =========================================
 * 
 * 1. Code Quality Issues:
 *    - Magic numbers without explanation
 *    - Unclear variable names and purposes
 *    - No comments explaining the logic
 *    - Inconsistent error handling approach
 * 
 * 2. Reliability Problems:
 *    - No input validation or range checking
 *    - Silent failures in error conditions
 *    - No diagnostic information collection
 *    - Potential for undefined behavior
 * 
 * 3. Maintainability Issues:
 *    - Hard to understand and modify
 *    - No clear interfaces or APIs
 *    - Difficult to test systematically
 *    - Poor separation of concerns
 * 
 * 4. Automotive-Specific Concerns:
 *    - No consideration for real-world constraints
 *    - Missing diagnostic and debugging support
 *    - No graceful degradation strategies
 *    - Poor preparation for higher ASIL requirements
 * 
 * Why This Matters in Automotive:
 * ==============================
 * 
 * Even though this is ASIL QM (non-safety), poor practices like these:
 * - Make debugging difficult in the field
 * - Reduce customer confidence in the vehicle
 * - Create maintenance nightmares for technicians
 * - Establish bad patterns that could be catastrophic in safety systems
 * 
 * In higher ASIL systems, these same patterns could:
 * - Cause unpredictable system behavior
 * - Lead to safety-critical failures
 * - Make certification impossible
 * - Result in product recalls or accidents
 */