.text # declaration of ’text’ section (which means ’program’)
.globl main # entry point to the ELF linker or loader.
main:
    # prologue
    pushq %rbp # save %rbp on the stack
    movq %rsp, %rbp # define %rbp for the current function

    # body
    movl $92, %eax

    # epilogue
    popq %rbp   # restore %rbp frim the stack
    ret # return to the caller
