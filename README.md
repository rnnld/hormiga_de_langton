# hormiga_de_langton
Pasos:
1.-
Abrir terminal Ubuntu para entrar en el directorio del archivo hormiga_langton usando:

cd ~/hormiga_langton

2.-
Compilar dentro de la carpeta ~/hormiga_langton usando:

g++ -std=c++17 hormiga.cpp -o hormiga `pkg-config --cflags --libs opencv4`

3.-
Ejecutar el programa usando:
./hormiga

"El programa pide al usuario indicar el ancho y largo del mapa(matriz). Indique su ancho y largo a gusto del usuario.

Posteriormente pedirá la cantidad de pasos que desea que la Hormiga ejecute(La hormiga comenzará desde el centro "ancho/2, largo/2").

Tras estos simples pasos, enviará al usuario a una carpeta con las imágenes(pasos) que haya hecho la hormiga, aplicando las reglas impuestas por el modelo matemático de Langton."