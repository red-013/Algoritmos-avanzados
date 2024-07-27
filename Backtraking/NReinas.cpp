//Jared Chávez Pozo - 20213283

#include <iostream>
#define N 5  // Define el tamaño del tablero como 4

using namespace std;

// Función que verifica si es válido colocar una reina en la posición (fila, columna)
int esPosicionValida(int tablero[][N], int fila, int columna) {
    // Verificar la fila hacia la izquierda
    for (int i = 0; i < columna; i++)
        if (tablero[fila][i]) return 0;

    // Verificar la diagonal superior izquierda
    int i, j;
    for (i = fila, j = columna; i >= 0 && j >= 0; i--, j--)
        if (tablero[i][j]) return 0;

    // Verificar la diagonal inferior izquierda
    for (i = fila, j = columna; i >= 0 && j < N; i--, j++)
        if (tablero[i][j]) return 0;

    // Si no hay conflictos, la posición es válida
    return 1;
}

// Función para imprimir el tablero
void imprimirTablero(int tablero[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (tablero[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Función que resuelve el problema de las N reinas utilizando backtracking
int resolverNReinas(int tablero[][N], int columna) {
    // Si todas las reinas han sido colocadas, retornar verdadero
    if (columna == N)
        return 1;

    // Intentar colocar una reina en cada fila de la columna actual
    for (int fila = 0; fila < N; fila++) {
        // Verificar si la posición actual es válida
        if (esPosicionValida(tablero, fila, columna)) {
            // Colocar la reina en la posición actual
            tablero[fila][columna] = 1;
            // Llamar recursivamente para colocar el resto de las reinas
            if (resolverNReinas(tablero, columna + 1))
                return 1;
            // Si no lleva a una solución, remover la reina
            tablero[fila][columna] = 0;
        }
    }
    // Si no se puede colocar una reina en ninguna fila de esta columna, retornar falso
    return 0;
}

int main() {
    // Inicializar el tablero con ceros
    int tablero[N][N] = { {0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0},
			  {0, 0, 0, 0, 0} };

    // Intentar resolver el problema de las N reinas
    if (resolverNReinas(tablero, 0)) {
        // Si se encuentra una solución, imprimir el tablero
        cout << "Solución encontrada:" << endl;
        imprimirTablero(tablero);
    } else {
        // Si no se encuentra una solución, imprimir "No se encontró solución"
        cout << "No se encontró solución" << endl;
    }

    return 0;
}



