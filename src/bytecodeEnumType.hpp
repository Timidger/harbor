#ifndef BYTECODE_ENUM_TYPE_HPP
#define BYTECODE_ENUM_TYPE_HPP

//Typedef bytecode_t for flexibility changing later
typedef unsigned char bytecode_t;

//Typedef datasize for later flexibility 
typedef char datasize_t;

//Enumeration of instructions (valid bytecode values)
enum bytecode_e{
	INST_PUTC = 0x00, //Pops a character from the stack and prints it as a char
	INST_GET  = 0x01, //Pushes the key pressed by the user onto the stack
	INST_IMD  = 0x02, //Pushes the next bytecode onto the stack
	INST_JMP  = 0x03, //Pops a value, and jumps from the incremented PC by that value
	INST_ADD  = 0x04, //Pops two values off the stack, pushes their sum onto the stack
	INST_PUTI = 0x05, //Pops a character from the stack and prints it as a unsigned int
	INST_PUTS = 0x06, //Pops a character from the stack and prints it as a signed int
	INST_BR   = 0x07  //Pops two values, if the first popped is true it jumps by the second 
};
#endif //BYTECODE_ENUM_TYPE_HPP