#pragma once
#include "Mica.h"

class Compact : public Automobil
{
private:
	 const std::string tip = "Compact";
public:
	Compact(); ///Constructor Compact
	Compact(std::string, float, int, int); ///Constructor Compact Model + lungime + litraj + pret
	void showInfo() override;
	Compact& operator= (Compact& cpy);
	friend std::ostream& operator <<(std::ostream& os, const Compact& ob);
	friend std::istream& operator >>(std::istream& is, Compact& ob);

};

Compact::Compact()
	:Automobil("Necunoscut", -1, -1, -1)
{}
Compact::Compact(std::string r_model, float r_lungime, int r_litraj, int r_pret)
{
	try
	{
		if (r_model != "hatchback" && r_model != "sedan" && r_model != "combi")
			throw r_model;
		this->model = r_model;
		this->lungime = r_lungime;
		this->litraj = r_litraj;
		this->pret = r_pret;
	}
	catch (std::string s)
	{
		while (r_model != "hatchback" && r_model != "sedan" && r_model != "combi")
		{
			std::cout << "Modelul masinii nu este bun, introduceti hatchback, sedan sau combi" << std::endl;
			std::cout << "Introduceti modelul masinii (hatchback/sedan/combi): ";
			std::cin >> r_model;
		}
	}
	this->model = r_model;
	this->lungime = r_lungime;
	try
	{
		if (this->lungime < 4.2 || this->lungime > 4.5)
			throw this->lungime;
	}
	catch (float excp)
	{
		while (this->lungime < 4.2 || this->lungime > 4.5)
		{
			std::cout << "Lungimea nu este adecvata pentru o masina de tip Compact." << std::endl << "Introduceti o lungime intre [4.2m,4.5m]:";
			std::cin >> this->lungime;
		}
	}
	this->litraj = r_litraj;
	this->pret = r_pret;
}
Compact& Compact::operator= (Compact& cpy)
{
	this->model = cpy.model;
	this->lungime = cpy.lungime;
	this->litraj = cpy.litraj;
	this->pret = cpy.pret;
	return *this;
}
std::ostream& operator <<(std::ostream& os, const Compact& ob)
{
	os << "Tipul masinii este: " << ob.tip << std::endl;
	os << "Modelul masinii este: " << ob.model << std::endl;
	os << "Lungimea masinii este: " << ob.lungime << "m" << std::endl;
	os << "Litrajul masinii este: " << ob.litraj << "l" << std::endl;
	os << "Pretul masinii este: " << ob.pret << "lei" << std::endl;
	return os;
}
std::istream& operator >>(std::istream& is, Compact& ob)
{
	std::string r_model;
	float r_lungime;
	int r_litraj;
	int r_pret;
	std::cout << "Introduceti modelul masinii(hatchback/sedan/combi): ";
	try
	{
		is >> r_model;
		if (r_model != "hatchback" && r_model != "sedan" && r_model != "combi")
			throw r_model;
	}
	catch (std::string s)
	{
		while (r_model != "hatchback" && r_model != "sedan" && r_model != "combi")
		{
			std::cout << "Modelul masinii nu este bun, introduceti hatchback, sedan sau combi" << std::endl;
			std::cout << "Introduceti modelul masinii (hatchback/sedan/combi): ";
			is >> r_model;
		}
	}
	std::cout << "Introduceti lungimea masinii: ";
	is >> r_lungime;
	try
	{
		if (r_lungime < 4.2 || r_lungime > 4.5)
			throw r_lungime;
	}
	catch (float excp)
	{
		while (r_lungime < 4.2 || r_lungime > 4.5)
		{
			std::cout << "Lungimea nu este adecvata pentru o masina de tip Compact." << std::endl << "Introduceti o lungime intre [4.2m,4.5m]:";
			is >> r_lungime;
		}
	}
	std::cout << "Introduceti litrajul masinii: ";
	is >> r_litraj;
	std::cout << "Introduceti pretul masinii: ";
	is >> r_pret;
	Compact A(r_model, r_lungime, r_litraj, r_pret);
	ob = A;
	return is;
}
void Compact::showInfo()
{
	std::cout << *this;
}
