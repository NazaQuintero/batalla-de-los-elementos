EXEC = programa

MENU_PATH = ./menu
PERSONAJE_PATH = ./personaje
TDA_PATH = ./tda
TERMINAL_PATH = ./terminal
UTILITARIO_PATH = ./utilitario
VALIDACIONES_PATH = ./validaciones

OFILES = main.o Menu.o Utilitario.o FabricaDePersonaje.o Tierra.o Fuego.o Aire.o Agua.o lista.o nodo.o Personaje.o Terminal.o Validador.o

CC = g++
CFLAGS = -g -O2 -Wall -Werror -pedantic -Wformat=2 -Wpointer-arith -Wunreachable-code -Wno-sign-conversion -lm
VALGRINDFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

validador.o: $(VALIDACIONES_PATH)/Validador.cpp $(VALIDACIONES_PATH)/Validador.h
	$(CC) $(CFLAGS) -c $(VALIDACIONES_PATH)/Validador.cpp

terminal.o: $(TERMINAL_PATH)/Terminal.cpp $(TERMINAL_PATH)/Terminal.h validador.o
	$(CC) $(CFLAGS) -c $(TERMINAL_PATH)/Terminal.cpp

personaje.o: $(PERSONAJE_PATH)/Personaje.cpp $(PERSONAJE_PATH)/Personaje.h validador.o
	$(CC) $(CFLAGS) -c $(PERSONAJE_PATH)/Personaje.cpp

nodo.o: $(TDA_PATH)/nodo.cpp $(TDA_PATH)/nodo.h personaje.o
	$(CC) $(CFLAGS) -c $(TDA_PATH)/nodo.cpp

lista.o: $(TDA_PATH)/lista.cpp $(TDA_PATH)/lista.h nodo.o
	$(CC) $(CFLAGS) -c $(TDA_PATH)/lista.cpp

agua.o: $(PERSONAJE_PATH)/Agua.cpp $(PERSONAJE_PATH)/Agua.h personaje.o
	$(CC) $(CFLAGS) -c $(PERSONAJE_PATH)/Agua.cpp

aire.o: $(PERSONAJE_PATH)/Agua.cpp $(PERSONAJE_PATH)/Agua.h personaje.o
	$(CC) $(CFLAGS) -c $(PERSONAJE_PATH)/Aire.cpp

fuego.o: $(PERSONAJE_PATH)/Fuego.cpp $(PERSONAJE_PATH)/Fuego.h personaje.o
	$(CC) $(CFLAGS) -c $(PERSONAJE_PATH)/Fuego.cpp

tierra.o: $(PERSONAJE_PATH)/Tierra.cpp $(PERSONAJE_PATH)/Tierra.h personaje.o
	$(CC) $(CFLAGS) -c $(PERSONAJE_PATH)/Tierra.cpp

fabrica.o: $(PERSONAJE_PATH)/FabricaDePersonaje.cpp $(PERSONAJE_PATH)/FabricaDePersonaje.h agua.o aire.o fuego.o tierra.o
	$(CC) $(CFLAGS) -c $(PERSONAJE_PATH)/FabricaDePersonaje.cpp

utilitario.o: $(UTILITARIO_PATH)/Utilitario.cpp $(UTILITARIO_PATH)/Utilitario.h lista.o fabrica.o terminal.o
	$(CC) $(CFLAGS) -c $(UTILITARIO_PATH)/Utilitario.cpp

menu.o: $(MENU_PATH)/Menu.cpp $(MENU_PATH)/Menu.h terminal.o utilitario.o
	$(CC) $(CFLAGS) -c $(MENU_PATH)/Menu.cpp

main.o: ./main.cpp menu.o terminal.o validador.o utilitario.o
	$(CC) $(CFLAGS) -c ./main.cpp

build: $(EXEC)

run: build
	./$(EXEC)

valgrind: build
	valgrind $(VALGRINDFLAGS) ./$(EXEC)

clean:
	rm -f *.o $(EXEC)

$(EXEC): $(OFILES)
		$(CC) $(CFLAGS) $(OFILES) -o $(EXEC)