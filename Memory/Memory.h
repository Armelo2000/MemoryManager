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
		uint32_t m_startAddress;
		uint32_t m_size;
		bool m_isFree;
		Block *m_prev;
		Block *m_next;

		Block(uint32_t startaddress, uint32_t size);
		Block(uint32_t startaddress, uint32_t size, Block* prev, Block* next);

		~Block();
	};

	Memory(uint32_t size);

private:
	Block* m_head;
	Block* m_tail;
	uint32_t m_blockCount;

	uint32_t m_usedSpace;
	uint32_t m_freeSpace;

	uint32_t m_addressPointer;
	uint32_t m_size;

	void addBlockToHead(uint32_t address, uint32_t size);
	void addBlockToTail(uint32_t address, uint32_t size);
	void addBlock(uint32_t address, uint32_t size);
	void addBlockBetweenHeadAndTail(uint32_t address, uint32_t size);
public:
	Block* getFirstBlock();
	Block* getLastBlock();



	int addBlockMemory(uint32_t size);


};






#endif /* MEMORY_MEMORY_H_ */
