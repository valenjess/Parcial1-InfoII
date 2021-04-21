#include <SoftwareSerial.h>
int eleccion=0;
int letra, retraso=0;

//puertos seriales
const int Ser=2;
const int rclk=4;
const int srclk=5;


void ingresoDatos( int , int , int ,int);
void Verificacion(int, int, int);
void imagen(int ,int ,int,int){

//inicializacion de los pines del puerto Ser,rclk y srclk
pinMode(Ser, OUTPUT);
pinMode(rclk, OUTPUT);
pinMode(srclk, OUTPUT);

digitalWrite(Ser,0);
digitalWrite(rclk,0);
digitalWrite(srclk,0);


void setup()
{

  Serial.begin(9600);

  Serial.println("1.Verificar que todos los leds funcionan ");
  Serial.println("2.Mostrar único patrón de leds");
  Serial.println("3.Mostrar una secuencia de patrones");

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

      Serial.println("--> Opcciones:");
      Serial.println("Ingrese 1 si desea elegir una letra mayúscula predeterminada");
      Serial.println("Ingrese 2 si desea realizar su propio diseño");

      while(Serial.available()==0);
        Serial.println("Su eleccion-->");
        estilo=Serial.parseInt();
        Serial.print(estilo);
      /*primera eleccion, ingresas una sola letra ponerlo en los 64 leds*/
      if (estilo==1){
        Serial.println("Su eleccion de letra-->");
        letra=Serial.parseInt();
        Serial.print(letra);
      //IF LETRA == 65
      //IngresoDato(letra);
        imagen([8][8],Ser,srclk,rclk)//organizar el arreglo con la letra que se desea poner

      }

      else if(estilo==2){
      //Ingrese el patron que deseee

      }

  }

   else if(eleccion==3){

        while(Serial.available()==0);
        Serial.println("Elija en tiempo de retraso:");
        retraso=Serial.parseInt();
        Serial.print(retraso);

        while(letra!=0){
        while(Serial.available()==0);
        Serial.println("Ingrese el patron letra por letra e introduzca 0 para finalizar");
        letra=Serial.parseInt();
        Serial.print(letra);
        }
          //IngresarDatos

    }

}

void loop()
{
}


void ingresoDatos( int acom, int Ser, int srclk,int rclk){

    digitalWrite(Ser,acom);

    digitalWrite(srclk,0);
    digitalWrite(srclk,1);
    digitalWrite(srclk,0);

    digitalWrite(rclk,0);
    digitalWrite(rclk,1);
    digitalWrite(rclk,0);
}

void Verificacion(int Ser, int srclk,int rclk){
  for(int cont=0;cont<65;cont++){
      ingresoDatos(1,Ser,srclk,rclk);
  }
  delay(500);
  for(int cont=0;cont<65;cont++){
     ingresoDatos(0,Ser,srclk,rclk);
  }

}

void imagen(int arreglo,int Ser,int srclk,int rclk){
  for(int k=0;k<8;k++){
       for(int bits=0;bits<8;bits++){
           ingresoDatos(*(*(arreglo+k)+bits),Ser,srclk,rclk);
       }
   }
}
