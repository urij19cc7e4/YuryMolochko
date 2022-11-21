#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

string bin_file = "bin.txt";
string txt_file = "txt.txt";

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

class employee
{
	friend ostream& operator<<(ostream& f, const employee& o);
	friend istream& operator>>(istream& f, employee& o);

private:
	string name;
	string post;
	int age;

public:
	employee(string name, string post, int age) : name(name), post(post), age(age) {}

	bool check_name(string _name)
	{
		return !name.compare(_name);
	}

	void from_bin(ifstream& f)
	{
		try
		{
			f.read((char*)this, sizeof(*this));
		}
		catch (...)
		{
			throw except("������ ������ �� ��������� �����");
		}
	}

	void to_bin(ofstream& f)
	{
		try
		{
			f.write((char*)this, sizeof(*this));
		}
		catch (...)
		{
			throw except("������ ������ � �������� ����");
		}
	}
};

ostream& operator<<(ostream& f, const employee& o)
{
	try
	{
		f << "\n" << o.name << ", " << o.post << ", " << o.age;
		return f;
	}
	catch (...)
	{
		throw except("������ ������ � ��������� ����");
	}
}

istream& operator>>(istream& f, employee& o)
{
	try
	{
		string tmp;
		getline(f, tmp);
		o.name = tmp.substr(0, tmp.find_first_of(',', 0));
		o.post = tmp.substr(o.name.length() + 2, tmp.find_last_of(',', tmp.length() - 1) - o.name.length() - 2);
		o.age = stoi(tmp.substr(o.name.length() + o.post.length() + 4, tmp.length() - (o.name.length() + o.post.length() + 4)));
		return f;
	}
	catch (...)
	{
		throw except("������ ������ �� ���������� �����");
	}
}

int main()
{
	while (true)
	{
		int a, age;
		string name, post;
		ofstream oft;
		ifstream ift;
		ofstream ofb;
		ifstream ifb;
		employee e("", "", 0);
		cout << "\n\n1 - ������� �� ����� �� ���������� �����\n2 - ������� �� ����� �� ��������� �����\n"<<
			"3 - �������� � ��������� ����\n4 - �������� � �������� ����\n"<<
			"5 - ������� �� ���������� �����\n6 - ������� �� ��������� �����\n"<<
			"7 - ����� � ��������� �����\n8 - ����� � �������� �����\n�������� ��������: ";
		cin >> a;
		try
		{
			switch (a)
			{
			case 1:
				try
				{
					ift.open(txt_file);
				}
				catch (...)
				{
					cout << "��� ������� � ���������� �����\n";
					exit(EXIT_FAILURE);
				}
				ift.seekg(0, ift.beg);
				while (!ift.eof())
				{
					ift >> e;
					cout << e;
				}
				ift.close();
				break;
			case 2:
				try
				{
					ifb.open(bin_file);
				}
				catch (...)
				{
					cout << "��� ������� � ��������� �����\n";
					exit(EXIT_FAILURE);
				}
				ifb.seekg(0, ifb.beg);
				while (!ifb.eof())
				{
					e.from_bin(ifb);
					cout << e;
				}
				ifb.close();
				break;
			case 3:
				try
				{
					oft.open(txt_file, ios_base::app);
				}
				catch (...)
				{
					cout << "��� ������� � ���������� �����\n";
					exit(EXIT_FAILURE);
				}
				oft.seekp(0, oft.end);
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "������� ��� ���������: ";
				getline(cin, name);
				cout << "������� ��������� ���������: ";
				getline(cin, post);
				cout << "������� ������� ���������: ";
				cin >> age;
				e = employee(name, post, age);
				oft << e;
				oft.close();
				break;
			case 4:
				try
				{
					ofb.open(bin_file, ios_base::app);
				}
				catch (...)
				{
					cout << "��� ������� � ��������� �����\n";
					exit(EXIT_FAILURE);
				}
				ofb.seekp(0, ofb.end);
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "������� ��� ���������: ";
				getline(cin, name);
				cout << "������� ��������� ���������: ";
				getline(cin, post);
				cout << "������� ������� ���������: ";
				cin >> age;
				e = employee(name, post, age);
				ofb << e;
				ofb.close();
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				try
				{
					ift.open(txt_file);
				}
				catch (...)
				{
					cout << "��� ������� � ���������� �����\n";
					exit(EXIT_FAILURE);
				}
				ift.seekg(0, ift.beg);
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "������� ��� ���������: ";
				getline(cin, name);
				while (!ift.eof())
				{
					ift >> e;
					if (e.check_name(name))
						cout << e;
				}
				ift.close();
				break;
			case 8:
				try
				{
					ifb.open(bin_file);
				}
				catch (...)
				{
					cout << "��� ������� � ��������� �����\n";
					exit(EXIT_FAILURE);
				}
				ifb.seekg(0, ifb.beg);
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "������� ��� ���������: ";
				getline(cin, name);
				while (!ifb.eof())
				{
					e.from_bin(ifb);
					if (e.check_name(name))
						cout << e;
				}
				ifb.close();
				break;
			default:
				throw except("����� ����� �����������");
			}
		}
		catch (except e)
		{
			cout << "��������� ������: " << e.message() << "\n";
		}
		catch (...)
		{
			cout << "��������� ������\n";
		}
	}
}