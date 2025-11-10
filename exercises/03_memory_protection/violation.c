/**
 * @file violation.c  
 * @brief DANGEROUS Memory Management Implementation - Multiple Memory Safety Violations
 * @author Automotive Safety Lab
 * @warning THIS CODE CONTAINS INTENTIONAL MEMORY SAFETY VIOLATIONS - DO NOT USE IN PRODUCTION
 * 
 * Learning Exercise: Identify memory safety violations in brake control system
 * Real-world scenario: Electronic Brake System (EBS) with ABS and stability control
 * HARA: S3+E4+C3 = ASIL B - Loss of braking capability
 * 
 * Expected Violations to Find:
 * - Buffer overflows and underflows
 * - Memory corruption and interference
 * - Unprotected shared memory access
 * - Missing memory isolation
 * - Dynamic allocation without protection
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// VIOLATION 1: No memory protection constants - unsafe sizes everywhere
#define MAX_BRAKE_PRESSURE 1000
#define WHEEL_COUNT 4

// VIOLATION 2: Global shared memory without protection
static uint32_t brake_pressure[WHEEL_COUNT];
static char system_log[100];  // Small buffer - overflow risk!
static uint32_t* shared_sensor_data;  // Unprotected shared pointer
static bool abs_active = false;

// VIOLATION 3: No memory isolation between safety levels
// Safety-critical brake data mixed with non-safety infotainment data
typedef struct {
    uint32_t brake_force[4];        // Safety-critical
    char radio_station[50];         // Non-safety - INTERFERENCE RISK!
    uint32_t wheel_speed[4];        // Safety-critical
    char bluetooth_name[100];       // Non-safety - INTERFERENCE RISK!
    uint32_t abs_status;            // Safety-critical
    char navigation_dest[200];      // Non-safety - LARGE BUFFER RISK!
} mixed_vehicle_data_t;  // VIOLATION: Mixed safety levels in same struct

static mixed_vehicle_data_t g_vehicle_data;  // VIOLATION: No protection

// VIOLATION 4: No stack protection or bounds checking
/**
 * @brief Brake Control Main Loop - VIOLATION EXAMPLES
 * @warning Multiple memory safety violations present
 */
void brake_control_loop(void)
{
    printf("🔥 VIOLATION BRAKE SYSTEM: Starting Dangerous Memory Implementation\n");
    printf("   System: Electronic Brake System (EBS)\n");
    printf("   Function: ABS and stability control\n");
    printf("   Failure Risk: Loss of braking capability\n\n");
    
    // VIOLATION 5: Large stack buffer without protection
    char temp_buffer[1000];  // Large stack allocation - overflow risk
    uint32_t sensor_readings[100];  // Another large buffer
    
    for (int cycle = 1; cycle <= 8; cycle++) {
        printf("--- Brake Cycle %d ---\n", cycle);
        
        // VIOLATION 6: Unsafe string operations without bounds checking
        char user_input[20];
        printf("  Enter brake test data (or 'auto' for simulation): ");
        
        // VIOLATION 7: Gets() equivalent - classic buffer overflow
        if (fgets(user_input, sizeof(user_input), stdin)) {
            // VIOLATION 8: Strcpy without length checking
            strcpy(temp_buffer, "Brake test data: ");
            strcat(temp_buffer, user_input);  // Potential overflow!
            
            // VIOLATION 9: Writing to unvalidated buffer location
            strcat(temp_buffer, " - Processing in dangerous memory system");
        } else {
            strcpy(temp_buffer, "auto");
        }
        
        // VIOLATION 10: Unsafe memory access based on user input
        if (strstr(temp_buffer, "auto")) {
            // VIOLATION 11: No bounds checking on array access
            for (int i = 0; i < cycle * 15; i++) {  // i can exceed array bounds!
                sensor_readings[i] = rand() % 1000;  // Buffer overflow when cycle > 6!
            }
        }
        
        // VIOLATION 12: Processing unsafe buffer data
        process_brake_sensors(temp_buffer, sensor_readings);
        
        // VIOLATION 13: Unsafe dynamic memory allocation
        apply_brake_force(cycle);
        
        printf("  Cycle %d: Buffer used %zu bytes\n", cycle, strlen(temp_buffer));
    }
    
    // VIOLATION 14: No memory cleanup or validation
    printf("\n💥 Brake system ending - NO MEMORY PROTECTION!\n");
}

/**
 * @brief Sensor Processing - MEMORY CORRUPTION VIOLATIONS
 */
void process_brake_sensors(char* input_buffer, uint32_t* sensor_data)
{
    // VIOLATION 15: No input parameter validation
    printf("  🧮 Processing brake sensors (unsafe memory access)...\n");
    
    // VIOLATION 16: Unsafe pointer arithmetic without bounds
    uint32_t* data_ptr = sensor_data;
    for (int i = 0; i < 20; i++) {  // May exceed allocated memory!
        *(data_ptr + i) = rand() % MAX_BRAKE_PRESSURE;
    }
    
    // VIOLATION 17: Mixing safety-critical and non-safety data
    sprintf(g_vehicle_data.radio_station, "FM %.1f", (rand() % 200) / 10.0);
    sprintf(g_vehicle_data.bluetooth_name, "Driver_%d_Phone", rand() % 100);
    
    // VIOLATION 18: Writing safety-critical data adjacent to non-safety buffers
    for (int wheel = 0; wheel < WHEEL_COUNT; wheel++) {
        g_vehicle_data.brake_force[wheel] = *(data_ptr + wheel);
        g_vehicle_data.wheel_speed[wheel] = *(data_ptr + wheel + 4);
    }
    
    // VIOLATION 19: No memory barrier or protection between operations
    g_vehicle_data.abs_status = (rand() % 2) ? 1 : 0;
    
    // VIOLATION 20: Unsafe navigation destination that could overflow
    snprintf(g_vehicle_data.navigation_dest, sizeof(g_vehicle_data.navigation_dest),
             "Long destination name that might be too long: %s %s %s %s",
             input_buffer, input_buffer, input_buffer, input_buffer);
}

/**
 * @brief Brake Force Application - DYNAMIC MEMORY VIOLATIONS
 */
void apply_brake_force(int cycle)
{
    // VIOLATION 21: Unsafe dynamic allocation without error checking
    uint32_t* dynamic_force_data = (uint32_t*)malloc(cycle * 100 * sizeof(uint32_t));
    
    // VIOLATION 22: No null pointer check after allocation
    printf("  ⚠️  Applying brake force with dynamic allocation\n");
    
    // VIOLATION 23: Writing to potentially invalid memory
    for (int i = 0; i < cycle * 10; i++) {
        dynamic_force_data[i] = rand() % MAX_BRAKE_PRESSURE;
    }
    
    // VIOLATION 24: Shared memory access without synchronization
    shared_sensor_data = dynamic_force_data;  // Race condition risk!
    
    // VIOLATION 25: Memory leak - malloc without corresponding free
    if (cycle % 3 == 0) {
        printf("  💀 Simulating memory leak (no free call)\n");
        return;  // EXIT WITHOUT FREE!
    }
    
    // VIOLATION 26: Use after free potential
    free(dynamic_force_data);
    if (cycle > 5) {
        printf("  Value after free: %d\n", *dynamic_force_data);  // Use after free!
    }
}

/**
 * @brief Unsafe System Logging Function
 */
void log_brake_event(const char* event_description)
{
    // VIOLATION 27: No buffer bounds checking
    strcat(system_log, event_description);  // system_log only 100 bytes!
    strcat(system_log, " | ");
    
    // VIOLATION 28: No log rotation or size management
    printf("  📝 Log size: %zu bytes (no overflow protection)\n", strlen(system_log));
}

/**
 * @brief Missing Memory Protection Functions
 * VIOLATION 29: These critical functions are not implemented!
 */
// void configure_memory_protection_unit(void) { /* NOT IMPLEMENTED */ }
// void setup_stack_guards(void) { /* NOT IMPLEMENTED */ }
// void isolate_safety_components(void) { /* NOT IMPLEMENTED */ }
// bool validate_memory_integrity(void) { /* NOT IMPLEMENTED */ }

/**
 * @brief Main Function - Integration of Memory Violations
 */
int main(void)
{
    printf("=== Automotive Safety Lab Exercise 03: Memory Violations ===\n");
    printf("🎯 Challenge: Find 30+ memory safety violations\n");
    printf("🚗 Context: Electronic Brake System (ASIL B)\n");
    printf("⚠️  Risk: Loss of braking capability due to memory corruption\n\n");
    
    // VIOLATION 30: No memory protection initialization
    printf("⚠️  Missing: Memory Protection Unit (MPU) setup\n");
    printf("⚠️  Missing: Stack guard initialization\n");
    printf("⚠️  Missing: Component memory isolation\n");
    
    // Initialize some unsafe shared memory
    shared_sensor_data = (uint32_t*)malloc(100 * sizeof(uint32_t));
    
    printf("\n");
    brake_control_loop();
    
    // Log some events to demonstrate buffer overflow
    log_brake_event("Brake system started");
    log_brake_event("ABS activation detected in wheel 1 and 2 during emergency braking");
    log_brake_event("Stability control engaged for severe weather conditions");
    log_brake_event("Multiple brake applications with high pressure detected");
    
    // VIOLATION 31: No memory cleanup or safe shutdown
    printf("\n⚠️  System ending without memory protection validation\n");
    printf("💀 DANGEROUS: Potential memory leaks and corruption\n\n");
    
    printf("🎓 LEARNING CHALLENGE:\n");
    printf("   → Count the memory safety violations you found\n");
    printf("   → Expected: 30+ violations of ISO 26262 memory requirements\n");
    printf("   → Focus on interference between safety levels\n");
    printf("   → Compare with compliant implementation\n");
    
    return 0;
}

/**
 * SUMMARY OF MAJOR VIOLATION CATEGORIES:
 * 
 * 1. BUFFER OVERFLOW VIOLATIONS (Most Critical):
 *    - Stack buffer overflows in brake control loop
 *    - Unsafe string operations (strcpy, strcat, sprintf)
 *    - Array bounds violations in sensor processing
 *    - Log buffer overflow in system logging
 *    - No bounds checking on user input processing
 * 
 * 2. MEMORY CORRUPTION FAILURES:
 *    - Mixed safety levels in same data structure
 *    - Unprotected shared memory access
 *    - Race conditions in shared pointer updates
 *    - Use-after-free vulnerabilities
 *    - Memory leaks without proper cleanup
 * 
 * 3. FREEDOM FROM INTERFERENCE VIOLATIONS:
 *    - Safety-critical brake data mixed with infotainment
 *    - No component isolation between safety levels
 *    - Shared buffers without access control
 *    - Cross-contamination of memory regions
 *    - Missing memory protection unit configuration
 * 
 * 4. DYNAMIC MEMORY HAZARDS:
 *    - Unsafe malloc/free patterns
 *    - No error checking on memory allocation
 *    - Memory leaks in critical paths
 *    - Double-free potential
 *    - Dangling pointer usage
 * 
 * 5. ASIL B REQUIREMENT VIOLATIONS:
 *    - Missing hardware memory protection (MPU)
 *    - Inadequate component isolation mechanisms
 *    - No memory integrity validation
 *    - Missing static analysis integration
 *    - Insufficient diagnostic coverage for memory faults
 */