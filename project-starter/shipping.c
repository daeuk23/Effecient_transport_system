#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "shipping.h"

#define BLUE 2
#define GREEN 4
#define YELLOW 8


int checkPoint(const struct Point locate) {
	int check = 0; // flag for checking if point is valid
	if ((locate.row >= 0 && locate.row < MAP_ROWS) && (locate.col >= 0 && locate.col < MAP_COLS))
	{
		check = 1; // change return value to 'true' when point is valid
	}
	else
		printf("Invalid destination\n");

	return check;
}


int checkWeight(int weight)
{
	int check = 0; // flag for checking if weight is valid
	if (weight > 0 && weight <= MAX_WEIGHT)
	{
		check = 1; // return 1 as true when weight is valid
	}
	else
		printf("Invalid weight (must be 1-1000 Kg.)\n");

	return check;
}

int checkSize(double sz)
{
	int check = 0; // flag for checking if size is valid
	if (sz == BOX_SMALL || sz == BOX_MEDIUM || sz == BOX_LARGE)
	{
		check = 1; // return 1 as true when size is valid
	}
	else
		printf("Invalid size\n");

	return check;
}

int checkAll(double size, int weight, struct Point pt)
{
	struct Map map = populateMap();
	struct Map* tempMap = &map;
	int check = 1;
	int min = 0;
	int max = 26;

	if (weight == 0 && size == 0 && pt.row == 'x')
	{
		check = 0;
	}
	else if (pt.row == NULL || pt.col == NULL || (int)(pt.row) > max || (int)(pt.col) > max)
	{
		pt.row = pt.col = -1;
	}

	if (check != 0)
	{
		if (checkWeight(weight) == 0)
		{
			check = -2;
		}
		else if (checkSize(size) == 0)
		{
			check = -1;
		}
		else if (checkPoint(pt) == 0)
		{
			check = -3;
		}
		else if (tempMap->squares[(int)pt.row][(int)pt.col] == 0)
		{
			check = -3;
			printf("Invalid destination\n");
		}
	}
	return check;
}

int onTheRoute(struct Route* route, struct Delivery ship)
{
	int isDest = 0;
	int i = 0;
	while (i < route->numPoints && isDest == 0)
	{
		if (route->points[i].col == ship.destination.col &&
			route->points[i].row == ship.destination.row)
		{
			isDest = 1;
		}
		i++;
	}
	return isDest;
}

int findBestRoute(struct Route routes[MAX_ROUTES], int s, struct Delivery ship)
{
	int check = 0;
	int i = 0;

	for (i = 0; i < s; i++)
	{
		if (routes[i].numPoints < routes[check].numPoints) {
			check = i;
		}
	}
	return check;
}

void display(struct Route best, struct Delivery ship) {
	switch (best.routeSymbol)
	{
	case 2:
		printf("Ship on BLUE LINE, ");
		break;
	case 4:
		printf("Ship on GREEN LINE, ");
		break;
	case 8:
		printf("Ship on YELLOW LINE, ");
		break;
	}

	if (best.numPoints >= 1)
	{
		if (best.numPoints != 1)
		{

			printf("divert: ");
			int i = 0;
			while (i < best.numPoints)
			{
				printf("%d%c", best.points[i].row + 1, 'A' + best.points[i].col);
				if (i != best.numPoints - 1)
				{
					printf(", ");
				}
				i++;
			}
			if (best.points[best.numPoints - 1].col != ship.destination.col ||
				best.points[best.numPoints - 1].row != ship.destination.row)
			{
				printf(", %d%c", ship.destination.row + 1, 'A' + ship.destination.col);
			}
		}
		else
		{
			printf("no diversion.");

		}
	}
	else {
		printf("Ships tomorrow");
	}
	printf("\n");
}


double calculatePercent(int val, int max)
{
	return (double)val / max * 100;
}

char chooseTruck(const struct Truck tk1, const struct Truck tk2)
{
	double tr1Weight = calculatePercent(tk1.currWeight, MAX_WEIGHT);
	double tr2Weight = calculatePercent(tk2.currWeight, MAX_WEIGHT);

	double tr1Size = calculatePercent(tk1.boxSizeTotal, MAX_SIZE);
	double tr2Size = calculatePercent(tk2.boxSizeTotal, MAX_SIZE);

	double tr1Percent = fmax(tr1Weight, tr1Size) * 100;
	double tr2Percent = fmax(tr1Weight, tr2Size) * 100;

	if (tr1Percent < tr2Percent)
	{
		return tk1.route->routeSymbol;
	}
	else if (tr2Percent < tr1Percent)
	{
		return tk2.route->routeSymbol;
	}
	else
	{
		return tk1.route->routeSymbol;
	}
}

// for handling possible route
void handlePossibleRoute(struct Route result, struct Truck truck, struct Delivery ship, struct Route routes[MAX_ROUTES], int* size)
{
	if ((onTheRoute(&result, ship) == 1 || distance(&result.points[result.numPoints - 1], &ship.destination) == 1) && result.numPoints >= 1)
	{
		result.routeSymbol = truck.route->routeSymbol;
		routes[(*size)++] = result;
	}
}

int NumOfValiDest(struct Route* route, struct Delivery ship) {
	int matches = 0;
	int i = 0;

	while (i < route->numPoints && matches == 0) {
		if (route->points[i].col == ship.destination.col && route->points[i].row == ship.destination.row)
			matches = 1;

		i++;
	}

	return matches;
}

void possibleRoutes(struct Delivery ship, struct Truck truck, const struct Map* map, struct Route routes[MAX_ROUTES], int* size)
{
	struct Map maps = populateMap();

	for (int i = 0; i < truck.route->numPoints; i++)
	{
		struct Route crRoute = shortestPath(&maps, truck.route->points[i], ship.destination);
		const struct Point resultDst = crRoute.points[crRoute.numPoints - 1];

		if (NumOfValiDest(&crRoute, ship) == 1) {
			crRoute.routeSymbol = truck.route->routeSymbol;
			routes[*size] = crRoute;
			(*size)++;
		}
		if (crRoute.numPoints == 2)
		{
			for (int j = 0; j < truck.route->numPoints; j++)
			{
				if (crRoute.points[0].row == truck.route->points[j].row && crRoute.points[0].col == truck.route->points[j].col)
				{
					crRoute.points[0] = ship.destination;
					crRoute.numPoints = 1;
				}
			}
			crRoute.routeSymbol = truck.route->routeSymbol;
			routes[*size] = crRoute;
			(*size)++;
		}
		else if (distance(&resultDst, &ship.destination) == 1) {
			crRoute.routeSymbol = truck.route->routeSymbol;
			routes[*size] = crRoute;
            (*size)++;
		}
	}
}

char findTruck(struct Delivery ship)
{
	/*struct Route routes[MAX_ROUTE] = {0};
	int bestRoute;
	int result = -1;

	for (int i = 0; i < MAX_TRUCK; i++)
	{
		if ((trucks[i].currWeight + ship.weight <= MAX_WEIGHT) && (trucks[i].boxSizeTotal + ship.volume <= MAX_SIZE))
		{
			possibleRoutes(ship, trucks[i], baseMap, routes, &(routes[i].numPoints));
		}
	}

	bestRoute = findBestRoute(routes, MAX_TRUCK, ship);
	display(routes[bestRoute], ship);

	if (bestRoute >= 0 && bestRoute < MAX_TRUCK)
	{
		result = trucks[bestRoute].route->routeSymbol;
		trucks[bestRoute].boxSizeTotal += ship.volume;
		trucks[bestRoute].currWeight += ship.weight;
	}

	return result;*/

	int result = -1;
	int size = 0;
	int bestRoute = 0;

	struct Route routes[MAX_ROUTES] = { 0 };
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();

	trucks[0].route = &blueRoute;
	trucks[1].route = &greenRoute;
	trucks[2].route = &yellowRoute;

	if ((trucks[0].currWeight + ship.weight <= MAX_WEIGHT) && (trucks[0].boxSizeTotal + ship.volume <= MAX_SIZE))
		possibleRoutes(ship, trucks[0], baseMap, routes, &size);

	if ((trucks[1].currWeight + ship.weight <= MAX_WEIGHT) && (trucks[1].boxSizeTotal + ship.volume <= MAX_SIZE))
		possibleRoutes(ship, trucks[1], baseMap, routes, &size);

	if ((trucks[2].currWeight + ship.weight <= MAX_WEIGHT) && (trucks[2].boxSizeTotal + ship.volume <= MAX_SIZE))
		possibleRoutes(ship, trucks[2], baseMap, routes, &size);

	bestRoute = findBestRoute(routes, size, ship);
	display(routes[bestRoute], ship);

	if (routes[bestRoute].routeSymbol == 2) {
		trucks[0].boxSizeTotal += ship.volume;
		trucks[0].currWeight += ship.weight;
		result = 2;
	}
	else if (routes[bestRoute].routeSymbol == 4) {
		trucks[1].boxSizeTotal += ship.volume;
		trucks[1].currWeight += ship.weight;
		result = 4;
	}
	else if (routes[bestRoute].routeSymbol == 8) {
		trucks[2].boxSizeTotal += ship.volume;
		trucks[2].currWeight += ship.weight;
		result = 8;
	}

	return result;
}


void result() {
	double size;
	int weight, scanned, length, row, col, i, done = 0, loop = 1, result = 0;
	char p[4], c;

	struct Point des;
	struct Delivery ship = { 0 };
	struct Map map = populateMap();
	baseMap = &map;

	struct Route blue = getBlueRoute();
	struct Route green = getGreenRoute();
	struct Route yellow = getYellowRoute();

	struct Truck truck[3] = {
	{&blue, 0, 0},
	{&green, 0, 0},
	{&yellow, 0, 0} 
	};

	do {
		row = col = weight = 0, length = 0, size = -1;
		des.row = -1, des.col = -1;

		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");

		if (scanf("%d %lf %s", &weight, &size, p) != 3) {
			printf("Invalid input. Follow this format: 1 1 1A\n");

			char ch = 'x';

			while (ch != '\n')
			{
				ch = getchar();
			}
		}
		else {
			length = strlen(p);

			if (weight == 0 && size == 0 && strcmp(p, "x") == 0) {
				done = 1;
				printf("Thank you for shipping with Seneca!\n");
				break;
			}

			for (i = 0; i < length; i++) {
				c = p[i];

				if (c >= '0' && c <= '9')
					row = row * 10 + (c - '0');

				else if (c >= 'A' && c <= 'Z')
					col = col * 26 + (c - 'A') +1;
			}

			//index starts from 0
			des.row = --row;
			des.col = --col;

			if (checkAll(size, weight, des) == 1) {
				ship.volume = size;
				ship.weight = weight;
				ship.destination.row = des.row;
				ship.destination.col = des.col;

				result = findTruck(ship);
			}

		}
	} while (!done);
}