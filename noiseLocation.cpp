/*
 * noiseLocation.cpp
 *
 *  Created on: Dec 25, 2016
 *      Author: froike
 */
#include <iostream>
#include <fstream>
#include "noiseLocation.h"
#include <cstdlib>
#include <string>

SensorRow* createTableFromFile(const char* fileName, int* size){

	FILE* f = fopen(fileName,"r");
	string line;
	short run = 1;
	int linesCount, counter = 0;
	double lat, lon, alt, delta;
	sensorRow* table;
	sensorRow* row;

	while(run){
		if (run > 1){ // SEC:wait for new points.
			if (counter<linesCount){
				if (fscanf(f,"%lf,%lf,%lf,%lf",&lat, &lon, &alt, &delta)){
					table[counter].snsrLocation = GeoPoint(lat,lon,alt);
					table[counter].Delta = delta;
					counter++;
				}else{
					printf("error 1");
					exit(1);
				}

			}else break;


		}else{ //First: with for points counter.
			if (!fscanf(f,"%d",&linesCount)){
				printf("error 2");
				exit(2);
			}
			table = (sensorRow*) malloc(sizeof(sensorRow)*linesCount);
			run = 2;
		}
	}
	*size = linesCount;
	fclose(f);
	return table;
}

double ErrorAsesmnt(SensorRow real, CartPoint p){
	//todo: Ofer.

	return 0;
}

CartPoint findSource(SensorRow*, short size, unsigned grid_gap){
	//todo Ofer.
	return CartPoint(1,2,3);
}




