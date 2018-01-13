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

  int precIndex = startIndex; 
  int qi;

  do
  {
    qi = (precIndex + 1) % length;

    for (int i = 0; i < length; i++)
    {
      // ne pas tester quand on doit prendre 2 fois le meme point
      if (i == precIndex || i == qi)
      {
        continue;
      }

      if (Utility::crossProduct(pointList.at(precIndex), pointList.at(i), pointList.at(qi)) < 0)
      {
        qi = i;
      }
      if (Utility::crossProduct(pointList.at(precIndex), pointList.at(i), pointList.at(qi)) == 0) // les point sont colinéaires
      {
        // Pour debug
        // cout << endl;
        // cout << "Begin" << endl;
        // cout << pointList.at(precIndex) << endl;
        // cout << pointList.at(i) << endl;
        // cout << pointList.at(qi) << endl;
        // cout << " distance entre : " << pointList.at(precIndex) << " (precIndex) et " <<  pointList.at(i) << " (i) est de " << Utility::distance2D(pointList.at(precIndex),pointList.at(i)) << endl;
        // cout << " distance entre : " << pointList.at(precIndex) << " (precIndex) et " <<  pointList.at(qi) << " (qi) est de " << Utility::distance2D(pointList.at(precIndex),pointList.at(qi)) << endl;
        // cout << "END" << endl;
        if (Utility::distance2D(pointList.at(precIndex),pointList.at(i)) > Utility::distance2D(pointList.at(precIndex),pointList.at(qi))) // on prend le point qui est le plus loin du point de rotation
        {
          qi = i;
        }
      }
    }

    result.push_back(pointList.at(qi));

    precIndex = qi;

  } while (precIndex != startIndex);

  int memeCoord=0;
  int colli=0;
  for (int i = 0; i < result.size()-1; i++)
  { 
    if(result.at(i) == result.at(i+1))
    {
      memeCoord++;
    }
  }

// si tous les points ont la meme coordonées OU si tous les points sont alignés
  if(memeCoord == result.size()-1 || (result.size()-1 <= 2)) 
  {
    result.clear();
    cout << "Tous les point ont le meme coordonnée" << endl;
  }

  return result;
}
