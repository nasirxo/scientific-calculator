                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
#include <LiquidCrystal_I2C.h>
#include "tinyexpr.h"
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys [ROWS] [COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
  {
    pinMode(10,INPUT_PULLUP);
    pinMode(13,INPUT);
    Serial.begin(115200);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(3, 0);
    lcd.print("N-Calculator");
    lcd.setCursor(3, 1);   
    lcd.print("By : Nasir");
    delay(1000);
    lcd.clear();
  }

String x = "";
String N = "";
void loop(){
//main:
   //Serial.println();
   char key = myKeypad.getKey();
   //int B = digitalRead(10);
        if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0')) {
        if(digitalRead(13)==0){
          lcd.clear();
          lcd.setCursor(0, 0);
          x=x+key;
          N=N+key;
          lcd.setCursor(0, 1);
          lcd.print(x);
        }
        else{
            if(key == '1'){x=x+"(";lcd.print("(");}
            else if(key == '2'){x=x+")";lcd.print(")");}
            else if(key == '3'){x=x+"^";lcd.print("^");}
            else if(key == '4'){x=x+",";lcd.print(",");}
            else if(key == '5'){x=x+".";lcd.print(".");}
            else if(key == '6'){x=x+"fac ";lcd.print("fac");}
            else if(key == '7'){x=x+"log ";lcd.print("log");}
            else if(key == '8'){x=x+"ln ";lcd.print("ln");}
            else if(key == '9'){x=x+"pi";lcd.print("pi");}
            else if(key == '0'){x=x+"e";lcd.print("e");}
            
            }    
         
        }
        else if (key != NO_KEY && (key =='=')) {
          Serial.print(x);
          lcd.setCursor(0, 0);
          lcd.print("INPUTING ...");
          lcd.setCursor(0, 1);
          lcd.print(x);delay(300);lcd.clear();
          x = "";
        } 
         else if (key != NO_KEY && (key =='C')) {
          if(digitalRead(13)==0){
          lcd.setCursor(0, 0);
          lcd.print(F("CLEARING ..."));
          delay(200);lcd.clear();x="";N="";
          }
          else{
            //Serial.print(digitalRead(13));
            //MATHS
            if(N.toInt() == 1){x="";x=x+"ncr";lcd.clear();lcd.print(x);N="";}
            else if(N.toInt() == 2){x="";x=x+"npr";lcd.clear();lcd.print(x);N="";}

            //PHYSICS
            else if(N.toInt() == 11){x="";x=x+"c";lcd.clear();lcd.print(x);N="";}
            else if(N.toInt() == 12){x="";x=x+"h";lcd.clear();lcd.print(x);N="";}
            else if(N.toInt() == 13){x="";x=x+"k";lcd.clear();lcd.print(x);N="";} 
            else if(N.toInt() == 14){x="";x=x+"me";lcd.clear();lcd.print(x);N="";}
            else if(N.toInt() == 15){x="";x=x+"mp";lcd.clear();lcd.print(x);N="";}
            else if(N.toInt() == 16){x="";x=x+"mn";lcd.clear();lcd.print(x);N="";} 
            else if(N.toInt() == 17){x="";x=x+"force";lcd.clear();lcd.print(x);N="";}                                                  
            else if(N.toInt() == 18){x="";x=x+"work";lcd.clear();lcd.print(x);N="";}
            else if(N.toInt() == 19){x="";x=x+"cforce";lcd.clear();lcd.print(x);N="";} 
            else if(N.toInt() == 20){x="";x=x+"eforce";lcd.clear();lcd.print(x);N="";}
            else if(N.toInt() == 21){x="";x=x+"charge";lcd.clear();lcd.print(x);N="";}
            else if(N.toInt() == 22){x="";x=x+"efield";lcd.clear();lcd.print(x);N="";} 
            else if(N.toInt() == 23){x="";x=x+"voltage";lcd.clear();lcd.print(x);N="";}
            else if(N.toInt() == 24){x="";x=x+"current";lcd.clear();lcd.print(x);N="";}
            else if(N.toInt() == 25){x="";x=x+"resistance";lcd.clear();lcd.print(x);N="";} 

           //ALPHABETS
          else if(N.toInt() == 65){x="";x=x+"A";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 66){x="";x=x+"B";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 67){x="";x=x+"C";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 68){x="";x=x+"D";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 69){x="";x=x+"E";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 70){x="";x=x+"F";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 71){x="";x=x+"G";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 72){x="";x=x+"H";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 73){x="";x=x+"I";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 74){x="";x=x+"J";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 75){x="";x=x+"K";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 76){x="";x=x+"L";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 77){x="";x=x+"M";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 78){x="";x=x+"N";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 79){x="";x=x+"O";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 80){x="";x=x+"P";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 81){x="";x=x+"Q";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 82){x="";x=x+"R";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 83){x="";x=x+"S";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 84){x="";x=x+"T";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 85){x="";x=x+"U";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 86){x="";x=x+"V";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 87){x="";x=x+"W";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 88){x="";x=x+"X";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 89){x="";x=x+"Y";lcd.clear();lcd.print(x);N="";}
          else if(N.toInt() == 90){x="";x=x+"Z";lcd.clear();lcd.print(x);N="";}
           
            }
        } 
         else if (key != NO_KEY && (key == '+' || key == '-' || key == '*' || key == '/')) {
          if(digitalRead(13)==0){
            lcd.setCursor(0, 1);
            x=x+key;
            lcd.print(x);   
          }
          else{
            if(key == '+'){x=x+"sin ";lcd.print("sin");}
            if(key == '-'){x=x+"cos ";lcd.print("cos");}
            if(key == '*'){x=x+"tan ";lcd.print("tan");}
            if(key == '/'){x=x+"sqrt ";lcd.print("sqrt");}
            }          
        }
         
        else if (key == NO_KEY && digitalRead(10)==LOW){
          float ans = te_interp(x.c_str(),0);
          lcd.setCursor(0, 0);lcd.print(ans);
          Serial.println(ans);
          delay(150);
         }
  
  }
