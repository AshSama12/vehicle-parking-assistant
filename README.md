# Vehicle Parking and Reversing Assistant 🚗

This Arduino-based **Vehicle Parking or Reversing Assistant** project measures the distance to obstacles using an **Ultrasonic Sensor** and provides visual feedback using LEDs and an LCD display. It also integrates motor control for safe movement of the vehicle.

---

## 🚀 **Project Overview**
- **Distance Measurement**: Uses an **HC-SR04 Ultrasonic Sensor** to measure the distance to an object in front of the vehicle.
- **Alerts**:
  - **Red LED**: DANGER - Stop the vehicle immediately (distance < 50 cm).
  - **Yellow LED**: Maintain distance (exactly 50 cm).
  - **Green LED**: Safe to move (distance > 50 cm).
- **LCD Display**: Shows real-time distance and status messages.
- **Motor Control**: Stops or runs motors based on the measured distance.

---

## 📷 **Components Used**
1. **Arduino UNO**
2. **HC-SR04 Ultrasonic Sensor** (for distance measurement)
3. **I2C 16x2 LCD Display** (for output)
4. **3 LEDs**:
   - Red (DANGER)
   - Yellow (Warning)
   - Green (Safe to move)
5. **2 DC Motors** (for movement)
6. **Breadboard** and **Jumper Wires**

---

## 🛠️ **Circuit Connections**

### Ultrasonic Sensor:
| **Pin**   | **Arduino Pin** |
|-----------|-----------------|
| VCC       | 5V              |
| TRIG      | 12              |
| ECHO      | 11              |
| GND       | GND             |

### LEDs:
| **LED**    | **Arduino Pin** |
|------------|-----------------|
| Red LED    | 8               |
| Yellow LED | 9               |
| Green LED  | 10              |

### Motors:
| **Motor**    | **Arduino Pin** |
|--------------|-----------------|
| Motor 1      | 2, 3            |
| Motor 2      | 4, 5            |

---

## 🔌 **How to Run the Project**

1. **Connect the components** as per the circuit diagram provided above.
2. **Upload the code** to the Arduino UNO using the Arduino IDE.
3. Open the **Serial Monitor** (at 9600 baud rate) to observe messages.
4. Observe the LCD display, LEDs, and motor behavior based on distance.

---

## 📄 **Code Explanation**

The Arduino code:
- Initializes the ultrasonic sensor, LCD, and pins.
- Continuously measures the distance using the **HC-SR04 sensor**.
- Based on the distance:
  - Updates the **LCD display**.
  - Controls **LED indicators**.
  - Stops or runs **motors**.
- Includes two helper functions:
  - `stopMotors()` - Stops all motors.
  - `runMotors()` - Moves motors forward.

---

## 🎯 **Behavior**

| **Distance** | **LED Status** | **Motor Action**  | **LCD Message**      |
|--------------|----------------|-------------------|----------------------|
| < 50 cm      | Red ON         | Stop              | "DANGER!!!"          |
| = 50 cm      | Yellow ON      | Stop              | "Maintain Dist."     |
| > 50 cm      | Green ON       | Move Forward      | "Safe to Move"       |

---

## 💾 **Dependencies**
- `Wire.h` and `LiquidCrystal_I2C.h` libraries for LCD display.

To install the libraries:
1. Open Arduino IDE.
2. Go to **Sketch → Include Library → Manage Libraries**.
3. Search for and install:
   - `LiquidCrystal I2C`
   - `Wire`




