#include <iostream> 
#include "llist.h" 
#include "bstree.h"
#include <cstdlib> 
#include <ctime>  
#include <chrono>
#include <cstdint>
#include <random>

int generateRandomKey(){ 
    return rand() % 2000000; 
}

void llenarListaAleatoria(llist<int>& lList, int n){
    std::random_device rd; 
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 2*n); 
    for(int index = 0; index < n; ++index){
        int num = dist(mt); 
        llnode<int>* newNode = new llnode<int>(num); 
        lList.Insert(newNode); 
    }
} 

void llenarListaSecuencial(llist<int>& lList, int n){
    for(int i = 0; i < n; i++){ 
        llnode<int>* newNode = new llnode<int>(i); 
        lList.Insert(newNode); 
    }
}

int main(){

    llist<int> myList;

    srand(static_cast<unsigned>(time(nullptr))); 

      const int n = 1000000; 

//     //Insertar las llaves secuenciales en la lista secuencial 
    //llenarListaSecuencial(myList, n); 

//     //Insertar los n nodos aleatorios
    

    //llenarListaAleatoria(myList, n); 



//     //Medir el tiempo transcurrido en segundos para aleatoria
    //     auto start = std::chrono::steady_clock::now(); 
    //     auto end = std::chrono::steady_clock::now(); 
    //     int busquedas = 0;  


    // //Medir busquedas
    // int randomSearchKey = generateRandomKey(); 
    // while(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < 1){
    //     randomSearchKey = generateRandomKey(); 
    //     llnode<int>* result = myList.Search(randomSearchKey);
    //     busquedas++; 
    //     end = std::chrono::steady_clock::now(); 
    // }  

    // std::cout << "Se realizaron " << busquedas << " busquedas en la lista en un segundo." << std::endl; 

    llnode<int>* nodo1 = new llnode<int>(1); 
    llnode<int>* nodo2 = new llnode<int>(2); 
    llnode<int>* nodo3 = new llnode<int>(3); 
    llnode<int>* nodo4 = new llnode<int>(4); 

    int buscar = 3; 
    llnode<int>* result = myList.Search(buscar);
    if (result != myList.nil) {
        std::cout << "Elemento " << buscar << " encontrado en la lista." << std::endl;
    } else {
        std::cout << "Elemento " << buscar << " no encontrado en la lista." << std::endl;
    }
    // bstree<int> tree; 
    // //Insertar nodos aleatorios
    //  for(int i = 0; i < n; i++){ 
    //    int randomKey = generateRandomKey(); 
    //    bstnode<int>* newNode = new bstnode<int>(randomKey); 
    //    tree.Insert(newNode); 
    // }    

    // //Insertar nodos secuenciales PREGUNTAR SI TIENE QUE ESTAR DESBALANCEADO A PROPOSITO
    // //tree.insertarSecuenciales(n); 

    //     //Medir el tiempo transcurrido en segundos para aleatoria
    // auto start = std::chrono::steady_clock::now(); 
    // auto end = std::chrono::steady_clock::now(); 
    // int busquedas = 0;  


    // //Busqueda en lista aleatoria
    // int randomSearchKey = generateRandomKey(); 
    // while(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < 1){
    //     randomSearchKey = generateRandomKey(); 
    //     bstnode<int>* result = tree.Search(tree.root, randomSearchKey);
    //     busquedas++; 
    //     end = std::chrono::steady_clock::now(); 
    // } 

    // std::cout << "Se realizaron " << busquedas << " busquedas en el arbol binario en un segundo." << std::endl; 

    return 0; 
}
