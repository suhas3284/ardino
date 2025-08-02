import time
import RPi.GPIO as GPIO

# Set the GPIO mode to BCM
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

# Pin Setup
pump_pin_0 = 20  # Suction Pump 0 connected to pin 20 (BCM)
pump_pin_1 = 21  # Suction Pump 1 connected to pin 21 (BCM)

# Set both pins as output
GPIO.setup(pump_pin_0, GPIO.OUT)
GPIO.setup(pump_pin_1, GPIO.OUT)

print("pin 20 suction off")
GPIO.output(pump_pin_0, 0)
time.sleep(3)

print("pin 21 air valve off")
GPIO.output(pump_pin_1, 0)
time.sleep(3)

print("pin 20 suction on")
GPIO.output(pump_pin_0, 1)
time.sleep(10)

print("pin 20 suction off")
GPIO.output(pump_pin_0, 0)
time.sleep(3)

print("pin 21 air valve on")
GPIO.output(pump_pin_1, 1)
time.sleep(5)

def activate_pump(pin):
    GPIO.output(pin, 1)  # Turn the pump on

def deactivate_pump(pin):
    GPIO.output(pin, 0)  # Turn the pump off

while True:
	#print("suction activated")
	#activate first pump
	#activate_pump(pump_pin_1)
	#time.sleep(10)
	
	print("suction deactivated")
	deactivate_pump(pump_pin_1)
	time.sleep(10)

#try:
#    while True:
#        # Gripping action
#        print("Gripping... Pumping air...")
#        activate_pump(pump_pin_0)  # Activate pump to grip
#        deactivate_pump(pump_pin_1)  # Deactivate second pump if used
#        time.sleep(3)  # Wait for 3 seconds to simulate gripping
#
#        # Releasing action
#        print("Releasing... Stopping air...")
#        deactivate_pump(pump_pin_0)  # Deactivate pump to release grip
#        deactivate_pump(pump_pin_1)  # Deactivate second pump if used
#        time.sleep(8)  # Wait for 8 seconds
#
#        # Gripping action again
#        print("Gripping... Pumping air...")
#        deactivate_pump(pump_pin_0)  # Deactivate first pump if used
#        activate_pump(pump_pin_1)  # Activate second pump to grip
#        time.sleep(3)  # Wait for 3 seconds to simulate gripping
#
#        # Releasing action
#        print("Releasing... Stopping air...")
#        deactivate_pump(pump_pin_0)  # Deactivate first pump
#        deactivate_pump(pump_pin_1)  # Deactivate second pump
#        time.sleep(8)  # Pause before next loop

#KeyboardInterrupt:
#	print("Program interrupted by user.")

# Clean up GPIO settings
GPIO.cleanup()
