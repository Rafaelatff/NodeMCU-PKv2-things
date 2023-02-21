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

Go to 'File' -> 'Preferences' and add the link: http://arduino.esp8266.com/stable/package_esp8266com_index.json

![boardmanager](https://user-images.githubusercontent.com/58916022/220225087-abf9ed0d-e714-4bdd-8649-76f9353ba558.PNG)

Then go to 'Tools' -> 'Port' and select the 'COM**x**' port that the NodeMCU is connect.

## Code (Digital Output)

To configure a pin as digital output, the function **pinMode** must be used. It uses the following parameters:

![pinMode2](https://user-images.githubusercontent.com/58916022/220225608-b5d9609b-abdd-471f-a8ca-eae3a09bb253.png)

Both parameters are type *uint8_t*, so we will declare the pins as *const uint8_t*:

```c
const uint8_t LED_Verde = D4; // both can be used, 2 (gpio) or D4 (board)
const uint8_t LED_Amarelo = D7;
const uint8_t LED_Vermelho = D3;
const uint8_t Buzzer = D5;
```

Now we can add, inside the 'void setup()', the function *pinMode* that configures the Pins as OUTPUT.

```c
void setup() {
  // put your setup code here, to run once:
  // Configura saídas digitais
  pinMode(LED_Verde,OUTPUT);
  pinMode(LED_Amarelo,OUTPUT);
  pinMode(LED_Vermelho,OUTPUT);
```





