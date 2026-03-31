#ifndef ALGORITHM_MANAGER_H
#define ALGORITHM_MANAGER_H

#include "Patient.h"
#include <vector>
#include <string>

using namespace std;

class AlgorithmManager {
private:
    vector<Patient> patients;  // Container to store all patients

    // Helper for O(2^n) subset sum algorithm
    bool subsetSumExistsHelper(const vector<int>& ids, int target, int index);

    // Helper for O(n!) permutation generation
    void generatePermutationsHelper(vector<Patient>& patients, int left, int right);

public:
    AlgorithmManager();  // Constructor

    // Patient management functions
    void addPatient(const Patient& patient);
    void addSamplePatients();
    void insertPatientManually();
    void displayAllPatients() const;

    // Algorithm implementations for different complexities
    void accessPatientO1(int id);                    // O(1) - Constant time
    void searchPatientByNameOlogN(string targetName); // O(log n) - Logarithmic
    void findCriticalPatientsOn();                   // O(n) - Linear time
    void sortPatientsByUrgencyOnlogn();              // O(n log n) - Log-linear
    void displayAllPatientPairsOn2();                // O(n²) - Quadratic
    void checkSubsetSumO2n(int targetSum);           // O(2ⁿ) - Exponential
    void listAllPermutationsOnFactorial();           // O(n!) - Factorial

    int getPatientCount() const;  // Get total patients count
};

#endif﻿
