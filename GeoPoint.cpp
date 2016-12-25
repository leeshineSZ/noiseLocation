/*
 * GeoPoint.cpp
 *
 *  Created on: Dec 24, 2016
 *      Author: froike
 */

#include <cmath>
#include "GeoPoint.h"

GeoPoint::GeoPoint(double lat, double lon, double alt){
	double lonR = toRadians(lon);
	double latR = toRadians(lat);
	double distance = EARTH_RADIUS + alt;
	_x = distance * cos(latR) * cos(lonR);
	_y = distance * cos(latR) * sin(lonR);
	_z = distance * sin(latR);
}


