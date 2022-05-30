
###                                    </p>
    Processadors Digitals
</p>

# </br> PRÁCTICA 4  :  SISTEMAS OPERATIVOS EN TIEMPO REAL


## Materiales
1 ESP32
1 Cable USB

## </br> 3.1. Código ejercicio practico 1
void setup()
{
Serial.begin(112500);
xTaskCreate(
anotherTask, /* Task function. */
"another Task", /* name of task. */
10000, /* Stack size of task */
NULL, /* parameter of the task */
1, /* priority of the task */
NULL); /* Task handle to keep track of created task */
}
void loop()
{
Serial.println("this is ESP32 Task");
delay(1000);
}
void anotherTask( void * parameter )
{
for(;;)
{
Serial.println("this is another Task");
delay(1000);
}
vTaskDelete( NULL );
}



## </br> 3.2. Código ejercicio practico 2

#include <Arduino.h>

const int led1 = 2; // Pin of the LED
const int led2 = 18; // Pin of the LED


void toggleOffLED(void * parameter){
for(;;){ // loop 10
// Turn the LED on
digitalWrite(led1, HIGH);
Serial.println("ON  LED");
// Pause the task for 500ms
vTaskDelay(500 / portTICK_PERIOD_MS);
}
vTaskDelete(NULL);
}  

void toggleOnLED(void * parameter){
for(;;){
// loop de 10 veces

// Turn the LED on
digitalWrite(led1, LOW);
Serial.println("OFF  LED");
// Pause the task for 500ms
vTaskDelay(500 / portTICK_PERIOD_MS);
}
vTaskDelete(NULL);
}

void setup(){
  Serial.begin(9600);
  pinMode(led1,OUTPUT);

  xTaskCreate(
    toggleOnLED,
    // Function that should be called
    "Toggle ON LED",
    // Name of the task (for debugging)
    1000,
    // Stack size (bytes)
    NULL,
    // Paramecollect2: error: ld returned 1 exit statuster to pass
    1,
    // Task priorityoid * parameter
    NULL
  );

  xTaskCreate(
  toggleOffLED,
    // Function that should be called
    "Toggle OFF LED",
    // Name of the task (for debugging)
    1000,
    // Stack size (bytes)
    NULL,
    // Paramecollect2: error: ld returned 1 exit statuster to pass
    1,
    // Task priorityoid * parameter
    NULL
  );
}

void loop(){}

## </br> 3.3.Observaciones

El codigo del ejercicio practico 1, funciona tal que crea una tasca con su nombre, tamaño, prioridad, parametros, etc.
Mas adelante se crea un loop donde imprime por el terminal "this is ESP32 Task" cada segundo que pase. Por último hay un void que crea un loop infinito donde imprime por 
pantalla "this is another Task" cada segundo que pase, y cuando salga de este loop infinito (algo que nunca pasará), vTaskDelete(NULL) se ocupara de eliminar la tasca pertinente.

En el codigo del ejercicio practico 2, implementamos un codigo que tiene dos tareas, una que apaga el led y otra que lo enciende.



![](web.png)
