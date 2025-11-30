#include "src/Dishstack.hpp"
#include <iostream>
using namespace std;

int main() {
  DishStack stack;

  Dish glintstoneStaff("Glintstone Staff Plate");
  Dish fireGiantHelmet("Fire Giant Helmet Bowl");
  Dish goldenSeed("Golden Seed Dish");
  Dish spiritAsh("Spirit Ash Cup");

  stack.push(glintstoneStaff);
  stack.push(fireGiantHelmet);
  stack.push(goldenSeed);
  stack.push(spiritAsh);

  cout << "Stack size after collecting treasures: " << stack.size() << endl;
  cout << "Most recent item collected: " << stack.peek().get_description() << endl;

  cout << "Used item: " << stack.pop().get_description() << endl;
  cout << "Used item: " << stack.pop().get_description() << endl;

  Dish EldenRing("Elden Ring Legendary Plate");
  stack.push(EldenRing);

  cout << "Final stack size: " << stack.size() << endl;
  cout << "Current top item: " << stack.peek().get_description() << endl;

  return 0;
}
