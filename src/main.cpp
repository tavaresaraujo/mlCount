#include <Arduino.h>

double calculoVazao;
volatile int contador;
float fluxoAcumulado = 0;
float metroCubico = 0;
float ContaAgua = 0;

void Vazao()
{
  contador++;
}

void setup()
{
  pinMode(2, INPUT);
  attachInterrupt(0, Vazao, RISING);
  Serial.begin(9600);
}

void loop()
{

  contador = 0;
  interrupts();
  delay(1000);
  noInterrupts();

  calculoVazao = (contador * 2.25);
  fluxoAcumulado = fluxoAcumulado + (calculoVazao / 1000);
  metroCubico = fluxoAcumulado / 1000;
  ContaAgua = metroCubico * 3.59;
  calculoVazao = calculoVazao * 60;
  calculoVazao = calculoVazao / 1000;

  // Serial.println("Litros por minutos :");
  // Serial.println(calculoVazao);
  Serial.println("Gasto Total Em litros :");
  Serial.println(fluxoAcumulado);
  // Serial.println("Metros cubicos totais:");
  // Serial.println(metroCubico);
  // Serial.println("R$ :");
  // Serial.println(ContaAgua);

  Serial.println("_________________________________");

}

