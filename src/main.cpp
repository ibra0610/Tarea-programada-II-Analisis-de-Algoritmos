#include <iostream> 
#include "llist.h" 
#include "bstree.h"
#include "rbtree.h"
#include "chasht.h"
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

void llenarArbolSecuencial(bstree<int>& bStree, int n){
    for(int i = 0; i < n; i++){ 
        bstnode<int>* newNode = new bstnode<int>(i); 
        bStree.Insert(newNode);  
    }
} 

void llenarRBTreeAleatorio(rbtree<int>& RBTree, int n){
    std::random_device rd; 
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 2*n); 
    for(int index = 0; index < n; ++index){
        int num = dist(mt); 
        rbtnode<int>* newNode = new rbtnode<int>(num); 
        RBTree.Insert(newNode); 
    }
}

void llenarRBTreeSecuencial(rbtree<int>& RBTree, int n){
    for(int i = 0; i < n; i++){ 
        rbtnode<int>* newNode = new rbtnode<int>(i); 
        RBTree.Insert(newNode);  
    }
}

void llenarTablaAleatoria(chtable<int>& tabla, int n){
    std::random_device rd; 
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 2*n); 
    for(int index = 0; index < n; ++index){
        int num = dist(mt); 
        tabla.Insert(index); 
    }
}

void llenarTablaSecuencial(chtable<int>& tabla, int n){
    for(int i = 0; i < n; i++){ 
        tabla.Insert(i);  
    }
}

int main(){

//     llist<int> myList;

     srand(static_cast<unsigned>(time(nullptr))); 

       const int n = 1000000; 

//     //Insertar las llaves secuenciales en la lista secuencial 
//     //llenarListaSecuencial(myList, n); 

// //     //Insertar los n nodos aleatorios
    

//     llenarListaAleatoria(myList, n); 



// //     //Medir el tiempo transcurrido en segundos para la lista
//         auto start = std::chrono::steady_clock::now(); 
//         auto end = std::chrono::steady_clock::now(); 
//         int busquedas = 0;  


//     // //Medir busquedas
//     int randomSearchKey = generateRandomKey(); 
//     while(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < 1){
//         randomSearchKey = generateRandomKey(); 
//         llnode<int>* result = myList.Search(randomSearchKey);
//         busquedas++; 
//         end = std::chrono::steady_clock::now(); 
//     }  

//     std::cout << "Se realizaron " << busquedas << " busquedas en la lista en un segundo." << std::endl; 


    //bstree<int> tree; 
    //Insertar nodos aleatorios  
    //llenarArbolAleatorio(tree, n);

    //Insertar nodos secuenciales
    //llenarArbolSecuencial(tree, n); 
    


    //Medir el tiempo transcurrido en segundos
    // auto start = std::chrono::steady_clock::now(); 
    // auto end = std::chrono::steady_clock::now(); 
    // int busquedas = 0;  


    //Busqueda en arbol
    // int randomSearchKey = generateRandomKey(); 
    // while(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < 1){
    //     randomSearchKey = generateRandomKey(); 
    //     bstnode<int>* result = tree.Search(tree.root, randomSearchKey);
    //     busquedas++; 
    //     end = std::chrono::steady_clock::now(); 
    // } 

    // std::cout << "Se realizaron " << busquedas << " busquedas en el arbol binario en un segundo." << std::endl;  


    //rbtree<int> arbolRN; 

    //llenar arbol rojinegro aleatorio 
    //llenarRBTreeAleatorio(arbolRN, n); 

    //llenar arbol rojinegro secuencial 
    // llenarRBTreeSecuencial(arbolRN, n);

    // auto start = std::chrono::steady_clock::now(); 
    // auto end = std::chrono::steady_clock::now(); 
    // int busquedas = 0;  


    // //Busqueda en arbol
    // int randomSearchKey = generateRandomKey(); 
    // while(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < 1){
    //     randomSearchKey = generateRandomKey(); 
    //     rbtnode<int>* result = arbolRN.Search(arbolRN.root, randomSearchKey);
    //     busquedas++; 
    //     end = std::chrono::steady_clock::now(); 
    // }

    // std::cout << "Se realizaron " << busquedas << " busquedas en el arbol rojinegro en un segundo." << std::endl;   

    //TEST DE BUSQUEDA
    // int busq = 5; 
    // rbtnode<int>* testRN = arbolRN.Search(arbolRN.root, busq); 
    // if(testRN != arbolRN.nil){ 
    //     std::cout << "Dato " << busq << " encontrado" << std::endl; 
    // }else{
    //     std::cout << "Dato " << busq << " no encontrado" << std::endl; 
    // }

    chtable<int> myTable(n); 

    //llenar tabla aleatorio 
    llenarTablaAleatoria(myTable, n); 


    //llenar tabla secuencial 
    //llenarTablaSecuencial(myTable, n); 

    auto start = std::chrono::steady_clock::now(); 
    auto end = std::chrono::steady_clock::now(); 
    int busquedas = 0;  

    //Busqueda en tabla
    int randomSearchKey = generateRandomKey(); 
    while(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < 1){
        randomSearchKey = generateRandomKey(); 
        int* resultadoTabla = myTable.Search(randomSearchKey); 
        busquedas++; 
        end = std::chrono::steady_clock::now(); 
    }

    std::cout << "Se realizaron " << busquedas << " busquedas en la tabla hash." << std::endl;    


    //TEST de busqueda en tabla 
    // int testTablaBus = 5; 
    // int* reultadoTEST = myTable.Search(testTablaBus); 

    // if(reultadoTEST != nullptr){
    //     std::cout << "Elemento " << testTablaBus << " encontrado en la tabla." << std::endl; 
    // }else{
    //     std::cout << "Elemento " << testTablaBus << " no encontrado en la tabla." << std::endl; 
    // }

    return 0; 
}
