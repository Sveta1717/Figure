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
		int* x1 = nullptr;
		int* y1 = nullptr;
		int* x = nullptr;
		int* y = nullptr;		
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

	double PerimeterPoligon1()
	{
		double per = 0;
		for (int i = 0; i < side; i++)
		{
			int j = (i + 1) % side;
			per += sqrt((x[i] - x1[j]) * (x[i] - x1[j]) + (y1[i] - y[j]) * (y[i] - y1[j]));
		}
		return per;
	}

	virtual void Draw() //const
	{
		cout << "Poligon, area = " << Area() << ", perimeter = " << PerimeterPoligon1() << "\n";
	}
	~Poligon1()
	{

	}
};

class Circle : public Ellipse1
{

public:
	Circle(): Circle(5, 3, 7)
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
		side1 = 2.5;
		side2 = 2.7;
		side3 = 4.5;
	}
	Triangle(double a, double b, double c)
	{
		this->side1 = a;
		this->side2 = b;
		this->side3 = c;
	}

	double AreaTriangle() const
	{
		double P = PerimeterTriangle();
		double p = P / 2;
		double  S = p * (p - side1) * (p - side2) * (p - side3);
		return sqrt(S);
	}

	double PerimeterTriangle() const
	{
		return side1 + side2 + side3;
	}

	void Draw() const
	{
		cout << "Triangle, area = " << AreaTriangle() << ", perimeter = " << PerimeterTriangle() << "\n";
		
		for (int line = 1; line <= 3; line++)
		{
			for (int i = 0; i < line; i++)
				cout << '*';
			cout << '\n';
		}
	}
	~Triangle()
	{

	}
};

class Quadrilateral : public Poligon1 // четырехугольник
{
protected:	
	int* x2;
	int* y2;
	int* y3;
	int* x3;

public:
	Quadrilateral() 
	{
		int* x2 = nullptr;
		int* y2 = nullptr;
		int* y3 = nullptr;
		int* x3 = nullptr;
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

	double AreaQuadrilateral() const
	{
		double S = 0.5 * (x - x1) * (y - y1) + (x1 - x2) * (y1 - y2) + (x2 - x3) * (y2 - y3) + (x3 - x) * (y3 - y);
		return S;
	}

	double PerimeterQuadrilateral()
	{
		return PerimeterPoligon1();
	}

	void Draw() 
	{
		cout << "Quadrilateral, area = " << AreaQuadrilateral() << ", perimeter = " << PerimeterQuadrilateral() << "\n";
	}
	~Quadrilateral()
	{

	}
};

class AcuteTriangle : public Triangle // остроугольный треугольник
{
public:

	AcuteTriangle()
	{
		side1 = 4.0;
		side2 = 3.7;
		side3 = 4.2;
	}

	double Area() const
	{
		return  AreaTriangle();
	}

	double Perimeter() const
	{
		return PerimeterTriangle();
	}

	void Draw() const
	{
		cout << "Acute triangle, area = " << Area() << ", perimeter = " << Perimeter() << "\n";
		
	}
	~AcuteTriangle()
	{

	}
};


class IsoscelesAcuteTriangle : public Triangle // равнобедренный остроугольный треугольник
{
public:

	IsoscelesAcuteTriangle()
	{
		side1 = 4.5;
		side2 = 5.0;
		side3 = 5.0;
	}

	double Area() const
	{
		return  AreaTriangle();
	}

	double Perimeter() const
	{
		return PerimeterTriangle();
	}

	void Draw() const
	{
		cout << "Isosceles triangle, area = " << Area() << ", perimeter = " << Perimeter() << "\n";
	}

	~IsoscelesAcuteTriangle()
	{

	}
};

class EquilateralAcuteTriangle : public Triangle // равносторонний  остроугольный треугольник
{
public:

	EquilateralAcuteTriangle()
	{
		side1 = 4.0;
		side2 = 4.0;
		side3 = 4.0;
	}

	double Area() const
	{
		return  AreaTriangle();
	}

	double Perimeter() const
	{
		return PerimeterTriangle();
	}

	void Draw() const
	{
		cout << "Equilateral acute triangle, area = " << Area() << ", perimeter = " << Perimeter() << "\n";
	}

	~EquilateralAcuteTriangle()
	{

	}
};

class  IsoscelesObtuseTriangle : public Triangle // равнобедренный тупоугольный треугольник
{
public:

	IsoscelesObtuseTriangle()
	{
		side1 = 4.5;
		side2 = 4.5;
		side3 = 7.5;
	}

	double Area() const
	{
		return  AreaTriangle();
	}

	double Perimeter() const
	{
		return PerimeterTriangle();
	}

	void Draw() const
	{
		cout << "Isosceles obtuse triangle, area = " << Area() << ", perimeter = " << Perimeter() << "\n";
	}

	~IsoscelesObtuseTriangle()
	{

	}
};

class ObtuseTriangle : public Triangle // тупоугольный треугольник
{
public:

	ObtuseTriangle()
	{
		side1 = 4.5;
		side2 = 5.0;
		side3 = 9.2;
	}
	double Area() const
	{
		return  AreaTriangle();
	}

	double Perimeter() const
	{
		return PerimeterTriangle();
	}

	void Draw() const
	{
		cout << "Obtuse triangle, area = " << Area() << ", perimeter = " << Perimeter() << "\n";

		int n = 5;
		int h;
		for (int i = 1; i < n; i++) {

			if (i <= n / 2)
			{
				h = i;
			}
			else if (i > n / 2)
			{
				h = n - i;
			}

			for (int j = 0; j < h; j++)
			{
				cout << "*";
			}
			cout << "\n";
		}
	}

	~ObtuseTriangle()
	{

	}
};

class RightTriangle : public Triangle // прямоугольный треугольник
{
public:

	RightTriangle()
	{
		side1 = 4.0;
		side2 = 3.0;
		side3 = 5.0;
	}

	double Area() const
	{
		return  AreaTriangle();
	}

	double Perimeter() const
	{
		return PerimeterTriangle();
	}

	void Draw() const
	{
		cout << "Right triangle, area = " << Area() << ", perimeter = " << Perimeter() << "\n";
	}

	~RightTriangle()
	{

	}
};

class IsoscelesRightTriangle : public Triangle //  равнобедренный прямоугольный треугольник
{
public:

	IsoscelesRightTriangle()
	{
		side1 = 4.0;
		side2 = 4.0;
		side3 = 5.5;
	}

	double Area() const
	{
		return  AreaTriangle();
	}

	double Perimeter() const
	{
		return PerimeterTriangle();
	}

	void Draw() const
	{
		cout << "Isosceles right triangle, area = " << Area() << ", perimeter = " << Perimeter() << "\n";
	}

	~IsoscelesRightTriangle()
	{

	}
};

class Parallelogram : public Quadrilateral
{
public:

	Parallelogram()
	{
		int* x2 = nullptr;
		int* y2 = nullptr;
		int* y3 = nullptr;
		int* x3 = nullptr;
	}

	double Area() const
	{
		return AreaQuadrilateral();
	}

	double Perimeter() 
	{
		return PerimeterQuadrilateral();
	}

	void Draw() 
	{
		cout << "Parallelogram, area = " << Area() << ", perimeter = " << Perimeter() << "\n";
	}

	~Parallelogram()
	{

	}
};

class Trapezoid : public Quadrilateral
{
public:

	Trapezoid()
	{
		int* x2 = nullptr;
		int* y2 = nullptr;
		int* y3 = nullptr;
		int* x3 = nullptr;
	}

	double Area() const
	{
		return AreaQuadrilateral();
	}

	double Perimeter() 
	{
		return PerimeterQuadrilateral();
	}

	void Draw() 
	{
		cout << "Trapezoid , area = " << Area() << ", perimeter = " << Perimeter() << "\n";
	}

	~Trapezoid()
	{

	}
};

class Deltoid : public Quadrilateral
{
public:

	Deltoid()
	{
		int* x2 = nullptr;
		int* y2 = nullptr;
		int* y3 = nullptr;
		int* x3 = nullptr;
	}

	double Area() const
	{
		return AreaQuadrilateral();
	}

	double Perimeter() 
	{
		return PerimeterQuadrilateral();
	}

	void Draw() 
	{
		cout << "Deltoid , area = " << Area() << ", perimeter = " << Perimeter() << "\n";
	}

	~Deltoid()
	{

	}
};

class Rectangle1 : public Parallelogram
{
protected:
	unsigned short width;
	unsigned short height;

public:


	Rectangle1(): Rectangle1(7, 3)
	{		
	}
	Rectangle1(unsigned short width, unsigned short height)
	{
		this->width = width;
		this->height = height;
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

	double Area() const
	{
		return width * height;
	}

	double Perimeter() const
	{
		return 2 * (width + height);
	}

	void Draw() const
	{
		cout << "Rectangle , area = " << Area() << ", perimeter = " << Perimeter() << "\n";
	}

	~Rectangle1()
	{

	}
};

class Rhombus : public Parallelogram
{
protected:
	double diagonal1;
	double diagonal2;	

public:
	Rhombus(): Rhombus(3.0, 3.0, 5.0)
	{
	}
	Rhombus(double side, double diagonal1, double diagonal2)
	{
		this->side = side;
		this->diagonal1 = diagonal1;
		this->diagonal2 = diagonal2;
	}

	unsigned short GetSide() const
	{
		return side;
	}
	
	void SetSide(double side_)
	{
		side_ = side;
	}

	double Area() const
	{
		return (diagonal1 * diagonal2) / 2;
	}

	double Perimeter() const
	{
		return 4 * side;
	}

	void Draw() const
	{
		cout << "Rhombus , area = " << Area() << ", perimeter = " << Perimeter() << "\n";
		
		for (int i = 1; i <= (diagonal1 * 2) + 1; i++)
		{
			for (int j = 1; j <= (diagonal1 * 2) + 1; j++)
			{
				if (i == 1 && j == diagonal1 + 1)
				{
					cout << "*";
				}
				else if (i >= 2 && i <= diagonal1 && j == (diagonal1 + 1) - (i - 1))
				{
					cout << "*";
				}
				else if (i >= 2 && i <= diagonal1 && j == (diagonal1 + 1) + (i - 1))
				{
					cout << "*";
				}
				else if (i >= diagonal1 && j == (i - diagonal1))
				{
					cout << "*";
				}
				else if (i >= diagonal1 && j == (diagonal1 * 2) + 2 - (i - diagonal1))
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << "\n";
		}
	}

	~Rhombus()
	{

	}
};

class Square : public Rectangle1
{
public:
	Square()
	{
		side = 5;
	}

	double Area() const
	{
		return abs(side) * abs(side);
	}

	double Perimeter() const
	{
		return 4 * side;
	}

	void Draw() const
	{
		cout << "Square , area = " << Area() << ", perimeter = " << Perimeter() << "\n";

		for (int i = 1; i <= side; i++) 
		{
			for (int j = 1; j <= side; j++) 
			{
				if (i == 1 || i == side) 
					cout << '*';
				else 
				{
					if (j == 1 || j == side) 
						cout << '*';
					else
						cout << ' ';
				}
			}   
			cout << "\n"; 
		}   
	}

	~Square()
	{

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

	Circle c;
	c.Draw();

	Triangle t;
	t.Draw();

	Quadrilateral q(&x, &x1, &y, &y1, &x2, &x3, &y2, &y3);
	q.Draw();

	AcuteTriangle a;
	a.Draw();

	IsoscelesAcuteTriangle i;
	i.Draw();

	ObtuseTriangle o;
	o.Draw();

	Parallelogram pl;
	pl.Draw();

	Trapezoid tr;
	tr.Draw();

	Deltoid d;
	d.Draw();

	Rectangle1 r;
	r.Draw();

	Rhombus rb;
	rb.Draw();

	Square s;
	s.Draw();
}
