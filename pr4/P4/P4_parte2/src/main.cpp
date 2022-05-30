#include <Arduino.h>

const int led1 = 2; // Pin of the LED
const int led2 = 18; // Pin of the LED


void toggleLED1(void * parameter){
for(;;){ // loop infinit
// Turn the LED on
digitalWrite(led1, HIGH);
Serial.println("ON  LED1");
// Pause the task for 500ms
vTaskDelay(500 / portTICK_PERIOD_MS);
// Turn the LED off
digitalWrite(led1, LOW);
Serial.println("OFF LED1");
// Pause the task again for 500ms
vTaskDelay(500 / portTICK_PERIOD_MS);
}
vTaskDelete(NULL);
}  

void toggleLED2(void * parameter){
for(int i = 0; i < 10; i++){
// loop de 10 veces
// Turn the LED on
digitalWrite(led2, HIGH);
Serial.println("ON  LED2");
// Pause the task for 500ms
vTaskDelay(500 / portTICK_PERIOD_MS);
// Turn the LED off
digitalWrite(led2, LOW);
Serial.println("OFF LED2");
// Pause the task again for 500ms
vTaskDelay(500 / portTICK_PERIOD_MS);
}
vTaskDelete(NULL);
}

void setup(){
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  xTaskCreate(
    toggleLED1,
    // Function that should be called
    "Toggle LED1",
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
  toggleLED2,
    // Function that should be called
    "Toggle LED2",
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
