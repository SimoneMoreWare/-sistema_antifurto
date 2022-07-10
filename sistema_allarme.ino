
#include <IRremote.h> //con tale libreria è possibile sfruttare a pieno le potenzialità del telecomando

#include <LiquidCrystal.h> //con tale libreria è possibile sfruttare a pieno le potenzialità del display

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //i digital pin utilizzati dal display
int RECV_PIN = 3; //il digital pin utilizzato dal ricevitore IR
int greenLed = 4; //il digital pin utilizzato dal led verde
int redLed = 13; //il digital pin utilizzato dal led rosso
int buzzer = 2; //il digital pin utilizzato dal buzzer attivo

//nelle seguenti righe sono stati dichiarati i valori esadecimali dei tasti 1,2,3,4,5,6,7,8,9;
//per inserire tali valori è stato utilizzato lo sketch precedente
String btn1 = "ff30cf"; 
String btn2 = "ff18e7"; 
String btn3 = "ff7a85";
String btn4 = "ff10ef";
String btn5 = "ff38c7";
String btn6 = "ff5aa5";
String btn7 = "ff42bd";
String btn8 = "ff4ab5";
String btn9 = "ff52ad";

IRrecv irrecv(RECV_PIN); // crea l'istanza 'irrecv'  

decode_results results; // salva il risultato ricevuto dal ricevitore IR

void setup() {
  irrecv.enableIRIn(); //il ricevitore è attivo
  digitalWrite (redLed,LOW); //il led rosso è spento
  digitalWrite (greenLed,LOW); //il led verde è spento
  digitalWrite (buzzer,LOW); //il buzzer non genera nessun suono, in quanto è spento
  pinMode (greenLed, OUTPUT); 
  pinMode (redLed, OUTPUT);
  pinMode (buzzer, OUTPUT);
  lcd.begin(16, 2); //colonne e righe di cui è composto il display
}

void loop() {
  int c[4]; //in ciascun indice in tale vettore sara memorizzata la cifra digitata dall'utente 
  int pin=0; //in tale variabile sarà memorizzato il pin digitato dall'utente
  int i=0; //tale variavile è utilizzata per indentificare l'indice del primo vettore
  int q=0; //tale variabile è utilizzata per indentificare l'indice del secondo vettore
  int y=3; //tale variabile è utilizzata per contatare i tentativi rimasti da parte dell'utente per digitare il pin
  int r=0; //tale variabile è utilizzata per l'inserimento dei valori se il pin digitato è quello sbagliato

  lcd.clear(); //Cancella tutto ciò che è presente sullo schermo LCD
  lcd.setCursor(0,0); //con tale comando il cursore si posiziona nella colonna 0 e riga 0 
  lcd.print("Inserire PIN:"); //sul display comparirà il messaggio: Inserire PIN:
  
  //con questo ciclo while sarà utilzzato per assegnare ciascuna cifra digitate al corrispostivo indice del vettore
  while (i<4){
    //con il seguente if si eseguiranno delle istruzioni solo se il ricevitore IR riceve un segnale
  if (irrecv.decode(&results)) {
    //nei seguenti if si confronta il valore digitato dall'utente con il valore esadecimale corrispondente
    if (String(results.value, HEX) == btn1) {
      c[i]=1; //si assegna il valore 1
          asterisco(i); //con tale funzione compare sul display *   
    } else if (String(results.value, HEX) == btn2) {
      c[i]=2;
          asterisco(i);
    } else if (String(results.value, HEX) == btn3) {
      c[i]=3;
          asterisco(i);
    } else if (String(results.value, HEX) == btn4){
        c[i]=4;
          asterisco(i);
    } else if (String(results.value, HEX) == btn5){
      c[i]=5;
          asterisco(i);
    } else if (String(results.value, HEX) == btn6){
      c[i]=6;
          asterisco(i);
    }else if (String(results.value, HEX) == btn7){
      c[i]=7;
          asterisco(i);
    }else if (String(results.value, HEX) == btn8){
      c[i]=8;
          asterisco(i);
    }else if (String(results.value, HEX) == btn9){
      c[i]=9;
          asterisco(i);
    }
   i++;    //si incrementa il valore di i di 1, in tal modo da passare all'indice succesivo
   delay(500);
   irrecv.resume(); // ricezione del successivo valore
   delay(500); //per inserire il prossimo valore si dovrà aspettare mezzo secondo
  }
  }
  pin=1000*c[0]+100*c[1]+10*c[2]+c[3]; //il pin digitato dall'utente
  delay(500);
 
   
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sblocca Arduino");
  
  while(r<3){
  q=0; 
  while(q<4){
    if (irrecv.decode(&results)) {
      if (String(results.value, HEX) == btn1) {
      c[q]=1;
          asterisco(q);
      } else if (String(results.value, HEX) == btn2) {
      c[q]=2;
          asterisco(q);
      } else if (String(results.value, HEX) == btn3) {
      c[q]=3;
          asterisco(q);       
      } else if (String(results.value, HEX) == btn4){
        c[q]=4;
          asterisco(q);
    } else if (String(results.value, HEX) == btn5){
      c[q]=5;
          asterisco(q);
    } else if (String(results.value, HEX) == btn6){
      c[q]=6;
          asterisco(q);
    }else if (String(results.value, HEX) == btn7){
      c[q]=7;
          asterisco(q);
    }else if (String(results.value, HEX) == btn8){
      c[q]=8;
          asterisco(q);
    }else if (String(results.value, HEX) == btn9){
      c[q]=9;
          asterisco(q);
    }
   q++;    
   delay(500);
   irrecv.resume();
   delay(500);
  }
  }
  int pin1=0; //il pin digitato dall'utente, sarà confrontato con quello iniziale
  pin1=1000*c[0]+100*c[1]+10*c[2]+c[3];

  //in questo if i due pin saranno confrontati
  if(pin==pin1){
    digitalWrite(redLed,LOW); //il led rosso è spento
    digitalWrite(greenLed,HIGH); //il led verde si accende
    
    digitalWrite(buzzer,HIGH);
    delay(250);
    digitalWrite(buzzer,LOW);
    delay(100);                  //il buzzer emetterà due segnali acustici brevi e vicini tra loro
    digitalWrite(buzzer,HIGH);
    delay(250);
    digitalWrite(buzzer,LOW);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PIN GIUSTO!!");
    delay(5000);
    
  } else {
    digitalWrite(redLed,HIGH); 
    
    digitalWrite(greenLed,LOW);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PIN SBAGLIATO!!");

    digitalWrite(buzzer,HIGH);
    delay(3000);
     
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("n.tentativi:");
    lcd.setCursor(13,1);
    y=y-1;
    lcd.print(y);
    
    digitalWrite(buzzer,LOW);
    digitalWrite(redLed,LOW);
    delay(2000);
    
    lcd.clear();
    lcd.print("sblocca Arduino");
  }
  r++; 
  }
  }

  void asterisco (int i){
           if(i==0){
            lcd.setCursor(0,1);
            lcd.print("*");
          } else if (i==1){
            lcd.setCursor(1,1);
            lcd.print("*");
          }else if (i==2){
            lcd.setCursor(2,1);
            lcd.print("*");
          }else if (i==3){
            lcd.setCursor(3,1);
            lcd.print("*");
          }
  }
 
  
  
