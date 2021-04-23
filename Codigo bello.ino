#include <SoftwareSerial.h>

int main(){


int eleccion=0;
int Letra, retraso=0,cantidad;
int estilo;
int** patron;

//puertos seriales
const int Ser=2;
const int rclk=4;
const int srclk=5;

//prototipo de las funciones  
void ingresoDatos( int** ,int ,int ,int);
void Verificacion(int , int, int);
int** imagen(int ,int ,int);
void publik(int ,int ,int ,int ,int );

//inicializacion de los pines del puerto Ser,rclk y srclk
pinMode(Ser, OUTPUT);
pinMode(rclk, OUTPUT);
pinMode(srclk, OUTPUT);

digitalWrite(Ser,0);
digitalWrite(rclk,0);
digitalWrite(srclk,0); 
  
init( );
  
  Serial.begin(9600);

  Serial.println("1.Verificar que todos los leds funcionan ");
  Serial.println("2.Mostrar único patrón de leds");
  Serial.println("3.Mostrar una secuencia de patrones");
  Serial.println("4.Mostrar el manual de instrucciones para ingresar un patron de leds");

  while(Serial.available()==0);
  Serial.println("Ingrese la opcion que desee:");
  eleccion=Serial.parseInt();
  Serial.print(eleccion);

  /*primera eleccion, la verificacion del estado de los 64 leds con un encedido y apagado */
if (eleccion==1){
    Verificacion(Ser,srclk,rclk);
}
  
  /*Segunda eleccion, el mostrar el unico patron dos elecciones para hacer el patron unico */
else if(eleccion==2){
	patron=imagen(Ser,srclk,rclk);
    ingresoDatos(patron,Ser,srclk,rclk);
}

else if(eleccion==3){
  Serial.println("Ingrese el retraso que desee:");
  while(Serial.available()==0);
  retraso=Serial.parseInt();
  Serial.print(retraso);
  
  Serial.println("Ingrese cantidad de patrones:");
  while(Serial.available()==0);
  cantidad=Serial.parseInt();
  Serial.print(cantidad);
  publik(retraso,cantidad,Ser, srclk,rclk );

 
   }
else if(eleccion==4){
    Serial.println("Para ingresar un patron de leds se hace de la siguente forma:");
	Serial.println("1.el programa le pedira que escoja del 1 al 8, lo cual significa ");
  	Serial.println("la cantidad de columnas de la matriz de leds");
  	Serial.println("           |->0");
  	Serial.println("           |  0");
  	Serial.println("columna ===|  0");
  	Serial.println("           |  0");
  	Serial.println("           |->0");
  	Serial.println("2.Una vez escogido la columna, el paso siguente indicado por el porgrama es ingresar un numero");
    Serial.println("entre el 1 y el 8, el cual significa el elemento de arriba hacia bajo que quieres encender");
    Serial.println("es decir, si por ejemplo escoges el elemento 2, se cambiara el elemento de la columna escogida");
    Serial.println("             0");
  	Serial.println("elemento 2 ->0");
  	Serial.println("             0");
  	Serial.println("             0");
  	Serial.println("             0");
  	Serial.println("             0");
  	Serial.println("             0");
  	Serial.println("             0");
  	Serial.println("Nota: este proceso se repetira hasta indefinidamente hasta que no indiques cuando ");
  	Serial.println("te lo pidan si deseas terminar o no");
  
}
  
while(1);
  

return 0;
}
  
void ingresoDatos(int** acom, int Ser, int srclk,int rclk){
  	for(int k=0;k<8;k++){
    	for(int bits=0;bits<8;bits++){

    	digitalWrite(Ser,*(*(acom+k)+bits));

    	digitalWrite(srclk,0);
    	digitalWrite(srclk,1);
    	digitalWrite(srclk,0);

    	digitalWrite(rclk,0);
    	digitalWrite(rclk,1);
    	digitalWrite(rclk,0);
        }
    }
}

void Verificacion(int Ser, int srclk,int rclk){
  for(int cont=0;cont<65;cont++){
      	digitalWrite(Ser,1);

    	digitalWrite(srclk,0);
    	digitalWrite(srclk,1);
    	digitalWrite(srclk,0);

    	digitalWrite(rclk,0);
    	digitalWrite(rclk,1);
    	digitalWrite(rclk,0);
        }
  delay(1000);

  

  for(int cont=0;cont<65;cont++){
     digitalWrite(Ser,0);
     digitalWrite(srclk,0);
     digitalWrite(srclk,1);
     digitalWrite(srclk,0);

    	digitalWrite(rclk,0);
    	digitalWrite(rclk,1);
    	digitalWrite(rclk,0);
  }

}

int** imagen(int Ser,int srclk,int rclk){
    int Numero=0,m=0,t=0;
    int **pt = new int*[8];
  
    for(int i=0;i<8;i++){
       pt[i] = new int[8];
    }

    for (int m=0;m<8;m++){
        for( int t=0;t<8;t++){
            pt[m][t]=0;
        }
    }

    while(Numero!=2){
        for(int t=0;t< 8;t++){
            for(int elem=0;elem<8;elem++){
                Serial.print(pt[elem][t]);
            }
    	Serial.println();
        }
    Serial.print("escoja la columna que desea modificar: ");
    while(Serial.available()==0);
    t=Serial.parseInt();
    Serial.println(t);
    Serial.print("en un rango de 1 a 8 escoja la el caracter que quiere modificar: ");
	while(Serial.available()==0);
    m=Serial.parseInt();
    Serial.println(m);
    pt[t-1][m-1]=1;

    Serial.print("si desea terminar ingrese 2, si desea continuar ingrese 1: ");
    while(Serial.available()==0);
    Numero=Serial.parseInt();
    Serial.println(Numero);
        }
return (pt);
}

void publik(int retraso,int cantidad,int Ser,int srclk,int rclk ){
  int** Almacen[8]={};
  int** patrones;

  
  for(int cont=0;cont<cantidad;cont++){{
    patrones= imagen(Ser,srclk,rclk);}
    Almacen[cont]=patrones;
  }
  for(int cant=0;cant<=4;cant++){
    for(int cant1=0;cant1<cantidad;cant1++){
  ingresoDatos( Almacen[cant1],Ser,srclk,rclk);
    delay(retraso);}
  }
}