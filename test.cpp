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
	printf("test 123\n");
	int size;
	unsigned grid_gap = 2500000;
	short grid_size = 5;


	sensorRow * table = createTableFromFile("inputTable.txt", &size);
	printf("Sensor Num: %d\n",size);

	for (int i = 0; i < size; ++i) {
		printf("%f\t", table[i].Delta);		table[i].snsrLocation.printCart();
		printf("\t\t");					 	table[i].snsrLocation.printGeo();
		printf("\n");

	}

	CartPoint * p = new CartPoint(0,0,0);

	p = findSource(table, size, grid_size, grid_gap);
	printf("Solution:\n");
	p->printCart();
	p->printGeo();
	//printf("\nmain::GridPoint[%3.2f][%3.2f][%3.2f]\n", p[0].get_x(),p[0].get_y(),p[0].get_z());

	//while(1){}     wtf??!?!?
	free(table);
}


