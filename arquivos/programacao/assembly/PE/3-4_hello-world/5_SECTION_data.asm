data:

hello_string: db "hello, world\n"
align   0x10,db 0x00

_written dd 0x00000000
align   0x20,db 0x00

%include "import_descriptor.asm"

data_size equ $ - data

sum_size_sec equ text_size + data_size

