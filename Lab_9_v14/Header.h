#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

enum COLOR
{
	WHITE,
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	HBLUE,
	VIOLET
};

namespace my_space
{
	class color
	{
	private:
		COLOR __col;

	public:
		color();
		color(COLOR);
		~color();

		COLOR getColor();
		void setColor(COLOR);
	};

	class coordinate
	{
	private:
		int x;
		int y;
		int z;

	public:
		coordinate();
		coordinate(int x = 0, int y = 0, int z = 0);
		~coordinate();

		int getX();
		int getY();
		int getZ();

		void setX(int);
		void setY(int);
		void setZ(int);
	};

	class back
	{
	private:
		color col;

	public:
		back(color);
		~back();

		color getBack();
		void setBack(color);
	};

	class figure
	{
	protected:
		color col;
		coordinate cor;

	public:
		figure(color, coordinate);
		virtual ~figure();

		color getColor();
		coordinate getCoord();

		void setColor(color);
		void setCoord(coordinate);
	};

	class line : public figure
	{
	protected:
		int width;
		coordinate cor2;

	public:
		line(int, color, coordinate, coordinate);
		virtual ~line();

		int getWidth();
		coordinate getCoord2();

		void setWidth(int);
		void setCoord2(coordinate);
	};

	class round : public figure
	{
	protected:
		int radius;

	public:
		round(int, color, coordinate);
		virtual ~round();

		int getR();
		void setR(int);
	};

	class header
	{
	private:
		color col;
		string text;

	public:
		header(color, string);
		~header();

		color getColor();
		string getStr();

		void setColor(color);
		void setStr(string);
	};
}