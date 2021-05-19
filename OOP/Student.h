#pragma once
#include"Libraries.h"
#include"User.h"

class Student:public User
{
public:
    //constructor
	Student() {
		rollNumber = 0;
		firstName = "";
		lastName = "";
		password = "";
		userName = "";
		this->totalCourses = 0;
	}

	//constructor to add new students
	Student(int rollNumber, string status, string firstName, string lastName, string password, string userName):User(firstName, lastName,password,userName){
		this->rollNumber = rollNumber;
		for (int i = 0; i < this->status->length(); i++)
		{
			if (this->status[i] == status) {
				this->statusSet = status;
				break;
			}
			else {
				this->statusSet = "";
			}

		}
		this->totalCourses = 0;
	}

	

	~Student();  //destructor


	//member functions
	void setRollNumber(int);
	void setStatus(string);

	int getRollNumber();
	string getStatus();

	//enroll the course 
	bool enrollCourse(Course c) {
		bool check = false;
		if (totalCourses <= 6) {   //max. 6 courses enroll per student
			for (int i = 0; i < totalCourses; i++) //check for already enrolled or not
			{
				if (course[i].getCourseCode() == c.getCourseCode()) {
					cout << "\nCourse already enrolled\n";
					check = true;
					break;
				}
			}
			if (check == false) {
				course[totalCourses] = c; //course added
				course[totalCourses].setEnrolledStudents(getFirstName() + " " + getLastName());
				return true;
			}
			else {
				return false;  //already added, can't add now
			}
		}
		else {
			cout << "You have enrolled maximum courses\n";
			return false;
		}
	}

	//set obtained marks to his/her course assignment, it'll just add instructor, and didn't access student
	void setObtainedMarks(int marks, int assignmentNo, Course c) {
		int chk = checkCourseEnrolled(c);
		if (chk > -1) {
			if (course[chk].getCountAssignment() >=assignmentNo) {
				this->obtainedMarks[assignmentNo][0] = marks;
				cout << "Set Obtained Marks Successfully" << endl;
			}
		}
		else {
			cout << "Course not found" << endl;
		}
		
	}

	//student view his/her marks course
	void viewMarks(Course c) {
		int chk = checkCourseEnrolled(c);
		if (chk > -1) {
			int chkAssignments = course[chk].getCountAssignment();
			if (chkAssignments > 0) {
				cout << "Marks of assignment wise: \n";
				for (int i = 0; i < chkAssignments; i++)
				{
					cout << i + 1 << ": " << obtainedMarks[i][0] << endl;
				}
			}
			else {
				cout << "No assignment found\n";
			}
		}
		else {
			cout << "Course not enrolled\n";
		}
	}

	//he/she will view all the resources of course
	void viewResources(Course c) {
		int chk = checkCourseEnrolled(c);
		if (chk > -1) {
			if (course[chk].getResources() != "") {
				cout << "Here is the resources of " << course[chk].getCourseName() << endl;
				course[chk].getResources();
			}
			else {
				cout << "No resource added\n";
			}
		}
		else {
			cout << "Course not enrolled\n";
		}
	}

	//check the student it may enrolled or not
	int checkCourseEnrolled(Course c) {
		for (int i = 0; i < totalCourses; i++)
		{
			if (course[i].getCourseCode() == c.getCourseCode()) {
				return i;
			}
		}
		return -1;
	}

	//get marks of course
	int getMarks(Course c) {
		int chk = checkCourseEnrolled(c);
		if (chk>-1) {
			return obtainedMarks[chk][0];
		}
		return 0;
	}

	//view the rosters of course
	void viewRoster(Course c) {
		int chk = checkCourseEnrolled(c);
		if (chk > -1) {
			cout << "Instructor of Course: " << course[chk].getInstructorName() << endl;
			cout << "\nList of Students enrolled in " << course[chk].getCourseName() << endl;
			cout << course[chk].getEnrolledStudents() << endl;
		}
		else {
			cout << "Course not enrolled\n";
		}
	}

	//view all the assignments of course
	void viewAssignmentsOfCourse(Course c) {
		int chk = checkCourseEnrolled(c);
		if (chk > -1) {
			if (course[chk].getAssignments() != "") {
				cout << course[chk].getAssignments() << endl;
			}
			else {
				cout << "No assignment exist\n";
			}
		}
		else {
			cout << "\nCourse not enrolled\n";
		}
	}



	//member  from abstract
	void getProfile();

private:
	//member variables
	int rollNumber;
	string status[4] = { "freshman", "sophomore", "junior", "senior" };
	string statusSet;
	unsigned int totalCourses;
	Course course[6];   //max. 6 courses added per student
	int obtainedMarks[][1];
};

Student::~Student()
{
	//delete[]course;
}

//definition
void Student::setRollNumber(int rollNumber) {
	if (rollNumber != 0) {
		this->rollNumber = rollNumber;
	}
	else {
		cout << "\nField is empty\n";
		this->rollNumber = 0;
	}
}

//set the status of student
void Student::setStatus(string status) {
	for (int i = 0; i < this->status->length(); i++)
	{
		if (this->status[i] == status) {
			this->statusSet = status;
			break;
		}
		else {
			this->statusSet = "";
		}
	}
	
}

int Student::getRollNumber() {
	return this->rollNumber;
}

string Student::getStatus() {
	if (this->statusSet != "") {
		return this->statusSet;
	}
	else {
		return ("No Status");
	}
}


//abstract member,, override
//function definition, because in abstract class, this function has no its definition
//if getprofile() is not in student or instructor so this class will called abstract class and we didn't make the object
void Student::getProfile() {
	cout << getFirstName() + " " + getLastName() << " is a " << getStatus() << " student at LUMS\n";
}
