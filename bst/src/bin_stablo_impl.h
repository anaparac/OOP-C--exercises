#ifndef BIN_STABLO_IMPL_H_INCLUDED
#define BIN_STABLO_IMPL_H_INCLUDED

///// Implementacija metoda iz Node klase //////////////////////
template<typename T>
Node<T>::Node(){
    left = nullptr;
    right = nullptr;
    T date{};
}


template <typename T>
BinarySTree<T>::BinarySTree(){
    root=nullptr;
}


template <typename T>
bool BinarySTree<T>::empty() const{
    return (root == nullptr);
}

//// Implementacija metoda iz BinaryTree klase //////////////////


//prvo navodimo predlozak klase, pa predlozak fje
template <typename T>
template <typename Funct>
void BinarySTree<T>::preOrder(Node<T> * root, Funct visit)
{
     //throw "Not implemented.";
    if(root!=nullptr){
        visit(root->data);
        preOrder(root->left, visit);
        preOrder(root->right, visit);
    }
}

template <typename T>
template <typename Funct>
void BinarySTree<T>::inOrder(Node<T> * root, Funct visit)
{

    //throw "Not implemented.";
    if(root!=nullptr){
    inOrder(root->left, visit);
    visit(root->data);
    inOrder(root->right, visit);
   }
}

template <typename T>
template <typename Funct>
void BinarySTree<T>::postOrder(Node<T> * root, Funct visit)
{
     //throw "Not implemented.";
    if(root!=nullptr){
    postOrder(root->left, visit);
    postOrder(root->right, visit);
    visit(root->data);
    }
}
template <typename T>
ErrorCode BinarySTree<T>::find(Node<T>* &root, T const &t){
    if(root != nullptr){
        if(root->data == t)
            return success;
        find(root->left, t);
        find(root->right, t);
    }
    return notfound;
}

template <typename T>
 ErrorCode insert(Node<T> * & root, T const & t){
    if( empty() ){
        Node<T> *novi = new Node<T>;
        novi->data=t;
        root=novi;
        return success;
    }
    else if(t < root->data){
        if(root->left == nullptr){
            Node<T> *novi = new Node<T>;
            novi->data = t;
            root->left = novi;
            return success;
        }

        insert(root->left, t);
    }
    else if( t > root->data ){
        if(root->right == nullptr){
            Node<T> *novi = new Node<T>;
            novi->data = t;
            root->right = novi;
            return success;
        }
        insert(root->right, t);
    }
    else return duplicate;
 }

template <typename T>
 ErrorCode remove(Node<T> * & root){

 }

#endif // BIN_STABLO_IMPL_H_INCLUDED
