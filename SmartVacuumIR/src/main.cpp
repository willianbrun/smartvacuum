#include <Arduino.h>
#include <WiFi.h>
#include <IRLibSendBase.h>
#include <IRLib_HashRaw.h>

IRsendRaw mySender;

uint16_t power[18] = {
    3022, 1110, 662, 1586, 1474, 762, 1474, 762,
    1474, 766, 662, 1582, 1474, 766, 662, 1582,
    1474, 1000};

uint16_t up[18] = {
    3018, 1110, 662, 1586, 1474, 762, 662, 1586,
    662, 1586, 662, 1582, 666, 1582, 662, 1586,
    1474, 1000};

uint16_t right[18] = {
    3018, 1110, 662, 1582, 1478, 762, 662, 1582,
    666, 1582, 662, 1586, 1474, 762, 1474, 762,
    1478, 1000};

uint16_t down[18] = {
    3018, 1110, 662, 1586, 1474, 762, 662, 1566,
    682, 1586, 662, 1586, 662, 1582, 1478, 762,
    1474, 1000};

uint16_t left[18] = {
    3018, 1110, 662, 1586, 1478, 758, 666, 1582,
    662, 1586, 662, 1586, 1474, 762, 662, 1586,
    1474, 1000};

uint16_t recharge[54] = {
    3014, 1114, 662, 1582, 1478, 762, 662, 1582,
    1474, 766, 662, 1582, 662, 1586, 1474, 762,
    1478, 5742, 3022, 1110, 662, 1562, 1498, 762,
    662, 1586, 1474, 762, 662, 1586, 662, 1582,
    1478, 762, 1470, 5746, 3022, 1110, 662, 1586,
    1474, 762, 662, 1586, 1474, 762, 662, 1586,
    662, 1582, 1474, 762, 1478, 1000};

uint16_t mode[54] = {
    2994, 1110, 666, 1582, 1478, 762, 658, 1586,
    662, 1586, 1474, 762, 662, 1586, 1474, 762,
    1474, 1390, 2998, 1110, 662, 1586, 1470, 766,
    662, 1586, 658, 1586, 1474, 766, 662, 1582,
    1474, 766, 1474, 1390, 2994, 1110, 662, 1586,
    1474, 762, 662, 1586, 662, 1582, 1478, 762,
    662, 1586, 1474, 762, 1474, 1000};

uint16_t super[54] = {
    3022, 1110, 666, 1582, 1474, 762, 662, 1586,
    662, 1586, 1474, 762, 666, 1582, 1474, 762,
    662, 6574, 3018, 1110, 662, 1582, 1478, 762,
    662, 1586, 662, 1582, 1474, 766, 658, 1586,
    1478, 762, 662, 6570, 3018, 1110, 662, 1586,
    1474, 762, 662, 1586, 658, 1586, 1474, 766,
    662, 1582, 1474, 766, 662, 1000};

const char *ssid = "iPhone de Willian";
const char *password = "willian123";
WiFiServer server(80);

void setup()
{
  Serial.begin(115200);

  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
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

void loop()
{
  WiFiClient client = server.available();
  if (client)
  {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        Serial.write(c);
        if (c == '\n')
        {
          if (currentLine.length() == 0)
          {
            client.println("HTTP/1.1 200 Success");
            client.println("Content-type:text/html");
            client.println();
            client.print("SUCCESS");
            client.println();
            break;
          }
          else
          {
            currentLine = "";
          }
        }
        else if (c != '\r')
        {
          currentLine += c;
        }
        if (currentLine.endsWith("GET /p"))
        {
          Serial.println("Power");
          mySender.send(power, 18, 36);
        }
        if (currentLine.endsWith("GET /u"))
        {
          Serial.println("Up");
          mySender.send(up, 18, 36);
        }
        if (currentLine.endsWith("GET /r"))
        {
          Serial.println("Right");
          mySender.send(right, 18, 36);
        }
        if (currentLine.endsWith("GET /down"))
        {
          Serial.println("Down");
          mySender.send(down, 18, 36);
        }
        if (currentLine.endsWith("GET /left"))
        {
          Serial.println("Left");
          mySender.send(left, 18, 36);
        }
        if (currentLine.endsWith("GET /recharge"))
        {
          Serial.println("Recharge");
          mySender.send(recharge, 18, 36);
        }
        if (currentLine.endsWith("GET /mode"))
        {
          Serial.println("Mode");
          mySender.send(mode, 18, 36);
        }
        if (currentLine.endsWith("GET /super"))
        {
          Serial.println("Super");
          mySender.send(super, 18, 36);
        }
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }
}