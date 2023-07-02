

/*******************************************************************************
   Título:      TCC  Engenharia Mecatrônica.

   Descrição:   C L P   ---  I H M

   Processador: Esp32_FreeRTOs


   Desenvolvido: MRPRO Tecnologia e Automação

   Autor: Tecnologo. Marcelo Rodrigues     
   CREA-SP 5070505617

   Data de Inicio: 02/07/2023       Versão:   2023.3.7

   Versão Multi-folhas VS-CODE
        

   Nome do Arquivo:
   https://capsistema.com.br/index.php/2020/11/27/como-usar-i2c-no-arduino-comunicacao-entre-duas-placas-arduino/   data da visita 05/06/2022
  
*******************************************************************************/  
/* ============================================================================  
                                                              
                                       _                      
                                      / \                     
                                     |oo >                    
                                     _\=/_                    
                    ___         #   /  _  \   #               
                   /<> \         \\//|/.\|\\//                
                 _|_____|_        \/  \_/  \/                 
                | | === | |          |\ /|                    
                |_|  0  |_|          \_ _/                    
                 ||  0  ||           | | |                    
                 ||__*__||           | | |                    
                |* \___/ *|          []|[]                    
                /=\ /=\ /=\          | | |                    
________________[_]_[_]_[_]_________/_]_[_\_____________________________________
                                                                             
=====================================================================================================      

=====================================================================================================   */

/*Biblioteca do Arduino*/
#include <Arduino.h>


/*Biblioteca FreeRTOS*/
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


/*Mapeamento dos pinos*/
#define LED 2


/* Variáveis para armazenamento do handle das tasks*/
TaskHandle_t tasks1handle = NULL;
TaskHandle_t tasks2handle = NULL;

/*protótipos das Tasks*/
void vTask1(void *pvParameteters);
void vTask2(void *pvParameteters);


void setup() {
   Serial.begin(9600);
   pinMode(LED,OUTPUT);

   xTaskCreate(vTask1,"TASK1",configMINIMAL_STACK_SIZE,NULL,1,&tasks1handle);
   xTaskCreate(vTask2,"TASK2",configMINIMAL_STACK_SIZE+1024,NULL,2,&tasks2handle);
 
}

void loop() {
 vTaskDelay(3000);

}

void vTask1(void *pvParameters)
{
  pinMode(LED,OUTPUT);

  while (1)
  {
    /* code */
    digitalWrite(LED,!digitalRead(LED));
    vTaskDelay(pdMS_TO_TICKS(200));
  }
  
}


void vTask2(void *pvParameters)
{
 int cont = 0;

  while (1)
  {
    /* code */
    Serial.println("Task 2: " + String(cont++));
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
  
}

