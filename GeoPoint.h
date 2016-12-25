/*
 * GeoPoint.h
 *
 *  Created on: Dec 22, 2016
 *      Author: froike
 */

#ifndef GEOPOINT_H_
#define GEOPOINT_H_

#include "CartPoint.h"

using namespace std;

class GeoPoint : public CartPoint{

public:
	GeoPoint(double lat, double lon, double alt);

private:


};


#endif /* GEOPOINT_H_ */
