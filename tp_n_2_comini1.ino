#define LED_R 2
#define LED_B 3
#define LED_G 4
#define LED2_R 5
#define LED2_B 6
#define LED2_G 7
#define LED3_R 8
#define LED3_B 9
#define LED3_G 10
#define BUZZ 11
#define POT_TIME A0
#define POT_R A1
#define POT_G A2
#define POT_B A3
#define BTN 12

int estado;
int ultimoEstado = HIGH; 	
bool encendido = false;

void setup()
{
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED2_R, OUTPUT);
  pinMode(LED2_G, OUTPUT);
  pinMode(LED2_B, OUTPUT);
  pinMode(LED3_R, OUTPUT);
  pinMode(LED3_G, OUTPUT);
  pinMode(LED3_B, OUTPUT);
  pinMode(POT_TIME, INPUT);
  pinMode(POT_R, INPUT);
  pinMode(POT_G, INPUT);
  pinMode(POT_B, INPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  estado = digitalRead(BTN);
  
  if (estado == LOW && ultimoEstado == HIGH) 
  {
    encendido = !encendido;
    delay(50);
  }
  ultimoEstado = estado;

  if (encendido) {encenderTodo();} 
  else {apagarTodo();}
}

void apagarTodo()
{
  analogWrite(LED_R, 0);
  analogWrite(LED_G, 0);
  analogWrite(LED_B, 0);
  analogWrite(LED2_R, 0);
  analogWrite(LED2_G, 0);
  analogWrite(LED2_B, 0);
  analogWrite(LED3_R, 0);
  analogWrite(LED3_G, 0);
  analogWrite(LED3_B, 0);
  digitalWrite(BUZZ, LOW);
}

void encenderTodo()
{
  int led_r = analogRead(POT_R);
  int rojo = map(led_r, 0, 1023, 0, 255);
  int led_b = analogRead(POT_B);
  int azul = map(led_b, 0, 1023, 0, 255);
  int led_g = analogRead(POT_G);
  int verde = map(led_g, 0, 1023, 0, 255);
  int tiempo = analogRead(POT_TIME);
  int milisegundos = map(tiempo, 0, 1023, 100, 500);
  
  analogWrite(LED3_R, 0);
  analogWrite(LED3_G, 0);
  analogWrite(LED3_B, 0);
  analogWrite(LED2_R, 0);
  analogWrite(LED2_G, 0);
  analogWrite(LED2_B, 0);
  analogWrite(LED_R, rojo);
  analogWrite(LED_G, verde);
  analogWrite(LED_B, azul);
  delay(milisegundos);
  
  digitalWrite(BUZZ, HIGH);
  delay(50);
  digitalWrite(BUZZ, LOW);
  
  analogWrite(LED_R, 0);
  analogWrite(LED_G, 0);
  analogWrite(LED_B, 0);
  analogWrite(LED3_R, 0);
  analogWrite(LED3_G, 0);
  analogWrite(LED3_B, 0);
  analogWrite(LED2_R, rojo);
  analogWrite(LED2_G, verde);
  analogWrite(LED2_B, azul);
  delay(milisegundos);
  
  digitalWrite(BUZZ, HIGH);
  delay(50);
  digitalWrite(BUZZ, LOW);
  
  analogWrite(LED_R, 0);
  analogWrite(LED_G, 0);
  analogWrite(LED_B, 0);
  analogWrite(LED2_R, 0);
  analogWrite(LED2_G, 0);
  analogWrite(LED2_B, 0);
  analogWrite(LED3_R, rojo);
  analogWrite(LED3_G, verde);
  analogWrite(LED3_B, azul);
  delay(milisegundos);
  
  digitalWrite(BUZZ, HIGH);
  delay(50);
  digitalWrite(BUZZ, LOW);
  
  Serial.print("Tiempo: ");
  Serial.println(milisegundos);
  Serial.print("Rojo: ");
  Serial.print(rojo);
  Serial.print(" ");
  Serial.print("Azul: ");
  Serial.print(azul);
  Serial.print(" ");
  Serial.print("Verde: ");
  Serial.println(verde);
}


