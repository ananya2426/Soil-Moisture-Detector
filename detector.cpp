#include <iostream>
#include <chrono>

int getSoilMoisture() {
    static int moisture = 800;  // Initial moisture value
    moisture -= 50;  // Simulate a gradual decrease in moisture
    if (moisture < 0) moisture = 800;  // Reset moisture if it goes below 0
    return moisture;
}

void controlDevice(int pin, bool state) {
    std::string status = state ? "ON" : "OFF";
    if (pin == 8) std::cout << "LED: " << status << std::endl;
    if (pin == 9) std::cout << "Buzzer: " << status << std::endl;
}

void setup() {
    std::cout << "System ready to monitor soil moisture...\n";
}

void loop() {
    int moistureLevel = getSoilMoisture();  // Simulate reading soil moisture
    std::cout << "Soil Moisture Level: " << moistureLevel << std::endl;

    if (moistureLevel < 500) {  // If soil is dry
        controlDevice(8, true);  // Turn on LED
        controlDevice(9, true);  // Turn on Buzzer
    } else {
        controlDevice(8, false); // Turn off LED
        controlDevice(9, false); // Turn off Buzzer
    }

    // Simulate a delay (using a simple loop instead of actual thread sleep)
    for (int i = 0; i < 100000000; ++i);  // A simple busy-wait loop to simulate time passing
}

int main() {
    setup();
    while (true) {
        loop();  // Continuously monitor moisture level
    }
    return 0;
}
