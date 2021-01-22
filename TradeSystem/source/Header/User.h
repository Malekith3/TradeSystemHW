#ifndef __USER_H
#define __USER_H
#include <iostream>
class User
{
protected:
	char* userName;
	char userPassword[10];
	
public:
	//***************************Constructors*************************************
	User(const char* userName, const char userPassword[]);
	User() {  };
	//***************************Copy Ctor****************************************
	User(const User& other);
	//***************************Destructor***************************************
	virtual ~User();
	//***************************Operators****************************************
	User& operator=(const User& other);
	//***************************Getters & Setters********************************
	virtual bool SetUserName(char* const userName);
	virtual bool SetPassword(const char userPassword[], const char* key);
	virtual const char* GetUserName() const;
	virtual char* GetPassword();
	//***************************Methods******************************************
	virtual void PrintUser();
	//****************************************************************************
};
#endif


