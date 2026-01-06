
char carattere = 'a';

void setup()
{
 Serial.begin(9600);
  
  Serial.print("Decimale: ");
  Serial.println(carattere, DEC);
  Serial.print("Esadecimale: 0x");
  Serial.println(carattere, HEX);
  Serial.print("Binario: b");
  Serial.println(carattere, BIN);
  Serial.print("Carattere: ");
  Serial.println(carattere);
 
}

void loop()
{
  
 
}
