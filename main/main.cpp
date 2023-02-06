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

	Memory* memory = new Memory();

	memory->addBlock(100, 10);
	memory->addBlock(200, 14);
	memory->addBlock(12, 5);
	memory->addBlock(8, 16);
	memory->addBlock(10, 45);

	cout<<"MemoryManagement"<<endl;
	return 0;
}


