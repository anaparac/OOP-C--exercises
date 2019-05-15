#ifndef _VECT_H_IS_INCLUDED_
#define _VECT_H_IS_INCLUDED_

#include <iostream>
#include <string>
#include <iterator>

using namespace std;

// deklaracija potrebna za testiranje
template <typename> class VectTest;

template <typename T>
class Vect
{
    friend class VectTest<T>;  // da testovi mogu dohvatiti privatne varijable
public:

    // Ctor - s parametrima i bez
    explicit Vect(size_t n = 0, T v= {});



    // Kontrola kopiranja dolazi ovdje
    // CCtor
    Vect<T> (const Vect<T>& v);

    // MCtor
    Vect<T> (Vect<T> && v) noexcept;

    // OP
    Vect<T>& operator=(const Vect<T>& v);

    // MOP
    Vect<T>& operator=(Vect<T> && v) noexcept;

    // DTOR
    ~Vect<T> ();

    // dohvat elemenata (operator [])
    T operator [](int n) const;

    // push_back metoda
    void push_back(T t);

     // info rutine size() i capacity()
    size_t size();
    //const verzija
    size_t size() const;

    size_t capacity() const;

    // operatori +=, -=, *=
    // provjeriti da li se ockeuje da ovo zbroji sve vrijednosti s nekim skalarom ili s drugim vektorom, takodjer je li potrebno omoguciti ulancavanje
    void operator +=(Vect<T> &v);

    void operator -=(Vect<T> &v);

    void operator *=(T t);

    // euklidska norma vraća double !
     double two_norm() const;


     //'op koji ne pripadaju klasi'
     template <typename V>
     friend Vect<V> operator +( Vect<V> & vect1, Vect<V> & vect2 );

     template <typename V>
     friend Vect<V> operator -( Vect<V> & vect1, Vect<V> & vect2 );

     template <typename V>
     friend std::ostream & operator <<( std::ostream & out, Vect<V> const& vect );


private:
        T *mdata;       // pokazivač na prvi element
        T *mfirst_free; // pokazivač na prvo slobodno mjesto
        T *mend;        // pokazivač na kraj alociranog prostora
                             // (jedno mjesto iza posljednjeg)

        // Oslobodi zauzeti prostor (pomoću alokatora)
        void free();

        // realociraj na novu lokaciju. Povećaj dimenziju vektora 2 puta; ako je
        // vektor prazan alociraj jedan element.
        void reallocate();

        // dodati vlastite privatne metode.

        // alokator ne mora imati pristup varijablama članicama klase pa ga činimo
        // statičkim. Ne zaboraviti definirati ga.
        static std::allocator<T> alloc;

};


// Implementacija je u posebnoj .h datoteci
#include "vect_impl.h"

#endif
