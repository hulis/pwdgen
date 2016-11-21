#pragma once
class Pwdgen
{
public:
	Pwdgen();
	~Pwdgen();

	void askLenght();
	void askOption();
	void checkSecurity();
	void menu();
	void optionCounter();
	int pwdLenght = 0;
	int useNumber = 0;
	int useLcase = 0;
	int useUcase = 0;
	int useSpecial = 0;

private:
	int securityLevel = 0;
	int select = 0;
	int userChoise = 0;
};

