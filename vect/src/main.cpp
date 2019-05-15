#include "vect.h"

using namespace std;

int main()
{
    // Vaši testovi dolaze ovdje.
    Vect<int> v;
    v.push_back(4);
    v.push_back(1);
    cout<<"v: "<<v<<endl;

    size_t n = 10;
    Vect<int> v1(n, 3);
    Vect<int> v2(n, 4);
    cout<<"v1: "<<v1<<endl;
    cout<<"v2: "<<v2<<endl;

    cout<<endl;
    cout<<"Duljina vektora v2 je: "<<v2.size()<<endl;


    v1+=v2;
    cout<<"v1+=v2: "<<v1<<endl;
    v*=4;
    cout<<"v1*=4: "<<v<<endl;

    auto v3=v1+v2;
    cout<<"v3=v1+v2: "<<v3<<endl;
    cout<<"v[0]: "<<v[0]<<endl;

    auto v4=v;
    v4.push_back(5);
    cout<<"v4:"<<v4<<endl;
    return 0;
}
