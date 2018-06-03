/*variables para cada color*/
int rled = 11; // Pin PWN 11 para led rojo
int bled = 10; // Pin PWM 10 para led azul
int gled = 9;  // Pin PWM 9  para led verde
 
/*variables auxiliares*/
int i; // Variable para ciclos repetitivos
int repeat = 5; // Variables para cantidad limite de repeticiones
 
 
void setup() {
/*Se inicializan pines*/  
  pinMode(rled, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(gled, OUTPUT);
}
 
void loop() {
  
 for(i=0; i<repeat; i++) 
    rgbon();
 delay(1000);  
 colors('y'); 
 delay(1000);
 colors('o');  
 delay(1000);
 colors('p'); 
 delay(1000); 
}
 
/*Funcion para colores principales*/
void rgbon(){
  analogWrite(rled,255); 
  delay(500);            
  analogWrite(rled,0);    
  analogWrite(bled,255); 
  delay(500);            
  analogWrite(bled,0);   
  analogWrite(gled,255); 
  delay(500);            
  analogWrite(gled,0);   
}
 
/* Funcion para otros colores */
void colors(char color){ 
  
  switch(color){ 
    case 'y': analogWrite(rled,255); // Se compara la y
            analogWrite(gled,255); // red = 255 / green = 255 / blue = 0
            analogWrite(bled,0);
    break;
    case 'o': analogWrite(rled,255); // se compara la o
            analogWrite(gled,180); // red = 255 / green = 180 / blue = 0
            analogWrite(bled,0);
    break;
    case 'p': analogWrite(rled,255); // se compara la p
          analogWrite(gled,0);   // red = 255 / green = 0 / blue = 255
            analogWrite(bled,255);
    break;
  } 
}
