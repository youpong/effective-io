CXXFLAGS = -std=c++20 -Wall -Wextra --pedantic-errors

TARGET = read

PRODUCER = dd if=/dev/random count=131072

all: $(TARGET)
run: $(TARGET) data
	@echo "READ BY fgetc()"
	time ./$(TARGET) -c <data
	@echo "READ BY std::getline()"
	time ./$(TARGET) -l <data
clean:
	rm -f $(TARGET) *.o data
$(TARGET): read.o
	$(CXX) -o $@ $^
data:
	$(PRODUCER) > data

.PHONY: all clean run