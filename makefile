CC = gcc
# CFLAGS = -c -Wall -Werror -Wextra
CFLAGS = -c

CPPFLAGS = -I C:\vclib\i686-w64-mingw32\include\SDL2
LDFLAGS = -L C:\vclib\i686-w64-mingw32\lib
LDLIBS = -lmingw32 -lSDL2main -lSDL2

EXEC = gol.exe
BIN_PATH = bin
BIN_INT_PATH = bin-int
SRC_PATH = src

SRC := $(wildcard $(SRC_PATH)/*.c)
OBJ := $(SRC:$(SRC_PATH)/%.c=$(BIN_INT_PATH)/%.o)

.PHONY: clean mrproper dir all

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $(BIN_PATH)/$(EXEC) $^ $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

$(BIN_INT_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -o $@ $(CFLAGS) $< $(CPPFLAGS) $(LDFLAGS)

dir:
	@mkdir $(BIN_PATH)
	@mkdir $(BIN_INT_PATH)

clean:
	del $(BIN_INT_PATH)\*.o

mrproper: clean
	del $(BIN_PATH)\$(EXEC)