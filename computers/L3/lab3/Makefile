CC=riscv64-unknown-elf-gcc
SPIKE=../build/riscv-isa-sim/spike
PK=../build/riscv-pk/pk

.PHONY: all
all: ex-e1


e1: e1.c
	$(CC) e1.c -o e1

e1.s: e1.c
	$(CC) -march=rv64imafd -c -S e1.c -o e1.s

e1-patched: e1-patched.s
	$(CC) -march=rv64imafd e1-patched.s -o e1-patched

run-e1: e1
	spike -l --log=e1.log pk e1

run-e1-patched: e1-patched
	spike -l --log=e1-patched.log pk e1-patched

ex-e1: e1
	python3 ex.py e1 spike pk

ex-e1-patched: e1-patched
	python3 ex.py e1-patched spike pk

clean:
	rm -f e1 e1.s
