# FINAL BINARY TARGET
./bin/Onyx : ./obj/onyx.o ./obj/main.o ./obj/commands.o ./obj/datastructures.o
	cc ./obj/onyx.o ./obj/main.o ./obj/commands.o ./obj/datastructures.o -o ./bin/Onyx

# =======================================================
#                     Dependencies
# =======================================================          
./obj/main.o : ./src/main.c ./inc/onyx.h
	cc -c ./src/main.c -o ./obj/main.o

./obj/onyx.o : ./src/onyx.c ./inc/onyx.h ./inc/datastructures.h
	cc -c ./src/onyx.c -o ./obj/onyx.o

./obj/commands.o : ./src/commands.c ./inc/commands.h ./inc/datastructures.h
	cc -c ./src/commands.c -o ./obj/commands.o

./obj/datastructures.o : ./src/datastructures.c ./inc/datastructures.h ./inc/commands.h
	cc -c ./src/datastructures.c -o ./obj/datastructures.o


# =======================================================
# Other targets
# ======================================================= 
all : ./bin/Onyx

clean:
	rm -f ./bin/*
	rm -f ./obj/*
