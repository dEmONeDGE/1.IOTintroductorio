#include <Ethernet.h>
#include <SPI.h>

byte mac[] = {0XAA, 0XBB, 0XCC, 0XDD, 0XEE, 0XFF};
IPAddress ip(10, 42, 0, 110);
IPAddress serverDns(8, 8, 8, 8);
IPAddress gateway(10, 42, 0, 32);
EthernetClient miCliente;

int aleatorio;

char miServidor[] = "www.dweet.io";
	
void setup() {
	Serial.begin(9600);
	Ethernet.begin(mac, ip, serverDns, gateway);
	delay(1000);

	randomSeed(millis());
}

void loop() {
	aleatorio = random(1, 100);
	Serial.println(aleatorio);

	//httpPeticion();
	delay(5000);
}