Industrial Safety Monitoring and Emergency Shutdown System Using LPC2129
An embedded systems project using the LPC2129 ARM7 microcontroller
for industrial safety monitoring and motor shutdown control. The system
uses an IR sensor, LED indication, UART communication with
HyperTerminal, a manual motor-OFF switch using an external
interrupt, and an L293D motor driver to control a DC motor.
Features
IR sensor interfacing: Reads the output of the connected IR
sensor.
LED indication: Provides visual status indication.
UART communication: Transmits system messages to a computer.
HyperTerminal monitoring: Displays serial messages from the
microcontroller.
External interrupt: Detects activation of the manual switch.
DC motor control: Uses the L293D motor driver to interface the
LPC2129 with the motor.
Manual motor shutdown: Executes the programmed motor-OFF logic
when the switch event is detected.
Hardware and Software Requirements
Hardware
LPC2129 ARM7 microcontroller / development board
IR sensor module
LED with a suitable current-limiting resistor
Manual switch connected to an external interrupt input
L293D motor driver IC
DC motor compatible with the L293D voltage and current ratings
Compatible UART-to-USB/serial interface
Regulated power supply and connecting wires
Software
Embedded C
Keil µVision or the compatible toolchain used for the project
Flash Magic or a compatible programming tool
HyperTerminal or another serial-terminal application
Working Principle
IR sensor input: The LPC2129 reads the output of the IR sensor.
Condition processing: The firmware evaluates the input and
executes the programmed response.
LED indication: The LED indicates the status defined in the
firmware.
UART messages: The controller transmits status or event messages
over UART, which are displayed in HyperTerminal.
Manual motor-OFF request: Activating the manual switch triggers
the configured external interrupt.
Motor shutdown: The interrupt-handling logic changes the control
signals sent to the L293D so the motor is stopped according to the
implemented firmware.
The exact sensor polarity, LED behaviour, UART messages, interrupt
trigger, and motor-control sequence depend on the source code.
System Block Diagram
``` text
              +----------------+
              |    IR Sensor   |
              +--------+-------+
                       |
                       v
              +----------------+
              |    LPC2129     |
              |   ARM7 MCU     |
              +--+----+----+---+
                 |    |    |
                 |    |    +<---- Manual Switch
                 |    |           (External Interrupt)
                 |    |
                 |    +------ UART TX ------> HyperTerminal
                 |
                 +------ LED Indicator
                 |
                 +------ Motor Control Signals
                            |
                            v
                     +-------------+
                     |    L293D    |
                     | Motor Driver|
                     +------+------+
                            |
                            v
                         DC Motor
```
This is a conceptual diagram. Confirm actual pin assignments and driver
connections from the project source code and circuit.
UART and HyperTerminal
UART provides serial communication between the LPC2129 and the computer.
HyperTerminal receives and displays messages transmitted by the
microcontroller.
Connect the controller's UART TX signal to the RX input of a
compatible serial interface.
Connect the required ground reference.
Open HyperTerminal or another serial-terminal program.
Select the correct COM port.
Set the baud rate and serial format to match the firmware.
Reset or run the microcontroller and observe the messages.
Important: Use a UART interface with compatible logic levels. Do not
connect an RS-232 voltage-level port directly to the microcontroller's
logic-level UART pins.
External Interrupt and Motor Shutdown
The manual switch is connected to an LPC2129 external interrupt input.
When the configured interrupt event occurs, the processor executes the
corresponding interrupt service routine (ISR). The interrupt-handling
logic changes the motor-control signals sent to the L293D, requesting
the motor to stop.
Check that the external interrupt pin and trigger are configured
correctly, the switch has a suitable pull-up or pull-down arrangement,
switch bounce is handled where necessary, and the L293D control signals
reach the intended motor-OFF state.
Getting Started
Clone or download this repository.
Review the source files for the program entry point, pin
definitions, UART settings, external interrupt configuration, and
L293D control logic.
Open the project in the supported IDE/toolchain and confirm the
LPC2129 target settings.
Build the firmware and resolve any build errors.
Connect the IR sensor, LED, manual switch, UART interface, L293D,
and motor according to the actual circuit.
Check the L293D supply, motor voltage/current requirements, and
common ground before powering the circuit.
Flash the firmware using a compatible programming tool.
Open HyperTerminal with serial settings matching the firmware and
test the system under controlled conditions.
Testing and Safety
Test the IR sensor input and LED indication separately.
Confirm that UART messages appear correctly in HyperTerminal.
Test the external interrupt switch and verify the expected motor-OFF
response.
Verify the L293D supply and motor current requirements; do not
exceed the IC's ratings.
Disconnect power before changing wiring, and secure the motor during
testing.
Do not rely on this educational prototype as the sole safety
mechanism for industrial machinery. Real industrial emergency-stop
systems require appropriately engineered and independently validated
safety hardware.
Applications
ARM7 and Embedded C learning
IR sensor interfacing
UART serial communication and debugging
External interrupt programming
DC motor control using the L293D
Demonstration of manual motor shutdown logic
Future Improvements
Add fault/event logging with timestamps.
Add more industrial sensors if required.
Improve fault detection and recovery handling.
Document exact L293D pin connections and the motor-control truth
table.
Validate the design against defined safety requirements before
real-world deployment.
Author
Akash S
GitHub: Akash-1414
Disclaimer
This project is intended for educational and prototyping purposes.
Verify all wiring, firmware behaviour, and motor-control circuitry
before powering the system. It is not a certified industrial safety
system.
