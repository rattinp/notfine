#include <FastLED.h>
// How many leds in your strip?
#define NUM_LEDS 1
#define DATA_PIN 4
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

#include <TinyGPS++.h>
#include <SoftwareSerial.h>
static const int RXPin = 2, TXPin = 3;
static const uint32_t GPSBaud = 9600;
// The TinyGPS++ object
TinyGPSPlus gps;
// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);
// For stats that happen every 5 seconds
unsigned long last = 0UL;

void setup()
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
 Serial.begin(115200);
 ss.begin(GPSBaud);
pinMode(4,OUTPUT);

}
void loop()
{
 // Dispatch incoming characters
 while (ss.available() > 0)
   gps.encode(ss.read());
 if (gps.location.isUpdated())
 {
   Serial.print(F("  Lat="));
   Serial.print(gps.location.lat(), 6);
   Serial.print(F(" Long="));
   Serial.println(gps.location.lng(), 6);
 }
 else if (millis() - last > 1000) // 5000
 {
   Serial.println();
   if (gps.location.isValid())
   {
     // replace 'Dest_LAT' and 'Dest_LON' values based on your location  
     // you can find Latitude and Longitude from Read_Lat_Lng.ino  
     // casita -31.388004393893635, -57.963952942329016
     //radar -31.368533106435464, -57.942892237179066
     // radar_exacto -31.368817, -57.942755
   // static const double Dest_LAT = 18.786254, Dest_LON = 73.880798; //londres
  //  static const double Dest_LAT = -31.388004, Dest_LON = -57.963952; //casita
 //    static const double Dest_LAT = -31.368533, Dest_LON = -57.942892; //radar
     static const double Dest_LAT = -31.368817, Dest_LON = -57.942755; //radar_exacto
    
     double distanceToDest =
       TinyGPSPlus::distanceBetween(
         gps.location.lat(),
         gps.location.lng(),
         Dest_LAT, 
         Dest_LON);
     Serial.print(F("Distance to Destination ="));
     Serial.print(distanceToDest/1000, 6);       // *Prints distance to destination 
double   distance_simplified = distanceToDest/1000;
     if(distance_simplified < 0.5000000)   //Here when distanceToDest/1000 is less than  0.050000  LED turns on . So change *distance to destination as per your requirement. 
     {
              if(distance_simplified < 0.10000000){

                leds[0] = CRGB::Red;
                FastLED.show();
                delay(300);
                leds[0] = CRGB::Black;
                FastLED.show();
                delay(200);
                           }else
                                {
                leds[0] = CRGB::Yellow;
                FastLED.show();
                delay(200);
                leds[0] = CRGB::Black;
                FastLED.show();
                delay(200);
                              }
     }
     else
     {
  leds[0] = CRGB::Blue;
  FastLED.show();
  delay(200);
     }
   }
   if (gps.charsProcessed() < 10)
     Serial.println(F("WARNING: No GPS data.  Check wiring."));
   last = millis();
   Serial.println();
 }
}
