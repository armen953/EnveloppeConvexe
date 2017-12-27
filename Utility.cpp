#include "Utility.h"

int  Utility::distance2D(ColorPoint p1, ColorPoint p2)
{
  return sqrt( pow((p2.getX() - p1.getX()),2) + pow((p2.getY() - p1.getY()),2)  );
}

int Utility::crossProduct(ColorPoint p1, ColorPoint p2, ColorPoint p3)
{
  int x1 = p1.getX() - p2.getX();
  int x2 = p1.getX() - p3.getX();
  int y1 = p1.getY() - p2.getY();
  int y2 = p1.getY() - p3.getY();

  int res = y2 * x1 - y1 * x2;
  // cout << res << endl; // for debug
  return res;
}

int Utility::getIntRandomNb(int min, int max)
{
  return rand() % (max - min) + min;
}


float Utility::getFlatRandNb(float min, float max)
{
  return (max - min) * ((((float)rand()) / (float)RAND_MAX)) + min;
}

void Utility::printArrayPoints(std::vector<ColorPoint> points)
{
  for (int i = 0; i < points.size(); i++)
  {
    std::cout << points.at(i) << std::endl;
  }
}

void Utility::writeConvexePointsToFIle(std::vector<ColorPoint> points)
{
  std::ofstream myfile;
  myfile.open("convexePoints.txt");
  if(!myfile.fail())
  {
    myfile << "Les points qui appartiennent a l'enveloppe convexe :" << std::endl;
    for (int i = 0; i < points.size(); i++)
    {
      myfile << "#" << i << " : " << points.at(i) << std::endl;
    }
  }else
  {
    std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
  }
  myfile.close();
}

void Utility::writePointsFormatedForGeogebra(std::vector<ColorPoint> points)
{
  std::ofstream myfile;
  myfile.open("geo.txt");
  if(!myfile.fail())
  {
    for (int i = 0; i < points.size(); i++)
    {
      myfile << "(" << points.at(i).getX() << "," << points.at(i).getY() << ")" << std::endl;
    }
  }else
  {
    std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
  }
  myfile.close();
}
 