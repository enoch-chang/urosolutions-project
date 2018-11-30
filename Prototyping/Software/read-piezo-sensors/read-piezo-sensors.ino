#define PIEZOELECTRIC_SENSOR_1 A0
#define PIEZOELECTRIC_SENSOR_2 A1
#define BIT_DEPTH 1023
#define MAX_VOLTAGE 5

float sensor_1 = 0;
float sensor_2 = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(PIEZOELECTRIC_SENSOR_1, INPUT);
  pinMode(PIEZOELECTRIC_SENSOR_2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

    sensor_1 = read_sensor(PIEZOELECTRIC_SENSOR_1);
    sensor_2 = read_sensor(PIEZOELECTRIC_SENSOR_2);
    Serial.print("Sensor 1: ");
    Serial.print(sensor_1);
    Serial.print("\n");

    Serial.print("Sensor 2: ");
    Serial.print(sensor_2);
    Serial.print("\n");
}

float read_sensor(int pin){
    unsigned int sensorValue = analogRead(pin); //read the A0 pin value
    float voltage = sensorValue * (MAX_VOLTAGE / BIT_DEPTH); //convert the value to a true voltage. 
    return voltage;
  }
