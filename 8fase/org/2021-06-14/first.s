global _start

section .text

_start:
  mov rax, 1        ; write(
  mov rdi, 1        ;   STDOUT_FILENO,
  mov rsi, msg      ;   "puss puss puss, kitten!\n",
  mov rdx, msglen   ;   sizeof("puss puss puss, kitten!\n")
  syscall           ; );

  mov rax, 60       ; exit(
  mov rdi, 0        ;   EXIT_SUCCESS
  syscall           ; );

section .rodata
  msg: db "puss puss puss, kitten!", 10
  msglen: equ $ - msg