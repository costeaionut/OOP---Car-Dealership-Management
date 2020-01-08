#pragma once
#include "Mini.h"

class Mica : public Automobil
{
private:
	const std::string tip = "Mic";
public:
	Mica();//Constructor Mica
	Mica(std::string, float, int, int); ///Constructor Mica mode + lungime + litraj + pret
	void showInfo() override;
	Mica& operator= (Mica& cpy);
	friend std::ostream& operator <<(std::ostream& os, const Mica&ob);
	friend std::istream& operator >>(std::istream& is, Mica&ob);
};

Mica::Mica()
	:Automobil("Neidentificat", -1.1, -1, -1)
{};
Mica::Mica(std::string s, float f, int l, int p)
	:Automobil(s, f, l, p)
{
	try
	{
		if (this->lungime < 3.85 || this->lungime > 4.1)
			throw this->lungime;
	}
	catch (float exc)
	{
		while (this->lungime < 3.85 || this->lungime > 4.1)
		{
			std::cout << "Lungimea nu este adecvata pentru o masina de tip Mica." << std::endl << "Introduceti o lungime intre [3.85m,4.1m]:";
			std::cin >> this->lungime;
		}
	}
}
Mica& Mica::operator=(Mica& cpy)
{
	this->model = cpy.model;
	this->lungime = cpy.lungime;
	this->litraj = cpy.litraj;
	this->pret = cpy.pret;
	return *this;
}
std::ostream& operator <<(std::ostream& os, const Mica& ob)
{
	os << "Tipul masinii este: " << ob.tip << std::endl;
	os << "Modelul automobilului este:" << ob.model << std::endl;
	os << "Lungimea automobilului este: " << ob.lungime << "m" << std::endl;
	os << "Litrajul automobilului este: " << ob.litraj << "l" << std::endl;
	os << "Pretul automobilului este: " << ob.pret << "lei" << std::endl;
	return os;
}
std::istream& operator >>(std::istream& is, Mica& ob)
{
	std::string s;
	float f;
	int l, p;
	std::cout << "Introduceti modelul masinii: ";
	is >> s;
	std::cout << "Introduceti lungimea masinii: ";
	is >> f;
	try
	{
		if (f < 3.85 || f > 4.1)
			throw f;
	}
	catch (float exc)
	{
		while (f < 3.85 || f > 4.1)
		{
			std::cout << "Lungimea nu este adecvata pentru o masina de tip Mica." << std::endl << "Introduceti o lungime intre [3.85m,4.1m]:";
			std::cin >> f;
		}
	}
	std::cout << "Introduceti litrajul masinii: ";
	is >> l;
	std::cout << "Introduceti pretul masinii: ";
	is >> p;
	Mica cpy(s,f,l,p);
	ob = cpy;
	return is;
}
void Mica::showInfo()
{
	std::cout << *this;
}