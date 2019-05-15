#include "zadatak.h"
#include <vector>
#include <string>
#include <list>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace std;



std::vector<int> zadatak1(std::string const & file_name){

    ifstream in(file_name);

    if(!in)
        throw runtime_error("File se nije otvorio.");

    istream_iterator<int> isi(in);
    istream_iterator<int> isi_end;

    std::vector<int> vec(isi, isi_end);


    replace(vec.begin(), vec.end(),0, 9);


    return vec;
}

void zadatak2(std::string const & file_name){
      ifstream in(file_name);
      if(!in)
          throw runtime_error("File not found.");

      istream_iterator<float> isi(in);
      istream_iterator<float> isi_end;

      vector<float> vec;
      copy( isi, isi_end , back_inserter(vec));

      ofstream out("3cols.txt");
      if(!out)
          throw runtime_error("File not found.");



      for(auto x: vec)
      out<<setprecision(6)<<showpos<<scientific<<x<<" "<<sin(x)<<" "<<exp(x)<<endl;
}

std::list<int> zadatak3(){
    list<int> first_list{1,2,3,4,5,6,7,8,9};
    list<int> second_list{1,2,3,4,5,6,7,8,9};



    while(*first_list.begin()!=5)
        next_permutation(first_list.begin(),first_list.end());

    while( *second_list.begin()!=9)
        next_permutation(second_list.begin(),second_list.end());




    auto it3=find(first_list.begin(), first_list.end(), 3);
    assert(it3!=first_list.end());
    auto it4=find(second_list.begin(), second_list.end(), 4);
    assert(it4!=second_list.end());
    auto it7=find(second_list.begin(), second_list.end(), 7);
    assert(it7!=second_list.end());



    auto ch=find(it4, second_list.end(), 7);
    if(ch==second_list.end())
        swap(it4,it7);
    first_list.splice(it3,second_list,it4,it7);

    return first_list;
}


