#include "zadatak.h"
#include <iostream>
#include <list>
#include <vector>


int main()
{
   std::vector<int> vec = zadatak1("../../src/brojevi.txt");
   zadatak2("../../src/fpbrojevi.txt");
   std::list<int> l = zadatak3();



 // for(auto x:l) std::cout<<x<<" ";
 // std::cout<<std::endl;

    return 0;
}
