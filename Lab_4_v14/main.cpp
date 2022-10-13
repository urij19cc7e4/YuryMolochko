#include <iostream>
#include <string>

using namespace std;

class plant
{
protected:
	string name;

public:

	plant(string name) : name(name) {}

	virtual ~plant() {}

	virtual void showName() = 0;

	virtual void showObj() = 0;
};

class seed : virtual public plant
{
protected:
	string grow_period;

public:
	seed(string name, string g_p) : plant(name), grow_period(g_p) {}

	~seed() {}

	virtual void showName()
	{
		cout << name << "\n";
	}

	virtual void showObj()
	{
		cout << "Grow period " << grow_period << "\n";
	}
};

class tree : public seed
{
protected:
	int age;

public:
	tree(string name, string g_p, int age) : seed(name, g_p), plant(name), age(age) {}

	~tree() {}

	virtual void showName()
	{
		cout << name << "\n";
	}

	virtual void showObj()
	{
		this->seed::showObj();
		cout << "Age " << age << "\n";
	}
};

class fruit : virtual public plant
{
protected:
	int weight;

public:
	fruit(string name, int weight) : plant(name), weight(weight) {}

	~fruit() {}

	virtual void showName()
	{
		cout << name << "\n";
	}

	virtual void showObj()
	{
		cout << "Weight " << weight << "\n";
	}
};

class banana : public fruit
{
protected:
	int length;

public:
	banana(string name, int weight, int length) : fruit(name, weight), plant(name), length(length) {}

	~banana() {}

	virtual void showName()
	{
		cout << name << "\n";
	}

	virtual void showObj()
	{
		this->fruit::showObj();
		cout << "Length " << length << "\n";
	}
};

class banana_tree : public tree, public banana
{
protected:
	double x;
	double y;

public:
	banana_tree(string name, string g_p, int age, int weight, int length, double x, double y)
		: tree(name, g_p, age), banana(name, weight, length), plant(name), x(x), y(y) {}

	~banana_tree() {}

	virtual void showName()
	{
		cout << name << "\n";
	}

	virtual void showObj()
	{
		this->tree::showObj();
		this->banana::showObj();
		cout << "Location " << x << " " << y << "\n";
	}
};

int main()
{
	string g_p;
	int age, weight, length;
	double x, y;
	cout << "¬ведите период роста: ";
	getline(cin, g_p);
	cout << "¬ведите возраст дерева: ";
	cin >> age;
	cout << "¬ведите вес плода: ";
	cin >> weight;
	cout << "¬ведите длину банана: ";
	cin >> length;
	cout << "¬ведите координату х местоположени€ бананового дерева: ";
	cin >> x;
	cout << "¬ведите координату х местоположени€ бананового дерева: ";
	cin >> y;

	plant** arr = new plant*[5];

	arr[0] = new seed("SEED", g_p);
	arr[1] = new tree("TREE", g_p, age);
	arr[2] = new fruit("FRUIT", weight);
	arr[3] = new banana("BANANA", weight, length);
	arr[4] = new banana_tree("BANANA TREE", g_p, age, weight, length, x, y);

	for (int i = 0; i < 5; ++i)
	{
		cout << "\n";
		arr[i]->showName();
		arr[i]->showObj();
		delete arr[i];
	}
	delete[] arr;
}