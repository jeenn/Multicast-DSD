#include "SocketMulticast.h"
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <sstream>
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {

    int res = 0;
    char *IP = argv[1];
    string mensaje = "";
    string token = "";
    int puerto = atoi(argv[2]); //El puerto enviado por parámetro, se convierte a int
    printf("%s\n", "RECEPTOR");
    SocketMulticast socket(puerto);

    while (true) {
        PaqueteDatagrama paqueteRecibido(15);
        socket.recibe(paqueteRecibido, IP);
        mensaje = paqueteRecibido.obtieneDatos();
        stringstream ss(mensaje);

        while (getline(ss, token, ',')) {
            cout << "Mensaje en partes: " << token << endl;
            res += atoi(token.c_str());//token se convierte a string de c y a esta string se le hace un
                    //ascii to integer para poder sumar cada uno de los tokens
        }
        cout << "Resultado " << res << endl;

        //Convirtiendo
        ostringstream strl;
        strl << res;
        string r = strl.str();
        cout << r << endl;
        const char *aux = r.c_str();
        char *x = strdup(aux);

        //ENVIANDO
        SocketDatagrama socketEnvio(7600);
        printf("Enviando al emisor: %s el contenido: %s\n", paqueteRecibido.obtieneDireccion(), x);
        PaqueteDatagrama paqueteEnviado(x, sizeof(int), paqueteRecibido.obtieneDireccion(), 7600);
        socketEnvio.envia(paqueteEnviado);
    }

    return 0;
}
