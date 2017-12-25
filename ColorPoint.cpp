#include "ColorPoint.h"
#include <iostream>

ColorPoint::ColorPoint(double _x, double _y, double _red, double _green, double _blue, double _size)
    : dPoint(_x, _y), red(_red), green(_green), blue(_blue), size(_size) {}

double ColorPoint::getRed()
{
  return red;
}

double ColorPoint::getGreen()
{
  return green;
}

double ColorPoint::getBlue()
{
  return blue;
}

double ColorPoint::getSize()
{
  return size;
}

void ColorPoint::setRed(double _red)
{
  red = _red;
}

void ColorPoint::setGreen(double _green)
{
  green = _green;
}

void ColorPoint::setBlue(double _blue)
{
  blue = _blue;
}

void ColorPoint::setSize(double _size)
{
  size = _size;
}

/**
 * Surcharge de l'opérateur << pour la class Colorpoint
*/
std::ostream &operator<<(std::ostream &os, ColorPoint cp)
{
  return os << "x = " << cp.getX() << " y= " << cp.getY();
}

bool operator==(ColorPoint p1, ColorPoint p2)
{
  return ((p1.getX() == p2.getX()) && (p1.getY() == p2.getY()));
}

bool operator!=(ColorPoint p1, ColorPoint p2)
{
  return ((p1.getX() != p2.getX()) && (p1.getY() != p2.getY()));
}
