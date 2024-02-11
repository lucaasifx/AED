BIN = ./bin
DATA = ./data
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
INPUT = $(DATA)/input
OUTPUT = $(DATA)/output


all: libed app

libed: \
	$(OBJ)/xavecoding_dlist.o
app:
	gcc $(SRC)/main.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

run:
	$(BIN)/app < $(INPUT)/01.in > $(OUTPUT)/01.out
	$(BIN)/app < $(INPUT)/02.in > $(OUTPUT)/02.out
	$(BIN)/app < $(INPUT)/03.in > $(OUTPUT)/03.out
	$(BIN)/app < $(INPUT)/04.in > $(OUTPUT)/04.out

clear:
	rm -rf $(BIN)/*
	rm -rf $(OBJ)/*