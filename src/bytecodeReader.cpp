#include <vector>
#include"bytecodeReader.hpp"
#include "bytecodeEnumType.hpp"

//get_bytecode: void -> string
//returns the bytecode stored in the reader
std::vector<harbor::instruction> bytecodeReader::get_instructions(){
	return instructions_;
}

//construct_from_ifstream: ifstream -> void
//consumes a ifstream, and places the parsed input into internal data
void bytecodeReader::construct_from_ifstream(std::ifstream &infile){
	instructions_.clear();
	wordwidth_t temp;
	harbor::instruction *instruction;
	while(infile >> temp){
		instruction = new harbor::instruction(temp);
		instructions_.push_back(*instruction);
		delete instruction;
	}
}
