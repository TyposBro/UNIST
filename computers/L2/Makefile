CC=riscv64-unknown-elf-gcc
SPIKE=../build/riscv-isa-sim/spike
PK=../build/riscv-pk/pk

.PHONY: all
all: tut1 tut2

tut1: tut1.c
	$(CC) $< -o $@

tut2: tut2.s tut2-lib.c
	$(CC) tut2.s tut2-lib.c -o $@

exer1: exer1.c
	$(CC) exer1.c -o exer1

exer2: exer2.s exer2-lib.c
	$(CC) exer2.s exer2-lib.c -o exer2

test-exer1: exer1
	$(SPIKE) $(PK) exer1

ex-exer1: exer1
	python3 ex.py exer1 $(SPIKE) $(PK)

ex-exer2: exer2
	python3 ex.py exer2 $(SPIKE) $(PK)

clean:
	rm -f tut1 tut2 exer1 exer2
