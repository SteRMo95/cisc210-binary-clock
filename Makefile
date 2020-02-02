%.o: %.c
	cc -c %<

objects:
	cc -c *.c

all: objects 
	cc -lm  -o clock *.o

run: all
	./clock.sh | ./clock

clean:
	rm *[^framebuffer].o clock
