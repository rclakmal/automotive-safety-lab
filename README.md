# Automotive Safety Lab# Automotive Safety Lab# Automotive Safety Lab



*Learn ISO 26262 Functional Safety Through Hands-On Automotive Software Exercises*



[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)*Learn ISO 26262 Functional Safety Through Hands-On Automotive Software Exercises**Learn ISO 26262 Functional Safety Through Hands-On Automotive Software Exercises*

[![ISO 26262](https://img.shields.io/badge/ISO%2026262-2018-orange.svg)](https://www.iso.org/standard/68383.html)



---

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

## 🎯 What You'll Learn

[![ISO 26262](https://img.shields.io/badge/ISO%2026262-2018-orange.svg)](https://www.iso.org/standard/68383.html)[![ISO 26262](https://img.shields.io/badge/ISO%2026262-2018-orange.svg)](https://www.iso.org/standard/68383.html)

Build safety-critical automotive software through **5 progressive exercises** from basic quality practices (ASIL QM) to critical systems (ASIL D). Each exercise uses real automotive scenarios: battery monitoring, engine control, braking systems, power steering, and autonomous emergency braking.



**Total Time:** 20-26 hours | **No prior ISO 26262 experience required**

------

---



## 📋 Prerequisites

## What You'll Learn---

### Required Tools

- **Bazel** (6.0+) → [Installation Guide](https://bazel.build/install)

- **GCC** (9+) or **Clang** (10+) → [GCC](https://gcc.gnu.org/install/) | [LLVM](https://llvm.org/)

- **Git** (2.0+) → [Download Git](https://git-scm.com/downloads)Build safety-critical automotive software through **5 progressive exercises** from basic quality practices (ASIL QM) to critical systems (ASIL D). Each exercise uses real automotive scenarios: battery monitoring, engine control, braking systems, power steering, and autonomous emergency braking.## What You'll Learn



### Optional Tools

- **VS Code** → [Download](https://code.visualstudio.com/)

- **Python** (3.8+) → [Download](https://www.python.org/downloads/)**Total Time:** 20-26 hours | **No prior ISO 26262 experience required**## 🎯 Welcome to Your Safety Engineering Journey



> **💡 Windows Users:** Install [Git for Windows](https://git-scm.com/download/win) which includes Git Bash for running tutorials.



------Build safety-critical automotive software through **5 progressive exercises** from basic quality practices (ASIL QM) to critical systems (ASIL D). Each exercise uses real automotive scenarios: battery monitoring, engine control, braking systems, power steering, and autonomous emergency braking.



## 🚀 Quick Start



```bash## PrerequisitesThis **interactive educational platform** guides you through ISO 26262:2018 functional safety principles using **hands-on exercises** with real automotive software components. Each exercise builds upon the previous one, taking you from basic safety concepts to **ASIL D critical systems**.

# 1. Clone the repository

git clone https://github.com/rclakmal/automotive-safety-lab.git

cd automotive-safety-lab

### Required**Total Time:** 20-26 hours | **No prior ISO 26262 experience required**

# 2. Verify prerequisites

bazel --version  # Should show 6.0+- **Bazel** (6.0+): [bazel.build/install](https://bazel.build/install)

gcc --version    # Should show 9.0+

git --version    # Should show 2.0+- **GCC** (9+) or **Clang** (10+): [gcc.gnu.org](https://gcc.gnu.org/install/) | [llvm.org](https://llvm.org/)---



# 3. Build first exercise- **Git** (2.0+): [git-scm.com](https://git-scm.com/downloads)

bazel build //exercises/01_basic_safety:all

---

# 4. Run violation example

bazel run //exercises/01_basic_safety:violation_example### Optional



# 5. Run compliant example  - **VS Code**: [code.visualstudio.com](https://code.visualstudio.com/)## 🚀 Quick Start (Choose Your Path)

bazel run //exercises/01_basic_safety:compliant_example

- **Python** (3.8+): [python.org](https://www.python.org/downloads/)

# 6. Start interactive tutorial (requires bash)

bash exercises/01_basic_safety/tutorial.sh## Prerequisites

```

**Windows Users:** Install [Git for Windows](https://git-scm.com/download/win) (includes Git Bash for tutorials)

---

### 👋 **I'm New Here**

## 📚 Learning Path

---

### Exercise 01: Basic Safety (ASIL QM) • 2-3 hours

**Topics:** Defensive programming, error handling, input validation  ### Required**Perfect!** Start with our comprehensive setup guide:

**Scenario:** Battery voltage monitoring system  

**Start:** `cd exercises/01_basic_safety && cat README.md`## Quick Start



### Exercise 02: Watchdog Timer (ASIL A) • 3-4 hours- **Bazel** (6.0+): [bazel.build/install](https://bazel.build/install)- 📖 **[GETTING_STARTED.md](./GETTING_STARTED.md)** - Complete beginner's guide (30 min setup)

**Topics:** Timing supervision, safe states, timeout handling  

**Scenario:** Engine control system  ```bash

**Start:** `cd exercises/02_watchdog_timer && cat README.md`

# 1. Clone- **GCC** (9+) or **Clang** (10+): [gcc.gnu.org](https://gcc.gnu.org/install/) | [llvm.org](https://llvm.org/)- ✅ Run: `./scripts/verify_setup.ps1` (Windows) or `./scripts/verify_setup.sh` (Linux/Mac)

### Exercise 03: Memory Protection (ASIL B) • 4-5 hours

**Topics:** MPU configuration, stack protection, freedom from interference  git clone https://github.com/rclakmal/automotive-safety-lab.git

**Scenario:** Electronic brake system  

**Start:** `cd exercises/03_memory_protection && cat README.md`cd automotive-safety-lab- **Git** (2.0+): [git-scm.com](https://git-scm.com/downloads)- 🎓 Then: [Exercise 01: Basic Safety](./exercises/01_basic_safety/README.md)



### Exercise 04: Redundancy & Voting (ASIL C) • 5-6 hours

**Topics:** Dual-channel architecture, 2oo2 voting, cross-checking  

**Scenario:** Electric power steering  # 2. Verify setup

**Start:** `cd exercises/04_redundancy_voting && cat README.md`

bazel --version  # Should show 6.0+

### Exercise 05: Critical Systems (ASIL D) • 6-8 hours

**Topics:** Triple modular redundancy, formal verification, fail-operational design  gcc --version    # Should show 9.0+### Optional### 🏃 **I'm Ready to Code**

**Scenario:** Autonomous emergency braking  

**Start:** `cd exercises/05_critical_systems && cat README.md`git --version    # Should show 2.0+



---- **VS Code**: [code.visualstudio.com](https://code.visualstudio.com/)**Awesome!** Quick setup (5 minutes):



## 📁 Project Structure# 3. Build first exercise



```bazel build //exercises/01_basic_safety:all- **Python** (3.8+): [python.org](https://www.python.org/downloads/)```bash

automotive-safety-lab/

├── exercises/

│   ├── 01_basic_safety/       # ASIL QM - Basic safety concepts

│   ├── 02_watchdog_timer/     # ASIL A - Timing supervision# 4. Run violation example# 1. Clone and enter directory

│   ├── 03_memory_protection/  # ASIL B - Freedom from interference

│   ├── 04_redundancy_voting/  # ASIL C - Redundancy & votingbazel run //exercises/01_basic_safety:violation_example

│   └── 05_critical_systems/   # ASIL D - Critical safety functions

├── docs/**Windows Users:** Install [Git for Windows](https://git-scm.com/download/win) (includes Git Bash for tutorials)git clone https://github.com/rclakmal/automotive-safety-lab.git && cd automotive-safety-lab

│   └── iso26262_guide.md      # ISO 26262 standard overview

├── tools/safety/              # Bazel safety analysis rules# 5. Run compliant example  

├── BUILD                      # Main build configuration

└── WORKSPACE                  # Workspace configurationbazel run //exercises/01_basic_safety:compliant_example

```



**Each exercise contains:**

- `README.md` - Instructions and learning objectives# 6. Start interactive tutorial (requires bash)---# 2. Verify setup (checks Bazel, compiler, Git)

- `violation.c` - Code with safety violations (what NOT to do)

- `compliant.c` - Proper implementation (best practices)bash exercises/01_basic_safety/tutorial.sh

- `tutorial.sh` - Interactive guided walkthrough

- `BUILD` - Bazel build configuration```./scripts/verify_setup.sh  # Linux/Mac



---



## 🔧 Common Issues---## Quick Start# OR



### "Command not found: bazel"

**Solution:** Install Bazel from [bazel.build/install](https://bazel.build/install)

## Learning Path.\scripts\verify_setup.ps1  # Windows

### "Command not found: gcc"

**Solution:**

- **Linux:** `sudo apt install build-essential`

- **macOS:** `xcode-select --install`### Exercise 01: Basic Safety (ASIL QM) - 2-3 hours```bash

- **Windows:** Install [MinGW](https://sourceforge.net/projects/mingw-w64/) or [MSVC Build Tools](https://visualstudio.microsoft.com/downloads/)

**Learn:** Defensive programming, error handling, input validation  

### "Command not found: bash" (Windows)

**Solution:** Install [Git for Windows](https://git-scm.com/download/win) which includes Git Bash**Scenario:** Battery voltage monitoring system  # 1. Clone# 3. Build first exercise (requires C/C++ compiler)



### Build fails with "No such target"**Start:** `cd exercises/01_basic_safety && cat README.md`

**Solution:**

```bashgit clone https://github.com/rclakmal/automotive-safety-lab.gitbazel build //exercises/01_basic_safety:all

# Clean and rebuild

bazel clean --expunge### Exercise 02: Watchdog Timer (ASIL A) - 3-4 hours

bazel build //exercises/01_basic_safety:all

```**Learn:** Timing supervision, safe states, timeout handling  cd automotive-safety-lab



### Tutorial script won't run**Scenario:** Engine control system  

**Solution:**

```bash**Start:** `cd exercises/02_watchdog_timer && cat README.md`# 4. Start learning!

# Make executable (Linux/Mac)

chmod +x exercises/01_basic_safety/tutorial.sh



# Run with bash explicitly (Windows)### Exercise 03: Memory Protection (ASIL B) - 4-5 hours# 2. Verify setupbazel run //exercises/01_basic_safety:violation_example

bash exercises/01_basic_safety/tutorial.sh

```**Learn:** MPU configuration, stack protection, freedom from interference  



---**Scenario:** Electronic brake system  bazel --version  # Should show 6.0+```



## 📖 ISO 26262 Overview**Start:** `cd exercises/03_memory_protection && cat README.md`



**ISO 26262** is the functional safety standard for automotive electrical/electronic systems.gcc --version    # Should show 9.0+



**Key Concepts:**### Exercise 04: Redundancy & Voting (ASIL C) - 5-6 hours

- **ASIL Levels:** QM (no risk) → A (low) → B (medium) → C (high) → D (critical)

- **Safety Lifecycle:** Concept → Development → Production → Operation**Learn:** Dual-channel architecture, 2oo2 voting, cross-checking  git --version    # Should show 2.0+**Windows users:** You need MinGW/MSVC and Git Bash. See [GETTING_STARTED.md](./GETTING_STARTED.md) for installation.

- **Requirements:** Hardware diagnostic coverage, software metrics, verification methods

**Scenario:** Electric power steering  

📘 **Learn More:** Read `docs/iso26262_guide.md` for detailed standard explanation

**Start:** `cd exercises/04_redundancy_voting && cat README.md`

---



## ⚠️ Safety Disclaimer

### Exercise 05: Critical Systems (ASIL D) - 6-8 hours# 3. Build first exercise### 📚 **I Want to Learn ISO 26262 First**

**This is an educational platform.** Code examples are simplified for learning and must not be used in production systems without proper safety assessment, verification, certification, and compliance with applicable standards.

**Learn:** Triple modular redundancy, formal verification, fail-operational design  

Real automotive safety systems require professional engineering, extensive testing, and formal certification processes.

**Scenario:** Autonomous emergency braking  bazel build //exercises/01_basic_safety:all**Great approach!** Theory before practice:

---

**Start:** `cd exercises/05_critical_systems && cat README.md`

## 🤝 Contributing

- � [ISO 26262 Foundation Guide](./docs/iso26262_guide.md) - Standard overview

Contributions improving educational value are welcome. Please ensure:

- Code follows automotive safety principles---

- Examples are well-documented with clear explanations

- Changes maintain progressive learning structure# 4. Run violation example- 🎯 [Learning Roadmap](#learning-roadmap) - See the complete progression



---## Project Structure



## 📄 Licensebazel run //exercises/01_basic_safety:violation_example- 🛠️ [Workflow Example](./docs/WORKFLOW_EXAMPLE.md) - See how an exercise works



MIT License - See [LICENSE](LICENSE) for details```



---automotive-safety-lab/



**✨ Ready to start?** Run `bazel build //exercises/01_basic_safety:all` and begin your safety engineering journey!├── exercises/


│   ├── 01_basic_safety/       # ASIL QM# 5. Run compliant example  ### 🔧 **I Need Help**

│   ├── 02_watchdog_timer/     # ASIL A

│   ├── 03_memory_protection/  # ASIL Bbazel run //exercises/01_basic_safety:compliant_example**We've got you covered:**

│   ├── 04_redundancy_voting/  # ASIL C

│   └── 05_critical_systems/   # ASIL D- ❓ [Troubleshooting Guide](./docs/TROUBLESHOOTING.md) - Common issues & solutions

├── docs/

│   └── iso26262_guide.md      # Standard overview# 6. Start interactive tutorial (requires bash)- 📊 Run: `./scripts/progress.sh` - Check your progress

├── tools/safety/              # Bazel safety rules

├── BUILD                      # Main build configbash exercises/01_basic_safety/tutorial.sh- 💬 [GitHub Issues](https://github.com/rclakmal/automotive-safety-lab/issues) - Ask questions

└── WORKSPACE                  # Workspace config

``````



Each exercise contains:---

- `README.md` - Instructions and learning objectives

- `violation.c` - Code with safety violations (what NOT to do)---

- `compliant.c` - Proper implementation (best practices)

- `tutorial.sh` - Interactive guided walkthrough## 📊 Your Learning Path {#learning-roadmap}

- `BUILD` - Bazel build configuration

## Learning Path

---

**Complete progression**: ASIL QM → ASIL A → ASIL B → ASIL C → ASIL D

## Common Issues

### Exercise 01: Basic Safety (ASIL QM) - 2-3 hours

### "Command not found: bazel"

Install Bazel: https://bazel.build/install**Learn:** Defensive programming, error handling, input validation  ```



### "Command not found: gcc"**Scenario:** Battery voltage monitoring system  ┌─────────────────────────────────────────────────────────┐

- **Linux:** `sudo apt install build-essential`

- **macOS:** `xcode-select --install`**Start:** `cd exercises/01_basic_safety && cat README.md`│  Exercise 01  →  Exercise 02  →  Exercise 03            │

- **Windows:** Install [MinGW](https://sourceforge.net/projects/mingw-w64/) or [MSVC Build Tools](https://visualstudio.microsoft.com/downloads/)

│  ASIL QM          ASIL A          ASIL B                │

### "Command not found: bash" (Windows)

Install [Git for Windows](https://git-scm.com/download/win) which includes Git Bash### Exercise 02: Watchdog Timer (ASIL A) - 3-4 hours│  Basic Safety    Watchdog        Memory                 │



### Build fails with "No such target"**Learn:** Timing supervision, safe states, timeout handling  │  (2-3 hrs)       (3-4 hrs)       (4-5 hrs)             │

```bash

# Clean and rebuild**Scenario:** Engine control system  └─────────────────────────────────────────────────────────┘

bazel clean --expunge

bazel build //exercises/01_basic_safety:all**Start:** `cd exercises/02_watchdog_timer && cat README.md`         ↓                 ↓

```

┌─────────────────────────────────────────────────────────┐

### Tutorial script won't run

```bash### Exercise 03: Memory Protection (ASIL B) - 4-5 hours│       Exercise 04         →        Exercise 05          │

# Make executable (Linux/Mac)

chmod +x exercises/01_basic_safety/tutorial.sh**Learn:** MPU configuration, stack protection, freedom from interference  │       ASIL C                      ASIL D                │



# Run with bash explicitly (Windows)**Scenario:** Electronic brake system  │       Redundancy & Voting         Critical Systems      │

bash exercises/01_basic_safety/tutorial.sh

```**Start:** `cd exercises/03_memory_protection && cat README.md`│       (5-6 hrs)                   (6-8 hrs)            │



---└─────────────────────────────────────────────────────────┘



## ISO 26262 Overview### Exercise 04: Redundancy & Voting (ASIL C) - 5-6 hours



**ISO 26262** is the functional safety standard for automotive electrical/electronic systems. It defines:**Learn:** Dual-channel architecture, 2oo2 voting, cross-checking  Total: ~20-26 hours to master automotive functional safety!

- **ASIL Levels:** QM (no risk) → A (low) → B (medium) → C (high) → D (critical)

- **Safety Lifecycle:** Concept → Development → Production → Operation**Scenario:** Electric power steering  ```

- **Requirements:** Hardware diagnostic coverage, software metrics, verification methods

**Start:** `cd exercises/04_redundancy_voting && cat README.md`

**Learn More:** Read `docs/iso26262_guide.md` for detailed standard explanation

**Check your progress:** `./scripts/progress.sh` (or `.ps1` on Windows)

---

### Exercise 05: Critical Systems (ASIL D) - 6-8 hours

## Safety Disclaimer

**Learn:** Triple modular redundancy, formal verification, fail-operational design  ## 🏗️ Project Structure

⚠️ **This is an educational platform.** Code examples are simplified for learning and must not be used in production systems without proper safety assessment, verification, certification, and compliance with applicable standards.

**Scenario:** Autonomous emergency braking  

Real automotive safety systems require professional engineering, extensive testing, and formal certification processes.

**Start:** `cd exercises/05_critical_systems && cat README.md````

---

automotive-safety-lab/

## Contributing

---├── .github/                    # GitHub configuration and Copilot instructions

Contributions improving educational value are welcome. Please ensure:

- Code follows automotive safety principles├── exercises/                  # Progressive ISO 26262 exercises

- Examples are well-documented with clear explanations

- Changes maintain progressive learning structure## Project Structure│   ├── 01_basic_safety/        # ASIL QM - Basic safety concepts



---│   ├── 02_watchdog_timer/      # ASIL A - Timing supervision



## License```│   ├── 03_memory_protection/   # ASIL B - Freedom from interference



MIT License - See [LICENSE](LICENSE) for detailsautomotive-safety-lab/│   ├── 04_redundancy_voting/   # ASIL C - Redundancy and voting systems



---├── exercises/│   └── 05_critical_systems/    # ASIL D - Critical safety functions



**Ready to start?** Run `bazel build //exercises/01_basic_safety:all` and begin your safety engineering journey!│   ├── 01_basic_safety/       # ASIL QM├── docs/                       # Educational materials and references


│   ├── 02_watchdog_timer/     # ASIL A│   ├── iso26262_guide.md       # ISO 26262 standard overview

│   ├── 03_memory_protection/  # ASIL B│   ├── TROUBLESHOOTING.md      # Common issues and solutions

│   ├── 04_redundancy_voting/  # ASIL C│   └── WORKFLOW_EXAMPLE.md     # Complete exercise walkthrough

│   └── 05_critical_systems/   # ASIL D├── scripts/                    # Helper scripts for setup and progress

├── docs/│   ├── verify_setup.sh/.ps1    # Environment verification

│   └── iso26262_guide.md      # Standard overview│   ├── quick_test.sh/.ps1      # Quick build test

├── tools/safety/              # Bazel safety rules│   └── progress.sh/.ps1        # Learning progress tracker

├── BUILD                      # Main build config├── tests/                      # Comprehensive integration test suite

└── WORKSPACE                  # Workspace config│   └── integration/            # Cross-exercise validation tests

```├── tools/                      # Safety analysis and development tools

│   └── safety/                 # Bazel safety analysis rules

Each exercise contains:├── BUILD                       # Main Bazel build configuration

- `README.md` - Instructions and learning objectives├── WORKSPACE                   # Bazel workspace configuration

- `violation.c` - Code with safety violations (what NOT to do)├── GETTING_STARTED.md          # Beginner's setup guide (START HERE!)

- `compliant.c` - Proper implementation (best practices)└── README.md                   # This file - project overview

- `tutorial.sh` - Interactive guided walkthrough```

- `BUILD` - Bazel build configuration

## 🎓 Learning Objectives

---

### ISO 26262 Fundamentals

## Common Issues- Understanding functional safety concepts through hands-on exercises

- ASIL classification from QM through D with progressive complexity

### "Command not found: bazel"- Safety lifecycle processes through practical implementation

Install Bazel: https://bazel.build/install- Real-world automotive safety engineering practices



### "Command not found: gcc"### Automotive Software Development

- **Linux:** `sudo apt install build-essential`- Safety-critical programming patterns with violation/compliant examples

- **macOS:** `xcode-select --install`- Memory protection and interference freedom (ASIL B)

- **Windows:** Install [MinGW](https://sourceforge.net/projects/mingw-w64/) or [MSVC Build Tools](https://visualstudio.microsoft.com/downloads/)- Redundancy and voting mechanisms (ASIL C) 

- Critical systems with formal verification (ASIL D)

### "Command not found: bash" (Windows)

Install [Git for Windows](https://git-scm.com/download/win) which includes Git Bash### Interactive Learning Experience

- Progressive skill building from basic to master level

### Build fails with "No such target"- Real automotive scenarios (battery, brakes, steering, AEB)

```bash- Hands-on debugging and implementation challenges

# Clean and rebuild- Professional certification preparation

bazel clean --expunge

bazel build //exercises/01_basic_safety:all## 📚 Educational Progression

```

The Automotive Safety Lab provides a complete learning journey through all automotive safety integrity levels:

### Tutorial script won't run

```bash### **ASIL QM (Quality Management)** - Foundation

# Make executable (Linux/Mac)- Basic safety concepts and defensive programming

chmod +x exercises/01_basic_safety/tutorial.sh- Error handling and validation patterns

- Battery monitoring system implementation

# Run with bash explicitly (Windows)

bash exercises/01_basic_safety/tutorial.sh### **ASIL A (Low Risk)** - Timing Safety

```- Watchdog timer systems and timing supervision  

- Safe state transitions and timeout handling

---- Engine control system scenario



## ISO 26262 Overview### **ASIL B (Medium Risk)** - Memory Protection

- Memory Protection Unit (MPU) configuration

**ISO 26262** is the functional safety standard for automotive electrical/electronic systems. It defines:- Stack protection and heap isolation

- **ASIL Levels:** QM (no risk) → A (low) → B (medium) → C (high) → D (critical)- Freedom from interference mechanisms

- **Safety Lifecycle:** Concept → Development → Production → Operation- Electronic brake system scenario

- **Requirements:** Hardware diagnostic coverage, software metrics, verification methods

### **ASIL C (High Risk)** - Redundancy Systems

**Learn More:** Read `docs/iso26262_guide.md` for detailed standard explanation- Dual-channel architectures with cross-checking

- 2-out-of-2 voting mechanisms

---- Comprehensive diagnostic coverage

- Electric power steering system scenario

## Safety Disclaimer

### **ASIL D (Highest Risk)** - Critical Systems

⚠️ **This is an educational platform.** Code examples are simplified for learning and must not be used in production systems without proper safety assessment, verification, certification, and compliance with applicable standards.- Triple Modular Redundancy (TMR) with diverse programming

- Formal verification and mathematical proofs

Real automotive safety systems require professional engineering, extensive testing, and formal certification processes.- Fail-operational design patterns

- Autonomous emergency braking scenario

---

## 🗺️ **Detailed Exercise Breakdown**

## Contributing

### **Phase 1: Foundation (ASIL QM)** 📚

Contributions improving educational value are welcome. Please ensure:**Goal**: Understand basic safety concepts and quality practices

- Code follows automotive safety principles

- Examples are well-documented with clear explanations🔗 **[Exercise 01: Basic Safety Concepts](./exercises/01_basic_safety/README.md)**

- Changes maintain progressive learning structure- Learn fundamental ISO 26262 principles

- Practice defensive programming

---- Compare violation vs. compliant code

- **Interactive**: Fix battery monitoring system

## License- **Time**: 2-3 hours



MIT License - See [LICENSE](LICENSE) for details### **Phase 2: Timing Safety (ASIL A)** ⏱️

**Goal**: Implement timing supervision and watchdog mechanisms

---

🔗 **[Exercise 02: Watchdog Timer Systems](./exercises/02_watchdog_timer/README.md)**

**Ready to start?** Run `bazel build //exercises/01_basic_safety:all` and begin your safety engineering journey!- Master watchdog timer implementation

- Learn timing failure detection
- Practice safe state transitions
- **Interactive**: Debug timing violations
- **Time**: 3-4 hours

### **Phase 3: Memory Safety (ASIL B)** 🛡️
**Goal**: Achieve freedom from interference

🔗 **[Exercise 03: Memory Protection](./exercises/03_memory_protection/README.md)**
- Implement memory protection mechanisms
- Prevent interference between components
- Master stack and heap safety
- **Interactive**: Fix memory corruption bugs
- **Time**: 4-5 hours

### **Phase 4: Redundancy & Voting (ASIL C)** 🔄
**Goal**: Build fault-tolerant systems with dual-channel redundancy

🔗 **[Exercise 04: Redundancy & Voting Systems](./exercises/04_redundancy_voting/README.md)**
- Design dual-channel redundant architectures
- Implement cross-checking and plausibility analysis
- Master 2-out-of-2 voting mechanisms
- Practice comprehensive diagnostic coverage
- **Interactive**: Build electric power steering with voting
- **Time**: 5-6 hours

### **Phase 5: Critical Systems (ASIL D)** 🎖️
**Goal**: Master the highest automotive safety integrity level

🔗 **[Exercise 05: Critical Systems (ASIL D)](./exercises/05_critical_systems/README.md)**
- Implement Triple Modular Redundancy (TMR)
- Master formal verification and mathematical proofs
- Apply diverse programming techniques
- Build fail-operational systems
- **Interactive**: Create autonomous emergency braking system
- **Time**: 6-8 hours

---

## 🔧 **Prerequisites & Setup**

### **Required Tools**
- **Bazel Build System**: [Install Bazel](https://bazel.build/install) (6.0+)
- **C/C++ Compiler**: GCC 9+ or Clang 10+
- **Git**: Version control (2.0+)

> **💡 No Admin Rights?** Check out our [Portable Setup Guide](./docs/PORTABLE_SETUP.md) for installing everything without administrator privileges!

### **Optional Tools** (Recommended)
- **VS Code**: IDE with excellent C/C++ support
- **cppcheck**: Static analysis for C/C++
- **Python 3.8+**: For analysis scripts

### **Automated Setup Verification**

Run our setup verification script:

**Windows (PowerShell):**
```powershell
.\scripts\verify_setup.ps1
```

**Linux/macOS (Bash):**
```bash
chmod +x scripts/verify_setup.sh
./scripts/verify_setup.sh
```

### **Quick Build Test**

Verify your build system:

```bash
# Quick test (Windows)
.\scripts\quick_test.ps1

# Quick test (Linux/Mac)
./scripts/quick_test.sh
```

### **Manual Setup** (If scripts don't work)
```bash
# 1. Clone the repository
git clone https://github.com/rclakmal/automotive-safety-lab.git
cd automotive-safety-lab

# 2. Verify Bazel installation
bazel --version

# 3. Build first exercise
bazel build //exercises/01_basic_safety:all

# 4. Run violation example
bazel run //exercises/01_basic_safety:violation_example

# 5. Run compliant example
bazel run //exercises/01_basic_safety:compliant_example
```

**Need help?** See [GETTING_STARTED.md](./GETTING_STARTED.md) or [TROUBLESHOOTING.md](./docs/TROUBLESHOOTING.md)

---

## 🧪 Exercise Format

Each exercise follows a consistent structure:

### Exercise Components
- **README.md**: Learning objectives and instructions
- **violation.c**: Code with intentional ISO 26262 violations
- **compliant.c**: Proper implementation following standards
- **analysis.md**: Detailed explanation of violations and fixes
- **tests/**: Unit tests and verification cases

### Safety Analysis Framework
- **Hazard Identification**: What can go wrong?
- **Risk Assessment**: How severe and likely?
- **Safety Requirements**: What must be implemented?
- **Verification**: How do we prove it works?

## 🛡️ Safety Violation Categories

### Systematic Failures
- **Design Errors**: Algorithmic mistakes
- **Implementation Bugs**: Coding violations
- **Integration Issues**: Component interaction failures
- **Specification Errors**: Incomplete requirements

### Random Hardware Failures
- **Sensor Malfunctions**: Invalid readings
- **Actuator Failures**: Stuck or unresponsive
- **Memory Corruption**: Bit flips and errors
- **Communication Faults**: Lost or corrupted messages

### Common Cause Failures
- **Environmental**: Temperature, vibration, EMI
- **Software**: Shared libraries, OS failures
- **Manufacturing**: Process variations
- **Maintenance**: Service-induced faults

## 📊 Assessment and Certification

### Knowledge Verification
- **Quizzes**: Embedded in each exercise
- **Practical Assignments**: Hands-on implementations
- **Case Studies**: Real automotive failure analysis
- **Capstone Project**: Complete safety-critical system

### Industry Alignment
- **ASPICE**: Automotive SPICE process model
- **MISRA**: Coding standards compliance
- **AUTOSAR**: Architecture standardization
- **Tool Qualification**: Safety tool validation

## 🔗 References and Standards

### Primary Standards
- **ISO 26262:2018**: Road vehicles — Functional safety
- **IEC 61508**: Functional safety of electrical systems
- **ISO/TS 16949**: Quality management for automotive
- **ASPICE**: Automotive Software Process Improvement

### Supporting Standards
- **MISRA C:2012**: Guidelines for the use of C
- **MISRA C++:2008**: Guidelines for the use of C++
- **AUTOSAR**: Automotive Open System Architecture
- **SAE J3061**: Cybersecurity guidebook

## 🤝 Contributing

This is an educational platform designed for learning. Contributors should:
- Follow automotive coding standards
- Provide clear educational value
- Include proper safety analysis
- Document all assumptions and limitations

## ⚠️ Safety Disclaimer

**IMPORTANT**: This platform is for educational purposes only. Code examples are simplified for learning and must not be used in production automotive systems without proper:
- Safety assessment and analysis
- Verification and validation
- Certification by qualified personnel
- Compliance with applicable standards

Real automotive systems require professional safety engineering, extensive testing, and certification processes that extend far beyond this educational content.

---

*Developed for automotive safety education in compliance with ISO 26262 principles*