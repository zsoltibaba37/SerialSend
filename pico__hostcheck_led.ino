/*
    With Raspberry Pi pico
*/


#define IP1 10
#define IP2 12
#define IP3 14


void setup() {
  Serial.begin(9600);
  pinMode(IP1, OUTPUT);
  pinMode(IP2, OUTPUT);
  pinMode(IP3, OUTPUT);
}

void loop() {
  // Wait for incoming data
  while (Serial.available() == 0){}

  String inData = Serial.readString();
  inData.trim();

  char one = '1';
  char nul = '0';
  
  char a = inData[0];
  if( a == one ){digitalWrite(IP1, HIGH);} else if ( a == nul ){digitalWrite(IP1, LOW);}

  char b = inData[1];
  if( b == one ){digitalWrite(IP2, HIGH);} else if ( b == nul ){digitalWrite(IP2, LOW);}
  
  char c = inData[2];
  if( c == one ){digitalWrite(IP3, HIGH);} else if ( c == nul ){digitalWrite(IP3, LOW);}  

}
