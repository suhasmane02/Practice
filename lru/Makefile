CC = g++
CFLAGS = -Wall -g
TARGET = lru
SRCS = lru.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@  $(OBJS)

