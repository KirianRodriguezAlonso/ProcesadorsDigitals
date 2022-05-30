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
