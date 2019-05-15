#include "zadatak.h"
#include <string>
#include <utility>
#include <list>
#include <map>
#include <iterator>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <iostream>



std::string procitaj_rijec(std::string::const_iterator & it, std::string::const_iterator itend)
{
    auto br=0;      //brojac za pomak iterator na prvi znak koji nije rijec
      auto i=it;    //s i se krece po stringu

      for(;i<itend && *i!='"' && *i!='"' && *i!='\n' && *i!=' ' && *i!='\t' && *i!='\v' && *i!='.' && *i!=',' && *i!='!' && *i!='?' && *i!=':' && *i!=';' && *i!='(' && *i!=')'; i++)
          br++;

        std::string rijec(it, it+br);

          it=i;


      return rijec;
}



void procitaj_datoteku(std::string file_name, std::map<std::string,int> & word_list){       //-->

    std::ifstream infile(file_name);
      if(!infile) throw std::runtime_error("Datoteka se nije otvorila.");

      std::string line;

     while(std::getline(infile, line)){


          std::string::const_iterator iter=line.begin();
          while(iter != line.end()){
              while(*iter=='"' || *iter=='\n' || *iter==' ' || *iter=='\t' || *iter=='\v' || *iter=='.' || *iter==',' || *iter=='!' || *iter=='?' || *iter==':' || *iter==';' || *iter=='(' || *iter==')' ) iter++;
              if(iter==line.end()) break;
              std::string s=procitaj_rijec(iter, line.end());
              auto it=word_list.find(s);
               if(it==word_list.end())
                  word_list.insert(std::make_pair(s,1));
              else
                  it->second++;
          }
     }

}


std::pair<std::list<std::string>, int> naj(std::map<std::string,int> const & word_list){            // --> OK
    int max(0);
    std::list<std::string> rijeci;

      //naci max value
      for(auto x: word_list)
          if(x.second>max)
              max=x.second;

      //stavi rijeci s max value u listu
      for(auto x: word_list)
          if(x.second==max)
              rijeci.push_back(x.first);


      auto lista=make_pair(rijeci,max);

      return lista;


}


std::vector<int>
broj_iz_grupe(std::map<std::string,int> const & word_list,
              std::multimap<std::string, std::string> const & grupe){           // --> OK

    //iterator na pocetak multimape
    auto pocetak=grupe.begin();


    int sum;
    std::vector<int> vec_sum;

    while(pocetak!=grupe.end()){
        //key je ime grupe
        auto key=pocetak->first;

        //nademo par iteratora raspona elemenata iz trenutne grupe
        auto raspon=grupe.equal_range(key);
        sum=0;

        //obradi elemente iz trenutne grupe
        for(auto it = raspon.first; it != raspon.second; it++){
            auto po=word_list.find(it->second);
            if(po!=word_list.end())
                sum+=po->second;

        }

        vec_sum.push_back(sum);

    //idemo na iducu grupu
    pocetak=raspon.second;

    }

    return vec_sum;
}
