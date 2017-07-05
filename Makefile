CXXFLAGS = -O2 -g -Wall -fmessage-length=0
OBJS =	Brutforce.o
TARGET = brutforce

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:
	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

run:
	./$(TARGET)