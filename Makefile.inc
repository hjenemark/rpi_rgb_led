CC := gcc

CFLAGS := -Wall -c -g -I$(INC_DIR)
LFLAGS := -Wall -I$(INC_DIR)

OBJS:= $(CFILES:.c=.o)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

$(PROJECT): $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@

all: $(PROJECT)


clean: 
	rm -f $(OBJS)
	rm -f $(PROJECT)
