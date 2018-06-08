// Declaracion de variables a ocupar
long dis;
long tiem;
int trig = 3;
int echo = 4;

int rled = 11; // Pin PWN 11 para led rojo
int bled = 10; // Pin PWM 10 para led azul
int gled = 9;  // Pin PWM 9  para led verde

//Inicializar
void setup( ){
Serial.begin(9600); //Se elige la frecuencia en baudios
pinMode(trig, OUTPUT); //salida del pulso generado por el sensor ultrasónico
pinMode(echo, INPUT);//entrada del pulso generado por el sensor ultrasónico
pinMode(rled,INPUT);
}
void loop(){
digitalWrite(trig,LOW);//recibimiento del pulso.
delayMicroseconds(5); //se Espera por microsegundos
digitalWrite(trig, HIGH);//envió del pulso.
delayMicroseconds(trig);

tiem=pulseIn(echo, HIGH);//fórmula para medir el pulso entrante.
dis= long(0.017*tiem);//fórmula para calcular la distancia del sensor ultrasónico.

//Se comparan las distancias para poder activar los distintos colores del led RGB
if(dis>100)
{ 
  analogWrite(gled,255); //Se enciende led RGB
}
else
{
  analogWrite(gled,0); //Se apaga led RGB si no esta en la distancia
}

if(dis>= 50 && dis < 100)
{
  analogWrite(bled,255);//Se enciende led RGB   
}
else
{
  analogWrite(bled,0); //Se apaga led RGB
}

if(dis < 50)
{
  analogWrite(rled,255); //Se enciende led RGB
}
else
{
  analogWrite(rled,0); //Se apaga led RGB
}

Serial.println("Distancia: ");  //Se escribe la distancia en monitor serie
Serial.println(dis);
Serial.println("cm");
delay(500);
}
