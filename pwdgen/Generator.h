#pragma once
class Generator
{
public:
	Generator();
	~Generator();
	void generatePWD(int l, int un, int ul, int uu, int us);
	void printPWD();

private:
	std::string password;
	int pwdLenght = 0;
	int useNumber = 0;
	int useUcase = 0;
	int useLcase = 0;
	int useSpecial = 0;
};

