PROJ_DIR := $(shell pwd)

APP := $(PROJ_DIR)/lib/libstr_util.so

CC := gcc
CXX := g++

CFLAGS := \
	-Wall -g -O0 \
	-fPIC  # for generate position independent code (PIC)

LDFLAGS := \
	-shared  # for generate shared library

SRCDIR := \
	$(PROJ_DIR) \
	$(PROJ_DIR)/src \

INCDIR := \
	-I$(PROJ_DIR)/include

LIBDIR := \
	-L/usr/lib \
	-L/usr/lib/x86_64-linux-gnu \
	-L/usr/local/lib \

LIBS := -lpthread

CFLAGS += \
	$(INCDIR)

LDFLAGS += \
	$(LIBDIR) $(LIBS)

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
