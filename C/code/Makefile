# Modified from Neil's Makefile!!!
# -Werror

CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic -Wfloat-equal -Wvla -std=c99
DEBUG := -g3
SANI := $(CFLAGS) -fsanitize=address -fsanitize=undefined $(DEBUG)
VALG := $(CFLAGS) $(DEBUG)
PRODUCTION= $(CFLAGS) -O3


%: %.c ../General/general.h ../General/general.c
		$(CC) $< ../General/general.c $(CFLAGS) -O2 -o $@ -lm

# ./XXX_s
%_s: %.c ../General/general.h ../General/general.c
		$(CC) $< ../General/general.c $(SANI) -o $@ -lm

# valgrind ./XXX_v
%_v: %.c ../General/general.h ../General/general.c
		$(CC) $< ../General/general.c $(VALG) -o $@ -lm


# 'make clean' removes all executables
clean:
		rm -f *_s *_v 
