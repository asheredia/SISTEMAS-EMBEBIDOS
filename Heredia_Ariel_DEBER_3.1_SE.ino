/*NOTA: TANTO MAESTRO COMO ESCLAVOS VAN EN SKETCHES DIFERENTES
 SE HA UNIFICADO PARA EVITAR LA NAVEGACIÓN ENTRE CARPETAS DE ESTE 
 REPOSITORIO
*/

/*  
 * CAPÍTULO III: MÓDULOS DE COMUNICACIÓN
 * DEBER 3.1: Recepción y envío de mensajes por comunicación I2C   
 * OBJETIVO: Enviar mensajes desde un master hacia tres esclavos y encerder leds en función de la comunicación
 * NOMBRE: HEREDIA ARIEL
 *  Funciones:   Wire.begin()  // Inicializa el hardware del bus
 *               Wire.beginTransmission(address); //Comienza la transmisión
 *               Wire.endTransmission(); // Finaliza la transmisión
 *               Wire.requestFrom(address,nBytes);  //solicita un numero de bytes al esclavo en la dirección address
*/

/*----------------------------------------MAESTRO------------------------------*/

#include <Wire.h>                         //Llamar a biblioteca

char caracter;                            //Definir caracter a ser leido  
void setup() {  
  Wire.begin();                           //Inicio comunicación I2C
  Serial.begin(9600);                     //Inicio comunicación Serial
  Serial.println("Bienvenido MASTER");    //Mensaje inicial

}

void loop() {
  if(Serial.available()>0){               //Verifica que existan datos a ser leídos
    
    caracter=Serial.read();               //Lectura de caracter
    caracter=toLowerCase(caracter);               //Conversión a minúsculas
    switch(caracter){                         //Sentencia de control según el caracter leído
      case 'q':
        Wire.beginTransmission(5);        //Configuracion del esclavo a enviar mensaje
        Wire.write(caracter);                 //Envía el dato al esclavo 1
        Wire.endTransmission();           //Fin de comunicación
      break;
      case 'w':
        Wire.beginTransmission(6);        //Configuracion del esclavo a enviar mensaje
        Wire.write(caracter);                 //Envía el dato al esclavo 1
        Wire.endTransmission();           //Fin de comunicación
      break;
      case 'e':
        Wire.beginTransmission(7);        //Configuracion del esclavo a enviar mensaje
        Wire.write(caracter);                 //Envía el dato al esclavo 1
        Wire.endTransmission();           //Fin de comunicación
      break;
    }
  }
}

/*----------------------------------------ESCLAVO 1------------------------------*/
/*  
 * CAPÍTULO III: MÓDULOS DE COMUNICACIÓN
 * DEBER 3.1: Recepción y envío de mensajes por comunicación I2C   
 * OBJETIVO: Enviar mensajes desde un master hacia tres esclavos y encerder leds en función de la comunicación
 * NOMBRE: HEREDIA ARIEL
 *  Funciones:   Wire.begin()  // Inicializa el hardware del bus
 *               Wire.beginTransmission(address); //Comienza la transmisión
 *               Wire.endTransmission(); // Finaliza la transmisión
 *               Wire.requestFrom(address,nBytes);  //solicita un numero de bytes al esclavo en la dirección address
*/



#include <Wire.h>                           //Llamar a librería
const int leds[4] = {13,12,11,10};          //Vector de valores para pines de los leds
void setup() {
  for(int i=0;i<4;i++){
    pinMode(leds[i],OUTPUT);                //Pines 10-13 declarados como salida
  }
  Wire.begin(5);                            //ID de esclavo
  Serial.begin(9600);                       //Inicio de comunicación serial
  Wire.onReceive(juego1);                   //Evento de recepción de mensajes
  Serial.println("Bienvenido ESCLAVO 1");   //Mensaje inicial
}

void loop() {
  delay(100);
}

void juego1(){
  while(Wire.available()){                  //Verifican si existen mensajes por leer
    Serial.print("Leido: ");                
    char letraleida = Wire.read();          //Recibe dato
    Serial.println(letraleida);             //Mensaje enviado por comunicación serial
    //Encendido y apagado de leds
    for(int i=4;i>=0;i--){
      digitalWrite(leds[i],HIGH);
      delay(5000);
      digitalWrite(leds[i],LOW);
      delay(5000);
    }
  }  
}

/*----------------------------------------ESCLAVO 2------------------------------*/
/*  
 * CAPÍTULO III: MÓDULOS DE COMUNICACIÓN
 * DEBER 3.1: Recepción y envío de mensajes por comunicación I2C   
 * OBJETIVO: Enviar mensajes desde un master hacia tres esclavos y encerder leds en función de la comunicación
 * NOMBRE: HEREDIA ARIEL
 *  Funciones:   Wire.begin()  // Inicializa el hardware del bus
 *               Wire.beginTransmission(address); //Comienza la transmisión
 *               Wire.endTransmission(); // Finaliza la transmisión
 *               Wire.requestFrom(address,nBytes);  //solicita un numero de bytes al esclavo en la dirección address
*/



#include <Wire.h>                           //Llamar a librería

const int leds[4] = {13,12,11,10};          //Vector de valores para pines de los leds
void setup() {
  for(int i=0;i<4;i++){
    pinMode(leds[i],OUTPUT);                //Pines 10-13 declarados como salida
  }
  Wire.begin(6);                            //ID de esclavo
  Serial.begin(9600);                       //Inicio de comunicación serial
  Wire.onReceive(juego2);                   //Evento de recepción de mensajes
  Serial.println("Bienvenido ESCLAVO 2");
}

void loop() {
  delay(100);

}

void juego2(){
  while(Wire.available()){            //Verifican si existen mensajes por leer
    Serial.print("Leido: ");
    char letraleida2 = Wire.read();   //Recibe dato
    Serial.println(letraleida2);      //Mensaje enviado por comunicación seria
    //Encendido y apagado de leds.
    for(int j=4;j>=0;j--){
      digitalWrite(leds[j],HIGH);
      delay(5000);
      digitalWrite(leds[j],LOW);
      delay(5000);
    }
  }
}


/*----------------------------------------ESCLAVO 3------------------------------*/
/*  
 * CAPÍTULO III: MÓDULOS DE COMUNICACIÓN
 * DEBER 3.1: Recepción y envío de mensajes por comunicación I2C   
 * OBJETIVO: Enviar mensajes desde un master hacia tres esclavos y encerder leds en función de la comunicación
 * NOMBRE: HEREDIA ARIEL
 *  Funciones:   Wire.begin()  // Inicializa el hardware del bus
 *               Wire.beginTransmission(address); //Comienza la transmisión
 *               Wire.endTransmission(); // Finaliza la transmisión
 *               Wire.requestFrom(address,nBytes);  //solicita un numero de bytes al esclavo en la dirección address
*/



#include <Wire.h>                           //Llamar a librería

const int leds[4] = {13,12,11,10};          //Vector de valores para pines de los leds
void setup() {
  for(int i=0;i<4;i++){
    pinMode(leds[i],OUTPUT);                //Pines 10-13 declarados como salida
  }
  Wire.begin(7);                            //ID de esclavo
  Serial.begin(9600);                       //Inicio de comunicación serial
  Wire.onReceive(juego3);                   //Evento de recepción de mensajes
  Serial.println("Bienvenido ESCLAVO 3");   
}

void loop() {
  delay(100);

}

void juego3(int bytes){               
  while(Wire.available()){                  //Verifican si existen mensajes por leer
    Serial.print("Leido: ");
    char letraleida3 = Wire.read();         //Recibe dato
    Serial.println(letraleida3);            //Mensaje enviado por cx serial
    //Encendido y apagado de leds
    for(int k=4;k>=0;k--){
      digitalWrite(leds[k],HIGH);
      delay(5000);
      digitalWrite(leds[k],LOW);
      delay(5000);
    }
  }
}
