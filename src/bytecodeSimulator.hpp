#ifndef BYTECODE_SIMULATOR_HPP
#define BYTECODE_SIMULATOR_HPP

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <assert.h>
#include "instruction.hpp"
#include "bytecodeEnumType.hpp"
//#include"bytecodeEnumType.hpp"

//bytecodeSimulator: runs bytecode. Does not handle creating bytecode
class bytecodeSimulator {
	private:
		std::vector<harbor::instruction> instruction_;
		std::vector<harbor::instruction>::iterator instructionIterator_;

		//Define our registers
		std::vector<wordwidth_t> register_;
		
		//evaluate: bytecode -> void
		//runs the given bytecode. Results are highly variable.
		void evaluate(harbor::instruction inst);
		
	public:
		
		//assign_bytecode: string -> void
		//assigns internal bytecode to the given string
		void assign_instructions(std::vector<harbor::instruction> bytecode);
		
		//run: void -> void
		//runs the internal bytecode
		void run();
		
		//constructor
		//sets internal counter to 0 upon creation
		bytecodeSimulator();
};

#endif //BYTECODE_SIMULATOR_HPP INCLUDED
