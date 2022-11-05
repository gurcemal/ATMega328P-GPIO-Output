/* Arduino Nano GPIO Exaple
   PD3 --> D3 --> Button 1
   PD4 --> D4 --> LED 1
   PB0 --> D8 --> Button 2
   PB1 --> D9 --> LED 1
*/

#define button_1 PD3
#define button_2 PB0
#define led_1 PD4
#define led_2 PB1

bool button1_value, button2_value;
byte portD_value = 0, portB_value = 0;

void setup() {
  Serial.begin(9600);
  DDRD &= (~(1 << button_1));       // 3. bit of portD is false and input for Button_1
  DDRD |= (1 << led_1);             // 4. bit of portD is true and output for Led_1

  DDRB &= (~(1 << button_2));       // 0. bit of portD is false and input for Button_2
  DDRB |= (1 << led_2);             // 1. bit of portD is true and output for Led_2

}

void loop() {
  button1_value = (PIND & (1 << button_1));     // read the 3. bit of PIND port
  button2_value = (PINB & (1 << button_2));     // read the 0. bit of PINB port

  if ( button1_value == 0 ) {
    portD_value |= (1 << led_1);         // set led_1 pin high
  }
  else  {
    portD_value &= (~(1 << led_1));      // set led_1 pin low
    Serial.println("Button 1 is pressed");
  }

  if ( button2_value == 1 ) {
    Serial.println("Button 2 is pressed");
    portB_value |= (1 << led_2);         // set led_2 pin high
  }
  else  {
    portB_value &= (~(1 << led_2));      // set led_2 pin low
  }

  PORTD = portD_value;
  PORTB = portB_value;
}
