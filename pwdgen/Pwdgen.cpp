#include <iostream>
#include <time.h>
#include <string>
#include "Pwdgen.h"
#include "Generator.h"


Pwdgen::Pwdgen()
{
}


Pwdgen::~Pwdgen()
{
}

void Pwdgen::askLenght()
{
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
	system("cls");
}

void Pwdgen::optionCounter()
{
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
}

void Pwdgen::askOption()
{
	//Toistetaan silmukkaa niin pitk‰‰n, ett‰ k‰ytt‰j‰ on valinnut v‰hint‰‰n 2 vaihtoehtoa
	do
	{
		std::cout << "You must choose yes to atleast two(2) options. type [y]es or [n]o and press Enter." << std::endl;

		//Kysyt‰‰n haluaako k‰ytt‰j‰ k‰ytt‰‰ salasanassa numeroita ja tallennetaan se muuttujaan
		std::cout << "\nUse numbers?" << std::endl;
		askOption();
		useNumber = userChoise;
		securityLevel += useNumber;
		//std::cout << useNumber;

		//Kysyt‰‰n haluaako k‰ytt‰j‰ k‰ytt‰‰ salasanassa pieni‰ kirjaimia ja tallennetaan se muuttujaan
		std::cout << "\nUse lower case letters?" << std::endl;
		askOption();
		useLcase = userChoise;
		securityLevel += useLcase;
		//std::cout << useLcase;

		//Kysyt‰‰n haluaako k‰ytt‰j‰ k‰ytt‰‰ salasanassa isoja kirjaimia ja tallennetaan se muuttujaan
		std::cout << "\nUse upper case letters?" << std::endl;
		askOption();
		useUcase = userChoise;
		securityLevel += useUcase;
		//std::cout << useUcase;

		//Kysyt‰‰n haluaako k‰ytt‰j‰ k‰ytt‰‰ salasanassa erikoismerkkej‰ ja tallennetaan se muuttujaan
		std::cout << "\nUse Special symbols?" << std::endl;
		askOption();
		useSpecial = userChoise;
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

}

void Pwdgen::menu()
{
	std::cout << "Welcome to Hulis' random password generator" << std::endl;
	system("pause");
	system("cls");

	//Kysyt‰‰n k‰ytt‰j‰lt‰ salasanan pituus
	askLenght();
	std::cout << "You have chosen " << pwdLenght << " as your password lenght." << std::endl;

	//Kysyt‰‰n salasanan rakenne
	std::cout << "Next we are gonna choose options what we are gonna include in your password" << std::endl;
	system("pause");
	system("cls");

	//Generoidaan salasana
	Generator pwd;
	pwd.generatePWD();

	system("pause");

	//Tulostetaan salasana
	pwd.printPWD();
}
