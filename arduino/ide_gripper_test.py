import smbus2
import time

bus = smbus2.SMBus(1)
ARDUINO_ADDR = 0x08

time.sleep(3)  # Give Arduino time to boot

try:
    while True:
        bus.write_byte(ARDUINO_ADDR, ord('A'))
        print("Sent: A")
        time.sleep(2)
except KeyboardInterrupt:
    print("Stopped")

