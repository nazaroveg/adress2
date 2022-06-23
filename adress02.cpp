﻿// adress02.cpp 
// nazaroveg@yandex.ru

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <algorithm>

class address
{
public:
	address(std::string, std::string, int, int) { }
	address(){}
	
	
	std::string get_output_address(std::string ci, std::string st, int hou, int apart) 
	{
		std::string a = std::to_string(hou);
		std::string b = std::to_string(apart);
		std::string out_add = (ci + ", " + st + ", " + a + ", " + b);
		return out_add;
	}
	void set_all(std::string ci, std::string st, int hou, int apart)
	{
		city = ci;
		street = st;
		house = hou;
		apartment = apart;
	}
	
	
private:
	std::string city = {0}, street = {0};
	int house = 0; int apartment = 0;
};




int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	
	std::ifstream fin;
	fin.open("in.txt");
	if (!fin.is_open()) 
	{
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
	
	
	address* add = new address[size];
	address adr;
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
	
		//add[i].set_all(a, b, c, d);
	add[i].get_output_address(a, b, c, d);
	}
	fin.close();
	
	address* temp = new address[1];
	
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (&add[j] > &add[j + 1]) {
				
				*temp = add[j];
				add[j] = add[j + 1];
				add[j + 1] = *temp;
			}
		}
	}
	delete[] temp;
	
	
	
	
	std::ofstream fout;
	fout.open("out.txt");
	if (!fout.is_open()) 
	{
		std::cout << "Error: unable to open file " << "out.txt" << " for writing" << '\n';
		return -3;
	}
	fout << size << std::endl;

	

	for (int i = 0; i < size; ++i)
	{		
		fout << &add[i] << std::endl;
		
	}

	fout.close();
	delete[] add;
	
}




