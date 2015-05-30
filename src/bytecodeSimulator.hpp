#ifndef BYTECODE_SIMULATOR_HPP
#define BYTECODE_SIMULATOR_HPP

#include <iostream>
#include <string>
#include<stack>
#include <assert.h>
#include "bytecodeEnumType.hpp"
//#include"bytecodeEnumType.hpp"

//bytecodeSimulator: runs bytecode. Does not handle creating bytecode
class bytecodeSimulator{
	private:
		std::string bytecode;
		std::string::iterator bytecodeIterator;
		
		//Define our evaluation stack
		std::stack<datasize_t> evaluationStack;
		
		//evaluate: bytecode -> void
		//runs the given bytecode. Results are highly variable.
		void evaluate(bytecode_t inst);
		
	public:
		
		//assign_bytecode: string -> void
		//assigns internal bytecode to the given string
		void assign_bytecode(std::string bytecode);
		
		//run: void -> void
		//runs the internal bytecode
		void run();
		
		//constructor
		//sets internal counter to 0 upon creation
		bytecodeSimulator();
};

#endif //BYTECODE_SIMULATOR_HPP INCLUDED