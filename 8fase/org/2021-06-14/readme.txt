sudo apt install as31 nasm

nasm -f elf64 -o first.o first.s
ld -o first first.o
./first

OR

nasm -f elf64 -o first.o first.s && ld -o first first.o && ./first
