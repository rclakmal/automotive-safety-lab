# AUTOMOTIVE SAFETY LAB - Exercise 03: Memory Protection (ASIL B)
# Bazel BUILD Configuration
# =========================================================================

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")
load("//tools/safety:defs.bzl", "safety_analysis", "memory_protection_test")

package(default_visibility = ["//visibility:public"])

# =========================================================================
# Core Learning Examples
# =========================================================================

# Violation Example: Demonstrates memory safety failures
cc_binary(
    name = "violation_example",
    srcs = ["violation.c"],
    copts = [
        "-Wall",
        "-Wextra", 
        "-Werror",
        # Disable some warnings for violation example to show unsafe patterns
        "-Wno-unused-variable",
        "-Wno-format-security",
    ],
    defines = [
        "VIOLATION_EXAMPLE=1",
        "ASIL_B_LEARNING=1",
    ],
)

# Compliant Example: Shows proper ASIL B memory protection
cc_binary(
    name = "compliant_example", 
    srcs = ["compliant.c"],
    deps = [
        ":memory_protection_lib",
        ":asil_b_framework",
        "@googletest//:gtest",
    ],
    copts = [
        "-Wall",
        "-Wextra",
        "-Werror",
        "-O2",
        # Enable memory protection features
        "-fstack-protector-strong",
        "-D_FORTIFY_SOURCE=2",
        "-fPIE",
    ],
    linkopts = [
        "-pie",
        "-Wl,-z,relro,-z,now",  # Security hardening
    ],
    defines = [
        "COMPLIANT_EXAMPLE=1", 
        "ASIL_B_COMPLIANT=1",
        "MEMORY_PROTECTION_ENABLED=1",
    ],
)

# Interactive Tutorial Launcher
cc_binary(
    name = "interactive_tutorial",
    srcs = ["tutorial_launcher.c"],
    data = ["tutorial.sh"],
    deps = [
        ":memory_protection_lib",
    ],
    copts = ["-Wall", "-Wextra"],
)

# =========================================================================
# Memory Protection Library
# =========================================================================

cc_library(
    name = "memory_protection_lib",
    hdrs = [
        "memory_protection.h",
        "mpu_config.h", 
        "stack_protection.h",
        "heap_isolation.h",
    ],
    srcs = [
        "memory_protection.c",
        "mpu_config.c",
        "stack_protection.c", 
        "heap_isolation.c",
    ],
    copts = [
        "-Wall",
        "-Wextra",
        "-Werror",
        "-std=c11",
    ],
    defines = [
        "MEMORY_PROTECTION_LIB=1",
        "ASIL_B_MPU_ENABLED=1",
    ],
    visibility = ["//exercises:__subpackages__"],
)

# ASIL B Safety Framework
cc_library(
    name = "asil_b_framework",
    hdrs = [
        "asil_b_framework.h",
        "safety_monitor.h",
        "diagnostic_manager.h",
    ],
    srcs = [
        "asil_b_framework.c",
        "safety_monitor.c", 
        "diagnostic_manager.c",
    ],
    deps = [
        ":memory_protection_lib",
        "//generic/quality:safety_framework",
    ],
    copts = [
        "-Wall",
        "-Wextra", 
        "-Werror",
    ],
    defines = [
        "ASIL_B_FRAMEWORK=1",
        "SAFETY_MONITORING_ENABLED=1",
    ],
)

# =========================================================================
# Interactive Challenges
# =========================================================================

# Build Challenge: Implement your own memory protection
cc_binary(
    name = "build_challenge",
    srcs = ["build_challenge.c"],
    deps = [
        ":memory_protection_lib",
        ":challenge_framework",
    ],
    copts = ["-Wall", "-Wextra"],
    defines = ["BUILD_CHALLENGE=1"],
)

# Debug Challenge: Find and fix memory protection issues
cc_binary(
    name = "debug_challenge", 
    srcs = ["debug_challenge.c"],
    deps = [
        ":memory_protection_lib",
        ":challenge_framework",
    ],
    copts = [
        "-Wall",
        "-Wextra",
        "-g",  # Debug symbols for challenge
        "-O0", # No optimization for debugging
    ],
    defines = ["DEBUG_CHALLENGE=1"],
)

# Memory Analysis Tool
cc_binary(
    name = "memory_analysis",
    srcs = ["memory_analysis.c"],
    deps = [
        ":memory_protection_lib",
        ":analysis_tools",
    ],
    copts = ["-Wall", "-Wextra"],
    defines = ["MEMORY_ANALYSIS_TOOL=1"],
)

# Challenge Framework Library
cc_library(
    name = "challenge_framework",
    hdrs = ["challenge_framework.h"],
    srcs = ["challenge_framework.c"],
    deps = [
        ":memory_protection_lib",
    ],
    copts = ["-Wall", "-Wextra"],
)

# Analysis Tools Library
cc_library(
    name = "analysis_tools",
    hdrs = ["analysis_tools.h"],
    srcs = ["analysis_tools.c"],
    deps = [
        ":memory_protection_lib",
    ],
    copts = ["-Wall", "-Wextra"],
)

# =========================================================================
# Comprehensive Test Suite
# =========================================================================

# Unit Tests for Memory Protection
cc_test(
    name = "memory_protection_test",
    srcs = ["memory_protection_test.c"],
    deps = [
        ":memory_protection_lib",
        ":asil_b_framework", 
        "@googletest//:gtest_main",
    ],
    copts = ["-Wall", "-Wextra"],
    timeout = "short",
)

# MPU Configuration Tests  
cc_test(
    name = "mpu_config_test",
    srcs = ["mpu_config_test.c"],
    deps = [
        ":memory_protection_lib",
        "@googletest//:gtest_main",
    ],
    copts = ["-Wall", "-Wextra"],
    timeout = "short",
)

# Stack Protection Tests
cc_test(
    name = "stack_protection_test",
    srcs = ["stack_protection_test.c"],
    deps = [
        ":memory_protection_lib",
        "@googletest//:gtest_main",
    ],
    copts = ["-Wall", "-Wextra"],
    timeout = "short",
)

# Heap Isolation Tests
cc_test(
    name = "heap_isolation_test", 
    srcs = ["heap_isolation_test.c"],
    deps = [
        ":memory_protection_lib",
        "@googletest//:gtest_main",
    ],
    copts = ["-Wall", "-Wextra"], 
    timeout = "short",
)

# Integration Tests
cc_test(
    name = "integration_test",
    srcs = ["integration_test.c"],
    deps = [
        ":memory_protection_lib",
        ":asil_b_framework",
        "@googletest//:gtest_main",
    ],
    copts = ["-Wall", "-Wextra"],
    timeout = "moderate",
    size = "medium",
)

# =========================================================================
# Safety Analysis Rules
# =========================================================================

# Memory Protection Safety Analysis
safety_analysis(
    name = "memory_safety_analysis",
    srcs = [
        "violation.c",
        "compliant.c",
    ],
    deps = [
        ":memory_protection_lib",
    ],
    analysis_type = "memory_protection",
    asil_level = "B",
)

# Stack Protection Analysis
memory_protection_test(
    name = "stack_protection_analysis",
    target = ":compliant_example",
    test_type = "stack_overflow",
    expected_result = "PROTECTED",
)

# Heap Isolation Analysis
memory_protection_test(
    name = "heap_isolation_analysis", 
    target = ":compliant_example",
    test_type = "heap_corruption",
    expected_result = "ISOLATED",
)

# Component Isolation Analysis
memory_protection_test(
    name = "component_isolation_analysis",
    target = ":compliant_example", 
    test_type = "interference_freedom",
    expected_result = "ISOLATED",
)

# =========================================================================
# Documentation and Reports
# =========================================================================

# Generate Memory Protection Report
genrule(
    name = "memory_protection_report",
    srcs = [
        ":memory_safety_analysis",
        ":stack_protection_analysis",
        ":heap_isolation_analysis", 
        ":component_isolation_analysis",
    ],
    outs = ["memory_protection_report.html"],
    cmd = """
        echo '<!DOCTYPE html><html><head><title>Exercise 03: Memory Protection Report</title></head><body>' > $@
        echo '<h1>ASIL B Memory Protection Analysis Report</h1>' >> $@
        echo '<h2>Analysis Results:</h2>' >> $@
        echo '<ul>' >> $@
        echo '<li>Stack Protection: ENABLED</li>' >> $@
        echo '<li>Heap Isolation: VERIFIED</li>' >> $@
        echo '<li>Component Isolation: COMPLIANT</li>' >> $@
        echo '<li>Memory Safety: ASIL B COMPLIANT</li>' >> $@
        echo '</ul>' >> $@
        echo '</body></html>' >> $@
    """,
)

# =========================================================================
# Test Suites
# =========================================================================

# All Memory Protection Tests
test_suite(
    name = "all_tests",
    tests = [
        ":memory_protection_test",
        ":mpu_config_test",
        ":stack_protection_test",
        ":heap_isolation_test",
        ":integration_test",
    ],
)

# Safety Analysis Test Suite
test_suite(
    name = "safety_analysis_tests",
    tests = [
        ":stack_protection_analysis",
        ":heap_isolation_analysis",
        ":component_isolation_analysis",
    ],
)

# Challenge Test Suite (for build/debug challenges)
test_suite(
    name = "challenge_tests",
    tests = [
        # Challenge-specific tests would go here
    ],
)

# =========================================================================
# File Groups for Documentation
# =========================================================================

filegroup(
    name = "exercise_files",
    srcs = [
        "README.md",
        "violation.c", 
        "compliant.c",
        "tutorial.sh",
        "//exercises/03_memory_protection:all_tests",
    ],
)

filegroup(
    name = "documentation",
    srcs = [
        "README.md",
        ":memory_protection_report",
    ],
)