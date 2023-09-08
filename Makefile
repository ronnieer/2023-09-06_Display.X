PROG=DiodTest.exe
SOURCES=DiodTest.c
DEPS=DiodTest.h
CC=gcc
CFLAGS=-Wall -Werror
DEBUG?=1
GTESTINCLUDE = gtest
LIBGTEST = C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a

ifeq ($(DEBUG), 1)
	CFLAGS += -g
	OUTPUTDIR=bin/debug
	PROG=DiodTest.exe
else
	CFLAGS += -g0 -O3
	OUTPUTDIR=bin/release
endif

#Kommer vi behöva kunna göra massa olika makefiler ute på företag?
#om man nämner makefiles på CV vilken nivå ligger vi på ungefär efter denna utbildning 1-5 :)
# $^ betyder den allt på raden efter exempel $(TEST): ?
OBJS =  $(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))

$(PROG): $(OUTPUTDIR) $(OBJS) 
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

$(OUTPUTDIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	@del /q "$(OUTPUTDIR)" 
	@del /q $(PROG)

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

check.exe: googleTest.o DiodTest.o
	g++ -o $@ $^ $(CFLAGS) -I $(GTESTINCLUDE)  $(LIBGTEST)

test: check.exe
	./check.exe


.PHONY: clean