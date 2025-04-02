EXE = hammerc

FLAGS = -O0 -g -Wall -Wextra -std=c99 -pedantic
RELEASE_FLAGS = -O2

FILES = impl.c

compile:
	$(CC) $(FLAGS) $(FILES) -o $(EXE)

release:
	$(CC) $(RELEASE_FLAGS) $(FILES) -o $(EXE)
