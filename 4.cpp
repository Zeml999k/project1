#include <iostream>
#include <fstream>

void Pass(int resulT, std::ofstream& Regist, std::ifstream& confirm)
{
	int count = 0;
	Regist.open("register.txt", std::ios::app | std::ios::out);
	confirm.open("register.txt", std::ios::in);
	std::string log, pass;
	if(!Regist && !confirm)
	{
		std::cout << "файл не открыт" << std::endl;
	}
	if(resulT == 1)
	{
		std::cout << "введите логин: " << std::endl;
		std::cin >> log;
		std::cout << "введите пароль: " << std::endl;
		std::cin >> pass;
		while(!confirm.eof())
		{
			std::string str = "";
			std::getline(confirm, str);
			if(str == log)count++;
			if(str == pass)count++;
		}
			if(count == 2) std::cout << "вы вошли в систему!" << std::endl;
			else std::cout << "неправильный логин или пароль!" << std::endl;


	}
	else
	{
		std::cout << "придумайте логин: " << std::endl;
		std::cin >> log;
		std::cout << "придумайте пароль: " << std::endl;
		std::cin >> pass;
		Regist << log << "\n" << pass << "\n\n";
	}
	Regist.close();
	confirm.close();
}

int main()
{
	int rezult;
	std::ofstream registeR;
	std::ifstream Conf;
	std::cout << "Press 1.Вход\n " << "\t2.Регистрация" << std::endl;
	std::cin >> rezult;
	Pass(rezult, registeR, Conf);
	return 0;
}
