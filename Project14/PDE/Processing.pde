import processing.serial.*;
Serial Port;
PImage logo;
int bgcolor = 0;

void setup() {
  size(800, 800);
  surface.setResizable(true);
  colorMode(HSB, 255);
  logo = loadImage("../Berardinux_white.png");
  surface.setSize(logo.width, logo.height);
  Port = new Serial(this, "/dev/ttyACM0", 9600);
}

void draw() {
  while (Port.available() > 0) {
    bgcolor = Port.read();
    println("Value received from Arduino: " + bgcolor);
  }

  background(bgcolor, 255, 255);
  image(logo, 0, 0);
}




  //myPort = new Serial(this, Serial.list()[0], 9600);
