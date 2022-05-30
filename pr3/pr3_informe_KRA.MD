
###                                    </p>
    Processadors Digitals
</p>

# </br> PRÁCTICA 3  :  WIFI y BLUETOOTH

## Materiales
1 ESP32
1 Cable USB

## </br> 3.1. Código practica A

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>


// SSID & Password
const char* ssid = "Xiaomi_11T_Pro"; // Enter your SSID here
const char* password = "f5cbd8a82232"; //Enter your Password here

WebServer server(80);

void handle_root();

void setup() {
Serial.begin(115200);
Serial.println("Try Connecting to ");
Serial.println(ssid);

// Connect to your wi-fi modem
WiFi.begin(ssid, password);

// Check wi-fi is connected to wi-fi network
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected successfully");
Serial.print("Got IP: ");
Serial.println(WiFi.localIP()); //Show ESP32 IP on serial

server.on("/", handle_root);

server.begin();
Serial.println("HTTP server started");
delay(100);
}

void loop() {
server.handleClient();
}
// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1> Hola! Esto Funciona!! </h1>\
</body>\
</html>";

// Handle root url (/)
void handle_root() {
server.send(200, "text/html", HTML);
}


## </br> 3.2. Código practica B

#include <Arduino.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;

void setup() {
Serial.begin(115200);
SerialBT.begin("KirianTEST"); //Bluetooth device name
Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
  SerialBT.write(Serial.read());
  }

  if (SerialBT.available()) {
  Serial.write(SerialBT.read());
  }

delay(20);
}



## </br> 3.3.Fotos del circuito

En el apartado A no requiere montaje por lo que no hay foto del circuito, pero si del resultado en la pagina web.

Respecto al apartado B, intentamos hacerlo con iPhone, pero lamentablemente solo funciona con Android, por lo que al descargar la aplicación en un 
dispositivo Android y seguir exactamente los mismos pasos finalmente pudimos comunicarnos con el terminal a través del dispositivo móvil.

![](web.png)
