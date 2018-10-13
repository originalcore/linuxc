# source file and object file share the same name
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

TARGET  := lnx_queue

# compile arguments
CC      := gcc
LIBS    :=
LDFLAGS :=
DEFINES :=
INCLUDE :=
CFLAGS  := -g -Wall -O3 $(DEFINES) $(INCLUDE)
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
