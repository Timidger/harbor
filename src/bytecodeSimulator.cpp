#include "instruction.hpp"
#include "bytecodeSimulator.hpp"
#include "bytecodeEnumType.hpp"

//evaluate: bytecode -> void
//runs the given bytecode. Results are highly variable.
void bytecodeSimulator::evaluate(harbor::instruction inst){
	switch(inst.opcode()){
	case INST_PUTC:
		std::cout << "INST_PUTC " << (char) register_[inst.source0()] << std::endl;
		break;
	
	case INST_PUTI:
		std::cout << "INST_PUTI " << register_[inst.source0()] << std::endl;
		break;	
	
	case INST_PUTS:
		std::cout << "INST_PUTS " << register_[inst.source0()] << std::endl;
		break;
		
	case INST_GET:{
		char input;
		std::cin >> input;
		register_[inst.destination()] = input;
		}
		break;
	
	case INST_IMD:
		register_[inst.destination()] = inst.immediate();
		break;
		
	case INST_JMP:
		instructionIterator_ += inst.immediate();
		break;
		
	case INST_BR:{
			bool shouldJump = register_[inst.source0()];
			char offset = inst.immediate();
			if(shouldJump){
				instructionIterator_ += offset;
			}
		}
		break;	
		
	case INST_ADD:
			register_[inst.destination()] = register_[inst.source0()] + register_[inst.source1()];
		break;
		
	default:
		std::cout << "ERROR, INVALID INST" << std::endl;
		break;
	}
}
		
//assign_bytecode: string -> void
//assigns internal bytecode to the given string
void bytecodeSimulator::assign_instructions(std::vector<harbor::instruction> instructions){
	instruction_.assign(instructions.begin(),instructions.end());
}

//run: void -> void
//runs the internal bytecode
void bytecodeSimulator::run() {
	for(instructionIterator_= instruction_.begin(); instructionIterator_ != instruction_.end(); instructionIterator_++) {
		evaluate(*instructionIterator_);
	}
}

//constructor
//sets internal counter to 0 upon creation
bytecodeSimulator::bytecodeSimulator(){}
