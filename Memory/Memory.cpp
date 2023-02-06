/*
 * Memory.cpp
 *
 *  Created on: 05.02.2023
 *      Author: melah
 */

#include "Memory.h"

Memory::Memory(): m_head(nullptr), m_tail(nullptr), m_blockCount(0){

}

Memory::Block::Block(uint32_t startaddress, uint32_t size):
						m_startAddress(startaddress), m_size(size),
						m_next(nullptr), m_prev(nullptr), m_isFree(false){

}

Memory::Block::Block(uint32_t startaddress, uint32_t size, Block* prev, Block* next):
						m_startAddress(startaddress), m_size(size),
						m_prev(prev), m_next(next), m_isFree(false){

}

Memory::Block::~Block(){

}

Memory::Block* Memory::getFirstBlock(){
	return m_head;
}

Memory::Block* Memory::getLastBlock(){
	return m_tail;
}

void Memory::addBlockToHead(uint32_t address, uint32_t size){
	this->m_head = new Block(address, size, nullptr, this->m_head);
	this->m_head->m_next->m_prev = this->m_head;
	m_blockCount++;
}
void Memory::addBlockToTail(uint32_t address, uint32_t size){
	this->m_tail->m_next = new Block( address, size, this->m_tail, nullptr);
	this->m_tail = this->m_tail->m_next;
	m_blockCount++;
}

void Memory::addBlock(uint32_t address, uint32_t size){

	if( this->m_head == nullptr ) {
			this->m_head = new Block(address, size);
			this->m_tail = this->m_head;
			m_blockCount++;
			return;
	}

	uint32_t headAddress = this->m_head->m_startAddress;
	uint32_t tailAddress = this->m_tail->m_startAddress;

	//Blöcke mit niedrigste adresse müssen vorne (head) hinzugefügt werden
	if(address < headAddress){
		//Parameter am Anfang hinzufügen
		addBlockToHead(address, size);
		return;
	}

	//Blöcke mit höchste adresse müssen hinten (tail) hinzugefügt werden
	if(address > tailAddress){
		//Parameter am Ende hinzufügen
		addBlockToTail(address, size);
		return;
	}

	addBlockBetweenHeadAndTail(address, size);

}

void Memory::addBlockBetweenHeadAndTail(uint32_t address, uint32_t size){

	Block* entry = this->m_head;
		while( entry != nullptr ) {
			auto lowAddress = entry->m_startAddress;
			auto highAddress = entry->m_next->m_startAddress;

			if((address > lowAddress) && (address < highAddress)) {
				entry->m_next = new Block(address, size, entry, entry->m_next);
				entry->m_next->m_next->m_prev = entry->m_next;
				m_blockCount++;
				return;
			}
			entry = entry->m_next;
		}

}
