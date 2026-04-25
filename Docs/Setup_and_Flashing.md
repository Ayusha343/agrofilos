# Setup And Flashing Guide

## Hardware Required

- 2 x Arduino Nano (or compatible)
- 315/433 MHz ASK RF transmitter and receiver modules
- Motor driver board (dual channel)
- 12V drive motors and 12V pump
- Voltage divider networks for battery sensing
- LEDs and push buttons as per pin maps

## Arduino IDE Preparation

1. Install Arduino IDE.
2. Open Library Manager and install `RadioHead`.
3. Select board: Arduino Nano.
4. Select processor compatible with your Nano clone/original.
5. Select proper COM port.

## Flash Order

1. Flash transmitter firmware:
   - `Code/315Mhz RF/RadioHead/Transmitter_4.0/Transmitter_4.0.ino`
2. Flash main unit firmware:
   - `Code/315Mhz RF/RadioHead/Mains_4.0/Mains_4.0.ino`
3. Power cycle both units.
4. Observe serial monitor and status LEDs.

## Basic Bring-Up Checklist

- Confirm RF modules are wired to expected pins in source.
- Confirm motor driver enable pins are PWM-capable pins used in firmware.
- Confirm battery divider ratios match firmware constants.
- Verify pump PWM output path and MOSFET stage before connecting pesticide lines.

## Safe Dry-Run Sequence

1. Run without pesticide (water only).
2. Raise wheels off ground for first motor-direction checks.
3. Send each direction command and verify wheel behavior.
4. Step through speed and flow levels.
5. Verify low-battery indicator by simulating threshold.
6. Verify water-level LED behavior at multiple fluid levels.

## Known Improvement Needed

Add RF-loss failsafe in `Mains_4.0.ino` so motors and pump stop if no valid command arrives within a timeout window.
