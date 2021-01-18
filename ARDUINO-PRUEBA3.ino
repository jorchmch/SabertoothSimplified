// ARDUINO NANO

#include <SabertoothSimplified.h>
#include <SoftwareSerial.h>
SoftwareSerial SWSerial(NOT_A_PIN, 6);  //TX ES  PIN 6
SabertoothSimplified ST(SWSerial); 
int power=0;
int DUR=20;   // Duracion
// 3 FUNCIONES: 
// [1] creciente: de -127 a 127 en drive.
// [2] decreciente: de 127 a -127 en drive.
// [3] printear: imprime en terminal.

// Observacion: Se puede usar turn() y drive() al mismo tiempo.
void setup()
{
  Serial.begin(9600);
  SWSerial.begin(9600); // This is the baud rate you chose with the DIP switches.
  Serial.println("INICIALIZADO PROGRAMA...");
}

// drive() :para ir adelante y atras, positivo adelante. (-127 a 127)
// turn()  :girar derecha o izquierda, positivo derecha. (-127 a 127)
void loop()
{
    //ORDENES
    CRECIENTE();
    delay(2000); //2 segundos
    
  
    DECRECIENTE();
    delay(2000); //2 segundos

    
    // detenerse sin apagar.
    DETENER();
    
    // se puede añadir  ST.drive(#VALOR); donde #VALOR agrega un radio en el giro
    Serial.println("NIVEL DE GIRO : MAXIMO DERECHA");
    ST.turn(127);   //maximo derecha
    delay(5000);  // Esperar 5 segundos.
    
    Serial.println("NIVEL DE GIRO : MAXIMO IZQUIERDA");
    ST.turn(-127);   //maximo derecha
    delay(5000);  // Esperar 5 segundos.

    DETENER();


    
}
void CRECIENTE(){
  for (power = -127; power < 127; power ++)
    {
      ST.drive(power);  
      delay(DUR);
      IMPRIMIR();
    } 
}
void DECRECIENTE(){
  for (power = 127; power > -127; power --)
    {
      ST.drive(power);  
      delay(DUR);
      IMPRIMIR();
    }
}


void IMPRIMIR(){
  Serial.print("NIVEL DE GIRO : ");
  Serial.println(power);;
}

void DETENER(){
    ST.turn(0);
    ST.drive(0);
    Serial.println("NIVEL DE GIRO : DETENIDO");
    delay(5000);  // Esperar 5 segundos.
}


       
