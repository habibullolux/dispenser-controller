import serial
import time

arduino_ports = ['COM3', 'COM4', 'COM5', 'COM6']
arduinos = [serial.Serial(port, baudrate=9600, timeout=1) for port in arduino_ports]

def find_ready_dispenser():
    """Check all dispensers and return the first ready one."""
    for index, arduino in enumerate(arduinos):
        arduino.write("check_ready\n".encode())
        response = arduino.readline().decode().strip()
        if response.startswith("Dispenser"):
            print(response)  # Log which dispenser is ready
            dispenser_id = int(response.split()[1])  # Extract dispenser number
            return index, dispenser_id
    print("No dispensers are ready.")
    return None, None

def assign_order_to_dispenser(arduino_index, dispenser_id):
    """Assign an order to the specified dispenser."""
    arduino = arduinos[arduino_index]
    arduino.write(f"assign_order {dispenser_id}\n".encode())
    response = arduino.readline().decode().strip()
    print(response)

def process_order():
    """Main function to process an order."""
    print("Checking for available dispensers...")
    arduino_index, dispenser_id = find_ready_dispenser()
    if arduino_index is not None:
        print(f"Assigning order to Arduino {arduino_index + 1}, Dispenser {dispenser_id}")
        assign_order_to_dispenser(arduino_index, dispenser_id)
    else:
        print("Error: No dispensers are available.")

while True:
    input("Press Enter to process a new order...")
    process_order()
