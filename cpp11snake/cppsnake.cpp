#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include "cppsnake.h"


using namespace std;


vector<int*> generateInputArray(int dimension) {

  vector<int*> array(dimension);

  auto gen = []()->int {
    static auto i = 0;
    return i++;
  };

  for (auto itr = array.begin(); itr != array.end(); itr++ ) {
    int* row = new int[dimension];
    generate(row, row + dimension, gen);
    *itr = row;
  }

  cout << "finished generating input array of dimension " << dimension << endl;
  return array;

}


void destroyInputArray(vector<int*>& inputArray) {

  for (auto itr = inputArray.begin(); itr != inputArray.end(); itr++ ) {
    delete[] (*itr);
  }

  cout << "cleaning up the input array" <<endl;
}


// dump the input array for reference purpose
void printInputArray(vector<int*>& inputArray, int dimension) {

  cout << "printing out the input array" << endl;
  
  for ( auto itr = inputArray.begin(); itr != inputArray.end(); itr++ ) {
    for ( auto i =0; i < dimension; i++ ) {
      cout <<setw(5)<<(*itr)[i];
    }
    cout<<endl;
  }

}

// calculate the four corner cordindates, will be used in snakePrint
vector<Point> calcualteCoordinates(int rounds, int dimension) {
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
    cout << "printing out the input array in a snake pattern" << endl;
  }

  // check the exit condition
  auto dimension = inputArray.size();
  auto remaining = dimension - 2 * rounds;

  if ( remaining == 0 ) {
    return;
  }

  if ( remaining == 1 ) {
    cout << inputArray[rounds][rounds];
    return;
  }

  auto coordinates = calcualteCoordinates(rounds, dimension);
  for ( auto col = coordinates[topLeft].x; col < coordinates[topRight].x; col++ ) {
    cout << setw(5) << inputArray[coordinates[topRight].y][col];
  }
  cout << endl;

  for ( auto row = coordinates[topRight].y; row < coordinates[bottomRight].y; row++ ) {
    cout << setw(5) << inputArray[row][coordinates[topRight].x];
  }
  cout << endl;


  for ( auto col = coordinates[bottomRight].x; col > coordinates[bottomLeft].x; col-- ) {
    cout << setw(5) << inputArray[coordinates[bottomRight].y][col];
  }
  cout << endl;

  for ( auto row = coordinates[bottomLeft].y; row > coordinates[topLeft].y; row-- ) {
    cout << setw(5) << inputArray[row][coordinates[bottomLeft].x];
  }
  cout << endl;

  // recursively call
  rounds++;
  snakePrint(rounds, inputArray);
 }


int main(int argc, char* argv[] ) {
  // create the input
  auto inputArray = generateInputArray(10);
  cout << endl << endl;
  
  // print out the input for reference purpose
  printInputArray(inputArray, 10);
  cout << endl << endl;
  
  // print the input in a snake pattern, real work here
  snakePrint(0, inputArray);
  cout << endl << endl;
  
  // done, clean up
  destroyInputArray(inputArray);

  char c;
  cin.get(c);

}
