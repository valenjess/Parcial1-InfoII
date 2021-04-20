const int Ser=2;
const int rclk=4;
const int srclk=5;

void ingresoDatos( int , int , int ,int );
void Verificacion(int, int, int);

void setup()
{
  pinMode(Ser, OUTPUT);
  pinMode(rclk, OUTPUT);
  pinMode(srclk, OUTPUT);
  
  digitalWrite(Ser,0);
  digitalWrite(rclk,0);
  digitalWrite(srclk,0);
  
  int a[2][4]={{1,0,1,0},{0,1,1,1}};
  int  A[8][8]={{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,0,0,1,0,0,0},{1,1,0,0,1,0,0,0},{1,1,0,0,1,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1}};
  
  Verificacion(Ser,srclk,rclk);

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