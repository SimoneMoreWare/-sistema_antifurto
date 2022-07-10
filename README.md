# -sistema_antifurto
Progetto Arduino: simulare un sistema antifurto

Un antifurto è un sistema elettronico che ha come scopo di impedire intrusioni eseguite da utenti di terze parti. Per tale scopo possono si impiegare più sensori, che possono essere in comunicazione tra loro tramite cablaggi o in connettività wireless. La comunicazione ad infrarossi (IR) è una tecnologia wireless ampiamente utilizzata.

In questo articolo presenteremo un tutorial riguardante il funzionamento approssimato di un antifurto su Arduino.

Il materiale da utilizzare per realizzare tale progetto è il seguente:

1x board Arduino UNO (o compatibili)
1x telecomando
1x ricevitore a infrarossi
1x display LCD
1x potenziometro 10 K
1x led rosso
1x led verde
2x resistori 220 ohm
1x buzzer attivo
25x jumper M-M;
Troverete tutti i componenti necessari nel kit Elegoo Advanced Starter Kit.

Il diagramma di collegamento è il seguente:
![alt text](https://i0.wp.com/www.moreware.org/wp/wp-content/uploads/2019/12/allarme.jpg?resize=1024%2C779&ssl=1)

video
https://www.youtube.com/watch?v=lHfq1DdYxGo

Per quanto riguarda la stesura del codice si deve tener conto dell’architettura di un ricevitore a infrarossi. I rilevatori di infrarossi sono piccoli microchips con una fotocellula sensibile alla luce infrarossa. Questi sensori sono quasi sempre utilizzati per il controllo remoto . All’interno dei telecomandi è presente il led ad infrarossi che emette pulsazioni alla giusta frequenza di luce che comanda al televisore di accendersi, spegnersi o cambiare canale. La luce ad infrarossi non è visibile agi occhi umani. Questo significa che il sensore necessita di un po’ di test prima di essere impostato correttamente.

La radiazione elettromagnetica IR viene emessa da molte fonti (sole, dalle lampadine e da qualsiasi altra fonte di calore). Queste ultime possono disturbare la comunicazione tra i nostri dispositivi IR. Per evitare che accada tutto ciò viene utilizzata la tecnica della modulazione.

Nel momento in cui si preme uno dei pulsanti verrà emessa tramite l’ausilio del LED IR una sequenza di accensioni e spegnimenti del LED IR  alla frequenza tipica di 38 kHz. Ad ogni pulsante è associato uno schema (detti pattern) specifico di 0 ed 1. Ad ogni stato logico è associata la frequenza di 0 Hz nel caso si voglia inviare uno 0 logico ed una frequenza di  38 kHz nel caso si voglia inviare un 1 logico. Gli schemi sono in genere costituiti da sequenze 12 o 32 bit.

La comunicazione IR richiede che tra trasmettitore e ricevitore non vi siano ostacoli, si devono trovare in condizione di visibilità reciproca, non sarà quindi possibile trasmettere attraverso ostacoli, come i muri, come invece risulta possibile per la comunicazione WiFi o Bluetooth.

Quindi ogni telecomando genera pulsazioni di luce infrarossa differente, e per tale motivo ciascun utente di Arduino deve provvedere a impostare correttamente il proprio telecomando.

Sketch https://github.com/SimoneMoreWare/-sistema_antifurto/tree/main

Tramite l’ausilio del monitor seriale è possibile associare per ogni tasto il valore esadecimale corrispondente. In questo modo è stato possibile “mappare” il telecomando tasto per tasto.

Ora è possibile procedere per la realizzazione del programma che simula un sistema antifurto. Il link del code in questione commentato riga per riga è presente su GitHub nel seguente link: https://github.com/SimoneMoreWare/-sistema_antifurto/blob/main/sistema_allarme.ino

Una volta effettuati questi passaggi basta caricare lo sketch sulla propria board di Arduino e cimentarvi nei diversi tentativi di inserire i PIN.



