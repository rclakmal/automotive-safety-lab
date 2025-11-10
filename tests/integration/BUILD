# AUTOMOTIVE SAFETY LAB - Integration Tests
# Bazel BUILD Configuration
# =========================================================================

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

package(default_visibility = ["//visibility:public"])

# =========================================================================
# Integration Test Framework
# =========================================================================

cc_library(
    name = "integration_test_framework",
    hdrs = ["integration_test_framework.h"],
    srcs = ["integration_test_framework.c"],
    copts = [
        "-Wall",
        "-Wextra",
        "-Werror",
    ],
    defines = ["INTEGRATION_TEST_FRAMEWORK=1"],
)

# =========================================================================
# Comprehensive Integration Test Suite
# =========================================================================

cc_binary(
    name = "integration_test_suite",
    srcs = ["integration_test_suite.c"],
    deps = [
        ":integration_test_framework",
        "//exercises/01_basic_safety:safety_framework",
        "//exercises/02_watchdog_timer:watchdog_lib",
        "//exercises/03_memory_protection:memory_protection_lib",
        "//exercises/04_redundancy_voting:tmr_framework",
        "//exercises/05_critical_systems:asil_d_safety_lib",
    ],
    copts = [
        "-Wall", 
        "-Wextra",
        "-Werror",
    ],
    defines = [
        "INTEGRATION_TEST_SUITE=1",
        "AUTOMOTIVE_SAFETY_LAB=1",
    ],
)

# Exercise-Specific Integration Tests
cc_test(
    name = "exercise_01_integration_test",
    srcs = ["exercise_01_integration_test.c"],
    deps = [
        ":integration_test_framework",
        "//exercises/01_basic_safety:safety_framework",
        "@googletest//:gtest_main",
    ],
    copts = ["-Wall", "-Wextra"],
    timeout = "short",
)

cc_test(
    name = "exercise_02_integration_test", 
    srcs = ["exercise_02_integration_test.c"],
    deps = [
        ":integration_test_framework",
        "//exercises/02_watchdog_timer:watchdog_lib",
        "@googletest//:gtest_main",
    ],
    copts = ["-Wall", "-Wextra"],
    timeout = "short",
)

cc_test(
    name = "exercise_03_integration_test",
    srcs = ["exercise_03_integration_test.c"],
    deps = [
        ":integration_test_framework", 
        "//exercises/03_memory_protection:memory_protection_lib",
        "@googletest//:gtest_main",
    ],
    copts = ["-Wall", "-Wextra"],
    timeout = "moderate",
)

cc_test(
    name = "exercise_04_integration_test",
    srcs = ["exercise_04_integration_test.c"],
    deps = [
        ":integration_test_framework",
        "//exercises/04_redundancy_voting:tmr_framework",
        "@googletest//:gtest_main",
    ],
    copts = ["-Wall", "-Wextra"],
    timeout = "moderate",
)

cc_test(
    name = "exercise_05_integration_test",
    srcs = ["exercise_05_integration_test.c"],
    deps = [
        ":integration_test_framework",
        "//exercises/05_critical_systems:asil_d_safety_lib",
        "@googletest//:gtest_main", 
    ],
    copts = ["-Wall", "-Wextra"],
    timeout = "long",
    size = "large",
)

# =========================================================================
# Cross-Exercise Validation Tests
# =========================================================================

cc_test(
    name = "asil_progression_test",
    srcs = ["asil_progression_test.c"],
    deps = [
        ":integration_test_framework",
        "//exercises/01_basic_safety:safety_framework",
        "//exercises/02_watchdog_timer:watchdog_lib", 
        "//exercises/03_memory_protection:memory_protection_lib",
        "//exercises/04_redundancy_voting:tmr_framework",
        "//exercises/05_critical_systems:asil_d_safety_lib",
        "@googletest//:gtest_main",
    ],
    copts = ["-Wall", "-Wextra"],
    timeout = "long",
    size = "large",
)

cc_test(
    name = "safety_concept_continuity_test",
    srcs = ["safety_concept_continuity_test.c"],
    deps = [
        ":integration_test_framework",
        "//exercises/01_basic_safety:safety_framework",
        "//exercises/02_watchdog_timer:watchdog_lib",
        "//exercises/03_memory_protection:memory_protection_lib", 
        "//exercises/04_redundancy_voting:tmr_framework",
        "//exercises/05_critical_systems:asil_d_safety_lib",
        "@googletest//:gtest_main",
    ],
    copts = ["-Wall", "-Wextra"],
    timeout = "moderate",
)

cc_test(
    name = "educational_value_test",
    srcs = ["educational_value_test.c"],
    deps = [
        ":integration_test_framework",
        "@googletest//:gtest_main",
    ],
    copts = ["-Wall", "-Wextra"],
    timeout = "short",
)

# =========================================================================
# Learning Progression Validation
# =========================================================================

cc_binary(
    name = "learning_progression_validator",
    srcs = ["learning_progression_validator.c"],
    deps = [
        ":integration_test_framework",
        "//exercises/01_basic_safety:safety_framework",
        "//exercises/02_watchdog_timer:watchdog_lib",
        "//exercises/03_memory_protection:memory_protection_lib",
        "//exercises/04_redundancy_voting:tmr_framework", 
        "//exercises/05_critical_systems:asil_d_safety_lib",
    ],
    copts = ["-Wall", "-Wextra"],
    defines = ["LEARNING_PROGRESSION_VALIDATOR=1"],
)

# Complete Lab Validation (Master Test)
cc_binary(
    name = "complete_lab_validation",
    srcs = ["complete_lab_validation.c"],
    deps = [
        ":integration_test_framework",
        "//exercises/01_basic_safety:safety_framework",
        "//exercises/02_watchdog_timer:watchdog_lib",
        "//exercises/03_memory_protection:memory_protection_lib",
        "//exercises/04_redundancy_voting:tmr_framework",
        "//exercises/05_critical_systems:asil_d_safety_lib",
    ],
    copts = ["-Wall", "-Wextra"],
    defines = [
        "COMPLETE_LAB_VALIDATION=1",
        "AUTOMOTIVE_SAFETY_MASTER_TEST=1",
    ],
)

# =========================================================================
# Test Suites
# =========================================================================

# All Integration Tests
test_suite(
    name = "all_integration_tests", 
    tests = [
        ":exercise_01_integration_test",
        ":exercise_02_integration_test",
        ":exercise_03_integration_test",
        ":exercise_04_integration_test",
        ":exercise_05_integration_test",
    ],
)

# Cross-Exercise Validation Tests
test_suite(
    name = "cross_exercise_tests",
    tests = [
        ":asil_progression_test",
        ":safety_concept_continuity_test", 
        ":educational_value_test",
    ],
)

# Complete Validation Suite
test_suite(
    name = "complete_validation",
    tests = [
        ":all_integration_tests",
        ":cross_exercise_tests",
    ],
)

# Master-Level Comprehensive Test Suite
test_suite(
    name = "master_level_validation",
    tests = [
        ":complete_validation",
        # Additional master-level challenges could be added here
    ],
)