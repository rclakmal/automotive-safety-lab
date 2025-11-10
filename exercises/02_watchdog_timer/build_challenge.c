/**
 * @file build_challenge.c
 * @brief Build Your Own Watchdog Implementation Challenge
 * @author Automotive Safety Lab
 * 
 * Learning Challenge: Implement ASIL A watchdog for transmission control
 * System: Automatic Transmission Control Module (TCM)
 * Requirements: 5ms cycle time, gear shift supervision, safe state management
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// =============================================================================
// TRANSMISSION CONTROL SYSTEM REQUIREMENTS
// =============================================================================

// TODO: Define your timing constants here
#define TCM_CYCLE_TIME_MS           5       // Maximum transmission cycle time
#define WATCHDOG_TIMEOUT_MS         25      // Hardware watchdog timeout
#define SHIFT_DECISION_TIMEOUT_MS   3       // Maximum gear shift decision time

// TODO: Define your watchdog timing window
#define WATCHDOG_KICK_MIN_MS        4       // Minimum time before kick
#define WATCHDOG_KICK_MAX_MS        6       // Maximum time before kick required

// Transmission safety limits
#define MAX_GEAR                    8       // Maximum gear position
#define MIN_GEAR                    1       // Minimum gear position  
#define NEUTRAL_GEAR                0       // Neutral position
#define REVERSE_GEAR               -1       // Reverse position

// Vehicle operating limits
#define MAX_VEHICLE_SPEED_KPH      200      // Maximum safe speed
#define MAX_ENGINE_RPM             7000     // Engine redline

// =============================================================================
// SAFETY STATE DEFINITIONS
// =============================================================================

/**
 * TODO: Define your transmission safety states
 * Implement the safety state hierarchy for transmission control
 */
typedef enum {
    // TODO: Add your safety states here
    TRANS_STATE_NORMAL          = 0x00,     // Normal operation
    TRANS_STATE_DEGRADED        = 0x01,     // Limited functionality
    TRANS_STATE_LIMP_HOME       = 0x02,     // Fixed gear mode
    TRANS_STATE_PARK_LOCK       = 0x03,     // Emergency park lock
    TRANS_STATE_FAULT           = 0xFF      // System fault
} transmission_safety_state_t;

/**
 * TODO: Define your watchdog diagnostics structure
 * Track timing violations and safety events
 */
typedef struct {
    // TODO: Add your diagnostic counters
    uint32_t kick_count;                    // Total watchdog kicks
    uint32_t missed_kicks;                  // Missed kick counter
    uint32_t early_kicks;                   // Too-early kicks
    uint32_t late_kicks;                    // Too-late kicks
    uint32_t shift_timeouts;                // Gear shift timeout events
    uint32_t cycle_overruns;                // Timing deadline violations
    transmission_safety_state_t current_state; // Current safety state
    uint32_t last_kick_time_ms;             // Timestamp of last kick
    bool     diagnostics_enabled;           // Diagnostic system status
} transmission_diagnostics_t;

/**
 * TODO: Define your transmission control data
 * Include gear position, vehicle speed, engine state
 */
typedef struct {
    // TODO: Add transmission control parameters
    int8_t   current_gear;                  // Current gear position
    int8_t   target_gear;                   // Requested gear position
    uint32_t vehicle_speed_kph;             // Vehicle speed (km/h)
    uint32_t engine_rpm;                    // Engine RPM
    uint32_t throttle_position;             // Throttle position (0-100%)
    bool     brake_pressed;                 // Brake pedal status
    bool     shift_in_progress;             // Gear shift status
    uint32_t shift_start_time;              // Shift operation start time
} transmission_control_data_t;

// =============================================================================
// GLOBAL STATE (Protected by watchdog)
// =============================================================================

static transmission_diagnostics_t g_trans_diag = {0};
static transmission_control_data_t g_trans_data = {0};
static volatile bool g_emergency_stop = false;

// =============================================================================
// UTILITY FUNCTIONS (Provided)
// =============================================================================

/**
 * @brief Get system time in milliseconds
 */
static uint32_t get_time_ms(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint32_t)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

/**
 * @brief Safe delay with emergency override
 */
static bool safe_delay_ms(uint32_t delay_ms)
{
    uint32_t start_time = get_time_ms();
    while ((get_time_ms() - start_time) < delay_ms) {
        if (g_emergency_stop) {
            return false;
        }
        usleep(1000);
    }
    return true;
}

// =============================================================================
// CHALLENGE IMPLEMENTATION SECTION
// =============================================================================

/**
 * TODO: Implement watchdog initialization
 * @brief Initialize transmission watchdog system
 * @return true if initialization successful
 * 
 * REQUIREMENTS:
 * - Initialize diagnostic counters
 * - Set up timing parameters
 * - Configure hardware watchdog (simulated)
 * - Validate system readiness
 */
static bool initialize_transmission_watchdog(void)
{
    printf("🔧 Initializing Transmission Watchdog System\n");
    
    // TODO: Initialize your diagnostic structure
    // Hint: Set all counters to 0, enable diagnostics, set normal state
    
    // TODO: Simulate hardware watchdog setup
    // Hint: Print configuration parameters for verification
    
    printf("   TODO: Add your watchdog initialization code here!\n");
    printf("   Requirements:\n");
    printf("   - Initialize diagnostic counters\n");
    printf("   - Configure %dms timeout\n", WATCHDOG_TIMEOUT_MS);
    printf("   - Set kick window: %d-%dms\n", WATCHDOG_KICK_MIN_MS, WATCHDOG_KICK_MAX_MS);
    printf("   - Enable safety monitoring\n");
    
    return false;  // TODO: Change to true when implemented
}

/**
 * TODO: Implement watchdog kick validation
 * @brief Validate watchdog kick timing and safety conditions
 * @param current_time Current system time in milliseconds
 * @return true if kick is valid and accepted
 * 
 * REQUIREMENTS:
 * - Check timing window (min/max kick intervals)
 * - Validate system safety state
 * - Update diagnostic counters
 * - Log validation results
 */
static bool validate_and_kick_watchdog(uint32_t current_time)
{
    // TODO: Calculate elapsed time since last kick
    // Hint: current_time - g_trans_diag.last_kick_time_ms
    
    // TODO: Implement timing window validation
    // Hint: Check against WATCHDOG_KICK_MIN_MS and WATCHDOG_KICK_MAX_MS
    
    // TODO: Update diagnostic counters based on validation results
    // Hint: Increment appropriate counters (early_kicks, late_kicks, kick_count)
    
    // TODO: Update last kick timestamp on successful kick
    
    printf("   🐕 TODO: Implement watchdog kick validation\n");
    printf("   Requirements:\n");
    printf("   - Validate timing window: %d-%dms\n", WATCHDOG_KICK_MIN_MS, WATCHDOG_KICK_MAX_MS);
    printf("   - Check safety state before kick\n");
    printf("   - Update diagnostic counters\n");
    printf("   - Log validation results\n");
    
    return false;  // TODO: Implement validation logic
}

/**
 * TODO: Implement safe state management
 * @brief Enter transmission safe state with specified reason
 * @param new_state Target safety state
 * @param reason Reason for state transition
 * 
 * REQUIREMENTS:
 * - Implement state transition logic
 * - Define safe actions for each state
 * - Log state changes with timestamps
 * - Ensure deterministic behavior
 */
static void enter_transmission_safe_state(transmission_safety_state_t new_state, const char* reason)
{
    printf("\n🛡️  ENTERING SAFE STATE: %d\n", new_state);
    printf("   Reason: %s\n", reason);
    
    // TODO: Update current safety state
    g_trans_diag.current_state = new_state;
    
    // TODO: Implement safe actions based on state
    switch (new_state) {
        case TRANS_STATE_DEGRADED:
            printf("   TODO: Implement degraded mode actions\n");
            printf("   Suggested: Limited shift patterns, reduced performance\n");
            break;
            
        case TRANS_STATE_LIMP_HOME:
            printf("   TODO: Implement limp-home mode actions\n");
            printf("   Suggested: Lock in 3rd gear, disable automatic shifts\n");
            break;
            
        case TRANS_STATE_PARK_LOCK:
            printf("   TODO: Implement park lock actions\n");
            printf("   Suggested: Engage parking pawl, disable all shifts\n");
            break;
            
        case TRANS_STATE_FAULT:
            printf("   TODO: Implement fault state actions\n");
            printf("   Suggested: Complete transmission lockout, service required\n");
            break;
            
        default:
            printf("   ⚠️  Unknown state - implement validation!\n");
            break;
    }
    
    // TODO: Add your safe state implementation here
}

/**
 * TODO: Implement transmission control with timing supervision
 * @brief Execute one transmission control cycle with safety monitoring
 * @return true if cycle completed successfully
 * 
 * REQUIREMENTS:
 * - Monitor cycle execution time
 * - Implement gear shift logic with timeout protection
 * - Validate all inputs and outputs
 * - Handle timing violations appropriately
 */
static bool execute_transmission_cycle(void)
{
    uint32_t cycle_start = get_time_ms();
    
    printf("   🚗 Executing transmission control cycle\n");
    
    // TODO: Simulate vehicle data acquisition
    // Hint: Generate realistic speed, RPM, throttle, brake data
    g_trans_data.vehicle_speed_kph = rand() % 120;
    g_trans_data.engine_rpm = 800 + rand() % 4000;
    g_trans_data.throttle_position = rand() % 100;
    g_trans_data.brake_pressed = (rand() % 10) < 2;  // 20% chance
    
    // TODO: Implement gear shift decision logic
    // Requirements:
    // - Respect timing deadline (SHIFT_DECISION_TIMEOUT_MS)
    // - Validate input parameters
    // - Implement safe shift patterns
    // - Handle timeout conditions
    
    printf("   TODO: Implement your gear shift logic here!\n");
    printf("   Current conditions:\n");
    printf("     Speed: %d km/h, RPM: %d, Throttle: %d%%, Brake: %s\n",
           g_trans_data.vehicle_speed_kph, g_trans_data.engine_rpm, 
           g_trans_data.throttle_position, g_trans_data.brake_pressed ? "ON" : "OFF");
    printf("   Requirements:\n");
    printf("   - Complete shift decision within %dms\n", SHIFT_DECISION_TIMEOUT_MS);
    printf("   - Validate all input parameters\n");
    printf("   - Implement safe shift logic\n");
    printf("   - Handle edge cases (high speed, low speed, etc.)\n");
    
    // TODO: Implement cycle time monitoring
    uint32_t cycle_time = get_time_ms() - cycle_start;
    
    if (cycle_time > TCM_CYCLE_TIME_MS) {
        g_trans_diag.cycle_overruns++;
        printf("   ❌ Cycle overrun: %dms (> %dms limit)\n", cycle_time, TCM_CYCLE_TIME_MS);
        
        // TODO: Handle timing violation
        // Hint: Consider safe state transition or warning
        
        return false;
    }
    
    printf("   ✅ Cycle completed in %dms\n", cycle_time);
    return true;
}

/**
 * TODO: Implement system health monitoring
 * @brief Monitor system health and trigger safe states if needed
 * @return Current safety state after health check
 * 
 * REQUIREMENTS:
 * - Check diagnostic counters against thresholds
 * - Evaluate system performance trends
 * - Trigger appropriate safe state transitions
 * - Log health assessment results
 */
static transmission_safety_state_t monitor_system_health(void)
{
    // TODO: Implement health monitoring logic
    // Check diagnostic counters and determine if safe state needed
    
    printf("   📊 TODO: Implement system health monitoring\n");
    printf("   Current diagnostics:\n");
    printf("     Kicks: %d, Missed: %d, Early: %d, Late: %d\n",
           g_trans_diag.kick_count, g_trans_diag.missed_kicks,
           g_trans_diag.early_kicks, g_trans_diag.late_kicks);
    printf("     Shift timeouts: %d, Cycle overruns: %d\n",
           g_trans_diag.shift_timeouts, g_trans_diag.cycle_overruns);
    
    // TODO: Define thresholds and trigger safe states
    // Example thresholds (implement your own logic):
    // - More than 3 missed kicks → LIMP_HOME
    // - More than 5 cycle overruns → DEGRADED
    // - More than 2 shift timeouts → PARK_LOCK
    
    return g_trans_diag.current_state;
}

/**
 * TODO: Implement main transmission control loop
 * @brief Main control loop with watchdog supervision
 * 
 * REQUIREMENTS:
 * - Execute control cycles with timing supervision
 * - Perform watchdog kicks at appropriate intervals
 * - Monitor system health continuously
 * - Handle failures gracefully with safe states
 */
static void transmission_control_loop(void)
{
    printf("🚗 Starting Transmission Control Loop Challenge\n");
    printf("   System: Automatic Transmission Control Module (TCM)\n");
    printf("   Safety Goal: Prevent unsafe gear shifts during driving\n");
    printf("   Challenge: Implement ASIL A watchdog supervision\n\n");
    
    for (int cycle = 1; cycle <= 10; cycle++) {
        printf("--- Transmission Cycle %d ---\n", cycle);
        
        // TODO: Check system health before cycle
        transmission_safety_state_t health_state = monitor_system_health();
        if (health_state >= TRANS_STATE_PARK_LOCK) {
            printf("   🛑 Cycle aborted due to safety state\n");
            break;
        }
        
        // TODO: Execute transmission control cycle
        if (!execute_transmission_cycle()) {
            printf("   ⚠️  Cycle failed - considering safe state\n");
            // TODO: Implement failure handling
        }
        
        // TODO: Perform watchdog kick with validation
        uint32_t current_time = get_time_ms();
        if (!validate_and_kick_watchdog(current_time)) {
            printf("   ❌ Watchdog kick failed\n");
            // TODO: Implement watchdog failure handling
        }
        
        // Inter-cycle delay
        if (!safe_delay_ms(200)) {  // 200ms between cycles
            printf("   ⚠️  Emergency stop requested\n");
            break;
        }
        
        printf("\n");
    }
    
    printf("✅ Transmission control loop completed\n");
}

/**
 * TODO: Implement final diagnostics report
 * @brief Generate comprehensive diagnostic report
 * 
 * REQUIREMENTS:
 * - Calculate diagnostic coverage percentage
 * - Assess ASIL A compliance
 * - Provide improvement recommendations
 * - Display learning progress
 */
static void generate_final_report(void)
{
    printf("\n╔══════════════════════════════════════════════════════════════╗\n");
    printf("║              TRANSMISSION WATCHDOG IMPLEMENTATION             ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    
    // TODO: Calculate and display diagnostic coverage
    printf("📊 DIAGNOSTIC COVERAGE ASSESSMENT:\n");
    
    // TODO: Implement coverage calculation
    uint32_t total_events = g_trans_diag.kick_count + g_trans_diag.missed_kicks;
    if (total_events > 0) {
        printf("   TODO: Calculate diagnostic coverage percentage\n");
        printf("   Formula: (detected_faults / total_events) * 100\n");
        printf("   ASIL A Requirement: ≥90%% diagnostic coverage\n");
    }
    
    printf("\n");
    printf("🎯 IMPLEMENTATION CHECKLIST:\n");
    
    // TODO: Provide implementation status checklist
    printf("   [ ] Watchdog initialization implemented\n");
    printf("   [ ] Timing window validation implemented\n");
    printf("   [ ] Safe state management implemented\n");
    printf("   [ ] Gear shift logic with timeout protection\n");
    printf("   [ ] System health monitoring implemented\n");
    printf("   [ ] Diagnostic coverage ≥90%%\n");
    printf("   [ ] Graceful failure handling\n");
    printf("   [ ] ASIL A requirements compliance\n");
    
    printf("\n");
    printf("🎓 LEARNING OBJECTIVES CHECKLIST:\n");
    printf("   [ ] Understand transmission safety requirements\n");
    printf("   [ ] Implement timing-critical watchdog supervision\n");
    printf("   [ ] Design appropriate safe state hierarchy\n");
    printf("   [ ] Apply diagnostic coverage principles\n");
    printf("   [ ] Handle real-time timing constraints\n");
    printf("   [ ] Validate safety-critical implementations\n");
    
    printf("\n");
    printf("📚 NEXT STEPS FOR COMPLETE IMPLEMENTATION:\n");
    printf("   1. Fill in all TODO sections with working code\n");
    printf("   2. Test your implementation with various scenarios\n");
    printf("   3. Compare with the compliant example implementation\n");
    printf("   4. Validate timing behavior under load conditions\n");
    printf("   5. Measure and verify diagnostic coverage\n");
    printf("   6. Document your safety analysis and verification\n");
}

/**
 * @brief Display implementation guidance
 */
static void display_implementation_guidance(void)
{
    printf("=== ISO 26262 Exercise 02: Build Challenge ===\n");
    printf("🎯 Build Your Own Watchdog Implementation\n");
    printf("🚗 System: Automatic Transmission Control Module (ASIL A)\n\n");
    
    printf("📋 CHALLENGE OVERVIEW:\n");
    printf("Implement a complete watchdog system for transmission control:\n");
    printf("• 5ms maximum cycle time for gear shift decisions\n");
    printf("• Hardware watchdog with 25ms timeout\n");
    printf("• Safe state management (normal → degraded → limp-home → park)\n");
    printf("• ASIL A diagnostic coverage requirements (≥90%%)\n\n");
    
    printf("🛠️  IMPLEMENTATION TASKS:\n");
    printf("1. Complete initialize_transmission_watchdog()\n");
    printf("2. Implement validate_and_kick_watchdog()\n");
    printf("3. Design enter_transmission_safe_state()\n");
    printf("4. Build execute_transmission_cycle()\n");
    printf("5. Create monitor_system_health()\n");
    printf("6. Finish generate_final_report()\n\n");
    
    printf("💡 IMPLEMENTATION HINTS:\n");
    printf("• Start with the diagnostic structure initialization\n");
    printf("• Implement timing validation step by step\n");
    printf("• Test each function individually before integration\n");
    printf("• Reference compliant.c for safety patterns\n");
    printf("• Focus on deterministic behavior and error handling\n\n");
    
    printf("🎮 Ready to start building? The code framework is ready!\n\n");
}

/**
 * @brief Main build challenge function
 */
int main(void)
{
    display_implementation_guidance();
    
    srand((unsigned int)time(NULL));
    
    // TODO: Initialize your watchdog system
    if (!initialize_transmission_watchdog()) {
        printf("❌ Watchdog initialization failed\n");
        printf("💡 Hint: Complete the initialize_transmission_watchdog() function\n");
        return 1;
    }
    
    // TODO: Run your transmission control loop
    transmission_control_loop();
    
    // TODO: Generate your final diagnostic report
    generate_final_report();
    
    printf("\n🏆 Build Challenge Completed!\n");
    printf("📖 Study the compliant implementation to see complete solutions\n");
    printf("🚀 Ready for Exercise 03: Memory Protection Systems!\n");
    
    return 0;
}