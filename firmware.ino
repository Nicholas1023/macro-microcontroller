// Onboard LEDs.
const int L1 = D0;
const int L2 = D1;
const int L3 = D2;

// Onboard buttons.
const int SW1 = D3;
const int SW2 = D4;
const int SW3 = D5;

// GPIO pins 2-4.
const int IO2 = D8;
const int IO3 = D10;
const int IO4 = D9;

// Microcontroller mode status.
bool GPIOControl = false;

// Print default mode prompt.
bool defaultEnable = true;

void setup() {
    Serial.begin(9600);
    Serial.println("Macro Microcontroller Firmware Version 1.0.8.");
    // Set GPIO pins, LEDs and push buttons modes.
    pinMode(IO2, OUTPUT);
    pinMode(IO3, OUTPUT);
    pinMode(IO4, OUTPUT);
    pinMode(L1, OUTPUT);
    pinMode(L2, OUTPUT);
    pinMode(L3, OUTPUT);
    pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);
    pinMode(SW3, INPUT);
    Serial.println("Press and hold any key until LEDs light up to enable GPIO control. Do nothing to run user program.");
}

void loop() {
    // Enable GPIO control mode if a key is pressed for more than 3 seconds.
    if ((digitalRead(SW1) == HIGH || digitalRead(SW2) == HIGH || digitalRead(SW3) == HIGH) && GPIOControl == false) {
        Serial.println("Keypress detected. Hold for 3 seconds to enable GPIO control.");
        defaultEnable = true;
        delay(3000);
        if (digitalRead(SW1) == HIGH || digitalRead(SW2) == HIGH || digitalRead(SW3) == HIGH) {
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
        if (defaultEnable == true) {
            userPins();
            Serial.println("Running user program... Enable GPIO control at the next loop.");
            defaultEnable = false;
        }
        userLoop();
    }
}

// Controlling GPIO pins with buttons.
void keyGPIOControl() {
    if (digitalRead(SW1) == HIGH) {
        while (true) {
            digitalWrite(IO2, HIGH);
            if (digitalRead(SW1) == LOW) {
                digitalWrite(IO2, LOW);
                break;
            }
        }
    } else if (digitalRead(SW2) == HIGH) {
        while (true) {
            digitalWrite(IO3, HIGH);
            if (digitalRead(SW2) == LOW) {
                digitalWrite(IO3, LOW);
                break;
            }
        }
    } else if (digitalRead(SW3) == HIGH) {
        while (true) {
            digitalWrite(IO4, HIGH);
            if (digitalRead(SW3) == LOW) {
                digitalWrite(IO4, LOW);
                break;
            }
        }
    }
}

// Add your custom code below. Do not modify anything above.
void userPins() {
    // Change pinMode() in here if needed.
}

void userLoop() {
    // Sample program.
    delay(500);
    digitalWrite(IO2, HIGH);
    delay(500);
    digitalWrite(IO2, LOW);
}