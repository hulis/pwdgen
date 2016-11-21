#include <iostream>
#include <string>
#include <time.h>
#include "Generator.h"
#include "Pwdgen.h"

Generator::Generator()
{
	std::string special[] = { "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", ":", ";", "<", "=", ">", "?", "@", "[", "\\", "]", "^", "_", "`", "{", "}", "~", "|" };
	char number[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char lcase[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char ucase[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
}


Generator::~Generator()
{
}

void Generator::generatePWD()
{
	Pwdgen pwd;
	int select;
	for (int i = 0; i < pwd.pwdLenght; i++)
	{
		select = rand() % 4 + 1;
		if (select == 1 && pwd.useNumber == 1)
		{
			password += number[rand() % 9 + 0];
		}
		else if (select == 2 && pwd.useLcase == 1)
		{
			password += lcase[rand() % 25 + 0];
		}
		else if (select == 3 && pwd.useUcase == 1)
		{
			password += ucase[rand() % 25 + 0];
		}
		else if (select == 4 && pwd.useSpecial == 1)
		{
			password += special[rand() % 31 + 0];
		}
		else
		{
			i--;
		}

	}
}

void Generator::printPWD()
{
	system("cls");
	std::cout << "Your super secure password: ";
	std::cout << password << std::endl;
}