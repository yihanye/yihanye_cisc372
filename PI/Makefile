SOURCES = src/pi.c src/pi_main.c
TARGET = pi
CFLAGS = -std=c99 -lm -O2

omp:
	$(CC) -Xpreprocessor -fopenmp -lomp $(SOURCES) -o $(TARGET)
	
acc:
	$(CC) $(SOURCES) $(CFLAGS) -fopenacc -o $(TARGET)

run:
	./$(TARGET) 100000000

clean:
	rm $(TARGET)
