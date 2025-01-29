#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string gender;
    string contact_info;
    string medical_history;

    Patient(int id, string name, int age, string gender, string contact_info, string medical_history)
        : id(id), name(name), age(age), gender(gender), contact_info(contact_info), medical_history(medical_history) {}

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << ", Gender: " << gender
             << ", Contact: " << contact_info << ", History: " << medical_history << endl;
    }
};

class Doctor {
public:
    int id;
    string name;
    string specialization;
    string schedule;

    Doctor(int id, string name, string specialization, string schedule)
        : id(id), name(name), specialization(specialization), schedule(schedule) {}

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Specialization: " << specialization
             << ", Schedule: " << schedule << endl;
    }
};

class Appointment {
public:
    int appointment_id;
    int patient_id;
    int doctor_id;
    string date;
    string time;

    Appointment(int appointment_id, int patient_id, int doctor_id, string date, string time)
        : appointment_id(appointment_id), patient_id(patient_id), doctor_id(doctor_id), date(date), time(time) {}

    void display() const {
        cout << "Appointment ID: " << appointment_id << ", Patient ID: " << patient_id
             << ", Doctor ID: " << doctor_id << ", Date: " << date << ", Time: " << time << endl;
    }
};

bool login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if ((username == "muskan" && password == "muskan123") || (username == "doctor" && password == "doc123")) {
        cout << "Login successful! Welcome, " << username << ".\n";
        return true;
    } else {
        cout << "Invalid credentials. Access denied.\n";
        return false;
    }
}

void addPatient(vector<Patient>& patients) {
    int id, age;
    string name, gender, contact_info, medical_history;
    cout << "Enter Patient ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Patient Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Gender: ";
    getline(cin, gender);
    cout << "Enter Contact Info: ";
    getline(cin, contact_info);
    cout << "Enter Medical History: ";
    getline(cin, medical_history);

    patients.push_back(Patient(id, name, age, gender, contact_info, medical_history));
}

void addDoctor(vector<Doctor>& doctors) {
    int id;
    string name, specialization, schedule;
    cout << "Enter Doctor ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Doctor Name: ";
    getline(cin, name);
    cout << "Enter Specialization: ";
    getline(cin, specialization);
    cout << "Enter Schedule: ";
    getline(cin, schedule);

    doctors.push_back(Doctor(id, name, specialization, schedule));
}

void addAppointment(vector<Appointment>& appointments) {
    int appointment_id, patient_id, doctor_id;
    string date, time;
    cout << "Enter Appointment ID: ";
    cin >> appointment_id;
    cout << "Enter Patient ID: ";
    cin >> patient_id;
    cout << "Enter Doctor ID: ";
    cin >> doctor_id;
    cin.ignore();
    cout << "Enter Appointment Date (DD/MM/YYYY): ";
    getline(cin, date);
    cout << "Enter Appointment Time (HH:MM): ";
    getline(cin, time);

    appointments.push_back(Appointment(appointment_id, patient_id, doctor_id, date, time));
}

void updateAppointment(vector<Appointment>& appointments) {
    int appointment_id;
    cout << "Enter Appointment ID to update: ";
    cin >> appointment_id;

    for (auto& appointment : appointments) {
        if (appointment.appointment_id == appointment_id) {
            cout << "Enter new Date (DD/MM/YYYY): ";
            cin.ignore();
            getline(cin, appointment.date);
            cout << "Enter new Time (HH:MM): ";
            getline(cin, appointment.time);
            cout << "Appointment updated successfully.\n";
            return;
        }
    }
    cout << "Appointment not found.\n";
}

void cancelAppointment(vector<Appointment>& appointments) {
    int appointment_id;
    cout << "Enter Appointment ID to cancel: ";
    cin >> appointment_id;

    for (auto it = appointments.begin(); it != appointments.end(); ++it) {
        if (it->appointment_id == appointment_id) {
            appointments.erase(it);
            cout << "Appointment canceled successfully.\n";
            return;
        }
    }
    cout << "Appointment not found.\n";
}

void generateReports(const vector<Appointment>& appointments, const vector<Patient>& patients) {
    cout << "Daily Appointment Report:\n";
    for (const auto& appointment : appointments) {
        appointment.display();
    }

    cout << "\nPatient Records Report:\n";
    for (const auto& patient : patients) {
        patient.display();
    }
}

int main() {
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

    if (!login()) return 0;

    int choice;

    while (true) {
        cout << "Hospital Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Add Appointment\n";
        cout << "4. Update Appointment\n";
        cout << "5. Cancel Appointment\n";
        cout << "6. Display Patients\n";
        cout << "7. Display Doctors\n";
        cout << "8. Display Appointments\n";
        cout << "9. Generate Reports\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient(patients);
                break;
            case 2:
                addDoctor(doctors);
                break;
            case 3:
                addAppointment(appointments);
                break;
            case 4:
                updateAppointment(appointments);
                break;
            case 5:
                cancelAppointment(appointments);
                break;
            case 6:
                for (const auto& patient : patients) patient.display();
                break;
            case 7:
                for (const auto& doctor : doctors) doctor.display();
                break;
            case 8:
                for (const auto& appointment : appointments) appointment.display();
                break;
            case 9:
                generateReports(appointments, patients);
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
