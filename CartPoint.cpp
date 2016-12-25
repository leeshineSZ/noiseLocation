/*
 * CartPoint.cpp
 *
 *  Created on: Dec 24, 2016
 *      Author: froike
 */


#include "CartPoint.h"
#include <cmath>
#include <stdio.h>

/*
 * Contractor
 */

CartPoint::CartPoint(){
	_z=0; _y = 0; _x = 0;
}

CartPoint::CartPoint(double x, double y, double z){
	_x = x;
	_y = y;
	_z = z;
}

double CartPoint::get_lat(){
	return toDegrees(asin(_z / EARTH_RADIUS));
}

double CartPoint::get_lon(){
	return toDegrees(atan2(_y,_x));
}

double CartPoint::get_alt(){
	return sqrt(pow(_x,2) + pow(_y,2) + pow(_z,2)) - EARTH_RADIUS;
}

double CartPoint::get_x(){
	return _x;
}

double CartPoint::get_y(){
	return _y;
}

double CartPoint::get_z(){
	return _z;
}

void CartPoint::printCart(){
	printf("(CartPoint: x:%f y:%f z:%f)\n",_x, _y, _z);
}

void CartPoint::printGeo(){
	printf("(CartPoint: lat:%f lon:%f alt:%f)\n",get_lat(), get_lon(), get_alt());
}

double CartPoint::distance(CartPoint other){
	return sqrt(pow(_x - other._x, 2) + pow(_y - other._y, 2) +pow(_z - other._z, 2));
}


double toDegrees(double radians){
	return (radians * 180) / M_PI;
}

double toRadians(double degrees){
	return (M_PI * degrees) / 180;
}
