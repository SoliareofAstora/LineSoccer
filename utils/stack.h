#pragma once

template<typename T>
class stack {
  struct node {
    T value;
    node* prev;
  };
  node* last;
  int length;

 public:
  stack();
  ~stack();

  void push(T x); // Dodaje element na stos
  T pop();        // Usuwa element ze stosu
  T &top();       // Zwraca referencj� do ostatniego elementu
  int size();       // Zwraca liczb� element�w na stosie
  bool empty();     // Sprawdza czy stos jest pusty
};

