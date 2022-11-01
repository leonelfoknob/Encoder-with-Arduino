 #define bt 5 //SW
 #define outputA 6 //---> CLK
 #define outputB 7 //--->DT
 
 

 int counter = 0; 
 int aState;
 int aLastState;
 int bt_state;
 int bt_val;

 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   pinMode (bt,INPUT_PULLUP);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);
 } 

 void loop() {
  bt_val = digitalRead(bt); 
   aState = digitalRead(outputA);
   if (aState != aLastState){     
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
   }
   aLastState = aState;
   delay(500);
 }
