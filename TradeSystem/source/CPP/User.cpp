#include "Header/User.h"

User::User(const char* userName, const char userPassword[],Address address)
{
	if (strlen(this->userPassword) >= strlen(userPassword))
	{
		strcpy(this->userPassword, userPassword);
		this->userName = strdup(userName);
		this->address = address;
	}
	else
		std::cout << "Max length of password is 10  . User is not initialized \n";
}

User::User(const User& other)
{
	if (strlen(this->userPassword) >= strlen(userPassword))
	{
		this->userName =strdup(other.userName);
		this->address = other.address;
		strcpy(this->userPassword, other.userPassword);
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
	strcpy(this->userPassword, other.userPassword);
}

void User::PrintUser()
{
	std::cout << "UserName: " << this->userName << std::endl;
	std::cout << "Password: " << this->userPassword << std::endl;
	std::cout << this->address;
}

bool User::SetUserName(char* constuserName)
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
