#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4;
String password = "123";
String input = "EEE";
static int i = 0;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  if (customKey){
    Serial.println(customKey);
    if (customKey == '*'){
      Serial.println("entrou no *");
      Serial.println(password);
      Serial.println(customKey);
      Serial.println(input);
      Serial.println(input==password);
      if (input.equals(password)){
        Serial.println(input);
        digitalWrite(13, HIGH);  
        delay(5000);
        digitalWrite(13, LOW); 
      }
      i=-1;
      input[0] = 'E';
      input[1] = 'E';
      input[2] = 'E';
    }
    input[i%3]= customKey;
    i++;
  }
}
