#ULTRA BASIC MAKEFILE
TARGET = solve
SOURCES = main.c team.c athlete.c
HEADERS = team.h athlete.h 
OBJECTS =$(SOURCES:.c=.o) 

CXXFLAGS = -O3 -Wall
CXX = gcc

ifeq ($(OS),Windows_NT)     # is Windows_NT on XP, 2000, 7, Vista, 10...
    rm_script := -del /Q /S
	ext := .exe
	run_script := type list.txt | $(TARGET)$(ext)
else
    rm_script := rm -f
	ext :=
	run_script := $(TARGET)$(ext) < list.txt
endif



all: $(TARGET)

run:
	$(run_script)

$(TARGET): $(OBJECTS) 
	$(CXX) $(OBJECTS) -o $(TARGET)


%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo cleaning project...
	$(rm_script) *.o
	$(rm_script) $(TARGET)$(ext)
