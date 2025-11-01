// Onboard LEDs.
const int LED1 = D0;
const int LED2 = D1;
const int LED3 = D2;

// Onboard buttons.
const int S1 = D3;
const int S2 = D4;
const int S3 = D5;

// GPIO pins 2-4.
const int IO2 = D8;
const int IO3 = D10;
const int IO4 = D9;

// Microcontroller mode status.
bool GPIOControl = false;

void setup() {
    Serial.begin(9600);
    Serial.println("Macro Microcontroller Firmware V1.0.3.\nPress and hold any key until LEDs light up to enable GPIO control or do nothing to run user program.");
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(S1, INPUT);
    pinMode(S2, INPUT);
    pinMode(S3, INPUT);
    userInit();
}

void loop() {
    // Statements to enable GPIO control mode if a key is pressed for more than 3 seconds.
    if ((digitalRead(S1) == HIGH || digitalRead(S2) == HIGH || digitalRead(S3) == HIGH) && GPIOControl == false) {
    delay(3000);
        if (digitalRead(S1) == HIGH || digitalRead(S2) == HIGH || digitalRead(S3) == HIGH) {
            GPIOControl = true;
            Serial.println("GPIO control mode enabled.");
            digitalWrite(LED1, HIGH);
            digitalWrite(LED2, HIGH);
            digitalWrite(LED3, HIGH);
            delay(1000);
            digitalWrite(LED1, LOW);
            digitalWrite(LED2, LOW);
            digitalWrite(LED3, LOW);
        }
    }
    if (GPIOControl == true) {
        pinMode(IO2, OUTPUT);
        pinMode(IO3, OUTPUT);
        pinMode(IO4, OUTPUT);
        keyGPIOControl();
    } else {
        Serial.println("Running user program...");
        userLoop();
    }
}

// Function for controlling GPIO pins with buttons.
void keyGPIOControl() {
    if (digitalRead(S1) == HIGH) {
        digitalWrite(IO2, HIGH);

    } else if (digitalRead(S2) == HIGH) {
        digitalWrite(IO3, HIGH);

    } else if (digitalRead(S3) == HIGH) {
        digitalWrite(IO4, HIGH);
    }
}

// Users add their program here.
void userInit() {

}

void userLoop() {
    // Sample program.
    pinMode(IO2, OUTPUT);
    delay(500);
    digitalWrite(IO2, HIGH);
    delay(500);
    pinMode(IO2, LOW);
}