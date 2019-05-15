#ifndef _ISORT_H_
#define _ISORT_H_
#include <vector>
#include <algorithm>


// Verzija s indeksima
template <typename Record>
void insertion_sort_ind(std::vector<Record>& vec){
    Record aux;
    int len=vec.size();
    for(auto i=1;i<len;++i){
        aux=vec[i];

        for(auto j=i;j>0 && vec[j-1]>aux;j--){
            vec[j]=vec[j-1];
            vec[j-1]=aux;

        }
    }
}


// Verzija koja uzima iterator range -- koristiti samo std::next i std::prev
template <typename Iter>
void insertion_sort(Iter first, Iter last){
    
    for(auto i=std::next(first);i!=last;i=std::next(i)){

            auto aux=*i;

                for(auto j=i;j!=first && *std::prev(j)>*j;j=std::prev(j)){


                    *j=*(std::prev(j));
                    *std::prev(j)=aux;

                }

    }
}

// verzija sa algoritmima std::rotate i std::upper_bound
template <typename Iter>
void insertion_sort1(Iter first, Iter last){

    for(auto i=std::next(first); i!=last; i=std::next(i))
        std::rotate(std::upper_bound(first, i, *i), i, std::next(i));
}


#endif
