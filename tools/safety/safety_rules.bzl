# Safety-critical toolchain configuration for ISO 26262
# ====================================================

def register_safety_toolchains():
    """Register safety-critical compiler toolchains"""
    native.register_toolchains(
        "//tools/safety:gcc_safety_toolchain",
    )

def _safety_cc_binary_impl(ctx):
    """Implementation for safety-critical C binary compilation"""
    # Safety-critical compilation flags
    safety_copts = [
        "-Wall", "-Wextra", "-Werror",           # All warnings as errors
        "-Wpedantic", "-Wconversion",            # Strict standards compliance
        "-Wuninitialized", "-Wunreachable-code", # Uninitialized variable detection
        "-fstack-protector-strong",              # Stack protection
        "-D_FORTIFY_SOURCE=2",                   # Buffer overflow protection
        "-fno-strict-overflow",                  # Prevent optimization-based vulnerabilities
        "-fwrapv",                               # Defined signed integer overflow behavior
        "-O2",                                   # Optimized but predictable
        "-g",                                    # Debug information for safety analysis
    ]
    
    # Linker flags for safety
    safety_linkopts = [
        "-Wl,-z,relro",                          # Read-only relocations
        "-Wl,-z,now",                            # Immediate binding
        "-Wl,--as-needed",                       # Only link necessary libraries
    ]
    
    return struct(
        safety_copts = safety_copts,
        safety_linkopts = safety_linkopts,
    )

safety_cc_binary = rule(
    implementation = _safety_cc_binary_impl,
    attrs = {
        "srcs": attr.label_list(allow_files = [".c", ".cpp"]),
        "hdrs": attr.label_list(allow_files = [".h", ".hpp"]),
        "deps": attr.label_list(),
        "copts": attr.string_list(),
        "linkopts": attr.string_list(),
        "asil_level": attr.string(default = "QM"),
    },
)

safety_cc_library = rule(
    implementation = _safety_cc_binary_impl,
    attrs = {
        "srcs": attr.label_list(allow_files = [".c", ".cpp"]),
        "hdrs": attr.label_list(allow_files = [".h", ".hpp"]), 
        "deps": attr.label_list(),
        "copts": attr.string_list(),
        "asil_level": attr.string(default = "QM"),
    },
)

def _safety_analysis_impl(ctx):
    """Implementation for safety analysis tools integration"""
    analysis_script = ctx.actions.declare_file(ctx.label.name + "_analysis.sh")
    
    ctx.actions.write(
        output = analysis_script,
        content = """#!/bin/bash
# Safety Analysis Script for {target}
# ASIL Level: {asil}

echo "Running safety analysis for {target} (ASIL {asil})"

# Static analysis with safety focus
if command -v cppcheck >/dev/null 2>&1; then
    echo "Running cppcheck static analysis..."
    cppcheck --enable=all --std=c99 --platform=unix32 \\
        --suppress=missingIncludeSystem \\
        --xml --xml-version=2 \\
        {sources} 2> {target}_cppcheck.xml
else
    echo "Warning: cppcheck not found, skipping static analysis"
fi

# MISRA compliance check
if command -v pc-lint >/dev/null 2>&1; then
    echo "Running MISRA C compliance check..."
    pc-lint +v -w3 -misra(2012) {sources} > {target}_misra.txt
else
    echo "Warning: pc-lint not found, skipping MISRA analysis"
fi

# Generate safety report
echo "Generating safety analysis report..."
cat > {target}_safety_report.md << EOF
# Safety Analysis Report: {target}

**ASIL Level**: {asil}
**Analysis Date**: $(date)
**Sources Analyzed**: {sources}

## Static Analysis Results
- cppcheck: See {target}_cppcheck.xml
- MISRA C: See {target}_misra.txt

## Safety Compliance Status
- [ ] Code review completed
- [ ] Unit tests with MC/DC coverage
- [ ] Integration testing completed
- [ ] Safety requirements verified

EOF

echo "Safety analysis completed. Report: {target}_safety_report.md"
        """.format(
            target = ctx.label.name,
            asil = ctx.attr.asil_level,
            sources = " ".join([f.path for f in ctx.files.srcs]),
        ),
        is_executable = True,
    )
    
    return [DefaultInfo(executable = analysis_script)]

safety_analysis = rule(
    implementation = _safety_analysis_impl,
    attrs = {
        "srcs": attr.label_list(allow_files = [".c", ".cpp", ".h", ".hpp"]),
        "asil_level": attr.string(default = "QM"),
    },
    executable = True,
)