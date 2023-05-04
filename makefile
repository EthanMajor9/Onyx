# FINAL BINARY TARGET
./bin/Onyx : ./obj/onyx.o ./obj/main.o
	cc ./obj/onyx.o ./obj/main.o -o ./bin/Onyx

# =======================================================
#                     Dependencies
# =======================================================          
./obj/main.o : ./src/main.c ./inc/onyx.h
	cc -c ./src/main.c -o ./obj/main.o

./obj/onyx.o : ./src/onyx.c ./inc/onyx.h
	cc -c ./src/onyx.c -o ./obj/onyx.o


# =======================================================
# Other targets
# ======================================================= 
all : ./bin/Onyx

clean:
	rm -f ./bin/*
	rm -f ./obj/*
