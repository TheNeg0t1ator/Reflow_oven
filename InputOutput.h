
void initializeInput(int but_1,int but_2, int but_3, int but_4, int SSR, int buzzer, int Thermistor_PIN){

  pinMode(SSR, OUTPUT);
  digitalWrite(SSR, LOW);        //Make sure we start with the SSR OFF (is off with HIGH)
  pinMode(buzzer, OUTPUT); 
  digitalWrite(buzzer, LOW);  
  pinMode(but_1, INPUT_PULLUP);
  pinMode(but_2, INPUT_PULLUP);
  pinMode(but_3, INPUT_PULLUP);
  pinMode(but_4, INPUT_PULLUP);
  pinMode(Thermistor_PIN, INPUT);
}





bool CheckInput(int pin,int *lastButtonStateFalling){
  bool Outputbool;
  int buttonStateFalling = 1;
  
  buttonStateFalling = (digitalRead(pin));
  if ((buttonStateFalling == LOW) && (*lastButtonStateFalling == HIGH)) {
     Outputbool = true; 
  }else{
     Outputbool = false; 
  }
  *lastButtonStateFalling = buttonStateFalling;
  return Outputbool;
}


