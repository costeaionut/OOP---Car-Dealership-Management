#pragma once
#include <set>
#include <utility>
#include <string>
#include<utility>
#include <iostream>
#include <vector>
#include <iterator>

class Automobil
{
protected:
    std::string model;
    float lungime;
    int litraj;
    int pret;
public:
    Automobil(); //Constructor
    Automobil(std::string); //Constructor cu model
    Automobil(std::string, float); //Constructor cu model + lungime
    Automobil(std::string, float, int); //Constructor cu model + lungime + litraj
    Automobil(std::string, int, int); //Consturctor cu model + litraj + pret;
    Automobil(std::string, float, int, int); //Constructor cu model + lungime + litraj + pret PT MONOVOLUM
    void virtual showInfo() = 0;
};

Automobil::Automobil()
    :model("Necunoscut"), lungime(-1.0), litraj(-1), pret(-1)
{};
Automobil::Automobil(std::string nume_model)
    :model(nume_model), lungime(-1.0), litraj(-1), pret(-1)
{};
Automobil::Automobil(std::string nume_model, float lung)
    :model(nume_model), lungime(lung), litraj(-1), pret(-1)
{};
Automobil::Automobil(std::string nume_model, float lung, int litrj)
    :model(nume_model), lungime(lung), litraj(litrj), pret(-1)
{}
Automobil::Automobil(std::string nume_mode, int litr, int prt)
    :model(nume_mode), lungime(-1), litraj(litr), pret(prt)
{}
Automobil::Automobil(std::string nume_model, float lung, int litrj, int p)
    :model(nume_model), lungime(lung), litraj(litrj), pret(p)
{};