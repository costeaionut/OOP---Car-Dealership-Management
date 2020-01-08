#pragma once
#include "Automobil.h"

class Mini : public Automobil
{
private:
	const std::string tip = "Mini";
public:
	Mini();//Constructor MINI 
	Mini(std::string, float, int, int);//Constructor MINI cu model + lungime + litraj + pret
	void showInfo() override;
	Mini& operator=(Mini&);
	friend std::ostream& operator <<(std::ostream&, const Mini&);
	friend std::istream& operator >>(std::istream&, const Mini&);
};

Mini::Mini()
	:Automobil("Neidentificat", -1, -1, -1)
{};
Mini::Mini(std::string s, float f, int l, int p)
	:Automobil(s, f, l, p)
{
	try
	{
		if (this->lungime > 4.0)
			throw this->lungime;
	}
	catch (float exc)
	{
		while (this->lungime > 4.0)
		{
			std::cout << "Lungimea nu este adecvata pentru o masina de tip Mini." << std::endl << "Introduceti o lungime mai mica de 4m:";
			std::cin >> this->lungime;
		}
	}
}
Mini& Mini::operator=(Mini& cpy)
{
	this->model = cpy.model;
	this->lungime = cpy.lungime;
	this->litraj = cpy.litraj;
	this->pret = cpy.pret;
	return *this;
}
std::ostream& operator <<(std::ostream& os, const Mini& ob)
{
	os << "Tipul masinii este: " << ob.tip << std::endl;
	os << "Modelul automobilului este:" << ob.model << std::endl;
	os << "Lungimea automobilului este: " << ob.lungime << "m" << std::endl;
	os << "Litrajul automobilului este: " << ob.litraj << "l" << std::endl;
	os << "Pretul automobilului este: " << ob.pret << "lei" << std::endl;
	return os;
}
std::istream& operator >>(std::istream& is, Mini& ob)
{
	std::string mod;
	float lung;
	int pr, litr;
	std::cout << "Introduceti modelul masinii: ";
	is >> mod;
	std::cout << "Introduceti lugimea masinii:";
	is >> lung;
	try
	{
		if (lung > 4)
			throw lung;
	}
	catch (float exc)
	{
		while (lung > 4)
		{
			std::cout << "Lungimea nu este adecvata pentru o masina de tip Mini." << std::endl << "Introduceti o lungime mai mica de 4m:";
			std::cin >> lung;
		}
	}
	std::cout << "Introduceti litrajul masinii: ";
	is >> litr;
	std::cout << "Introduceti pretul masinii: ";
	is >> pr;
	Mini cpy(mod, lung, litr, pr);
	ob = cpy;
	return is;
}
void Mini::showInfo()
{
	std::cout << *this;
}