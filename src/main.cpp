#include <iostream> 
#include "llist.h" 
#include <cstdlib> 
#include <ctime>  
#include <chrono>

int generateRandomKey(){ 
    return rand() % 2000001; 
}


int main(){

    llist<int> myList;//Lista para las llaves aleatorias 
    llist<int> listaSecuencial; //Lista para las llaves secuenciales

    srand(static_cast<unsigned>(time(nullptr))); 

    const int n = 1000000; 

    //Insertar las llaves secuenciales en la lista secuencial 
    for(int i = 0; i < n; i++){ 
        llnode<int>* newNode = new llnode<int>(i); 
        listaSecuencial.Insert(newNode); 
    }


    //Insertar los n nodos aleatorios
    
    for(int i = 0; i < n; i++){ 
        int randomKey = generateRandomKey(); 
        llnode<int>* newNode = new llnode<int>(randomKey); 
        myList.Insert(newNode); 
    } 

    //Medir el tiempo transcurrido en segundos para aleatoria
    auto start = std::chrono::steady_clock::now(); 
    auto end = std::chrono::steady_clock::now(); 
    int busquedasAleatorias = 0;  


    //Busqueda en lista aleatoria
    while(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < 1){
        int randomSearchKey = generateRandomKey(); 
        llnode<int>* result = listaSecuencial.Search(randomSearchKey); //CAMBIAR AQUI EL TIPO DE LISTA PARA APUNTAR LOS RESULTADOS
        busquedasAleatorias++; 
        end = std::chrono::steady_clock::now(); 
    } 

    std::cout << "Se realizaron " << busquedasAleatorias << " busquedas en un segundo." << std::endl; 

    return 0; 
}
