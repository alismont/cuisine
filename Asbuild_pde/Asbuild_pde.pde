/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 25.09.2016 06:56:43
 Project     :
 Libraries   :
 Author      :
 Description :
******************************************************************/
import processing.serial.*;
import controlP5.*; // importe la librairie GUI controlP5

Serial  myPort;

PFont myFont;     // The display font
String inString;  // Input string from serial port
int lf = 10;      // ASCII linefeed 
String t=":";
String[] tag = new String[110];

String TramEcriture="";
int value = 0;

// controlP5
ControlP5 controlP5; // 
ControlP5 cp5, cp6, cp7, cp8, cp9, cp10, cp11, cp12;
Textlabel myTextlabelA;
Textlabel myTextlabelB;
Button envoiButton; 
Textfield chaineText; 
int myColorBackground = color(0, 0, 0);
int knobValue = 100;
float f=10;
Knob myKnobA;
Chart myChart;
String textValue = "";

int F1=0;

//-----------------------------------------------------------------------------------
void setup() { // fonction d'initialisation ex�cut�e 1 fois au d�marrage

  colorMode(RGB, 255, 255, 255); // fixe format couleur R G B pour fill, stroke, etc...
  fill(0, 0, 255); // couleur remplissage RGB
  stroke (0, 0, 0); // couleur pourtour RGB
  rectMode(CORNER); // origine rectangle : CORNER = coin sup gauche | CENTER : centre 
  imageMode(CORNER); // origine image : CORNER = coin sup gauche | CENTER : centre
  //strokeWeight(0); // largeur pourtour
  frameRate(30);// Images par seconde

  size(1000, 1057); // ouvre une fen�tre xpixels  x ypixels
  background(0, 0, 0); // couleur fond fenetre

  // --- initialisation des objets et fonctionnalit�s utilis�es --- 

  //------------- initialisation port serie ---- 
  println(Serial.list());  
  myPort = new Serial(this, Serial.list()[3], 9600); 
  
  myPort.bufferUntil('\n'); 

  myPort.clear();
  
  
  //  ------------ControlP5--------------------
  cp5 = new ControlP5(this); //<>//

  cp5.addTextfield("cp5")
    .setPosition(400, 20)
    .setSize(200, 20)
    .setFont(createFont("arial", 10))
    .setAutoClear(false);
    
  cp5.addBang("Add")
    .setPosition(400, 100)
    .setSize(80, 20)
    .getCaptionLabel().align(ControlP5.CENTER, ControlP5.CENTER)
    ;  
    
}
//------------------------------------------------
void  draw() { 
  
  if (inString != null) {
    String[] q = splitTokens(inString, "/");
    tag[0]=q[0];//
    tag[1]=q[1];//
    tag[2]=q[2];//
        tag[3]=q[3];//
                tag[4]=q[4];//
                        tag[5]=q[5];//
                          tag[6]=q[6];//
                            tag[7]=q[7];//

  }

  AffichageTags(tag); //<>//
  
    fill(130);
  rect(54, 130, 151, 50);
} 


//=================================================================================================Affichage
void AffichageTags(String[] tags) {  // This function also does not return a value
  background(0);

  if (tags[0] != null) {
    //image(img, 0, 0); 
    fill(250, 226, 5);
    textSize(20);

    text(tags[0], 26, 35);
    text(tags[1], 26, 55);
    text(tags[2], 200, 35);
    text(tags[3], 200, 55);
    text(tags[4], 600, 35);
    text(tags[5], 600, 55);
    text(tags[6], 600, 75);
    text(tags[7], 600, 95);

  }
}
//***********************************

void serialEvent(Serial p) { 
  inString = p.readString();
  //print(inString);
} 

void mouseClicked() {
  println(mouseX); println(mouseY);
  if (mouseX >= 26 & mouseX<=75 & mouseY>=126 & mouseY <=173) {
    myPort.write("OK/");
  }
  
}
//-----------------------------
public void clear() {
  cp5.get(Textfield.class, "").clear();
}

void controlEvent(ControlEvent theEvent) {
  if (theEvent.isAssignableFrom(Textfield.class)) {
    if (theEvent.getName()=="cp5") {
      F1=int(theEvent.getStringValue());
      myPort.write("F1"+F1+'/'); 
      println(theEvent.getName()+F1);//+theEvent.getStringValue());
    }

  }
}

public void Add() {
      println("add");
  myPort.write("BP/"); 
}