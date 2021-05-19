#pragma once
#include"Libraries.h"
#include"Instructor.h"
//assignment class
class Assignment
{
public:
	Assignment(string assignmentName, string dueDate, int totalMarks) {   //constrcutor for create new assignment 
		this->assignmentName = assignmentName;
		this->dueDate = dueDate;
		this->totalMarks = totalMarks;
	}

	Assignment() {    //constructor for create by default due to others classes to make pointer of assignment
		this->assignmentName = "";
		this->dueDate = "";
		this->totalMarks = 0;
	}

	void setDueDate(string dueDate) {    //for update dueDate if need
		this->dueDate = dueDate;
	}

	string getAssignmentName() {
		return this->assignmentName;
	}
	string getDueDate() {
		return this->dueDate;
	}
	int getTotalMarks() {
		return this->totalMarks;
	}

	
	~Assignment();     //destructor

private:
	string assignmentName, dueDate;
	int totalMarks;
};

Assignment::~Assignment()
{
}


//course class
class Course
{
public:
	  //constructor
	Course() {      //by default constructor for make a pointer on another classes 
		this->courseName = "";
		this->courseCode = "";
		this->offeringSchool = "";
		this->countAssignment = 0;
		this->totalStudents = 0;
		this->enrolledStudents = "";
	}
	Course(string, string, string, int, Instructor);    //for creating new courses
	~Course();  //destructor


	//member functions
	void setCourseName(string courseName) {   //setter functions
		this->courseName = courseName;
	}
	void setCourseCode(string courseCode) {
		this->courseCode = courseCode;
	}
	void setOfferingSchool(string offeringSchool) {
		this->offeringSchool = offeringSchool;
	}
	void setCapacity(int capacity) {
		if (capacity >= 0) {
			this->capacity = capacity;
		}
		else {
			this-> capacity = 0;
			cout << "\nInvalid Capacity\n";
		}
	}

	string getCourseName() {    //getter function
		return this->courseName;
	}
	string getCourseCode() {
		return this->courseCode;
	}
	string getOfferingSchool() {
		return this->offeringSchool;
	}
	int getCapacity() {
		return this->capacity;
	}

	//count the assignment of each courses for iteration on view assignment
	int getCountAssignment() {
		return this->countAssignment;
	}

	//get total students enrolled in course
	int getTotalStudents() {
		return this->totalStudents;
	}
	//when assignemnt create it increase by 1 to check how many assignments in course
	void setCountAssignment() {
		this->countAssignment++;
	}
	//if we display the list of enrolled students so just call the function to print all the students name
	void setEnrolledStudents(string name) {      
		this->enrolledStudents += (name + "\n");
		totalStudents++;
	}
	//get number of enrolled students
	string getEnrolledStudents() {
		this->enrolledStudents;
	}
	//set resources, it will concatenate the resources, it just display all the resources when instructor create
	void setResources(string res) {
		resources += (res + "\n");
	}
	//get resource
	string getResources() {
		return this->resources;
	}
	//set the instructor name if change instrcutor of course
	void setInstructorName(Instructor inst) {
		this->instructor = inst;
	}

	//display the instructure name for roster
	string getInstructorName() {
		string str = "";
		str = instructor.getFirstName() + " " + instructor.getLastName();
	}

	//add new assignment of course
	void addAssignment(string assignmentName, string dueDate, int totalMarks) {
		Assignment* temp = new Assignment(assignmentName, dueDate, totalMarks);
		ass = temp;
		countAssignment++;
		cout << "Assignment added successfully" << endl;
	}
	//get the assignment detail
	string getAssignments() {
		string temp = "";
		if (countAssignment > 0) {
			stringstream ss;
			string numtemp = "";
			for (int i = 0; i < countAssignment; i++)
			{
				ss << ass[i].getTotalMarks();
				ss >> numtemp;
				temp = temp + ("Assignment Name: " + ass[i].getAssignmentName() + "\nDue Date: " + ass[i].getDueDate() + "\nTotal Marks: " + numtemp + "\n");
			}
			return temp;
		}
		else {
			return temp;
		}
	}


private:
	//member variables
	string courseName, courseCode, offeringSchool;
	unsigned int capacity;

	string resources;
	string enrolledStudents;
	int countAssignment;
	int totalStudents;
	Assignment *ass;   //assignments for course, make pointer to point multiple assignments
	Instructor instructor;  //a course has one instructor
};


//definition of constructor to add new course
Course::Course(string courseName, string courseCode, string offeringSchool, int capacity, Instructor instructor)
{
	this->courseName = courseName;
	this->courseCode = courseCode;
	this->offeringSchool = offeringSchool;
	if (capacity >= 0) {
		this->capacity = capacity;
	}
	else {
		this->capacity = 0;

		cout << "\nInvalid Capacity\n";
	}
	this->countAssignment = 0;
	this->totalStudents = 0;
	this->enrolledStudents = "";
	this->instructor = instructor;
	
}

//destructor
Course::~Course()
{
	delete ass;   //delete the assignment pointer if course deleted
}