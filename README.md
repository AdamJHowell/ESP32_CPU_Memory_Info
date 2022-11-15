# ESP32_CPU_Memory_Info

A sketch that gathers ESP32 CPU and memory info, and prints that to the serial port.  
This program will continuously output the stats, so it can be easily incorporated into existing code to monitor changes as your program executes.

Example output:

```
Source file: C:\ESP32_CPU_Memory_Info\ESP32_CPU_Memory_Info.ino
ESP32 Chip model: ESP32-D0WDQ6
  Revision: 3
  Core count: 2
  Chip ID: 381348
  Frequency: 240
  Cycle count: 1002386537
  SDK version: v4.4.2
Heap: 
  Total: 363804
  Used: 25300
  Free: 338504
  Largest block: 118772
  Minimum free since boot: 333112
Flash: 
  Total: 16777216
  Speed: 80000000
Sketch: 
  Size: 264336
  Free: 1310720
PSRAM: 
  Total: 4192139
  Used: 0
  Free: 4192139
  Largest block: 4128756
  Minimum free since boot: 4192139
Next printout in 20 seconds.
```
