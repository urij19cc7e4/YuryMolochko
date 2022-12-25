#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "Header.h"

using namespace std;

using namespace my_space;

int main()
{
	int r, choose;
	my_space::color c;
	int x, y;
	cout << "Введите координату x круга: ";
	cin >> x;
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	cout << "Введите координату y круга: ";
	cin >> y;
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	cout << "Введите радиус круга: ";
	cin >> r;
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	cout << "0. Белый\n1. Красный\n2. Оранжевый\n3. Желтый\n4. Зеленый\n5. Голубой\n6. Синий\n7. Фиолетовый\nВыберите цвет круга: ";
	cin >> choose;
	switch (choose)
	{
	case 0:
		c.setColor(COLOR::WHITE);
		break;
	case 1:
		c.setColor(COLOR::RED);
		break;
	case 2:
		c.setColor(COLOR::ORANGE);
		break;
	case 3:
		c.setColor(COLOR::YELLOW);
		break;
	case 4:
		c.setColor(COLOR::GREEN);
		break;
	case 5:
		c.setColor(COLOR::BLUE);
		break;
	case 6:
		c.setColor(COLOR::HBLUE);
		break;
	case 7:
		c.setColor(COLOR::VIOLET);
		break;
	default:
		cout << "Неправильный вариант";
	}
	my_space::round __round = my_space::round(r, c, coordinate(x, y));
	cout << "\n\nПараметры круга:\n";
	cout << "Радиус: " << __round.getR() << "\n";
	cout << "Координаты: " << __round.getCoord().getX() << "; " << __round.getCoord().getY() << "\n";
	cout << "Цвет: ";
	switch (__round.getColor().getColor())
	{
	case WHITE:
		cout << "Белый\n";
		break;
	case RED:
		cout << "Красный\n";
		break;
	case ORANGE:
		cout << "Оранжевый\n";
		break;
	case YELLOW:
		cout << "Желтый\n";
		break;
	case GREEN:
		cout << "Зеленый\n";
		break;
	case BLUE:
		cout << "Голубой\n";
		break;
	case HBLUE:
		cout << "Синий\n";
		break;
	case VIOLET:
		cout << "Фиолетовый\n";
		break;
	}
}