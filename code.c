Program Code:
int soil_m = A0; // this pin is for connecting analog input for soil moisture sensor
int water_l = A1; // this pin is for connecting analog input for water level sensor
int relay = 13; // connect this pin for switch relay
int a; // variable for storing soil moisture value
int b; // variable for storing water level value
void setup()
{
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
  pinMode(soil_m, INPUT); // input should should be declared for pin for water sensor
  pinMode(water_l, INPUT); // input should be declared for pin for water level sensor
  pinMode(relay, OUTPUT); // output should be declared for pin for relay as it controls others        and act as an output device
}

void loop() {
    Serial.println("soil moisture:");
    a = digitalRead(soil_m); // storing soil moisture sensor
    delay(300);
    b = digitalRead(water_l); //stroing water level sensor
    delay(300);
    Serial.println("value of soil moisture sensor");
    Serial.println(a);
    delay(300);
    Serial.println("value of water level sensor");
    Serial.println(b);
    delay(500);
    if (a ==0) // threshold value for soil moisture sensor if the sensor here 0 means it detected water and 1 means it isn't
    {
      digitalWrite(relay, HIGH); //here high means relay is off its in sink mode
      Serial.println("MOTOR IS OFF");
      delay(2000);
    }
    if (a==1)
    {
      digitalWrite(relay,LOW);
      Serial.println("MOTOR IS ON");
      delay(2000);
    }
