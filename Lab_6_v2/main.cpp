#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

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

template <typename T>
class matrix
{
private:
	T** data;
	int m;
	int n;

public:
	matrix(int m, int n) : m(m), n(n)
	{
		if (m <= 0 || n <= 0)
			throw except("Недопустимые размеры матрицы");
		data = new T*[m];
		for (int i = 0; i < m; ++i)
			data[i] = new T[n];
	}

	~matrix()
	{
		for (int i = 0; i < m; ++i)
			delete[] data[i];
		delete[] data;
	}

	void enter()
	{
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
			{
				cout << "(" << i << "," << j << ") - ";
				cin >> data[i][j];
			}
	}

	void print()
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
				cout << setw(5) << left << data[i][j] << " ";
			cout << "\n";
		}
	}

	void resize(int m, int n)
	{
		if (m <= 0 || n <= 0)
			throw except("Недопустимые размеры матрицы");
		T** temp = new T*[m];
		for (int i = 0; i < m; ++i)
			temp[i] = new T[n];
		for (int i = 0; i < (this->m < m ? this->m : m); ++i)
			for (int j = 0; j < (this->n < n ? this->n : n); ++j)
				temp[i][j] = data[i][j];
		this->m = m;
		this->n = n;
		for (int i = 0; i < m; ++i)
			delete[] data[i];
		delete[] data;
		data = temp;
	}

	T& operator()(int x, int y)
	{
		if (x < 0 || x >= m || y < 0 || y >= n)
			throw except("Координаты матрицы (" + to_string(x) + "," + to_string(y) + 
				") не соответствуют ее размеру (" + to_string(m) + "," + to_string(n) + ")");
		return data[x][y];
	}
};

int main()
{
	int m, n;
	cout << "Введите размер матрицы:\n";
	cin >> m >> n;
	matrix<int> M(m, n);

	while (true)
	{
		int a, x, y;
		cout << "\n\n1 - Заполнить матрицу\n2 - Вывести матрицу\n3 - Изменить элемент матрицы\n4 - Вывести элемент матрицы\nВыберите действие: ";
		cin >> a;
		try
		{
			switch (a)
			{
			case 1:
				M.enter();
				break;
			case 2:
				M.print();
				break;
			case 3:
				cout << "Введите координаты элемента:\n";
				cin >> x >> y;
				M(x, y);
				cout << "Введите новое значение: ";
				cin >> M(x, y);
				break;
			case 4:
				cout << "Введите координаты элемента:\n";
				cin >> x >> y;
				M(x, y);
				cout << "Значение элемента: " << M(x, y) << "\n";
				break;
			default:
				throw except("Такой номер отсутствует");
			}
		}
		catch (except e)
		{
			cout << "Произошла ошибка: " << e.message() << "\n";
		}
		catch (...)
		{
			cout << "Произошла ошибка\n";
		}
	}
}