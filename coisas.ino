#include <stdint.h>

//const byte LED_Green = D4;
const uint8_t LED_Verde = D4; // both can be used, 2 (gpio) or D4 (board)
const uint8_t LED_Amarelo = D7;
const uint8_t LED_Vermelho = D3;
const uint8_t Buzzer = D5;
const uint8_t tecla = D0;
#define LDR A0

void setup() {
  // put your setup code here, to run once:
  // Configura saídas digitais
  pinMode(LED_Verde,OUTPUT);
  pinMode(LED_Amarelo,OUTPUT);
  pinMode(LED_Vermelho,OUTPUT);

  // Configura entradas digitais
  pinMode(tecla,INPUT); // 10k pull-up externo

  // Configura entradas/saídas analógicas
  // no previous config needed

  // Configura serial para mostrar resultados
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_Verde, HIGH);
  delay(1000); // 1000 mili-segundos = 1 segundo
  digitalWrite(LED_Verde,LOW);
  delay(1000); // 1 segundo

  if(digitalRead(tecla)== LOW){
    digitalWrite(LED_Vermelho,HIGH);
  }
  else {
    digitalWrite(LED_Vermelho,LOW);
  }

  Serial.println(analogRead(LDR));

  for (int i = 0; i <=255; i++){
    analogWrite(LED_Amarelo,i);
    //analogWrite(Buzzer,i);
    delay(10);
  }

  for (int i = 255; i >= 0 ; i--){
    analogWrite(LED_Amarelo,i);
    //analogWrite(Buzzer,i);
    delay(10);
  }  
}

