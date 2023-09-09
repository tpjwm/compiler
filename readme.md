build stuff for main project:
`cmake -S . -B build/`

command for assembly stuff for testing directory:
`nasm -f elf64 test.asm && ld test.o -o test`

debug mode because I haven't used c/c++ in too long:
`g++ -g <file>`

`gdb <compiled file>`
then use break to set breakpoints either on specific lines or function names
use `p` to display values, `n` to next, and `s` to step into
`layout src` to see code in a window