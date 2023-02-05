/*
 * Memory.h
 *
 *  Created on: 05.02.2023
 *      Author: melah
 */

#ifndef MEMORY_MEMORY_H_
#define MEMORY_MEMORY_H_

#include "common.h"

class Memory{
private:
	//jeder control block hat 8 Bytes Größe. 4B für Start
	// 2B für Länge der gesamte Block und 2 Byte für Block-Id
	static const uint32_t BLOCK_CONTROL_SIZE	{8};


public:
	//Diese Mask wird mit dem Block ID verknüpft um zu prüfen
	//ob ein Block frei ist oder nicht
	static const uint16_t BLOCK_FREE_MASK	{0x4000};

	class Block{
	public:
		uint32_t startAddress;
		uint32_t size;
		bool isFree;
		Block *prev;
		Block *next;

	};

private:
	Block* m_block;


public:
	Block* getFirstBlock();
	Block* getLastBlock();

	void addBlock();


};






#endif /* MEMORY_MEMORY_H_ */
