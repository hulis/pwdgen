#pragma once
class Generator
{
public:
	Generator();
	~Generator();
	void generatePWD();
	void printPWD();

private:
	std::string special[32];
	char number[10];
	char lcase[26];
	char ucase[26];
	std::string password;
};

