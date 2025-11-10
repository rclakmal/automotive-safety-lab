# BUILD file for Exercise 01: Basic Safety Concepts
# ================================================

load("//tools/safety:safety_rules.bzl", "safety_cc_binary", "safety_analysis")

package(default_visibility = ["//visibility:public"])

# Violation example - demonstrates poor practices
safety_cc_binary(
    name = "violation_example",
    srcs = ["violation.c"],
    asil_level = "QM",
    copts = [
        "-Wno-error",  # Allow compilation despite warnings for educational purposes
    ],
)

# Compliant example - demonstrates good practices  
safety_cc_binary(
    name = "compliant_example", 
    srcs = ["compliant.c"],
    asil_level = "QM",
)

# Interactive tutorial runner
sh_binary(
    name = "interactive_tutorial",
    srcs = ["tutorial.sh"],
    data = [
        ":violation_example",
        ":compliant_example",
        "README.md",
        "//docs:iso26262_guide",
    ],
)

# Safety analysis for both examples
safety_analysis(
    name = "safety_check",
    srcs = [
        "violation.c",
        "compliant.c", 
    ],
    asil_level = "QM",
)

# Unit tests for the compliant example
cc_test(
    name = "compliant_test",
    srcs = ["test_compliant.c"],
    deps = [
        "@com_google_googletest//:gtest_main",
    ],
    copts = ["-std=c99"],
)

# Exercise completion tracker
genrule(
    name = "progress_marker",
    outs = ["exercise_01_completed.marker"],
    cmd = "echo 'Exercise 01: Basic Safety - Completed on' > $@ && date >> $@",
)

# All files for this exercise
filegroup(
    name = "all",
    srcs = [
        ":violation_example",
        ":compliant_example", 
        ":interactive_tutorial",
        ":safety_check",
        "README.md",
        "violation.c",
        "compliant.c",
        "tutorial.sh",
    ],
)

# README files for hierarchical documentation
filegroup(
    name = "readme",
    srcs = ["README.md"],
)