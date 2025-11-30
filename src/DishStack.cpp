#include "DishStack.hpp"

DishStack::DishStack() {
   top = -1;
}

void DishStack::push(Dish& dish) {
   if (top >= MAX_SIZE - 1) {
      cout << "Stack is full! Cannot push more dishes." << endl;
      return;
   }
   top++;
   stack[top] = &dish;
}

Dish DishStack::pop() {
   if (top < 0) {
      cout << "Stack is empty! Cannot pop." << endl;
      return Dish("No dish");
   }
   Dish popped = *stack[top];
   top--;
   return popped;
}

Dish DishStack::peek() {
   if (top < 0) {
      cout << "Stack is empty! Nothing to peek." << endl;
      return Dish("No dish");
   }
   return *stack[top];
}

int DishStack::size() {
   return top + 1;
}
