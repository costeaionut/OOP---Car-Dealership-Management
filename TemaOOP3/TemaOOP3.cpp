#include "template.h"

void display(std::set<std::pair<Monovolum*, bool>> s)
{
    std::set<std::pair<Monovolum*, bool>>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        std::cout << *itr->first;
        if (itr->second == false)
            std::cout << "Masina nu este secondhand" << std::endl;
        else
            std::cout << "Masina este secondhand" << std::endl;
    }
}

int main()
{
    //Vanzare<Mini> c(2);
    //std::cout << c;
    std::vector<Mini> A;
    std::vector<Mini> D;
    Mini B("3", 2.88, 250, 350), C("2", 2.99, 230, 111), cpy;
    A.push_back(B);
    A.push_back(C);
    for (auto itr = A.begin(); itr != A.end(); itr++)
    {
        D.push_back(*itr);
        break;
    }
    for (auto itr = D.begin(); itr != D.end(); itr++)
    {
        std::cout << *itr << "BBBBBBBBB";
    }


    /*std::set<std::pair<Monovolum*, bool>> stoc;
    Monovolum A[3], B, C;
    std::cin >> A[0];
    std::cin >> A[1];
    std::cin >> A[2];
    std::pair<Monovolum*, bool> x;

    x = std::make_pair(A, false);
    stoc.insert(x);

    x = std::make_pair(A + 1, true);
    stoc.insert(x);

    x = std::make_pair(A + 2, false);
    stoc.insert(x);

    display(stoc);*/
    
}
