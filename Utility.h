#ifndef _Utility_
#define _Utility_

#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ColorPoint.h"

namespace Utility
{
  /**
   * @description: Calcule la distance entre 2 points
   * @params: 
   *  ColorPoint p1
   *  ColorPoint p2
   * @return: La distance entre les 2 points
  */
  int distance(ColorPoint p1, ColorPoint p2);

  /** 
     * @description: 
     *  determine si le point p3 est a gauche ou a droite du segment [p1,p2] en effectuant un produit vectoriel entre p1p2 et p1p3
     *  - si le res > 0 alros le point est a gauche 
     *  - si le res < 0 alros le point est a droite 
     *  - si le res = 0 alors les point sont aligné (colinaire)
     * @params: 
     *  ColorPoint p1: Le point qui sert de reference
     *  ColorPoint p2: Le point qui sert de reference
     *  ColorPoint P3: Le point a verifier
     * @return:
     *  le resultat du produit vectoriel
    */
  int crossProduct(ColorPoint p1, ColorPoint p2, ColorPoint p3);

  /**
   * @description: Ecrit dans un fichier les points passé en parametre (crée un fichier convexePoints.txt)
   * @params: 
   *  vector<ColorPoint> points: Les point a ecrire dans le fichier
   * @return: void
  */
  void writeConvexePointsToFIle(std::vector<ColorPoint> points);

  /**
   * @description: Ecrit dans un fichier les points passé en parametre sous le forme (X,Y). Crée un fichier geo.txt
   * @params: 
   *  vector<ColorPoint> points: Les point a ecrire dans le fichier
   * @return: void
  */
  void writePointsFormatedForGeogebra(std::vector<ColorPoint> points);
};

#endif