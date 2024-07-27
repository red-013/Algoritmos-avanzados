//Jared Chávez Pozo - 20213283

#include <iostream>
#define MAX 10  // Define el tamaño máximo para el arreglo de resultados

using namespace std;

// Variables globales
int contador = 0, solucionEncontrada = 0;
int resultado[MAX];

// Función recursiva para encontrar un subconjunto de paquetes que sumen el peso objetivo
int encontrarEmpaque(int indiceInicio, int totalPaquetes, int pesoObjetivo, int paquetes[]) {
    // Si el peso objetivo es negativo o hemos recorrido todos los paquetes, no hay solución
    if (pesoObjetivo < 0 || indiceInicio == totalPaquetes) return 0;

    // Almacena el paquete actual en el resultado temporal
    resultado[contador++] = paquetes[indiceInicio];

    // Si el paquete actual cumple con el peso objetivo, imprime el resultado
    if (paquetes[indiceInicio] == pesoObjetivo) {
        for (int i = 0; i < contador; i++)
            cout << resultado[i] << " ";
        cout << endl;
        solucionEncontrada = 1;
    }

    // Intentar incluir el paquete actual en la solución y llamar recursivamente
    if (encontrarEmpaque(indiceInicio + 1, totalPaquetes, pesoObjetivo - paquetes[indiceInicio], paquetes))
        return 1;
    else {
        // Si incluir el paquete actual no lleva a una solución, removerlo y probar con el siguiente paquete
        contador--;
        return (encontrarEmpaque(indiceInicio + 1, totalPaquetes, pesoObjetivo, paquetes));
    }
}

int main(int argc, char** argv) {
    int totalPaquetes = 5;
    int paquetes[] = {7, 8, 2, 3, 1};  // Arreglo de pesos de los paquetes
    int pesoObjetivo = 12;  // Peso objetivo a encontrar

    // Llamada inicial a la función recursiva
    encontrarEmpaque(0, totalPaquetes, pesoObjetivo, paquetes);

    // Verificar si se encontró alguna solución
    if (solucionEncontrada)
        cout << "Hay soluciones posibles";
    else
        cout << "No hay solución";

    return 0;
}

