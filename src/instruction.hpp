/*
 * instruction.hpp
 *
 *  Created on: May 30, 2015
 *      Author: tristan
 */

#ifndef INSTRUCTION_HPP_
#define INSTRUCTION_HPP_

#include "bytecodeEnumType.hpp"

namespace harbor {
	class instruction {
	private:
		operationsize_t opcode_;
		registersize_t destination_;
		registersize_t source0_;
		registersize_t source1_;
		immediatesize_t immediate_;
		union binaryMap{
			wordwidth_t numericalValue;
			struct{
				operationsize_t opcode : 6;
				registersize_t destination: 6;
				registersize_t source0: 6;
				registersize_t source1: 6;
				immediatesize_t immediate: 8;
			};
		};

	public:
		operationsize_t opcode() { return opcode_; };
		registersize_t destination() { return opcode_; };
		registersize_t source0() { return source0_; };
		registersize_t source1() { return source1_; };
		immediatesize_t immediate() { return immediate_; };

		explicit instruction() {
			instruction(0,0,0,0,0);
		}

		explicit instruction (wordwidth_t binary) {
			binaryMap map;
			map.numericalValue = binary;
			instruction(map.opcode, map.destination, map.source0, map.source1, map.immediate);
		}

		instruction (operationsize_t opcode, registersize_t destination,
				registersize_t source0, registersize_t source1, immediatesize_t immediate)
		:opcode_(opcode),destination_(destination),source0_(source0),source1_(source1),immediate_(immediate)
		{}
	};


}

#endif /* INSTRUCTION_HPP_ */
