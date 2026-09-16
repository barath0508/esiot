from gpiozero import LED
from time import sleep

led = LED(18)

while True:
    led.on()
    sleep(1)
    led.off()
    sleep(1)

#next
from gpiozero import DigitalInputDevice
from time import sleep

ir = DigitalInputDevice(17)

while True:
    if ir.value == 0:
        print("Object Detected")
    else:
        print("No Object")
    sleep(1)

#next
from gpiozero import DistanceSensor
from time import sleep

sensor = DistanceSensor(echo=27, trigger=17)

while True:
    print(round(sensor.distance * 100, 2), "cm")
    sleep(1)
