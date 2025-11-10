#!/usr/bin/env bash
# Interactive Tutorial for Exercise 04: Redundancy and Voting Systems
# ASIL C - Electric Power Steering

echo "================================================"
echo "Exercise 04: Redundancy and Voting Systems"
echo "ASIL C - Electric Power Steering"
echo "================================================"
echo ""
echo "This exercise demonstrates:"
echo "  - Dual-channel redundancy"
echo "  - 2-out-of-2 voting mechanisms"
echo "  - Cross-checking between channels"
echo "  - Plausibility analysis"
echo "  - Comprehensive diagnostic coverage"
echo ""
echo "Press Enter to continue..."
read

echo ""
echo "Step 1: Running VIOLATION example..."
echo "Expected: Missing redundancy, no voting, single point of failure"
echo ""
bazel run //exercises/04_redundancy_voting:violation_example

echo ""
echo "Press Enter to continue..."
read

echo ""
echo "Step 2: Running COMPLIANT example..."
echo "Expected: Dual channels, voting, fault detection and isolation"
echo ""
bazel run //exercises/04_redundancy_voting:compliant_example

echo ""
echo "================================================"
echo "Tutorial Complete!"
echo ""
echo "Next Steps:"
echo "  1. Review the code differences"
echo "  2. Study the README.md"
echo "  3. Understand ASIL C requirements"
echo "  4. Move to Exercise 05 (ASIL D)"
echo "================================================"
