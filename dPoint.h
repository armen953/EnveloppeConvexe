#ifndef _dPoint_h
#define _dPoint_h

class dPoint
{
private:
  double x;
  double y;

public:
  dPoint() {}
  dPoint(double _x, double _y);
  /*** Getters ***/
  double getX();
  double getY();
  /*** Setters ***/
  void setX(double _x);
  void setY(double _y);
};

#endif
