# Hospital Patient Management System
## Algorithm Analysis and Implementation Project

---

## Table of Contents
1. [Project Overview](#project-overview)
2. [Problem Statement](#problem-statement)
3. [System Architecture](#system-architecture)
4. [Algorithm Implementations](#algorithm-implementations)
5. [Installation and Setup](#installation-and-setup)
6. [Usage Guide](#usage-guide)
7. [Complexity Analysis](#complexity-analysis)
8. [Error Handling](#error-handling)
9. [References](#references)
10. [Contributors](#contributors)

---

## Project Overview

The Hospital Patient Management System is a comprehensive C++ application designed to demonstrate seven fundamental algorithm complexity classes through real-world healthcare scenarios. The system provides practical implementations of algorithms ranging from constant time O(1) to factorial time O(n!), each applied to meaningful hospital management tasks such as patient record access, searching, sorting, and treatment scheduling.

### Key Features
- *7 Algorithm Implementations*: Demonstrates O(1), O(log n), O(n), O(n log n), O(n²), O(2ⁿ), and O(n!) complexities
- *Real Healthcare Context*: Each algorithm solves actual hospital management problems
- *Interactive Menu System*: User-friendly interface with colored console output
- *Data Management*: Insert, display, and manage patient records
- *Performance Metrics*: Time measurements for each algorithm execution
- *Comprehensive Error Handling*: Try-catch blocks with input validation

---

## Problem Statement

Modern hospitals require efficient information systems to manage patient data, prioritize care, and optimize resource allocation. The challenge lies in selecting appropriate algorithms that balance performance with functionality. This project addresses this by:

1. Providing instant access to patient records (O(1))
2. Enabling fast patient search capabilities (O(log n))
3. Identifying critical patients requiring immediate attention (O(n))
4. Prioritizing patients by urgency level (O(n log n))
5. Analyzing patient interactions and conflicts (O(n²))
6. Solving resource allocation problems (O(2ⁿ))
7. Optimizing treatment sequences (O(n!))

---

## System Architecture

### File Structure

HospitalPatientManagement/
│
├── Patient.h              # Patient class declaration
├── Patient.cpp            # Patient class implementation
├── AlgorithmManager.h     # Algorithm manager declaration
├── AlgorithmManager.cpp   # Algorithm implementations
├── main.cpp              # Main program with menu system
└── README.md             # Project documentation


### Class Design

#### Patient Class
- *Attributes*: id (int), name (string), urgency (int 1-10)
- *Methods*: Getters, setters, display, comparison functions
- *Purpose*: Encapsulates patient data and provides basic operations

#### AlgorithmManager Class
- *Attributes*: vector<Patient> patients
- *Methods*: Seven algorithm implementations plus helper functions
- *Purpose*: Manages patient data and implements all complexity algorithms

---

## Algorithm Implementations

### 1. O(1) - Constant Time: Direct Patient Access
*Purpose*: Retrieve patient records instantly by ID
*Application*: Emergency room lookup, immediate patient access
*Implementation*: Direct array indexing using patient ID as index

### 2. O(log n) - Logarithmic Time: Binary Search
*Purpose*: Search for patients by name efficiently
*Application*: Finding patients in large databases
*Implementation*: Binary search on sorted patient names

### 3. O(n) - Linear Time: Critical Patient Scan
*Purpose*: Identify all patients with urgency level 10
*Application*: Emergency response, prioritizing critical care
*Implementation*: Linear scan through all patients

### 4. O(n log n) - Log-linear Time: Sort by Urgency
*Purpose*: Sort patients by urgency level (highest first)
*Application*: Creating priority treatment lists
*Implementation*: std::sort (Introsort algorithm)

### 5. O(n²) - Quadratic Time: Patient Pair Analysis
*Purpose*: Generate all possible patient pairs
*Application*: Room-sharing compatibility, conflict detection
*Implementation*: Nested loops generating n(n-1)/2 pairs

### 6. O(2ⁿ) - Exponential Time: Subset Sum
*Purpose*: Find subsets of patient IDs that sum to target
*Application*: Resource allocation, equipment distribution
*Implementation*: Recursive algorithm exploring all subsets

### 7. O(n!) - Factorial Time: Treatment Permutations
*Purpose*: Generate all possible treatment sequences
*Application*: Optimizing surgery schedules, treatment order
*Implementation*: Recursive permutation generation

---

## Installation and Setup

### Prerequisites
- C++11 compatible compiler (g++ 4.8+ or Clang 3.4+)
- Make (optional, for using Makefile)
- Terminal/Command Prompt with ANSI color support

### Installation Steps

#### Method 1: Using Make (Recommended)
bash
# Clone or download the project files
cd HospitalPatientManagement

# Compile the program
make

# Run the program
make run

# Clean build files
make clean


#### Method 2: Manual Compilation with g++
bash
# Compile all source files
g++ -std=c++11 -Wall main.cpp Patient.cpp AlgorithmManager.cpp -o hospital_system

# Run the executable
./hospital_system


#### Method 3: Windows (MinGW)
bash
# Compile with MinGW
g++ -std=c++11 -Wall main.cpp Patient.cpp AlgorithmManager.cpp -o hospital_system.exe

# Run
hospital_system.exe


---

## Usage Guide

### Main Menu Options

| Option | Algorithm | Description |
|--------|-----------|-------------|
| 1 | O(1) | Access patient by ID |
| 2 | O(log n) | Search patient by name |
| 3 | O(n) | Find critical patients |
| 4 | O(n log n) | Sort by urgency |
| 5 | O(n²) | Display all patient pairs |
| 6 | O(2ⁿ) | Check subset sum |
| 7 | O(n!) | Generate treatment permutations |
| 8 | - | Display all patients |
| 9 | - | Insert new patient |
| 10 | - | Run all demonstrations |
| 0 | - | Exit program |

### Sample Usage

#### Inserting a New Patient

Enter your choice: 9

--- Enter Patient Details ---
Enter Patient ID: 1011
Enter Patient Name: Sarah Johnson
Enter Urgency Level (1-10): 9
✓ Patient inserted successfully!


#### Running O(1) Algorithm

Enter your choice: 1
Enter patient ID to access: 1003

=== O(1) Constant Time Algorithm ===
✓ Patient Found:
ID: 1003 | Name: Charlie Brown | Urgency: 2/10
Time taken: 15 microseconds
Complexity: O(1) - Constant time


#### Binary Search (O(log n))

Enter your choice: 2
Enter patient name to search: Grace Hopper

=== O(log n) Logarithmic Time Algorithm ===
✓ Patient Found after 3 comparisons:
ID: 1007 | Name: Grace Hopper | Urgency: 8/10
Total comparisons: 3
Time taken: 12 microseconds
Complexity: O(log n) - Logarithmic time


### Color Coding
- *Yellow*: Menu headers and section titles
- *Green*: Success messages and found results
- *Red*: Error messages and warnings

---

## Complexity Analysis

### Theoretical vs Practical Performance

| Algorithm | Complexity | n=10 | n=100 | n=1000 | Real-world Application |
|-----------|------------|------|-------|--------|------------------------|
| Direct Access | O(1) | 1μs | 1μs | 1μs | Emergency lookup |
| Binary Search | O(log n) | 4μs | 7μs | 10μs | Patient search |
| Linear Scan | O(n) | 10μs | 100μs | 1ms | Critical alerts |
| Sorting | O(n log n) | 33μs | 664μs | 9.9ms | Priority lists |
| Nested Loops | O(n²) | 100μs | 10ms | 1s | Pair analysis |
| Subset Sum | O(2ⁿ) | 1ms | ∞ | ∞ | Small resource alloc. |
| Permutations | O(n!) | 3.6ms | ∞ | ∞ | Small schedule opt. |

### Space Complexity Analysis

| Algorithm | Space Complexity | Explanation |
|-----------|-----------------|-------------|
| O(1) Access | O(n) | Stores n patients in vector |
| O(log n) Search | O(n) | Creates sorted copy |
| O(n) Scan | O(1) | Uses constant extra space |
| O(n log n) Sort | O(log n) | Recursion stack space |
| O(n²) Pairs | O(1) | Constant extra space |
| O(2ⁿ) Subset | O(n) | Recursion depth |
| O(n!) Permutations | O(n) | Recursion depth |

---

## Error Handling

The system implements comprehensive error handling throughout:

### Input Validation
- *ID Validation*: Ensures valid integer input
- *Name Validation*: Prevents empty names
- *Urgency Validation*: Restricts values to 1-10 range
- *Menu Input*: Handles non-numeric input

### Exception Types
- *invalid_argument*: For invalid input formats
- *out_of_range*: For values outside expected ranges
- *exception*: For general error handling

### Error Recovery
- Clears input buffer after invalid input
- Returns to menu without crashing
- Displays descriptive error messages in red

### Example Error Messages

✗ Input Error: Invalid ID format
✗ Range Error: Urgency must be between 1 and 10
✗ No patient found with ID: 9999


---

## References

### Books

Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to algorithms (3rd ed.). MIT Press.

Sedgewick, R., & Wayne, K. (2011). Algorithms (4th ed.). Addison-Wesley Professional.

Knuth, D. E. (1998). The art of computer programming, volume 3: Sorting and searching (2nd ed.). Addison-Wesley.

Stroustrup, B. (2013). The C++ programming language (4th ed.). Addison-Wesley Professional.

Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). Data structures and algorithms in C++ (2nd ed.). John Wiley & Sons.

### Academic Papers

Bentley, J. L., & McIlroy, M. D. (1993). Engineering a sort function. Software: Practice and Experience, 23(11), 1249-1265. https://doi.org/10.1002/spe.4380231105

Musser, D. R. (1997). Introspective sorting and selection algorithms. Software: Practice and Experience, 27(8), 983-993. https://doi.org/10.1002/(SICI)1097-024X(199708)27:8<983::AID-SPE117>3.0.CO;2-#

### Online Resources

C++ Reference. (2023). std::sort. Retrieved March 31, 2026, from https://en.cppreference.com/w/cpp/algorithm/sort

GeeksforGeeks. (2023). Analysis of different sorting techniques. Retrieved March 31, 2026, from https://www.geeksforgeeks.org/analysis-of-different-sorting-techniques/

Stack Overflow. (2023). What is the time complexity of std::sort? Retrieved March 31, 2026, from https://stackoverflow.com/questions/18474089/what-is-the-time-complexity-of-stdsort

### Documentation

ISO/IEC. (2020). ISO/IEC 14882:2020 Programming languages — C++. International Organization for Standardization.

### Healthcare Informatics

Shortliffe, E. H., & Cimino, J. J. (2014). Biomedical informatics: Computer applications in health care and biomedicine (4th ed.). Springer.

---

## Contributors

*Group F - Algorithm Analysis and Implementation Project*

| Student Number | Name |
|----------------|------|
| 220115085 | Sandile Sibeko |
| 221152725 | Mongiwethu Eddy Ncube |
| 220068905 | Keamogetse Selebano |
| 220122253 | Ndzulamo Michelle Yingwani |
| 220080694 | Hlonipho Nersely Bila |
| 220061777 | Zizile Ezona Mbanqi |
| 219027546 | Bongane Sithole |

*Course:* APM11A1 - Algorithm Analysis and Implementation  
*Assignment:* 3  
*Date:* March 31, 2026  
*Institution:* University of Johannesburg  
*Department:* Department of Applied Mathematics and Computer Science

### Group Roles and Contributions

| Name | Role | Contributions |
|------|------|---------------|
| Sandile Sibeko | Project Lead | Overall coordination, O(1) and O(n) algorithms |
| Mongiwethu Eddy Ncube | Algorithm Specialist | O(log n) and O(n log n) implementations |
| Keamogetse Selebano | UI/UX Designer | Menu system, color coding, user interface |
| Ndzulamo Michelle Yingwani | Documentation Lead | README, references, technical documentation |
| Hlonipho Nersely Bila | Testing Engineer | Error handling, input validation, testing |
| Zizile Ezona Mbanqi | Algorithm Specialist | O(n²) and O(2ⁿ) implementations |
| Bongane Sithole | Integration Lead | O(n!) implementation, system integration |

---

## License

This project is created for educational purposes as part of the University of Johannesburg's curriculum. All code is original work and may be used for learning and reference purposes.

---

## Acknowledgments

- University of Johannesburg for providing the academic framework
- Course instructors for guidance on algorithm analysis
- Healthcare professionals for real-world context validation
- Department of Applied Mathematics and Computer Science for resources and support

---

## Version History

| Version | Date | Changes | Contributors |
|---------|------|---------|--------------|
| 1.0 | March 31, 2026 | Initial release with all seven algorithms | All Group Members |
| 1.1 | March 31, 2026 | Added error handling and colored output | Hlonipho Bila, Keamogetse Selebano |
| 1.2 | March 31, 2026 | Implemented data insertion functionality | Zizile Mbanqi, Bongane Sithole |

---

## Declaration of Originality

We, the undersigned, declare that this project is our original work. All sources used have been acknowledged and referenced appropriately. No part of this work has been plagiarized.

*Signed:*

| Name | Signature | Date |
|------|-----------|------|
| Sandile Sibeko | S.S | 31/03/2026 |
| Mongiwethu Eddy Ncube | M.E.N | 31/03/2026 |
| Keamogetse Selebano | K.S | 31/03/2026 |
| Ndzulamo Michelle Yingwani | N.M.Y | 31/03/2026 |
| Hlonipho Nersely Bila | H.N.B | 31/03/2026 |
| Zizile Ezona Mbanqi | Z.E.M | 31/03/2026 |
| Bongane Sithole | B.S | 31/03/2026 |

---

## Future Enhancements

Potential improvements for future versions:
1. Database integration for persistent storage
2. GUI interface for better user experience
3. Network capabilities for multi-user access
4. Additional algorithm implementations
5. Real-time patient monitoring integration
6. Machine learning for predictive patient care
7. Mobile application interface
8. Cloud-based patient data synchronization
9. Encryption for patient data security
10. Automated report generation

---

*Note:* This system is designed for educational purposes to demonstrate algorithm complexity concepts. For production healthcare systems, additional security, privacy, and regulatory compliance measures would be required.

---

## Contact Information

For questions or clarifications regarding this project, please contact:
- *Course*: APM11A1 - Algorithm Analysis and Implementation
- *Institution*: University of Johannesburg
- *Department*: Applied Mathematics and Computer Science
- *Date*: March 31, 2026
```
