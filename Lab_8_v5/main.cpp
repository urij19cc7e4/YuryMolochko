#include <iostream>
#include <fstream>
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
struct elem
{
	T data;
	int count;
	elem* left;
	elem* right;
};

template <typename T>
class tree
{
private:
	elem<T>* root = nullptr;
	int size = 0;

	void __clear(elem<T>** __root)
	{
		if (*__root)
		{
			__clear(&((*__root)->left));
			__clear(&((*__root)->right));
			delete *__root;
			*__root = nullptr;
		}
	}

	void __pushtree(elem<T>** __root, elem<T>* __rootold)
	{
		if (__rootold)
		{
			__pushtree(__root, __rootold->left);
			__push(__root, __rootold->data);
			__pushtree(__root, __rootold->right);
		}
	}

	void __pop(elem<T>** __elem)
	{
		if ((*__elem)->count > 1)
			(*__elem)->count = (*__elem)->count - 1;
		else
		{
			elem<T>* tmp = *__elem;
			if (tmp->left && tmp->right)
			{
				elem<T>* lost = tmp->left->right;
				*__elem = tmp->left;
				(*__elem)->right = tmp->right;
				__pushtree(__elem, lost);
				__clear(&lost);
			}
			else if (tmp->left)
				*__elem = tmp->left;
			else if (tmp->right)
				*__elem = tmp->right;
			else
				*__elem = nullptr;
			delete tmp;
		}
	}

	void __push(elem<T>** __root, const T& data)
	{
		if (*__root)
			if ((*__root)->data > data)
				__push(&((*__root)->left), data);
			else if ((*__root)->data < data)
				__push(&((*__root)->right), data);
			else
				(*__root)->count = (*__root)->count + 1;
		else
			*__root = new elem<T>{ data, 1, nullptr, nullptr };
	}

	elem<T>** __seek(elem<T>** __root, const T& data)
	{
		if (*__root)
			if ((*__root)->data > data)
				return __seek(&((*__root)->left), data);
			else if ((*__root)->data < data)
				return __seek(&((*__root)->right), data);
			else
				return __root;
		else
			throw except("Элемент не найден");
	}

	void __print(elem<T>** __root, char x)
	{
		if (*__root)
		{
			__print(&((*__root)->left), x);
			cout << (*__root)->data << x;
			__print(&((*__root)->right), x);
		}
	}

public:
	tree() {}

	~tree()
	{
		clear();
	}

	void clear()
	{
		__clear(&root);
		size = 0;
	}

	void pop(const T& data)
	{
		__pop(__seek(&root, data));
		--size;
	}

	void pop(T&& data)
	{
		__pop(__seek(&root, data));
		--size;
	}

	void push(const T& data)
	{
		__push(&root, data);
		++size;
	}

	void push(T&& data)
	{
		__push(&root, data);
		++size;
	}

	void print(char x)
	{
		__print(&root, x);
	}
};

int main()
{
	tree<double> dT;
	tree<string> sT;
	while (true)
	{
		int choose;
		double dX;
		string sX;
		std::cout << "\n\n1. Добавить число\n2. Добавить строку\n3. Удалить число\n4. Удалить строку\n" <<
			"5. Вывести числа на экран\n6. Вывести строки на экран\n7. Очистить числа\n8. Очистить строки\nВыберите действие: ";
		cin >> choose;
		try
		{
			switch (choose)
			{
			case 1:
				std::cout << "Введите число: ";
				cin >> dX;
				dT.push(dX);
				break;
			case 2:
				std::cout << "Введите строку: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, sX);
				sT.push(sX);
				break;
			case 3:
				std::cout << "Введите число: ";
				cin >> dX;
				dT.pop(dX);
				break;
			case 4:
				std::cout << "Введите строку: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, sX);
				sT.pop(sX);
				break;
			case 5:
				dT.print(' ');
				break;
			case 6:
				sT.print('\n');
				break;
			case 7:
				dT.clear();
				break;
			case 8:
				sT.clear();
				break;
			default:
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw except("Такой номер отсутствует");
			}
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
}