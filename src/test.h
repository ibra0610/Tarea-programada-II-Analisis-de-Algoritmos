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
    // Esta clase es para ser usada por otras clases. 
    // Por eficiencia los atributos se dejan publicos.
    T key;
    llnode<T> *prev, *next;
    
    // Constructor por omision.
    llnode() {
        prev = nullptr;
		next = nullptr;
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
        nil = new llnode<T>();
    };
    
    ~llist() {
        // Destructor (borra la lista)
        llnode<T> *b = nil->next; 
        llnode<T> *a = nullptr;     
		while(b!=nil){
            a=b;
            b=b->next;
            delete a;
		}
	    delete nil;
    };
    
    void Insert(llnode<T>* x) {
        // Inserta el nodo x en la lista.
        if(nil->next == nullptr){ //si lista vacia
			x->next = nil;
			x->prev = nil;
			nil->next = x;
			nil->prev = nil;
		}else{
			x->next = nil->next;
			nil->next->prev = x;
			nil->next = x;
			x->prev = nil;
		}
    };

    llnode<T>* Search(const T& k) {
        // Busca la llave iterativamente. Si la encuentra, devuelve un 
        // apuntador al nodo que la contiene; sino devuelve el nodo nil (el centinela).
         llnode<T> *p;
		p = nil->next;
		while((p!=nil)&&(p->key!=k)){
			p = p->next;
		}		
		return p;
    };
        
    void Delete(llnode<T>* x) {
        x->prev->next = x->next;
		x->next->prev = x->prev;
        // Saca de la lista la llave contenida en el nodo apuntado por x.
    };    
};

#endif /* llist_h */
