//Programmer: Edgar E. Mamani A.
//Comunidad Arduino UMSS.
//FCyT - UMSS.
#define poten	A0
#define boton	2

const unsigned long tiempoPot = 10L * 200L;

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
		//delay(150);
		Serial.println("Persona ingresando.");
		contPersonas++;
	}

	if(millis() - ultimaConexionPot > tiempoPot){
		estPot = analogRead(poten);
		estPot = map(estPot, 0, 1023, 0, 100);    
	}
}