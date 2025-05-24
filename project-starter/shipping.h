#ifndef SHIPPING_H
#define SHIPPING_H
#include "mapping.h"

#define MAX_TRUCK 3
#define BOX_SMALL 0.25
#define BOX_MEDIUM 0.50
#define BOX_LARGE 1.0
#define MAX_WEIGHT 1500
#define MAX_SIZE 36
#define MAX_ROUTES 200

struct Delivery
{
	int weight; // Package weight
	double volume;
	struct Point destination; // Package destination as a point
};

/**
 * Represents a truck's information including its route, current weight and total boxSize.
 */
struct Truck
{
	struct Route* route;
	int currWeight;
	double boxSizeTotal;
};

struct Map* baseMap;
struct Truck trucks[MAX_TRUCK];

int checkPoint(const struct Point locate); // To check if destination is valid

int checkWeight(int weight); // To check if weight is valid

int checkSize(double sz); // To check if size is valid

int checkAll(double size, int weight, struct Point pt); // To check if all condition included size, weight and location is valid

int NumOfValiDest(struct Route* route, struct Delivery ship);

int onTheRoute(struct Route* route, struct Delivery ship); // To check if destination is on the certain route

int findBestRoute(struct Route routes[MAX_ROUTES], int sz, struct Delivery ship); // check the shortest path

void display(struct Route best, struct Delivery ship);

double calculatePercent(int val, int max);

char chooseTruck(const struct Truck tk1, const struct Truck tk2);

void handlePossibleRoute(struct Route result, struct Truck truck, struct Delivery ship, struct Route routes[MAX_ROUTES], int* size);

void possibleRoutes(struct Delivery ship, struct Truck truck, const struct Map* map, struct Route routes[MAX_ROUTES], int* size);

char findTruck(struct Delivery ship);

void result();
#endif