# source file and object file share the same name
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

TARGET  := binaryTree

# compile arguments
CC      := gcc
LIBS    :=
LDFLAGS :=
DEFINES :=
INCLUDE :=
# Must have a no-stack-protection flag here
# Stack Smashing here is actually caused
# due to a protection mechanism used by gcc
# to detect buffer overflow errors
CFLAGS  := -g -Wall -O3 $(DEFINES) $(INCLUDE) -fno-stack-protector
CXXFLAGS:= $(CFLAGS)

.PHONY : everything objs clean distclean rebuild

everything : $(TARGET)

all : $(TARGET)

objs : $(OBJS)

rebuild: distclean everything

clean :
	rm -fr *.o

distclean : clean
	rm -fr $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)
