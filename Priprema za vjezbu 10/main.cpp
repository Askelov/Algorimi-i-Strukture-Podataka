#include <iostream>
#include <string.h>
#include "UsmjereniGraf.h"

int main() {
    UsmjereniGraf<bool> *g = new MatricaGraf<bool>(6);
  g->dodajGranu(0, 1, 2.5);
  g->dodajGranu(1, 2, 1.2);
  g->dodajGranu(1, 3, 0.1);
  g->dodajGranu(3, 3, -4.0);
  g->dodajGranu(2, 4, 3.14);
  g->dodajGranu(2, 3, 2.73);
  g->dodajGranu(3, 5, 1);
  g->dodajGranu(5, 2, -5.0);
  g->obrisiGranu(1,2);
  g->obrisiGranu(3,5);
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
     std:: cout << g->postojiGrana(i, j);
  delete g;

UsmjereniGraf<std::string> *k = new MatricaGraf<std::string>(4);
  k->postaviOznakuCvora(0,"a");
  k->postaviOznakuCvora(1,"bcd");
  for (int i = 0; i < 4; i++)
      std::cout << "(" << i << ") -> '" << k->dajOznakuCvora(i) << "'; ";
  delete k;
    return 0;
}
