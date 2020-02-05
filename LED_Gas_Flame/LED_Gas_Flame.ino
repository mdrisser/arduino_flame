int led1 = 3;
int led2 = 5;
int led3 = 6;
int led4 = 9;
int led5 = 10;

void fade(int increment, int wait) {
  for(int fadeValue = 255; fadeValue >= 0; fadeValue -= increment) {
    analogWrite(led2, fadeValue);

    if(fadeValue > 150) {
      analogWrite(led1, fadeValue);
    }

    if(fadeValue > 100) {
      analogWrite(led3, fadeValue - 60);
    }

    if(fadeValue > 55) {
      analogWrite(led4, fadeValue - 80);
    }

    if(fadeValue > 20) {
      analogWrite(led4, fadeValue - 100);
    }
    
    delay(wait);
  }

  for(int fadeValue = 255; fadeValue >= 0; fadeValue += increment) {
    analogWrite(led2, fadeValue);

    if(fadeValue > 150) {
      analogWrite(led1, fadeValue);
    }

    if(fadeValue > 100) {
      analogWrite(led3, fadeValue - 60);
    }

    if(fadeValue > 55) {
      analogWrite(led4, fadeValue - 80);
    }

    if(fadeValue > 20) {
      analogWrite(led4, fadeValue - 100);
    }
    
    delay(wait);
  }
}

void setup() {
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
   pinMode(led5, OUTPUT);
}

void loop() {
  fade(3,10);
}