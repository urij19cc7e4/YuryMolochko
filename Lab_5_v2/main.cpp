#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template <typename T>
T f(const T* arr, int len)
{
	T t = arr[0];
	for (int i = 1; i < len; ++i)
		if (t < arr[i])
			t = arr[i];
	return t;
}

char f(const char* str)
{
	char c = str[0];
	for (int i = 1; str[i]; ++i)
		if (c < str[i])
			c = str[i];
	return c;
}

int main()
{
	int* arr, len;
	cout << "Введите длину массива чисел: ";
	cin >> len;
	arr = new int[len];
	cout << "Введите массив чисел:\n";
	for (int i = 0; i < len; ++i)
	{
		cout << "#" << std::setw(3) << std::left << i + 1 << " - ";
		cin >> arr[i];
	}
	cout << "Наибольшее число: " << f(arr, len) << "\n";


	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string str;
	cout << "Введите строку: ";
	getline(cin, str);
	cout << "Символ с наибольшим кодом: " << f(str.c_str()) << "\n";
}