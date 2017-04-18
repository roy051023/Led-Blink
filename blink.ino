//define
char mode = 0;
int interval = 0;
int led = 13;


//setup
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Please select the flash rate by the number:");
  Serial.println("1. Flash rate is 2 sec.");
  Serial.println("2. Flash rate is 1 sec.");
  Serial.println("3. Flash rate is 0.5 sec.");
}


//loop
void loop() {
  if(Serial.available()){
    mode = Serial.read();
    delta();
  }
  flash();
}

void delta(){
  switch (mode) {
      case '1':
        interval = 2000;
        break;
      case '2':
        interval = 1000;
        break;
      case '3':
        interval = 500;
        break;
      default:
        break;
  }
}

void flash(){
  digitalWrite(led, HIGH);
  delay(interval);
  digitalWrite(led, LOW);
  delay(interval);
}
