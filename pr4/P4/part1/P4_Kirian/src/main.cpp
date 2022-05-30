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