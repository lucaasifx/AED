BIN = ./bin
SRC = ./src
DATA = ./data
INCLUDE = ./include
OBJ = ./obj

all: libed app

libed: \
	$(OBJ)/linked_list.o
app:
	gcc $(SRC)/main.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@
run:
	$(BIN)/app
clear:
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*