//Write a C++ program to implement a class called Employee that has private member variables for name, employee ID, and salary. Include member functions to calculate and set salary based on employee performance.

// #include <iostream>
// #include <string>
// using namespace std;

// class Employee
// {
//     private:
//         string name;
//         int employeeID;
//         double salary;
//     public:
//         void setSalary(double s)
//         {
//             salary = s;
//         }
//         void setSalary(double s, double bonus)
//         {
//             salary = s + bonus;
//         }
//         void show()
//         {
//             cout << "Name: " << name << endl;
//             cout << "Employee ID: " << employeeID << endl;
//             cout << "Salary: " << salary << endl;
//         }
// };

// int main()
// {
//     Employee e;
//     e.setSalary(50000);
//     e.show();
//     e.setSalary(50000, 10000);
//     e.show();
//     return 0;
// }

//Write a C++ program to implement a class called Date that has private member variables for day, month, and year. Include member functions to set and get these variables, as well as to validate if the date is valid.

// #include <iostream>
// using namespace std;

// class Date
// {
//     private:
//         int day;
//         int month;
//         int year;
//     public:
//         void setDate(int d, int m, int y)
//         {
//             day = d;
//             month = m;
//             year = y;
//         }
//         int getDay()
//         {
//             return day;
//         }
//         int getMonth()
//         {
//             return month;
//         }
//         int getYear()
//         {
//             return year;
//         }
//         bool isValid()
//         {
//             if (year < 0)
//             {
//                 return false;
//             }
//             if (month < 1 || month > 12)
//             {
//                 return false;
//             }
//             if (day < 1 || day > 31)
//             {
//                 return false;
//             }
//             if (month == 2)
//             {
//                 if (year % 4 == 0)
//                 {
//                     if (day > 29)
//                     {
//                         return false;
//                     }
//                 }
//                 else
//                 {
//                     if (day > 28)
//                     {
//                         return false;
//                     }
//                 }
//             }
//             if (month == 4 || month == 6 || month == 9 || month == 11)
//             {
//                 if (day > 30)
//                 {
//                     return false;
//                 }
//             }
//             return true;
//         }
// };

// int main()
// {
//     Date d;
//     d.setDate(31, 12, 2020);
//     if (d.isValid())
//     {
//         cout << "Date is valid." << endl;
//     }
//     else
//     {
//         cout << "Date is invalid." << endl;
//     }
//     return 0;
// }

//Write a C++ program to implement a class called Student that has private member variables for name, class, roll number, and marks. Include member functions to calculate the grade based on the marks and display the student's information.

#include <iostream>
#include <string>
using namespace std;

class Student
{
    private:
        string name;
        string className;
        int rollNumber;
        double marks;
        char grade;
    public:
        void setStudent(string n, string c, int r, double m)
        {
            name = n;
            className = c;
            rollNumber = r;
            marks = m;
            if (marks >= 90)
            {
                grade = 'A';
            }
            else if (marks >= 80)
            {
                grade = 'B';
            }
            else if (marks >= 70)
            {
                grade = 'C';
            }
            else if (marks >= 60)
            {
                grade = 'D';
            }
            else if (marks >= 50)
            {
                grade = 'E';
            }
            else
            {
                grade = 'F';
            }
        }
        void show()
        {
            cout << "Name: " << name << endl;
            cout << "Class: " << className << endl;
            cout << "Roll Number: " << rollNumber << endl;
            cout << "Marks: " << marks << endl;
            cout << "Grade: " << grade << endl;
        }
};

int main()
{
    Student s;
    s.setStudent("Prashant", "Bachelor", 240023, 100);
    s.show();
    return 0;
}