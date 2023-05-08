# Compiler settings
CC = cc

# Directories
SRCDIR = ./src
INCDIR = ./inc
OBJDIR = ./obj
BINDIR = ./bin

# Object files
OBJECTS = $(OBJDIR)/onyx.o \
		  $(OBJDIR)/main.o \
		  $(OBJDIR)/misc_commands.o \
		  $(OBJDIR)/hashtable.o

# Final binary target
$(BINDIR)/Onyx : $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Dependencies
$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/onyx.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/onyx.o: $(SRCDIR)/onyx.c $(INCDIR)/onyx.h $(INCDIR)/hashtable.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/misc_commands.o: $(SRCDIR)/misc_commands.c $(INCDIR)/misc_commands.h $(INCDIR)/hashtable.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/hashtable.o: $(SRCDIR)/hashtable.c $(INCDIR)/hashtable.h
	$(CC) $(CFLAGS) -c $< -o $@

# Other targets
all: $(BINDIR)/Onyx

clean:
	rm -f $(BINDIR)/*
	rm -f $(OBJDIR)/*