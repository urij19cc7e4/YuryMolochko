#include <iostream>
#include <string>

using namespace std;

class plant
{
	friend ostream& operator<<(ostream& out, const plant& d);

protected:
	string name;

public:
	plant(string name): name(name){}

	~plant() {}
};

class seed : virtual public plant
{
	friend ostream& operator<<(ostream& out, const seed& d);

protected:
	string grow_period;

public:
	seed(string name, string g_p) : plant(name), grow_period(g_p) {}

	~seed() {}
};

class tree : public seed
{
	friend ostream& operator<<(ostream& out, const tree& d);

protected:
	int age;

public:
	tree(string name, string g_p, int age) : seed(name, g_p), plant(name), age(age) {}

	~tree() {}
};

class fruit : virtual public plant
{
	friend ostream& operator<<(ostream& out, const fruit& d);

protected:
	int weight;

public:
	fruit(string name, int weight) : plant(name), weight(weight) {}

	~fruit() {}
};

class banana : public fruit
{
	friend ostream& operator<<(ostream& out, const banana& d);

protected:
	int length;

public:
	banana(string name, int weight, int length) : fruit(name, weight), plant(name), length(length) {}

	~banana() {}
};

class banana_tree : public tree, public banana
{
	friend ostream& operator<<(ostream& out, const banana_tree& d);

protected:
	double x;
	double y;

public:
	banana_tree(string name, string g_p, int age, int weight, int length, double x, double y)
		: tree(name, g_p, age), banana(name, weight, length), plant(name), x(x), y(y) {}

	~banana_tree() {}
};

ostream& operator<<(ostream& out, const plant& d)
{
	cout << "Plant name: " << d.name << "\n";
	return out;
}

ostream& operator<<(ostream& out, const seed& d)
{
	cout << (plant)d << "Seed grow period: " << d.grow_period << "\n";
	return out;
}

ostream& operator<<(ostream& out, const tree& d)
{
	cout << (seed)d << "Tree age: " << d.age << "\n";
	return out;
}

ostream& operator<<(ostream& out, const fruit& d)
{
	cout << (plant)d << "Fruit weight: " << d.weight << "\n";
	return out;
}

ostream& operator<<(ostream& out, const banana& d)
{
	cout << (fruit)d << "Banana lenght: " << d.length << "\n";
	return out;
}

ostream& operator<<(ostream& out, const banana_tree& d)
{
	cout << (tree)d << (banana)d << "Banana tree location: " << d.x << " " << d.y << "\n";
	return out;
}

int main()
{
	string name, g_p;
	int age, weight, length;
	double x, y;
	cout << "Введите имя растения: ";
	getline(cin, name);
	cout << "Введите период роста: ";
	getline(cin, g_p);
	cout << "Введите возраст дерева: ";
	cin >> age;
	cout << "Введите вес плода: ";
	cin >> weight;
	cout << "Введите длину банана: ";
	cin >> length;
	cout << "Введите координату х местоположения бананового дерева: ";
	cin >> x;
	cout << "Введите координату х местоположения бананового дерева: ";
	cin >> y;
	banana_tree o(name, g_p, age, weight, length, x, y);
	cout << "Банановое дерево:\n" << o;
}