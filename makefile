
#Compiler
CC = g++

#Debug or Release
DEBUG = -g
RELEASE = -O2
EXEC_TYPE = ${RELEASE}

#Compiler options
CFLAGS = -pipe -W -Wall -Wextra -ansi -Wunused-variable -pedantic-errors ${EXEC_TYPE}

#PATH
PATH_X = 
PATH_OPENGL = 
INCPATH = ${PATH_X} ${PATH_OPENGL}

#FLAGS
FLAGS_X = 
FLAGS_OPENGL = -lglut
OTHER_FLAGS = -lm
LDFLAGS = ${FLAGS_X} ${FLAGS_OPENGL} ${OTHER_FLAGS}

#executable name
EXEC = exemple

#list here all the source files
SRC = exemple.cpp int_vector.cpp mid_edge.cpp
#OBJ files (if sources in cpp)
OBJ = ${SRC:.cpp=.o} 

#what we are trying to build
all: $(EXEC)

#linkage
$(EXEC): ${OBJ}
	@echo 
	@echo ================ [LINKAGE ...]  ================ 
	@echo

	$(CC) -o $@ $^ $(LDFLAGS)
	@echo
	@echo ================ [progam ${EXEC} compiled succesfully] ================ 
	@echo


#compile every source files
%.o: %.cpp
	@echo --------- build [$<] ----------
	$(CC) $(CFLAGS) $(INCPATH) -c $<  -o $@
	@echo OK [$<] - [$@]
	@echo



#make clean
clean:
	rm -rf *.o *~
