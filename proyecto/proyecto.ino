//Programmer: Edgar E. Mamani A.
//Comunidad Arduino UMSS.
//FCyT - UMSS.


#include <Ethernet.h>
#include <SPI.h>

#define nombreCosa "iotUMSS"
#define poten	A0
#define boton	2

const unsigned long tiempoPot = 10L * 500L;
unsigned long ultimaConexionPot = 0;

byte mac[] = {0XAA, 0XBB, 0XCC, 0XDD, 0XEE, 0XFF};
IPAddress ip(192, 168, 1, 110);
IPAddress serverDns(8, 8, 8, 8);
IPAddress gateway(192, 168, 1, 1);
EthernetClient miCliente;

char miServidor[] = "www.dweet.io";
boolean estBoton;
int estPot = 0;
int contPersonas = 0;

void setup() {
	Serial.begin(9600);
	pinMode(boton, INPUT);
	Ethernet.begin(mac, ip, serverDns, gateway);
	delay(1000);
}

void loop() {

	estBoton = digitalRead(boton);
	
	if(estBoton){
		delay(150);
		contPersonas++;
		httpPeticion(contPersonas, estPot);
		Serial.println("Personas: " + String(contPersonas));
	}

	if(millis() - ultimaConexionPot > tiempoPot){
		estPot = analogRead(poten);
		estPot = map(estPot, 0, 1023, 0, 100);
		Serial.println("Lectura actual: " + String(estPot));
		httpPeticion(contPersonas, estPot);
		ultimaConexionPot = millis();
	}
}

void httpPeticion(int val1, int val2){
	miCliente.stop();

	if(miCliente.connect(miServidor, 80)){
		Serial.println("Conectado al servidor...");

		String c = "GET /dweet/for/";
		c.concat(nombreCosa);
		c.concat("?val1=");
		c.concat(val1);
		c.concat("&val2=");
		c.concat(val2);
		c.concat(" HTTP/1.1");

		miCliente.println(c);
		miCliente.println("Host: www.dweet.io");
		miCliente.println("Connection: close");
		miCliente.println();

		Serial.println(c);
		
	}
	else
		Serial.println("La conexión con el servidor falló...");

}