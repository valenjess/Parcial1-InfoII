#include <SoftwareSerial.h>

int main(){
  
#define col1 {1,1,1,1,1,1,1,1}
#define col3 {1,1,0,0,1,0,0,0}
#define b1 {1,0,0,1,0,0,0,1}
#define c1 {1,1,0,0,0,0,1,1}
#define j1 {1,1,0,0,0,0,0,0}
#define lb {0,0,0,0,0,0,1,1}


int eleccion=0;
int letra, retraso=0;
int estilo;

//puertos seriales
const int Ser=2;
const int rclk=4;
const int srclk=5;


void ingresoDatos( short int ,short int ,short int ,short int);
void Verificacion(int , int, int);
void LetrasAbe(int , int, int, int);
void imagen(int ,int ,int,int);
void publik();

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
      //primera eleccion, ingresas una sola letra ponerlo en los 64 leds/
      if (estilo==1){
        Serial.println("Su eleccion de letra-->");
        letra=Serial.parseInt();
        Serial.println(letra);
        
        LetrasAbe(letra,Ser,srclk,rclk);
      }

      else if(estilo==2){
        publik();

      }
}

else if(eleccion==3){

        while(Serial.available()==0);
        Serial.println("Elija en tiempo de retraso:");
        retraso=Serial.parseInt();
        Serial.print(retraso);

        while(letra!=0){
        int opcion=0;
        while(Serial.available()==0);
        Serial.println("Desea: 1.letra predeterminada o 2.crear un patrón");
        opcion=Serial.parseInt();
          
          if (opcion==1){
           Serial.println("Su eleccion de letra-->");
           letra=Serial.parseInt();
           Serial.print(letra);
           LetrasAbe(letra,Ser,srclk,rclk);
             delay(retraso);}
          
          
        
         else{
   
               publik();} 
          delay(retraso);}
    }
  
while(1);
  

return 0;
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
           ingresoDatos(((arreglo+k)+bits),Ser,srclk,rclk);
       }
   }
}

void publik(){
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
        Serial.println(Numero);}
 
    }
void LetrasAbe(int Letra,int Ser, int srclk, int rclk){

    if (Letra==65){
        malloc ;int A[8][8]={col1,col1,col3,col3,col3,col3,col1,col1};
        imagen(A[8][8], Ser, srclk, rclk);
      	free;A[8][8];
    }
    else if(Letra==66){
        malloc ;int B[8][8]={col1,col1,b1,b1,b1,b1,{1,0,0,1,0,0,1,0},{0,1,1,0,1,1,0,0}};;
        imagen(B[8][8], Ser, srclk, rclk);
      	free; B[8][8];
    }
    else if(Letra==67){
    	malloc ;int C[8][8]={col1,col1,c1,c1,c1,c1,c1,c1};
      	imagen(C[8][8], Ser, srclk, rclk);
      	free; C[8][8];
    }
    else if(Letra==68){
    	malloc ;int D[8][8]={col1,col1,c1,c1,c1,c1,{0,1,1,1,1,1,1,0},{0,0,1,1,1,1,0,0}};
    	imagen(D[8][8], Ser, srclk, rclk);
      	free;D[8][8];
    }
    else if(Letra==69){
    	malloc ;int E[8][8]={col1,col1,b1,b1,b1,b1,{1,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,1}};
    	imagen(E[8][8], Ser, srclk, rclk);
		free;E[8][8];
    }
    else if(Letra==70){
    	malloc ;int F[8][8]={col1,col1,col3,col3,col3,col3,{1,1,0,0,0,0,0,0},{1,1,0,0,0,0,0,0}};
    	imagen(F[8][8], Ser, srclk, rclk);
      	free;F[8][8];

    }
    else if(Letra==71){
    	malloc ;int G[8][8]={col1,col1,{1,1,0,0,1,0,0,1},{1,1,0,0,1,0,0,1},{1,1,0,0,1,0,0,1},{1,1,0,0,1,0,0,1},{1,1,0,0,1,0,0,1},{1,1,0,0,1,1,1,1}};
    	imagen(G[8][8], Ser, srclk, rclk);
      	free;G[8][8];
    }
    else if(Letra==72){
    	malloc ;int H[8][8]={col1,col1,{0,0,0,0,1,0,0,0},{0,0,0,0,1,0,0,0},{0,0,0,0,1,0,0,0},{0,0,0,0,1,0,0,0},col1,col1};
    	imagen(H[8][8], Ser, srclk, rclk);
      	free;H[8][8];
    }
    else if(Letra==73){
    	malloc ;int I[8][8]={c1,c1,c1,col1,col1,c1,c1,c1};
    	imagen(I[8][8], Ser, srclk, rclk);
      	free;I[8][8];
    }
    else if(Letra==74){
    	malloc ;int J[8][8]={{1,1,0,0,0,1,1,1},{1,1,0,0,0,1,1,1},{1,1,0,0,0,0,0,1},col1,{1,1,1,1,1,1,1,0},j1,j1,j1};
    	imagen(J[8][8], Ser, srclk, rclk);
      	free;J[8][8];
    }
    else if(Letra==75){
    	malloc ;int K[8][8]={col1,col1,{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,1,0,0,1,0,0},{0,1,0,0,0,0,1,0},{1,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,1}};
    	imagen(K[8][8], Ser, srclk, rclk);
      	free; K[8][8];
    }
    else if(Letra==76){
    	malloc ;int L[8][8]={col1,col1,lb,lb,lb,lb,lb,lb};
    	imagen(L[8][8], Ser, srclk, rclk);
        free;L[8][8];
      
    }
    else if(Letra==77){
    	malloc ;int M[8][8]={col1,col1,{0,1,0,0,0,0,0,0},{0,0,1,1,0,0,0,0},{0,0,1,1,0,0,0,0},{0,1,0,0,0,0,0,0},col1,col1};
    	imagen(M[8][8], Ser, srclk, rclk);
      	free;M[8][8];
    }
    else if(Letra==78){
    	malloc ;int N[8][8]={col1,col1,{0,1,0,0,0,0,0,0},{0,0,1,0,0,0,0,0},{0,0,0,1,0,0,0,0},{0,0,0,0,1,0,0,0},{0,0,0,0,0,1,0,0},col1};
    	imagen(N[8][8], Ser, srclk, rclk);
    	free; N[8][8];
    }
    else if(Letra==79){
    	malloc ;int O[8][8]={col1,col1,c1,c1,c1,c1,col1,col1};
    	imagen(O[8][8], Ser, srclk, rclk);
      	free;O[8][8];
    }
    else if(Letra==80){
    	malloc ;int P[8][8]={col1,col1,col3,col3,col3,col3,col3,{0,1,1,1,0,0,0,0}};
    	imagen(P[8][8], Ser, srclk, rclk);
      	free; P[8][8];
    }
    else if(Letra==81){
    	malloc ;int Q[8][8]={col1,col1,c1,c1,{1,1,0,0,1,0,1,1},{1,1,0,0,0,1,1,1},col1,col1};
    	imagen(Q[8][8], Ser, srclk, rclk);
      	free; Q[8][8];
    }
    else if(Letra==82){
    	malloc ;int R[8][8]={col1,col1,{1,0,0,1,0,0,0,0},{1,0,0,1,1,0,0,0},{1,0,0,1,0,1,0,0},{1,0,0,1,0,0,1,0},{1,0,0,1,0,0,0,1},{0,1,1,0,0,0,0,1}};
    	imagen(R[8][8], Ser, srclk, rclk);
      	free; R[8][8];
    }
    else if(Letra==83){
    	malloc ;int S[8][8]={{1,1,1,1,0,0,1,1},{1,0,0,1,0,0,1,1},{1,0,0,1,0,0,1,1},{1,0,0,1,0,0,1,1},{1,0,0,1,0,0,1,1},{1,0,0,1,0,0,1,1},{1,0,0,1,0,0,1,1},{1,0,0,0,1,1,1,1}};
    	imagen(S[8][8], Ser, srclk, rclk);
      	free; S[8][8];
    }
    else if(Letra==84){
    	malloc ;int T[8][8]={j1,j1,j1,col1,col1,j1,j1,j1};
    	imagen(T[8][8], Ser, srclk, rclk);
      	free; T[8][8];
    }
    else if(Letra==85){
    	malloc ;int U[8][8]={col1,col1,lb,lb,lb,lb,col1,col1};
    	imagen(U[8][8], Ser, srclk, rclk);
      	free; U[8][8];
    }
    else if(Letra==86){
    	malloc ;int V[8][8]={{1,1,1,1,1,0,0,0},{1,1,1,1,1,1,0,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,1,0},{1,1,1,1,1,1,0,0},{1,1,1,1,1,0,0,0}};
    	imagen(V[8][8], Ser, srclk, rclk);
      	free; V[8][8];
    }
    else if(Letra==87){
    	malloc ;int W[8][8]={col1,{1,1,1,1,1,1,1,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,0,1,0,0,0},{0,0,0,0,0,1,0,0},{1,1,1,1,1,1,1,0},col1};
    	imagen(W[8][8], Ser, srclk, rclk);
      	free; W[8][8];
    }
    else if(Letra==88){
    	malloc ;int X[8][8]={{1,0,0,0,0,0,0,1},{1,1,0,0,0,0,1,1},{0,0,1,0,0,1,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,1,0,0,1,0,0},{1,1,0,0,0,0,1,1},{1,0,0,0,0,0,0,1}};
    	imagen(X[8][8], Ser, srclk, rclk);
      	free; X[8][8];
    }
    else if(Letra==89){
    	malloc ;int Y[8][8]={{1,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0},{0,0,1,0,0,0,0,0},{0,0,0,1,1,1,1,1},{0,0,0,1,1,1,1,1},{0,0,1,0,0,0,0,0},{1,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0}};
    	imagen(Y[8][8], Ser, srclk, rclk);
		free;  Y[8][8];

    }
    else if(Letra==90){
    	malloc ;int Z[8][8]={{1,1,0,0,0,0,0,1},c1,{1,1,0,0,0,1,1,1},{1,1,0,0,1,0,1,1},{1,1,0,1,0,0,1,1},{1,1,1,0,0,0,1,1},c1,{1,0,0,0,0,0,1,1}};
    	imagen(Z[8][8], Ser, srclk, rclk);
        free; Z[8][8];

    }
}