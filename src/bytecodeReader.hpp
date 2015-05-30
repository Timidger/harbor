#ifndef BYTECODE_READER_HPP
#define BYTECODE_READER_HPP

#include <vector>
#include <fstream>

#include "instruction.hpp"
#include "bytecodeEnumType.hpp"

//bytecodeReader: handles parsing input into simulator readable bytecode.
class bytecodeReader{
	private:
		std::vector<harbor::instruction> instructions_;
	public:
		
		//get_bytecode: void -> string
		//returns the bytecode stored in the reader
		std::vector<harbor::instruction> get_instructions();
		
		//construct_from_ifstream: ifstream -> void
		//consumes a ifstream, and places the parsed input into internal data
		void construct_from_ifstream(std::ifstream &infile);
};

#endif //BYTECODE_READER_HPP INCLUDED
