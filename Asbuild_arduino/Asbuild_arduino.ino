
//-------------------------------------------------------------------

int TpsEv=300;
int TpsHot=300;
int Cpt_BpHot=0;
int BpHot = 5 ; 
int EtatBpHot=0;
int BpEv = 2;
int EtatBpEv=0;
int SpotEv = 11;
int SpotHotOn=0;
int SpotEvOn=0;
int SpotHot = 12;
int BpEscalHot=7;
int BpEscalEv=3;
int val1=0;
int val2=0;
int val3=0;
int val4=0;
int val5=0;
int val6=0;
int B3[20];
int TpsSgen=50;
int Led13=13;
boolean firstscan =true;
char octetReception;
char caractereReception;
char octetReceptionProc;
char caractereReceptionProc;
String chaineReception, Tram;
String chaineReceptionProc, TramProc;
boolean Processing=true;
int outSpothot=0;
int outSpotEv=0;
char charVal[10];

int BpHotTps=10;
int BpEvTps=10;
int Cpt_BpEv_val=0;
int Cpt_BpHot_val=0;

//**********************************************************
void setup(){

  Serial.begin(9600);
  //pinMode(BpHot, INPUT);
  //pinMode(BpEv, INPUT);
  //pinMode(BpEscalHot, INPUT);
  //pinMode(BpEscalEv, INPUT);
  
  pinMode(BpHot,INPUT_PULLUP);
    pinMode(BpEv,INPUT_PULLUP);
      pinMode(BpEscalHot,INPUT_PULLUP);
        pinMode(BpEscalEv,INPUT_PULLUP);
  
  
  pinMode(SpotHot, OUTPUT);
  pinMode(SpotEv, OUTPUT);
  pinMode(Led13, OUTPUT);
BpHotTps=0;
BpEvTps=0;
digitalWrite(SpotHot,HIGH);
digitalWrite(SpotEv,HIGH);
B3[2]=0;
B3[4]=0;

}
//***********************************************************
void loop(){
if (!firstscan){


if(BpHotTps>0)
{
BpHotTps=BpHotTps-1;
}
else{
BpHotTps=0;
}


if(BpEvTps>0)
{
BpEvTps=BpEvTps-1;
}
else{
BpEvTps=0;
}



//-----------EV--------------------
val1 = digitalRead(BpEv);

if(val1==0)
{
Cpt_BpEv_val=Cpt_BpEv_val+1;
    if (Cpt_BpEv_val>15){
    digitalWrite(SpotHot,HIGH);
        digitalWrite(SpotEv,HIGH);
        outSpothot=0;
        outSpotEv=0;
    }
} else{
Cpt_BpEv_val=0;
}

if(val1==0){
    if(!B3[3])
    {
          B3[3] = 1.0;
          B3[4] = 1.0;

    }
    else
    {
          B3[4] = 0.0;
    }
}
else {
          B3[3] = 0.0;
          B3[4] = 0.0;
}

 if(B3[4] & outSpothot==0 & BpEvTps>0) {
 digitalWrite(SpotHot,LOW);
          outSpothot=1;
}
if(B3[4] & outSpotEv==0)
{
  digitalWrite(SpotEv,LOW);
  BpEvTps=20;
  outSpotEv=1;
}
else
{

if(B3[4] & outSpotEv==1 & BpEvTps==0)
{
    
   digitalWrite(SpotEv,HIGH);
   outSpotEv=0;
}
}

//----------HOT---------------
val2 = digitalRead(BpHot);

if(val2==0)
{
Cpt_BpHot_val=Cpt_BpHot_val+1;
    if (Cpt_BpHot_val>10){
    digitalWrite(SpotHot,HIGH);
        digitalWrite(SpotEv,HIGH);
        outSpothot=0;
        outSpotEv=0;
    }
} else{
Cpt_BpHot_val=0;
}



if(val2==0){
    if(!B3[1])
    {
          B3[1] = 1.0;
          B3[2] = 1.0;

    }
    else
    {
          B3[2] = 0.0;
    }
}
else {
          B3[1] = 0.0;
          B3[2] = 0.0;
}

 if(B3[2] & outSpotEv==0 & BpHotTps>0) {
 digitalWrite(SpotEv,LOW);
          outSpotEv=1;
 
}

if(B3[2] & outSpothot==0)
{
digitalWrite(SpotHot,LOW);
          BpHotTps=15;
          outSpothot=1;
}else{

if(B3[2] & outSpothot==1 & BpHotTps==0)
{
    
         digitalWrite(SpotHot,HIGH);
    outSpothot=0; 
}
}
 

//------ESCALIER---------------
val3 = digitalRead(BpEscalEv);
 
if(val3==0){
    if(!B3[5])
    {
          B3[5] = 1.0;
          B3[6] = 1.0;      
    }
    else
    {
          B3[6] = 0.0;
    }
}
else {
          B3[5] = 0.0;
          B3[6] = 0.0;
}

if(B3[6] & outSpotEv==0)
{
digitalWrite(SpotEv,LOW);
outSpotEv=1;
}

val4 = digitalRead(BpEscalEv); 
if(val4==1){
    if(!B3[7])
    {
          B3[7] = 1.0;
          B3[8] = 1.0;      
    }
    else
    {
          B3[8] = 0.0;
    }
}
else {
          B3[7] = 0.0;
          B3[8] = 0.0;
}

if(B3[8] & outSpotEv==1)
{
digitalWrite(SpotEv,HIGH);
outSpotEv=0;
}


//----BP-HOT----
val5 = digitalRead(BpEscalHot);
 
if(val5==1){
    if(!B3[9])
    {
          B3[9] = 1.0;
          B3[10] = 1.0;      
    }
    else
    {
          B3[10] = 0.0;
    }
}
else {
          B3[9] = 0.0;
          B3[10] = 0.0;
}

if(B3[10] & outSpothot==0)
{
digitalWrite(SpotHot,LOW);
outSpothot=1;
}

 val6 = digitalRead(BpEscalHot);
 
if(val6==0){
    if(!B3[11])
    {
          B3[11] = 1.0;
          B3[12] = 1.0;      
    }
    else
    {
          B3[12] = 0.0;
    }
}
else { 
          B3[11] = 0.0;
          B3[12] = 0.0;
}

if(B3[12] & outSpothot==1)
{
digitalWrite(SpotHot,HIGH);
outSpothot=0;

}


      
AffProcessing();

}
    firstscan=false;
}
//---------------------------------
void AffProcessing() {
  while (Serial.available() > 0) { 
  
     octetReceptionProc = Serial.read(); // lit le 1er octet de la file d'attente
if (octetReceptionProc == '/') {
        if (chaineReceptionProc.substring(0, 2) == "OK")  {
            digitalWrite(Led13,LOW);
        }

      chaineReceptionProc = "";
    }
    else {
      caractereReceptionProc = char(octetReceptionProc);
      chaineReceptionProc = chaineReceptionProc + caractereReceptionProc;
      delay(10);
    }
  }
  
  
  
       
    Serial.print("BpEscalHot= ");
    Serial.print(digitalRead(BpEscalHot));
    Serial.print("/");
    
    Serial.print("BpEscalEv= ");
    Serial.print(digitalRead(BpEscalEv));
    Serial.print("/");    

  
      Serial.print("BpHot= ");
    Serial.print(digitalRead(BpHot));
    Serial.print("/");    

          Serial.print("BpEv= ");
    Serial.print(digitalRead(BpEv));
    Serial.print("/");
    
              Serial.print("BpHotTps= ");
    Serial.print(BpHotTps);
    Serial.print("/");
    
                  Serial.print("BpEvTps= ");
    Serial.print(BpEvTps);
    Serial.print("/");
    
                      Serial.print("outSpothot= ");
    Serial.print(outSpothot);
    Serial.print("/");
    
                          Serial.print("outSpotEv= ");
    Serial.print(outSpotEv);
    Serial.print("/");
    
        Serial.println();
        
}