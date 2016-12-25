/*
 * noiseLocation.h
 *
 *  Created on: Dec 25, 2016
 *      Author: froike
 */

#ifndef NOISELOCATION_H_
#define NOISELOCATION_H_

#include "GeoPoint.h"

struct SensorRow{
	CartPoint snsrLocation;
	double Delta;
};

SensorRow createTableFromFile(char* fileName);

double ErrorAsesmnt(SensorRow real, CartPoint p);

CartPoint findSource(SensorRow*, short size, unsigned grid_gap);




#endif /* NOISELOCATION_H_ */
