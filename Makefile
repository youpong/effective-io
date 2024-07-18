CXXFLAGS = -std=c++20 -Wall -Wextra --pedantic-errors

TARGET = read

PRODUCER = dd if=/dev/random count=131072 2>/dev/null

all: $(TARGET)
run: $(TARGET)
	@echo "READ BY fgetc()"
	time $(PRODUCER) | ./$(TARGET) -c
	@echo "READ BY std::getline()"
	time $(PRODUCER) | ./$(TARGET) -l
clean:
	rm -f $(TARGET) *.o
$(TARGET): read.o
	$(CXX) -o $@ $^

.PHONY: all clean run