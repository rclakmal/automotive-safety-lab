/*
 * AUTOMOTIVE SAFETY LAB - Integration Test Framework
 * ==================================================
 * 
 * Framework for validating the complete learning progression
 * and ensuring educational continuity across all exercises.
 */

#ifndef INTEGRATION_TEST_FRAMEWORK_H
#define INTEGRATION_TEST_FRAMEWORK_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Learning Progression Validation Functions
 */

// Exercise 01: Basic Safety Concepts (ASIL QM)
bool validate_safety_principles(void);
bool validate_defensive_programming(void);
bool validate_error_handling(void);

// Exercise 02: Watchdog Timer Systems (ASIL A)
bool validate_watchdog_initialization(void);
bool validate_timing_supervision(void);
bool validate_safe_state_transitions(void);
bool validate_timeout_handling(void);

// Exercise 03: Memory Protection (ASIL B)
bool validate_mpu_configuration(void);
bool validate_stack_protection(void);
bool validate_heap_isolation(void);
bool validate_interference_freedom(void);

// Exercise 04: Redundancy & Voting (ASIL C)
bool validate_dual_channel_architecture(void);
bool validate_cross_checking(void);
bool validate_voting_system(void);
bool validate_diagnostic_coverage_asil_c(void);

// Exercise 05: Critical Systems (ASIL D)
bool validate_tmr_architecture(void);
bool validate_formal_verification(void);
bool validate_diverse_programming(void);
bool validate_fail_operational_design(void);
bool validate_diagnostic_coverage_asil_d(void);

// Cross-Exercise Integration Validation
bool validate_progressive_complexity(void);
bool validate_asil_progression(void);
bool validate_safety_concept_continuity(void);
bool validate_educational_value(void);

/*
 * Test Result Structure
 */
typedef struct {
    bool passed;
    uint32_t score;
    char description[256];
    char recommendations[512];
} test_result_t;

/*
 * Learning Progress Tracking
 */
typedef struct {
    uint32_t exercises_completed;
    uint32_t total_exercises;
    uint32_t cumulative_score;
    uint32_t maximum_score;
    bool ready_for_certification;
} learning_progress_t;

/*
 * Framework Utilities
 */
void print_test_header(const char* test_name);
void print_test_result(const char* test_name, bool passed);
void print_progress_summary(const learning_progress_t* progress);
void generate_completion_certificate(uint32_t score, char* certificate, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* INTEGRATION_TEST_FRAMEWORK_H */