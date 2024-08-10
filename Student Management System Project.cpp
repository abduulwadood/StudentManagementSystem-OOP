#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Attendance
{
  public:
    int presentCount;
  int absentCount;

  Attendance(): presentCount(0), absentCount(0) {}
};

class Student
{
  int admno;
  char name[20];
  char gender;
  int std;
  float marks;
  float percentage;
  Attendance attendance;

  public:
    void getData();
  void display();
  int getAdmno()
  {
    return admno;
  }

  void updateAttendance(bool present);
};

void updateAttendanceData()
{
  int n, flag = 0;
  ifstream fin;
  ofstream fout;

  fin.open("Students.dat", ios:: in | ios::binary);
  fout.open("TempStud.dat", ios::out | ios::binary);

  Student s;
  cout << "Enter Admission Number you want to update attendance for: ";
  cin >> n;

  int present;
  cout << "Enter 1 for present, 0 for absent: ";
  cin >> present;

  while (fin.read((char*) &s, sizeof(s)))
  {
    if (n == s.getAdmno())
    {
      s.updateAttendance(present == 1);

      flag++;
    }

    fout.write((char*) &s, sizeof(s));
  }

  fout.close();
  fin.close();

  if (flag == 0)
    cout << "The Admission No. " << n << " not found....\n\n";
  else
  {
    remove("Students.dat");
    rename("TempStud.dat", "Students.dat");
  }
}

void Student::updateAttendance(bool present)
{
  if (present)
  {
    attendance.presentCount++;
  }
  else
  {
    attendance.absentCount++;
  }
}

void Student::getData()
{
  cout << "\n\nEnter Student Details......\n";
  cout << "Enter Admission No.     : ";
  cin >> admno;
  cout << "Enter Full Name         : ";
  cin.ignore();
  cin.getline(name, 20);
  cout << "Enter Gender (M/F)      : ";
  cin >> gender;
  cout << "Enter Standard          : ";
  cin >> std;
  cout << "Enter Marks (out of 500): ";
  cin >> marks;
  cout << endl;
  percentage = marks *100.0 / 500.00;
}

void Student::display()
{
  cout << "\n\n.......Student Details......\n";
  cout << "Admission No.     : " << admno << endl;
  cout << "Full Name         : " << name << endl;
  cout << "Gender            : " << gender << endl;
  cout << "Standard          : " << std << endl;
  cout << "Marks (out of 500): " << marks << endl;
  cout << "Percentage        : " << percentage << endl;
  cout << "Present Count     : " << attendance.presentCount << endl;
  cout << "Absent Count      : " << attendance.absentCount << endl;
  cout << endl;
}

void addData()
{
  ofstream fout;
  fout.open("Students.dat", ios::binary | ios::out | ios::app);
  Student s;
  s.getData();
  fout.write((char*) &s, sizeof(s));
  fout.close();
  cout << "\n\nData Successfully Saved to File....\n";
}

void displayData()
{
  int n,flag;	
  ifstream fin;
  fin.open("Students.dat", ios:: in | ios::binary);
  Student s;
  cout << "Enter Admission Number you want to search : ";
  cin >> n;

  while (fin.read((char*) &s, sizeof(s)))
  {
    if (n == s.getAdmno())
    {
      cout << "The Details of Admission No. " << n << " shown herewith:\n";
      s.display();
      flag++;
    }
  }
}


void searchData()
{
  int n, flag = 0;
  ifstream fin;
  fin.open("Students.dat", ios:: in | ios::binary);
  Student s;
  cout << "Enter Admission Number you want to search : ";
  cin >> n;

  while (fin.read((char*) &s, sizeof(s)))
  {
    if (n == s.getAdmno())
    {
      cout << "The Details of Admission No. " << n << " shown herewith:\n";
      s.display();
      flag++;
    }
  }

  fin.close();
  if (flag == 0)
    cout << "The Admission No. " << n << " not found....\n\n";
  cout << "\n\nData Reading from File Successfully Done....\n";
}

void deleteData()
{
  int n, flag = 0;
  ifstream fin;
  ofstream fout;
  ofstream tout;

  fin.open("Students.dat", ios:: in | ios::binary);
  fout.open("TempStud.dat", ios::out | ios::binary);
  tout.open("TrashStud.dat", ios::out | ios::app | ios::binary);

  Student s;
  cout << "Enter Admission Number you want to move to Trash : ";
  cin >> n;

  while (fin.read((char*) &s, sizeof(s)))
  {
    if (n == s.getAdmno())
    {
      cout << "The Following Admission No. " << n << " has been moved to Trash:\n";
      s.display();
      tout.write((char*) &s, sizeof(s));
      flag++;
    }
    else
    {
      fout.write((char*) &s, sizeof(s));
    }
  }

  fout.close();
  tout.close();
  fin.close();

  if (flag == 0)
    cout << "The Admission No. " << n << " not found....\n\n";
  else
  {
    remove("Students.dat");
    rename("TempStud.dat", "Students.dat");
  }
}

void getTrash()
{
  ifstream fin;
  fin.open("TrashStud.dat", ios:: in | ios::binary);
  Student s;
  cout << "\nRecords in the trash are:\n";
  while (fin.read((char*) &s, sizeof(s)))
  {
    s.display();
  }

  fin.close();
}

int main()
{
  int choice;
  system("cls");
  while (1)
  {
    cout << endl << "-------------------------------";
    cout << endl << "STUDENT RECORD MANAGEMENT SYSTEM";
    cout << endl << "-------------------------------";
    cout << endl << "1. Add Record";
    cout << endl << "2. Display Records";
    cout << endl << "3. Search Record";
    cout << endl << "4. Delete Record";
    cout << endl << "5. View Deleted Records";
    cout << endl << "6. Exit";
    cout << endl << "7. Update Attendance";
    cout << endl << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
      case 1:
        addData();
        break;
      case 2:
        displayData();
        break;
      case 3:
        searchData();
        break;
      case 4:
        deleteData();
        break;
      case 5:
        getTrash();
        break;
      case 6:
        exit(0);
        break;
      case 7:
        updateAttendanceData();
        break;
      default:
        cout << "Invalid Choice!";
        break;
    }
  }

  return 0;
}
