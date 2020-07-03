TARGET = sudoku

all: $(TARGET)

$(TARGET) : % : %.cpp
	$(CXX) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: all clean
