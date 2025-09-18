

#include <iostream>
using namespace std;

struct courseinfo 
{
    char crscode[20];
    int ectscred;
};
struct studentinfo 
{
    char name[50];
    char adress[50];
    char phnum[20];
    char stid[20];
    char major[4];
    char deg[3];
    double cpa;
    int ects;
    double tgp;
    courseinfo courses[6];
    int crsnum;
    double gpa;
};
//Prototypes
void Read_Student(studentinfo student[], int snum);
bool Already_Registered(const studentinfo student[], const int maxsize, const int snum);
void Register_to_Courses(studentinfo student[], const int maxsize, char id[]);
int How_Many_Students(const studentinfo student[], const int maxsize);
bool Find_Student(const studentinfo student[], const int maxsize, char id[]);
void Student_Details(const studentinfo student[], const int maxsize, char name[]);
void Withdraw_Course(studentinfo student[], const int maxsize, char id[]);
void Enter_Grades_Calculate_Gpa(studentinfo student[], const int maxsize, char id[]);
void Display_Students_Acc_To_Criteria(studentinfo student[], const int maxsize, int criteria);
void Highest_Cpa(studentinfo student[], const int maxsize);
double Highest_CPA(studentinfo student[], const int maxsize);

const int MAX = 100;
int main()
{
    int choice;
    studentinfo student[MAX];
    cout << "Welcome to the system of the University";
    do
    {
        cout << "\n1) Read a student"
            << "\n2) Return number of students"
            << "\n3) Find student"
            << "\n4) Print student details"            
            << "\n5) Withdraw course(s)"
            << "\n6) Enter grades and calculate GPA"
            << "\n7) Display students according to criteria"
            << "\n8) Highest CPA"
            << "\n9) Exit"
            << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int studentindex;
            cout << "\nEnter student's index to read his information: ";
            cin >> studentindex;
            Read_Student(student, studentindex);
            break;
        case 2:
            cout << "\nHow many students registered: "
                << How_Many_Students(student, MAX);
            break;
        case 3:
            char id[20];
            cout << "\nEnter student's ID: ";
            cin >> id;
            if ((Find_Student(student, MAX, id) == true))
            {
                cout << "\nStudent found";
            }
            else
                cout << "\nStudent not found";

            break;
        case 4:
            char name[50];
            cout << "\nEnter student's name to print his details: ";
            cin.getline(name, 50);
            Student_Details(student, MAX, name);
            break;
        case 5:
            char id[20];
            cout << "\nEnter ID of the student to withdraw his courses: ";
            cin >> id;
            Withdraw_Course(student, MAX, id);
            break;
        case 6:
            char id[20];
            cout << "\nEnter ID of the student to enter grades and calculate GPA: ";
            cin >> id;
            Enter_Grades_Calculate_Gpa(student, MAX, id);
            break;
        case 7:
            int criteria;
            cout << "Enter criteria for students to be displayed: ";
            Display_Students_Acc_To_Criteria(student, MAX,criteria);
            break;
        case 8:
            Highest_Cpa(student, MAX);
            break;
        case 9:
            cout << "\nHope to se you again!\nBye";
            break;
        default:
            cout << "\nInvalid choice, try again";
            break;
        }

    } while (choice != 11);

}

void Read_Student(studentinfo student[], int snum)
{
    do {
        student[snum].cpa = 0.0;
        cout << "Reading data for student number " << snum + 1;
        cout << "\nEnter student's name: ";
        cin.getline(student[snum].name, 50);
        cout << "\nEnter student's adress: ";
        cin.getline(student[snum].adress, 50);
        cout << "\nEnter student's phnum: ";
        cin.getline(student[snum].phnum, 20);
        cout << "\nEnter student's stid: ";
        cin.getline(student[snum].stid, 20);
        do
        {
            cout << "\nEnter student's major: ";
            cin >> student[snum].major;
            if (student[snum].major != "COMP" || student[snum].major != "DATA" || student[snum].major != "CENG" || student[snum].major != "MIS")
                cout << "Invalid major, try again.";
        } while (student[snum].major != "COMP" || student[snum].major != "DATA" || student[snum].major != "CENG" || student[snum].major != "MIS");
        do
        {
            cout << "Enter student's degree: ";
            cin >> student[snum].deg;
            if (student[snum].deg != "BSc" || student[snum].deg != "MSc")
                cout << "Invalid degree, try again.";
        } while (student[snum].deg != "BSc" || student[snum].deg != "MSc");
    } while (Already_Registered(student, MAX, snum) == false);
    Register_to_Courses(student, MAX, student[snum].stid);
}
bool Already_Registered(const studentinfo student[], const int maxsize, const int snum) 
{
    int count = 0;
    for (int i = 0; i < maxsize; i++) 
    {
        if (student[snum].name == student[i].name || student[snum].adress == student[i].adress || student[snum].phnum == student[i].phnum || student[snum].stid == student[i].stid)
            count++;
    }
    if (count > 1)
        return true;
    return false;     
}

void Register_to_Courses(studentinfo student[],const int maxsize, char stid[])
{
    for (int i = 0; i < maxsize; i++) 
    {
        if (student[i].stid == stid) 
        {
            int c = 0;
            do 
            {
                cout << "\nEnter students course code: ";
                cin >> student[i].courses[c].crscode;
                cout << "\nEnter ECTS credits for course: ";
                cin >> student[i].courses[c].ectscred;
                c++;
            } while (c < 5);
            int ectssum = 0;
            for (int j = 0; j < 5; j++) 
            {
                ectssum = ectssum + (student[i].courses[j].ectscred);
            }
            student[i].ects = ectssum;
            if (student[i].cpa > 3.0 || student[i].ects>= 204) 
            {
                cout << "\nYou were allowed to take one more course";
                cout << "\nEnter student's course code: ";
                cin >> student[i].courses[c].crscode;
                cout << "\nEnter ECTS credits for course: ";
                cin >> student[i].courses[c].ectscred;
                student[i].ects = student[i].ects + student[i].courses[c].ectscred;
            }
            student[i].crsnum = c + 1;

        }
    }
}
int How_Many_Students(const studentinfo student[], const int maxsize)
{
    int amount = 0;
    for (int i = 0; i < maxsize; i++) 
    {
        if (student[i].name[0] != '\0')
            amount++;
    }
    return amount;
}

bool Find_Student(const studentinfo student[], const int maxsize, char id[])
{
    for (int i = 0; i < maxsize; i++) 
    {
        if (student[i].stid == id)
            return true;
    }
    return false;
}

void Student_Details(const studentinfo student[], const int maxsize, char name[])
{
    int identicalstud[100];
    int samename = 0;
    int i;
    for (i = 0; i < maxsize; i++) 
    {
        if (student[i].name == name) 
        {
            identicalstud[samename] = i;
            samename++;

        }
    }
    if (samename >= 1) 
    {
        cout << "\nThere (is/are) " << samename << " student(s) named " << name;
        for (int j = 0; j < samename; j++) 
        {
            cout << "\nName: " << student[identicalstud[j]].name
                << "\nAdress: " << student[identicalstud[j]].adress
                << "\nPhone number: " << student[identicalstud[j]].phnum
                << "\nStudent ID: " << student[identicalstud[j]].stid
                << "\nMajor: " << student[identicalstud[j]].major
                << "\nDegree: " << student[identicalstud[j]].deg
                << "\nCPA: " << student[identicalstud[j]].cpa
                << "\nECTS Credits completed: " << student[identicalstud[j]].ects
                << "\nTotal Grade Points: " << student[identicalstud[j]].tgp
                << "\nStudent registered for courses: ";

            for (int k = 0; student[identicalstud[j]].courses[k].crscode != '\0'; k++)
            {
                cout << "\nCourse code: " << student[identicalstud[j]].courses[k].crscode
                    << " | " << student[identicalstud[j]].courses[k].ectscred << " ECTS credits";
            }
                
            cout << "\nNumber of current courses: " << student[identicalstud[j]].crsnum;
                
        }
    }
    else if (samename == 0) 
    {
        cout << "\nThere are no students with name: " << name;
    }
    
}

void Withdraw_Course(studentinfo student[], const int maxsize, char id[])
{
  
    int coursestodel[6];
    int count = 0;
    int todel;
    for (int i = 0; i < maxsize; i++) 
    {
        if (student[i].stid == id) 
        {
            do {
                
                cout << "\nEnter index(0 - 6) of course to delete(-1 to stop): ";
                cin >> todel;
                coursestodel[count] = todel;               
            } while (todel != -1);
            for (int j = 0; coursestodel[j] != -1; j++) 
            {
                for (int k = coursestodel[j]; student[i].courses[k].crscode != '\0'; k++)
                {
                    student[i].courses[k].crscode = student[i].courses[k + 1].crscode;
                    student[i].courses[k].ectscred = student[i].courses[k + 1].ectscred;
                }
            }

        }
    }
}

void Enter_Grades_Calculate_Gpa(studentinfo student[], const int maxsize, char id[])
{
    double GPA = 0;
    char grades[20];
    int totalgradepoints = 0;
    int i;
    for (i = 0; i < maxsize; i++) 
    {
        if (student[i].stid == id) 
        {
            for (int j = 0; student[i].courses[j].crscode != '\0'; j++) 
            {
                char grade;
                cout << "Enter grade for course: ";
                cin >> grade;
                if (grade == 'F')
                {
                    GPA = GPA + ((student[i].courses[j].ectscred) * 0);
                    student[i].ects = student[i].ects - student[i].courses[j].ectscred;
                }
                else if (grade == 'D-')
                {
                    GPA = GPA + ((student[i].courses[j].ectscred) * 0.7);
                }
                else if (grade == 'D')
                {
                    GPA = GPA + ((student[i].courses[j].ectscred) * 1);
                }
                else if (grade == 'D+')
                {
                    GPA = GPA + ((student[i].courses[j].ectscred) * 1.3);
                }
                else if (grade == 'C-')
                {
                    GPA = GPA + ((student[i].courses[j].ectscred) * 1.7);
                }
                else if (grade == 'C')
                {
                    GPA = GPA + ((student[i].courses[j].ectscred) * 2);
                }
                else if (grade == 'C+')
                {
                    GPA = GPA + ((student[i].courses[j].ectscred) * 2.3);
                }
                else if (grade == 'B-')
                {
                    GPA = GPA + ((student[i].courses[j].ectscred) * 2.7);
                }
                else if (grade == 'B')
                {
                    GPA = GPA + ((student[i].courses[j].ectscred) * 3);
                }
                else if (grade == 'B+')
                {
                    GPA = GPA + ((student[i].courses[j].ectscred) * 3.3);
                }
                else if (grade == 'A-')
                {
                    GPA = GPA + ((student[i].courses[j].ectscred) * 3.7);
                }
                else if (grade == 'A')
                {
                    GPA = GPA + ((student[i].courses[j].ectscred) * 4);
                }
                              
            }            
            student[i].gpa = GPA;
        }
    }
    
}

void Display_Students_Acc_To_Criteria(studentinfo student[], const int maxsize, int criteria)
{

    for (int i = 0; i < maxsize; i++) 
    {
        if (student[i].ects >= criteria) 
        {
            cout << "\nStudent's name: " << student[i].name
                << "\nStudent's ID: " << student[i].stid;
        }
    }
}

void Highest_Cpa(studentinfo student[], const int maxsize)
{
    for (int i = 0; i < maxsize; i++) 
    {
        if (student[i].ects >= 180) 
        {
            if (student[i].cpa == Highest_CPA(student, MAX))
                cout << "\nStudent " << i << " has the highest CPA of: " << student[i].cpa;
        }
    }
}

double Highest_CPA(studentinfo student[], const int maxsize)
{
    double min, max;
    min = student[0].cpa;
    for(int i = 0; i < maxsize; i++) 
    {
        if (student[i].cpa > student[i + 1].cpa)
            max = student[i].cpa;
        else
            min = student[i].cpa;
    }
    return max;
        
}

