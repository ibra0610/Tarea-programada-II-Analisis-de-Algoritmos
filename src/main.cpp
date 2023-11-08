#include <iostream> 
#include "llist.h" 
#include "bstree.h"
#include <cstdlib> 
#include <ctime>  
#include <chrono>

int generateRandomKey(){ 
    return rand() % 2000001; 
}


int main(){

//     llist<int> myList;//Lista para las llaves aleatorias 

//     //srand(static_cast<unsigned>(time(nullptr))); 

      const int n = 1000000; 

//     //Insertar las llaves secuenciales en la lista secuencial 
//     for(int i = 0; i < n; i++){ 
//         llnode<int>* newNode = new llnode<int>(i); 
//         myList.Insert(newNode); 
//     }

//     //Insertar los n nodos aleatorios
    
// //    for(int i = 0; i < n; i++){ 
// //        int randomKey = generateRandomKey(); 
// //        llnode<int>* newNode = new llnode<int>(randomKey); 
// //        myList.Insert(newNode); 
// //     }  


//     //Medir el tiempo transcurrido en segundos para aleatoria
//     // auto start = std::chrono::steady_clock::now(); 
//     // auto end = std::chrono::steady_clock::now(); 
//     int busquedas = 0;  
//     auto startTime = std::chrono::high_resolution_clock::now();
//     auto endTime = startTime + std::chrono::seconds(1); 

//     while (std::chrono::high_resolution_clock::now() < endTime) {
//         int randomSearchKey = generateRandomKey(); 
//         llnode<int>* result = myList.Search(randomSearchKey);
//         busquedas++;
//     }

//     auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime); 

//     //Busqueda en lista aleatoria
//     // int randomSearchKey = generateRandomKey(); 
//     // while(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < 1){
//     //     randomSearchKey = generateRandomKey(); 
//     //     llnode<int>* result = myList.Search(randomSearchKey);
//     //     busquedas++; 
//     //     end = std::chrono::steady_clock::now(); 
//     // }  



//     std::cout << "Se realizaron " << busquedas / duration.count() << " busquedas en la lista en un segundo." << std::endl; 



    bstree<int> tree; 
    //Insertar nodos aleatorios
     for(int i = 0; i < n; i++){ 
       int randomKey = generateRandomKey(); 
       bstnode<int>* newNode = new bstnode<int>(randomKey); 
       tree.Insert(newNode); 
    }    

    //Insertar nodos secuenciales PREGUNTAR SI TIENE QUE ESTAR DESBALANCEADO A PROPOSITO
    //tree.insertarSecuenciales(n); 

        //Medir el tiempo transcurrido en segundos para aleatoria
    auto start = std::chrono::steady_clock::now(); 
    auto end = std::chrono::steady_clock::now(); 
    int busquedas = 0;  


    //Busqueda en lista aleatoria
    int randomSearchKey = generateRandomKey(); 
    while(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < 1){
        randomSearchKey = generateRandomKey(); 
        bstnode<int>* result = tree.Search(tree.root, randomSearchKey);
        busquedas++; 
        end = std::chrono::steady_clock::now(); 
    } 

    std::cout << "Se realizaron " << busquedas << " busquedas en el arbol binario en un segundo." << std::endl; 

    return 0; 
}
