#include <stdio.h>
#include "mapping.h"


// Helper function 1 - Test cases for valid location checking

int checkMapCoordinates(const struct Map* map) {
    int rowCal = map->numRows;
    int colCal = map->numCols;

    for (int i = 0; i < rowCal; i++) {
        if (i < 0 || i >= 25) {
            printf("Row coordinate out of range: %d\n", i + 1);
            return 0;
        }
        for (int j = 0; j < colCal; j++) {
            if (j < 0 || j >= 25) {
                printf("Column coordinate out of range: %d\n", j);
                return 0;
            }
        }
    }
    return 1;
}

// Test Case 1: populateMap()-> checkbox(struct point location)
void test_populateMap()
{
    //display format of map
    struct Map map = populateMap();

    // Verify if the rows,number in 25
    if (map.numRows == 10 && map.numCols == 10)
        printf("populateMap test 1 passed!\n");
    else
        printf("populateMap test 1 failed!\n");

    // Verify if one is out of range
    if (map.numRows == 20 && map.numCols == -1)
        printf("populateMap test 2 passed!\n");
    else
        printf("populateMap test 2 failed!\n");

    // If we put different type of argument then program wont accept-> comfile error

    // Verify case when both are 0
    if (map.numRows == 0 && map.numCols == 0)
        printf("populateMap test 3 passed!\n");
    else
        printf("populateMap test 3 failed!\n");

    printf("\n");
}


// => print, addRoute blackbox testing code will be implemented at ms4