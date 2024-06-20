CC = gcc

TARGET = timer 

SRC_DIR = ./src
BUILD_DIR = ./build

SRCS = $(shell find $(SRC_DIR) -name "*.c") 
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# CFLAGS = $(shell pkg-config --cflags )
# LDFLAGS = $(shell pkg-config --libs )

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

