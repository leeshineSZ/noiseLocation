/*
 * noiseLocation.h
 *
 *  Created on: Dec 25, 2016
 *      Author: froike
 */

#ifndef NOISELOCATION_H_
#define NOISELOCATION_H_

#include "GeoPoint.h"

typedef struct SensorRow{
	CartPoint snsrLocation;
	double Delta;
} sensorRow;

SensorRow* createTableFromFile(const char* fileName, int* size);

double ErrorAsesmnt(SensorRow* real, CartPoint p);


/*
 * TODO: create copy constructor!!! using pointer here is worng and can be buggy;
 */
CartPoint * findSource(SensorRow * table, short sat_num, short grid_size, unsigned grid_gap);




#endif /* NOISELOCATION_H_ */
