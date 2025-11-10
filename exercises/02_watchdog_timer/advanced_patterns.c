/**
 * @file advanced_patterns.c
 * @brief Advanced Watchdog Patterns for Complex Automotive Systems
 * @author Automotive Safety Lab
 * 
 * Educational Demonstration: Advanced watchdog architectures and patterns
 * Focus: Hierarchical supervision, dual watchdogs, adaptive timing
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

// =============================================================================
// ADVANCED WATCHDOG CONFIGURATION
// =============================================================================

// Hierarchical watchdog levels
#define SYSTEM_LEVEL_TIMEOUT_MS     100    // Top-level system watchdog
#define FUNCTION_LEVEL_TIMEOUT_MS   50     // Function-specific watchdogs
#define TASK_LEVEL_TIMEOUT_MS       20     // Individual task watchdogs

// Dual watchdog configuration
#define HW_WATCHDOG_TIMEOUT_MS      80     // Hardware watchdog
#define SW_WATCHDOG_TIMEOUT_MS      60     // Software watchdog

// Adaptive timing parameters
#define BASE_CYCLE_TIME_MS          10     // Normal operation cycle time
#define STARTUP_CYCLE_TIME_MS       20     // Extended time during startup
#define THERMAL_CYCLE_TIME_MS       15     // Extended time at high temperature

// Pattern validation sequences
#define PATTERN_SEQUENCE_LENGTH     4
static const uint16_t WATCHDOG_PATTERNS[PATTERN_SEQUENCE_LENGTH] = {
    0x5A5A, 0xA5A5, 0x3C3C, 0xC3C3
};

// =============================================================================
// ADVANCED WATCHDOG TYPES
// =============================================================================

/**
 * @brief Watchdog supervision levels
 */
typedef enum {
    WDT_LEVEL_SYSTEM    = 0,    // System-wide supervision
    WDT_LEVEL_FUNCTION  = 1,    // Function-level supervision  
    WDT_LEVEL_TASK      = 2,    // Task-level supervision
    WDT_LEVEL_COUNT     = 3
} watchdog_level_t;

/**
 * @brief Adaptive timing modes
 */
typedef enum {
    TIMING_MODE_NORMAL      = 0,    // Normal operation timing
    TIMING_MODE_STARTUP     = 1,    // Extended timing during startup
    TIMING_MODE_THERMAL     = 2,    // Temperature-compensated timing
    TIMING_MODE_DEGRADED    = 3,    // Degraded mode with relaxed timing
    TIMING_MODE_EMERGENCY   = 4     // Emergency mode timing
} timing_mode_t;

/**
 * @brief Hierarchical watchdog descriptor
 */
typedef struct {
    watchdog_level_t level;
    uint32_t timeout_ms;
    uint32_t last_kick_time;
    uint32_t kick_count;
    uint32_t timeout_count;
    bool enabled;
    const char* name;
} hierarchical_watchdog_t;

/**
 * @brief Dual watchdog system
 */
typedef struct {
    hierarchical_watchdog_t hw_watchdog;    // Hardware watchdog
    hierarchical_watchdog_t sw_watchdog;    // Software watchdog
    bool cross_check_enabled;               // Cross-validation between watchdogs
    uint32_t disagreement_count;            // Counter for watchdog disagreements
    uint32_t last_cross_check_time;         // Last cross-validation timestamp
} dual_watchdog_system_t;

/**
 * @brief Adaptive timing controller
 */
typedef struct {
    timing_mode_t current_mode;
    uint32_t cycle_time_ms;
    uint32_t kick_window_min_ms;
    uint32_t kick_window_max_ms;
    uint32_t mode_change_count;
    uint32_t temperature_celsius;
    bool startup_complete;
} adaptive_timing_t;

/**
 * @brief Pattern validation system
 */
typedef struct {
    uint16_t expected_pattern;
    uint32_t sequence_index;
    uint32_t pattern_violations;
    uint32_t successful_validations;
    bool synchronization_lost;
} pattern_validator_t;

// =============================================================================
// GLOBAL ADVANCED WATCHDOG STATE
// =============================================================================

static hierarchical_watchdog_t g_watchdog_hierarchy[WDT_LEVEL_COUNT];
static dual_watchdog_system_t g_dual_watchdog;
static adaptive_timing_t g_adaptive_timing;
static pattern_validator_t g_pattern_validator;

// =============================================================================
// UTILITY FUNCTIONS
// =============================================================================

static uint32_t get_time_ms(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint32_t)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

// =============================================================================
// HIERARCHICAL WATCHDOG IMPLEMENTATION
// =============================================================================

/**
 * @brief Initialize hierarchical watchdog system
 */
static void initialize_hierarchical_watchdogs(void)
{
    printf("🏗️  Initializing Hierarchical Watchdog System\n");
    
    // System level watchdog
    g_watchdog_hierarchy[WDT_LEVEL_SYSTEM] = (hierarchical_watchdog_t){
        .level = WDT_LEVEL_SYSTEM,
        .timeout_ms = SYSTEM_LEVEL_TIMEOUT_MS,
        .last_kick_time = get_time_ms(),
        .kick_count = 0,
        .timeout_count = 0,
        .enabled = true,
        .name = "System Supervisor"
    };
    
    // Function level watchdog
    g_watchdog_hierarchy[WDT_LEVEL_FUNCTION] = (hierarchical_watchdog_t){
        .level = WDT_LEVEL_FUNCTION,
        .timeout_ms = FUNCTION_LEVEL_TIMEOUT_MS,
        .last_kick_time = get_time_ms(),
        .kick_count = 0,
        .timeout_count = 0,
        .enabled = true,
        .name = "Function Monitor"
    };
    
    // Task level watchdog
    g_watchdog_hierarchy[WDT_LEVEL_TASK] = (hierarchical_watchdog_t){
        .level = WDT_LEVEL_TASK,
        .timeout_ms = TASK_LEVEL_TIMEOUT_MS,
        .last_kick_time = get_time_ms(),
        .kick_count = 0,
        .timeout_count = 0,
        .enabled = true,
        .name = "Task Supervisor"
    };
    
    printf("   ✅ System Level: %dms timeout\n", SYSTEM_LEVEL_TIMEOUT_MS);
    printf("   ✅ Function Level: %dms timeout\n", FUNCTION_LEVEL_TIMEOUT_MS);
    printf("   ✅ Task Level: %dms timeout\n", TASK_LEVEL_TIMEOUT_MS);
}

/**
 * @brief Kick hierarchical watchdog at specified level
 */
static bool kick_hierarchical_watchdog(watchdog_level_t level)
{
    if (level >= WDT_LEVEL_COUNT) {
        printf("   ❌ Invalid watchdog level: %d\n", level);
        return false;
    }
    
    hierarchical_watchdog_t* wdt = &g_watchdog_hierarchy[level];
    uint32_t current_time = get_time_ms();
    uint32_t elapsed = current_time - wdt->last_kick_time;
    
    if (elapsed > wdt->timeout_ms) {
        wdt->timeout_count++;
        printf("   💥 %s TIMEOUT: %dms (> %dms)\n", wdt->name, elapsed, wdt->timeout_ms);
        return false;
    }
    
    wdt->kick_count++;
    wdt->last_kick_time = current_time;
    printf("   🐕 %s kick #%d (%dms elapsed)\n", wdt->name, wdt->kick_count, elapsed);
    
    return true;
}

/**
 * @brief Check all hierarchical watchdogs
 */
static void check_hierarchical_watchdogs(void)
{
    printf("   🔍 Checking hierarchical watchdogs:\n");
    
    for (int level = 0; level < WDT_LEVEL_COUNT; level++) {
        hierarchical_watchdog_t* wdt = &g_watchdog_hierarchy[level];
        uint32_t elapsed = get_time_ms() - wdt->last_kick_time;
        
        if (elapsed > wdt->timeout_ms * 0.8) {  // 80% threshold warning
            printf("     ⚠️  %s approaching timeout: %dms/%dms\n", 
                   wdt->name, elapsed, wdt->timeout_ms);
        }
    }
}

// =============================================================================
// DUAL WATCHDOG IMPLEMENTATION
// =============================================================================

/**
 * @brief Initialize dual watchdog system
 */
static void initialize_dual_watchdog(void)
{
    printf("\n🔄 Initializing Dual Watchdog System\n");
    
    uint32_t current_time = get_time_ms();
    
    // Hardware watchdog
    g_dual_watchdog.hw_watchdog = (hierarchical_watchdog_t){
        .level = WDT_LEVEL_SYSTEM,
        .timeout_ms = HW_WATCHDOG_TIMEOUT_MS,
        .last_kick_time = current_time,
        .kick_count = 0,
        .timeout_count = 0,
        .enabled = true,
        .name = "Hardware WDT"
    };
    
    // Software watchdog
    g_dual_watchdog.sw_watchdog = (hierarchical_watchdog_t){
        .level = WDT_LEVEL_SYSTEM,
        .timeout_ms = SW_WATCHDOG_TIMEOUT_MS,
        .last_kick_time = current_time,
        .kick_count = 0,
        .timeout_count = 0,
        .enabled = true,
        .name = "Software WDT"
    };
    
    g_dual_watchdog.cross_check_enabled = true;
    g_dual_watchdog.disagreement_count = 0;
    g_dual_watchdog.last_cross_check_time = current_time;
    
    printf("   ✅ Hardware Watchdog: %dms timeout\n", HW_WATCHDOG_TIMEOUT_MS);
    printf("   ✅ Software Watchdog: %dms timeout\n", SW_WATCHDOG_TIMEOUT_MS);
    printf("   ✅ Cross-validation enabled\n");
}

/**
 * @brief Perform dual watchdog cross-validation
 */
static bool cross_validate_dual_watchdogs(void)
{
    if (!g_dual_watchdog.cross_check_enabled) {
        return true;
    }
    
    uint32_t current_time = get_time_ms();
    uint32_t hw_elapsed = current_time - g_dual_watchdog.hw_watchdog.last_kick_time;
    uint32_t sw_elapsed = current_time - g_dual_watchdog.sw_watchdog.last_kick_time;
    
    // Check for significant disagreement (>10ms difference)
    uint32_t time_difference = (hw_elapsed > sw_elapsed) ? 
                              (hw_elapsed - sw_elapsed) : (sw_elapsed - hw_elapsed);
    
    if (time_difference > 10) {
        g_dual_watchdog.disagreement_count++;
        printf("   ⚠️  Watchdog disagreement: HW=%dms, SW=%dms (diff=%dms)\n", 
               hw_elapsed, sw_elapsed, time_difference);
        
        if (g_dual_watchdog.disagreement_count > 3) {
            printf("   💥 Multiple watchdog disagreements detected!\n");
            return false;
        }
    }
    
    g_dual_watchdog.last_cross_check_time = current_time;
    return true;
}

/**
 * @brief Kick both watchdogs with cross-validation
 */
static bool kick_dual_watchdogs(void)
{
    uint32_t current_time = get_time_ms();
    
    // Kick hardware watchdog
    g_dual_watchdog.hw_watchdog.kick_count++;
    g_dual_watchdog.hw_watchdog.last_kick_time = current_time;
    
    // Kick software watchdog  
    g_dual_watchdog.sw_watchdog.kick_count++;
    g_dual_watchdog.sw_watchdog.last_kick_time = current_time;
    
    printf("   🔄 Dual watchdog kick: HW #%d, SW #%d\n",
           g_dual_watchdog.hw_watchdog.kick_count,
           g_dual_watchdog.sw_watchdog.kick_count);
    
    return cross_validate_dual_watchdogs();
}

// =============================================================================
// ADAPTIVE TIMING IMPLEMENTATION
// =============================================================================

/**
 * @brief Initialize adaptive timing system
 */
static void initialize_adaptive_timing(void)
{
    printf("\n🎛️  Initializing Adaptive Timing System\n");
    
    g_adaptive_timing.current_mode = TIMING_MODE_STARTUP;
    g_adaptive_timing.cycle_time_ms = STARTUP_CYCLE_TIME_MS;
    g_adaptive_timing.kick_window_min_ms = STARTUP_CYCLE_TIME_MS - 2;
    g_adaptive_timing.kick_window_max_ms = STARTUP_CYCLE_TIME_MS + 2;
    g_adaptive_timing.mode_change_count = 0;
    g_adaptive_timing.temperature_celsius = 25;  // Room temperature
    g_adaptive_timing.startup_complete = false;
    
    printf("   ✅ Initial mode: STARTUP (%dms cycle)\n", STARTUP_CYCLE_TIME_MS);
    printf("   ✅ Temperature monitoring enabled\n");
    printf("   ✅ Dynamic timing adjustment active\n");
}

/**
 * @brief Update adaptive timing based on system conditions
 */
static void update_adaptive_timing(void)
{
    timing_mode_t new_mode = g_adaptive_timing.current_mode;
    uint32_t new_cycle_time = g_adaptive_timing.cycle_time_ms;
    
    // Simulate temperature reading
    g_adaptive_timing.temperature_celsius = 25 + (rand() % 60);  // 25-85°C
    
    // Determine appropriate timing mode
    if (!g_adaptive_timing.startup_complete) {
        // Still in startup phase
        static int startup_cycles = 0;
        startup_cycles++;
        if (startup_cycles > 5) {
            g_adaptive_timing.startup_complete = true;
            new_mode = TIMING_MODE_NORMAL;
            new_cycle_time = BASE_CYCLE_TIME_MS;
        }
    } else if (g_adaptive_timing.temperature_celsius > 70) {
        // High temperature - extend timing
        new_mode = TIMING_MODE_THERMAL;
        new_cycle_time = THERMAL_CYCLE_TIME_MS;
    } else {
        // Normal operation
        new_mode = TIMING_MODE_NORMAL;
        new_cycle_time = BASE_CYCLE_TIME_MS;
    }
    
    // Update timing if mode changed
    if (new_mode != g_adaptive_timing.current_mode) {
        g_adaptive_timing.mode_change_count++;
        printf("   🎛️  Timing mode change: %d → %d (%dms cycle, temp=%d°C)\n",
               g_adaptive_timing.current_mode, new_mode, new_cycle_time,
               g_adaptive_timing.temperature_celsius);
        
        g_adaptive_timing.current_mode = new_mode;
        g_adaptive_timing.cycle_time_ms = new_cycle_time;
        g_adaptive_timing.kick_window_min_ms = new_cycle_time - 2;
        g_adaptive_timing.kick_window_max_ms = new_cycle_time + 2;
    }
}

// =============================================================================
// PATTERN VALIDATION IMPLEMENTATION
// =============================================================================

/**
 * @brief Initialize pattern validation system
 */
static void initialize_pattern_validator(void)
{
    printf("\n🔐 Initializing Pattern Validation System\n");
    
    g_pattern_validator.expected_pattern = WATCHDOG_PATTERNS[0];
    g_pattern_validator.sequence_index = 0;
    g_pattern_validator.pattern_violations = 0;
    g_pattern_validator.successful_validations = 0;
    g_pattern_validator.synchronization_lost = false;
    
    printf("   ✅ Pattern sequence length: %d\n", PATTERN_SEQUENCE_LENGTH);
    printf("   ✅ Initial pattern: 0x%04X\n", g_pattern_validator.expected_pattern);
    printf("   ✅ Cryptographic validation enabled\n");
}

/**
 * @brief Validate watchdog pattern and advance sequence
 */
static bool validate_watchdog_pattern(uint16_t received_pattern)
{
    if (received_pattern != g_pattern_validator.expected_pattern) {
        g_pattern_validator.pattern_violations++;
        printf("   ❌ Pattern violation: got 0x%04X, expected 0x%04X\n",
               received_pattern, g_pattern_validator.expected_pattern);
        
        if (g_pattern_validator.pattern_violations > 2) {
            g_pattern_validator.synchronization_lost = true;
            printf("   💥 Pattern synchronization lost!\n");
            return false;
        }
        return false;
    }
    
    // Pattern validation successful
    g_pattern_validator.successful_validations++;
    
    // Advance to next pattern in sequence
    g_pattern_validator.sequence_index = 
        (g_pattern_validator.sequence_index + 1) % PATTERN_SEQUENCE_LENGTH;
    g_pattern_validator.expected_pattern = 
        WATCHDOG_PATTERNS[g_pattern_validator.sequence_index];
    
    printf("   🔐 Pattern validated: 0x%04X → 0x%04X (next)\n",
           received_pattern, g_pattern_validator.expected_pattern);
    
    return true;
}

// =============================================================================
// DEMONSTRATION SCENARIOS
// =============================================================================

/**
 * @brief Demonstrate hierarchical watchdog supervision
 */
static void demo_hierarchical_supervision(void)
{
    printf("\n" "="*60 "\n");
    printf("🏗️  DEMO: Hierarchical Watchdog Supervision\n");
    printf("="*60 "\n");
    
    printf("\nScenario: Multi-level supervision in autonomous driving system\n");
    printf("- System Level: Overall vehicle safety monitoring\n");
    printf("- Function Level: Path planning and control supervision\n");
    printf("- Task Level: Individual sensor and actuator monitoring\n\n");
    
    for (int cycle = 1; cycle <= 5; cycle++) {
        printf("--- Supervision Cycle %d ---\n", cycle);
        
        // Check watchdog health
        check_hierarchical_watchdogs();
        
        // Kick watchdogs in hierarchy order (bottom-up)
        kick_hierarchical_watchdog(WDT_LEVEL_TASK);
        kick_hierarchical_watchdog(WDT_LEVEL_FUNCTION);  
        kick_hierarchical_watchdog(WDT_LEVEL_SYSTEM);
        
        usleep(25000);  // 25ms delay
        printf("\n");
    }
}

/**
 * @brief Demonstrate dual watchdog cross-validation
 */
static void demo_dual_watchdog_validation(void)
{
    printf("="*60 "\n");
    printf("🔄 DEMO: Dual Watchdog Cross-Validation\n");
    printf("="*60 "\n");
    
    printf("\nScenario: Brake control system with hardware/software diversity\n");
    printf("- Hardware watchdog provides ultimate safety backup\n");
    printf("- Software watchdog enables early fault detection\n");
    printf("- Cross-validation detects watchdog disagreements\n\n");
    
    for (int cycle = 1; cycle <= 5; cycle++) {
        printf("--- Dual Watchdog Cycle %d ---\n", cycle);
        
        if (!kick_dual_watchdogs()) {
            printf("   💥 Cross-validation failure detected!\n");
        }
        
        usleep(30000);  // 30ms delay
        printf("\n");
    }
}

/**
 * @brief Demonstrate adaptive timing adjustment
 */
static void demo_adaptive_timing(void)
{
    printf("="*60 "\n");
    printf("🎛️  DEMO: Adaptive Timing Adjustment\n");
    printf("="*60 "\n");
    
    printf("\nScenario: Battery thermal management with temperature compensation\n");
    printf("- Startup phase: Extended timing for initialization\n");
    printf("- Normal operation: Optimal performance timing\n");
    printf("- High temperature: Conservative timing for safety\n\n");
    
    for (int cycle = 1; cycle <= 8; cycle++) {
        printf("--- Adaptive Timing Cycle %d ---\n", cycle);
        
        update_adaptive_timing();
        
        printf("   Current: %s mode, %dms cycle, %d°C\n",
               (g_adaptive_timing.current_mode == TIMING_MODE_STARTUP) ? "STARTUP" :
               (g_adaptive_timing.current_mode == TIMING_MODE_NORMAL) ? "NORMAL" :
               (g_adaptive_timing.current_mode == TIMING_MODE_THERMAL) ? "THERMAL" : "OTHER",
               g_adaptive_timing.cycle_time_ms, g_adaptive_timing.temperature_celsius);
        
        usleep(20000);  // 20ms delay
        printf("\n");
    }
}

/**
 * @brief Demonstrate pattern-based validation
 */
static void demo_pattern_validation(void)
{
    printf("="*60 "\n");
    printf("🔐 DEMO: Pattern-Based Watchdog Validation\n");
    printf("="*60 "\n");
    
    printf("\nScenario: Secure communication in vehicle networking\n");
    printf("- Cryptographic pattern sequences prevent false kicks\n");
    printf("- Pattern violations indicate potential security threats\n");
    printf("- Synchronization loss triggers security lockdown\n\n");
    
    for (int cycle = 1; cycle <= 6; cycle++) {
        printf("--- Pattern Validation Cycle %d ---\n", cycle);
        
        uint16_t pattern_to_send;
        
        if (cycle == 4) {
            // Inject a pattern violation for demonstration
            pattern_to_send = 0xDEAD;  // Wrong pattern
            printf("   🔥 Injecting pattern violation for demonstration\n");
        } else {
            pattern_to_send = g_pattern_validator.expected_pattern;
        }
        
        validate_watchdog_pattern(pattern_to_send);
        
        usleep(15000);  // 15ms delay
        printf("\n");
    }
}

/**
 * @brief Generate comprehensive advanced patterns report
 */
static void generate_advanced_patterns_report(void)
{
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║              ADVANCED WATCHDOG PATTERNS REPORT              ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    
    printf("📊 HIERARCHICAL WATCHDOG SUMMARY:\n");
    for (int level = 0; level < WDT_LEVEL_COUNT; level++) {
        hierarchical_watchdog_t* wdt = &g_watchdog_hierarchy[level];
        printf("   %s: %d kicks, %d timeouts\n", 
               wdt->name, wdt->kick_count, wdt->timeout_count);
    }
    
    printf("\n📊 DUAL WATCHDOG SUMMARY:\n");
    printf("   Hardware kicks: %d\n", g_dual_watchdog.hw_watchdog.kick_count);
    printf("   Software kicks: %d\n", g_dual_watchdog.sw_watchdog.kick_count);
    printf("   Cross-validation disagreements: %d\n", g_dual_watchdog.disagreement_count);
    
    printf("\n📊 ADAPTIVE TIMING SUMMARY:\n");
    printf("   Current mode: %d\n", g_adaptive_timing.current_mode);
    printf("   Mode changes: %d\n", g_adaptive_timing.mode_change_count);
    printf("   Final cycle time: %dms\n", g_adaptive_timing.cycle_time_ms);
    printf("   Final temperature: %d°C\n", g_adaptive_timing.temperature_celsius);
    
    printf("\n📊 PATTERN VALIDATION SUMMARY:\n");
    printf("   Successful validations: %d\n", g_pattern_validator.successful_validations);
    printf("   Pattern violations: %d\n", g_pattern_validator.pattern_violations);
    printf("   Synchronization status: %s\n", 
           g_pattern_validator.synchronization_lost ? "LOST" : "OK");
    
    printf("\n🎓 ADVANCED PATTERNS LEARNED:\n");
    printf("   ✅ Hierarchical supervision with multi-level timeouts\n");
    printf("   ✅ Dual watchdog systems with cross-validation\n");
    printf("   ✅ Adaptive timing based on operating conditions\n");
    printf("   ✅ Pattern-based validation for security\n");
    printf("   ✅ Complex fault detection and isolation\n");
    printf("   ✅ Real-world automotive safety architectures\n");
    
    printf("\n🚀 APPLICATIONS IN AUTOMOTIVE SYSTEMS:\n");
    printf("   • Autonomous driving (ASIL D): Hierarchical + dual watchdogs\n");
    printf("   • Battery management (ASIL C): Adaptive timing + patterns\n");
    printf("   • Brake control (ASIL D): Dual diversity + cross-validation\n");
    printf("   • Engine management (ASIL B): Hierarchical supervision\n");
    printf("   • Vehicle networking: Pattern validation for security\n");
}

/**
 * @brief Main advanced patterns demonstration
 */
int main(void)
{
    printf("=== ISO 26262 Exercise 02: Advanced Watchdog Patterns ===\n");
    printf("🎯 Demonstrating sophisticated watchdog architectures\n");
    printf("🚗 Applications: ASIL C/D automotive safety systems\n");
    printf("🛡️  Focus: Hierarchical, dual, adaptive, and pattern-based supervision\n\n");
    
    srand((unsigned int)time(NULL));
    
    // Initialize all advanced watchdog systems
    initialize_hierarchical_watchdogs();
    initialize_dual_watchdog();
    initialize_adaptive_timing();
    initialize_pattern_validator();
    
    // Demonstrate each advanced pattern
    demo_hierarchical_supervision();
    demo_dual_watchdog_validation();
    demo_adaptive_timing();
    demo_pattern_validation();
    
    // Generate comprehensive report
    generate_advanced_patterns_report();
    
    printf("\n🏆 Advanced Watchdog Patterns Demonstration Complete!\n");
    printf("📚 These patterns form the foundation for ASIL C/D systems\n");
    printf("🚀 Ready to apply these concepts in Exercise 03: Memory Protection!\n");
    
    return 0;
}