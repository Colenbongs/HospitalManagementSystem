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

// Function to pause and wait for user input
void waitForUser() {
    cout << YELLOW << "\nPress Enter to continue..." << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Run all algorithm demonstrations in sequence
void runAllDemonstrations(AlgorithmManager& manager) {
    cout << YELLOW << "\n========================================" << RESET << endl;
    cout << YELLOW << "RUNNING ALL ALGORITHM DEMONSTRATIONS" << RESET << endl;
    cout << YELLOW << "========================================" << RESET << endl;

    // Execute all seven algorithms
    manager.accessPatientO1(1003);                      // O(1) - Constant
    manager.searchPatientByNameOlogN("Grace Hopper");   // O(log n) - Logarithmic
    manager.findCriticalPatientsOn();                    // O(n) - Linear
    manager.sortPatientsByUrgencyOnlogn();               // O(n log n) - Log-linear
    manager.displayAllPatientPairsOn2();                 // O(n²) - Quadratic
    manager.checkSubsetSumO2n(2005);                     // O(2ⁿ) - Exponential
    manager.listAllPermutationsOnFactorial();            // O(n!) - Factorial

    cout << YELLOW << "\n========================================" << RESET << endl;
    cout << YELLOW << "ALL DEMONSTRATIONS COMPLETED" << RESET << endl;
    cout << YELLOW << "========================================" << RESET << endl;
}

int main() {
    // Display welcome message
    cout << YELLOW << "========================================" << RESET << endl;
    cout << YELLOW << "HOSPITAL PATIENT MANAGEMENT SYSTEM" << RESET << endl;
    cout << YELLOW << "Algorithm Complexity Analysis Project" << RESET << endl;
    cout << YELLOW << "========================================" << RESET << endl;

    AlgorithmManager manager;  // Create manager instance

    // Initialize system with sample data
    try {
        manager.addSamplePatients();
        cout << GREEN << "\nSystem initialized with " << manager.getPatientCount() << " patients." << RESET << endl;
    }
    catch (const exception& e) {
        cout << RED << "Error initializing system: " << e.what() << RESET << endl;
        return 1;
    }

    int choice;
    bool running = true;  // Flag to control program execution

    while (running) {  // Keep running until user chooses to exit
        displayMenu();  // Show menu

        try {
            cin >> choice;  // Get user choice

            // Input validation
            if (cin.fail()) {
                throw invalid_argument("Invalid input. Please enter a number.");
            }

            // Process user choice
            switch (choice) {
            case 1: {  // O(1) Constant Time
                int id;
                cout << "Enter patient ID to access: ";
                cin >> id;
                manager.accessPatientO1(id);
                break;
            }

            case 2: {  // O(log n) Logarithmic Time
                string name;
                cout << "Enter patient name to search: ";
                cin.ignore();
                getline(cin, name);
                manager.searchPatientByNameOlogN(name);
                break;
            }

            case 3:  // O(n) Linear Time
                manager.findCriticalPatientsOn();
                break;

            case 4:  // O(n log n) Log-linear Time
                manager.sortPatientsByUrgencyOnlogn();
                break;

            case 5:  // O(n²) Quadratic Time
                manager.displayAllPatientPairsOn2();
                break;

            case 6: {  // O(2ⁿ) Exponential Time
                int target;
                cout << "Enter target sum to check: ";
                cin >> target;
                manager.checkSubsetSumO2n(target);
                break;
            }

            case 7:  // O(n!) Factorial Time
                manager.listAllPermutationsOnFactorial();
                break;

            case 8:  // Display all patients
                manager.displayAllPatients();
                break;

            case 9:  // Insert new patient
                manager.insertPatientManually();
                break;

            case 10:  // Run all demonstrations
                runAllDemonstrations(manager);
                break;

            case 0:  // Exit program
                cout << YELLOW << "\nThank you for using the Hospital Patient Management System!" << RESET << endl;
                cout << YELLOW << "Exiting program..." << RESET << endl;
                running = false;  // Set flag to exit loop
                break;

            default:  // Invalid choice
                cout << RED << "Invalid choice. Please enter 0-10." << RESET << endl;
                clearInputBuffer();  // Clear invalid input
            }

            // If not exiting, wait for user to press Enter
            if (running && choice != 0) {
                cout << YELLOW << "\nPress Enter to return to menu..." << RESET;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }

        }
        catch (const invalid_argument& e) {
            cout << RED << "Error: " << e.what() << RESET << endl;
            clearInputBuffer();  // Clear error flags and buffer
        }
        catch (const exception& e) {
            cout << RED << "Unexpected error: " << e.what() << RESET << endl;
            clearInputBuffer();
        }

        // Clear screen for better visibility 
    }

    return 0;
}﻿
