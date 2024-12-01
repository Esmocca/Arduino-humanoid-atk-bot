// Sensor character v3
// Enabling Blocking system

#define heal_pin 8
#define block_pin 7

int damage;

// Character stats:

int hp = 20;
int deff = 300;
int atk = 300;

int ldrPin = A2;

//Heal button

int heal_press_count=0;
int heal_state =0;
int prev_heal_state =0;

// Block button

int block_press_count = 0;
int block_state = 0;
int prev_block_state = 0;

bool ldr_disabled = false;//ldr disable state

void setup()
{
  Serial.begin(9600);
  pinMode(ldrPin,INPUT);
  pinMode(heal_pin, INPUT_PULLUP);
  pinMode(block_pin, INPUT_PULLUP);
}
void HpState()
{
  // Sensors indicate health point 
  if(ldr_disabled)
  {
    return; // Skip ldr reading when disabled
  }
  // Read ldr value
  
  int ldrStatus = analogRead(ldrPin);
  if(ldrStatus >=deff){
    damage++;
  }
  else{
    
  }
  if(damage >= hp){
    Serial.print("You Dead");
    delay(9999999);
  }
}

void HealState()
{
  heal_state = digitalRead(heal_pin);
  if (heal_state != prev_heal_state)
  {
    if(heal_state == HIGH) {
      //idle 
    }else{
      //button pressed
      hp++;
      Serial.print("Healed! Current HP: ");
      Serial.println(hp);
    }
    delay(100);
  }
  prev_heal_state = heal_state;
}

void BlockState()
{
  block_state = digitalRead(block_pin);
 if (block_state != prev_block_state) {
    if (block_state == HIGH) {
      
      ldr_disabled = false; // Enable LDR
      Serial.println("Block inactive: LDR enabled");
    
     } else { // Button press
      
      ldr_disabled = true;
      Serial.println("Blocking : LDR disabled");
     }
     delay(100);
 }
     prev_block_state = block_state;
}

void loop() {
  HpState();
  HealState();
  BlockState();


  
}
