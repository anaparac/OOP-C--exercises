#ifndef LISTA_H
#define LISTA_H 

#include <cstddef>  // za std::size_t
#include <stdexcept>
#include <cassert>
#include <iostream>

template <typename> class ListTest;

// Paramtrizirana struktura koja predstavlja čvor u listi.
// Sadrži vrijednost (value) i pokazivače na prethodni i sljedeći
// element u listi.
template <typename T>
struct Node{
	T value{};
	Node * previous = nullptr;
	Node * next = nullptr;
};

/**
 * Dvostruko povezana lista s elementima indeksiranim cjelobrojnim indeksima.
 * Indeksi elemenata počinju s nulom. Sve metode koje uzimaju indeks provjeravaju
 * da li je unutar granica i u suprotnom izbacuju std::runtime_error.  
 **/
template <typename T>
class List{
    friend class ListTest<T>;
	public:
		// Konstruktor
		List() :  mSize(0), mPositionIdx(0), mStart(nullptr), mPosition(nullptr) {}

        // Destruktor
		~List() { clear(); }

        // Obriši (dealociraj) sve elemente liste.
		void clear();

        // Da li je lista prazna?
		bool empty() const;

        // Broj elemenata u listi.
		std::size_t size() const;

        // Ubaci element "t" na poziciju "i" u listi. Pozicija "i" mora biti važeća
		// i tada se element ubacuje na to mjesto, a prijašnji "i"-ti element postaje 
		// "i"+1-vi element. Pozicija "i" može biti jednaka size()  i tada se element ubacuje na kraj liste. 
		// Metoda mora ispravno ubacivati i u praznu listu. Metoda pozicionira listu na novom
		// i-tom elementu (pozivom metode setPosition()). 
                // Novi element se alocira dinamički pomoću new operatora.
		void insert(std::size_t i, T const & t);

        // Izbaciti element iz liste i dealocirati ga pomoću delete. Trenutna pozicija
		// nakon izbacivanja pokazuje na prethodni element ako postoji; kada se izabacuje prvi element
		// onda pokazuje na novi prvi element ili lista ostaje prazna. 
		void remove(std::size_t i);

        // Postaviti trenutnu poziciju na i-to mjesto. Dozvoljeni "i" ide od 0 do
        // size()-1. Inače izbaci izuzetak std::runtime_error.
		void setPosition(std::size_t i) const;

        // Vrati selektirani element. Konstantan verzija.
                T const & current() const;

        // Vrati selektirani element. Nekonstantna verzija.
                T & current();

        // Dodaje element na kraj liste. Listu pozicionira na novom elementu.
		void push_back(T const & t);

        // Sortira listu pomoću operatora <. Implementirati "insertion sort".
                void sort();




        void ispisi(){
                    auto it=mStart;

                    std::cout<<"{ ";
                    while(it!=nullptr){
                        std::cout<<it->value<<" ";
                        it=it->next;

                    }
                        std::cout<<"}"<<std::endl;
        }

    private:
       std::size_t mSize;
       mutable std::size_t mPositionIdx;
           Node<T> * mStart;
       mutable Node<T> * mPosition;

	   // Vrati pokazivač na selektirani node.
	   Node<T> * currentNode() { return mPosition; }
};


template <typename T>
bool List<T>::empty() const { 
  // Implementacija
    return (mSize==0);
}

template <typename T>
std::size_t List<T>::size() const { return mSize; }

template <typename T>
T const & List<T>::current() const {
 // Implementacija
    return mPosition->value;
}

template <typename T>
T & List<T>::current() {
 // Implementacija
    return mPosition->value;
}

template <typename T>
void List<T>::setPosition(std::size_t i) const{
 // Implementacija

    if(i < 0 || i > mSize)
        throw std::runtime_error("error - setPosition");

    mPositionIdx=i;
    auto it=mStart;
    while(i>0) {it=it->next;  i--;}
    mPosition=it;


}


template <typename T>
void List<T>::insert(std::size_t i, T const & t){
 // Implementacija
     if(i < 0 || i > mSize+1)
        throw std::runtime_error("error - insert");


     struct Node<T> *novi = new Node<T>;
     if(!mSize){
         novi->value=t;
         mStart=novi;
     }
     else{
     if(!i){

         novi->value=t;

         novi->next=mStart;
         mStart->previous=novi;
         mStart=novi;

     }
     else if(i==mSize){
         novi->value=t;
         setPosition(mSize-1);

         mPosition->next=novi;
         novi->previous=mPosition;


     }
     else{
         novi -> value=t;
         setPosition(i);
         auto tmp = mPosition->previous;
         novi -> previous = tmp;
         novi -> next=mPosition;
         mPosition->previous=novi;
         tmp->next=novi;
    }
    }
     mSize++;
     setPosition(i);
}

template <typename T>
void List<T>::remove(std::size_t i){
 // Implementacija
    if(i < 0 || i > mSize || !mSize)
       throw std::runtime_error("error - remove");


    if(!i){
        auto tmp=mStart;
        mStart=mStart->next;
        if(mSize>1)
        mStart->next->previous=nullptr;
        setPosition(i);
        delete [] tmp;

    }
    else if(i==mSize-1){

        setPosition(mSize-2);
        auto tmp=mPosition->next;
        mPosition->next=nullptr;

        delete [] tmp;

    }
    else{
        setPosition(i);

        auto front=mPosition->previous, tmp=mPosition, back=mPosition->next;
        front->next=back;
        back->previous=front;
        mPosition=front;
        delete [] tmp;


    }
    mSize--;

}

template <typename T>
void List<T>::clear(){
 // Implementacija

    while(mSize!=0)
        remove(mSize-1);

}

template <typename T>
void List<T>::push_back(T const & t) {
 // Implementacija
    insert(mSize,t);
}

template <typename T>
void List<T>::sort() {
 // Implementacija

    if(mSize)
    for(unsigned int i=1;i!=mSize;i++){

        for(auto j=i;j>0;j--){
            setPosition(j);
            auto val1=current();
            mPosition=mPosition->previous;
            auto val2=current();
            if(val2>val1){
                remove(j-1);
                insert(j-1,val1);
                remove(j);
                insert(j,val2);
            }
    }
}
}
#endif /* LISTA_H */
