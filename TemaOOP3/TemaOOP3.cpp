#include "template.h"

void display(std::set<std::pair<Monovolum*, bool>> s)
{
    std::set<std::pair<Monovolum*, bool>>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        std::cout << *itr->first;
    }
}

int main()
{
    Vanzare<Monovolum> c(3);
    
}
