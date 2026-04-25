# AGROFILOS

Automatic Multipurpose Pesticide Sprayer (UGV prototype) for safer and more affordable crop spraying.

AGROFILOS is a school-innovation robotics project focused on reducing farmer exposure to pesticides and physical strain during field spraying. The platform uses a remote-controlled, battery-powered ground vehicle with adjustable spray flow and multi-nozzle coverage.

## Project Status

- Current stable firmware generation: v4.0 (315 MHz RF with RadioHead)
- Prototype stage: self-tested functional prototype
- Intended use: controlled agricultural spraying experiments and demonstrations

## Repository Structure

- `Code/`
- `Code/315Mhz RF/RadioHead/` - current generation firmware (v4.0)
- `Code/315Mhz RF/VirtualWire/` - archived v1.0-v2.0 experiments
- `Code/HC-05/` - archived v3.0 Bluetooth generation
- `Docs/` - project report and technical documentation
- `Materials/` - bill of materials and reference files
- `Blueprints/` - design visuals and slide resources
- `Patent/` - patent-related working files

## Firmware At A Glance

- `Mains_4.0.ino`: machine-side controller (motors, pump, sensing, RF receive)
- `Transmitter_4.0.ino`: remote-side controller (buttons, level selection, RF transmit)
- Command encoding: single-character protocol for speed + flow levels and directional movement

## Safety Note

This repository contains prototype firmware and documentation. Do not deploy in production farming without adding hardware failsafes, emergency stop behavior, enclosure/weatherproofing, and formal field validation.

## Key Documentation

- `Docs/AGROFILOS_Project_Report.pdf`
- `Docs/AGROFILOS_Project_Report.docx`
- `Code/Firmware_Versions.md`
- `Docs/Setup_and_Flashing.md`
- `Code/Code_Audit.md`
- `Materials/BILL.md`

## Credits

Developer: Ayushman Sahoo

Institution: DAV Public School, Kalinga Nagar, Bhubaneswar