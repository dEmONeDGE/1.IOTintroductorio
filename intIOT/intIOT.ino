//Programmer: Edgar E. Mamani A.
//Comunidad Arduino UMSS.
//FCyT - UMSS.
#define poten	A0
#define boton	2

const unsigned long tiempoPot = 10L * 500L;

boolean estBoton;
int estPot;
int contPersonas = 0;

unsigned long ultimaConexionPot = 0;

void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT);
}

void loop() {

	estBoton = digitalRead(boton);
	
	if(estBoton){
		delay(150);
		contPersonas++;
		Serial.println("Personas: " + String(contPersonas));
	}

	if(millis() - ultimaConexionPot > tiempoPot){
		estPot = analogRead(poten);
		estPot = map(estPot, 0, 1023, 0, 100);
		Serial.println("Lectura actual: " + String(estPot));
		ultimaConexionPot = millis();
	}
}