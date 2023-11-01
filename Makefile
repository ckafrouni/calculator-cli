CC=gcc
CFLAGS=-g -Wall -Wextra

SRC_DIR=src/code
HEADER_DIR=src/includes
BUILD_DIR=build

EXECUTABLE=$(BUILD_DIR)/calculator
SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
HEADERS=$(wildcard $(HEADER_DIR)/*.h)

all: $(BUILD_DIR) $(EXECUTABLE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


.PHONY: clean run install uninstall 

clean:
	rm -rf $(BUILD_DIR)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

install: $(BUILD_DIR) $(EXECUTABLE)
	cp $(EXECUTABLE) $(HOME)/.local/bin

uninstall:
	rm -f $(HOME)/.local/bin/$(notdir $(EXECUTABLE))