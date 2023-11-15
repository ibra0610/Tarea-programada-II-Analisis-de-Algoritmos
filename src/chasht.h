//
//  chtable.h
//

#ifndef chtable_h
#define chtable_h

#include <list>
#include <vector>

template <typename T>

// Tabla de dispersi�n con encadenamiento
class chtable {
public:
    // Constructor que especifica el tama�o de la tabla
    chtable(int sz) {
        size = sz; 
        table.resize(size); 
    };
        
    // Destructor (borra la tabla)
    ~chtable() {    
    };
    
    // Inserta el elemento en la tabla
    void Insert(const T& k) { 
        int index = k % size; 
        table[index].push_back(k); 
    };
    
    // Retorna un puntero a la llave o nullptr si no se encuentra
    T* Search(const T& k) { 
        int index = k % size; 

        for(auto it = table[index].begin(); it != table[index].end(); ++it){
            if(*it == k){
                return &(*it); 
            }
        } 

        return nullptr; 
    };

private:
    // N�mero de entradas en la tabla
    int size;
    
    // La tabla es un vector de listas de STL
    std::vector<std::list<T> > table;
};

#endif /* chtable_h */
