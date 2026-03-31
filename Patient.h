#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>

using namespace std;

class Patient {
private:
    int id;           // Unique patient ID
    string name;      // Patient name
    int urgency;      // Urgency level 1-10 (10 = most urgent)

public:
    // Constructors
    Patient();
    Patient(int id, string name, int urgency);

    // Getters
    int getId() const;
    string getName() const;
    int getUrgency() const;

    // Setters
    void setId(int id);
    void setName(string name);
    void setUrgency(int urgency);

    // Display patient details
    void display() const;

    // Static comparison functions for sorting
    static bool compareByName(const Patient& a, const Patient& b);
    static bool compareByUrgencyDesc(const Patient& a, const Patient& b);
};

#endif // PATIENT_H
