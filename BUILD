# Main BUILD file for ISO 26262 Safety Laboratory
# ===============================================

load("//tools/safety:safety_rules.bzl", "safety_cc_binary", "safety_cc_library", "safety_analysis")

# Package for the entire safety laboratory
package(default_visibility = ["//visibility:public"])

# Safety-critical compiler configuration
cc_toolchain_suite(
    name = "safety_toolchain",
    toolchains = {
        "k8|gcc": "//tools/safety:gcc_safety_toolchain",
        "k8": "//tools/safety:gcc_safety_toolchain",
    },
)

# Main documentation and overview
filegroup(
    name = "documentation",
    srcs = [
        "README.md",
        "//docs:all_docs",
        "//exercises:all_readmes",
    ],
)

# All safety components
filegroup(
    name = "safety_components",
    srcs = [
        "//src/watchdog:all",
        "//src/diagnostics:all",
        "//src/communication:all",
        "//components:all",
    ],
)

# All exercises for interactive learning
filegroup(
    name = "all_exercises",
    srcs = [
        "//exercises/01_basic_safety:all",
        "//exercises/02_watchdog_timer:all",
        "//exercises/03_memory_protection:all",
        "//exercises/04_redundancy_voting:all",
        "//exercises/05_critical_systems:all",
    ],
)

# Safety analysis and reporting tools
filegroup(
    name = "safety_tools",
    srcs = [
        "//tools/hara_calculator:all",
        "//tools/fmea_generator:all",
        "//tools/coverage_analyzer:all",
    ],
)

# Integration test suite
filegroup(
    name = "integration_tests",
    srcs = [
        "//tests/integration:all_integration_tests",
        "//tests/integration:cross_exercise_tests",
    ],
)

# Complete safety laboratory target
filegroup(
    name = "automotive_safety_lab",
    srcs = [
        ":documentation",
        ":safety_components", 
        ":all_exercises",
        ":safety_tools",
        ":integration_tests",
    ],
)