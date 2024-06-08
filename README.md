# branch_pred_example

This section demonstrates how branch prediction works in a C++ program by examining the generated assembly code.

## Generated Assembly Code
The following assembly code corresponds to the C++ function above:

```assembly
.LC0:
        .string "x is greater than 10"
.LC1:
        .string "x is greater than 5"
.LC2:
        .string "x is greater than 0"
.LC3:
        .string "x is 0 or less"
example(int):
        push    rbx
        mov     edx, 20
        mov     esi, OFFSET FLAT:.LC0
        cmp     edi, 10
        jg      .L42
        mov     edx, 19
        mov     esi, OFFSET FLAT:.LC1
        cmp     edi, 5
        jg      .L42
        test    edi, edi
        jle     .L12
        mov     edx, 19
        mov     esi, OFFSET FLAT:.LC2
.L42:
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
        mov     rax, QWORD PTR std::cout[rip]
        mov     rax, QWORD PTR [rax-24]
        mov     rbx, QWORD PTR std::cout[rax+240]
        test    rbx, rbx
        je      .L9
        cmp     BYTE PTR [rbx+56], 0
        je      .L15
        movsx   esi, BYTE PTR [rbx+67]
.L16:
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char> >::put(char)
        pop     rbx
        mov     rdi, rax
        jmp     std::basic_ostream<char, std::char_traits<char> >::flush()
.L12:
        mov     edx, 14
        mov     esi, OFFSET FLAT:.LC3
        jmp     .L42
.L15:
        mov     rdi, rbx
        call    std::ctype<char>::_M_widen_init() const
        mov     rax, QWORD PTR [rbx]
        mov     esi, 10
        mov     rax, QWORD PTR [rax+48]
        cmp     rax, OFFSET FLAT:_ZNKSt5ctypeIcE8do_widenEc
        je      .L16
        mov     rdi, rbx
        call    rax
        movsx   esi, al
        jmp     .L16
example(int) [clone .cold]:
```

Comparison and Conditional Jumps:
* cmp edi, 10 followed by jg .L42 checks if x > 10.
* cmp edi, 5 followed by jg .L42 checks if x > 5.
* test edi, edi followed by jle .L12 checks if x <= 0.
