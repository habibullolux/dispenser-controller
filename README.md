<<<<<<< HEAD
# dispenser-controller
This project is a system for automating the control of multiple dispensers using Arduino and Adafruit Motor Shields. It integrates with a UTNServer ProMax hub to connect multiple Arduinos to a central laptop, enabling seamless management through a Python-based command orchestrator.
=======
# Dispenser Controller System

## Short Description

This project automates the control of multiple dispensers using Arduino and Adafruit Motor Shields. It integrates with a UTNServer ProMax hub to connect multiple Arduinos to a central laptop, enabling seamless management through a Python-based command orchestrator.

## Features

- **Multi-Dispenser Management**: Supports up to 4 dispensers, each controlled by an Arduino and an Adafruit Motor Shield.
- **Networked Connection**: Uses UTNServer ProMax for USB-over-IP to connect all Arduinos to a single laptop.
- **Centralized Control**: A Python script automates tasks like checking dispenser readiness, assigning orders, and handling errors.
- **Arduino Integration**: Dispensers are controlled using simple commands via serial communication.
- **Scalable Design**: Easily expandable to add more dispensers or features.

## How It Works

1. **Order Received**: The system confirms that an order has been received.
2. **Dispenser Check**: It checks the readiness of each dispenser.
3. **Order Assignment**: Assigns the order to an available dispenser.
4. **Task Execution**: Operates the selected dispenser to complete the task.

## Technology Stack

- **Arduino**: Used to control the motors via Adafruit Motor Shields.
- **UTNServer ProMax**: Facilitates USB-over-IP communication to connect multiple Arduinos.
- **Python**: Central script to orchestrate dispenser operations.
- **Adafruit Motor Shield Library**: For motor control.


### Hardware Requirements

- 4 Arduinos with Adafruit Motor Shields.
- UTNServer ProMax hub.
- USB cables for each Arduino.
- Dispensers connected to the motor shield outputs.

### Software Requirements

- Arduino IDE for programming the Arduinos.
- Python 3.x installed on the laptop.
- UTNServer client software installed and configured.

### Steps to Set Up

1. **Prepare the Arduino Code**:
    - Upload the provided Arduino sketch to each Arduino.
    - Ensure each Arduino is assigned to control a specific dispenser.

2. **Connect to UTNServer**:
    - Plug each Arduino into the UTNServer ProMax hub.
    - Use the UTNServer client to map each Arduino to a virtual COM port.

3. **Run the Python Script**:
    - Clone this repository.
    - Run the `dispenser_controller.py` script.
    - Use the script to manage and monitor dispensers.
    
>>>>>>> master
