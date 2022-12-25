#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "Header.h"

using namespace std;

string in = "input";
string out = "output";

class except
{
private:
	string error;

public:
	except(string error) : error(error) {}

	string message()
	{
		return error;
	}
};

int count_words(string& str)
{
	int count = 0;
	const char* __str = str.c_str();
	bool letter = false;
	while (*__str)
	{
		if (*__str != ' ')
			letter = true;
		else if (letter)
		{
			letter = false;
			++count;
		}
		++__str;
	}
	if (letter)
		++count;
	return count;
}

int main()
{
	try
	{
		int i = 0;
		int count;
		string str;
		ifstream fin;
		ofstream fout;
		try
		{
			fin.open(in, ios_base::in);
			cout << "Файл входных данных открыт\n";
		}
		catch (...)
		{
			throw except("Нет доступа к файлу входных данных\n");
		}
		try
		{
			fout.open(out, ios_base::out);
			cout << "Файл выходных данных открыт\n";
		}
		catch (...)
		{
			throw except("Нет доступа к файлу выходных данных\n");
		}
		while (!fin.eof())
		{
			++i;
			getline(fin, str);
			count = count_words(str);
			fout << count_words(str) << '\n';
			cout << "Обработана " << i << "-ая строка входного файла. Найдено слов: " << count << "\n";
		}
		fin.close();
		fout.close();
	}
	catch (except e)
	{
		std::cout << "Произошла ошибка: " << e.message() << "\n";
	}
	catch (...)
	{
		std::cout << "Произошла ошибка\n";
	}
}