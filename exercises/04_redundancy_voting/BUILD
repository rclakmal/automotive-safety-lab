# Exercise 04: Redundancy and Voting Systems (ASIL C)
# ===================================================
# Electric Power Steering with dual-channel redundancy and voting

load("//tools/safety:safety_rules.bzl", "safety_cc_binary", "safety_cc_library", "safety_analysis")

package(default_visibility = ["//visibility:public"])

# Violation example - Missing redundancy and voting
cc_binary(
    name = "violation_example",
    srcs = ["violation.c"],
    copts = [
        "-std=c99",
        "-Wall",
        "-Wextra",
    ],
)

# Compliant example - Proper ASIL C redundancy with voting
cc_binary(
    name = "compliant_example",
    srcs = ["compliant.c"],
    copts = [
        "-std=c99",
        "-Wall",
        "-Wextra",
        "-DASIL_C=1",
        "-DREDUNDANT_CHANNELS=1",
        "-DVOTING_ENABLED=1",
    ],
)

# Safety analysis for Exercise 04
safety_analysis(
    name = "redundancy_analysis",
    srcs = [
        "compliant.c",
        "violation.c",
    ],
    asil_level = "C",
)

# Interactive tutorial
sh_binary(
    name = "interactive_tutorial",
    srcs = ["tutorial.sh"],
    data = [
        ":compliant_example",
        ":violation_example",
        "README.md",
    ],
)

# Documentation
filegroup(
    name = "docs",
    srcs = ["README.md"],
)

# All exercise components
filegroup(
    name = "all",
    srcs = [
        ":compliant_example",
        ":violation_example",
        ":docs",
    ],
)
