// adress02.cpp 
// nazaroveg@yandex.ru

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

class address
{
public:
	

	std::string get_output_address(std::string ci, std::string st, int hou, int apart)
	{
		std::string a = std::to_string(hou);
		std::string b = std::to_string(apart);
		std::string out_add = (ci + ", " + st + ", " + a + ", " + b);
		return out_add;
	}
	void sort(std::string s_arr, int size)
	{
		std::string* arr_2 = new std::string[size]();

		for (int i = 0; i < size; ++i)
		{
			arr_2[s_arr[i]]++;
		}
		int k{};
		for (int i = 0; i < size; i++) {
			while (arr_2[i] != "\0") {
				s_arr[k] = i;
				k++;
				arr_2[i]--;
			}
		}

		delete[]arr_2;



	}


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
	
	
	address* add = new address[size];
	
	std::string a;
	std::string b;
	int c;
	int d;
	std::string* result = new std::string[size];

	for (int i = 0; i < size; ++i)
	{

		/*fin >> a;
		fin >> b;
		fin >> c;
		fin >> d;*/
		add[i] = getline(fin);

		result[i] = add->get_output_address(a, b, c, d);
	}
	add->sort(result, size);

	
	fin.close();
	
	
	
		std::cout << result << std::endl;
		
	

}




