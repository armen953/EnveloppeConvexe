#ifndef _ConvexeHullAlgorithms_h
#define _ConvexeHullAlgorithms_h

#include <vector>
#include <math.h>
#include "ColorPoint.h"
#include "Utility.h"

using namespace std;

class ConvexeHullAlgorithms
{

public:
  /**
     * @description: Prend un tableau de Point, calcule et return les points qui appartiennent a l'enveloppe convexe en utilisant l'algorithme du Marche de Jarvis
     * @params:
     *   vector<ColorPoint> pointList : Liste des points dont il faut calculer l'enveloppe convexe
     * @return: 
     *  un tableau de point qui font partie de l'envelopppe convexe
    */
  static vector<ColorPoint> Jarvis(vector<ColorPoint> pointList);

};

#endif
