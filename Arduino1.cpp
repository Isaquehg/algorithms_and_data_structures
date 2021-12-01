#include <Servo.h>

//inicializando Servo
Servo servo;

void setup()
{
  Serial.begin(9600);//Monitor
  servo.attach(9);//servo motor
  pinMode(13, INPUT);//Sensor sonoro
  pinMode(10, OUTPUT);//Trigger
  pinMode(6, INPUT);//Echo
  pinMode(8, OUTPUT);//LED1
  pinMode(7, OUTPUT);//LED2 VERDE
}
void loop()
{
  int som = 0;//sensor sonoro
  int led1 = 7;//verde
  int led2 = 8;//vermelho
  
  //ULTRASSONICO
  long duracao = 0;//duracao de ir e voltar som
  float dist = 0.0;//distancia ultrassonico
  digitalWrite(10, LOW);//inicializa o trigger
  delayMicroseconds(5);
  digitalWrite(10, HIGH);//envio do sinal
  delayMicroseconds(10);//tempo p enviar o sinal
  digitalWrite(10, LOW);//

  duracao = pulseIn(6, HIGH);//incia a contagem
  dist = duracao * 0.034 / 2.0;//distancia em cm(entre 4m e 2cm)
  //SERVO
  int angle = analogRead(A0);
  // Mapeando o valor de 0 a 180 graus
  angle = map(angle, 0, 1023, 0, 180);
  servo.write(angle);//mandar posicao p servo
  delay(15);
  
  //SENSOR DE SOM
  som = digitalRead(13);//leitura do sensor de som
    
  //acima de 80db
  if(som == HIGH){//Apenas Som
    delay(100);
    Serial.println("Ruido Detectado");
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    delay(2000);
  }
  else if(dist <= 320 && dist >= 2){//Apenas Movimento
    delay(100);
    Serial.println("Movimentacao!!");
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    Serial.print("Dist: ");
    Serial.println(dist);
  }
  else if((dist <= 320 && dist >= 2) && som == HIGH){//Ambos
    delay(100);
    Serial.println("Moviment e Ruido");
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    Serial.print("Dist: ");
    Serial.println(dist);
  }
  else{//Nenhum
    Serial.println("Nada Detectado");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    }
}