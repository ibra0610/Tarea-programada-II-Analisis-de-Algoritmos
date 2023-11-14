//
//  rbtree.h
//

#ifndef rbtree_h
#define rbtree_h

#include <iostream>

enum colors {RED, BLACK};

// Nodos del arbol:
template <typename T>
class rbtnode
{
public:
    // Esta clase es usada por la clase rbtree. Por eficiencia se hacen los atributos publicos.
    T key;
    rbtnode<T> *p, *left, *right;
    enum colors color;
    
    // Constructor por omision.
    rbtnode() {
    };
    
    //Inicializacion de datos miembro.
    rbtnode (const T& k, rbtnode<T> *w = nullptr, rbtnode<T> *y = nullptr, rbtnode<T> *z = nullptr, enum colors c = RED): key(k), p(w), left(y), right(z), color(c) {};
    
    ~rbtnode() {
    };
};

// Arbol rojinegro:
template <typename T>
class rbtree {
public:
    rbtnode<T> *root;    // raiz del arbol
    rbtnode<T> *nil;     // nodo nil (hoja) del arbol
    
    rbtree() {
        // Constructor (crea un arbol vacio) 
        nil = new rbtnode<T>(); 
        nil->color = BLACK; 
        root = nil; 
    };
    
    ~rbtree() {
        // Destructor (borra el arbol)
        borrarArbol(root); 
        delete nil;  
    };
    
    void Insert(rbtnode<T>* z) {
        // Inserta el nodo z en la posicion que le corresponde en el arbol. 
        rbtnode<T>* x = root;
        rbtnode<T>* y = nil; 

        while(x != nil){
            y = x; 
            if(z->key < x->key){
                x = x->left;
            }else{
                x = x->right; 
            }
        } 

        z->p = y; 
        if(y == nil){
            root = z; 
        }else if(z->key < y->key){
            y->left = z; 
        }else{
            y->right = z; 
        } 

        z->left = nil; 
        z->right = nil; 
        z->color = RED; 

        insertFixup(z); 
    };
    
    void InorderWalk(rbtnode<T> *x) {
        // Recorre en orden el subarbol con raiz x, imprimiendo la llave de cada nodo en en una nueva linea de la salida estandar despues de recorrido el subarbol izquierdo y antes de recorrer el subarbol derecho.
        if(x != nil){
            InorderWalk(x->left); 
            std::cout << x->key << " ";  
            InorderWalk(x->right); 
        }
    };
    
    rbtnode<T>* Search(rbtnode<T> *x, const T& k) {
        // Busca la llave k recursivamente en el subarbol con raiz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve el nodo nil. 
        if(x == nil || k == x->key){
            return x;
        } 
        if(k < x->key){
            return Search(x->left, k); 
        }else{
            return Search(x->right, k); 
        }
    };
    
    rbtnode<T>* IterativeSearch(rbtnode<T> *x, const T& k) {
        // Busca la llave k iterativamente en el subarbol con raiz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve el nodo nil.
        while(x != nil && k != x->key){
            if(k < x->key){
                x = x->left;
            }else{
                x = x->right;
            }
        } 

        return x; 
    };
    
    rbtnode<T>* Minimum(rbtnode<T> *x) {
        // Devuelve el nodo que tiene la llave menor. Si el arbol esta vacio, devuelve el nodo nil. 
        while(x->left != nil){
            x = x->left; 
        } 
        return x; 
    };
    
    rbtnode<T>* Maximum(rbtnode<T> *x) {
        // Devuelve el nodo que tiene la llave mayor. Si el arbol esta vacio devuelve el nodo nil. 
        while(x->right != nil){
            x = x->right; 
        }
        return x; 
    };
    
    rbtnode<T>* Successor(rbtnode<T> *x) {
        // Devuelve el nodo cuya llave es la que le sigue a la del nodo x. Si no existe el nodo, devuelve el nodo nil. 
        if(x->right != nil){
            return Minimum(x->right); 
        } 

        rbtnode<T>* y = x->p; 
        while(y != nil && x == y->right){
            x = y; 
            y = y->p;
        } 
        return y; 
    }; 

private: 
    void borrarArbol(rbtnode<T>* x){
        if(x != nil){
            borrarArbol(x->left); 
            borrarArbol(x->right); 
            delete x; 
        }
    } 

    void rightRotate(rbtnode<T>* y){
        rbtnode<T>* x = y->left; 
        y->left = x->right; 

        if(x->right != nil){
            x->right->p = y; 
        } 
        x->p = y->p; 

        if(y->p == nil){
            root = x; 
        }else if(y == y->p->left){
            y->p->left = x; 
        }else{
            y->p->right = x; 
        } 

        x->right = y; 
        y->p = x; 
    } 

    void leftRotate(rbtnode<T>* x){
        rbtnode<T>* y = x->right; 
        x->right = y->left; 
        if(y->left != nil){
            y->left->p = x;
        } 

        y->p = x->p; 
        if(x->p == nil){
            root = y; 
        }else if(x == x->p->left){
            x->p->left = y; 
        }else{
            x->p->right = y; 
        } 

        y->left = x; 
        x->p = y; 
    } 

    void insertFixup(rbtnode<T>* z){
        while(z->p->color == RED){
            if(z->p == z->p->p->left){
                rbtnode<T>* y = z->p->p->right; 
                if(y->color == RED){
                    z->p->color = BLACK; 
                    y->color = BLACK; 
                    z->p->p->color = RED; 
                    z = z->p->p; 
                }else{
                    if(z == z->p->right){
                        z = z->p; 
                        leftRotate(z);
                    }
                    z->p->color = BLACK; 
                    z->p->p->color = RED; 
                    rightRotate(z->p->p); 
                }
            }else {
                rbtnode<T>* y = z->p->p->left; 
                if(y->color == RED){
                    z->p->color = BLACK; 
                    y->color = BLACK; 
                    z->p->p->color = RED; 
                    z = z->p->p;
                }else{
                    if(z == z->p->left){
                        z = z->p; 
                        rightRotate(z); 
                    } 
                    z->p->color = BLACK; 
                    z->p->p->color = RED; 
                    leftRotate(z->p->p); 
                }
            }
        }

        root->color = BLACK; 
    }
};

#endif /* rbtree_h */
