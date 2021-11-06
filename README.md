# BitHelper 
## Description
C++ templates for reading and writing a specific type of data in normal or reverse byte order. \
Can be used to convert from Little Endian to Big Endian or vice versa.\
Check out [test1.cpp][test1.cpp] for how to use it.\
You can simply use `make` command to compile the test code, or use g++/your c++ compiler.

## What is it for?
It reads/writes a specific data type from/to a binary file. The reverse namespace contains the same functions, just reads from/writes to a file in reverse byte order. It can be used to convert Little Endian to Big Endian or vice versa. 

## Examples
### Reading a double
```
std::fstream *_file = new std::fstream("test.bin",std::ios::in | std::ios::binary);
...
double d = bithelper::ReadData<double>(_file);
```

### Writing a double
```
double d = 15.12;
std::fstream *_file = new std::fstream("test.bin", std::ios::out | std::ios::binary);
...
bithelper::WriteData<double>(_file, d);
```