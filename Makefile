CC = gcc
CFLAGS = -g
TARGET = l_list_ex
SOURCES = l_list.c l_list_ex.c
OBJ = $(patsubst %.c,%.o,$(SOURCES))

$(TARGET):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)
	rm *.o

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
