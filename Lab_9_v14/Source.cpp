#include "Header.h"

using namespace my_space;

my_space::color::color() : __col(WHITE) {}

my_space::color::color(COLOR c) : __col(c) {}

my_space::color::~color() {}

COLOR my_space::color::getColor()
{
	return __col;
}

void my_space::color::setColor(COLOR c)
{
	__col = c;
}

my_space::coordinate::coordinate() : x(0), y(0), z(0) {}

my_space::coordinate::coordinate(int x, int y, int z) : x(x), y(y), z(z) {}

my_space::coordinate::~coordinate() {}

int my_space::coordinate::getX()
{
	return x;
}

int my_space::coordinate::getY()
{
	return y;
}

int my_space::coordinate::getZ()
{
	return z;
}

void my_space::coordinate::setX(int x)
{
	this->x = x;
}

void my_space::coordinate::setY(int y)
{
	this->y = y;
}

void my_space::coordinate::setZ(int z)
{
	this->z = z;
}

my_space::back::back(color c) : col(c) {}

my_space::back::~back() {}

my_space::color my_space::back::getBack()
{
	return col;
}

void my_space::back::setBack(color c)
{
	col = c;
}

my_space::figure::figure(color c, coordinate coord) : col(c), cor(coord) {}

my_space::figure::~figure() {}

my_space::color my_space::figure::getColor()
{
	return col;
}

my_space::coordinate my_space::figure::getCoord()
{
	return cor;
}


void my_space::figure::setColor(color c)
{
	col = c;
}

void my_space::figure::setCoord(coordinate coord)
{
	cor = coord;
}

my_space::line::line(int w, color c, coordinate coord1, coordinate coord2) : figure(c, coord1), width(w), cor2(coord2) {}

my_space::line::~line() {}

int my_space::line::getWidth()
{
	return width;
}

my_space::coordinate my_space::line::getCoord2()
{
	return cor2;
}

void my_space::line::setWidth(int w)
{
	width = w;
}

void my_space::line::setCoord2(coordinate coord2)
{
	cor2 = coord2;
}

my_space::round::round(int r, color c, coordinate coord) : figure(c, coord), radius(r) {}

my_space::round::~round() {}

int my_space::round::getR()
{
	return radius;
}

void my_space::round::setR(int r)
{
	radius = r;
}

my_space::header::header(color c, string s) : col(c), text(s) {}

my_space::header::~header() {}

my_space::color my_space::header::getColor()
{
	return col;
}

string my_space::header::getStr()
{
	return text;
}

void my_space::header::setColor(color c)
{
	col = c;
}

void my_space::header::setStr(string s)
{
	text = s;
}