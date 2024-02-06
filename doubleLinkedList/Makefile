BIN = ./bin
DATA = ./data
OBJ = ./obj
SRC = ./src
INCLUDE = ./include


all: libed app

libed: \
	$(OBJ)/dlinkedlist.o
app:
	gcc $(SRC)/main.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

run:
	$(BIN)/app

clear:
	rm -rf $(BIN)/*
	rm -rf $(OBJ)/*