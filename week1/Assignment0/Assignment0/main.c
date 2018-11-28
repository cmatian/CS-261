/***********************************************************
**
** Christopher Matian
** 1/12/2018
** Assignment 0 - Area of Triangle
**
************************************************************/

#include <stdio.h>
#include <math.h>

// Heron's Formula
// Area of Triangle Function Declaration and Definition
int areaOfTriangle( int s1, int s2, int s3) {
    
    // First Calculation
    int x = (s1 + s2 + s3) / 2;
    
    // Final Calculation based on Heron's Formula
    int area = sqrt( x * (x - s1) * (x - s2) * (x - s3) );
    
    // Return the area
    return area;
    
}

int main(int argc, const char * argv[]) {
    
    // Variable Definitions
    int side1 = 30;
    int side2 = 28;
    int side3 = 26;
    
    // findArea variable calls area calculation function
    int findArea = areaOfTriangle(side1, side2, side3);
    
    // Print the results of findArea
    printf("%d\n", findArea);

    return 0;
}
