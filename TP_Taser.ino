#define taserPin 2
#define motorPin 3
#define buttonPin 4
#define shockTime 1
#define resetTime 120
#define motorSpeed 255

int clk = 0;    //Set reset timer to zero
int shock = 0;  //Set shock timer to zero

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(taserPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  if(digitalRead(buttonPin) == LOW && shock >= shockTime){ // Shock if shock time has passed and button is pushed
    digitalWrite(taserPin, HIGH);
  }
  else{
    digitalWrite(taserPin, LOW);
  }
  if(digitalRead(buttonPin) == LOW){  // While the button is pushed
    analogWrite(motorPin, motorSpeed); // Start the motor
    delay(1000);                // Wait one second
    shock++;                    // Increment the shock timer
    clk++;                      // Increment the reset timer
  }
  else{                               // While the button is open
    analogWrite(motorPin, 0);   // Stop the motor
    delay(1000);                // Wait one second
    clk++;                      // Increment the reset timer
  }
  if(clk >= resetTime){         // Reset the clocks if time has passed
    clk = 0;
    shock = 0;
  }
  //LED Case Statement
}
