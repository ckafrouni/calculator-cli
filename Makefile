CC=gcc
CFLAGS=-g -Wall -Wextra

SRC_DIR=src/code
HEADER_DIR=src/includes
BUILD_DIR=build

EXECUTABLE=calculator
PROG=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))

all: $(BUILD_DIR) $(EXECUTABLE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

$(EXECUTABLE): $(PROG)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


.PHONY: clean run install uninstall all

clean:
	rm -rf $(BUILD_DIR)

run: $(EXECUTABLE)
	./$(BUILD_DIR)/$(EXECUTABLE)

install: $(EXECUTABLE)
	cp $(BUILD_DIR)/$(EXECUTABLE) $(HOME)/.local/bin

uninstall:
	rm -f $(HOME)/.local/bin/$(EXECUTABLE)