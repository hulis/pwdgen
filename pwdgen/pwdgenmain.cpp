#include <iostream>
#include <time.h>
#include <string>

int askLenght();
int askOption();
int checkSecurity();
void printPWD(std::string salasana);

int main()
{
	int pwdLenght = 0;
	int useNumber;
	int useLcase;
	int useUcase;
	int useSpecial;
	int securityLevel = 0;
	int select = 0;
	char number[] = { '0','1','2','3','4','5','6','7','8','9' };
	char lcase[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char ucase[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	//char special[] = { '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`', '{', '}', '~', '|' };
	std::string special[] = { "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", ":", ";", "<", "=", ">", "?", "@", "[", "\\", "]", "^", "_", "`", "{", "}", "~", "|" };
	std::string password;
	//char password[] = "";

	//alustetaan satunnaislukujen generointi
	srand(time(0));

	std::cout << "Welcome to Hulis' random password generator" << std::endl;
	system("pause");
	system("cls");

	//Kysyt��n k�ytt�j�lt� salasanan pituus aliohjelmassa
	pwdLenght = askLenght();
	system("cls");
	//std::cout << pwdLenght;

	std::cout << "You have chosen " << pwdLenght << " as your password lenght." << std::endl;
	std::cout << "Next we are gonna choose options what we are gonna include in your password" << std::endl;
	system("pause");
	system("cls");

	//Toistetaan silmukkaa niin pitk��n, ett� k�ytt�j� on valinnut v�hint��n 2 vaihtoehtoa
	do
	{
		std::cout << "You must choose yes to atleast two(2) options. type [y]es or [n]o and press Enter." << std::endl;

		//Kysyt��n haluaako k�ytt�j� k�ytt�� salasanassa numeroita ja tallennetaan se muuttujaan
		std::cout << "\nUse numbers?" << std::endl;
		useNumber = askOption();
		securityLevel += useNumber;
		//std::cout << useNumber;

		//Kysyt��n haluaako k�ytt�j� k�ytt�� salasanassa pieni� kirjaimia ja tallennetaan se muuttujaan
		std::cout << "\nUse lower case letters?" << std::endl;
		useLcase = askOption();
		securityLevel += useLcase;
		//std::cout << useLcase;

		//Kysyt��n haluaako k�ytt�j� k�ytt�� salasanassa isoja kirjaimia ja tallennetaan se muuttujaan
		std::cout << "\nUse upper case letters?" << std::endl;
		useUcase = askOption();
		securityLevel += useUcase;
		//std::cout << useUcase;

		//Kysyt��n haluaako k�ytt�j� k�ytt�� salasanassa erikoismerkkej� ja tallennetaan se muuttujaan
		std::cout << "\nUse Special symbols?" << std::endl;
		useSpecial = askOption();
		securityLevel += useSpecial;
		//std::cout << securityLevel;

		if (securityLevel < 2)
		{
			std::cout << "You didn't choose enough options. Choose again!" << std::endl;
			system("pause");
			system("cls");
			securityLevel = 0;
		}
	} while (securityLevel < 2);

	//Generoidaan salasana
	for (int i = 0; i < pwdLenght; i++)
	{
		select = rand() % 4 + 1;
		if (select == 1 && useNumber == 1)
		{
			password+= number[rand() % 9 + 0];
		}
		else if (select == 2 && useLcase == 1)
		{
			password+= lcase[rand() % 25 + 0];
		}
		else if (select == 3 && useUcase == 1)
		{
			password+= ucase[rand() % 25 + 0];
		}
		else if (select == 4 && useSpecial == 1)
		{
			password+= special[rand() % 31 + 0];
		}
		else
		{
			i--;
		}

	}
	system("pause");

	printPWD(password);
	/*for (int p = 0; p < pwdLenght; p++)
	{
	std::cout << password << std::endl;
	}*/
	
}


//Salasanan pituuden kysely. Palautusarvona salasanan pituus 
int askLenght()
{
	int pwdLenght;
	do
	{
		std::cout << "Choose password lenght between 8-25. Type lenght in numbers and press Enter" << std::endl;
		std::cin >> pwdLenght;

		if (pwdLenght < 8)
		{
			system("cls");
			std::cout << "Minimum password lenght not met. Too insecure!" << std::endl;
			system("pause");
			system("cls");
		}
		else if (pwdLenght > 25)
		{
			system("cls");
			std::cout << "Password lenght too long. You probably forget your password!" << std::endl;
			system("pause");
			system("cls");
		}

	} while (pwdLenght < 8 || pwdLenght > 25);
	return pwdLenght;
}


//Kysely aliohjelma kysyy k�ytt�j�n valinnan y/n ja palauttaa valintaa vastaavan arvon y=1, n=0
int askOption()
{
	int userChoise = 0;
	char keyInput;
	std::cin >> keyInput;
	if (keyInput == 'y')
	{
		userChoise = 1;
	}
	else if (keyInput == 'n')
	{
		userChoise = 0;
	}
	else
	{
		userChoise = 0;
	}
	return userChoise;

}

void printPWD(std::string salasana)
{
	system("cls");
	std::cout << "Your super secure password: ";
	std::cout << salasana << std::endl;
}