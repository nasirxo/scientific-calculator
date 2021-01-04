#include <Adafruit_GFX.h> // Hardware-specific library
#include <MCUFRIEND_kbv.h>
#define BLACK   0x0000
#define RED     0xF800
#define GREEN   0x07E0
#define WHITE   0xFFFF
#define GREY    0x8410
MCUFRIEND_kbv tft;
unsigned long fact(int n){
unsigned long f=n;
while(n-->1){f*=n;}
return f;
}
void ntable(int n,int z){  
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  tft.setTextColor(GREEN);
  for(long x=1;x<=z;x++){
    char m[20];
    sprintf(m,"\n %ld x %ld = %ld",long(n),x,long(n*x));
    tft.println(m);
    }
  }
  
void ftable(int f,int n){
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  tft.setTextColor(GREEN);
  for(int x=f;x<=n;x++){
    char m[100];
    sprintf(m,"\n %d! = %ld",x,fact(x));
    tft.println(m);
    }
  }

void hextable(int f,int n){
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  tft.setTextColor(GREEN);
  for(int x=f;x<=n;x++){
    char m[100];
    sprintf(m,"\n %d = %X",x,x);
    tft.println(m);
    }
  }

  
void stable(int c,int n){
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  tft.setTextColor(GREEN);
  for(int x=c;x<=n;x++){
    char m[100];
    sprintf(m,"\n SUM(%d) = %d",x,(x*(x+1))/2);
    tft.println(m);
    }
  }

void sqtable(int c,int n){
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  tft.setTextColor(GREEN);
  for(int x=c;x<=n;x++){
    char m[100];char * f;
    sprintf(m,"\n sqrt(%d) = ",x);
    tft.print(m);tft.print(pow(x,0.5));
    }
  }

double Qsolve(double a,double b,double c,int mode){
  float d = (b*b)-4*a*c;
  if(mode>0){return (-b+sqrt(d))/(2*a);}
  else{return (-b-sqrt(d))/(2*a);}  
  }
  
double BMI(double weight, double height) {
   return weight/(height*2);
}


void menu(int n){
  int Y = 30;
  tft.fillScreen(GREEN);
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.setCursor(20, Y);//+20
  tft.println("1 : x TABLE");
  tft.setCursor(20, Y+20);
  tft.println("2 : + TABLE");
  tft.setCursor(20, Y+40);
  tft.println("3 : ! TABLE");
  tft.setCursor(20, Y+60);
  tft.println("4 : SQRT TABLE");
  tft.setCursor(20, Y+80);
  tft.println("5 : HEX TABLE");
  tft.setCursor(20, Y+100);
  tft.println("6 : Q-Solver");
  tft.setCursor(20, Y+120);
  tft.println("7 : Math-Solver");
  tft.setCursor(20, Y+140);
  tft.println("8 : Math-Farmulas");
  tft.setCursor(20, Y+160);
  tft.println("9 : Math Game");
  tft.setCursor(20, Y+180);
  tft.println("10 : BMI-Find");
  tft.setCursor(20, Y+200);
  tft.println("11 : UNIT-CONVERT");
  
  delay(n);
  }
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    //mySerial.begin(4800);
    randomSeed(analogRead(A0));
    tft.reset();
    uint16_t identifier = tft.readID();
    Serial.print("ID = 0x");
    Serial.println(identifier, HEX);
    if (identifier == 0xEFEF) identifier = 0x9486;
    tft.begin(identifier);
    tft.fillScreen(RED);
    tft.setCursor(40, 50);
    tft.setTextColor(GREEN);
    tft.setTextSize(4);
    tft.println("N-CALC");
    tft.setCursor(40, 100);
    tft.setTextSize(2);
    tft.println("BY : Nasir Ali");
    tft.setRotation(0);
   // tft.fillScreen(0x0000);
    delay(1000);
    menu(100);
}


void loop()
{
start:
int n = Serial.readString().toInt();
while(n){
tft.fillScreen(0x0000);
if(n==1){
  tft.setCursor(40, 130);
  tft.setTextColor(GREEN);
  tft.println(" ENTER NUMBER");
  while(true){
    int i = Serial.readString().toInt();
    if(i>1){
    tft.setCursor(40, 130);
    tft.setTextSize(4);
    tft.fillScreen(0x0000);
    tft.println(i);
    delay(1000);
    tft.fillScreen(0x0000);
   // tft.setCursor(0, 0);
    ntable(i,20);  
    }
    else if(Serial.readString()=='/'){
      break;break;
      }
  }
 }
else if(n==2){
  tft.setCursor(20, 20);tft.setTextColor(GREEN);tft.println(" SUMMATION-TABLE ");
  tft.setCursor(40, 130);tft.setTextColor(GREEN);  
  tft.println(" FROM ");
  while(true){
    int i = Serial.readString().toInt();
    if(i>1){
    tft.setCursor(40, 130);
    tft.setTextSize(4);
    tft.fillScreen(0x0000);
    tft.println(i);
    delay(500);
    tft.fillScreen(0x0000);
    tft.setCursor(40, 130);tft.setTextSize(2);
    tft.println(" TO ");
    while(true){  int z = Serial.readString().toInt();
    if(z>1){
    tft.fillScreen(0x0000);
    tft.setCursor(40, 130);tft.setTextSize(4);tft.println(z);delay(500);       
    tft.fillScreen(0x0000);
    stable(i,z);  
    break;
    }}}}}
else if(n==3){
  tft.setCursor(20, 20);tft.setTextColor(GREEN);tft.println(" FACTORIAL-TABLE ");
  tft.setCursor(40, 130);tft.setTextColor(GREEN);tft.println(" FROM ");
  while(true){
    int i = Serial.readString().toInt();
    if(i>1){
    tft.setCursor(40, 130);tft.setTextSize(4);    
    tft.fillScreen(0x0000);
    tft.println(i);
    delay(500);
    tft.fillScreen(0x0000);
    tft.setCursor(40, 130);tft.setTextSize(2);
    tft.println(" TO ");
    while(true){  int z = Serial.readString().toInt();
    if(z>1){
    tft.fillScreen(0x0000);
    tft.setCursor(40, 130);tft.setTextSize(4);tft.println(z);delay(500);       
    tft.fillScreen(0x0000);
    ftable(i,z);  
    break;
    }}}}}


else if(n==4){
  tft.setCursor(20, 20);tft.setTextColor(GREEN);tft.println(" SQRT-TABLE ");
  tft.setCursor(40, 130);tft.setTextColor(GREEN);tft.println(" FROM ");
  while(true){
    int i = Serial.readString().toInt();
    if(i>1){
    tft.setCursor(40, 130);tft.setTextSize(4);    
    tft.fillScreen(0x0000);
    tft.println(i);
    delay(500);
    tft.fillScreen(0x0000);
    tft.setCursor(40, 130);tft.setTextSize(2);
    tft.println(" TO ");
    while(true){  int z = Serial.readString().toInt();
    if(z>1){
    tft.fillScreen(0x0000);
    tft.setCursor(40, 130);tft.setTextSize(4);tft.println(z);delay(500);       
    tft.fillScreen(0x0000);
    sqtable(i,z);  
    break;
    }}}}}

else if(n==5){
  tft.setCursor(20, 20);tft.setTextColor(GREEN);tft.println(" HEX-TABLE ");
  tft.setCursor(40, 130);tft.setTextColor(GREEN);tft.println(" FROM ");
  while(true){
    int i = Serial.readString().toInt();
    if(i>1){
    tft.setCursor(40, 130);tft.setTextSize(4);    
    tft.fillScreen(0x0000);
    tft.println(i);
    delay(500);
    tft.fillScreen(0x0000);
    tft.setCursor(40, 130);tft.setTextSize(2);
    tft.println(" TO ");
    while(true){  int z = Serial.readString().toInt();
    if(z>1){
    tft.fillScreen(0x0000);
    tft.setCursor(40, 130);tft.setTextSize(4);tft.println(z);delay(500);       
    tft.fillScreen(0x0000);
    hextable(i,z);  
    break;
    }}}}}

else if(n==6){
  tft.setCursor(20, 20);tft.setTextColor(GREEN);tft.println(" Q-Solver ");
  tft.setCursor(40, 130);tft.setTextColor(GREEN);tft.println("ENTER A :");
  while(true){
    double a = Serial.readString().toInt();
    if(a!=0){
    tft.setCursor(40, 130);tft.setTextSize(4);    
    tft.fillScreen(0x0000);
    tft.println(a);
    delay(300);
    tft.fillScreen(0x0000);
    tft.setCursor(40, 130);tft.setTextSize(2);
    tft.println("ENTER B : ");
    while(true){  double b = Serial.readString().toInt();
    if(b!=0){
    tft.fillScreen(0x0000);
    tft.setCursor(40, 130);tft.setTextSize(4);tft.println(b);delay(300);       
    tft.fillScreen(0x0000);
    tft.setCursor(40, 130);tft.setTextSize(2);
    tft.println("ENTER C : ");
    while(true){  double c = Serial.readString().toInt();
    if(c!=0){
    tft.fillScreen(0x0000);
    tft.setCursor(40, 130);tft.setTextSize(4);tft.println(c);delay(300);       
    tft.fillScreen(0x0000);
    tft.setCursor(20, 50);tft.setTextSize(2);tft.print("ROOT 1 : ");tft.print(Qsolve(a,b,c,1));
    tft.setCursor(20, 70);tft.setTextSize(2);tft.print("ROOT 2 : ");tft.print(Qsolve(a,b,c,-1));
    break;
       }
    }}}}}}

else if(n==7){
  tft.setCursor(20, 20);tft.setTextColor(GREEN);tft.println(" MATH-SOLVER ");
  tft.setCursor(20, 40);tft.setTextColor(GREEN);tft.println("ENTER QUESTION ..");
  while(true){
    String cmd = Serial.readString();
    if(cmd.length()>2){
    //tft.setCursor(20, 70);tft.setTextSize(2);    
    // tft.fillScreen(0x0000);
    //tft.print(cmd);
    delay(100);
    tft.fillScreen(0x0000);
    tft.setCursor(40, 100);tft.setTextSize(2);tft.println(" ANSWER ");
    tft.setCursor(50, 130);tft.setTextSize(2);tft.println(cmd.c_str());
    }}}

else if(n==8){
  tft.setCursor(20, 10);tft.setTextColor(GREEN);tft.println(" MATH-FARMULAS ");
  tft.setCursor(0, 30); tft.setTextSize(1);
  tft.print("\n(a+b)2=a2+2ab+b2\n(a-b)2=a2-2ab+b2\n(a+b)3=a3+b3+3ab(a+b)\n(a-b)3=a3-b3-3ab(a-b)\n(a+b+c)2=a2+b2+c2+2ab+2bc+2ca\n(a+b+c)3=a3+b3+c3+3a2b+3a2c+3b2c+3b2a+3c2a+3c2a+6abc\na2-b2=(a+b)(a-b)\na3-b3=(a-b)(a2+ab+b2)\na3+b3=(a+b)(a2-ab+b2)\n(a+b)2+(a-b)2=4ab\n(a+b)2-(a-b)2=2(a2+b2)\nIfa+b+c=0,thena3+b3+c3=3abc\n");
  
  while(true){
    String cmd = Serial.readString();
    }
  }
else if(n==9){
  bool win=true;
  int score = 0,level=1,GT[10]={10,20,30,40,50,60,70,80,90,100};
  int q1=random(1,10),q2=random(1,10);
  char QT[20];
  
  while (win==true){
    tft.setTextSize(2);
    tft.setCursor(40, 10);tft.setTextColor(GREEN);tft.print(" SCORE : ");tft.println(score);
    tft.setCursor(40, 30);tft.setTextColor(GREEN);tft.print(" LEVEL : ");tft.println(level);
    int ans = Serial.readString().toInt(); 
    sprintf(QT,"%d x %d",q1,q2);
    tft.setTextSize(3);
    tft.setCursor(40, 120);tft.setTextColor(GREEN);tft.print(QT);
    if (ans == q1*q2 && ans !=0){
    score++;
    tft.fillScreen(0x0000);   
    q1 = random(1,level*10);
    q2 = random(1,level*10);  
    if (score >= GT[level-1]){
        level++;
      }   
    }
    else if (ans != q1*q2 && ans !=0){
      tft.fillScreen(0x0000);
      tft.setTextSize(3);
      tft.setCursor(30, 60);tft.setTextColor(RED);tft.print("GAME-OVER");
      tft.setTextSize(2);
      tft.setCursor(30, 120);tft.setTextColor(GREEN);tft.print("You Scored : ");tft.print(score);
      tft.setCursor(10, 170);tft.setTextColor(RED);tft.print("     Press 1\n        to\n     Play Again");
      while(true){
        int ans = Serial.readString().toInt(); 
        if (ans==1){
          tft.fillScreen(0x0000);
          score = 0;level=1;
          break;
          }
        }
      }
  
   }
  }
  
  else if(n==10){
  while(true){
    tft.setCursor(20, 20);tft.setTextColor(GREEN);tft.println(" BMI-CALCULATOR ");
    tft.setCursor(20, 130);tft.setTextColor(GREEN);tft.println("  ENTER WEIGHT\n      IN KG ");
    double a = Serial.readString().toInt();
    if(a!=0){
    tft.setCursor(40, 130);tft.setTextSize(4);    
    tft.fillScreen(0x0000);
    tft.println(a);
    delay(300);
    tft.fillScreen(0x0000);
    tft.setCursor(20, 130);tft.setTextSize(2);
    tft.println("   ENTER HEIGHT\n       IN FEET");
    while(true){  
    double b = Serial.readString().toInt();
    if(b!=0 && b!=1){
    tft.setTextColor(0x0000);
    double bmi = BMI(a,b/3.281);
    if(bmi <= 18.5){tft.fillScreen(WHITE);}
    else if(bmi > 18.5 && bmi <= 25.0){tft.fillScreen(GREEN);}
    else if(bmi > 25.0){tft.fillScreen(RED);}
    tft.setCursor(20, 150);tft.setTextSize(2);tft.print("YOUR BMI : ");tft.print(bmi);
    }
    else if(b==1){tft.fillScreen(0x0000);break;}
    }
  }
  }

  }

else if(n==11){
  int Y = 30;
  tft.fillScreen(GREEN);
  
  while(true){
    tft.setTextSize(2);
    tft.setTextColor(BLACK);
    tft.setCursor(20, Y);//+20
    tft.println("1 : M TO CM");
    tft.setCursor(20, Y+20);
    tft.println("2 : M TO FEET");
    tft.setCursor(20, Y+40);
    tft.println("3 : FEET TO M");
    tft.setCursor(20, Y+60);
    tft.println("4 : FT TO MARLA");
    tft.setCursor(20, Y+80);
    tft.println("5 : F TO C");
    tft.setCursor(20, Y+100);
    tft.println("6 : C TO F");

    int i = Serial.readString().toInt();
    if(i!=0){ 
    tft.fillScreen(0x0000);
    tft.setCursor(20, 130);tft.setTextColor(GREEN);tft.println("  ENTER NUMBER\n        TO\n      CONVERT");
    while(true){
    double z = Serial.readString().toInt();
    if(z!=0 && z!=1){

    if(i==1){
    tft.fillScreen(0x0000);
    tft.setCursor(70, 130);tft.setTextColor(GREEN);tft.print(z/100.0);tft.print(" CM");
    }
    
    else if(i==2){
    tft.fillScreen(0x0000);
    tft.setCursor(70, 130);tft.setTextColor(GREEN);tft.print(z/3.281);tft.print(" FT");
    }

    else if(i==3){
    tft.fillScreen(0x0000);
    tft.setCursor(70, 130);tft.setTextColor(GREEN);tft.print(z*3.281);tft.print(" M");
    }

    else if(i==4){
    tft.fillScreen(0x0000);
    tft.setCursor(70, 130);tft.setTextColor(GREEN);tft.print(z/272.25);tft.print(" MARLA");
    }
     else if(i==5){
    tft.fillScreen(0x0000);
    tft.setCursor(70, 130);tft.setTextColor(GREEN);tft.print((z-32)*(5.0/9.0));tft.print(" C");
     }
    else if(i==6){
    tft.fillScreen(0x0000);
    tft.setCursor(70, 130);tft.setTextColor(GREEN);tft.print(z*(9.0/5.0)+32);tft.print(" F");
    

    
    
    }}
    else if (z==1){tft.fillScreen(GREEN);int Y=30;break;}
/*
    else if(i==2){
    while(true){double z = Serial.readString().toInt();
    if(z!=0){
    
    }}}

*/

    
    }}}}





    
else {
    Serial.print("-100");
    menu(100);
    break;break;
  }
    
  }
  }   
