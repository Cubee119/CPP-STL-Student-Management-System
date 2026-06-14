#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// Define Student structure
struct Student {
    string id;
    string name;
    int score;
};

// Template challenge: Generic maximum and minimum functions
template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
T getMin(T a, T b) {
    return (a < b) ? a : b;
}

// Global container for student data
vector<Student> students;

// Function 1: Add student data
void addStudent() {
    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;
    
    // Check for duplicate student ID
    for (const auto& student : students) {
        if (student.id == s.id) {
            cout << "[ERROR] Student ID " << s.id << " already exists! Request denied.\n";
            return;
        }
    }
    
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Score: ";
    cin >> s.score;
    
    students.push_back(s);
    cout << "[SUCCESS] Student data added successfully!\n";
}

// Function 2: List all students
void listStudents() {
    if (students.empty()) {
        cout << "[INFO] No student data found.\n";
        return;
    }
    cout << "--------------------------------------------------\n";
    cout << left << setw(15) << "ID" << setw(15) << "Name" << "Score\n";
    cout << "--------------------------------------------------\n";
    for (const auto& s : students) {
        cout << left << setw(15) << s.id << setw(15) << s.name << s.score << "\n";
    }
    cout << "--------------------------------------------------\n";
}

// Function 3: Sort by score
void sortStudents() {
    if (students.empty()) {
        cout << "[INFO] No student data to sort.\n";
        return;
    }
    // Sort students by score in descending order using Lambda
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score;
    });
    cout << "[SUCCESS] Sorted by score (High to Low)! Use Option 2 to view.\n";
}

// Function 4: Search student by ID
void searchStudent() {
    string targetId;
    cout << "Enter Student ID to search: ";
    cin >> targetId;
    
    for (const auto& s : students) {
        if (s.id == targetId) {
            cout << "--------------------------------------------------\n";
            cout << "[RESULT] ID: " << s.id << " | Name: " << s.name << " | Score: " << s.score << "\n";
            cout << "--------------------------------------------------\n";
            return;
        }
    }
    cout << "[ERROR] Student ID " << targetId << " not found.\n";
}

// Function 5: Show statistics
void showStatistics() {
    if (students.empty()) {
        cout << "[INFO] No student data to calculate statistics.\n";
        return;
    }
    
    int sum = 0;
    int maxScore = students[0].score;
    int minScore = students[0].score;
    int passCount = 0;
    
    for (const auto& s : students) {
        sum += s.score;
        // Call Template functions
        maxScore = getMax<int>(maxScore, s.score);
        minScore = getMin<int>(minScore, s.score);
        if (s.score >= 60) {
            passCount++;
        }
    }
    
    double average = static_cast<double>(sum) / students.size();
    int failCount = students.size() - passCount;
    
    cout << "--------------------------------------------------\n";
    cout << "Class Average : " << fixed << setprecision(2) << average << "\n";
    cout << "Highest Score : " << maxScore << "\n";
    cout << "Lowest Score  : " << minScore << "\n";
    cout << "Passed Count  : " << passCount << "\n";
    cout << "Failed Count  : " << failCount << "\n";
    cout << "--------------------------------------------------\n";
}

int main() {
    int choice = -1;
    while (choice != 0) {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add student\n";
        cout << "2. List all students\n";
        cout << "3. Sort by score\n";
        cout << "4. Search by id\n";
        cout << "5. Show statistics\n";
        cout << "0. Exit\n";
        cout << "=====================================\n";
        cout << "Enter option: ";
        cin >> choice;
        
        switch (choice) {
            case 1: addStudent(); break;
            case 2: listStudents(); break;
            case 3: sortStudents(); break;
            case 4: searchStudent(); break;
            case 5: showStatistics(); break;
            case 0: cout << "System closed. Goodbye!\n"; break;
            default: cout << "[ERROR] Invalid option, please try again.\n"; break;
        }
    }
    return 0;
}