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

double ErrorAsesmnt(SensorRow * table, CartPoint * p, short size){

	double  dist = 0.0;

	// old calc
	for(int i=0;i<size;i++){
		dist = dist + table[i].snsrLocation.distance(p[0]);
	}
	//printf("ErrorAses::Grid[%3.2f][%3.2f][%3.2f]\n", p[0].get_x(), p[0].get_y(), p[0].get_z());
	dist = dist / size;
	return dist;
}



CartPoint * findSource(SensorRow * table, short sat_num, short grid_size, unsigned grid_gap){

	int step = grid_size / 2;
	int x_zero = 0 , y_zero = 0 , z_zero = 0;
	int counter = 0;
	double rank, min_rank=11000000;
	double x_center=0.0, y_center=0.0, z_center=0.0;
	bool complete = false;

	CartPoint * grid = new CartPoint(0,0,0);

	while(!complete){
		//printf("\nfindSource::grid_size=%2i,grid_gap=%2i,grid_step=%2i;\n", grid_size, grid_gap,step);
		//printf("Center[%3.2f][%3.2f][%3.2f]\n", x_center, y_center, z_center);
		min_rank=11000000;
		for(int z=-step;z<=step;z++){
			for(int y=-step;y<=step;y++){
				for(int x=-step;x<=step;x++){
					grid[0]._x = (double) x*grid_gap + x_center;
					grid[0]._y = (double) y*grid_gap + y_center;
					grid[0]._z = (double) z*grid_gap + z_center;
					//printf("findSource::Grid[%3.2f][%3.2f][%3.2f]\n", grid[0].get_x(), grid[0].get_y(), grid[0].get_z());

					rank = ErrorAsesmnt(table, grid, sat_num);
					if(rank < min_rank){
						min_rank = rank;
						x_zero = x;
						y_zero = y;
						z_zero = z;
						//printf("\nMin_rank_int[%2i][%2i][%2i]= %3.2f\n", x_zero, y_zero, z_zero, min_rank);
						//printf("Min GridPoint_int[%3.2f][%3.2f][%3.2f]\n", grid[0].get_x(), grid[0].get_y(), grid[0].get_z());
					}
				}
			}
		}
		grid[0]._x = (double) x_zero*grid_gap + x_center;
		grid[0]._y = (double) y_zero*grid_gap + y_center;
		grid[0]._z = (double) z_zero*grid_gap + z_center;
		//printf("Min_rank[%2i][%2i][%2i][%2i]= %3.2f\n", counter, x_zero, y_zero, z_zero, min_rank);
		//printf("MinGridPoint[%3.2f][%3.2f][%3.2f]\n", grid[0].get_x(), grid[0].get_y(), grid[0].get_z());

		x_center = grid[0].get_x();
		y_center = grid[0].get_y();
		z_center = grid[0].get_z();
		grid_gap = min_rank * 0.3;

		if ((min_rank < 10) || (counter == 15)) complete = true;
		counter++;
	}
	return grid;
}





