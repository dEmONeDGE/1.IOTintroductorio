//Programmer: Edgar E. Mamani A.
//Comunidad Arduino UMSS.
//FCyT - UMSS.


#include <Ethernet.h>
#include <SPI.h>

#define nombreCosa "iotUMSS"

byte mac[] = {0XAA, 0XBB, 0XCC, 0XDD, 0XEE, 0XFF};
IPAddress ip(192, 168, 1, 110);
IPAddress serverDns(8, 8, 8, 8);
IPAddress gateway(192, 168, 1, 1);
EthernetClient miCliente;

int val1 = 0, val2 = 0;

char miServidor[] = "www.dweet.io";
	
void setup() {
	Serial.begin(9600);
	Ethernet.begin(mac, ip, serverDns, gateway);
	delay(1000);

	randomSeed(A0);
}

void loop() {
	val1 = random(1, 100);
	val2 = random(1, 100);
	httpPeticion(val1, val2);
	delay(5000);
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