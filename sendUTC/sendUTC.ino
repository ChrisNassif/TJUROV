#include "WiFi.h"
#include "ESPAsyncWebServer.h"

const char* ssid = "UROSUS";
const char* password = NULL;

// Set web server port number to 80
AsyncWebServer server(80);

IPAddress IP;

time_t get_UTC_Time() {
  return now()
}

void setup() {
  Serial.begin(9600);

  WiFi.mode(WIFI_AP)
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  // Set your Static IP address
  IPAddress local_IP(192, 168, 1, 184);
  // Set your Gateway IP address
  IPAddress gateway(192, 168, 1, 1);

  IPAddress subnet(255, 255, 0, 0);
  IPAddress primaryDNS(8, 8, 8, 8);   //optional
  IPAddress secondaryDNS(8, 8, 4, 4); //optional

  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());


  server.on("/UTC_Time", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", get_UTC_Time().to_string());
  });

  server.begin()
  
}

void loop() {
  


}


// DEPENDENCIES: (install in the following order)

// Time Library in library manager
// https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/
// install the esp32 board in tools/ board manager
// download the following and add it with [Sketch/Include Library/Add .ZIP Library]: 
//    https://github.com/me-no-dev/ESPAsyncWebServer/archive/master.zip



// RESOURCES:
// https://randomnerdtutorials.com/esp32-access-point-ap-web-server/#:~:text=ESP32%20IP%20Address,ESP32%20point%20will%20be%20printed.
// https://randomnerdtutorials.com/esp32-static-fixed-ip-address-arduino-ide/ 


// OTHER MISC RESOURCES THAT COULD BE USEFULL LATER:
// If connection through https doesn't work then:
// https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/src/WiFiUdp.h
// https://gist.github.com/santolucito/4016405f54850f7a216e9e453fe81803

