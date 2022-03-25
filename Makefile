TARGET= yahtzee
$(TARGET): main.c
	cc -o $(TARGET) main.c
run: $(TARGET)
	./$(TARGET)