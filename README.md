# Automotive Safety Lab

*Interactive ISO 26262 Learning Platform for Safety Engineers*

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](BUILD)
[![ISO 26262](https://img.shields.io/badge/ISO%2026262-2018-orange.svg)](https://www.iso.org/standard/68383.html)

---

## 🎯 Welcome to Your Safety Engineering Journey

This **interactive educational platform** guides you through ISO 26262:2018 functional safety principles using **hands-on exercises** with real automotive software components. Each exercise builds upon the previous one, taking you from basic safety concepts to **ASIL D critical systems**.

---

## 🚀 Quick Start (Choose Your Path)

### 👋 **I'm New Here**
**Perfect!** Start with our comprehensive setup guide:
- 📖 **[GETTING_STARTED.md](./GETTING_STARTED.md)** - Complete beginner's guide (30 min setup)
- ✅ Run: `./scripts/verify_setup.ps1` (Windows) or `./scripts/verify_setup.sh` (Linux/Mac)
- 🎓 Then: [Exercise 01: Basic Safety](./exercises/01_basic_safety/README.md)

### 🏃 **I'm Ready to Code**
**Awesome!** Quick setup (5 minutes):
```bash
# 1. Clone and enter directory
git clone https://github.com/rclakmal/automotive-safety-lab.git && cd automotive-safety-lab

# 2. Verify setup (checks Bazel, compiler, Git)
./scripts/verify_setup.sh  # Linux/Mac
# OR
.\scripts\verify_setup.ps1  # Windows

# 3. Build first exercise (requires C/C++ compiler)
bazel build //exercises/01_basic_safety:all

# 4. Start learning!
bazel run //exercises/01_basic_safety:violation_example
```

**Windows users:** You need MinGW/MSVC and Git Bash. See [GETTING_STARTED.md](./GETTING_STARTED.md) for installation.

### 📚 **I Want to Learn ISO 26262 First**
**Great approach!** Theory before practice:
- � [ISO 26262 Foundation Guide](./docs/iso26262_guide.md) - Standard overview
- 🎯 [Learning Roadmap](#learning-roadmap) - See the complete progression
- 🛠️ [Workflow Example](./docs/WORKFLOW_EXAMPLE.md) - See how an exercise works

### 🔧 **I Need Help**
**We've got you covered:**
- ❓ [Troubleshooting Guide](./docs/TROUBLESHOOTING.md) - Common issues & solutions
- 📊 Run: `./scripts/progress.sh` - Check your progress
- 💬 [GitHub Issues](https://github.com/rclakmal/automotive-safety-lab/issues) - Ask questions

---

## 📊 Your Learning Path {#learning-roadmap}

**Complete progression**: ASIL QM → ASIL A → ASIL B → ASIL C → ASIL D

```
┌─────────────────────────────────────────────────────────┐
│  Exercise 01  →  Exercise 02  →  Exercise 03            │
│  ASIL QM          ASIL A          ASIL B                │
│  Basic Safety    Watchdog        Memory                 │
│  (2-3 hrs)       (3-4 hrs)       (4-5 hrs)             │
└─────────────────────────────────────────────────────────┘
         ↓                 ↓
┌─────────────────────────────────────────────────────────┐
│       Exercise 04         →        Exercise 05          │
│       ASIL C                      ASIL D                │
│       Redundancy & Voting         Critical Systems      │
│       (5-6 hrs)                   (6-8 hrs)            │
└─────────────────────────────────────────────────────────┘

Total: ~20-26 hours to master automotive functional safety!
```

**Check your progress:** `./scripts/progress.sh` (or `.ps1` on Windows)

## 🏗️ Project Structure

```
automotive-safety-lab/
├── .github/                    # GitHub configuration and Copilot instructions
├── exercises/                  # Progressive ISO 26262 exercises
│   ├── 01_basic_safety/        # ASIL QM - Basic safety concepts
│   ├── 02_watchdog_timer/      # ASIL A - Timing supervision
│   ├── 03_memory_protection/   # ASIL B - Freedom from interference
│   ├── 04_redundancy_voting/   # ASIL C - Redundancy and voting systems
│   └── 05_critical_systems/    # ASIL D - Critical safety functions
├── docs/                       # Educational materials and references
│   ├── iso26262_guide.md       # ISO 26262 standard overview
│   ├── TROUBLESHOOTING.md      # Common issues and solutions
│   └── WORKFLOW_EXAMPLE.md     # Complete exercise walkthrough
├── scripts/                    # Helper scripts for setup and progress
│   ├── verify_setup.sh/.ps1    # Environment verification
│   ├── quick_test.sh/.ps1      # Quick build test
│   └── progress.sh/.ps1        # Learning progress tracker
├── tests/                      # Comprehensive integration test suite
│   └── integration/            # Cross-exercise validation tests
├── tools/                      # Safety analysis and development tools
│   └── safety/                 # Bazel safety analysis rules
├── BUILD                       # Main Bazel build configuration
├── WORKSPACE                   # Bazel workspace configuration
├── GETTING_STARTED.md          # Beginner's setup guide (START HERE!)
└── README.md                   # This file - project overview
```

## 🎓 Learning Objectives

### ISO 26262 Fundamentals
- Understanding functional safety concepts through hands-on exercises
- ASIL classification from QM through D with progressive complexity
- Safety lifecycle processes through practical implementation
- Real-world automotive safety engineering practices

### Automotive Software Development
- Safety-critical programming patterns with violation/compliant examples
- Memory protection and interference freedom (ASIL B)
- Redundancy and voting mechanisms (ASIL C) 
- Critical systems with formal verification (ASIL D)

### Interactive Learning Experience
- Progressive skill building from basic to master level
- Real automotive scenarios (battery, brakes, steering, AEB)
- Hands-on debugging and implementation challenges
- Professional certification preparation

## 📚 Educational Progression

The Automotive Safety Lab provides a complete learning journey through all automotive safety integrity levels:

### **ASIL QM (Quality Management)** - Foundation
- Basic safety concepts and defensive programming
- Error handling and validation patterns
- Battery monitoring system implementation

### **ASIL A (Low Risk)** - Timing Safety
- Watchdog timer systems and timing supervision  
- Safe state transitions and timeout handling
- Engine control system scenario

### **ASIL B (Medium Risk)** - Memory Protection
- Memory Protection Unit (MPU) configuration
- Stack protection and heap isolation
- Freedom from interference mechanisms
- Electronic brake system scenario

### **ASIL C (High Risk)** - Redundancy Systems
- Dual-channel architectures with cross-checking
- 2-out-of-2 voting mechanisms
- Comprehensive diagnostic coverage
- Electric power steering system scenario

### **ASIL D (Highest Risk)** - Critical Systems
- Triple Modular Redundancy (TMR) with diverse programming
- Formal verification and mathematical proofs
- Fail-operational design patterns
- Autonomous emergency braking scenario

## 🗺️ **Detailed Exercise Breakdown**

### **Phase 1: Foundation (ASIL QM)** 📚
**Goal**: Understand basic safety concepts and quality practices

🔗 **[Exercise 01: Basic Safety Concepts](./exercises/01_basic_safety/README.md)**
- Learn fundamental ISO 26262 principles
- Practice defensive programming
- Compare violation vs. compliant code
- **Interactive**: Fix battery monitoring system
- **Time**: 2-3 hours

### **Phase 2: Timing Safety (ASIL A)** ⏱️
**Goal**: Implement timing supervision and watchdog mechanisms

🔗 **[Exercise 02: Watchdog Timer Systems](./exercises/02_watchdog_timer/README.md)**
- Master watchdog timer implementation
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