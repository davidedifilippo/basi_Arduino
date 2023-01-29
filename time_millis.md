## La funzione millis()

Restituisce il numero di millisecondi da quando la scheda Arduino ha avviato il programma corrente. Questo numero andrà in overflow (tornerà a zero) dopo circa 50 giorni dato che utilizza un tipo di dato a 32bit ossia 4Byte senza segno per memorizzare i millisecondi:

    (2^32-1) millisecodi = 2^32/(1000*60sec*60min*24ore) = 49.71 giorni 


currentTime = millis()

La funzione risulta utile e sostituisce la funzione delay() quando non è possibile arrestare l'esecuzione del programma. Ad esempio nel controllo del lampeggio di un led e simultaneo utilizzo di pulsanti da monitorare, di un tastierino numerico o nelle letture rapide di sensori.
La funzione delay(millisecondi) in effetti è bloccante (si arresta il sistema per tot millisecondi). 

## Le variabili di tipo long 

la varabile currentTime deve essere dichiarata di tipo unsigned long:

    unsigned long currentTime;
    
Dichiaro le variabili necessarie:

    bool ledState = false;
    unsigned long previousTime;
    unsigned long interval = 1000;  
    
## Fase di setup 

impostare il piedino 2 come uscita, in modo da poter alimentare il led:

    pinMode(2, OUTPUT);
   
Si attiva la porta di comunicazione seriale per il debug dell'applicazione:

    Serial.begin(9600)

Si stampa il valore di inizio attività:

    currentTime = millis();
    Serial.print("Start at:" + currentTime);

## Fase di loop

Ad ogni ciclo di loop si aggiorna il tempo in modo che sia aggiornato al valore corrente:

    currentTime = millis();
    
Cambio lo stato del led solo se è passato il tempo impostato:

     if (currentTime - previousTime >= interval) {
    
          previousTime = currentMillis; // Mi ricordo l'istante del cambiamento di stato 

          // if the LED is off turn it on and vice-versa:
             if (ledState == LOW) {
                ledState = HIGH;
              } else {
                      ledState = LOW;
                                      }
Quindi cambio lo stato di accensione del led reale:
    
      digitalWrite(ledPin, ledState);
