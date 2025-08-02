#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// Direcciones: 0=arriba, 1=derecha, 2=abajo, 3=izquierda
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct Hormiga {
    int x, y, dir;
};

void generarImagen(const vector<vector<int>>& grilla, const Hormiga& h, int paso, int tamCelda = 20) {
    int filas = grilla.size();
    int columnas = grilla[0].size();
    Mat imagen(filas * tamCelda, columnas * tamCelda, CV_8UC3, Scalar(255, 255, 255));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            Rect celda(j * tamCelda, i * tamCelda, tamCelda, tamCelda);
            Scalar color = (grilla[i][j] == 0) ? Scalar(255, 255, 255) : Scalar(0, 0, 0);
            rectangle(imagen, celda, color, FILLED);
        }
    }

    Point centro(h.y * tamCelda + tamCelda / 2, h.x * tamCelda + tamCelda / 2);
    Point direccion = centro + Point(dy[h.dir], dx[h.dir]) * (tamCelda / 2);
    arrowedLine(imagen, centro, direccion, Scalar(0, 0, 255), 2);

    char nombre[50];
    sprintf(nombre, "paso_%04d.png", paso);
    imwrite(nombre, imagen);
}

int main() {
    srand((unsigned)time(0));

    int filas, columnas, pasos;
    cout << "Ingrese el tamaño de la grilla (filas columnas): ";
    cin >> filas >> columnas;

    cout << "Ingrese la cantidad de pasos: ";
    cin >> pasos;

    vector<vector<int>> grilla(filas, vector<int>(columnas, 0));

    Hormiga h = {filas / 2, columnas / 2, 0};

    for (int p = 0; p < pasos; ++p) {
        generarImagen(grilla, h, p);

        int& celda = grilla[h.x][h.y];
        if (celda == 0) {
            h.dir = (h.dir + 1) % 4;
            celda = 1;
        } else {
            h.dir = (h.dir + 3) % 4;
            celda = 0;
        }

        h.x = (h.x + dx[h.dir] + filas) % filas;
        h.y = (h.y + dy[h.dir] + columnas) % columnas;
    }

    cout << "Simulación completa. Las imágenes se han guardado como paso_0000.png, paso_0001.png, etc." << endl;

    // Mostrar imagen final generada
    printf("Imagen final: paso_%04d.png\n", pasos - 1);

    // Abrir carpeta actual en Windows desde WSL
    system("explorer.exe .");

    return 0;
}
