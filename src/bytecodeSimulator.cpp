#include"bytecodeSimulator.hpp"

//evaluate: bytecode -> void
//runs the given bytecode. Results are highly variable.
void bytecodeSimulator::evaluate(bytecode_t inst){
	switch(inst){
	case INST_PUTC:
		std::cout << "INST_PUTC " << evaluationStack.top() << std::endl;
		evaluationStack.pop();
		break;
	
	case INST_PUTI:
		std::cout << "INST_PUTI " << +(unsigned char)evaluationStack.top() << std::endl;
		evaluationStack.pop();
		break;	
	
	case INST_PUTS:
			std::cout << "INST_PUTS " << +(signed char)evaluationStack.top() << std::endl;
			evaluationStack.pop();
			break;	
		
	case INST_GET:{
		char input;
		std::cin >> input;
		evaluationStack.push(input);
		}
		break;
	
	case INST_IMD:
		evaluationStack.push(*(++bytecodeIterator));
		break;
		
	case INST_JMP:
		bytecodeIterator += evaluationStack.top();
		evaluationStack.pop();
		break;
		
	case INST_BR:{
			bool shouldJump = evaluationStack.top();
			evaluationStack.pop();
			char offset = evaluationStack.top();
			evaluationStack.pop();
			if(shouldJump){
				bytecodeIterator += offset;
			}
		}
		break;	
		
	case INST_ADD:
		{char a = evaluationStack.top();
		evaluationStack.pop();
		evaluationStack.push(evaluationStack.top() + a);}
		evaluationStack.pop();
		break;
		
	default:
		std::cout << "ERROR, INVALID INST" << std::endl;
		break;
	}
}
		
//assign_bytecode: string -> void
//assigns internal bytecode to the given string
void bytecodeSimulator::assign_bytecode(std::string bytecode){
	this->bytecode.assign(bytecode);
}

//run: void -> void
//runs the internal bytecode
void bytecodeSimulator::run(){
	bytecode_t inst;
	for(bytecodeIterator = bytecode.begin(); bytecodeIterator != bytecode.end(); bytecodeIterator++){
		inst = *bytecodeIterator;
		evaluate(inst);
	}
}

//constructor
//sets internal counter to 0 upon creation
bytecodeSimulator::bytecodeSimulator(){}