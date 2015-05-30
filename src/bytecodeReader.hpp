#ifndef BYTECODE_READER_HPP
#define BYTECODE_READER_HPP

#include<fstream>

//bytecodeReader: handles parsing input into simulator readable bytecode.
class bytecodeReader{
	private:
		std::string bytecode;
	public:
		
		//get_bytecode: void -> string
		//returns the bytecode stored in the reader
		std::string get_bytecode();
		
		//construct_from_ifstream: ifstream -> void
		//consumes a ifstream, and places the parsed input into internal data
		void construct_from_ifstream(std::ifstream &infile);
};

#endif //BYTECODE_READER_HPP INCLUDED