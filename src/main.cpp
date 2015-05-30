#include <iostream>
#include <fstream>

#include"bytecodeEnumType.hpp"
#include"bytecodeReader.hpp"
#include"bytecodeSimulator.hpp"

//Error Mesages 
std::string usageMessage = "bytecodeReader - pwd/bytecodeReader file.byte";
std::string errorMessage = "Failed to open file:";

int main(int argc, char *argv[])
{
	//If we are not given a file, return prompt declaring usage
	if(argc < 2){
		std::cout << usageMessage << std::endl;
		return -1;
	}
	
	//Try to open our input file
	std::ifstream infile;
	infile.open(argv[1]);	

	//If we fail to open the file, return an error message
	if(infile.fail()){
		std::cout << errorMessage << " " << argv[1] << std::endl;
		return -2;
	}
	
	//Create a reader instance, read in from ifstream
	bytecodeReader reader;
	reader.construct_from_ifstream(infile);
	
	//create a simulator instance, get bytecode from reader, run
	bytecodeSimulator simulator;
	simulator.assign_bytecode(reader.get_bytecode());
	simulator.run();
}