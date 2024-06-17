#define M1 10
#define M2 11
#define M3 12
#define M4 13
#define echo 4
#define trig 2
#define buzzer 7
#define IR 5

void printvalues(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  long t= pulseIn(echo,HIGH);
  long inches=t/74/2;
  long cm =t/29/2;

  int IR_OUTPUT;
  IR_OUTPUT=digitalRead(IR);

  Serial.print(inches);
  Serial.print("in \t");
  Serial.print(cm);
  Serial.print("cm\t");
  Serial.print("IR output ");
  Serial.print(IR_OUTPUT);
  Serial.print("\n");
  delay(100);
}

void Motor(int a) {
  int pin;
  switch (a) {
    case 1: pin = M1; break;
    case 2: pin = M2; break;
    case 3: pin = M3; break;
    case 4: pin = M4; break;
    default: return;  // Exit if invalid motor number is given
  }
  digitalWrite(pin, LOW);
  delay(2000);
  digitalWrite(pin, HIGH);
  delay(1000);
}

int ultrasonic(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  long t= pulseIn(echo,HIGH);
  long inches=t/74/2;
  long cm =t/29/2;

  return(cm);
}



void buzz(int f,int t){
  tone(7,f,t);
}


int IR_F(){
  int IR_OUTPUT;
  IR_OUTPUT=digitalRead(IR);
  if(IR_OUTPUT==0){
    return 1;
  }
  else{
    return 0;
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(IR,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:s
 digitalWrite(M1,HIGH);
 digitalWrite(M2,HIGH);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,HIGH);
  printvalues();
int ultrasonicvalue=ultrasonic(),irvalue=IR_F();

  if(ultrasonicvalue<10 && irvalue==1){
    Motor(1);
  }
  else{
    buzz(1535,100);
  }
    
  
}
