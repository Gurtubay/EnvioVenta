#ifndef VENTA_C
#define VENTA_C

//include carrito
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Venta{
    private:
    string ventaID;
    vector productos[];
    int cantidadProductos;
    string sitioWeb;
    float precioVenta;
    //Carrito carrito{};

    public:
    Venta(){

    }
    //generar ID
    void generarID()
    {
        int num;
        srand(time(NULL));
        num = rand() % 100001;
        ventaID = "SH" + to_string(num);
    }

    void setNumProductos(){
        //cantidadProductos = carrito.getNumeroProductos();
    }

    void setPrecioVenta(){
        //PrecioVenta = carrito.getTotal
    }

    //Primera estadistica
    float promedioProductoVenta(){
        return precioVenta/cantidadProductos;
    }
    //Estadistica precios
    //Estaditica por sitioweb
    //Estadistica general

};//Clase Venta

#endif