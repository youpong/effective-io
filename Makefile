CXXFLAGS = -std=c++20 -Wall -Wextra --pedantic-errors

TARGET = read
all: $(TARGET)
run: $(TARGET)
	time dd if=/dev/random count=131072 | ./$(TARGET) -c
	time dd if=/dev/random count=131072 | ./$(TARGET) -l
clean:
	rm -f $(TARGET) *.o
$(TARGET): read.o
	$(CXX) -o $@ $^

.PHONY: all clean run