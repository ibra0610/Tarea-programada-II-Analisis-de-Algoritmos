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

void llenarArbolAleatorio(bstree<int>& bStree, int n){ 
    std::random_device rd; 
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 2*n); 
    for(int index = 0; index < n; ++index){
        int num = dist(mt); 
        bstnode<int>* newNode = new bstnode<int>(num); 
        bStree.Insert(newNode); 
    }
}

int main(){

    // llist<int> myList;

    // srand(static_cast<unsigned>(time(nullptr))); 

      const int n = 1000000; 

//     //Insertar las llaves secuenciales en la lista secuencial 
    //llenarListaSecuencial(myList, n); 

//     //Insertar los n nodos aleatorios
    

    //llenarListaAleatoria(myList, n); 



//     //Medir el tiempo transcurrido en segundos para la lista
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


    bstree<int> tree; 
    // //Insertar nodos aleatorios  
    //llenarArbolAleatorio(tree, n);

    // //Insertar nodos secuenciales
    tree.InsertarEnOrden(tree.root, 0); 
    //Medir el tiempo transcurrido en segundos
    auto start = std::chrono::steady_clock::now(); 
    auto end = std::chrono::steady_clock::now(); 
    int busquedas = 0;  


    //Busqueda en arbol
    int randomSearchKey = generateRandomKey(); 
    while(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < 1){
        randomSearchKey = generateRandomKey(); 
        bstnode<int>* result = tree.Search(tree.root, randomSearchKey);
        busquedas++; 
        end = std::chrono::steady_clock::now(); 
    } 

    std::cout << "Se realizaron " << busquedas << " busquedas en el arbol binario en un segundo." << std::endl;  


    // int buscarArbol = 5; 
    // bstnode<int>* busquedaArbol = tree.Search(tree.root, buscarArbol); 
    // if(busquedaArbol==nullptr){
    //     std::cout << "No se encontro " << buscarArbol << " en el arbol." << std::endl;  
    // }else{
    //     std::cout << "Se encontro " << buscarArbol << " en el arbol." << std::endl;  
    // }

    return 0; 
}
