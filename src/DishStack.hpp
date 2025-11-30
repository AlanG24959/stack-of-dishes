#pragma once
#include "Dish.h"
#include <iostream>
using namespace std;

class DishStack {
private:
  static const int MAX_SIZE = 100;
  Dish* stack[MAX_SIZE];
  int top;

public:
  DishStack();
  void push(Dish& dish);
  Dish pop();
  Dish peek();
  int size();
};
