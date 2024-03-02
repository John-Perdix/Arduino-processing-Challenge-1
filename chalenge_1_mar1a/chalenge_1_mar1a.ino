const int esquerda = 13;    // the number of the pin for the pushbutton
const int direita = 2;

unsigned long lastDebounceTimeEsq = 0;  // Last time the button state changed
unsigned long lastDebounceTimeDir = 0;  // Last time the button state changed
unsigned long debounceDelay = 50;        // Debounce time in milliseconds

void setup() {
  Serial.begin(9600);//iniciar comunicação com o pc
  pinMode(esquerda, INPUT);
  pinMode(direita, INPUT);
  while(!Serial){
  }
}

void loop() {
  // Ler o states  dos pushbuttons
  int esqState = digitalRead(esquerda);
  int dirState = digitalRead(direita);

  // verificar o pushbuttons esquerdo se tem debounce
  if (esqState == HIGH && (millis() - lastDebounceTimeEsq) > debounceDelay) {
    Serial.print("A");
    lastDebounceTimeEsq = millis(); // Guardar o tempo do pressionar
  }

  //  verificar o pushbuttons direito se tem debounce
  if (dirState == HIGH && (millis() - lastDebounceTimeDir) > debounceDelay) {
    Serial.print("D");
    lastDebounceTimeDir = millis();
    lastDebounceTimeEsq = millis(); // Guardar o tempo do pressionar
  }
}

