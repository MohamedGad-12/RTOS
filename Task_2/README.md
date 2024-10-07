# FreeRTOS Snake Game

A classic Snake game implemented using FreeRTOS, designed to run on QEMU Emulator for ARM architecture.

## Videos

You can find gameplay videos showcasing the project at the following link:

[Gameplay Videos](https://drive.google.com/drive/folders/1ec0S2Njf6rQPxsSqO6VrZqBw8PvzBWFP)

## Build Instructions

### To build the project, navigate to the project directory and run the following commands:

```bash
make
```


### To clean the build files, use:

```bash
make clean
```

## Debugging

### To debug the project using QEMU, use the following commands:

#### Start QEMU in debug mode:

```bash
qemu-system-arm -M lm3s6965evb -m 128M -s -S -nographic -kernel gcc/Snake.axf
```

#### In another terminal, start GDB:

```bash
arm-none-eabi-gdb.exe gcc/Snake.axf
```
#### Connect GDB to QEMU:
```bash
target remote localhost:1234
```

## Running the Game
### To run the Snake game in QEMU, execute the following command:

```bash
qemu-system-arm -M lm3s6965evb -nographic -kernel gcc/Snake.bin
```

*******