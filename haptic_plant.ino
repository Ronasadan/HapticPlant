const int motor1= 11;
const int motor2= 7;
const int motor3= 2;
//const int motor4= 2;

int pcPin1= A1;
int pcPin2= A3;
int pcPin3= A4;

int val1;
int val2;
int val3;

int amB1;
int amB2;
int amB3;

/*int soilval = 0;
int soilPin = A0;
int soilPower = 7;

*/
void setup() {
  Serial.begin(9600);
  pinMode(pcPin1, INPUT);
  pinMode(pcPin2, INPUT);
  pinMode(pcPin3, INPUT);   
 // pinMode(soilPin, INPUT);

  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
//  pinMode(motor4, OUTPUT);
        
/*  pinMode(soilPower, OUTPUT);
  digitalWrite(soilPower, LOW);
*/

amB1 = analogRead(pcPin1);
amB2 = analogRead(pcPin2);
amB3 = analogRead(pcPin3);

}

void loop() {

  val1 = analogRead(pcPin1);
  val2 = analogRead(pcPin2);
  val3 = analogRead(pcPin3);  


    if(amB1 - val1 >= 10)
      {digitalWrite(motor1, HIGH);
      }
    else
      {
        digitalWrite(motor1, LOW);
      delay(10);
      }
 
    if(amB2 - val2 >= 10)
      {digitalWrite(motor2, HIGH);
      }
    else
      {
        digitalWrite(motor2, LOW);
       delay (10);
      }
      
    if(amB3 - val3 >= 10)
      {digitalWrite(motor3, HIGH);
      }
    else
      {
        digitalWrite(motor3, LOW);
       delay (10);
      }
      

/*   soilval = analogRead(soilPin);
    if(soilval < 0 ) {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, HIGH);
      }

Serial.print("Moisture level: ");
Serial.println(soilval);
delay(50);
*/Serial.print("pc1: ");
Serial.println(val1);
delay(50);
Serial.print("pc2: ");
Serial.println(val2);
delay(50);
Serial.print("pc3: ");
Serial.println(val3);
delay(50);



}
