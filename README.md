# StudentManagementSystem-OOP
Overview:
This project is a Student Management System developed using Object-Oriented Programming (OOP) principles. It efficiently manages student data, including details like admission number, name, gender, standard, marks, and attendance records. The system provides functionality to add, search, display, delete, and update student records, with a focus on demonstrating core OOP concepts such as encapsulation, inheritance, and polymorphism.

Features:
Add Student Records: Easily add new student details including admission number, name, gender, standard, marks, and attendance.
Search and Display Records: Search for specific students by their admission number and display their details.
Update Attendance: Update the attendance of students, tracking the number of days present and absent.
Delete Records: Move student records to a trash file instead of permanent deletion, providing a soft delete functionality.
View Deleted Records: Review student records that have been moved to the trash.
User-Friendly Interface: Simple and intuitive console-based interface for easy interaction.

Usage:
Main Menu: Select options from the main menu to perform actions like adding, searching, displaying, deleting, or updating student records.
Attendance Management: Choose the option to update attendance by entering the student's admission number and marking them as present or absent.
Trash Management: Deleted records are not permanently removed but moved to a trash file, allowing you to review and restore them if needed.

File Structure:
studentManagementSystem.cpp - The main source code file containing the logic for the Student Management System.
Students.dat - Binary file used to store student records.
TempStud.dat - Temporary file used during record updates.
TrashStud.dat - File used to store deleted student records.

Contributing:
Contributions are welcome! Feel free to fork this repository and submit pull requests. Please ensure your changes align with the OOP principles and enhance the functionality of the system.
