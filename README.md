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
```

Now we can add, inside the 'void setup()', the function *pinMode* that configures the pin MODE as OUTPUT. The available MODE configurations are: SPECIAL, FUNCTION_0, OUTPUT, OUTPUT_OPEN_DRAIN, INPUT, INPUT_PULLUP, WAKEUP_PULLUP and WAKEUP_PULLDOWN. This function and many others can be found at 'code_esp8266_wiring_digital.cpp'.

**NOTE: the code inside 'void setup()' only runs one time right after reseting the board.**

```c
void setup() {
  // put your setup code here, to run once:
  // Configuring the digital outputs
  pinMode(LED_Verde,OUTPUT);
  pinMode(LED_Amarelo,OUTPUT);
  pinMode(LED_Vermelho,OUTPUT);
}
```

Then, in the 'void loop()' we add the code that configure the pin output logic level (0 - low and 1 - high).

```c
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_Verde, HIGH);
  delay(1000); // 1000 mili-second = 1 second
  digitalWrite(LED_Verde,LOW);
  delay(1000); // 1 second
}
```

## Code (Digital Input)

We declare the variable tecla with type *const uint8_t* to use in the *pinMode* function.

```c
const uint8_t tecla = D0;
```

Inside the 'void setup()', we use again the function *pinMode* to configure the pin MODE as INPUT.

```c
  // Configuring the digital inputs
  pinMode(tecla,INPUT); // 10k pull-up
```

And in the 'void loop()' we add the code to read the input pin status.

```c
  if(digitalRead(tecla)== LOW){
    digitalWrite(LED_Vermelho,HIGH);
  }
  else {
    digitalWrite(LED_Vermelho,LOW);
  }
```

## Code (Analog Output)

We declare the variable Buzzer with type *const uint8_t* to use in the *analogWrite* function.

```c
const uint8_t Buzzer = D5;
```
No initialization need to be done, so we just added the code inside 'void loop()'. To help to visualizate the results, two *for* loops are added, that will slowly increase/decrease the bright of the LED.

**Note: the last parameter of *analogWrite* receiver the parameter *val* with type  *int*. On Arduino IDE *int* is only 8 bits long.**

```c
  for (int i = 0; i <=255; i++){
    analogWrite(LED_Amarelo,i);
    //analogWrite(Buzzer,i);
    delay(10);
  }

  for (int i = 255; i >= 0 ; i--){
    analogWrite(LED_Amarelo,i);
    //analogWrite(Buzzer,i);
    delay(10);
  } 
```
