#include <robo_hardware2.h> 
#include <Servo.h>

//-----PINOS PARA SENSORES REFLETANCIA-----//
//SENSOR_LINHA_MAIS_ESQUERDO	    A3
//SENSOR_LINHA_ESQUERDO			    A2
//SENSOR_LINHA_DIREITO			    A1	
//SENSOR_LINHA_MAIS_DIREITO			A0	
//-----PINOS PARA SENSORES REFLETANCIA-----//

float valorSensorMaisEsq;
float valorSensorEsq;
float valorSensorDir;
float valorSensorMaisDir;
#define DIVISOR 70
void setup(){
	Serial.begin(9600);
	robo.configurar();
}
void loop(){
	valorSensorMaisEsq = robo.lerSensorLinhaEsq(); 
  valorSensorEsq = robo.lerSensorLinhaEsq();         //le um valor do sensor. O sensor retornar um valor de 0 100
	valorSensorDir = robo.lerSensorLinhaDir();         //le um valor do sensor. O sensor retornar um valor de 0 100
	valorSensorMaisDir = robo.lerSensorLinhaDir();
	Serial.print("; Maisesq: ");
	Serial.println(valorSensorMaisEsq);
  Serial.print("; esq: ");
	Serial.println(valorSensorEsq);       //Imprime o valor do sensor pela porta serial
	Serial.print("; dir: ");
	Serial.println(valorSensorDir);       //Imprime o valor do sensor pela porta serial
	Serial.print("; Maisdir: ");
	Serial.println(valorSensorMaisDir); 
	//Impressão dos valores dos sensores
	if (valorSensorMaisEsq > DIVISOR && valorSensorEsq > DIVISOR && valorSensorDir > DIVISOR &&  valorSensorMaisDir > DIVISOR) {//todos pegando branco
		robo.acionarMotores(60, 60);//frente
		delay(300);
	}
	else if (valorSensorMaisEsq > DIVISOR && valorSensorEsq <= DIVISOR &&  valorSensorDir <= DIVISOR  && valorSensorMaisDir > DIVISOR) {//só os mais pegando branco
		robo.acionarMotores(60, 60);//frente
		delay(300);
	}
  	else if ( valorSensorMaisEsq <= DIVISOR && valorSensorEsq <= DIVISOR && valorSensorDir <= DIVISOR && valorSensorMaisDir > DIVISOR) {//só o mais direito pegando branco
		robo.acionarMotores(-60, 60);//esquerda
		delay(300);
	} else if (valorSensorMaisEsq <= DIVISOR && valorSensorEsq <= DIVISOR  &&  valorSensorDir  > DIVISOR  && valorSensorMaisDir > DIVISOR) {//só os direitos pegando branco
		robo.acionarMotores(-60, 60);//esquerda
		delay(300);
	} else if (valorSensorMaisEsq > DIVISOR && valorSensorEsq <= DIVISOR && valorSensorDir <= DIVISOR &&  valorSensorMaisDir <= DIVISOR) { //só o mais esquerdo pegando branco
		robo.acionarMotores(60, -60);//direita
		delay(300);
	}
  	else if (valorSensorMaisEsq > DIVISOR && valorSensorEsq > DIVISOR && valorSensorDir <= DIVISOR &&  valorSensorMaisDir <= DIVISOR) {// só os esquerdos pegando branco
		robo.acionarMotores(60, -60);//direita
		delay(300);
	}
  	else if (valorSensorMaisEsq > DIVISOR && valorSensorEsq > DIVISOR && valorSensorDir > DIVISOR &&  valorSensorMaisDir <= DIVISOR) {// só o mais direio pegando preto
		robo.acionarMotores(60, -60);//direita
		delay(300);
	}
  	else if (valorSensorMaisEsq <= DIVISOR && valorSensorEsq <= DIVISOR && valorSensorDir <= DIVISOR &&  valorSensorMaisDir > DIVISOR) {// só o mais direito pegando branco
		robo.acionarMotores(-60, 60);//esquerda
		delay(300);
	}
	else {
		robo.acionarMotores(0,0);//parar
		delay(300);
	}

	delay(1000);

}
