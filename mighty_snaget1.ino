#include <SoftwareSerial.h>
int main(){
  
init( );
const unsigned short lr=3,lv=2;
  
//cnfigu puertos digitales exit
  
Serial.begin(9600);
  

int vacio[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    int Numero=0, Columna=0,Fila=0;

    while(Numero!=2){
        for(int colm=0;colm < 8;colm++){
            for(int elem=0;elem<8;elem++){
                Serial.print(vacio[colm][elem]);
            }
            Serial.println();
        }

         Serial.print("escoja la columna que desea modificar: ");
      	 while(Serial.available()==0);
         Columna=Serial.parseInt();
      	 Serial.println(Columna);
         Serial.print("en un rango de 1 a 8 escoja la el caracter que quiere modificar: ");
	     while(Serial.available()==0);
      	 Fila=Serial.parseInt();
      	 Serial.println(Fila);
         vacio[Fila-1][Columna-1]=1;

         Serial.print("si desea terminar ingrese 2, si desea continuar ingrese 1: ");
         while(Serial.available()==0);
      	 Numero=Serial.parseInt();
      	 Serial.println(Numero);
    }


  while(1);
  

return 0;
}