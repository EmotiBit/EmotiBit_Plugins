#include "alg01.h"  // Include the header file from the 'src' folder

Rounder rounder;

void setup() {
    Serial.begin(9600);
    double num = 4.7;
    int rounded = rounder.round(num);  // Use the 'Rounder' class to round a number
    Serial.print("Rounded value of ");
    Serial.print(num);
    Serial.print(" is: ");
    Serial.println(rounded);
}

void loop() {
    // Empty loop
}
