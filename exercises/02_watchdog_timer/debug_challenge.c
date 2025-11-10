/**
 * @file debug_challenge.c
 * @brief Interactive Debugging Challenge for Watchdog Timing Issues
 * @author Automotive Safety Lab
 * 
 * Learning Challenge: Debug and fix timing violations in a realistic ECM scenario
 * Scenario: Intermittent watchdog resets causing engine roughness during high-load
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

// ECM timing requirements
#define ECM_CYCLE_TIME_MS       10
#define WATCHDOG_WINDOW_MIN_MS  8
#define WATCHDOG_WINDOW_MAX_MS  12
#define FUEL_CALC_TIMEOUT_MS    5

// Simulation parameters
#define DEBUG_CYCLES            15
#define HIGH_LOAD_PROBABILITY   30  // 30% chance of high load

// Fault injection modes (for learning)
typedef enum {
    FAULT_NONE = 0,
    FAULT_BLOCKING_OPERATION,
    FAULT_EXCESSIVE_COMPUTATION,
    FAULT_INTERRUPT_STORM,
    FAULT_MEMORY_ALLOCATION,
    FAULT_NETWORK_DELAY
} fault_type_t;

// Debug state tracking
typedef struct {
    uint32_t total_cycles;
    uint32_t watchdog_resets;
    uint32_t timing_violations;
    uint32_t successful_kicks;
    uint32_t fuel_calculation_timeouts;
    bool     debug_mode_enabled;
    fault_type_t active_fault;
} debug_state_t;

static debug_state_t g_debug = {0};

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
 * @brief Inject timing faults for learning (BUGGY VERSION)
 */
static void inject_fault_for_learning(fault_type_t fault_type)
{
    g_debug.active_fault = fault_type;
    
    switch (fault_type) {
        case FAULT_BLOCKING_OPERATION:
            printf("   🐛 FAULT INJECTED: Blocking network request\n");
            usleep(20000);  // 20ms delay - exceeds cycle time!
            break;
            
        case FAULT_EXCESSIVE_COMPUTATION:
            printf("   🐛 FAULT INJECTED: Complex calculation without timeout\n");
            for (volatile int i = 0; i < 2000000; i++) {
                // Simulates unoptimized computation
            }
            break;
            
        case FAULT_INTERRUPT_STORM:
            printf("   🐛 FAULT INJECTED: Interrupt processing overload\n");
            usleep(15000);  // 15ms delay - simulates interrupt storm
            break;
            
        case FAULT_MEMORY_ALLOCATION:
            printf("   🐛 FAULT INJECTED: Dynamic memory allocation\n");
            void* temp = malloc(1000000);  // Large allocation causing delay
            if (temp) {
                memset(temp, 0xAA, 1000000);
                free(temp);
            }
            break;
            
        case FAULT_NETWORK_DELAY:
            printf("   🐛 FAULT INJECTED: CAN bus communication delay\n");
            usleep(12000);  // 12ms delay - exceeds watchdog window
            break;
            
        default:
            break;
    }
}

/**
 * @brief BUGGY fuel calculation with timing issues
 */
static uint32_t calculate_fuel_buggy(void)
{
    uint32_t start_time = get_time_ms();
    
    // Random fault injection for learning
    if (rand() % 100 < HIGH_LOAD_PROBABILITY) {
        fault_type_t fault = (fault_type_t)(1 + rand() % 5);
        inject_fault_for_learning(fault);
    }
    
    // Simulate fuel calculation (sometimes slow)
    uint32_t throttle = rand() % 100;
    uint32_t rpm = 800 + rand() % 5200;
    
    // BUG: No timeout protection on calculation
    if (rpm > 4000) {
        // Simulate complex calculation for high RPM
        for (volatile int i = 0; i < rand() % 1000000; i++) {
            // Variable computation time - timing hazard!
        }
    }
    
    uint32_t calculation_time = get_time_ms() - start_time;
    if (calculation_time > FUEL_CALC_TIMEOUT_MS) {
        g_debug.fuel_calculation_timeouts++;
        printf("   ⚠️  Fuel calculation timeout: %dms (> %dms)\n", 
               calculation_time, FUEL_CALC_TIMEOUT_MS);
    }
    
    return (throttle * rpm) / 1000;
}

/**
 * @brief BUGGY watchdog kick implementation
 */
static bool kick_watchdog_buggy(uint32_t current_time, uint32_t last_kick_time)
{
    uint32_t elapsed = current_time - last_kick_time;
    
    // BUG: No timing window validation
    printf("   🐕 Kicking watchdog after %dms\n", elapsed);
    
    if (elapsed > WATCHDOG_WINDOW_MAX_MS) {
        g_debug.watchdog_resets++;
        printf("   💥 WATCHDOG RESET! Late kick: %dms (> %dms)\n", 
               elapsed, WATCHDOG_WINDOW_MAX_MS);
        return false;
    }
    
    g_debug.successful_kicks++;
    return true;
}

/**
 * @brief Debug challenge main loop (BUGGY VERSION)
 */
static void debug_challenge_main_loop(void)
{
    printf("🔥 BUGGY ECM Control Loop - Find and Fix the Issues!\n");
    printf("   Challenge: Fix intermittent watchdog resets\n");
    printf("   Symptom: Engine roughness during high-load conditions\n\n");
    
    uint32_t last_kick_time = get_time_ms();
    
    for (int cycle = 1; cycle <= DEBUG_CYCLES; cycle++) {
        printf("--- Debug Cycle %d ---\n", cycle);
        
        uint32_t cycle_start = get_time_ms();
        g_debug.total_cycles++;
        
        // Fuel calculation with potential timing issues
        uint32_t fuel_amount = calculate_fuel_buggy();
        
        // BUG: No cycle time monitoring before watchdog kick
        uint32_t current_time = get_time_ms();
        
        // Attempt watchdog kick (may fail due to timing issues)
        if (!kick_watchdog_buggy(current_time, last_kick_time)) {
            printf("   🚨 System reset required - restarting ECM\n");
            // Simulate system restart delay
            usleep(100000);  // 100ms restart time
            last_kick_time = get_time_ms();
            continue;
        }
        
        last_kick_time = current_time;
        
        uint32_t cycle_time = current_time - cycle_start;
        if (cycle_time > ECM_CYCLE_TIME_MS) {
            g_debug.timing_violations++;
            printf("   ❌ Cycle overrun: %dms (> %dms target)\n", 
                   cycle_time, ECM_CYCLE_TIME_MS);
        }
        
        printf("   ⛽ Fuel injected: %d units\n", fuel_amount);
        printf("   ✅ Cycle completed in %dms\n", cycle_time);
        
        // Inter-cycle delay
        usleep(300000);  // 300ms
        printf("\n");
    }
}

/**
 * @brief Display debug statistics and hints
 */
static void display_debug_results(void)
{
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    DEBUG CHALLENGE RESULTS                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    
    printf("📊 DEBUGGING STATISTICS:\n");
    printf("   Total cycles attempted: %d\n", g_debug.total_cycles);
    printf("   Successful watchdog kicks: %d\n", g_debug.successful_kicks);
    printf("   Watchdog resets: %d\n", g_debug.watchdog_resets);
    printf("   Timing violations: %d\n", g_debug.timing_violations);
    printf("   Fuel calculation timeouts: %d\n", g_debug.fuel_calculation_timeouts);
    
    float reset_rate = (float)g_debug.watchdog_resets * 100.0f / g_debug.total_cycles;
    printf("   Watchdog reset rate: %.1f%%\n", reset_rate);
    
    printf("\n");
    printf("🔍 ISSUES DETECTED:\n");
    
    if (g_debug.watchdog_resets > 0) {
        printf("   ❌ Watchdog timeout violations detected\n");
        printf("      → Late watchdog kicks exceed timing window\n");
        printf("      → System resets causing engine roughness\n");
    }
    
    if (g_debug.timing_violations > 0) {
        printf("   ❌ Cycle timing deadline violations detected\n");
        printf("      → Processing time exceeds 10ms target\n");
        printf("      → Variable execution time causing jitter\n");
    }
    
    if (g_debug.fuel_calculation_timeouts > 0) {
        printf("   ❌ Fuel calculation timeouts detected\n");
        printf("      → Blocking operations without timeout protection\n");
        printf("      → Unoptimized algorithms causing delays\n");
    }
    
    printf("\n");
    printf("🛠️  DEBUGGING HINTS:\n");
    printf("\n");
    
    printf("💡 Timing Issues:\n");
    printf("   • Add timeout protection to all blocking operations\n");
    printf("   • Implement cycle time monitoring and limits\n");
    printf("   • Use bounded algorithms for fuel calculations\n");
    printf("   • Add early warning for approaching deadlines\n");
    printf("\n");
    
    printf("💡 Watchdog Issues:\n");
    printf("   • Validate timing window before watchdog kick\n");
    printf("   • Implement pattern-based kick validation\n");
    printf("   • Add diagnostic counters for timing analysis\n");
    printf("   • Ensure kicks occur at consistent intervals\n");
    printf("\n");
    
    printf("💡 Fault Tolerance:\n");
    printf("   • Implement graceful degradation for high-load\n");
    printf("   • Add safe state transitions on timing failures\n");
    printf("   • Use priority-based task scheduling\n");
    printf("   • Implement load shedding for non-critical functions\n");
    printf("\n");
    
    printf("🎯 CHALLENGE COMPLETION:\n");
    
    if (reset_rate < 5.0f) {
        printf("   ✅ Excellent! Watchdog reset rate below 5%%\n");
        printf("   🏆 You've successfully debugged the timing issues!\n");
    } else if (reset_rate < 15.0f) {
        printf("   ⚠️  Good progress! Reset rate below 15%%\n");
        printf("   🔧 Continue optimizing to reach production quality\n");
    } else {
        printf("   ❌ High reset rate indicates significant timing issues\n");
        printf("   📚 Review the hints above and study compliant.c for solutions\n");
    }
    
    printf("\n");
    printf("📖 NEXT STEPS:\n");
    printf("   1. Study the compliant implementation: bazel run :compliant_example\n");
    printf("   2. Compare your fixes with the safety patterns shown\n");
    printf("   3. Practice implementing timeout protection mechanisms\n");
    printf("   4. Learn about advanced watchdog validation techniques\n");
}

/**
 * @brief Interactive debugging session
 */
static void run_interactive_debugging(void)
{
    printf("🎮 INTERACTIVE DEBUGGING MODE\n");
    printf("   You'll observe timing issues in real-time\n");
    printf("   Pay attention to the failure patterns\n");
    printf("   Think about how to fix each issue you see\n\n");
    
    char input[10];
    printf("Ready to start debugging? (y/n): ");
    if (fgets(input, sizeof(input), stdin) && input[0] == 'y') {
        g_debug.debug_mode_enabled = true;
        debug_challenge_main_loop();
        display_debug_results();
    } else {
        printf("Debugging session cancelled.\n");
    }
}

/**
 * @brief Main debug challenge function
 */
int main(void)
{
    printf("=== ISO 26262 Exercise 02: Debug Challenge ===\n");
    printf("🎯 Interactive debugging of watchdog timing issues\n");
    printf("🚗 System: Engine Control Module (ECM)\n");
    printf("🐛 Problem: Intermittent watchdog resets causing engine roughness\n\n");
    
    printf("📋 CHALLENGE BRIEFING:\n");
    printf("A production ECM is experiencing intermittent issues:\n");
    printf("• Watchdog resets during high-load conditions\n");
    printf("• Engine roughness and power fluctuations\n");
    printf("• Increased warranty claims from customers\n");
    printf("• Field reports show timing-related error codes\n\n");
    
    printf("Your task: Identify and understand the root cause\n");
    printf("Then propose fixes based on ISO 26262 timing safety\n\n");
    
    srand((unsigned int)time(NULL));
    
    run_interactive_debugging();
    
    return 0;
}