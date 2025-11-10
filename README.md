# Automotive Safety Lab

*Learn ISO 26262 Functional Safety Through Hands-On Automotive Software Exercises*

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![ISO 26262](https://img.shields.io/badge/ISO%2026262-2018-orange.svg)](https://www.iso.org/standard/68383.html)

---

## What You'll Learn

Build safety-critical automotive software through **5 progressive exercises** from basic quality practices (ASIL QM) to critical systems (ASIL D). Each exercise uses real automotive scenarios: battery monitoring, engine control, braking systems, power steering, and autonomous emergency braking.

**Total Time:** 20-26 hours | **No prior ISO 26262 experience required**

---

## Prerequisites

### Required Tools
- **Bazel** (6.0+) - [Installation Guide](https://bazel.build/install)
- **GCC** (9+) or **Clang** (10+) - [GCC Download](https://gcc.gnu.org/install/) | [LLVM Download](https://llvm.org/)
- **Git** (2.0+) - [Download Git](https://git-scm.com/downloads)

### Optional Tools
- **VS Code** - [Download](https://code.visualstudio.com/)
- **Python** (3.8+) - [Download](https://www.python.org/downloads/)

**Windows Users:** Install [Git for Windows](https://git-scm.com/download/win) which includes Git Bash for running tutorials.

---

## Quick Start

```bash
# 1. Clone the repository
git clone https://github.com/rclakmal/automotive-safety-lab.git
cd automotive-safety-lab

# 2. Verify prerequisites
bazel --version
gcc --version
git --version

# 3. Build first exercise
bazel build //exercises/01_basic_safety:all

# 4. Run violation example
bazel run //exercises/01_basic_safety:violation_example

# 5. Run compliant example
bazel run //exercises/01_basic_safety:compliant_example

# 6. Start interactive tutorial (requires bash)
bash exercises/01_basic_safety/tutorial.sh
```

---

## Learning Path

### Exercise 01: Basic Safety (ASIL QM)
**Duration:** 2-3 hours  
**Topics:** Defensive programming, error handling, input validation  
**Scenario:** Battery voltage monitoring system  
**Start:** `cd exercises/01_basic_safety && cat README.md`

### Exercise 02: Watchdog Timer (ASIL A)
**Duration:** 3-4 hours  
**Topics:** Timing supervision, safe states, timeout handling  
**Scenario:** Engine control system  
**Start:** `cd exercises/02_watchdog_timer && cat README.md`

### Exercise 03: Memory Protection (ASIL B)
**Duration:** 4-5 hours  
**Topics:** MPU configuration, stack protection, freedom from interference  
**Scenario:** Electronic brake system  
**Start:** `cd exercises/03_memory_protection && cat README.md`

### Exercise 04: Redundancy & Voting (ASIL C)
**Duration:** 5-6 hours  
**Topics:** Dual-channel architecture, 2oo2 voting, cross-checking  
**Scenario:** Electric power steering  
**Start:** `cd exercises/04_redundancy_voting && cat README.md`

### Exercise 05: Critical Systems (ASIL D)
**Duration:** 6-8 hours  
**Topics:** Triple modular redundancy, formal verification, fail-operational design  
**Scenario:** Autonomous emergency braking  
**Start:** `cd exercises/05_critical_systems && cat README.md`

---

## Project Structure

```
automotive-safety-lab/
 exercises/
    01_basic_safety/       # ASIL QM - Basic safety concepts
    02_watchdog_timer/     # ASIL A - Timing supervision
    03_memory_protection/  # ASIL B - Freedom from interference
    04_redundancy_voting/  # ASIL C - Redundancy & voting
    05_critical_systems/   # ASIL D - Critical safety functions
 docs/
    iso26262_guide.md      # ISO 26262 standard overview
 tools/safety/              # Bazel safety analysis rules
 BUILD                      # Main build configuration
 WORKSPACE                  # Workspace configuration
```

Each exercise contains:
- `README.md` - Instructions and learning objectives
- `violation.c` - Code with safety violations (what NOT to do)
- `compliant.c` - Proper implementation (best practices)
- `tutorial.sh` - Interactive guided walkthrough
- `BUILD` - Bazel build configuration

---

## Common Issues

### Command not found: bazel
**Solution:** Install Bazel from [bazel.build/install](https://bazel.build/install)

### Command not found: gcc
**Solution:**
- **Linux:** `sudo apt install build-essential`
- **macOS:** `xcode-select --install`
- **Windows:** Install [MinGW](https://sourceforge.net/projects/mingw-w64/) or [MSVC Build Tools](https://visualstudio.microsoft.com/downloads/)

### Command not found: bash (Windows)
**Solution:** Install [Git for Windows](https://git-scm.com/download/win) which includes Git Bash

### Build fails with \"No such target\"
**Solution:**
```bash
bazel clean --expunge
bazel build //exercises/01_basic_safety:all
```

### Tutorial script won't run
**Solution:**
```bash
# Make executable (Linux/Mac)
chmod +x exercises/01_basic_safety/tutorial.sh

# Run with bash explicitly (Windows)
bash exercises/01_basic_safety/tutorial.sh
```

---

## ISO 26262 Overview

**ISO 26262** is the functional safety standard for automotive electrical/electronic systems.

**Key Concepts:**
- **ASIL Levels:** QM (no risk)  A (low)  B (medium)  C (high)  D (critical)
- **Safety Lifecycle:** Concept  Development  Production  Operation
- **Requirements:** Hardware diagnostic coverage, software metrics, verification methods

**Learn More:** Read `docs/iso26262_guide.md` for detailed standard explanation

---

## Safety Disclaimer

**This is an educational platform.** Code examples are simplified for learning and must not be used in production systems without proper safety assessment, verification, certification, and compliance with applicable standards.

Real automotive safety systems require professional engineering, extensive testing, and formal certification processes.

---

## Contributing

Contributions improving educational value are welcome. Please ensure:
- Code follows automotive safety principles
- Examples are well-documented with clear explanations
- Changes maintain progressive learning structure

---

## License

MIT License - See [LICENSE](LICENSE) for details

---

**Ready to start?** Run `bazel build //exercises/01_basic_safety:all` and begin your safety engineering journey!