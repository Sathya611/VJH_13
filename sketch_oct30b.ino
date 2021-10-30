const int GSR=A0;
int sensorValue=0;
int gsr_average=0;
void setup()
{
 Serial.begin(9600);
}
void loop()
{
 long sum=0;
 for(int i=0;i<10;i++)  //average the 10 measurements USING FOR LOOP
 {
  sensorValue=analogRead(GSR);
  sum += sensorValue;
  delay(5);
 }
 gsr_average = sum/10;
 Serial.print("gsr_average-");
 Serial.println(gsr_average);
 int human_resistence=((1024+2*gsr_average)*10000)/(516-gsr_average);// FOLOW DATASHEET
 Serial.print("human_resistence-");
 Serial.println(human_resistence);
}
