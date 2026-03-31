#include "Patient.h"
#include <iomanip>

// Default constructor
Patient::Patient() : id(0), name(""), urgency(0) {}

// Parameterized constructor
Patient::Patient(int id, string name, int urgency) {
    this->id = id;
    this->name = name;
    this->urgency = urgency;
}

// Getters implementation
int Patient::getId() const { return id; }
string Patient::getName() const { return name; }
int Patient::getUrgency() const { return urgency; }

// Setters implementation
void Patient::setId(int id) { this->id = id; }
void Patient::setName(string name) { this->name = name; }
void Patient::setUrgency(int urgency) { this->urgency = urgency; }

// Display patient information
void Patient::display() const {
    cout << "ID: " << id << " | Name: " << name << " | Urgency: " << urgency << "/10";
}

// Compare patients by name for sorting
bool Patient::compareByName(const Patient& a, const Patient& b) {
    return a.name < b.name;
}

// Compare patients by urgency (descending order)
bool Patient::compareByUrgencyDesc(const Patient& a, const Patient& b) {
    return a.urgency > b.urgency;
}
