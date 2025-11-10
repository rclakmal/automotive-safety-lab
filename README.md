# Automotive Safety Lab

*Interactive ISO 26262 Learning Platform for Safety Engineers*

## 🎯 Welcome to Your Safety Engineering Journey

This **interactive educational platform** guides you through ISO 26262:2018 functional safety principles using **hands-on exercises** with real automotive software components. Each exercise builds upon the previous one, taking you from basic safety concepts to **ASIL D critical systems**.

### 🚀 **Quick Start - Your Learning Path**

**New to ISO 26262?** Start here: [📚 ISO 26262 Foundation Guide](./docs/iso26262_guide.md)

**Ready to code?** Jump to: [🔧 Exercise 01: Basic Safety Concepts](./exercises/01_basic_safety/README.md)

**Want the big picture?** See: [🗺️ Complete Learning Roadmap](#learning-roadmap)

## 🏗️ Project Structure

```
automotive-safety-lab/
├── .github/                    # GitHub configuration and Copilot instructions
├── src/                        # Core automotive software components
│   ├── watchdog/              # Watchdog timer implementations
│   ├── diagnostics/           # Diagnostic and monitoring systems
│   ├── communication/         # CAN/Ethernet communication stacks
│   └── state_machines/        # Safety state machine implementations
├── exercises/                  # Progressive ISO 26262 exercises
│   ├── 01_basic_safety/       # ASIL QM - Basic safety concepts
│   ├── 02_watchdog_timer/     # ASIL A - Timing supervision
│   ├── 03_memory_protection/  # ASIL B - Freedom from interference
│   ├── 04_redundancy/         # ASIL C - Redundant systems
│   └── 05_autonomous_systems/ # ASIL D - Critical safety functions
├── components/                # Reusable automotive components
│   ├── sensors/               # Sensor interfaces and validation
│   ├── actuators/             # Actuator control and feedback
│   ├── hal/                   # Hardware abstraction layer
│   └── safety_monitors/       # Independent safety monitoring
├── docs/                      # Educational materials and references
│   ├── iso26262_guide.md     # ISO 26262 standard overview
│   ├── asil_classification.md # ASIL rating methodology
│   ├── safety_lifecycle.md   # Safety development lifecycle
│   └── verification_methods.md # V&V techniques and processes
├── tools/                     # Safety analysis and development tools
│   ├── hara_calculator/       # Hazard Analysis and Risk Assessment
│   ├── fmea_generator/        # Failure Mode and Effects Analysis
│   └── coverage_analyzer/     # Test coverage analysis tools
└── examples/                  # Complete example implementations
    ├── engine_control/        # Engine control module (ECM)
    ├── brake_system/          # Electronic brake system
    └── steering_assist/       # Power steering assistance
```

## 🎓 Learning Objectives

### ISO 26262 Fundamentals
- Understanding functional safety concepts
- ASIL classification and decomposition
- Safety lifecycle processes (V-model)
- Risk assessment and hazard analysis

### Automotive Software Development
- Safety-critical programming patterns
- MISRA C/C++ compliance
- Freedom from interference
- Verification and validation techniques

### Practical Safety Engineering
- Real-world automotive scenarios
- Component-level safety implementation
- System integration challenges
- Certification and assessment processes

## 📚 Educational Progression

### Level 1: Foundation (ASIL QM)
**Target**: Understanding basic safety concepts
- Introduction to ISO 26262
- Safety vs. security concepts
- Basic automotive architectures
- Quality management approaches

### Level 2: Basic Safety (ASIL A)
**Target**: Simple safety mechanisms
- Watchdog timer implementation
- Basic diagnostic functions
- Error detection and reporting
- Safe state definitions

### Level 3: Intermediate Safety (ASIL B)
**Target**: Memory protection and interference
- Memory protection units (MPU)
- Inter-process communication safety
- Resource partitioning
- Timing supervision

### Level 4: Advanced Safety (ASIL C)
**Target**: Redundancy and diversity
- Dual-channel architectures
- Cross-checking mechanisms
- Diagnostic coverage analysis
- Systematic failure prevention

### Level 5: Critical Safety (ASIL D)
**Target**: Highest integrity systems
- Triple modular redundancy (TMR)
- Diverse programming approaches
- Formal verification methods
- Complete V&V documentation

## �️ **Interactive Learning Roadmap** {#learning-roadmap}

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

### **Phase 4: Redundancy (ASIL C)** 🔄
**Goal**: Build fault-tolerant systems with redundancy

🔗 **[Exercise 04: Dual-Channel Systems](./exercises/04_redundancy/README.md)**
- Design redundant architectures
- Implement cross-checking mechanisms
- Practice diagnostic coverage analysis
- **Interactive**: Build voting systems
- **Time**: 5-6 hours

### **Phase 5: Critical Systems (ASIL D)** 🚨
**Goal**: Master highest safety integrity systems

🔗 **[Exercise 05: Autonomous Emergency Braking](./exercises/05_autonomous_systems/README.md)**
- Implement ASIL D safety mechanisms
- Master formal verification techniques
- Practice safety case development
- **Interactive**: Build life-critical system
- **Time**: 8-10 hours

## 🔧 **Quick Setup Guide**

### **Prerequisites**
- **Bazel Build System**: [Install Bazel](https://bazel.build/install)
- **C/C++ Compiler**: GCC 9+ or Clang 10+
- **Development Environment**: VS Code (recommended)
- **Optional**: Static analysis tools (cppcheck, PC-lint)

### **30-Second Setup**
```bash
# 1. Clone the repository
git clone <repository-url>
cd ISO26262

# 2. Install Bazel (if not already installed)
# Follow: https://bazel.build/install

# 3. Build everything
bazel build //...

# 4. Start first exercise
bazel run //exercises/01_basic_safety:interactive_tutorial

# 5. Follow the prompts in your terminal!
```

### **Verify Your Setup**
```bash
# Test build system
bazel test //exercises/01_basic_safety:all

# Run safety analysis
bazel run //tools/safety:safety_check -- //exercises/01_basic_safety

# Generate learning progress report
bazel run //tools:progress_tracker
```

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