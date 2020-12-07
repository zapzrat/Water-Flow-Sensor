volatile int flow_frequency;
unsigned int l_hour, f_val;
unsigned long ctTime, flow_val, cloopTime;

const int ledStatus = 13 ;

void flowLogic() {
  l_hour = (flow_frequency * 60 / 7.5);
  flow_frequency = 0;
  Serial.print("Water Sensor : ");
  Serial.print(l_hour, DEC);
  Serial.print(" L/hour");
  Serial.println("");

  if (l_hour >= 10) {
    digitalWrite(ledStatus, HIGH);
  }
  else if (l_hour < 10) {
    digitalWrite(ledStatus, LOW);
  }

}

void flow () //  Water flow Interrupt function
{
  flow_frequency++;  f_val++;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Micro Project Thailand ~^.^~ ");
  attachInterrupt(0, flow, RISING);  sei();   ctTime = millis();  cloopTime = ctTime; // Water flow

  pinMode(ledStatus, OUTPUT);
}

void loop () {
  ctTime = millis();
  if (ctTime >= (cloopTime + 1000)) {
    cloopTime = ctTime;
    flowLogic();
  }
}
