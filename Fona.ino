//Fona 808 
void StartFona() {
  fonaSS.begin(4800);
  if (!fona.begin(fonaSS)) {        
    Serial.println(F("Couldn't find FONA"));
  }else {
  Serial.println(F("FONA is OK"));}
}

void SendSmsBPM() {
    if (digitalRead(6) == HIGH){
     if (!fona.callPhone("599038320")) {
        Serial.println(F("Failed"));
      } else {
        Serial.println(F("Sent!"));
      }
    }
}

