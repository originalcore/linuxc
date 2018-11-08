# source file and object file share the same name
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

TARGET  := double_list

# compile arguments
CC      := gcc
LIBS    :=
LDFLAGS :=
DEFINES :=
INCLUDE :=
CFLAGS  := -g -Wall -O3 $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS)

.PHONY : everything objs clean distclean rebuild pngs

everything : $(TARGET)

all : $(TARGET)

objs : $(OBJS)

rebuild: distclean everything

# patsubst(X,Y,Z)
# In Z range, find X, replace to Y
# convert name.dot ==> name.png
png_files := $(patsubst %.dot,%.png,$(wildcard *.dot))

pngs: $(png_files)

$(png_files): %.png: %.dot
	dot -Tpng $< -o $@

clean :
	rm -fr *.so
	rm -fr *.o
	rm -fr *.png

distclean : clean
	rm -fr $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)
