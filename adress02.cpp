// adress02.cpp 
// nazaroveg@yandex.ru

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>


class address
{
public:
	address (){city, street, house, apartment;}
	
	std::string get_output_address(std::string ci, std::string st, int hou, int apart)
	{
		std::string a = std::to_string(hou);
		std::string b = std::to_string(apart);
		std::string out_add = (ci + ", " + st + ", " + a + ", " + b);
		return out_add;
	}
	
	void set(std::string ci, std::string st, int hou, int apart)
	{
		city = ci, street = st, house = hou; apartment = apart;
	}
	void sort(address *arr, int size )
	{
		

		address* arr_2 = new address[size]();

		for (int i = 0; i < size; ++i)
		{
			arr_2[arr[i]]++;
		}
		int k{};
		for (int i = 0; i < size; i++) {
			while (arr_2[i] != ' ') {
				arr[k] = i;
				k++;
				arr_2[i]--;
			}
		}

		delete[]arr_2;
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
		add[i].set(a, b, c, d);	

	}
	fin.close();
	adr.sort(add, size);
	


}




