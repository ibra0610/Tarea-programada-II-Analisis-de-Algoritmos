//
//  llist.h
//

#ifndef llist_h
#define llist_h

// Nodos de la lista:
template <typename T>
class llnode
{
public:
    // Esta clase es para ser usada por otras clases. Por eficiencia los atributos se dejan publicos.
    T key;
    llnode<T> *prev, *next;
    
    // Constructor por omision.
    llnode() {
    };
    
    // Inicializacion de los datos miembro.
    llnode (const T& k, llnode<T> *w = nullptr, llnode<T> *y = nullptr):key(k), prev(w), next(y)  {};
    
    ~llnode() {
    };
};

// Lista enlazada con nodo centinela:
template <typename T>
class llist
{
public:
    llnode<T> *nil;        // nodo centinela

    llist() {
        // Constructor (crea una lista vacia)  
        nil = new llnode<T>; 
        nil->prev = nil; 
        nil->next = nil; 
    };
    
    ~llist() {
        // Destructor (borra la lista)
        while (nil->next != nil){
            Delete(nil->next); 
        }
        
        delete nil; 
    };
    
    void Insert(llnode<T>* x) {
        // Inserta el nodo x en la lista. 
        x->next = nil->next; 
        x->prev = nil; 
        nil->next->prev = x; 
        nil->next = x; 
    };


    llnode<T>* Search(const T& k) {
        // Busca la llave iterativamente. Si la encuentra, devuelve un apuntador al nodo que la contiene; sino devuelve el nodo nil (el centinela).
        nil->key = k;
        llnode<T>* x = nil->next; 
        while (x->key != k){
            x = x->next; 
        } 
        if(x == nil){
            return nil;
        }else{
            return x; 
        }
    };
        
    void Delete(llnode<T>* x) {
        // Saca de la lista la llave contenida en el nodo apuntado por x.
        if(x != nil){ 
            x->prev->next = x->next; 
            x->next->prev = x->prev; 
            delete x; 
        }
    };    
};

#endif /* llist_h */
