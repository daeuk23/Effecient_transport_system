//code work for confirming whether printing map is working properly or not
// sft MS4 - group1 blackbox testing code, helper codes

#include <stdio.h>
#include "mapping.h"


// Test Case 1: check rows and cols if its validate value
void tempMapGenerator()
{
    struct Map tmpMap = populateMap();

    // Verify the number default of rows and columns
    if (tmpMap.numRows == MAP_ROWS && tmpMap.numCols == MAP_COLS)
        printf("valid input made PASS!\n");
    else
        printf("Invalid input made FAIL!\n");
    printf("\n");
}


// Test Case 2: populateMap()-> checkbox(struct point location)
void printMapTester()
{
    //display format of map
    struct Map m1 = populateMap();
    // Case 1: Verify if the rows,number in 25
    printMap(&m1, 25, 25);
    printf("\n");
    if (printMapChecker(&m1))
        printf("printing map method 1 passed!\n");
    else
        printf("printing map method 1 failed!\n");

    // Case 2: Verify if one is out of range
    struct Map m2 = populateMap();
    printMap(&m2, 15, -3);
    printf("\n");
    if (printMapChecker(&m2))
        printf("printing map method 2 passed!\n");
    else
        printf("printing map method 2 failed!\n");

    // If we put different type of argument then program wont accept-> comfile error

    // Case 3: Verify case when both are 0
    struct Map m3 = populateMap();
    printMap(&m3, 0, 0);
    printf("\n");
    if (printMapChecker(&m3))
        printf("printing map method 3 passed!\n");
    else
        printf("printing map method 3 failed!\n");
    printf("\n");

    // Case 4: Verify if this function works when values are not int type
    struct Map m4 = populateMap();
    printMap(&m4, 15, "abc");
    printf("\n");
    if (printMapChecker(&m4))
        printf("printing map method 4 passed!\n");
    else
        printf("printing map method 4 failed!\n");
    printf("\n");
}

// printing temp map format with a example to simply run itself 
void printMapFormat(const struct Map* map) {
    int rowMax = map->numRows;

    //print header
    printf("%4s", " ");
    for (int i = 0; i < map->numCols; i++) {
        printf("%c", 'A' + i);
    }
    printf("\n");

    //line and blank to identify the part
    printf("%4s", " ");
    for (int i = 0; i < map->numCols; i++) {
        printf("-");
    }
    printf("\n");

    //print map conts
    for (int i = 1; i <= rowMax; i++) {
        printf("%3d|", i);
        for (int j = 0; j < map->numCols; j++) {
            printf("%d", map->squares[j - 1][i]);
        }
        printf("\n");
    }
}

// Helper function - Test cases for valid location checking => resolveing the valid value with return val
int printMapChecker(const struct Map* map) {
    int rowCal = map->numRows;
    int colCal = map->numCols;

    for (int i = 0; i < rowCal; i++) {
        if (i < 0 || i >= 25) {
            printf("Invalid Row Value: %d\n", i + 1);
            return 0;
        }
        for (int j = 0; j < colCal; j++) {
            if (j < 0 || j >= 25) {
                printf("Invalid Column Value: %d\n", j);
                return 0;
            }
        }
    }
    return 1;
}


/*void main()
{
    tempMapGenerator();
    printMapTester();
    return 0;
}*/
