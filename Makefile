PROG = main.exe 
TESTPROG = tests.exe 
SRC = main.c registration.c userdatabase.c email.c
TESTSRC = registrationTests.cpp registration.c
CFLAGS = -g
LIBS = 
GTEST = gtest
LIBGTEST = C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a

all: $(PROG)


$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

$(TESTPROG): $(TESTSRC)
	g++ -o $@ $^  -I $(GTEST)  $(LIBGTEST)

test: $(TESTPROG)
	./$(TESTPROG)


clean:
	rm -f $(PROG)

.PHONY: all clean