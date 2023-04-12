PROJ_NAME=main

ALUNO=Marcelofa

CC = gcc
CFLAGS = -ggdb -O0 -std=c99 -fstack-protector-all -Werror=implicit-function-declaration
LDFLAGS=-O0 -g

SRCDIR = ./Leituras ./Estruturas ./Formas ./Geral

SRC = $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.c))

OBJ = $(SRC:.c=.o)

EXEC = main

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

pack: $(PROJ_NAME)
	rm -f ../$(ALUNO).zip
	echo $(ALUNO)
	date >> .entrega
	cd ..; zip $(ALUNO).zip -r src/*.c src/*.h src/Makefile LEIA-ME.txt .entrega