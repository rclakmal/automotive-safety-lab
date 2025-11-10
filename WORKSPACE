workspace(name = "automotive_safety_lab")

# Load Bazel rules for C/C++
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Rules for C/C++ compilation
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# Google Test for unit testing
http_archive(
    name = "com_google_googletest",
    urls = ["https://github.com/google/googletest/archive/03597a01ee50f33f9142a624c876c14fda3cc169.zip"],
    strip_prefix = "googletest-03597a01ee50f33f9142a624c876c14fda3cc169",
)

# Bazel Skylib for utility functions
http_archive(
    name = "bazel_skylib",
    sha256 = "66ffd9315665bfaafc96b52278f57c7e2dd09f5ede279ea6d39b2be471e7e3aa",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.4.2/bazel-skylib-1.4.2.tar.gz",
        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.4.2/bazel-skylib-1.4.2.tar.gz",
    ],
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
bazel_skylib_workspace()

# Rules for Python (for safety analysis tools)
http_archive(
    name = "rules_python",
    sha256 = "9d04041ac92a0985e344235f5d946f71ac543f1b1565f2cdbc9a2aaee8adf55b",
    strip_prefix = "rules_python-0.26.0",
    url = "https://github.com/bazelbuild/rules_python/releases/download/0.26.0/rules_python-0.26.0.tar.gz",
)

load("@rules_python//python:repositories.bzl", "py_repositories")
py_repositories()

# Safety-critical compiler configurations
load("//tools/safety:safety_config.bzl", "register_safety_toolchains")
register_safety_toolchains()