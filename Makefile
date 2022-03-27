TARGET= yahtzee
$(TARGET): src/main.c
	cc -o src/$(TARGET) src/main.c
run: $(TARGET)
	./$(TARGET)