CC = /usr/bin/g++
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)
CFLAGS = -std=c++11
LDFLAGS =
EXE=bctl

all: $(SRC) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^

clean:
	rm $(OBJ)
  
