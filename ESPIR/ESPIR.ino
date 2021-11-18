#include <WiFi.h>
#include <IRLibSendBase.h>
#include <IRLib_HashRaw.h>

IRsendRaw mySender;

uint16_t on[18] = {
  3022, 1110, 662, 1586, 1474, 762, 1474, 762,
  1474, 766, 662, 1582, 1474, 766, 662, 1582,
  1474, 1000
};

uint16_t up[18] = {
  3018, 1110, 662, 1586, 1474, 762, 662, 1586,
  662, 1586, 662, 1582, 666, 1582, 662, 1586,
  1474, 1000
};

uint16_t right[18] = {
  3018, 1110, 662, 1582, 1478, 762, 662, 1582,
  666, 1582, 662, 1586, 1474, 762, 1474, 762,
  1478, 1000
};


uint16_t down[18] = {
  3018, 1110, 662, 1586, 1474, 762, 662, 1566,
  682, 1586, 662, 1586, 662, 1582, 1478, 762,
  1474, 1000
};

uint16_t left[18] = {
  3018, 1110, 662, 1586, 1478, 758, 666, 1582,
  662, 1586, 662, 1586, 1474, 762, 662, 1586,
  1474, 1000
};

uint16_t recharge[54] = {
  3014, 1114, 662, 1582, 1478, 762, 662, 1582,
  1474, 766, 662, 1582, 662, 1586, 1474, 762,
  1478, 5742, 3022, 1110, 662, 1562, 1498, 762,
  662, 1586, 1474, 762, 662, 1586, 662, 1582,
  1478, 762, 1470, 5746, 3022, 1110, 662, 1586,
  1474, 762, 662, 1586, 1474, 762, 662, 1586,
  662, 1582, 1474, 762, 1478, 1000
};

uint16_t mode[54] = {
  2994, 1110, 666, 1582, 1478, 762, 658, 1586,
  662, 1586, 1474, 762, 662, 1586, 1474, 762,
  1474, 1390, 2998, 1110, 662, 1586, 1470, 766,
  662, 1586, 658, 1586, 1474, 766, 662, 1582,
  1474, 766, 1474, 1390, 2994, 1110, 662, 1586,
  1474, 762, 662, 1586, 662, 1582, 1478, 762,
  662, 1586, 1474, 762, 1474, 1000
};

uint16_t super[54] = {
  3022, 1110, 666, 1582, 1474, 762, 662, 1586,
  662, 1586, 1474, 762, 666, 1582, 1474, 762,
  662, 6574, 3018, 1110, 662, 1582, 1478, 762,
  662, 1586, 662, 1582, 1474, 766, 658, 1586,
  1478, 762, 662, 6570, 3018, 1110, 662, 1586,
  1474, 762, 662, 1586, 658, 1586, 1474, 766,
  662, 1582, 1474, 766, 662, 1000
};

const char* ssid = "iPhone de Willian";
const char* password = "willian123";
WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectada.");
  Serial.println("Endereço de IP: ");
  Serial.println(WiFi.localIP());

  server.begin();

  Serial.println(F("Pressione o comando desejado"));
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 2 on.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 2 off.<br>");
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
        if (currentLine.endsWith("GET /ligar")) {
          Serial.println("Liga");
          //   digitalWrite(LED, HIGH);
        }
        if (currentLine.endsWith("GET /L")) {
          //  digitalWrite(LED, LOW);
        }
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");

    int result = Serial.parseInt();
    switch (result) {
      case 1:
        mySender.send(on, 18, 36);
        break;
      case 2:
        mySender.send(up, 18, 36);
        break;
      case 3:
        mySender.send(right, 18, 36);
        break;
      case 4:
        mySender.send(down, 18, 36);
        break;
      case 5:
        mySender.send(left, 18, 36);
        break;
      case 6:
        mySender.send(recharge, 54, 36);
        break;
      case 7:
        mySender.send(mode, 54, 36);
        break;
      case 8:
        mySender.send(super,  54, 36);
        break;
    }
  }
}
