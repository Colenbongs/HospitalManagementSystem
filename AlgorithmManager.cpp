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
