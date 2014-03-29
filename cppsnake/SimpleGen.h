#ifndef SIMPLEGEN_H
#define SIMPLEGEN_H

class SimpleGen {
 private:
  int _initial;

 public:
  SimpleGen(int initial);

  int operator()();

};

  
#endif
