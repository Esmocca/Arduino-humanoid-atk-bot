#include<Servo.h>
#define block_button 12
#define Atk_button 11
#define run_pin 10

Servo punggung;
Servo bahukanan;
Servo tangankanan;
Servo tangankiri;
Servo pinggang;
Servo kakikanan;
Servo kakikiri;

// Attack button

int button_press_count = 0;
int button_state = 0;
int prev_button_state = 0;

// Skill button

//int skill_press_count = 0;
//int skill_state = 0;
//int prev_skill_state = 0;

// Block button

int block_press_count = 0;
int block_state = 0;
int prev_block_state = 0;

// life displays

// Character stats :
int Atk = 200;
int Deffense = 800;

int runValue = 0;
int BlockldrPin = A2;
int KilledldrPin = A3;
int AttackledPin = 8;
long randnum;

void setup() {
  
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  pinMode (Atk_button, INPUT_PULLUP); 
 // pinMode (skill_pin, INPUT_PULLUP);
  pinMode (block_button,INPUT_PULLUP);
  pinMode (run_pin, INPUT);
  pinMode (AttackledPin, OUTPUT);
  pinMode (BlockldrPin, INPUT);
  pinMode (KilledldrPin, INPUT);
  punggung.attach(7);
  bahukanan.attach(6);
  tangankanan.attach(5);
  tangankiri.attach(4);
  pinggang.attach(3);

  bahukanan.write(90);
  tangankanan.write(120);
  tangankiri.write(80);
  punggung.write(160);
  tangankanan.write(120);
  tangankiri.write(80);
  pinggang.write(40);


  Serial.println("Start...");
}

void loop() {
// Blocking attack...
   block_state = digitalRead(block_button);
 if (block_state != prev_block_state) {
    if (block_state == HIGH) {
      digitalWrite(AttackledPin,LOW);
      // Servo blocking idle animation
      bahukanan.write(90);
      tangankanan.write(120);
      tangankiri.write(80);
      punggung.write(160);
      tangankanan.write(120);
      tangankiri.write(80);
      pinggang.write(40);
   

           
    } else { // Button press
      // Servo blocking animation
   Serial.println("blocking"); 
   bahukanan.write(150);
   tangankanan.write(120);
   tangankiri.write(60);
   delay(500);
   bahukanan.write(90);
   tangankanan.write(120);
   tangankiri.write(80);
   punggung.write(160);
   tangankanan.write(120);
   tangankiri.write(80);
   pinggang.write(40);
   int ldrStatus = analogRead(BlockldrPin);
  
  if(ldrStatus >=Deffense){
    Serial.print("Blockbreaks...");
    delay(10000);// delay for 10 seconds...
  }
  else{
    
  } 

    }
    delay(50);
  }
  prev_block_state = block_state;

  //skill_state = digitalRead(skill_pin);
 //if (skill_state != prev_skill_state) {
  //  if (skill_state == HIGH) {
  //    digitalWrite(ledPin,LOW);
  //    servo1.write(170);
  //    servo2.write(50);
  //    servo3.write(90);
  //    servo6.write(180);
      
      
      
   // } else { //button press
   
   //   digitalWrite(ledPin, HIGH);

   //   servo2.write(180);
   //   servo1.write(140);
   //   servo3.write(160);
   //   delay(300);
   //   servo1.write(140);
   //   servo2.write(30);
   //   servo3.write(60);
   //   delay(Atkspeed);
   //   delay(50);
      //

   //   servo1.write(140);
   //   servo2.write(30);
   //   servo3.write(60);
   //   delay(Atkspeed);
   //   servo1.write(140);
   //   servo2.write(160);
   //   servo3.write(160);
   //   delay(Atkspeed); 
   //   delay(50);
      
      //    
      
   //    servo6.write(60);
   //   servo2.write(180);
   //   servo1.write(140);
   //   servo3.write(160);

    //  delay(300);
    //  servo6.write(180);
    //  servo1.write(140);
    //  servo2.write(30);
    //  servo3.write(60);

    //  delay(Atkspeed);
    //  delay(50);
    //  digitalWrite(ledPin, LOW);  
    //     servo1.write(170);
    //  servo2.write(50);
    //  servo3.write(90);
    //  servo6.write(180);
      
     // delay(2000);
   // }
   // delay(50);
  //}
  //prev_skill_state = skill_state;
 
  //Tombol laari ditekan  
  runValue = digitalRead(run_pin);
    if(runValue != 0){
      // Servo running animation

    }
    else{
      // Servo running idle animmation

    }

  button_state = digitalRead(Atk_button);
  if (button_state != prev_button_state) {
    if (button_state == HIGH) {
      digitalWrite(AttackledPin,LOW);
      //Servo atatack idle animation
      bahukanan.write(90);
      tangankanan.write(120);
      tangankiri.write(80);
      punggung.write(160);
      tangankanan.write(120);
      tangankiri.write(80);
      pinggang.write(40);
   
    } else { //button press
      randnum  = random(2);
      Serial.println("Attacking");
      Serial.println(randnum);

      if(randnum == 0){
      delay(200);
      digitalWrite(AttackledPin, HIGH);
      // Servo animation 1
      
      pinggang.write(100);
      punggung.write(100);
      bahukanan.write(120);
      tangankanan.write(30);
      delay(500);
      tangankanan.write(120);
      pinggang.write(40);
      punggung.write(160);
      digitalWrite(AttackledPin, LOW);
      }
      if(randnum == 1){
      delay(200);
      digitalWrite(AttackledPin, HIGH);
       // Servo animation 2

       pinggang.write(100);
       punggung.write(100);
       bahukanan.write(120);
       tangankanan.write(30);
       delay(500);
       tangankanan.write(120);
       pinggang.write(40);
       punggung.write(160);
      digitalWrite(AttackledPin, LOW);
      }  
      
    }
    delay(100);
  }
  prev_button_state = button_state;

   int ldrStatus = analogRead(KilledldrPin);
  
  if(ldrStatus >=800){
    Serial.print("You Dead");
    delay(9999999);
  }
  else{
    
  }
} 
