# Firmware Versions

## Purpose

This document maps firmware generations and clarifies which folders are active versus archival.

## Version Matrix

| Version | Communication | Primary Files | Status |
|---|---|---|---|
| v1.0 | VirtualWire ASK | `Code/315Mhz RF/VirtualWire/Dummy/TX 1.0.ino`, `Code/315Mhz RF/VirtualWire/Dummy/RX 1.0.ino` | Archive |
| v2.0 | VirtualWire ASK | `Code/315Mhz RF/VirtualWire/Main Unit/Main_2.0/Main_2.0.ino`, `Code/315Mhz RF/VirtualWire/Transmiter/Transmiter2.0/Transmiter2.0.ino` | Archive |
| v3.0 | HC-05 Bluetooth | `Code/HC-05/Main_3.0/Main_3.0.ino`, `Code/HC-05/Transmitter_3.0/Transmitter_3.0.ino` | Archive |
| v4.0 | RadioHead RH_ASK | `Code/315Mhz RF/RadioHead/Mains_4.0/Mains_4.0.ino`, `Code/315Mhz RF/RadioHead/Transmitter_4.0/Transmitter_4.0.ino` | Current |

## Recommended Baseline

Use only v4.0 for active testing and demonstrations.

## Archive Notes

- The VirtualWire and HC-05 paths are useful for design history but not production-ready.
- Some archive files are duplicated across SSD and non-SSD paths; keep them for traceability unless a cleanup branch is created.
