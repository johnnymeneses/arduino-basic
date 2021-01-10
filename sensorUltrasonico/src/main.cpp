/*=============================================================================

Autor:        Johnny Meneses [bilbo_vader@outlook.com]
Descrição:    Sensor Ultrasônico
              O funcionamento do HC-SR04 se baseia no envio de sinais ultrassônicos pelo sensor,
              que aguarda o retorno (echo) do sinal, e com base no tempo entre envio e retorno,
              calcula a distância entre o sensor e o objeto detectado.

              Primeiramente é enviado um pulso de 10µs, indicando o início da transmissão de dados. Depois disso,
              são enviado 8 pulsos de 40 KHz e o sensor então aguarda o retorno (em nível alto/high), para determinar a 
              distância entre o sensor e o objeto, utilizando a equação Distância = (Tempo echo em nível alto * velocidade do som) /2

Lista de Componentes
[1] Arduino Uno R3
[1] Ultrasonic Distance Sensor

 *===========================================================================*/  

#include <Arduino.h>
#include "Ultrasonic.h" //Inclusão da Biblioteca - Sensor Ultrasônico

  const int echoPin = 6; //PINO DIGITAL UTILIZADO PELO HC-SR04 ECHO(RECEBE)
  const int trigPin = 7; //PINO DIGITAL UTILIZADO PELO HC-SR04 TRIG(ENVIA)

  Ultrasonic ultrasonic(trigPin,echoPin); //INICIALIZANDO OS PINOS DO ARDUINO


void setupSensor()
{
  pinMode(echoPin, INPUT); //Pino de Entrada (Recebe)
  pinMode(trigPin, OUTPUT); //Pino de Saída (Envia)

}

void setup()
{
  Serial.begin(9600);
  setupSensor();
}


void acionaSensor()
{
  Serial.print("Sensor 01: ");
  Serial.print(ultrasonic.read()); // Prints the distance on the default unit (centimeters)
  Serial.println("cm");
  delay(1000);

}

void loop()
{
  acionaSensor();
}




