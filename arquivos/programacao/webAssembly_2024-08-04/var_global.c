https://webassembly.github.io/wabt/demo/wat2wasm/
https://webassembly.github.io/wabt/demo/wasm2wat/

unsigned char v1[] = "variável global v1";
unsigned char v2 = 'T';

int main() {
  return v2 + 1;
}

/*
(module
  (table 0 anyfunc)
  (memory $0 1)
  (data (i32.const 16) "vari\c3\a1vel global v1\00")
  (data (i32.const 48) "T")
  (export "memory" (memory $0))
  (export "main" (func $main))
  (func $main (; 0 ;) (result i32)
    (i32.add
      (i32.load8_u offset=48 (i32.const 0))
      (i32.const 1)
    )
  )
)

hexdump -C test.wasm 
00000000  00 61 73 6d 01 00 00 00  01 85 80 80 80 00 01 60  |.asm...........`|
00000010  00 01 7f 03 82 80 80 80  00 01 00 04 84 80 80 80  |................|
00000020  00 01 70 00 00 05 83 80  80 80 00 01 00 01 06 81  |..p.............|
00000030  80 80 80 00 00 07 91 80  80 80 00 02 06 6d 65 6d  |.............mem|
00000040  6f 72 79 02 00 04 6d 61  69 6e 00 00 0a 90 80 80  |ory...main......|
00000050  80 00 01 8a 80 80 80 00  00 41 00 2d 00 30 41 01  |.........A.-.0A.|
00000060  6a 0b 0b a0 80 80 80 00  02 00 41 10 0b 14 76 61  |j.........A...va|
00000070  72 69 c3 a1 76 65 6c 20  67 6c 6f 62 61 6c 20 76  |ri..vel global v|
00000080  31 00 00 41 30 0b 01 54                           |1..A0..T|
00000088

echo -n -e \\x00\\x61\\x73\\x6d # WASM_BINARY_MAGIC
echo -n -e \\x01\\x00\\x00\\x00 # WASM_BINARY_VERSION


echo -n -e \\x01 # type section
echo -n -e \\x85 # section size

echo -n -e \\x80 # num types
echo -n -e \\x80 # func
echo -n -e \\x80 # num params
echo -n -e \\x00 # rum results
echo -n -e \\x7f # i32



unsigned char v1[] = "variável global v1";
unsigned char v2 = 'T';

char * msg() {
  return v1;
}


(module
 (table 0 anyfunc)
 (memory $0 1)
 (data (i32.const 16) "vari\c3\a1vel global v1\00")
 (data (i32.const 48) "T")
 (export "memory" (memory $0))
 (export "msg" (func $msg))
 (func $msg (; 0 ;) (result i32)
  (i32.const 16)
 )
)


https://wasdk.github.io/WasmFiddle/

git clone --recursive https://github.com/WebAssembly/wabt
cd wabt
git submodule update --init
mkdir build
cd build
cmake ..
cmake --build .
make

bin/wat2wasm test.wat -o test.wasm

*/
