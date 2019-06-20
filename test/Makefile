PROJ_DIR := ..

APP := test

CC := gcc
CXX := g++

CFLAGS := \
	-Wall -g -O0 \

LDFLAGS := \

SRCDIR := \
	. 

INCDIR := \
	-I$(PROJ_DIR)/include

LIBDIR := \
	-L/usr/lib \
	-L/usr/lib/x86_64-linux-gnu \
	-L/usr/local/lib \
	-L$(PROJ_DIR)/lib

LIBS := \
	-lpthread -lstr_util

CFLAGS += \
	$(INCDIR)

LDFLAGS += \
	$(LIBDIR) $(LIBS)

#SRCS := $(foreach var, $(SRCDIR), $(wildcard $(addprefix $(var)/*, .c) )) # also right
#OBJS := $(patsubst %.c, %.o, $(filter %.c, $(SRCS)))  # also right
#OBJS := $(SRCS:%.c=%.o) # also right

SRCS := $(foreach var, $(SRCDIR), $(wildcard $(var)/*.c) )

OBJS := $(patsubst %.c, %.o, $(SRCS))

all:$(APP)

%.o:%.c
	$(CC) -c $< $(CFLAGS) -o $@ 
	@echo "========================================================="
	

$(APP):$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
	@echo ""
	@echo "============== compile program successfully ============="
	@echo ""

.PHONE: install clean cleanall debug

install:

clean:
	rm -f $(OBJS)

cleanall:
	rm -f $(OBJS) $(APP)

debug:
	@echo $(SRCS)
	@echo $(OBJS)
