CC:=g++
CFLAGS:=
MAIN:=main.cpp
OUT:=wot++
BINDIR:=bin

default: all


all:
	$(CC) $(CFLAGS) -S $(MAIN) -o $(BINDIR)/$(OUT).s
	$(CC) $(CFLAGS) $(MAIN) -o $(BINDIR)/$(OUT)


debug:
	$(CC) $(CFLAGS) -S $(MAIN) -o $(BINDIR)/$(OUT).s
	$(CC) $(CFLAGS) $(MAIN) -Wall -Wextra -g -o $(BINDIR)/$(OUT)


opt:
	$(CC) $(CFLAGS) -S $(MAIN) -Ofast -o $(BINDIR)/$(OUT).s
	$(CC) $(CFLAGS) $(MAIN) -Ofast -o $(BINDIR)/$(OUT)


small:
	$(CC) $(CFLAGS) -S $(MAIN) -Os -o $(BINDIR)/$(OUT).s
	$(CC) $(CFLAGS) $(MAIN) -Os -o $(BINDIR)/$(OUT)



.PHONY: clean
clean:
	rm $(BINDIR)/$(OUT)