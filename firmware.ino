const int LED1 = D0;
const int LED2 = D1;
const int LED3 = D2;
const int S1 = D3;
const int S2 = D4;
const int S3 = D5;
const int IO2 = D8;
const int IO3 = D10;
const int IO4 = D9;
bool ControlIO2 = false;
bool ControlIO3 = false;
bool ControlIO4 = false;

void setup() {
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(S1, INPUT);
    pinMode(S2, INPUT);
    pinMode(S3, INPUT);
}

void loop() {
    if (digitalRead(S1) == HIGH && ControlIO2 == false) {
        delay(3000);
        if (digitalRead(S1) == HIGH) {
            ControlIO2 = true;
            digitalWrite(LED1, HIGH);
            delay(1000);
            digitalWrite(LED3, LOW);
        }

    } else if (digitalRead(S2) == HIGH && ControlIO3 == false) {
        delay(3000);
        if (digitalRead(S2) == HIGH) {
            ControlIO3 = true;
            digitalWrite(LED2, HIGH);
            delay(1000);
            digitalWrite(LED3, LOW);
        }

    } else if (digitalRead(S3) == HIGH && ControlIO4 == false) {
        delay(3000);
        if (digitalRead(S3) == HIGH) {
            ControlIO4 = true;
            digitalWrite(LED3, HIGH);
            delay(1000);
            digitalWrite(LED3, LOW);
        }
    }

    if (digitalRead(S1) == HIGH && ControlIO2 == true) {
        pinMode(IO2, OUTPUT);
        digitalWrite(IO2, HIGH);

    } else if (digitalRead(S2) == HIGH && ControlIO3 == true) {
        pinMode(IO3, OUTPUT);
        digitalWrite(IO3, HIGH);

    } else if (digitalRead(S3) == HIGH && ControlIO4 == true) {
        pinMode(IO4, OUTPUT);
        digitalWrite(IO4, HIGH);
    }
}
