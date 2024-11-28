CC = g++
CFLAGS = -Wall

BIN = production
OUT = solution.lp

TEST = example

all:
	$(CC) $(CFLAGS) main.cpp -o $(BIN)

	./$(BIN) $(OUT) < $(TEST)
	
	@printf "File saved in "
	@readlink -f $(OUT)

clean:
	rm -f $(BIN) $(OUT)
