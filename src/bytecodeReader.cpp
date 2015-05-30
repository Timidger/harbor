#include"bytecodeReader.hpp"

//get_bytecode: void -> string
//returns the bytecode stored in the reader
std::string bytecodeReader::get_bytecode(){
	return bytecode;
}

//construct_from_ifstream: ifstream -> void
//consumes a ifstream, and places the parsed input into internal data
void bytecodeReader::construct_from_ifstream(std::ifstream &infile){
	bytecode.clear();
	char temp;
	while(infile >> temp){
		bytecode.push_back(temp);
	}
}