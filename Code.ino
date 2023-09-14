/*
Calculation & Validation for the Ethanol Concentration
The range to sense the ethanol near sensor regions is 0.04 mg/L – 4 mg/L. Ethanol mass fraction we obtained for sensor regions was in range 0.00028 to 0.00050, we will do the calculation for the ethanol concentration from the obtained mass fraction.
Concentration= 0.00028 (Ethanol mass in car) mg/ (Total mass in car) mg * density inside car cabin kg/m3
Density inside the car cabin = P/RT (Real Gas equation) P= 101325 Pascals; R= 287 J/ kg K; T (Average cabin Temperature) = 297 K
Density inside the car cabin = 101325/(287*297) = 1.1731 kg/m3
For minimum mass fraction (Sensor Number 2)
0.00028*1.1731 kg/m3 = 0.000328468 kg/m3 =0.000328468 *1000 mg/L= 0.33mg/L
For maximum mass fraction (Sensor Number 1)
0.00049*1.1731 kg/m3 = 0.000574819 kg/m3 =0.000328468 *1000 mg/L= 0.57mg/L
That concludes the 4 sensors are in the sensing range which is between (0.33-0.57) mg/L, which will successfully detect the Ethanol limits
*/


#define sensor1 A0
#define sensor2 A1
#define sensor3 A2
#define sensor4 A3
#define led 13
#define engine 9
void setup()
{
Serial.begin(9600);
delay(2000);
pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);
pinMode(sensor3, INPUT);
pinMode(sensor4, INPUT);
pinMode(engine, OUTPUT);
pinMode(led, OUTPUT);
}
void loop()
{
float adcValue1,adcValue2,adcValue3,adcValue4=0;
for(int i=0;i<10;i++)
{
adcValue1+= analogRead(sensor1);
adcValue2+= analogRead(sensor2);
adcValue3+= analogRead(sensor3);
adcValue4+= analogRead(sensor4);
delay(10);
}
float v1= (adcValue1/1024) ;
float mgL1= 100* v1;
float v2= (adcValue2/1024);
float mgL2= 100* v2;
float v3= (adcValue3/1024);
float mgL3= 100 * v3;
float v4= (adcValue4/1024);
float mgL4= 100 * v4;
if(mgL1 && mgL2 && mgL3 && mgL4 > 0.04)
{
digitalWrite(engine, HIGH);
digitalWrite(led, HIGH);
}
else
{
digitalWrite(engine, LOW);
digitalWrite(led, LOW);
}
delay(50)
}