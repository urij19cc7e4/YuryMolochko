#include <iostream>
#include <string>

using namespace std;

class detail
{
	friend class control;

private:
	static int _id;
	int id;
	string name;
	int weight;

	friend void print(detail&);

public:
	detail()
	{
		id = ++_id;
		weight = 0;
	}

	detail(string n, int w) : name(n), weight(w)
	{
		id = ++_id;
	}
};

static class control
{
public:
	static void setWeight(detail& d, int w)
	{
		d.weight = w;
	}
};

void print(detail& d)
{
	cout << "#" << d.id << "  <" << d.name << ">  " << d.weight << " грамм\n";
}

int detail::_id = 0;

int main()
{
	detail d1("001", 10), d2("002", 25);
	cout << "Детали до обработки:\n";
	print(d1);
	print(d2);
	control::setWeight(d1, 150);
	control::setWeight(d2, 6);
	cout << "Детали после обработки:\n";
	print(d1);
	print(d2);

	cout << "\n\n";

	detail* ds = new detail[10];
	for (int i = 0; i < 10; ++i)
		ds[i] = detail(string("пружина ") + to_string(i+1), 30);
	cout << "Массив деталей до обработки:\n";
	for (int i = 0; i < 10; ++i)
		print(ds[i]);
	for (int i = 0; i < 10; ++i)
		control::setWeight(ds[i], 90);
	cout << "Массив деталей после обработки:\n";
	for (int i = 0; i < 10; ++i)
		print(ds[i]);
	delete[] ds;
}