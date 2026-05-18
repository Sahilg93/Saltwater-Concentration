int activePin = 0;

//defines the leds
#define led1 8 
#define led2 9
#define led3 10

float activeVoltage;
float concentration;

void setup(void) {
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop(void) {
  activeVoltage = analogRead(activePin);

  float activeVoltageValue = (activeVoltage / 1023.0) * 5.0 * 1000;
  
  Serial.print("Active: ");
  Serial.println(activeVoltageValue);

  concentration = 4307.17 * log(activeVoltageValue) -214.041;
  Serial.println("Salt Concentration: ");
  Serial.println(concentration);

  WritetoLED(concentration);
 
  delay(2000);
}

void WritetoLED(float concentration) {
  if (concentration < 2320) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else if (concentration >= 1571 && concentration <= 3706) {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led3, LOW); 
  }  else if (concentration >= 2606 && concentration <= 4735) {
    digitalWrite(led3, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}
