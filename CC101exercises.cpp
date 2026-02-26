#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {

    char choice;

    do {
        int students, days;

        cout<< "Enter the number of students: ";
        cin>> students;

        cout<< "Enter the number of school days: ";
        cin>> days;

        vector<vector<int>> attendance(students, vector<int>(days));

        
        for(int i = 0; i < students; i++) {
            cout << "\nEnter attendance for Student " << i + 1 << ":\n";

            for(int j = 0; j < days; j++) {
                cout << "Day " << j + 1 << " (1 = Present, 0 = Absent): ";
                cin >> attendance[i][j];
            }
        }

        
        cout<< "\n\nStudent\t";
        for(int d = 0; d < days; d++) {
            cout << "D" << d + 1 << "\t";
        }
        cout << "Total\tPercentage\tRemarks\n";

        
        for(int i = 0; i < students; i++) {

            int total = 0;
            cout<< i + 1 << "\t";

            for(int j = 0; j < days; j++) {
                cout << attendance[i][j] << "\t";
                total += attendance[i][j];
            }

            double percentage = (double)total / days * 100;

            string remarks;
            if(percentage < 50)
                remarks = "DRP";
            else
                remarks = "OK";

            cout<< total << "\t";
            cout<< fixed << setprecision(0) << percentage << "%\t\t";
            cout<< remarks << endl;
        }

        cout<< "\nRun again? (y/n): ";
        cin>> choice;

    } while(choice == 'y' || choice == 'Y');

    return 0;
}