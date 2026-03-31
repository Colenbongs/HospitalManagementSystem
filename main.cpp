#include "AlgorithmManager.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// ANSI color codes
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// Display main menu with yellow color
void displayMenu() {
    cout << YELLOW << "\n========================================" << RESET << endl;
    cout << YELLOW << "HOSPITAL PATIENT MANAGEMENT SYSTEM" << RESET << endl;
    cout << YELLOW << "========================================" << RESET << endl;
    cout << YELLOW << "1. O(1) - Constant Time" << RESET << endl;
    cout << YELLOW << "2. O(log n) - Logarithmic Time" << RESET << endl;
    cout << YELLOW << "3. O(n) - Linear Time" << RESET << endl;
    cout << YELLOW << "4. O(n log n) - Log-linear Time" << RESET << endl;
    cout << YELLOW << "5. O(n²) - Quadratic Time" << RESET << endl;
    cout << YELLOW << "6. O(2ⁿ) - Exponential Time" << RESET << endl;
    cout << YELLOW << "7. O(n!) - Factorial Time" << RESET << endl;
    cout << YELLOW << "8. Display All Patients" << RESET << endl;
    cout << YELLOW << "9. Insert New Patient" << RESET << endl;
    cout << YELLOW << "10. Run All Demonstrations" << RESET << endl;
    cout << YELLOW << "0. Exit" << RESET << endl;
    cout << YELLOW << "========================================" << RESET << endl;
    cout << YELLOW << "Enter your choice: " << RESET;
}

// Function to clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Run all algorithm demonstrations in sequence
void runAllDemonstrations(AlgorithmManager& manager) {
    cout << YELLOW << "\n========================================" << RESET << endl;
    cout << YELLOW << "RUNNING ALL ALGORITHM DEMONSTRATIONS" << RESET << endl;
    cout << YELLOW << "========================================" << RESET << endl;

    manager.accessPatientO1(1003);
    manager.searchPatientByNameOlogN("Grace Hopper");
    manager.findCriticalPatientsOn();
    manager.sortPatientsByUrgencyOnlogn();
    manager.displayAllPatientPairsOn2();
    manager.checkSubsetSumO2n(2005);
    manager.listAllPermutationsOnFactorial();

    cout << YELLOW << "\n========================================" << RESET << endl;
    cout << YELLOW << "ALL DEMONSTRATIONS COMPLETED" << RESET << endl;
    cout << YELLOW << "========================================" << RESET << endl;
}

int main() {
    cout << YELLOW << "========================================" << RESET << endl;
    cout << YELLOW << "HOSPITAL PATIENT MANAGEMENT SYSTEM" << RESET << endl;
    cout << YELLOW << "Algorithm Complexity Analysis Project" << RESET << endl;
    cout << YELLOW << "========================================" << RESET << endl;

    AlgorithmManager manager;

    try {
        manager.addSamplePatients();
        cout << GREEN << "\nSystem initialized with " << manager.getPatientCount() << " patients." << RESET << endl;
    }
    catch (const exception& e) {
        cout << RED << "Error initializing system: " << e.what() << RESET << endl;
        return 1;
    }

    int choice;
    bool running = true;

    while (running) {
        displayMenu();

        try {
            cin >> choice;

            if (cin.fail()) {
                throw invalid_argument("Invalid input. Please enter a number.");
            }

            switch (choice) {
            case 1: {
                int id;
                cout << "Enter patient ID to access: ";
                cin >> id;
                manager.accessPatientO1(id);
                break;
            }
            case 2: {
                string name;
                cout << "Enter patient name to search: ";
                cin.ignore();
                getline(cin, name);
                manager.searchPatientByNameOlogN(name);
                break;
            }
            case 3:
                manager.findCriticalPatientsOn();
                break;
            case 4:
                manager.sortPatientsByUrgencyOnlogn();
                break;
            case 5:
                manager.displayAllPatientPairsOn2();
                break;
            case 6: {
                int target;
                cout << "Enter target sum to check: ";
                cin >> target;
                manager.checkSubsetSumO2n(target);
                break;
            }
            case 7:
                manager.listAllPermutationsOnFactorial();
                break;
            case 8:
                manager.displayAllPatients();
                break;
            case 9:
                manager.insertPatientManually();
                break;
            case 10:
                runAllDemonstrations(manager);
                break;
            case 0:
                cout << YELLOW << "\nThank you for using the Hospital Patient Management System!" << RESET << endl;
                cout << YELLOW << "Exiting program..." << RESET << endl;
                running = false;
                break;
            default:
                cout << RED << "Invalid choice. Please enter 0-10." << RESET << endl;
                clearInputBuffer();
            }

            if (running && choice != 0) {
                cout << YELLOW << "\nPress Enter to return to menu..." << RESET;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }
        }
        catch (const invalid_argument& e) {
            cout << RED << "Error: " << e.what() << RESET << endl;
            clearInputBuffer();
        }
        catch (const exception& e) {
            cout << RED << "Unexpected error: " << e.what() << RESET << endl;
            clearInputBuffer();
        }
    }

    return 0;
}
