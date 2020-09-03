# # Variable spéciales
# # $@	Le nom de la cible
# # $<	Le nom de la première dépendance
# # $^	La liste des dépendances
# # $?	La liste des dépendances plus récentes que la cible
# # $*	Le nom du fichier sans suffixe

CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
# LDFLAGS =
EXEC = gol.exe
BIN_PATH = bin
BIN_INT_PATH = bin-int
SRC_PATH = src

SRC := $(wildcard $(SRC_PATH)/*.c)
OBJ := $(SRC:$(SRC_PATH)/%.c=$(BIN_INT_PATH)/%.o)

.PHONY: clean mrproper dir all

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $(BIN_PATH)/$(EXEC) $^

$(BIN_INT_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -o $@ $(CFLAGS) $<

dir:
	@mkdir $(BIN_PATH)
	@mkdir $(BIN_INT_PATH)

clean:
	del $(BIN_INT_PATH)\*.o

mrproper: clean
	del $(BIN_PATH)\$(EXEC)