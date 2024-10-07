#Eng. Mohamed Gamal Saleh Mohamed

#---------------------------------------------------------------------#

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3
Deg=-mthumb -g #-gdwarf-2 AsOBJ 
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
File=UART0

#-----------------------------------------------------------------------#

all:$(File).bin

#startup.s: startup.c
	#$(CC)gcc.exe -S $(Deg) $(CFLAGS) $< -o $@ 

#startup.o: startup.s
	#$(CC)as.exe $(Deg) $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe -c $(Deg) $(INCS) $(CFLAGS) $< -o $@ 

$(File).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -g -T linker_script.ld -Map=output.map $(LIBS) $(OBJ) $(AsOBJ) -o $@  

$(File).hex: $(File).elf
	$(CC)objcopy -O ihex $< $@

$(File).bin:$(File).hex	
	$(CC)objcopy -I ihex $(File).hex -O binary $(File).bin
	@echo "============Bulid_Done============"

#-----------------------------------------------------------------------#

debug: $(File).elf
	$(CC)strip.exe -g -S -d $<
	@echo "============rm_degig_Done============"

#-----------------------------------------------------------------------#

clean_all:
	rm *.o *.elf *.bin *.hex *.map  #*.s
	@echo "============rm_all============"	

#-----------------------------------------------------------------------#

clean:
	rm *.elf *.bin *.hex *.map  #*.s
	@echo "============rm============"	

#-----------------------------------------------------------------------#