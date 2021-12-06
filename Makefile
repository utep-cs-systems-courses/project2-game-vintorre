COMMON_OBJECTS = 
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I h
LDFLAGS = -L/opt/ti/msp430_gcc/include

CC = msp430-elf-gcc
AS = msp430-elf-as

all: button.elf

button.elf: main.o led.o state_manager.o buzzer.o switches.o wdInterruptHandler.o p2_interrupt_handler.o  
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf *.c~ *.h~

main.o: led.h switches.h buzzer.h state_manager.h

led.o: led.h switches.h

state_manager.o: state_manager.h switches.h buzzer.h led.h

buzzer.o: buzzer.h

switches.o: switches.h state_manager.h

wdInterruptHandler.o: led.h state_manager.h

p2_interrupt_handler.o: switches.h

