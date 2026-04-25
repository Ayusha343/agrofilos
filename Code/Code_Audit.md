# Code Audit Snapshot (April 2026)

## Scope

Audit review focused on Arduino firmware files in `Code/`.

## High Priority Findings

1. `Code/315Mhz RF/VirtualWire/Dummy/TX 1.0.ino`
- Syntax issue in `Serial.begin` line prevents compile.

2. `Code/HC-05/Main_3.0/Main_3.0.ino`
- Multiple direct `bilu.read()` calls in conditional chain can consume bytes and break command decoding.

3. `Code/HC-05/Transmitter_3.0/Transmitter_3.0.ino`
- Similar read-pattern issue makes command handling unreliable.

4. `Code/315Mhz RF/RadioHead/Mains_4.0/Mains_4.0.ino`
- No explicit RF-loss watchdog timeout to force stop on signal loss.

## Medium Priority Findings

1. `Code/315Mhz RF/RadioHead/Mains_4.0/Mains_4.0.ino`
- Pairing LED logic appears incomplete (`i` starts at 3 and does not change).

2. `Code/315Mhz RF/RadioHead/*`
- Return value from `rf315.init()` is not checked.

## Duplicates And Historical Copies

- Duplicate v2.0 transmitter and main files exist in SSD and non-SSD folders.
- `Transmitter_4.0.txt` appears to be a duplicate of `Transmitter_4.0.ino` content.

## Recommendation

Treat v4.0 as the active branch and create a cleanup pass that:

- Adds failsafe timeout and initialization checks
- Removes accidental duplicates (or marks as archive)
- Documents pin maps and thresholds near firmware source
