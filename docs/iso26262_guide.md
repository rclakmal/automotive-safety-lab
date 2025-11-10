# ISO 26262:2018 Standard Overview
*Functional Safety for Road Vehicles - Educational Guide for Safety Engineers*

## 📋 Table of Contents
1. [Introduction to ISO 26262](#introduction)
2. [Standard Structure](#structure)  
3. [Key Concepts](#concepts)
4. [ASIL Classification](#asil)
5. [Safety Lifecycle](#lifecycle)
6. [Practical Application](#application)

## 🎯 Introduction to ISO 26262 {#introduction}

ISO 26262 is the **international standard for functional safety** of electrical and electronic systems in production automobiles. Published in 2011 and updated in 2018, it provides a framework for developing safety-critical automotive systems.

### What is Functional Safety?
**Functional safety** is the part of overall safety that depends on a system operating correctly in response to its inputs, including the safe management of likely operator errors, hardware failures, and environmental changes.

### Why ISO 26262?
- **Risk-based approach**: Systematic identification and mitigation of hazards
- **Automotive-specific**: Tailored to road vehicle operational environments
- **Lifecycle coverage**: From concept through production to decommissioning
- **Industry harmonization**: Common framework across automotive suppliers

## 📚 Standard Structure {#structure}

ISO 26262:2018 consists of **12 parts**:

### Part 1: Vocabulary
- Definitions and terminology
- Conceptual foundation
- Relationship to other standards

### Part 2: Management of Functional Safety
- Organizational responsibilities
- Safety culture and competence
- Safety lifecycle planning

### Part 3: Concept Phase
- **Item definition** and operational situations
- **Hazard analysis and risk assessment (HARA)**
- **Safety goals** and ASIL determination

### Part 4: Product Development at System Level
- System architecture and design
- Safety requirements specification
- Integration and testing

### Part 5: Product Development at Hardware Level
- Hardware development process
- Safety mechanisms for hardware
- Hardware metrics and evaluation

### Part 6: Product Development at Software Level
- **Software development process**
- **Software safety requirements**
- **Software architectural design**
- Implementation and testing

### Part 7: Production, Operation, Service, Decommissioning
- Production quality assurance
- Field monitoring and response
- Maintenance and modification

### Part 8: Supporting Processes
- **Specification and management of safety requirements**
- **Configuration management**
- **Change management**
- **Verification** and **validation**

### Part 9: Automotive Safety Integrity Level (ASIL)-oriented and Safety-oriented Analyses
- **Dependent failure analysis (DFA)**
- **Requirements for software tools**
- **Qualification of software tools**

### Part 10: Guidelines on ISO 26262
- Application guidance
- Examples and interpretations
- Practical implementation tips

### Part 11: Guidelines on Application of ISO 26262 to Semiconductors
- Semiconductor-specific guidance
- Safety element out of context (SEooC)
- Hardware development considerations

### Part 12: Adaptation of ISO 26262 for Motorcycles
- Motorcycle-specific adaptations
- Operational situation differences
- Modified ASIL determination

## 🔑 Key Concepts {#concepts}

### Hazard
A potential source of harm caused by malfunctioning behavior of the item.

**Example**: Unintended acceleration of a vehicle could lead to collision.

### Risk
Combination of the probability of occurrence of harm and the severity of that harm.

### Safety Goal
Top-level safety requirement that specifies the safety intent for an item.

**Example**: "The vehicle shall not accelerate unintentionally."

### Item
System or array of systems, implemented at the vehicle level, to which ISO 26262 is applied.

**Examples**: 
- Electronic stability control system
- Anti-lock braking system  
- Lane keeping assistance system

### Element
System, hardware, or software component that is part of an item.

### Safety Mechanism
Technical solution implemented to detect and control or avoid failures and/or to control or avoid their effects.

### Safe State
Operating mode of an item without an unreasonable level of risk.

**Examples**:
- Engine shutdown for engine control systems
- Controlled stop for automated driving systems
- Manual override for assistance systems

## 📊 ASIL Classification {#asil}

**Automotive Safety Integrity Level (ASIL)** represents the risk level associated with a hazardous event. It determines the rigor of safety measures required.

### ASIL Determination Parameters

#### Severity (S)
- **S1**: Light to moderate injuries
- **S2**: Severe to life-threatening injuries (survival probable)  
- **S3**: Life-threatening to fatal injuries (survival uncertain)

#### Exposure (E)  
- **E1**: Very low probability (< 10% of operating time)
- **E2**: Low probability (10% to 33% of operating time)
- **E3**: Medium probability (33% to 67% of operating time)  
- **E4**: High probability (> 67% of operating time)

#### Controllability (C)
- **C1**: Controllable in general (> 99% of drivers can avoid harm)
- **C2**: Simply controllable (> 90% of drivers can avoid harm)
- **C3**: Normally controllable (> 90% of average drivers can avoid harm)

### ASIL Classification Matrix

| S | E | C1 | C2 | C3 |
|---|---|----|----|----| 
| S1 | E1 | QM | QM | QM |
| S1 | E2 | QM | QM | QM |
| S1 | E3 | QM | QM | A |
| S1 | E4 | QM | A | B |
| S2 | E1 | QM | QM | QM |
| S2 | E2 | QM | QM | A |
| S2 | E3 | QM | A | B |
| S2 | E4 | A | B | C |
| S3 | E1 | QM | QM | A |
| S3 | E2 | QM | A | B |
| S3 | E3 | A | B | C |
| S3 | E4 | B | C | D |

### ASIL Levels

#### QM (Quality Managed)
- No safety requirements according to ISO 26262
- Managed by quality processes only
- **Examples**: Entertainment systems, comfort features

#### ASIL A (Lowest Safety Level)
- Basic safety mechanisms required
- Simple fault detection and response
- **Examples**: Battery monitoring, basic diagnostics

#### ASIL B
- Enhanced safety mechanisms
- Freedom from interference requirements  
- **Examples**: Airbag sensors, power steering assistance

#### ASIL C
- Redundancy and diversity measures
- Comprehensive diagnostic coverage
- **Examples**: Electronic stability control, adaptive cruise control

#### ASIL D (Highest Safety Level)
- Highest safety measures required
- Fault tolerance and graceful degradation
- **Examples**: Automated emergency braking, autonomous steering

## 🔄 Safety Lifecycle {#lifecycle}

The ISO 26262 safety lifecycle follows a **V-model approach**:

### Left Side (Development)
1. **Management of Functional Safety** (Ongoing)
2. **Concept Phase**
   - Item definition
   - Hazard analysis and risk assessment  
   - Safety goals definition
3. **System Development**
   - Technical safety requirements
   - System architectural design
   - Safety validation planning
4. **Hardware/Software Development**
   - Hardware/software safety requirements
   - Architectural design
   - Implementation

### Right Side (Verification & Validation)
5. **Hardware/Software Integration and Testing**
   - Unit testing
   - Integration testing  
   - Safety requirement verification
6. **System Integration and Testing**
   - System integration testing
   - Safety validation
   - Functional safety assessment
7. **Vehicle Integration and Testing**
   - Vehicle-level integration
   - Final safety validation
   - Production release

### Supporting Processes (Throughout)
- Configuration management
- Change management  
- Verification activities
- Documentation
- Quality assurance

## 🛠️ Practical Application {#application}

### For Safety Engineers

#### 1. Hazard Analysis and Risk Assessment (HARA)
**Process**:
1. Define the item and its operational situations
2. Identify potential hazards systematically  
3. Assess severity, exposure, and controllability
4. Determine ASIL ratings
5. Define safety goals

**Tools**:
- Hazard checklists
- FMEA (Failure Mode and Effects Analysis)
- FTA (Fault Tree Analysis)  
- STPA (Systems-Theoretic Process Analysis)

#### 2. Safety Requirements Engineering
**Activities**:
- Derive functional safety requirements from safety goals
- Allocate requirements to system elements
- Define verification and validation criteria
- Ensure requirements traceability

#### 3. Safety Architecture Design
**Considerations**:
- Freedom from interference
- Fault detection and response
- Safe state management
- Redundancy and diversity
- Diagnostic coverage

#### 4. Verification and Validation
**Methods**:
- Requirements-based testing
- Fault injection testing  
- Hardware-in-the-loop (HIL) simulation
- Safety case development
- Independent assessment

### Example: Adaptive Cruise Control System

#### Item Definition
**Function**: Maintain set speed and following distance
**Operational Situations**: Highway driving, various weather conditions
**Interfaces**: Driver controls, radar sensors, engine/brake actuators

#### HARA Example
**Hazard**: Unintended acceleration during cruise control operation
- **Severity**: S2 (severe injuries possible from rear-end collision)
- **Exposure**: E4 (cruise control used frequently on highways)  
- **Controllability**: C2 (driver can brake to override)
- **ASIL**: B

**Safety Goal**: "The cruise control system shall not cause unintended acceleration that could lead to collision."

#### Safety Requirements Examples
- **FSR-1**: The system shall detect loss of radar sensor signal within 100ms
- **FSR-2**: The system shall transition to safe state (cruise off) upon sensor fault
- **FSR-3**: The system shall provide driver warning of system limitations
- **FSR-4**: The system shall be overrideable by driver brake input

#### Architecture Considerations
- Dual-channel radar processing (ASIL B decomposition)
- Independent safety monitor for acceleration commands
- Watchdog supervision of control algorithms  
- Graceful degradation to manual driving

## 📈 Implementation Roadmap

### For Organizations
1. **Establish Safety Culture**
   - Train personnel in functional safety
   - Define safety responsibilities
   - Implement safety processes

2. **Develop Safety Lifecycle**
   - Define development processes
   - Establish verification and validation methods
   - Implement traceability and configuration management

3. **Tool Qualification**
   - Assess and qualify development tools
   - Establish tool confidence levels
   - Maintain tool qualification evidence

4. **Continuous Improvement**
   - Monitor field performance
   - Analyze safety incidents
   - Update processes based on lessons learned

## 📚 Related Standards

### IEC 61508
Generic functional safety standard that ISO 26262 is derived from.

### ISO/PAS 21448 (SOTIF)
Safety of the Intended Functionality - addresses AI/ML and automation limitations.

### ASPICE
Automotive Software Process Improvement and Capability Determination.

### MISRA
Guidelines for safe programming in C and C++.

### AUTOSAR
Automotive software architecture standardization.

---

*This guide provides an educational overview of ISO 26262. For certification and production use, reference the complete standard documentation.*