// #include <Arduino.h>

// #include "HX711.h"

// HX711 loadcell;

// const int LOADCELL_DOUT_PIN = 4;
// const int LOADCELL_SCK_PIN = 18;

// // 2. Adjustment settings
// const long LOADCELL_OFFSET = 50682624;
// const long LOADCELL_DIVIDER = 5895655;

// void setup() {
//     Serial.begin(921600);

//     loadcell.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
//     loadcell.set_scale(LOADCELL_DIVIDER);
//     loadcell.set_offset(LOADCELL_OFFSET);
// }

// void loop() {
//     Serial.print("Weight: ");
//     Serial.println(loadcell.get_units(10), 2);

//     delay(10);
// }
