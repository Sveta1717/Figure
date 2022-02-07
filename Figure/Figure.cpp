#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <algorithm>
#include <math.h>
#include <vector> 
//#include <SFML/Graphics.hpp>
#define PI 3.14159;

using namespace std;


class Figure abstract
{
protected:

	int x;
	int y;

public:	
	Figure(int x = 0, int y = 0)
	{
		this->x = x;	
		this->y = y;
	}

	virtual double Area()
	{
		return 0;
	}

	virtual double Perimeter()// = 0;
	{
		return 0;
	}
	
	virtual void Draw() // = 0;		
	{
		
	}
};

class Point : public Figure
{	
public:
	Point()
	{
		x = y = 0;
	}
	
	void Draw() //const
	{
		COORD position;
		position.X = x;
		position.Y = y;
		system("cls");
		int i;
		int j;
		for (i = 0, j = 0; i < y, j < x; i++, j++)
		{			
				cout << " ";			
		}
		cout << "Point : " << char(46) << "\n\n";
	}

	~Point()
	{

	}
};

class Line : public Figure
{	
public:
	Line()
	{
		x = y = 0;
	}
		
	virtual void Draw() //const
	{
		COORD position;
		position.X = x;
		position.Y = y;
		
		int i;
		int j;
		cout << "Line : ";
		for (i = 0, j = 0; i < y, j < 7; i++, j++)
		{
			cout << "_";
		}
		cout << "\n\n";
	}
	~Line()
	{

	}
};

class Ellipse1 : public Figure
{
protected:

	double radius1;	
	double radius2;
	
public:
	Ellipse1()
	{		
		radius1 = 5;
		radius2 = 9;
	}

	Ellipse1(double radius1_, double radius2_)
	{
		//cout << "Ellipse param c-tor!\n";
		radius1_ = radius1;		
		radius2_ = radius2;
	}

	double Area()
	{		
		return radius1 * radius2 / 2 * PI;
	}

	double Perimeter()
	{
		return 2.0 * sqrt((radius1 * radius1 + radius2 * radius2) / 2.0) * PI;
	}

	virtual void Draw() //const
	{		

		cout << "Ellips, area = " << Area() << ", perimeter = " << Perimeter() << "\n";
	}
	~Ellipse1()
	{
	}
};

class Poligon1 : public Figure
{
protected:
	int side;
	int* x1;
	int* y1;
	int* x;
	int* y;

public:	
	Poligon1()
	{
		
	}

	Poligon1(int side, int* x_, int* x1_, int* y_, int* y1_)
	{
		this->side = side;	
		this->x = x_;
		this->x1 = x1_;
		this->y = y_;
		this->y1 = y1;
	}

	double Area()
	{		
		double area = 0;
		for (int i = 0; i < side - 1; i++)
		{
			area += (x[i] + x1[i]) * (y1[i] - y[i]);			
		}		
		return abs(area) / 2; 
	}

	double Perimeter()
	{
		double per = 0;
		for (int i = 0; i < side - 1; i++)
		{
			int j = (i + 1) % side;
			per += sqrt((x[i] - x1[i]) * (x[i] - x1[i]) + (y1[i] - y[i]) * (y[i] - y1[i]));			
		}
		return per;
	}

	virtual void Draw() //const
	{
		cout << "Poligon, area = " << Area() << ", perimeter = " << Perimeter() << "\n";
	}
	~Poligon1()
	{

	}
};

class Circle : public Ellipse1
{	

public:
	Circle()
	{	

	}

	Circle(int center_x, int center_y, int radius_)//:  Ellipse(center_x, center_y, radius)
	{
		radius1 = radius_;
	}

	double Area()
	{
		return radius1 * radius1 * PI;
	}

	double Perimeter()
	{
		return 2 * radius1 * PI;
	}

	virtual void Draw() //const
	{
		cout << "Circle, area = " << Area() << ", perimeter = " << Perimeter() << "\n";
	}

	~Circle()
	{

	}
};


class Triangle : public Poligon1 // треугольник
{
protected:
	double side1;
	double side2;
	double side3;

public:

	Triangle()
	{
		side1 = 7.0;
		side2 = 6.0;
		side3 = 5.0;
	}
	Triangle(double a, double b, double c)
	{
		this->side1 = a;
		this->side2 = b;
		this->side3 = c;
	}	

	double Area() const
	{
		double P = Perimeter();
		double p = P / 2;
		double  S = p * (p - side1) * (p - side2) * (p - side3);
		return sqrt(S);
	}

	double Perimeter() const
	{
		return side1 + side2 + side3;
	}

	void Draw() const
	{
		cout << "Triangle, area = " << Area() << ", perimeter = " << Perimeter() << "\n";
		int line;      
		int i;        
		
		for (line = 1; line <= 5; line++) 
		{			
			for (i = 0; i < line; i++)
				cout << char(46);
			cout << char('\n');
		}
	}
};

class Quadrilateral : public Poligon1 // четырехугольник
{
protected:
	
	/*int y1;
	int x1;*/
	int* x2;
	int* y2;
	int* y3;
	int* x3;
	
public:

	Quadrilateral()
	{

	}
	Quadrilateral(int* x, int* y, int* y1, int* x1, int* x2, int* y2, int* y3, int* x3)
	{
		this->x = x;
		this->x1 = x1;
		this->y = y;
		this->y1 = y1;
		this->x2 = x2;
		this->x3 = x3;
		this->y2 = y2;
		this->y3 = y3;
	}	

	double Area() const
	{
		double S = 0.5 * (x - x1) * (y - y1) + (x1 - x2) * (y1 - y2) + (x2 - x3) * (y2 - y3) + (x3 - x) * (y3 - y);
		return S;
	}

	double Perimeter() const
	{
		return 0;
	}

	void Draw() const
	{
		cout << "Quadrilateral, area = " << Area() << ", perimeter = " << Perimeter() << "\n";
	}
};

class AcuteTriangle : public Triangle // остроугольный треугольник
{
public:

	AcuteTriangle()
	{

	}
	AcuteTriangle(unsigned short width, unsigned short height)
	{

	}	

	void Draw() const
	{
		cout << "Acute triangle!\n";
	}
};


class IsoscelesAcuteTriangle : public Triangle // равнобедренный остроугольный треугольник
{
public:

	IsoscelesAcuteTriangle()
	{

	}
	IsoscelesAcuteTriangle(unsigned short width, unsigned short height)
	{

	}	

	void Draw() const
	{
		cout << "Isosceles acute triangle!\n";
	}
};

class EquilateralAcuteTriangle : public Triangle // равносторонний  остроугольный треугольник
{
public:

	EquilateralAcuteTriangle()
	{

	}
	EquilateralAcuteTriangle(unsigned short width, unsigned short height)
	{

	}

	

	void Draw() const
	{
		cout << "Equilateral triangle!\n";
	}
};

class  EquilateralObtuseTriangle : public Triangle // равностроронний тупоугольный треугольник
{
public:

	EquilateralObtuseTriangle()
	{

	}
	EquilateralObtuseTriangle(unsigned short width, unsigned short height)
	{

	}	

	void Draw() const
	{
		cout << "  Equilateral obtuse triangle!\n";
	}
};

class ObtuseTriangle : public Triangle // тупоугольный треугольник
{
public:

	ObtuseTriangle()
	{

	}
	ObtuseTriangle(unsigned short width, unsigned short height)
	{

	}	

	void Draw() const
	{
		cout << " Obtuse triangle!\n";
	}
};

class RightTriangle : public Triangle // прямоугольный треугольник
{
public:

	RightTriangle()
	{

	}
	RightTriangle(unsigned short width, unsigned short height)
	{

	}	

	void Draw() const
	{
		cout << "Right triangle!\n";
	}
};

class IsoscelesRightTriangle : public Triangle //  равнобедренный прямоугольный треугольник
{
public:

	IsoscelesRightTriangle()
	{

	}
	IsoscelesRightTriangle(unsigned short width, unsigned short height)
	{

	}

	

	void Draw() const
	{
		cout << " Isosceles right triangle!\n";
	}
};

class Rectangle1
{
protected:
	unsigned short width;
	unsigned short height;

public:


	Rectangle1()
	{

	}
	Rectangle1(unsigned short width, unsigned short height)
	{

	}

	unsigned short GetWidth() const
	{
		return width;
	}
	unsigned short GetHeight() const
	{
		return height;
	}

	void SetWidth(unsigned short width_)
	{
		width_ = width;
	}
	void SetHeight(unsigned short height_)
	{
		height_ = height;
	}

	void Draw() const
	{
		cout << "RECTANGLE!\n";
	}
};

int main()
{
	int x = 2;
	int x1 = 6;
	int y = 6;
	int y1 = 3;
	int x2 = 2;
	int x3 = 6;
	int y3 = 6;
	int y2 = 3;
	Point p;
	p.Draw();

	Line l;
	l.Draw();

	Ellipse1 e;
	e.Draw();

	/*Poligon1 pl(5, &x, &x1, &y, &y1);
	pl.Draw();*/

	Circle c;
	c.Draw();

	Triangle t;
	t.Draw();

	Quadrilateral q(&x, &x1, &y, &y1, &x2, &x3, &y2, &y3);
	q.Draw();

	Rectangle1 r;
	r.Draw();	
}

