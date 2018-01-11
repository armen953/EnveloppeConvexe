#ifndef _Utility_
#define _Utility_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
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
  int distance2D(ColorPoint p1, ColorPoint p2);

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
     *  int: le resultat du produit vectoriel
    */
  int crossProduct(ColorPoint p1, ColorPoint p2, ColorPoint p3);

  /**
   * @description: Genere un nobre aleatoire entre 2 nombres entiers
   * @params:
   *  int min: le mininumm du nombre aléatoire
   *  int max: le maximum du nombre aléatoire 
   * @return:
   *  int: le nombre aleatoire généré
  */
  int getIntRandomNb(int min, int max);

  /**
   * @description: Genere un nobre aleatoire entre 2 nombres decimal
   * @params: 
   *  float min: le mininumm du nombre aléatoire
   *  float max: le maximum du nombre aléatoire 
   * @return: 
   *  float: le nombre aleatoire généré
  */
  float getFlatRandNb(float min, float max);


  /**
   * @description: Affiche tous les elements d'un taleau de point
   * @params: 
   *  vector<ColorPoint> points: liste des points a afficher
   * @return: void
  */
  void printArrayPoints(std::vector<ColorPoint> points);

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

  /**
   * @description: Ecrit dans un fichier en mettant en forme pour aciliter la reprise des points aléatoirement généré
   * @params: 
   *  vector<ColorPoint> points: Les point a ecrire dans le fichier
   * @return: void
  */    
  void debugPoints(std::vector<ColorPoint> points);
};

#endif