#include <iostream>
#include "zadatak.h"
#include <string>
#include <utility>
#include <list>
#include <map>
#include <vector>



int main()
{


   //test za fju procitaj_rijec
    std::string s("Ovo je testni string.");
        std::string::const_iterator iter=s.begin();
        std::string prva=procitaj_rijec(iter, s.end());
        std::cout<<prva<<std::endl;


   //test za fju procitaj_datoteku()
        std::map<std::string,int>  word_list;
            procitaj_datoteku("1.txt", word_list);

            for(auto x: word_list) std::cout<<x.first<<" -> "<<x.second<<std::endl;


   //test za fju naj()
    std::map<std::string, int> m{{"pas", 2}, {"macka", 3}, {"svinja", 3}};
    auto par=naj(m);

    for(auto it : par.first)
      std::cout<<it<<" ";
      std::cout<<par.second<<std::endl;


    //test za fju broj_iz_grupe()
      std::map<std::string, int> tekst={{"pas",2}, {"macka", 2}, {"mis", 3}, {"konj", 4}, {"je", 6}, {"su", 4}};
      std::multimap<std::string,std::string> grupa={{"a","pas"}, {"a","v"}, {"b", "konj"}, {"b", "mis"}, {"c","pjetao"}};
      auto vec=broj_iz_grupe(tekst,grupa);
      for(auto x: vec)  std::cout<<x<<" ";
      std::cout<<std::endl;

    return 0;
}
