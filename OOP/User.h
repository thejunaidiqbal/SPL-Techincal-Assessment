#pragma once
#include"Libraries.h"

//abstract class
class User
{
public:
	User(string, string, string, string);
	User();
	~User();
	//member functions
	virtual void getProfile() = 0;   //pure virtual function.. now abstract class don't make object

	void setFirstName(string);    // for overriding
	void setLastName(string);
	void setPassword(string);
	void setUserName(string);

	string getFirstName();
	string getLastName();
	string getPassword();
	string getUserName();

	bool setSignIn(string, string);    //overriding 
	bool setSignOut();
	

protected:
	//members variable
	string firstName, lastName, password, userName;
	bool signin, signout;
};

User::User() {
	this->firstName = "";
	this->lastName = "";
	this->password = "";
	this->userName = "";
}

User::User(string firstName, string lastName, string password, string userName) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->password = password;
	this->userName = userName;
}

//members function definition

bool User::setSignIn(string userName, string password) {
	if (this->userName==userName&& this->password==password)
	{
		this->signin = true;
		return this->signin;  //successfully signin
	}
	else {
		this->signin = false;
		return this->signin;    //incorrect authentication (username & password)
	}
}
bool User::setSignOut() {
	if (this->signin==true)
	{
		this->signin = false;
		return true;    //signout successfully
	}
	else {
		return false;   //if user already signout
	}
}


void User::setFirstName(string firstName) {
	this->firstName = firstName;
}
void User::setLastName(string lastName) {
	this->lastName = lastName;
}
void User::setPassword(string password) {
	this->password = password;
}
void User::setUserName(string userName) {
	this->userName = userName;
}

string User::getFirstName() {
	return this->firstName;
}
string User::getLastName() {
	return this->lastName;
}
string User::getPassword() {
	return this->password;
}
string User::getUserName() {
	return this->userName;
}