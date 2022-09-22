#include <iostream>
#include <string>

using namespace std;

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int gcd(int a, int b)
{
	if (a < b)
		swap(&a, &b);
	while (a % b != 0)
	{
		a = a % b;
		swap(&a, &b);
	}
	return b;
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

class fract
{
	friend fract& operator--(fract& f);
	friend fract operator--(fract& f, int i);
	friend bool operator==(const fract& f, double& d);
	friend bool operator==(double& d, const fract& f);
	friend ostream& operator<<(ostream& out, const fract& f);

private:
	int numer;
	int denom;

public:
	fract(int numer = 0, int denom = 1)
	{
		if (denom == 0)
		{
			this->numer = 0;
			this->denom = 1;
		}
		else
		{
			this->numer = numer;
			this->denom = denom;
		}
	}

	fract& operator=(const fract& f)
	{
		numer = f.numer;
		denom = f.denom;
		return *this;
	}

	fract& operator[](int d)
	{
		int _d = denom;
		denom = lcm(denom, d);
		numer = numer * denom / _d;
		return *this;
	}

	fract& operator()(int numer = 0, int denom = 1)
	{
		if (denom == 0)
		{
			this->numer = 0;
			this->denom = 1;
		}
		else
		{
			this->numer = numer;
			this->denom = denom;
		}
		return *this;
	}

	operator double() const
	{
		return numer / (double)denom;
	}

	fract& operator++()
	{
		numer += denom;
		return *this;
	}

	fract operator++(int i)
	{
		fract tmp(this->numer, this->denom);
		++(*this);
		return tmp;
	}

	fract operator+(const fract& f) const
	{
		fract _fract(0, lcm(this->denom, f.denom));
		_fract.numer = this->numer * _fract.denom / this->denom + f.numer * _fract.denom / f.denom;
		return _fract;
	}

	bool operator<(const fract& f) const
	{
		int d = lcm(this->denom, f.denom);
		return this->numer * d / this->denom < f.numer* d / f.denom;
	}

	bool operator>(const fract& f) const
	{
		int d = lcm(this->denom, f.denom);
		return this->numer * d / this->denom > f.numer * d / f.denom;
	}
};

fract& operator--(fract& f)
{
	f.numer -= f.denom;
	return f;
}

fract operator--(fract& f, int i)
{
	fract tmp(f.numer, f.denom);
	++f;
	return tmp;
}

double operator-(const fract& f, double& d)
{
	return (double)f - d;
}

double operator-(double& d, const fract& f)
{
	return d - (double)f;
}

bool operator==(const fract& f, double& d)
{
	return (double)f == d;
}

bool operator==(double& d, const fract& f)
{
	return d == (double)f;
}

ostream& operator<<(ostream& out, const fract& f)
{
	out << f.numer << "/" << f.denom;
	return out;
}

int main()
{
	int n, d;
	fract f1, f2, f3;
	double dd;

	cout << "¬ведите числитель дроби: ";
	cin >> n;
	cout << "¬ведите знаменатель дроби: ";
	cin >> d;
	f1(n, d);

	cout << "¬ведите числитель дроби: ";
	cin >> n;
	cout << "¬ведите знаменатель дроби: ";
	cin >> d;
	f2(n, d);

	cout << "¬ведите числитель дроби: ";
	cin >> n;
	cout << "¬ведите знаменатель дроби: ";
	cin >> d;
	f3(n, d);

	cout << "¬ведите число с плавающей зап€той: ";
	cin >> dd;

	cout << f1 << " + " << f2 << " = " << f1 + f2 << "\n";
	cout << f1 << " - " << f2 << " = " << f1 - f2 << "\n";
	cout << dd << " + " << f3 << " = " << dd + f3 << "\n";
	cout << dd << " - " << f3 << " = " << dd - f3 << "\n";
	cout << f1 << " " << (f1 > f2 ? ">" : (f1 < f2 ? "<" : "=")) << " " << f2 << "\n";
	cout << f1 << " " << (f1 > f3 ? ">" : (f1 == f3 ? "=" : "<")) << " " << f3 << "\n";
	cout << f3 << " " << (f3 > f2 ? ">" : (f3 < f2 ? "<" : "=")) << " " << f2 << "\n";
}