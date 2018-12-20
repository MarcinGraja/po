
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

class Rodzic
{
public:
	virtual void Metoda() = 0;
};
class Potomek : public Rodzic
{
public:
	void Metoda()
	{
		std::cout << "nazwa klasy to Potomek\n";
	}
};
class Bryla
{
public:
	virtual double pole() = 0;
	virtual double objetosc() = 0;

};
class Kula : public Bryla
{
	double r;
public:
	double pole()
	{
		return 4 * M_PI * r*r;
	}
	double objetosc()
	{
		return 4 / 3.0*M_PI*r*r*r;
	}
	double getR()
	{
		return r;
	}
	Kula(double R) : r(R) {}
};
class Prostopadloscian : public Bryla
{
	double a, b, h;
public:
	Prostopadloscian(double A, double B, double H) : a(A), b(B), h(H) {}
	double pole()
	{
		return 2 * a*b + 2 * b*h + 2 * a*h;
	}
	double objetosc()
	{
		return a * b * h;
	}
};
class Ksztalt
{
public:
	virtual void pole() = 0;
};
class Kolo : public Ksztalt
{
	float r;
public:
	Kolo(float R) : r(R) {}
	void pole()
	{
		std::cout << "pole kola:" << r*r*M_PI << std::endl;
	}
};
class Kwadrat : public Ksztalt
{
	float a;
public:
	Kwadrat(float A) : a(A) {}
	void pole()
	{
		std::cout << "pole kwadratu:" << a * a << std::endl;
	}
};
int main()
{
	//class Rodzic r1, r2; // nie działa :/
	class Potomek p1, p2;
	p1.Metoda();
	Kula k1(5), k2(7);
	Prostopadloscian pr1(1, 2, 3), pr2(4, 5, 6);
	std::cout << "k1("<<k1.getR()<<") pole:" << k1.pole() << " k1 objetosc: " << k1.objetosc() << '\n'
		<< "k2("<<k2.getR()<<") pole:" << k2.pole() << " k2 objetosc: " << k2.objetosc() << '\n'
		<< "pr1 pole:" << pr1.pole() << " pr1 objetosc: " << pr1.objetosc() << '\n'
		<< "pr2 pole:" << pr2.pole() << " pr2 objetosc: " << pr2.objetosc() << '\n';
	Kolo ko1(2), ko2(4);
	Kwadrat kw1(7), kw2(3);
	Ksztalt *pko1 = &ko1, *pko2=&ko2, *pkw1=&kw1, *pkw2=&kw2;
	pko1->pole();
	pko2->pole();
	pkw1->pole();
	pkw2->pole();
	std::cin.ignore();
}
