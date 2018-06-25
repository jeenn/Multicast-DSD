#include "SocketMulticast.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {

    char *IP = argv[1];
    int puerto = atoi(argv[2]);
    int res;
    string dato = "1,1,1,1"; //Este es el dato que se envía al emisor
    const char *aux = dato.c_str(); //Dato se convierte a string de c
    char *mensaje = strdup(aux); //Se asigna memoria dinámica

    printf("%s\n", "EMISOR");
    SocketMulticast socket(puerto);
    PaqueteDatagrama datos(mensaje, dato.length(), IP, puerto);
    socket.envia(datos, 255);

    //Recibiendo
    SocketDatagrama socketRecibir(7600);

    while (true) {
        printf("%s\n", "Esperando...");
        PaqueteDatagrama paqueteRecibido(sizeof(int));
        socketRecibir.recibe(paqueteRecibido);
        res = atoi(paqueteRecibido.obtieneDatos());
        printf("Recibidos = %d\n", res);
    }

    return 0;
}