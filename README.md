# nodeMCU-Pk2v2
nodeMCU connected to PK2v2 from wisstek lab.

## Hardware

Basically a NodeMCU is:

* esp12e (wifi module) + ESP8266 (uC from Espressif) = NodeMCU

NodeMCU is an open hardware and has its contents to assist at the [NodeMCU repositorie](https://github.com/nodemcu).

![pinout](https://user-images.githubusercontent.com/58916022/220213432-7506cd64-24e6-46b8-ab33-38d8ec6e18b0.PNG)

To config the digital pins, as an example to the green LED connected to D4 pin, it is possible to use both ways:

```c
const byte LED_Green = D4; // D4 according to board connection
const byte LED_Verde = 2; // just the number 2, from GPIO pin connection
```

# IDE configuration

Download the Arduino IDE by clicking it [here](https://www.arduino.cc/en/software).

## Code

