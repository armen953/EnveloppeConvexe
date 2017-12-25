#ifndef _ColorPoint_h
#define _ColorPoint_h

#include "dPoint.h"
#include <iostream>

class ColorPoint : public dPoint
{
private:
  double red;
  double green;
  double blue;
  double size;

public:
  ColorPoint() {}
  // Constructeur avec des parametres par defaut
  ColorPoint(double _x, double _y, double _red = 0.0, double _green = 0.0, double _blue = 0.0, double _size = 10.0);
  /*** Getters ***/
  double getRed();
  double getGreen();
  double getBlue();
  double getSize();
  /*** Setters ***/
  void setRed(double _red);
  void setGreen(double _green);
  void setBlue(double _blue);
  void setSize(double _size);
};

std::ostream &operator<<(std::ostream &os, ColorPoint cp);
bool operator==(ColorPoint p1, ColorPoint p2);
bool operator!=(ColorPoint p1, ColorPoint p2);

#endif
