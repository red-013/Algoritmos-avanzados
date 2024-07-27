//Jared Ch�vez Pozo - 20213283

#include <iostream>
#include <cstring>

#define UNASSIGNED 0
#define N 9

using namespace std;

/* Función de utilidad para imprimir el tablero de sudoku */
void imprimirTablero(int tablero[N][N]) {
    for (int row = 0; row < N; row++) {
        if (row % 3 == 0 && row != 0) {
            cout << "---------------------" << endl; // Línea horizontal
        }
        for (int col = 0; col < N; col++) {
            if (col % 3 == 0 && col != 0) {
                cout << "| "; // Línea vertical
            }
            cout << tablero[row][col] << " ";
        }
        cout << endl;
    }
}

/* Devuelve un booleano que indica si es valido colocar el número num en la fila y columna pasada */
bool esValido(int tablero[N][N], int row, int col, int num) {
    // Verifica la fila y columna
    for (int d = 0; d < N; d++)
        if (tablero[row][d] == num || tablero[d][col] == num)
            return false;

    // Verifica el cuadrado
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tablero[i + startRow][j + startCol] == num)
                return false;

    return true;
}

/* Busca en el tablero una posición no asignada. La posicion encontrada la registra en row, col  */
bool buscarPosicionVacia(int tablero[N][N], int &row, int &col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (tablero[row][col] == UNASSIGNED)
                return true;
    return false;
}

/* Función para resolver el Sudoku utilizando backtracking */
bool resolverSudoku(int tablero[N][N]) {
    int row, col;

    // Si no hay ubicaciones vacias, hemos terminado
    if (!buscarPosicionVacia(tablero, row, col))
        return true; // Retorna True, indicando que no hay posiciones vacias (Se resolvio el sudoku!)

    // Considera dígitos del 1 al 9
    for (int num = 1; num <= 9; num++) {
        // Si parece prometedor
        if (esValido(tablero, row, col, num)) {
            // Realiza la asignación tentativa
            tablero[row][col] = num;

            // Recursión para asignar el resto de posiciones
            if (resolverSudoku(tablero))
                return true;

            // Falló, entonces desasigna el numero (BACKTRACK)
            tablero[row][col] = UNASSIGNED;
        }
    }
    return false; // Esto desencadena el backtracking
}

int main() {
    int tablero[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                         {5, 2, 0, 0, 0, 0, 0, 0, 0},
                         {0, 8, 7, 0, 0, 0, 0, 3, 1},
                         {0, 0, 3, 0, 1, 0, 0, 8, 0},
                         {9, 0, 0, 8, 6, 3, 0, 0, 5},
                         {0, 5, 0, 0, 9, 0, 6, 0, 0},
                         {1, 3, 0, 0, 0, 0, 2, 5, 0},
                         {0, 0, 0, 0, 0, 0, 0, 7, 4},
                         {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (resolverSudoku(tablero) == true)
        imprimirTablero(tablero);
    else
        cout << "No solution exists" << endl;
    return 0;
}
