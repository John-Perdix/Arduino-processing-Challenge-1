import processing.serial.*;

Serial myPort;
String val;

int r, x, y, vel;

void setup() {
  size(1024, 1024);
  vel = 10;
  x = width/2;
  y = height/2;
  r = 50;

  String portName = "COM3";
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  background(255);
  fill(255, 180, 0);
  noStroke();
  circle(x, y, r*2);

  while (myPort.available() > 0) {
    // Ler os bytes do ardUino
    char inChar = (char) myPort.read();
    // carregar no pushbutton esquerdo move o circulo
    if (inChar == 'A') {
      if (x>r) {
        x -= vel;
      }
    }
    // carregar no pushbutton direito move o circulo
    else if (inChar == 'D') {
      if (x < width-r) {
        x += vel;
      }
    }
  }
}
