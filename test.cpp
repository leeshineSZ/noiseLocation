/*
 * test.cpp
 *
 *  Created on: Dec 24, 2016
 *      Author: froike
 */

#include "noiseLocation.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	printf("test\n");
	int size;
	sensorRow* table = createTableFromFile("inputTable.txt", &size);
	printf("%d\n",size);

	for (int i = 0; i < size; ++i) {
		table[i].snsrLocation.printCart();
		table[i].snsrLocation.printGeo();
	}
	free(table);


}
