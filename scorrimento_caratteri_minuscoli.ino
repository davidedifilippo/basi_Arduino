char carattere = 97;

int count = 0;

void setup()
{
 Serial.begin(9600); 
}

void loop()
{
  //Stampo i codici ASCII da 97 a 122   
  Serial.print(carattere, DEC);
  Serial.print(" ");
  Serial.println(carattere);
  
  carattere++; 
  
  if(carattere > 122) 
    carattere = 97;
  
  delay(200);
  
}
