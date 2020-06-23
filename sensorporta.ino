int trig = 7; 
int echo = 6; 
long dist, cm;
int stPorta = 0;

 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(5, OUTPUT); //led vm
  pinMode(4, OUTPUT); //led am
  pinMode(3, OUTPUT); //led vd
  
  pinMode(2, OUTPUT); //buzzer
  pinMode(1, OUTPUT); //relay
}
 
void loop() {

  aguardando();
  lerDistancia();
  // digitalWrite(3, LOW);

  if (stPorta == 0) {
      digitalWrite(5, HIGH);
      digitalWrite(3, LOW);
      } else {
      digitalWrite(5, LOW);
      digitalWrite(3, HIGH);
   }

  if ((cm < 20) && (stPorta == 0)) {
      abrePorta();
      }

    delay(3000);
  if ((cm > 20) && (stPorta == 1)) {
      fechaPorta();
    }
}


void aguardando() {
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  delay(100);
  }

void lerDistancia() {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  pinMode(echo, INPUT);
  dist = pulseIn(echo, HIGH);
  cm = (dist/2) / 29.1;   
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
}

void abrePorta(){
  if(cm < 20){
    stPorta = 1;
    digitalWrite(4, LOW);
    
    tone(2,261);
    delay(50); 
    noTone(2); 
  
    delay(10); 
  
    tone(2,293);
    delay(50); 
    noTone(2);
  
    delay(10); 
  
    tone(2,329);
    delay(50); 
    noTone(2);

    digitalWrite(3, HIGH);
    delay(150); 
    digitalWrite(3, LOW);

    delay(150); 
    
    digitalWrite(3, HIGH);
    delay(150); 
    digitalWrite(3, LOW);

    delay(150); 

    digitalWrite(3, HIGH);
    delay(150); 
    digitalWrite(3, LOW);

    digitalWrite(4, LOW);

    } else {
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
    }
}

void fechaPorta(){
  if(cm > 20){
    stPorta = 0;
    digitalWrite(4, LOW);
    
    tone(2,329);
    delay(50); 
    noTone(2);
  
    delay(10); 
  
    tone(2,293);
    delay(50); 
    noTone(2);
  
    delay(10); 

    tone(2,261);
    delay(50); 
    noTone(2); 


    digitalWrite(5, HIGH);
    delay(150); 
    digitalWrite(5, LOW);

    delay(150); 
    
    digitalWrite(5, HIGH);
    delay(150); 
    digitalWrite(5, LOW);

    delay(150); 

    digitalWrite(5, HIGH);
    delay(150); 
    digitalWrite(5, LOW);
    
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    
    } else {
      digitalWrite(5, LOW);
      digitalWrite(4, HIGH);
    }

}
