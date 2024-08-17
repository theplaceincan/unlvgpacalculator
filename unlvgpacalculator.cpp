// Written by theplaceincan (Github).

/* 
This was made because, unlike the UNLV website, 
you can save your courses, calculate GPAs offline, and
easily edit your courses in a simple text file.
*/

// If you need help:
// 1. Please see this website for steps on using the program: https://github.com/theplaceincan/unlvgpacalculator
// 2. Message me! :)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_OF_GRADES = 13;

struct grade {
    string letter;
    double gradePoint;
};

const string grades[NUM_OF_GRADES] = { 
    "A", "A-", 
    "B+", "B", "B-", 
    "C+", "C", "C-", 
    "D+", "D", "D-", 
    "F", "S/U"
};

double gradePoints[NUM_OF_GRADES] = { 
    4.0, 3.7, 
    3.3, 3.0, 2.7, 
    2.3, 2.0, 1.7, 
    1.3, 1.0, 0.7, 
    0.0, 0.0
};

grade gradeArray[NUM_OF_GRADES];

int main() {
    for(int i = 0; i < NUM_OF_GRADES; i++) {
        gradeArray[i].letter = grades[i];
        gradeArray[i].gradePoint = gradePoints[i];
    }

    string fileName = "grades.csv";
    ifstream iFile(fileName);

    if (!iFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string str;
    int commaLocation = 0;
    double gpa = 0;
    double totalGradePoints = 0;
    int totalUnitsTaken = 0;

    while (getline(iFile, str)) {
        if (str.empty() || str[0] == '-') { 
            commaLocation = str.find(',');
            string _semester = str.substr(0, commaLocation); 
            str = str.substr(commaLocation + 1);
            commaLocation = str.find(',');
            string _year = str.substr(0, commaLocation); 
            if(_semester == "-FA") cout << "============ Fall " << "20" << _year << " ============" << endl;  
            if(_semester == "-SP") cout << "============ Spring " << "20" << _year << " ============" << endl;  
            if(_semester == "-SM") cout << "============ Summer " << "20" << _year << " ============" << endl;  
            continue; 
        }

        commaLocation = str.find(',');
        string _classesTaken = str.substr(0, commaLocation);
        str = str.substr(commaLocation + 1);

        commaLocation = str.find(',');
        int _unitTaken = stoi(str.substr(0, commaLocation));
        str = str.substr(commaLocation + 1);

        commaLocation = str.find(',');
        string _grade = str.substr(0, commaLocation);
        double _gradePoint = 0;
        bool gradeFound = false;
        for (int i = 0; i < NUM_OF_GRADES; i++) {
            if (_grade == gradeArray[i].letter) {
                _gradePoint = gradeArray[i].gradePoint;
                totalGradePoints += _gradePoint * _unitTaken;
                gradeFound = true;
                break;
            }
        }
        // if (!gradeFound) { cout << "Warning: Grade " << _grade << " found." << endl; }
        if (_unitTaken > 0) {
            totalUnitsTaken += _unitTaken;
        }
        cout << "Class: " << _classesTaken << ", Units: " << _unitTaken << ", Grade: " << _grade << ", Grade point: " << _gradePoint << endl;
    }

    if (totalUnitsTaken > 0) {
        gpa = (totalGradePoints / totalUnitsTaken);
    } else {
        gpa = 0.0;
    }

    cout << "========================================" << endl;
    cout << setprecision(3) << fixed;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Total Units Taken: " << (totalUnitsTaken + 0.0) << endl;
    cout << "GPA: " << gpa << endl;

    iFile.close();
    return 0;
}
