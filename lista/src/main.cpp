#include "lista.h"
#include <iostream>


int main()
{
// Ovdje pišete vlastite testove klase.
    List<int> lista;

    for(int i=10;i>0;--i)
        lista.push_back(i*2);


    lista.ispisi();

    std::cout<<lista.size()<<std::endl;

    //ubaci element na mjesto i
    lista.insert(0,13);
    lista.insert(0,15);
    lista.insert(0,70);
    lista.insert(0,340);


    lista.ispisi();
    //izbaci element na mjestu i
    lista.remove(2);

    lista.ispisi();



    std::cout<<lista.size()<<std::endl;
    std::cout<<"Sort: ";
    lista.sort();
    lista.ispisi();

    lista.setPosition(2);
    std::cout<<lista.current()<<std::endl;
    lista.clear();



   
  return 0;
}
