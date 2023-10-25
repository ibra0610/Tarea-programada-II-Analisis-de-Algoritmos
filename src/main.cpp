#include <iostream> 
#include "llist.h" 
#include <cstdlib> 
#include <ctime>  
#include <chrono>

int generateRandomKey(){ 
    return rand() % 2000001; 
}


int main(){

    llist<int> myList;  

    srand(static_cast<unsigned>(time(nullptr))); 

    //Insertar los n nodos
    const int n = 1000000; 
    for(int i = 0; i < n; i++){ 
        int randomKey = generateRandomKey(); 
        llnode<int>* newNode = new llnode<int>(randomKey); 
        myList.Insert(newNode); 
    } 

    //Medir el tiempo transcurrido en segundos 
    auto start = std::chrono::steady_clock::now(); 
    auto end = std::chrono::steady_clock::now(); 
    int busquedas = 0; 

    while(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < 1){
        int randomSearchKey = generateRandomKey(); 
        llnode<int>* result = myList.Search(randomSearchKey); 
        busquedas++; 
        end = std::chrono::steady_clock::now(); 
    } 

    std::cout << "Se realizaron " << busquedas << " busquedas con valores aleatorios en un segundo." << std::endl; 

    return 0; 
}
