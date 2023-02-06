/*
 * main.cpp
 *
 *  Created on: 05.02.2023
 *      Author: melah
 */


#include <iostream>
#include "Memory.h"

using namespace std;

int main(){

	Memory* memory = new Memory(316);

	memory->addBlockMemory(100);
	memory->addBlockMemory(200);
	memory->addBlockMemory(12);
	memory->addBlockMemory(8);
	memory->addBlockMemory(10);

	cout<<"MemoryManagement"<<endl;
	return 0;
}


