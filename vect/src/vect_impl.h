// Vaša implementacija dolazi ovdje.

#include <memory>
#include <iterator>
#include <stdexcept>
#include <cmath>




//definicija alokatora
template <typename T>
allocator<T> Vect<T>::alloc;

//obicni konstruktor
template<typename T>
Vect<T>::Vect (size_t n, T t){
    //ako je n=0 konstruiramo prazan vektor
    if ( n == 0 ){
        mdata = nullptr;
        mend  = nullptr;
        mfirst_free = nullptr;

    }
    else {//alociramo memoriju za vektor duljine 2n
        mdata = alloc.allocate(2*n);
        mfirst_free = mdata;
        //ispunimo prvih n mjesta s inicijalnom vrijednoscu t
        for( size_t i = 0; i < n; ++i ){
            alloc.construct( mfirst_free, t );
            mfirst_free = next( mfirst_free, 1);
        }
        mend  = next(mdata, 2*n);
    }
}



// CCtor
template<typename T>
Vect<T>::Vect ( const Vect<T>& vect){
    //provjeri ima li vec konstruiranih vrijednosti u vektoru vect
    size_t n = vect.capacity();
    if ( n != 0 ){
        //poduplamo kolicinu memorije za vektor
        mdata = alloc.allocate(n);
        mfirst_free = mdata;
        //konstruiraj objekte koje smo vec imali u vect
        for( size_t i = 0; i < vect.size(); ++i ){
            alloc.construct( mfirst_free, vect[i] );
            mfirst_free = next( mfirst_free, 1);
        }
        mend  = next(mdata, n);
    }
    //ako je vect bio prazan
    else {
        mdata = nullptr;
        mfirst_free = nullptr;
        mend  = nullptr;

    }
}

// MCtor
template<typename T>
Vect<T>::Vect ( Vect<T> && vect) noexcept{
    mdata = vect.mdata;
    mfirst_free = vect.mfirst_free;
    mend = vect.mend;

    vect.mdata = nullptr;
    vect.mfirst_free = nullptr;
    vect.mend = nullptr;

}



// OP
template<typename T>
Vect<T>& Vect<T>::operator=( const Vect<T>& vect){
    if (mdata != vect.mdata){
        free();
        size_t n = vect.capacity();
        if ( n == 0 ){
            mdata = nullptr;
            mend  = nullptr;
            mfirst_free = nullptr;
        }
        else {
            //ako vect nije bio prazan
            mdata = alloc.allocate(n);
            mfirst_free = mdata;

            for( size_t i = 0; i < vect.size(); ++i ){
                alloc.construct( mfirst_free, vect[i] );
                mfirst_free = next( mfirst_free, 1);
            }
            mend  = next(mdata, n);
        }
    }
    return *this;
}

// MOP
template<typename T>
Vect<T>& Vect<T>::operator =( Vect<T> && vect) noexcept{
    if ( mdata != vect.mdata ){
        free();
        mdata = vect.mdata;
        mfirst_free = vect.mfirst_free;
        mend = vect.mend;

        vect.mdata = nullptr;
        vect.mfirst_free = nullptr;
        vect.mend = nullptr;
    }
    return *this;
}



// DTOR
template<typename T>
Vect<T>::~Vect(){
    free();
}





// []
template<typename T>
T Vect<T>::operator []( int i ) const{

    auto element = mdata;
    //pomaknemo se za i mjesta od prvog, ako je i=0 ostat cemo na prvom elementu
    element = next(mdata, i);

    return *element;
}

// push_back
template<typename T>
void Vect<T>::push_back( T t ){

    //ako vise nema slobodnog mjesta realociraj memoriju
    if ( mfirst_free == mend )
        reallocate();

    *mfirst_free = t;
    //ako je vektor bio prazan
    if ( mdata == nullptr )
        mdata = mfirst_free;
    mfirst_free  = next( mfirst_free, 1 );

}

// size() - nekonstantni
template<typename T>
size_t Vect<T>::size(){
    return ( size_t )distance( mdata, mfirst_free );
}

//size() - konstantni
template<typename T>
size_t Vect<T>::size() const{
    return ( size_t )distance( mdata, mfirst_free );
}

//capacity()
template<typename T>
size_t Vect<T>::capacity() const{
    return ( size_t )distance( mdata, mend );
}

//+=
template<typename T>
void Vect<T>::operator +=( Vect<T>& vect ){

    int i = 0;
    for ( auto el = mdata ; el != mfirst_free; el = next(el, 1),i++){
        *el += vect[i];
    }
}

//-=
template<typename T>
void Vect<T>::operator -=( Vect<T> &vect ){
    int i = 0;
    for ( auto el = mdata ; el != mfirst_free; el = next(el, 1), i++){
        *el -= vect[i];
    }
}

//*=
template<typename T>
void Vect<T>::operator *=( T t ){
    for (auto el = mdata ; el != mfirst_free; el = next(el, 1)){
        *el *= t;
    }
}

// euklidska norma
template<typename T>
double Vect<T>::two_norm() const{

    double x = 0;
    for (auto i  = mdata; i!= mfirst_free; i = next(i, 1)){
        x += (*i)*(*i);
    }
    return sqrt(x);
}


//alokatorom alociramo novu memoriju
template<typename T>
void Vect<T>::reallocate(){
    if ( size() == 0 ){
        //ako je vektor bio prazan alociramo samo jedno novo mjesto
        mfirst_free = alloc.allocate(1);
        mdata = nullptr;
        mend = next(mfirst_free,1);

    }
    else{//ako nije bio prazan poduplamo memoriju i konstruiramo stare objekte u novom vektoru
         //oslobodimo staru memoriju
        size_t duplo = 2*capacity();

        auto nova = alloc.allocate( 2*capacity() );
        auto prvi= nova;

        for( auto i = mdata; i != mfirst_free; i = next(i, 1) ){
            // konstruiramo objekte iz vet
            alloc.construct( nova, *i);
            nova = next(nova, 1);
        }
        //oslobodimo staru memoriju
        free();
        //postavimo pokazivace
        mdata = prvi;
        mfirst_free = nova;
        mend = next (mdata, duplo );
    }
}



// alokatorom oslobodimo zauzetu memoriju
template<typename T>
void Vect<T>::free(){
   //unisti objekte i oslobodi memoriju
    for ( auto i = mdata ; i != mfirst_free; i = next(i, 1) )
        alloc.destroy(i);

    alloc.deallocate(mdata, capacity());
}


//operatori izvan kalse

//operator +
template <typename T>
Vect<T> operator +( Vect<T> &vect1, Vect<T> & vect2 ){
    Vect<T> v;
    for( size_t i = 0; i < vect1.size() ; i++ ){
        v.push_back( vect1[i] + vect2[i]);
    }
    return v;
}

//operator -
template <typename T>
Vect<T> operator -( Vect<T> &vect1, Vect<T> &vect2 ){
    Vect<T> v;
    for( size_t i = 0; i < vect1.size() ; i++ ){
        v.push_back( vect1[i] - vect2[i]);
    }
    return v;
}


//operator <<
template <typename T>
std::ostream & operator <<( std::ostream & out, Vect<T> const& vect ){
    out << "[";
    for ( auto i = vect.mdata ; i != vect.mfirst_free; i = next(i,1)){
        out <<*i;
        if( next(i,1)!= vect.mfirst_free )
            out<<",";
    }
    out << "]";
    return out;
}
