/**
 * @file timing_analysis.c
 * @brief Timing Analysis Tool for Watchdog Behavior Study
 * @author Automotive Safety Lab
 * 
 * Educational Tool: Analyze timing behavior of watchdog systems
 * Focus: Deadline monitoring, timing windows, and diagnostic coverage
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Timing analysis configuration
#define ANALYSIS_CYCLES         20
#define TARGET_CYCLE_TIME_MS    10
#define WATCHDOG_WINDOW_MIN_MS  8
#define WATCHDOG_WINDOW_MAX_MS  12
#define WATCHDOG_TIMEOUT_MS     50

// Analysis results structure
typedef struct {
    uint32_t cycle_count;
    uint32_t total_cycles;
    uint32_t cycles_within_deadline;
    uint32_t cycles_over_deadline;
    uint32_t kicks_in_window;
    uint32_t kicks_too_early;
    uint32_t kicks_too_late;
    uint32_t min_cycle_time;
    uint32_t max_cycle_time;
    uint32_t avg_cycle_time;
} timing_analysis_t;

static timing_analysis_t g_analysis = {0};

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
 * @brief Simulate variable execution time
 */
static void simulate_workload(uint32_t base_time_ms, uint32_t variance_ms)
{
    uint32_t actual_time = base_time_ms + (rand() % (variance_ms * 2)) - variance_ms;
    usleep(actual_time * 1000);
}

/**
 * @brief Analyze watchdog kick timing
 */
static void analyze_kick_timing(uint32_t kick_time, uint32_t last_kick_time)
{
    uint32_t elapsed = kick_time - last_kick_time;
    
    if (elapsed >= WATCHDOG_WINDOW_MIN_MS && elapsed <= WATCHDOG_WINDOW_MAX_MS) {
        g_analysis.kicks_in_window++;
        printf("   ✅ Valid kick: %dms (window: %d-%dms)\n", 
               elapsed, WATCHDOG_WINDOW_MIN_MS, WATCHDOG_WINDOW_MAX_MS);
    } else if (elapsed < WATCHDOG_WINDOW_MIN_MS) {
        g_analysis.kicks_too_early++;
        printf("   ⚠️  Early kick: %dms (< %dms minimum)\n", elapsed, WATCHDOG_WINDOW_MIN_MS);
    } else if (elapsed <= WATCHDOG_TIMEOUT_MS) {
        g_analysis.kicks_too_late++;
        printf("   ⚠️  Late kick: %dms (> %dms maximum)\n", elapsed, WATCHDOG_WINDOW_MAX_MS);
    } else {
        printf("   💥 Watchdog timeout: %dms (> %dms timeout)\n", elapsed, WATCHDOG_TIMEOUT_MS);
    }
}

/**
 * @brief Analyze cycle timing
 */
static void analyze_cycle_timing(uint32_t cycle_time)
{
    g_analysis.cycle_count++;
    g_analysis.total_cycles += cycle_time;
    
    if (cycle_time <= TARGET_CYCLE_TIME_MS) {
        g_analysis.cycles_within_deadline++;
        printf("   ✅ Cycle time: %dms (≤ %dms target)\n", cycle_time, TARGET_CYCLE_TIME_MS);
    } else {
        g_analysis.cycles_over_deadline++;
        printf("   ❌ Deadline miss: %dms (> %dms target)\n", cycle_time, TARGET_CYCLE_TIME_MS);
    }
    
    // Update min/max tracking
    if (g_analysis.cycle_count == 1 || cycle_time < g_analysis.min_cycle_time) {
        g_analysis.min_cycle_time = cycle_time;
    }
    if (cycle_time > g_analysis.max_cycle_time) {
        g_analysis.max_cycle_time = cycle_time;
    }
}

/**
 * @brief Generate timing analysis report
 */
static void generate_analysis_report(void)
{
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    TIMING ANALYSIS REPORT                   ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    
    // Cycle timing analysis
    printf("📊 CYCLE TIMING ANALYSIS:\n");
    printf("   Total cycles analyzed: %d\n", g_analysis.cycle_count);
    printf("   Cycles within deadline: %d (%.1f%%)\n", 
           g_analysis.cycles_within_deadline, 
           (float)g_analysis.cycles_within_deadline * 100.0f / g_analysis.cycle_count);
    printf("   Cycles over deadline: %d (%.1f%%)\n", 
           g_analysis.cycles_over_deadline,
           (float)g_analysis.cycles_over_deadline * 100.0f / g_analysis.cycle_count);
    
    if (g_analysis.cycle_count > 0) {
        g_analysis.avg_cycle_time = g_analysis.total_cycles / g_analysis.cycle_count;
        printf("   Minimum cycle time: %dms\n", g_analysis.min_cycle_time);
        printf("   Maximum cycle time: %dms\n", g_analysis.max_cycle_time);
        printf("   Average cycle time: %dms\n", g_analysis.avg_cycle_time);
    }
    
    printf("\n");
    
    // Watchdog timing analysis
    uint32_t total_kicks = g_analysis.kicks_in_window + g_analysis.kicks_too_early + g_analysis.kicks_too_late;
    printf("🐕 WATCHDOG TIMING ANALYSIS:\n");
    printf("   Total kicks analyzed: %d\n", total_kicks);
    
    if (total_kicks > 0) {
        printf("   Kicks in valid window: %d (%.1f%%)\n",
               g_analysis.kicks_in_window,
               (float)g_analysis.kicks_in_window * 100.0f / total_kicks);
        printf("   Early kicks: %d (%.1f%%)\n",
               g_analysis.kicks_too_early,
               (float)g_analysis.kicks_too_early * 100.0f / total_kicks);
        printf("   Late kicks: %d (%.1f%%)\n",
               g_analysis.kicks_too_late,
               (float)g_analysis.kicks_too_late * 100.0f / total_kicks);
    }
    
    printf("\n");
    
    // Safety assessment
    printf("🛡️  SAFETY ASSESSMENT:\n");
    
    float cycle_compliance = (float)g_analysis.cycles_within_deadline * 100.0f / g_analysis.cycle_count;
    float kick_compliance = (float)g_analysis.kicks_in_window * 100.0f / total_kicks;
    
    if (cycle_compliance >= 95.0f) {
        printf("   ✅ Cycle timing compliance: %.1f%% (Excellent)\n", cycle_compliance);
    } else if (cycle_compliance >= 90.0f) {
        printf("   ⚠️  Cycle timing compliance: %.1f%% (Acceptable)\n", cycle_compliance);
    } else {
        printf("   ❌ Cycle timing compliance: %.1f%% (Unacceptable)\n", cycle_compliance);
    }
    
    if (kick_compliance >= 95.0f) {
        printf("   ✅ Watchdog timing compliance: %.1f%% (Excellent)\n", kick_compliance);
    } else if (kick_compliance >= 90.0f) {
        printf("   ⚠️  Watchdog timing compliance: %.1f%% (Acceptable)\n", kick_compliance);
    } else {
        printf("   ❌ Watchdog timing compliance: %.1f%% (Unacceptable)\n", kick_compliance);
    }
    
    // Overall diagnostic coverage assessment
    float overall_coverage = (cycle_compliance + kick_compliance) / 2.0f;
    printf("\n");
    printf("📈 DIAGNOSTIC COVERAGE: %.1f%%", overall_coverage);
    
    if (overall_coverage >= 90.0f) {
        printf(" ✅ (ASIL A Compliant)\n");
        printf("   System meets ASIL A diagnostic coverage requirements\n");
    } else {
        printf(" ❌ (Below ASIL A Requirement)\n");
        printf("   System requires improvement to meet ASIL A standards\n");
    }
    
    printf("\n");
    printf("🔍 RECOMMENDATIONS:\n");
    
    if (g_analysis.cycles_over_deadline > 0) {
        printf("   • Investigate deadline violations in cycle timing\n");
        printf("   • Consider workload optimization or deadline adjustment\n");
    }
    
    if (g_analysis.kicks_too_early > 0) {
        printf("   • Review watchdog kick placement in control loop\n");
        printf("   • Ensure minimum timing requirements are met\n");
    }
    
    if (g_analysis.kicks_too_late > 0) {
        printf("   • Investigate timing delays in watchdog supervision\n");
        printf("   • Consider timeout protection for blocking operations\n");
    }
    
    if (overall_coverage >= 90.0f) {
        printf("   ✅ System demonstrates good timing safety practices\n");
    }
}

/**
 * @brief Main timing analysis execution
 */
int main(void)
{
    printf("=== ISO 26262 Exercise 02: Timing Analysis Tool ===\n");
    printf("🎯 Analyzing watchdog timing behavior and diagnostic coverage\n");
    printf("⏱️  Target: %dms cycle time, %d-%dms watchdog window\n\n", 
           TARGET_CYCLE_TIME_MS, WATCHDOG_WINDOW_MIN_MS, WATCHDOG_WINDOW_MAX_MS);
    
    srand((unsigned int)time(NULL));
    uint32_t last_kick_time = get_time_ms();
    
    for (int cycle = 1; cycle <= ANALYSIS_CYCLES; cycle++) {
        printf("--- Analysis Cycle %d ---\n", cycle);
        
        uint32_t cycle_start = get_time_ms();
        
        // Simulate variable workload (realistic automotive conditions)
        uint32_t base_workload = 5;  // 5ms base execution time
        uint32_t workload_variance = 3;  // ±3ms variance
        
        if (cycle % 5 == 0) {
            // Simulate periodic high-load conditions
            printf("   🔥 High-load condition (network/diagnostics)\n");
            base_workload = 8;
            workload_variance = 5;
        }
        
        simulate_workload(base_workload, workload_variance);
        
        uint32_t cycle_end = get_time_ms();
        uint32_t cycle_time = cycle_end - cycle_start;
        
        // Analyze cycle timing
        analyze_cycle_timing(cycle_time);
        
        // Simulate watchdog kick timing
        uint32_t kick_time = cycle_end;
        analyze_kick_timing(kick_time, last_kick_time);
        last_kick_time = kick_time;
        
        printf("\n");
    }
    
    // Generate comprehensive analysis report
    generate_analysis_report();
    
    return 0;
}