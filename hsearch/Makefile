src:=$(wildcard *.c)
obj:=$(src:.c=.o)
.PHONY: all clean

all: hsearch
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

hsearch: $(obj)
	$(CC) $(LDFLAGS) -o $@ $^ 

clean:
	rm -f *~ *.o hsearch.x hsearch

