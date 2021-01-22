#include "Header/User.h"

User::User(const char* userName, const char userPassword[])
{
	if (strlen(this->userPassword) >= strlen(userPassword))
	{
		strcpy(this->userPassword, userPassword);
		this->userName = strdup(userName);
	}
	else
		std::cout << "Max length of password is 10  . User is not initialized \n";
}

User::User(const User& other)
{
	if (strlen(this->userPassword) >= strlen(userPassword))
	{
		this->userName =strdup(other.userName);
		//strcpy(this->userPassword, other.userPassword); //Alex thinks it's unnecessary- if there's a problem lower his grade only!
	}
	else
		std::cout << "Max length of password is 10  . User is not initialized \n";
	
}

User::~User()
{
	delete[] this->userName;
}

User& User::operator=(const User& other)
{
	if (this == &other)
		return *this;
	
	this->userName = strdup(other.userName);
	//strcpy(this->userPassword, other.userPassword); //Alex thinks it's unnecessary- if there's a problem lower his grade only!
}

void User::PrintUser()
{
	std::cout << "UserName: " << this->userName << std::endl;
	//std::cout << "Password: " << this->userPassword << std::endl; //Alex thinks it's unnecessary- if there's a problem lower his grade only!
}

bool User::SetUserName(char* const userName)
{
	delete[] this->userName;
	this->userName = strdup(userName);
	if (this->userName)
		return true;
	
	return false;
}

bool User::SetPassword(const char userPassword[], const char* key)
{
	if (!strcmp(this->userPassword, key) && strlen(this->userPassword) >= strlen(userPassword))
	{
		strcpy(this->userPassword, userPassword);
		std::cout << "Password is changed \n";
		return true;
	}
	else
	{
		std::cout << "key need to be previous password ! please enter the right one \n ";
		return false;
	}
}

const char* User::GetUserName() const
{
	return this->userName;
}

char* User::GetPassword()
{
	return this->userPassword;
}
