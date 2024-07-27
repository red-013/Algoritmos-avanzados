//Jared Ch�vez Pozo - 20213283

#include <iostream>
#define N 5  // Define el tama�o del tablero como 4

using namespace std;

// Funci�n que verifica si es v�lido colocar una reina en la posici�n (fila, columna)
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

    // Si no hay conflictos, la posici�n es v�lida
    return 1;
}

// Funci�n para imprimir el tablero
void imprimirTablero(int tablero[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (tablero[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Funci�n que resuelve el problema de las N reinas utilizando backtracking
int resolverNReinas(int tablero[][N], int columna) {
    // Si todas las reinas han sido colocadas, retornar verdadero
    if (columna == N)
        return 1;

    // Intentar colocar una reina en cada fila de la columna actual
    for (int fila = 0; fila < N; fila++) {
        // Verificar si la posici�n actual es v�lida
        if (esPosicionValida(tablero, fila, columna)) {
            // Colocar la reina en la posici�n actual
            tablero[fila][columna] = 1;
            // Llamar recursivamente para colocar el resto de las reinas
            if (resolverNReinas(tablero, columna + 1))
                return 1;
            // Si no lleva a una soluci�n, remover la reina
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
        // Si se encuentra una soluci�n, imprimir el tablero
        cout << "Soluci�n encontrada:" << endl;
        imprimirTablero(tablero);
    } else {
        // Si no se encuentra una soluci�n, imprimir "No se encontr� soluci�n"
        cout << "No se encontr� soluci�n" << endl;
    }

    return 0;
}



