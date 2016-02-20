#include <SoftwareSerial.h>
#include "Adafruit_FONA.h"

#define FONA_RX 1
#define FONA_TX 9
#define FONA_RST 0

SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);

Adafruit_FONA fona = Adafruit_FONA(FONA_RST);



//  Variables
int pulsePin = 10;                 // Pulse Sensor purple wire connected to analog pin 0


// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

static boolean serialVisual = true; 

void setup(){
  Serial.begin(115200);             // we agree to talk fast!
  StartFona();                      // Start Fona
                               // sets up to read Pulse Sensor signal every 2mS 
}

void loop(){ 
  interruptSetup();
   SendSmsBPM();
    serialOutput() ;    
    if (QS == true){     // A Heartbeat Was Found  
        serialOutputWhenBeatHappens();   // A Beat Happened, Output that to serial.     
        QS = false;                      // reset the Quantified Self flag for next time    
    }
  delay(20);                             //  take a break
}






