//#include <SoftwareSerial.h>

//SoftwareSerial mySerial(2,3);
 
void setup() 
{
  Serial.begin(9600);
  //mySerial.begin(9600);
  
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  pinMode(A2, INPUT);
  pinMode(A4, INPUT);

}
float v1 = 0.0 , v2 = 0.0 ;
float r1 = 396 , r2 = 385;
void loop() 
{  
  float i1 = 0.0 , i2 = 0.0;
  float p1 = 0.0 , p2 = 0.0;
  // Grid 
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);

  v1 = 0.0 , v2 = 0.0 ;
  for(int k = 0 ; k < 50; k++)
  {
    v1 += (analogRead(A2)* 5.0) / 1024.0 , v2 += (analogRead(A4)* 5.0) / 1024.0;
    delay(2);
  }
  v1/=50.00 , v2/=50.00;
  i1 = v1/r1 , i2 = v2/r2;
  p1 = v1*v1/r1; p2 = v2*v2/r2; 

  
    Serial.println("grid,"+String(v1)+","+String(i1)+","+String(p1));
    delay(5000);
    Serial.println("roller,"+String(v2)+","+String(i2)+","+String(p2));
    delay(5000);
  // Roller
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  
  v1 = 0.0 , v2 = 0.0 ;
  for(int k = 0 ; k < 50; k++)
  {
    v1 += (analogRead(A2)* 5.0) / 1024.0 , v2 += (analogRead(A4)* 5.0) / 1024.0;
    delay(2);
  }
  v1/=50.00 , v2/=50.00;
  i1 = v1/r1 , i2 = v2/r2;
  p1 = v1*v1/r1; p2 = v2*v2/r2;
   
  
    Serial.println("grid,"+String(v1)+","+String(i1)+","+String(p1));
    delay(5000);
    Serial.println("roller,"+String(v2)+","+String(i2)+","+String(p2));
    delay(5000);
  //
}
