#pragma once
#include"Libraries.h"
#include"Student.h"
#include"Course.h"

class Instructor:public User
{
public:
	   //constructor to add new instructor
	Instructor(string designation, string qualification, int instructorCode, string firstName, string lastName, string password, string userName) :User(firstName, lastName, password, userName) {
		this->designation = designation;
		this->qualification = qualification;
		if (instructorCode > 0) {
			this->instructorCode = instructorCode;
		}
		else {
			this->instructorCode = 0;
			cout << "Invalid Instructor Code\n";
		}
	}

	//by default constructor to make pointer on another classes
	Instructor() {
		this->designation = "";
		this->qualification = "";
		
		this->instructorCode = 0;
			
	}
	~Instructor();  //destructor


	//member functions, setter getter
	string getDesignation() {
		this->designation;
	}
	string getQualification() {
		this->qualification;
	}
	int getInstructorCode() {
		return this->instructorCode;
	}

	//member  from abstract
	void getProfile();
	//find the student it enrolled or not just check
	int findStudent(Student std, Course c) {
		for (int i = 0; i < c.getTotalStudents(); i++)
		{
			if (student[i].getRollNumber()==std.getRollNumber()) {
				if (std.checkCourseEnrolled(c) > 0) {
					return i;
				}
				
			}
		}
		return -1;
	}
	
	//add the marks to student of his course
	void addMarks(Student std, int marks, Course c, int assNo) {
		unsigned int chk = findStudent(std, course);
		if (chk >= 0) {
			student[chk].setObtainedMarks(marks, assNo, c);
			cout << "Marks added successfully" << endl;
		}
		else {
			cout << "\nStudent not found\n";
		}
	}
	//view marks of all students of that course which instructor teach
	void viewMarks(Course c) {
		cout << "Marks of all students: \n";
		for (int i = 0; i < course.getTotalStudents(); i++)
		{
			cout << "RollNo.: " << student[i].getRollNumber() << "\tMarks: " << student[i].getMarks(c) << endl;
		}
	}

	//add the resource of course that teach instructor
	void addResource(string res) {
		course.setResources(res);
	}
	//view resources
	void viewResource() {
		cout << "Resource of " << course.getCourseName() << ": \n";
		cout << course.getResources() << endl;
	}

	//view rosters, show all the students in course and instructor name
	void viewRoster() {
		cout << "Course: " << course.getCourseName() << ", Instructor Name: " << course.getInstructorName() << endl;
		cout << course.getEnrolledStudents() << endl;
	}
	//add the new assignment in that course which instructor teach
	void addAssignment(string assignmentName, string dueDate, int totalMarks) {
		course.addAssignment(assignmentName, dueDate, totalMarks);
	}
	//view all assignment of course which instructor teach
	void viewAssignment() {
		cout << "Assignments of " << course.getCourseName() << " course are: \n" << course.getAssignments();
	}

private:
	//member variables
	string designation, qualification;
	int instructorCode;
	Course course;
	Student *student;
};


Instructor::~Instructor()
{
	delete student;  //free the space after deleting instructor
}

void Instructor::getProfile() {
	cout << getFirstName() + " " + getLastName() << " is " << getDesignation() << " at LUMS\n";
}