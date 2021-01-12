
String data; // String türünde data adında bir değişken tanımlıyoruz
int flag = 0;
const int buttonPin = 2; 
int buttonState = 0;  

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);                  
  Serial.begin(9600);
}

void loop() {

  while(Serial.available() > 0){
    int deneme = Serial.read();
    char ch = deneme;
    
    if(ch == 'a')
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

     if(ch == 'b')
      digitalWrite(LED_BUILTIN, LOW);   // turn the LED off (LOW is the voltage level)

     if(ch == 'c'){
      for(int i = 0 ; i < 3 ; i++){
        blink();
      }
     }

     if(ch == 'd'){
        int result;
        String samo;
        char temp[100];
        data = Serial.readString();
        result = data.toInt();
        result = result*result;
        
        samo = String(result);
        for(int i = 0 ; i < sizeof(samo)/ 2 ; i++){
          temp[i] = samo[i];
          Serial.write(temp[i]);
          //Serial.println(samo[i]);
        }
        //Serial.write(temp);
        //Serial.println(samo);
        
        
     }
     if(ch == 'e'){
       buttonState = digitalRead(buttonPin);
       int counter = 0;
         if (buttonState == HIGH) {
          counter++;
          Serial.println(counter);
          // turn LED on:
          //digitalWrite(ledPin, HIGH);
        } else {
          // turn LED off:
          //digitalWrite(ledPin, LOW);
  }
     }
      
  
  }
}

void blink()
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100); 
}
