#include "csnake.h"
#include <stdio.h>
#include <stdlib.h>

typedef int (**SNAKE_INPUT);

// generate input array
void generateInputArray(int dimension, SNAKE_INPUT* outArray ) {

  int i = 0;
  int j = 0;

  // allocate memory for input array
  SNAKE_INPUT array = malloc( sizeof(SNAKE_INPUT) * dimension);

  for ( i = 0; i < dimension; i++ ) {
    array[i] = (int *) malloc (sizeof(int) * dimension );
  }

  //now filling the array with number
  for ( i = 0; i < dimension; i++ ) {
    for ( j = 0; j < dimension; j++ ) {
      array[i][j] = i*dimension + j;
    }
  }

  *outArray = array;
}


void cleanupInputArray(int dimension, SNAKE_INPUT array ) {

  int i = 0;
  for ( i = 0; i < dimension; i++ ) {
    free(array[i]);
  }

  // now time for the array itself
  free(array);

}
  

// used to print out the input array for reference purpose
void printInputArray(int dimension, SNAKE_INPUT array) {

  int i = 0;
  int j = 0;

  for ( i = 0; i < dimension; i++ ) {
    for ( j = 0; j < dimension; j++ ) {
      printf("%5d", array[i][j]);
    }
     printf("\n");
  }
}



// calculate the corner cordinates of the reduced array after certain rounds
void calculateCornerCoordinates(int rounds, int dimension, Point cornerCoordinates[4] ) {

  cornerCoordinates[topLeft].x = rounds;
  cornerCoordinates[topLeft].y = rounds;

  cornerCoordinates[topRight].x = dimension - 1 - rounds;
  cornerCoordinates[topRight].y = cornerCoordinates[topLeft].y;

  cornerCoordinates[bottomRight].x = cornerCoordinates[topRight].x;
  cornerCoordinates[bottomRight].y = dimension - 1 - rounds;

  cornerCoordinates[bottomLeft].x = cornerCoordinates[topLeft].x;
  cornerCoordinates[bottomLeft].y = cornerCoordinates[bottomRight].y; 
  
}


void snakePrint(int rounds, int dimension, SNAKE_INPUT array) {

  // determine if we need to stop
  int remainingDimension = dimension - 2*rounds;

  if (remainingDimension == 0 ) return;

  if (remainingDimension == 1 ) {
    printf("%5d\n", array[rounds][rounds]);
    return;
  }

  // prepare a cordinat array to hold the cordinates of the four corner points
  Point cordinates[4] = { {0,0},{0,0},{0,0},{0,0}};
  calculateCornerCoordinates(rounds, dimension, cordinates);
  
  // actual printing happens now
  // from top left corner to top right
  int row = 0;
  int col = 0;

  for ( col = cordinates[topLeft].x; col < cordinates[topRight].x; col++ ) {
    printf("%5d", array[cordinates[topLeft].y][col]);
  }
  printf("\n");

  // from top right to bottom right
  for (  row = cordinates[topRight].y; row  < cordinates[bottomRight].y ; row++ ) {
    printf("%5d", array[row][cordinates[topRight].x]);
  }
  printf("\n");

  // from bottom right to bottom left
  for (  col = cordinates[bottomRight].x ; col > cordinates[bottomLeft].x; col-- ) {
    printf("%5d",array[cordinates[bottomRight].y][col]);
  }
  printf("\n");

  // from bottom left to bottom right
  for (  row = cordinates[bottomLeft].y; row > cordinates[topLeft].y; row-- ) {
    printf("%5d", array[row][cordinates[topLeft].x]);
  }
  printf("\n");

  rounds++;
  snakePrint(rounds,dimension, array);
      
}

int main(int argc, char* argv[] ) {

  // array will hold the generated input array
  SNAKE_INPUT array = NULL;

  // generate input 
  generateInputArray(10, &array);
  
  //show the input array for verification purpose
  printInputArray(10, array);

  printf("\n\n");
  
  // kick start the printing, start from 0
  snakePrint(0, 10, array);

  cleanupInputArray(10, array);
  
  return 0;
}
