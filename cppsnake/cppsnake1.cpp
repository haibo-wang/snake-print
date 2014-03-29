#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include "cppsnake.h"
#include "SimpleGen.h"

using namespace std;


vector<int*> generateInputArray(int dimension) {

  vector<int*> array;

  for ( int i = 0; i < dimension; i++ ) {
    SimpleGen gen(dimension * i);
    int* row = new int[dimension];
    generate(row, row + dimension, gen);
    array.push_back(row);
  }

  cout << "finished generating input array of dimension " << dimension << endl;
  return array;

}


void destroyInputArray(vector<int*>& inputArray) {
  vector<int*>::iterator itr;

  for ( itr = inputArray.begin(); itr != inputArray.end(); itr++ ) {
    delete[] (*itr);
  }

  cout << "cleaning up the input array" <<endl;
}


// dump the input array for reference purpose
void printInputArray(vector<int*>& inputArray, int dimension) {

  cout << "printing out the input array" << endl;
  
  vector<int*>::iterator itr;
  for ( itr = inputArray.begin(); itr != inputArray.end(); itr++ ) {
    for ( int i =0; i < dimension; i++ ) {
      cout <<setw(5)<<(*itr)[i];
    }
    cout<<endl;
  }

}

// calculate the four corner cordindates, will be used in snakePrint
vector<Point> calculateCoordinates(int rounds, int dimension) {

  vector<Point> coordinates(4);

  coordinates[topLeft].x = rounds;
  coordinates[topLeft].y = rounds;

  coordinates[topRight].x = dimension -1 - rounds;
  coordinates[topRight].y = coordinates[topLeft].y;

  coordinates[bottomRight].x = coordinates[topRight].x;
  coordinates[bottomRight].y = dimension - 1 - rounds;

  coordinates[bottomLeft].x = coordinates[topLeft].x;
  coordinates[bottomLeft].y = coordinates[bottomRight].y;

  return coordinates;
  
}


// snake print the array
void snakePrint(int rounds, vector<int*>& inputArray) {

  if ( rounds == 0 ) {
    cout << "printing out the input array in snake pattern" << endl;
  }

  // check the exit condition
  int dimension = inputArray.size();
  int remaining = dimension - 2 * rounds;

  if ( remaining == 0 ) {
    return;
  }

  if ( remaining == 1 ) {
    cout << inputArray[rounds][rounds];
    return;
  }

  vector<Point> coordinates = calculateCoordinates(rounds, dimension);
  for ( int col = coordinates[topLeft].x; col < coordinates[topRight].x; col++ ) {
    cout << setw(5) << inputArray[coordinates[topRight].y][col];
  }
  cout << endl;

  for ( int row = coordinates[topRight].y; row < coordinates[bottomRight].y; row++ ) {
    cout << setw(5) << inputArray[row][coordinates[topRight].x];
  }
  cout << endl;


  for ( int col = coordinates[bottomRight].x; col > coordinates[bottomLeft].x; col-- ) {
    cout << setw(5) << inputArray[coordinates[bottomRight].y][col];
  }
  cout << endl;

  for ( int row = coordinates[bottomLeft].y; row > coordinates[topLeft].y; row-- ) {
    cout << setw(5) << inputArray[row][coordinates[bottomLeft].x];
  }
  cout << endl;

  // recursively call this fucntion
  rounds++;
  snakePrint(rounds, inputArray);
 }


int main(int argc, char* argv[] ) {
  // generate input
  vector<int*> inputArray = generateInputArray(10);
  cout << endl << endl;
  
  // print out the input for reference
  printInputArray(inputArray, 10);
  cout << endl << endl;
  
  // print the input in snake pattern, real work is done here
  snakePrint(0, inputArray);
  cout << endl << endl;
  
  // done, clean up
  destroyInputArray(inputArray);

}
