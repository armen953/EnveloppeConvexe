#include "ConvexeHullAlgorithms.h"

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

      if (Utility::crossProduct(pointList.at(pi), pointList.at(i), pointList.at(qi)) < 0)
      {
        qi = i;
      }
      if (Utility::crossProduct(pointList.at(pi), pointList.at(i), pointList.at(qi)) == 0) // les point sont colinéaires
      {
        // Pour debug
        cout << endl;
        cout << "Begin" << endl;
        cout << pointList.at(pi) << endl;
        cout << pointList.at(i) << endl;
        cout << pointList.at(qi) << endl;
        cout << " distance entre : " << pointList.at(pi) << " (pi) et " <<  pointList.at(i) << " (i) est de " << Utility::distance2D(pointList.at(pi),pointList.at(i)) << endl;
        cout << " distance entre : " << pointList.at(pi) << " (pi) et " <<  pointList.at(qi) << " (qi) est de " << Utility::distance2D(pointList.at(pi),pointList.at(qi)) << endl;
        cout << "END" << endl;
        if (Utility::distance2D(pointList.at(pi),pointList.at(i)) > Utility::distance2D(pointList.at(pi),pointList.at(qi))) // on prend le point qui est le plus loin du point de rotation
        {
          qi = i;
        }
      }
    }
    
    if (pointList.at(qi) != firstPts)
    {
      cout << "le point a ete ajouté : " << pointList.at(qi) << endl;
      result.push_back(pointList.at(qi));
    }
    pi = qi;

  } while (pi != startIndex);

  return result;
}
