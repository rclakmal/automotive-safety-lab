/*
 * Exercise 01: Basic Safety - Compliant Example  
 * =============================================
 * 
 * ✅ This code demonstrates good quality practices in automotive software
 * ✅ While ASIL QM, it follows patterns that scale to higher ASIL systems
 * 
 * System: Battery voltage monitoring for dashboard display
 * ASIL Level: QM (Quality Managed - no safety impact)
 * 
 * Good Practices Demonstrated:
 * 1. Comprehensive input validation
 * 2. Proper error handling and reporting
 * 3. Diagnostic information collection
 * 4. Defensive programming techniques
 * 5. Clear, maintainable code structure
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// ✅ GOOD PRACTICE 1: Clear, documented constants
#define BATTERY_VOLTAGE_MIN         10.5f   // Minimum safe operating voltage (V)
#define BATTERY_VOLTAGE_MAX         15.0f   // Maximum safe operating voltage (V)
#define BATTERY_VOLTAGE_NOMINAL     12.6f   // Nominal fully charged voltage (V)
#define ADC_RESOLUTION_BITS         12      // 12-bit ADC (0-4095)
#define ADC_REFERENCE_VOLTAGE       5.0f    // 5V ADC reference
#define VOLTAGE_DIVIDER_RATIO       3.0f    // Voltage divider for battery measurement
#define MAX_DISPLAY_MODES           3       // Number of supported display modes

// ✅ GOOD PRACTICE 2: Proper error code definitions
typedef enum {
    BATTERY_OK = 0,
    BATTERY_ERROR_INVALID_PARAM,
    BATTERY_ERROR_ADC_FAULT,
    BATTERY_ERROR_OUT_OF_RANGE,
    BATTERY_ERROR_DISPLAY_FAULT,
    BATTERY_ERROR_SYSTEM_FAULT
} battery_error_t;

// ✅ GOOD PRACTICE 3: Clear status definitions
typedef enum {
    BATTERY_STATUS_UNKNOWN = 0,
    BATTERY_STATUS_CRITICAL,        // < 10.5V - Immediate attention needed
    BATTERY_STATUS_LOW,            // 10.5V - 11.5V - Should be charged soon  
    BATTERY_STATUS_NORMAL,         // 11.5V - 14.0V - Normal operation
    BATTERY_STATUS_HIGH           // > 14.0V - Possible charging issue
} battery_status_t;

// ✅ GOOD PRACTICE 4: Structured data with validation
typedef struct {
    uint16_t raw_adc_value;        // Raw ADC reading (0-4095)
    float calculated_voltage;      // Calculated battery voltage (V)
    battery_status_t status;       // Current battery status
    uint32_t timestamp_ms;         // Measurement timestamp
    uint32_t measurement_count;    // Total measurements taken
    bool data_valid;               // Data validity flag
} battery_measurement_t;

// ✅ GOOD PRACTICE 5: Diagnostic information structure  
typedef struct {
    uint32_t total_measurements;
    uint32_t invalid_readings;
    uint32_t out_of_range_readings;
    uint32_t adc_faults;
    float min_voltage_seen;
    float max_voltage_seen;
    uint32_t status_change_count;
} battery_diagnostics_t;

// ✅ GOOD PRACTICE 6: Protected global state with clear initialization
static battery_measurement_t g_current_measurement = {0};
static battery_diagnostics_t g_diagnostics = {0};
static bool g_system_initialized = false;

// ✅ GOOD PRACTICE 7: Get current timestamp for diagnostics
static uint32_t get_timestamp_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint32_t)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

// ✅ GOOD PRACTICE 8: Comprehensive input validation
static battery_error_t validate_adc_reading(uint16_t adc_value) {
    // Check if ADC value is within expected range
    if (adc_value > ((1 << ADC_RESOLUTION_BITS) - 1)) {
        return BATTERY_ERROR_ADC_FAULT;
    }
    
    return BATTERY_OK;
}

// ✅ GOOD PRACTICE 9: Simulate ADC reading with realistic behavior
static battery_error_t read_battery_adc(uint16_t *adc_value) {
    if (adc_value == NULL) {
        return BATTERY_ERROR_INVALID_PARAM;
    }
    
    // Simulate realistic ADC readings around 12V battery
    // Real implementation would interface with hardware ADC
    static uint16_t base_reading = 2500;  // Roughly 12V
    
    // Add some realistic variation (+/- 0.1V)
    int variation = (rand() % 200) - 100;  // -100 to +100 ADC counts
    int simulated_reading = base_reading + variation;
    
    // Ensure reading stays within ADC bounds
    if (simulated_reading < 0) {
        simulated_reading = 0;
    } else if (simulated_reading > 4095) {
        simulated_reading = 4095;
    }
    
    *adc_value = (uint16_t)simulated_reading;
    
    // ✅ Validate the reading
    return validate_adc_reading(*adc_value);
}

// ✅ GOOD PRACTICE 10: Clear voltage conversion with validation
static battery_error_t convert_adc_to_voltage(uint16_t adc_value, float *voltage) {
    if (voltage == NULL) {
        return BATTERY_ERROR_INVALID_PARAM;
    }
    
    // Validate ADC input
    battery_error_t error = validate_adc_reading(adc_value);
    if (error != BATTERY_OK) {
        return error;
    }
    
    // Convert ADC reading to voltage
    // Formula: Voltage = (ADC_value / ADC_max) * V_ref * divider_ratio
    float adc_voltage = ((float)adc_value / (float)((1 << ADC_RESOLUTION_BITS) - 1)) * ADC_REFERENCE_VOLTAGE;
    *voltage = adc_voltage * VOLTAGE_DIVIDER_RATIO;
    
    // ✅ Validate calculated voltage is reasonable
    if (*voltage < 0.0f || *voltage > 20.0f) {  // Sanity check
        return BATTERY_ERROR_OUT_OF_RANGE;
    }
    
    return BATTERY_OK;
}

// ✅ GOOD PRACTICE 11: Clear status determination with documentation
static battery_status_t determine_battery_status(float voltage) {
    if (voltage < BATTERY_VOLTAGE_MIN) {
        return BATTERY_STATUS_CRITICAL;
    } else if (voltage < 11.5f) {
        return BATTERY_STATUS_LOW;  
    } else if (voltage <= 14.0f) {
        return BATTERY_STATUS_NORMAL;
    } else {
        return BATTERY_STATUS_HIGH;
    }
}

// ✅ GOOD PRACTICE 12: Comprehensive measurement with diagnostics
battery_error_t read_battery_measurement(battery_measurement_t *measurement) {
    if (measurement == NULL) {
        return BATTERY_ERROR_INVALID_PARAM;
    }
    
    if (!g_system_initialized) {
        return BATTERY_ERROR_SYSTEM_FAULT;
    }
    
    uint16_t adc_reading;
    float voltage;
    
    // ✅ Read ADC with error handling
    battery_error_t error = read_battery_adc(&adc_reading);
    if (error != BATTERY_OK) {
        g_diagnostics.adc_faults++;
        return error;
    }
    
    // ✅ Convert to voltage with validation
    error = convert_adc_to_voltage(adc_reading, &voltage);
    if (error != BATTERY_OK) {
        g_diagnostics.invalid_readings++;
        return error;
    }
    
    // ✅ Validate voltage range
    if (voltage < 8.0f || voltage > 18.0f) {
        g_diagnostics.out_of_range_readings++;
        return BATTERY_ERROR_OUT_OF_RANGE;
    }
    
    // ✅ Update measurement structure
    measurement->raw_adc_value = adc_reading;
    measurement->calculated_voltage = voltage;
    measurement->status = determine_battery_status(voltage);
    measurement->timestamp_ms = get_timestamp_ms();
    measurement->measurement_count = ++g_diagnostics.total_measurements;
    measurement->data_valid = true;
    
    // ✅ Update diagnostic information
    if (voltage < g_diagnostics.min_voltage_seen || g_diagnostics.total_measurements == 1) {
        g_diagnostics.min_voltage_seen = voltage;
    }
    if (voltage > g_diagnostics.max_voltage_seen || g_diagnostics.total_measurements == 1) {
        g_diagnostics.max_voltage_seen = voltage;
    }
    
    // Track status changes
    if (measurement->status != g_current_measurement.status) {
        g_diagnostics.status_change_count++;
    }
    
    // ✅ Store current measurement for comparison
    g_current_measurement = *measurement;
    
    return BATTERY_OK;
}

// ✅ GOOD PRACTICE 13: Multiple display modes with validation
battery_error_t display_battery_info(const battery_measurement_t *measurement, int display_mode) {
    if (measurement == NULL || !measurement->data_valid) {
        return BATTERY_ERROR_INVALID_PARAM;
    }
    
    if (display_mode < 1 || display_mode > MAX_DISPLAY_MODES) {
        return BATTERY_ERROR_DISPLAY_FAULT;
    }
    
    const char* status_strings[] = {
        "UNKNOWN", "CRITICAL", "LOW", "NORMAL", "HIGH"
    };
    
    switch (display_mode) {
        case 1: // Standard display
            printf("  Battery: %.2f V [%s]\n", 
                   measurement->calculated_voltage, 
                   status_strings[measurement->status]);
            break;
            
        case 2: // Detailed technical display
            printf("  Battery Details:\n");
            printf("    Voltage: %.2f V\n", measurement->calculated_voltage);
            printf("    Raw ADC: %u counts\n", measurement->raw_adc_value);
            printf("    Status: %s\n", status_strings[measurement->status]);
            printf("    Timestamp: %u ms\n", measurement->timestamp_ms);
            break;
            
        case 3: // Diagnostic display
            printf("  Battery Diagnostics:\n");
            printf("    Current: %.2f V [%s]\n", 
                   measurement->calculated_voltage, 
                   status_strings[measurement->status]);
            printf("    Measurements: %u total\n", g_diagnostics.total_measurements);
            printf("    Range: %.2f - %.2f V\n", 
                   g_diagnostics.min_voltage_seen, g_diagnostics.max_voltage_seen);
            printf("    Faults: %u invalid, %u out-of-range, %u ADC\n",
                   g_diagnostics.invalid_readings, 
                   g_diagnostics.out_of_range_readings,
                   g_diagnostics.adc_faults);
            break;
            
        default:
            return BATTERY_ERROR_DISPLAY_FAULT;
    }
    
    return BATTERY_OK;
}

// ✅ GOOD PRACTICE 14: System initialization with self-test
battery_error_t initialize_battery_monitor(void) {
    printf("✅ Initializing battery monitoring system...\n");
    
    // ✅ Clear all state
    memset(&g_current_measurement, 0, sizeof(g_current_measurement));
    memset(&g_diagnostics, 0, sizeof(g_diagnostics));
    
    // ✅ Initialize diagnostic minimums to reasonable values
    g_diagnostics.min_voltage_seen = 999.0f;  // Will be overwritten on first reading
    g_diagnostics.max_voltage_seen = 0.0f;    // Will be overwritten on first reading
    
    // ✅ Perform self-test
    printf("   Performing self-test...\n");
    
    // Test ADC reading capability
    uint16_t test_adc;
    battery_error_t error = read_battery_adc(&test_adc);
    if (error != BATTERY_OK) {
        printf("❌ ADC self-test failed: %d\n", error);
        return error;
    }
    
    // Test voltage conversion
    float test_voltage;
    error = convert_adc_to_voltage(test_adc, &test_voltage);
    if (error != BATTERY_OK) {
        printf("❌ Voltage conversion self-test failed: %d\n", error);
        return error;
    }
    
    printf("   Self-test completed: ADC=%u, Voltage=%.2f V\n", test_adc, test_voltage);
    
    // ✅ Mark system as initialized
    g_system_initialized = true;
    
    printf("✅ Battery monitoring system initialized successfully\n");
    return BATTERY_OK;
}

// ✅ GOOD PRACTICE 15: Main function with proper error handling
int main(void) {
    printf("✅ Battery Monitor - Quality Implementation Example\n");
    printf("==================================================\n");
    printf("✅ This code demonstrates GOOD automotive practices\n");  
    printf("✅ Suitable foundation for higher ASIL systems\n");
    printf("==================================================\n\n");
    
    battery_error_t error;
    
    // ✅ Initialize system with error checking
    error = initialize_battery_monitor();
    if (error != BATTERY_OK) {
        printf("❌ System initialization failed: %d\n", error);
        return -1;
    }
    
    printf("\nRunning battery monitoring demonstration...\n");
    
    // ✅ Controlled measurement loop with error handling
    for (int i = 0; i < 5; i++) {
        printf("\nMeasurement %d:\n", i + 1);
        
        battery_measurement_t measurement;
        error = read_battery_measurement(&measurement);
        
        if (error == BATTERY_OK) {
            // ✅ Display in different modes to show flexibility
            int display_mode = (i % MAX_DISPLAY_MODES) + 1;
            error = display_battery_info(&measurement, display_mode);
            
            if (error != BATTERY_OK) {
                printf("⚠️  Display error: %d\n", error);
            }
        } else {
            printf("❌ Measurement error: %d\n", error);
        }
        
        sleep(1);
    }
    
    // ✅ Final diagnostic report
    printf("\n📊 Final System Report:\n");
    printf("=======================\n");
    printf("Total measurements: %u\n", g_diagnostics.total_measurements);
    printf("Successful readings: %u\n", 
           g_diagnostics.total_measurements - g_diagnostics.invalid_readings 
           - g_diagnostics.out_of_range_readings - g_diagnostics.adc_faults);
    printf("Voltage range observed: %.2f - %.2f V\n", 
           g_diagnostics.min_voltage_seen, g_diagnostics.max_voltage_seen);
    printf("Status changes: %u\n", g_diagnostics.status_change_count);
    
    if (g_diagnostics.invalid_readings == 0 && 
        g_diagnostics.out_of_range_readings == 0 && 
        g_diagnostics.adc_faults == 0) {
        printf("✅ No faults detected - System operating normally\n");
    } else {
        printf("⚠️  Faults detected - Review diagnostic data\n");
    }
    
    printf("\n✅ Quality implementation demo completed\n");
    printf("📚 Compare with violation.c to see the differences!\n");
    
    return 0;
}

/*
 * Educational Analysis - Why This Implementation is Better:
 * ========================================================
 * 
 * 1. Code Quality Improvements:
 *    ✅ Clear, self-documenting constants and enums
 *    ✅ Comprehensive input validation and bounds checking
 *    ✅ Consistent error handling with meaningful return codes
 *    ✅ Structured data types with clear purposes
 * 
 * 2. Reliability Enhancements:
 *    ✅ Defensive programming against invalid inputs
 *    ✅ Proper error propagation and reporting
 *    ✅ Diagnostic data collection for troubleshooting
 *    ✅ Self-test capabilities during initialization
 * 
 * 3. Maintainability Features:
 *    ✅ Clear separation of concerns (ADC, conversion, display)
 *    ✅ Easy to unit test individual functions
 *    ✅ Extensible design for additional features
 *    ✅ Comprehensive documentation and comments
 * 
 * 4. Automotive-Specific Benefits:
 *    ✅ Diagnostic information for field service
 *    ✅ Multiple display modes for different user needs
 *    ✅ Foundation ready for higher ASIL requirements
 *    ✅ Clear traceability from requirements to implementation
 * 
 * Scaling to Higher ASIL Levels:
 * ==============================
 * 
 * This QM implementation provides a foundation that can be enhanced for higher ASIL:
 * 
 * ASIL A: Add timing supervision and basic redundancy checks
 * ASIL B: Implement memory protection and freedom from interference  
 * ASIL C: Add dual-channel measurement and cross-checking
 * ASIL D: Include formal verification and diverse implementation
 * 
 * The structured approach, comprehensive error handling, and diagnostic
 * capabilities established here become essential as safety requirements increase.
 */