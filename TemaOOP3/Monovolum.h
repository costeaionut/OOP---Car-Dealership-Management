#pragma once
#include "Compact.h"

class Monovolum : public Automobil
{
private:
	const std::string tip = "Monovolum";
	int cap_pers;
	bool sh;
	int ani_vechime;
public:
	Monovolum(); //Constructor MONOVOLUM simplu
	Monovolum(std::string, int, int, int, bool); //Constructor MONOVOLUM model +  litraj + pret + capacitate
	Monovolum& operator=(Monovolum& cpy);
	friend std::ostream& operator <<(std::ostream&, const Monovolum&);
	friend std::istream& operator >>(std::istream& is, Monovolum& ob);
	bool getSh() { return this->sh; }
	void showInfo();
};

Monovolum::Monovolum()
	:Automobil("Necunoscut", -1, -1, -1), cap_pers(-1), sh(0)
{}
Monovolum::Monovolum(std::string s, int litr, int pret, int nr_pers, bool sh)
	:Automobil(s, litr, pret), cap_pers(nr_pers), sh(sh)
{
	try
	{
		if (nr_pers < 5 || nr_pers > 7)
			throw nr_pers;
	}
	catch (const int exc)
	{
		while (nr_pers < 5 || nr_pers > 7)
		{
			std::cout << "Numarul de persoane este invalid va rugam introduceti un numar in intervalul :";
			std::cin >> nr_pers;
		}
	}
	this->cap_pers = nr_pers;
	if (this->sh == true)
	{
		std::cout << "Introduceti anii vechime: ";
		std::cin >> this->ani_vechime;
	}
}
Monovolum& Monovolum::operator=(Monovolum& cpy)
{
	this->model = cpy.model;
	this->litraj = cpy.litraj;
	this->pret = cpy.pret;
	this->lungime = cpy.lungime;
	this->cap_pers = cpy.cap_pers;
	this->sh = cpy.sh;
	this->ani_vechime = cpy.ani_vechime;
	return *this;
}
std::ostream& operator <<(std::ostream& os, const Monovolum& ob)
{
	os << "Tipul masinii este: " << ob.tip << std::endl;
	os << "Modelul masinii este: " << ob.model << std::endl;
	os << "Numarul de persoane din masina: " << ob.cap_pers << std::endl;
	os << "Litrajul masinii este: " << ob.litraj << "l" << std::endl;
	os << "Pretul masinii este: " << ob.pret << "lei" << std::endl;
	if (ob.sh == 1)
	{
		os << "Masina este secondhand!";
		os << "Anii vechime sunt: " << ob.ani_vechime;
	}
	else
		os << "Masina nu este secondhand!";
	return os;
}
std::istream& operator >>(std::istream& is, Monovolum& ob)
{
	std::string m;
	int lit, pr, nr_per;
	std::cout << "Introduceti modelul masinii: ";
	std::cin >> m;
	std::cout << "Introduceti litrajul masinii: ";
	std::cin >> lit;
	std::cout << "Introduceti pretul masinii: ";
	std::cin >> pr;
	std::cout << "Introduceti capacitatea de transport a masinii: ";
	std::cin >> nr_per;
	try
	{
		if (nr_per < 5 || nr_per > 7)
			throw nr_per;
	}
	catch (int exc)
	{
		while (nr_per < 5 || nr_per > 7)
		{
			std::cout << "Capacitatea introdusa nu este valida. Va rugam introduceti alta din intervalul [5,7]: ";
			std::cin >> nr_per;
		}
	}
	bool s;
	std::cout << "Este masina secondhand?" << std::endl << "0.Nu" << std::endl << "1.Da";
	std::cout << std::endl << "0/1: ";
	std::cin >> s;
	Monovolum cpy(m, lit, pr, nr_per, s);
	ob = cpy;
	return is;
}
void Monovolum::showInfo()
{
	std::cout << *this;
}