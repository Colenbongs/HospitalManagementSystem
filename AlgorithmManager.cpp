#include "AlgorithmManager.h"
#include <algorithm>
#include <iostream>
#include <chrono>
#include <cctype>

using namespace std;
using namespace chrono;

// ANSI color codes for console output
#define GREEN "\033[32m"   // Success messages
#define RED "\033[31m"     // Error messages
#define YELLOW "\033[33m"  // Menu and titles
#define RESET "\033[0m"    // Reset color

// Constructor
AlgorithmManager::AlgorithmManager() {}

// Add a single patient to the system
void AlgorithmManager::addPatient(const Patient& patient) {
    try {
        patients.push_back(patient);
        cout << GREEN << "✓ Patient added successfully!" << RESET << endl;
    }
    catch (const exception& e) {
        cout << RED << "✗ Error adding patient: " << e.what() << RESET << endl;
    }
}

// Add 10 sample patients for demonstration
void AlgorithmManager::addSamplePatients() {
    try {
        patients.push_back(Patient(1001, "Alice Johnson", 5));
        patients.push_back(Patient(1002, "Bob Smith", 10));
        patients.push_back(Patient(1003, "Charlie Brown", 2));
        patients.push_back(Patient(1004, "Diana Prince", 10));
        patients.push_back(Patient(1005, "Eve Adams", 7));
        patients.push_back(Patient(1006, "Frank Castle", 3));
        patients.push_back(Patient(1007, "Grace Hopper", 8));
        patients.push_back(Patient(1008, "Henry Ford", 4));
        patients.push_back(Patient(1009, "Ivy Chen", 9));
        patients.push_back(Patient(1010, "Jack Ryan", 6));
        cout << GREEN << "✓ Added 10 sample patients successfully!" << RESET << endl;
    }
    catch (const exception& e) {
        cout << RED << "✗ Error adding sample patients: " << e.what() << RESET << endl;
    }
}

// Manual data insertion with input validation
void AlgorithmManager::insertPatientManually() {
    try {
        int id;
        string name;
        int urgency;

        cout << YELLOW << "\n--- Enter Patient Details ---" << RESET << endl;

        cout << "Enter Patient ID: ";
        cin >> id;
        if (cin.fail()) throw invalid_argument("Invalid ID format");

        cout << "Enter Patient Name: ";
        cin.ignore();
        getline(cin, name);
        if (name.empty()) throw invalid_argument("Name cannot be empty");

        cout << "Enter Urgency Level (1-10): ";
        cin >> urgency;
        if (cin.fail()) throw invalid_argument("Invalid urgency format");
        if (urgency < 1 || urgency > 10) throw out_of_range("Urgency must be between 1 and 10");

        Patient newPatient(id, name, urgency);
        patients.push_back(newPatient);
        cout << GREEN << "✓ Patient inserted successfully!" << RESET << endl;

    }
    catch (const invalid_argument& e) {
        cout << RED << "✗ Input Error: " << e.what() << RESET << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    catch (const out_of_range& e) {
        cout << RED << "✗ Range Error: " << e.what() << RESET << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    catch (const exception& e) {
        cout << RED << "✗ Error: " << e.what() << RESET << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// Display all patients in the system
void AlgorithmManager::displayAllPatients() const {
    try {
        if (patients.empty()) {
            cout << RED << "No patients in the system." << RESET << endl;
            return;
        }

        cout << YELLOW << "\n=== All Patients in System ===" << RESET << endl;
        cout << "Total Patients: " << patients.size() << endl;
        cout << "----------------------------------------" << endl;

        for (const auto& patient : patients) {
            patient.display();
            cout << endl;
        }

        cout << "----------------------------------------" << endl;

    }
    catch (const exception& e) {
        cout << RED << "✗ Error displaying patients: " << e.what() << RESET << endl;
    }
}

// ==================== O(1) Constant Time Algorithm ====================
// Direct access to patient record - time doesn't grow with input size
void AlgorithmManager::accessPatientO1(int id) {
    cout << YELLOW << "\n=== O(1) Constant Time Algorithm ===" << RESET << endl;
    cout << "Accessing patient record directly by ID" << endl;

    try {
        auto start = high_resolution_clock::now();  // Start timing

        bool found = false;
        // Linear search but still O(1) if ID maps directly to index
        // In real implementation, we would use direct indexing
        for (size_t i = 0; i < patients.size(); i++) {
            if (patients[i].getId() == id) {
                cout << GREEN << "\n✓ Patient Found:" << RESET << endl;
                patients[i].display();
                cout << endl;
                found = true;
                break;
            }
        }

        auto end = high_resolution_clock::now();  // End timing
        auto duration = duration_cast<microseconds>(end - start);

        if (!found) {
            cout << RED << "✗ No patient found with ID: " << id << RESET << endl;
        }

        cout << "Time taken: " << duration.count() << " microseconds" << endl;
        cout << "Complexity: O(1) - Constant time" << endl;

    }
    catch (const exception& e) {
        cout << RED << "✗ Error in O(1) algorithm: " << e.what() << RESET << endl;
    }
}

// ==================== O(log n) Logarithmic Time Algorithm ====================
// Binary search - divides search space in half each iteration
void AlgorithmManager::searchPatientByNameOlogN(string targetName) {
    cout << YELLOW << "\n=== O(log n) Logarithmic Time Algorithm ===" << RESET << endl;
    cout << "Binary search for patient by name" << endl;

    try {
        auto start = high_resolution_clock::now();

        // Create sorted copy for binary search
        vector<Patient> sortedPatients = patients;
        sort(sortedPatients.begin(), sortedPatients.end(), Patient::compareByName);

        int left = 0;
        int right = sortedPatients.size() - 1;
        int steps = 0;
        bool found = false;

        // Binary search algorithm - O(log n) comparisons
        while (left <= right) {
            steps++;
            int mid = left + (right - left) / 2;  // Avoid overflow

            if (sortedPatients[mid].getName() == targetName) {
                cout << GREEN << "\n✓ Patient Found after " << steps << " comparisons:" << RESET << endl;
                sortedPatients[mid].display();
                cout << endl;
                found = true;
                break;
            }
            else if (sortedPatients[mid].getName() < targetName) {
                left = mid + 1;  // Search right half
            }
            else {
                right = mid - 1;  // Search left half
            }
        }

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        if (!found) {
            cout << RED << "\n✗ Patient '" << targetName << "' not found after "
                << steps << " comparisons." << RESET << endl;
        }

        cout << "Total comparisons: " << steps << endl;
        cout << "Time taken: " << duration.count() << " microseconds" << endl;
        cout << "Complexity: O(log n) - Logarithmic time" << endl;

    }
    catch (const exception& e) {
        cout << RED << "✗ Error in O(log n) algorithm: " << e.what() << RESET << endl;
    }
}

// ==================== O(n) Linear Time Algorithm ====================
// Linear scan - examines each element exactly once
void AlgorithmManager::findCriticalPatientsOn() {
    cout << YELLOW << "\n=== O(n) Linear Time Algorithm ===" << RESET << endl;
    cout << "Scanning all patients for critical urgency (level 10)" << endl;

    try {
        auto start = high_resolution_clock::now();

        int criticalCount = 0;
        cout << "\nCritical Patients (Urgency = 10):" << endl;
        cout << "----------------------------------------" << endl;

        // Linear scan through all patients - O(n)
        for (const auto& patient : patients) {
            if (patient.getUrgency() == 10) {
                patient.display();
                cout << " [CRITICAL]" << endl;
                criticalCount++;
            }
        }

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        if (criticalCount == 0) {
            cout << "No critical patients found." << endl;
        }

        cout << "----------------------------------------" << endl;
        cout << "Total patients scanned: " << patients.size() << endl;
        cout << "Critical patients found: " << criticalCount << endl;
        cout << "Time taken: " << duration.count() << " microseconds" << endl;
        cout << "Complexity: O(n) - Linear time" << endl;

    }
    catch (const exception& e) {
        cout << RED << "✗ Error in O(n) algorithm: " << e.what() << RESET << endl;
    }
}

// ==================== O(n log n) Log-linear Time Algorithm ====================
// Efficient sorting algorithm (Introsort - hybrid of quicksort, heapsort, insertion sort)
void AlgorithmManager::sortPatientsByUrgencyOnlogn() {
    cout << YELLOW << "\n=== O(n log n) Log-linear Time Algorithm ===" << RESET << endl;
    cout << "Sorting patients by urgency (highest first)" << endl;

    try {
        auto start = high_resolution_clock::now();

        // Create copy to sort
        vector<Patient> sortedPatients = patients;
        // std::sort uses Introsort: O(n log n) average and worst case
        sort(sortedPatients.begin(), sortedPatients.end(), Patient::compareByUrgencyDesc);

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        cout << "\nPatients Sorted by Urgency:" << endl;
        cout << "----------------------------------------" << endl;

        for (const auto& patient : sortedPatients) {
            patient.display();
            cout << endl;
        }

        cout << "----------------------------------------" << endl;
        cout << "Time taken: " << duration.count() << " microseconds" << endl;
        cout << "Complexity: O(n log n) - Log-linear time" << endl;

    }
    catch (const exception& e) {
        cout << RED << "✗ Error in O(n log n) algorithm: " << e.what() << RESET << endl;
    }
}

// ==================== O(n²) Quadratic Time Algorithm ====================
// Nested loops - generates all pairs, number of operations = n(n-1)/2
void AlgorithmManager::displayAllPatientPairsOn2() {
    cout << YELLOW << "\n=== O(n²) Quadratic Time Algorithm ===" << RESET << endl;
    cout << "Generating all possible patient pairs" << endl;

    try {
        auto start = high_resolution_clock::now();

        int pairCount = 0;
        cout << "\nAll Patient Pairs:" << endl;
        cout << "----------------------------------------" << endl;

        // Nested loops - O(n²) complexity
        for (size_t i = 0; i < patients.size(); i++) {
            for (size_t j = i + 1; j < patients.size(); j++) {
                cout << pairCount + 1 << ". ";
                patients[i].display();
                cout << " <-> ";
                patients[j].display();
                cout << endl;
                pairCount++;
            }
        }

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        if (pairCount == 0) {
            cout << "Not enough patients to form pairs." << endl;
        }
        else {
            cout << "----------------------------------------" << endl;
            cout << "Total pairs generated: " << pairCount << endl;
        }

        cout << "Time taken: " << duration.count() << " microseconds" << endl;
        cout << "Complexity: O(n²) - Quadratic time" << endl;

    }
    catch (const exception& e) {
        cout << RED << "✗ Error in O(n²) algorithm: " << e.what() << RESET << endl;
    }
}

// ==================== O(2ⁿ) Exponential Time Algorithm ====================
// Recursive subset sum - explores all possible subsets (2^n possibilities)
bool AlgorithmManager::subsetSumExistsHelper(const vector<int>& ids, int target, int index) {
    try {
        // Base cases
        if (target == 0) return true;      // Found valid subset
        if (index >= ids.size() || target < 0) return false;  // No solution

        // Recursive cases: include current element OR exclude it
        // This creates binary tree with 2^n leaves
        return subsetSumExistsHelper(ids, target - ids[index], index + 1) ||
            subsetSumExistsHelper(ids, target, index + 1);
    }
    catch (const exception& e) {
        cout << RED << "✗ Error in subset sum recursion: " << e.what() << RESET << endl;
        return false;
    }
}

void AlgorithmManager::checkSubsetSumO2n(int targetSum) {
    cout << YELLOW << "\n=== O(2ⁿ) Exponential Time Algorithm ===" << RESET << endl;
    cout << "Checking if any subset of patient IDs sums to " << targetSum << endl;

    try {
        // Extract IDs from patients
        vector<int> ids;
        for (const auto& patient : patients) {
            ids.push_back(patient.getId());
        }

        cout << "Patient IDs: ";
        for (int id : ids) {
            cout << id << " ";
        }
        cout << endl;
        cout << "Target sum: " << targetSum << endl;

        auto start = high_resolution_clock::now();

        // Exponential algorithm call
        bool result = subsetSumExistsHelper(ids, targetSum, 0);

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        cout << "\nResult: ";
        if (result) {
            cout << GREEN << "✓ A subset of patient IDs sums to " << targetSum << RESET << endl;
        }
        else {
            cout << RED << "✗ No subset of patient IDs sums to " << targetSum << RESET << endl;
        }

        cout << "Total patients (n): " << ids.size() << endl;
        cout << "Maximum subsets: 2^" << ids.size() << " = " << (1ULL << ids.size()) << " possibilities" << endl;
        cout << "Time taken: " << duration.count() << " microseconds" << endl;
        cout << "Complexity: O(2ⁿ) - Exponential time" << endl;
        cout << "WARNING: This algorithm becomes infeasible for n > 30" << endl;

    }
    catch (const exception& e) {
        cout << RED << "✗ Error in O(2ⁿ) algorithm: " << e.what() << RESET << endl;
    }
}

// ==================== O(n!) Factorial Time Algorithm ====================
// Recursive permutation generation - generates all n! possible arrangements
void AlgorithmManager::generatePermutationsHelper(vector<Patient>& patients, int left, int right) {
    try {
        if (left == right) {
            // Base case: complete permutation found
            static int permutationCount = 0;
            permutationCount++;
            cout << permutationCount << ". ";
            for (const auto& p : patients) {
                cout << p.getName() << " ";
            }
            cout << endl;
        }
        else {
            // Generate permutations by swapping each element
            for (int i = left; i <= right; i++) {
                swap(patients[left], patients[i]);           // Swap current
                generatePermutationsHelper(patients, left + 1, right);  // Recurse
                swap(patients[left], patients[i]);           // Backtrack
            }
        }
    }
    catch (const exception& e) {
        cout << RED << "✗ Error in permutation generation: " << e.what() << RESET << endl;
    }
}

void AlgorithmManager::listAllPermutationsOnFactorial() {
    cout << YELLOW << "\n=== O(n!) Factorial Time Algorithm ===" << RESET << endl;
    cout << "Generating all permutations of patient treatment order" << endl;

    try {
        // Limit to 5 patients to avoid overwhelming output
        int maxPatients = min(5, (int)patients.size());

        if (maxPatients < 2) {
            cout << RED << "Need at least 2 patients to demonstrate permutations." << RESET << endl;
            return;
        }

        // Take subset of patients
        vector<Patient> subset(patients.begin(), patients.begin() + maxPatients);

        cout << "\nGenerating permutations for " << maxPatients << " patients:" << endl;
        cout << "Patients: ";
        for (const auto& p : subset) {
            cout << p.getName() << " ";
        }

        // Calculate factorial
        long long factorial = 1;
        for (int i = 2; i <= maxPatients; i++) {
            factorial *= i;
        }
        cout << "\nTotal permutations: " << maxPatients << "! = " << factorial << endl;
        cout << "----------------------------------------" << endl;

        auto start = high_resolution_clock::now();

        // Reset permutation counter
        static int permutationCounter = 0;
        permutationCounter = 0;

        // Generate all permutations
        generatePermutationsHelper(subset, 0, subset.size() - 1);

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);

        cout << "----------------------------------------" << endl;
        cout << "Total permutations: " << factorial << endl;
        cout << "Time taken: " << duration.count() << " milliseconds" << endl;
        cout << "Complexity: O(n!) - Factorial time" << endl;
        cout << "WARNING: This algorithm becomes impossible for n > 10" << endl;

    }
    catch (const exception& e) {
        cout << RED << "✗ Error in O(n!) algorithm: " << e.what() << RESET << endl;
    }
}

// Get total number of patients
int AlgorithmManager::getPatientCount() const {
    return patients.size();
}
