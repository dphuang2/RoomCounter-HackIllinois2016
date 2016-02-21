/*
 * This code was implemented by Daniel Zhang (dzhang54), Dylan Huang (dphuang2) and Harsh Modhera (hmodhe2).
 * It was created/worked on the following days: Feb 19-21, 2016. It was for Hack Illinois 2016.
 * The purpose of this code is to read how much the flex sensor (and if the touch sensor was activated)
 * changes in order to determine if someone has entered a room or left the room.
 * The data is then pushed to a website server which anyone can view online from their web browser
 * or mobile phone.
 */


#include <Ethernet.h>
#include <SPI.h>


// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield.

byte mac[] = { 0x90, 0xb6, 0x86, 0x05, 0xc5, 0xdb };

// If you don't want to use DNS (and reduce your sketch size),
// use the numeric IP instead of the name for the server:

char server[] = "resumepipe.web.engr.illinois.edu";    // name address for our project website (using DNS).

// Set the static IP address to use if the DHCP fails to assign.

IPAddress ip(130,126,112,114);

// Set all pin variables.

int touchSensorPin = 4;
int flexSensorPin = A0;
int greenLEDPin = 8;
const int pinLED = 3;
String location = "ECEB";
String data;
int isTouchPressed = 0;

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):

EthernetClient client;

void setup()
{
      pinMode(touchSensorPin, INPUT);
      pinMode(pinLED, OUTPUT);
      pinMode(greenLEDPin, OUTPUT);
}

void loop()
{
      data = ""; // Initialize a blank string.
      isTouchPressed = 0; // Reset the touch sensor.
      int flexSensorReading = analogRead(flexSensorPin);

      /*
        Use this to debug touch sensor.
        If this is uncommented, decrement will not work.

        while(digitalRead(touchSensorPin)) {
            digitalWrite(greenLEDPin, HIGH);
        }
      */

      // POST Request activate if flex sensor reading is greather than 500.
//      Serial.println(flexSensorReading);
      if(flexSensorReading >= 300) {

            // If touch sensor pin is active and flex sensor reading is above 500, decrement or increment accordingly.

            if(digitalRead(touchSensorPin)) {
                isTouchPressed--;
                Serial.println("isTouchPressed decremented");
                delay(300);
            } else {
                isTouchPressed++;
                delay(300);
            }

            // Turns on the LED when sending POST Request.

            digitalWrite(pinLED, HIGH);

            // Open serial communications and wait for port to open.

            Serial.begin(9600);

            // Start the Ethernet connection.

            if (Ethernet.begin(mac) == 0) {
                Serial.println("Failed to configure Ethernet using DHCP");
                // Try to configure using IP address instead of DHCP.
                Ethernet.begin(mac, ip);
            }

            // Give the Ethernet shield a second to initialize.

            delay(1000);
            Serial.println("connecting...");

            // Sending data for the POST request to be read and updated onto server/website.

            data = "location=" + location + "&count=" + isTouchPressed;

            // If you get a connection, report back via serial.

            if (client.connect(server, 80)) {
                  Serial.println("connected");

                  // Make a HTTP request.

                  client.println("POST /assets/php/update.php HTTP/1.1");
                  client.println("Host: resumepipe.web.engr.illinois.edu"); //Website that the POST is being sent
                  client.println("Content-Type: application/x-www-form-urlencoded"); //Required line of code when sending data through POST requests
                  client.println("Connection: close"); //Below are all required when sending data with post request
                  client.print("Content-Length: ");
                  client.println(data.length());
                  client.println();
                  client.println(data);
            } else {
                  // If you didn't get a connection to the server...
                  Serial.println("connection failed");
            }

            // If there are incoming bytes available
            // from the server, read them and print them.

            if (client.available()) {
                char c = client.read();
                Serial.print(c);
            }

            client.stop();
      }

      // Turning off the pinLED.

      digitalWrite(greenLEDPin, LOW);
      digitalWrite(pinLED, LOW);
      delay(250);
}
