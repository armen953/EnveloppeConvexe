#include "ConvexeHullAlgorithms.h"

int distance2D(ColorPoint p1, ColorPoint p2)
{
  return sqrt( pow((p2.getX() - p1.getX()),2) + pow((p2.getY() - p1.getY()),2)  );
}

vector<ColorPoint> ConvexeHullAlgorithms::Jarvis(vector<ColorPoint> pointList)
{
  vector<ColorPoint> result;
  int length = pointList.size();
  int startIndex;

  // Trouver le point le plus a gauche
  ColorPoint firstPts = pointList.at(0);
  startIndex = 0;
  for (int i = 1; i < length; i++)
  {
    if (pointList.at(i).getX() < firstPts.getX())
    {
      firstPts = pointList.at(i);
      startIndex = i;
    }
    else if(pointList.at(i).getX() == firstPts.getX()) // si 2 pts ont le meme x alors on compare les Y et on prend le plus petit
    {
      if(pointList.at(i).getY() < firstPts.getY())
      {
        firstPts = pointList.at(i);
        startIndex = i;
      }
    }
  }
  cout << "Pts a gauche : " << firstPts << endl;

  result.push_back(firstPts);

  int pi = startIndex; 
  int qi;

  do
  {
    qi = (pi + 1) % length;

    for (int i = 0; i < length; i++)
    {
      if (i == pi || i == qi)
      {
        continue;
      }

      if (crossProduct(pointList.at(pi), pointList.at(i), pointList.at(qi)) < 0)
      {
        qi = i;
        // faire un cout pout tester
      }
      if (crossProduct(pointList.at(pi), pointList.at(i), pointList.at(qi)) == 0)
      {
        // FAIRE l'algo a la main et tester sur geogebra
        cout << endl;
        cout << "Begin" << endl;
        cout << pointList.at(pi) << endl;
        cout << pointList.at(i) << endl;
        cout << pointList.at(qi) << endl;
        cout << " distance entre : " << pointList.at(pi) << " (pi) et " <<  pointList.at(i) << " (i) est de " << distance2D(pointList.at(pi),pointList.at(i)) << endl;
        cout << " distance entre : " << pointList.at(pi) << " (pi) et " <<  pointList.at(qi) << " (qi) est de " << distance2D(pointList.at(pi),pointList.at(qi)) << endl;
        cout << "END" << endl;
        if (distance2D(pointList.at(pi),pointList.at(i)) > distance2D(pointList.at(pi),pointList.at(qi)))
        {
          qi = i;
        }

      }
    }
    if (&pointList.at(qi) != &firstPts)
    {
      cout << "le point a ete ajouté : " << pointList.at(qi) << endl;
      result.push_back(pointList.at(qi));
    }
    pi = qi;

  } while (pi != startIndex);

  return result;
}

int ConvexeHullAlgorithms::crossProduct(ColorPoint p1, ColorPoint p2, ColorPoint p3)
{
  int x1 = p1.getX() - p2.getX();
  int x2 = p1.getX() - p3.getX();
  int y1 = p1.getY() - p2.getY();
  int y2 = p1.getY() - p3.getY();

  int res = y2 * x1 - y1 * x2;
  // cout << res << endl; // for debug
  return res;
}
