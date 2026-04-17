🌡️ Smart Ambient Risk Monitor
📌 Overview

This Arduino project monitors temperature and light and shows a risk level using an RGB LED.

🧠 Summary (What is happening?)
The system reads temperature (LM35) and light level (LDR)
A potentiometer sets a temperature threshold
Based on light + temperature:
Bright → always Safe (Green)
Dark → temperature decides:
Low → Safe (LED OFF)
Medium → Warning (Blue)
High → Danger (Red)

👉 So, the system is doing:
Sensing → Decision → Visual Output

🧰 Components
Arduino Uno
LM35
Photoresistor (LDR)
Potentiometer
RGB LED
10kΩ resistor
🔌 Connections
LM35 → A0;
Pot → A1;
LDR → A2;
RGB → 9 (R), 10 (G), 11 (B)
▶️ Run
Upload code
Open Serial Monitor
Observe LED changes
