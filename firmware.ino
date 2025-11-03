// Onboard LEDs.
const int L1 = D0;
const int L2 = D1;
const int L3 = D2;

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
    Serial.println("Macro Microcontroller Firmware V1.0.4.\nPress and hold any key until LEDs light up to enable GPIO control or do nothing to run user program.");
    pinMode(L1, OUTPUT);
    pinMode(L2, OUTPUT);
    pinMode(L3, OUTPUT);
    pinMode(S1, INPUT);
    pinMode(S2, INPUT);
    pinMode(S3, INPUT);
    pinMode(IO2, OUTPUT);
    pinMode(IO3, OUTPUT);
    pinMode(IO4, OUTPUT);
    userPins();
}

void loop() {
    // Statements to enable GPIO control mode if a key is pressed for more than 3 seconds.
    if ((digitalRead(S1) == HIGH || digitalRead(S2) == HIGH || digitalRead(S3) == HIGH) && GPIOControl == false) {
        Serial.println("Keypress detected. Hold for 3 seconds to enable GPIO control.");
        delay(3000);
        if (digitalRead(S1) == HIGH || digitalRead(S2) == HIGH || digitalRead(S3) == HIGH) {
            GPIOControl = true;
            Serial.println("GPIO control mode enabled.");
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, HIGH);
            delay(1000);
            digitalWrite(L1, LOW);
            digitalWrite(L2, LOW);
            digitalWrite(L3, LOW);
        }
    }
    if (GPIOControl == true) {
        keyGPIOControl();
    } else {
        Serial.println("Running user program... You can enable GPIO control at the next loop.");
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

// Functions for users to add their program.
void userPins() {
    // Change pinMode() in here if needed.
}

void userLoop() {
    // Sample program.
    delay(500);
    digitalWrite(IO2, HIGH);
    delay(500);
    pinMode(IO2, LOW);
}