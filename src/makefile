CFLAGS =-g -O3

all: tokenizer gui tester history

tokenizer.o: tokenizer.h
tester.o: tokenizer.h history.h
gui.o: tokenizer.h history.h
history.o: history.h

tokenizer: tokenizer.h
	cc -o $@ $^ $(CFLAGS)
tester: tokenizer.h history.h
	cc -o $@ $^ $(CFLAGS)
gui: tokenizer.h history.h
	cc -o $@ $^ $(CFLAGS)
history: history.h
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o tokenizer
	rm -f *.o gui
	rm -f *.o tester
	rm -f *.o history


