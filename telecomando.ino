#include <IRremote.h> //libreria per utilizzare tutte le potenzialità che offre il telecomandio

int RECV_PIN = 11;//Pin in cui è collegato il ricevitore infrarossi 

IRrecv irrecv(RECV_PIN); // crea l'istanza 'irrecv'
decode_results results; // salva il risultato ricevuto dal ricevitore IR

void setup()
{
  Serial.begin(9600); //si abilita l'utilizzo del monitor seriale
  irrecv.enableIRIn(); //il ricevitore è attivo
}

void loop() {
  if (irrecv.decode(&results)) { // vero se si riceve un risultato
    Serial.println(String(results.value, HEX)); // stampa il valore esadecimale del tasto corrispondente
    irrecv.resume(); // ricezione del successivo valore
  }
}
