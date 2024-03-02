#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

    typedef struct {
        char codigo[255];
        char nombre[255];
        char numeroDeTelefono[255];
    } clientes;

    typedef struct {
        char codigoCliente[20];
        char codigoServicio[10];
        char fecha[20];
        char hora[20];
    } llamadas;

#endif // ESTRUCTURAS_H_INCLUDED
