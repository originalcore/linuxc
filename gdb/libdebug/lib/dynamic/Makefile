# The sharelib name goes here
TARGET  := libtest_d.so

# compile and lib parameter
CC      := gcc
LIBS    :=
LDFLAGS :=
DEFINES :=
INCLUDE := -I../../include
CFLAGS  := -g -Wall -O3 $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS) -DHAVE_CONFIG_H
SHARE   := -fPIC -shared -o

# source file and target object file share the same name
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

.PHONY : everything objs clean distclean rebuild

everything : $(TARGET)

all : $(TARGET)

objs : $(OBJS)

rebuild: distclean everything

clean :
	rm -fr *.o

distclean : clean
	rm -fr $(TARGET)

# gcc interface.c -share -fPIC -o libtest.so
$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) $(SHARE) $@ $(OBJS) $(LDFLAGS) $(LIBS)
