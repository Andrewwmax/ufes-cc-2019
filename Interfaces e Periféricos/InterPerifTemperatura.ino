/*
No futuro:
	requisição por bluetooth da temperatura via comando.
    servidor de mini interface php
    conexão wifi
    conexão bluetooth tratada
    matriz de leds
    conexão de api com alguma nuvem
*/

//Sensor de Temperatura e Humidade
#include "SDHT.h"
// Leitor de cartão microSD
#include <SD.h>
#include <SPI.h>
// Tempo
#include <Time.h>
// Comunicação Serial bluetooth
#include <SoftwareSerial.h>

// Pinos Bluetooth
const int pinoRX = 5;
const int pinoTX = 4;

// Pino Buzzer
const int pinoBuz = 3;

// Pino CS do Cartao microSD
const int pinoSS = 10;

// Temperatura para fazer o piso e ativar o buzzer
int tempAnt = 0;

// Objeto Sensor de temperatura
SDHT dht;

// Objeto Cartao microSD
File myFile;

// Objeto inicializado do bluetooth
SoftwareSerial hc06(pinoRX, pinoTX);

// struct time_t para data/horario -10700 correcao de Fuso Horario 
time_t t = 1562034680 - 10700;

// Contador da reexibicao
int countCabecalho = 20;
/*
	Futuras implementacoes para comandos do Bluetooth
	String cmd="";
*/

void setup() {

	//INICIALIZA O SINCRONISMO SERIAL DO ARDUINO
	Serial.begin(9600);

	//INICIALIZA O SINCRONISMO SERIAL DO BLUETOOTH
	hc06.begin(9600);

	//Pino do buzzer
	pinMode(pinoBuz, OUTPUT); 
	
	// Pino MicroSD
	pinMode(pinoSS, OUTPUT);

	Serial.println(String("\n\n\nTrabalho de Interfaces e Perifericos")
      		     + String("\nUFES - Campus Ceunes, Sao Mateus - ES")
        	  	 + String("\nTemperatura e Humidade")
      		     + String("\nProf. Wilian Hiroshi Hisatugu")
      		     + String("\nAlunos: André Thiago Couto")
      		     + String("\n\tCarlos Humberto Brito")
      		     + String("\n\tBruno Calmon Barreto"));

  	hc06.println(String("\n\n\nTrabalho de Interfaces e Perifericos")
       		   + String("\nUFES - Campus Ceunes, Sao Mateus - ES")
      		   + String("\nTemperatura e Humidade")
      		   + String("\nProf. Wilian Hiroshi Hisatugu")
      		   + String("\nAlunos: André Thiago Couto")
      		   + String("\n\tCarlos Humberto Brito")
      		   + String("\n\tBruno Calmon Barreto"));
        
	if (SD.begin()) {
		myFile = SD.open("temp.txt", FILE_WRITE);
		if (myFile){
      		myFile.println(String("\n\n\nTrabalho de Interfaces e Perifericos")
	      			     + String("\nUFES - Campus Ceunes, Sao Mateus - ES")
	      			     + String("\nTemperatura e Humidade")
	      			     + String("\nProf. Wilian Hiroshi Hisatugu")
	      			     + String("\nAlunos: André Thiago Couto")
	      			     + String("\n\tCarlos Humberto Brito")
	      			     + String("\n\tBruno Calmon Barreto"));
		} else 
			Serial.println("Erro ao Abrir Arquivo .txt");
		
		myFile.close();
  	}

	// Inicializa o SD Card
	// Sons de aviso, 2 bips pra correto e 1 para erro
	if (SD.begin()) { 
		tone(3, 5000, 150);
		delay(250);
		tone(3, 5000, 150);
		delay(500);
	} else tone(3, 3000, 100);

	// Chama a funcao cabecalho para exibir informacoes e futuras instrucoes
	cabecalho();

}

void loop() {
	
	// Reexibicao do cabecalho a cada 20 passos
	if(countCabecalho-- == 0){
		cabecalho();
		countCabecalho = 20;
	}

	// funcao de teste do sensor de temperatura
	// Em seguida se existir um sensor conectado na porta 2,
	// chama a funcao layout que faz as operacoes de exibicao
	// da temperatura
	if (dht.broadcast(DHT11, 2)) 
		layout();
	// Espera por 2 segundos para a proxima execucao
	delay(2000);
}

void layout() {

	// Recebe o Piso, para os calculos do buzzer
	int tempAtual = (int) dht.celsius;
	
	// Sons do buzzer
	if(tempAnt < tempAtual){
		for(int i = 0; i < 5; i++){
			tone(3, 1500 + (i * 50), 150);
			delay(100);
		}
	} else if(tempAnt > tempAtual){
		for(int i = 0; i < 5; i++){
			tone(3, 1000 - (i * 50), 150);
			delay(100);
		}
	}

	// Recebe o Piso, para atualizar a temperatura da proxima iteracao
	tempAnt = (int) dht.celsius;
	
	// BACKEND
	// Exibe a mensagem em todos os dispositivos conectados
	Serial.println("| " + String(dht.celsius, 2) + " | " + String(dht.humidity, 2) + " |");
	hc06.println(  "| " + String(dht.celsius, 2) + " | " + String(dht.humidity, 2) + " |");

	if (SD.begin()) {
		myFile = SD.open("temp.txt", FILE_WRITE);
		if (myFile) myFile.println("| " + String(dht.celsius, 2) + " | " + String(dht.humidity, 2) + " |");
		else Serial.println("Erro ao Abrir Arquivo .txt");
		myFile.close();
	} else tone(3, 3000, 120);
}

void cabecalho(){

	// Cria || Abre arquivo .txt
	myFile = SD.open("temp.txt", FILE_WRITE);

	// Imprimir informacoes no Serial do Arduino 
	Serial.println("Tamanho do arquivo: " 	+ String(myFile.size() / 1024) + "Kb");
	Serial.println("Iniciado em " 			+ String(hour(t))   + ":"
											+ String(minute(t)) + ":"
											+ String(second(t)) + " | "
											+ String(day(t))    + "/"
											+ String(month(t))  + "/"
											+ String(year(t)));
	Serial.println("| Tempe | Humid |");

	// Imprimir informacoes no arquivo do cartao microSD 
	myFile.println("Tamanho do arquivo: " 	+ String(myFile.size() / 1024) + "Kb");
	myFile.println("Iniciado em " 			+ String(hour(t))   + ":"
											+ String(minute(t)) + ":"
											+ String(second(t)) + " | "
											+ String(day(t))    + "/"
											+ String(month(t))  + "/"
											+ String(year(t)));
	myFile.println("| Tempe | Humid |");

	// Imprimir informacoes no Serial do bluetooth 
	hc06.println("Tamanho do arquivo: " 	+ String(myFile.size() / 1024) + "Kb");
	hc06.println("Iniciado em " 			+ String(hour(t))   + ":"
											+ String(minute(t)) + ":"
											+ String(second(t)) + " | "
											+ String(day(t))    + "/"
											+ String(month(t))  + "/"
											+ String(year(t)));
	hc06.println("| Tempe | Humid |");
	
	// fecha Arquivo
	myFile.close();
}
