# ==============================
# Makefile for LED Strip project
# ==============================

#Targets
all: build run

build:
	gcc -o main ./LED_driver/main.c ./LED_driver/led_driver.c -I.

run:
	./main

clean:
	rm -f ./main