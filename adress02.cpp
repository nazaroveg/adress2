// adress02.cpp 
// nazaroveg@yandex.ru

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

class address
{
public:
	address(std::string ci, std::string st, int hou, int apart) : city(ci), street(st), house(hou), apartment(apart)
	{}

	std::string get_output_address(std::string ci, std::string st, int hou, int apart)
	{
		std::string a = std::to_string(hou);
		std::string b = std::to_string(apart);
		std::string out_add = (ci + ", " + st + ", " + a + ", " + b);
		return out_add;
	}
	/*void fread(std::ifstream& fin)
	{
		fin >> city;
		fin >> street;
		fin >> house_number;
		fin >> apartment;
	}*/





private:
	std::string city, street;
	int house, apartment;
};

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	
	std::ifstream fin;
	fin.open("in.txt");
	if (!fin.is_open()) {
		std::cout << "Error: файл не открыт " << "in.txt"  << '\n';
		return -1;
	}
	int size = 0;
	fin >> size;
	if (size <= 0)
	{
		std::cout << "Ошибка: недопустимый размер  " << size << '\n';
		return -2;
	}
	
	std::string a;
	std::string b;
	int c;
	int d;
	address* add = new address[size];
	
	
	std::string a;
	std::string b;
	int c;
	int d;
	

	for (int i = 0; i < size; ++i)
	{
		fin >> a;
		fin >> b;
		fin >> c;
		fin >> d;
		add->get_output_address(a, b, c, d);

	}
	
}




