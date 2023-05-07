#include <IRremote.h>
#include <Servo.h>

int IR_PIN = 2;
IRrecv irrecv(IR_PIN);



Servo base; //A1
Servo hinge1; //A0
Servo hinge2; //A1
Servo clamp; //A2
int pos = 0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode())
  {
    unsigned long code = irrecv.decodedIRData.command;
    Serial.println(code);

    if (code == 69)// turn everything off. //////// press power off
    {
      base.detach(),hinge1.detach(),hinge2.detach(),clamp.detach();
    }
    else if (code == 71) // menu----- open clamp
    {
      
      base.detach(),hinge1.detach(),hinge2.detach(),clamp.detach(); 

      
      clamp.attach(A2);

      clamp.write(15);
    }
    else if (code == 67)//return----- close
    {
      base.detach(),hinge1.detach(),hinge2.detach(),clamp.detach();

      clamp.attach(A2);
      clamp.write(130);
    }
    else if (code == 25) // - ---- down
    {
    base.detach();
    hinge1.detach();
    hinge2.detach();
    clamp.detach();

    hinge2.attach(A1);
    hinge2.write(30);
    delay(50);
    hinge2.detach();
    }
    else if (code == 64)//+ --- up
    {
      base.detach(),hinge1.detach(),hinge2.detach(),clamp.detach();
      hinge2.attach(A1);
      
      hinge2.write(190);
      delay(50);
      hinge2.detach();
    }

    else if (code == 7) // >> ---- forward
    {
     base.detach(),hinge1.detach(),hinge2.detach(),clamp.detach();

     hinge1.attach(A0); 
     hinge1.write(147);
     delay(50);
     hinge1.detach();
    }
    else if (code == 9) // <<< ---- back
    {
    base.detach(),hinge1.detach(),hinge2.detach(),clamp.detach();

     hinge1.attach(A0);
     
     hinge1.write(0);
     delay(50);
     hinge1.detach();  
    }
    irrecv.resume();
  }
}
