#pragma once
#include "Monovolum.h"

template <class T>
class Vanzare
{
protected:
	int masini_stoc;
	int masini_vandute;
	std::vector<T> stoc;
	std::vector<T> vandute;
public:
	Vanzare()
	{
		this->masini_stoc = -1;
		this->masini_vandute = -1;
	} // Constructor simplu
	Vanzare(int nr_stoc);
	Vanzare& operator-=(int masini)
	{
		std::cout << masini;
		std::cout << this->masini_stoc;
		if (masini < this->masini_stoc)
		{
			for (auto itr = this->stoc.rbegin(); itr != this->stoc.rend(); itr++)
			{
				if (this->masini_vandute != masini)
				{
					this->masini_vandute++;
					this->vandute.push_back(*itr);
				}
			}
			while (masini != 0)
			{
				this->masini_stoc--;
				masini--;
				this->stoc.pop_back();
			}
		}
		else
			std::cout << "Nu sunt suficiente masini in stoc";

		return *this;
	}
	//Constructor cu nr masini stoc + masinile din stoc
	friend std::ostream& operator <<(std::ostream& os, const Vanzare<T>& ob)
	{
		os << "Numarul de masini din stoc sunt: " << ob.masini_stoc << std::endl << "Masinile din stoc sunt: ";
		for (auto i = ob.stoc.begin(); i != ob.stoc.end(); i++)
			os << *i;
		os << "Numarul de masini vandute sunt: " << ob.masini_vandute << std::endl;
		if (ob.vandute.empty() == 1)
			std::cout << "Nu au fost vandute masini";
		else
			for (auto j = ob.vandute.begin(); j != ob.stoc.end(); j++)
				os << *j;
		return os;
	}
};
template<class T>
Vanzare<T>::Vanzare(int nr_stoc)
{
	T masina;
	this->masini_stoc = nr_stoc;
	for (int itr = 1; itr <= this->masini_stoc; itr++)
	{
		std::cin >> masina;
		this->stoc.push_back(masina);
	}
}

template<>
class Vanzare<Monovolum>
{
protected:
	int masini_stoc;
	int masini_vandute;
	std::set<std::pair<Monovolum*, bool>> stoc;
	std::vector<Monovolum> vandute;
public:
	Vanzare(int nr_stoc);
};
Vanzare<Monovolum>::Vanzare(int nr_stoc)
	:masini_stoc(nr_stoc)
{
	Monovolum *masina;
	masina = new Monovolum;
	std::pair<Monovolum*, bool> x;
	for (int itr = 1; itr <= this->masini_stoc; itr++)
	{
		std::cin >> *masina;
		x = std::make_pair(masina, masina->getSh());
		this->stoc.insert(x);
	}
}