#include "isort.h"
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   

    vector<double> V{1.2, 2.3, 7.1, 1.1, 2.4};
    list<double> L{7.3, 2.4, 4.5, 0.3, 1.1};
    vector<string> VS{"pig", "dog", "elephant", "cat", "arrow"};

    cout<<"Vektor V prije sortiranja: ";
    for(auto x: V) cout<<x<<" ";
    cout<<endl;

    insertion_sort_ind(V);

    cout<<"Vektor V nakon sortiranja: ";
    for(auto x: V) cout<<x<<" ";

    cout<<endl;

    cout<<"Lista L prije sortiranja: ";
    for(auto x: L) cout<<x<<" ";
    cout<<endl;

    insertion_sort(L.begin(), L.end());

    cout<<"Lista L nakon sortiranja: ";
    for(auto x: L) cout<<x<<" ";

    cout<<endl;

    cout<<"Vektor VS prije sortiranja: ";
    for(auto x: VS) cout<<x<<" ";
    cout<<endl;

    insertion_sort1(VS.begin(), VS.end());

    cout<<"Vektor VS nakon sortiranja: ";
    for(auto x: VS) cout<<x<<" ";

    cout<<endl;


    return 0;
}
