#include "dPoint.h"

dPoint::dPoint(double _x, double _y) : x(_x), y(_y) {}

double dPoint::getX()
{
  return x;
}

double dPoint::getY()
{
  return y;
}

void dPoint::setX(double _x)
{
  x = _x;
}

void dPoint::setY(double _y)
{
  y = _y;
}
