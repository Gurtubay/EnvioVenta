// CLASE ENVIO

// Programada por José Miguel García Gurtubay Moreno
// 28 de noviembre 2020


#ifndef ENVIO_C
#define ENVIO_C

#include "envio.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <string>

using namespace std;

class Envio{
    private:
        
        string tipoEnvio;
        float costoCaja;
        float dimensionesProducto[3] = {0.0,0.0,0.0};
        float costoEnvio;
        string trackID;

    public:
        //Member initializing list
        Envio(){
            tipoEnvio = "normal";
            costoCaja = 0.0;
            dimensionesProducto[3];
            costoEnvio = 0.0;
            trackID = "falta definir";
        }

        //tipos de cajas (20x20x30) (30x40x60) (50x40x120)
        void calcularCostoCaja(){
            if ((dimensionesProducto[0] <= 20) && (dimensionesProducto[1] <= 20) && (dimensionesProducto[2] <= 30))
            {
                // La caja es de tipo (20x20x30) cuesta $9.99
                costoCaja = 9.99;
            }
            else if ((dimensionesProducto[0] && dimensionesProducto[0] <= 30 ) && (dimensionesProducto[1] > 20 && dimensionesProducto[1] <= 40) && (dimensionesProducto[2] > 30 && dimensionesProducto[2] <= 60))
            {
                // La caja es de tipo (30x30x60) cuesta $19.99
                costoCaja = 19.99;
            }
            else if ((dimensionesProducto[0] > 30 && dimensionesProducto[0] <= 50 ) && (dimensionesProducto[1] > 40 && dimensionesProducto[1] <= 40) && (dimensionesProducto[2] > 60 && dimensionesProducto[2] <= 120))
            {
                // La caja es de tipo (50x40x120) cuesta $29.99
                costoCaja = 29.99;
            }
            else
            {
                // La caja es personalizada cuesta $49.99
                costoCaja = 49.99;
            }
            
            
            
        }
        //tipos de envio: "gratis", "pago", "express"
        void calcularCostoEnvio(){
            if (tipoEnvio == "gratis")
            {
                costoEnvio = 0.0 + costoCaja;
            }
            else if (tipoEnvio == "pago")
            {
                costoEnvio = 77.50 + costoCaja;
            }
            else
            {
                costoEnvio = 249.99 + costoCaja;
            }          
        }
        void randomTrackID(){
            // genera un string aleatorio
            char code[10];
            srand(time(NULL));
                for(int i=0; i <= 9; i++)
                    code[i] = 33 + rand() % (126 - 33);
            trackID = code;
        }

        void setTipoEnvio(string tipoEnvio){
            this -> tipoEnvio = tipoEnvio; //"gatis" "pago" "express"
        }
        void setDimensionesProducto(float alto, float ancho, float profundidad){
            this -> dimensionesProducto[0] = alto;
            this -> dimensionesProducto[1] = ancho;
            this -> dimensionesProducto[2] = profundidad;
        }

        string getTipoEnvio(){return tipoEnvio;}

        float getCostoEnvio(Producto p){

            float x, y, z;
            x = p.getDimensionX();
            y = p.getDimensionY();
            z = p.getDimensionZ();

            setDimensionesProducto(x,y,z);
            calcularCostoCaja();
            calcularCostoEnvio();

            return costoEnvio;
            }
        string getTrackID(){return trackID;}
};//clase Envio

#endif