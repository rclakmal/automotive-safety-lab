/*
 * AUTOMOTIVE SAFETY LAB - Integration Test Framework Implementation
 * ================================================================
 */

#include "integration_test_framework.h"
#include <stdio.h>
#include <string.h>

/*
 * Framework Utilities Implementation
 */

void print_test_header(const char* test_name) {
    printf("\n🔍 %s\n", test_name);
    printf("================================================\n");
}

void print_test_result(const char* test_name, bool passed) {
    printf("   %s %s\n", passed ? "✅" : "❌", test_name);
}

void print_progress_summary(const learning_progress_t* progress) {
    printf("\n📊 LEARNING PROGRESS SUMMARY\n");
    printf("============================\n");
    printf("Exercises Completed: %d/%d\n", 
           progress->exercises_completed, progress->total_exercises);
    printf("Cumulative Score: %d/%d\n", 
           progress->cumulative_score, progress->maximum_score);
    printf("Completion Percentage: %.1f%%\n", 
           (float)progress->cumulative_score / progress->maximum_score * 100.0f);
    printf("Certification Ready: %s\n", 
           progress->ready_for_certification ? "✅ YES" : "📚 Continue Learning");
}

void generate_completion_certificate(uint32_t score, char* certificate, size_t size) {
    if (score >= 125) {
        snprintf(certificate, size, "🎖️ AUTOMOTIVE SAFETY MASTER - Perfect Score Achievement");
    } else if (score >= 110) {
        snprintf(certificate, size, "🥇 AUTOMOTIVE SAFETY EXPERT - Exceptional Performance");
    } else if (score >= 95) {
        snprintf(certificate, size, "🥈 AUTOMOTIVE SAFETY ENGINEER - Strong Competency");
    } else if (score >= 80) {
        snprintf(certificate, size, "🥉 AUTOMOTIVE SAFETY PRACTITIONER - Good Foundation");
    } else if (score >= 65) {
        snprintf(certificate, size, "📚 AUTOMOTIVE SAFETY STUDENT - Basic Understanding");
    } else {
        snprintf(certificate, size, "🔄 CONTINUE LEARNING - Review and Practice More");
    }
}