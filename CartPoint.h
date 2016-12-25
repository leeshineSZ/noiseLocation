/*
 * CartPoint.h
 *
 *  Created on: Dec 22, 2016
 *      Author: froike
 */

#ifndef CARTPOINT_H_
#define CARTPOINT_H_

using namespace std;


class CartPoint{
public:

	static const double EARTH_RADIUS = 6378137;
	double _x, _y, _z;
	CartPoint();
	CartPoint(double x, double y, double z);
	double get_lat();
	double get_lon();
	double get_alt();
	double get_x();
	double get_y();
	double get_z();
	void printCart();
	void printGeo();
	double distance(CartPoint Other);


private:


};

double toDegrees(double radians);
double toRadians(double degrees);



#endif /* CARTPOINT_H_ */
