#ifndef _ConvexeHullAlgorithms_h
#define _ConvexeHullAlgorithms_h

#include "ColorPoint.h"
#include <vector>
#include <math.h>

using namespace std;

class ConvexeHullAlgorithms
{

public:
  /**
     * @description: Prend un tableau de Point, calcule et return les points qui appartiennet a l'enveloppe convexe en utilisant l'algorithme du Marche de Jarvis
     * @params:
     *   vector<ColorPoint> pointList : Liste des points dont il faut calculer l'enveloppe convexe
     * @return: 
     *  un tableau de point qui font partie de l'envelopppe convexe
    */
  static vector<ColorPoint> Jarvis(vector<ColorPoint> pointList);

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
  static int crossProduct(ColorPoint p1, ColorPoint p2, ColorPoint p3);
};

#endif
