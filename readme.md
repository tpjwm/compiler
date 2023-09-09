build stuff for main project:
`cmake -S . -B build/`

command for assembly stuff for testing directory:
`nasm -f elf64 test.asm && ld test.o -o test`