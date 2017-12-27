/*********************************************************/
/*                    OpenGL.ccp                         */
/*********************************************************/
/*                                                       */
/*********************************************************/

/* inclusion des fichiers d'en-tete Glut */
#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <jerror.h>

#include <vector>
#include "ConvexeHullAlgorithms.h"
#include "ColorPoint.h"
#include "Utility.h"

using namespace std;
#define Pi 3.141592654

double Scal = 6; //36;

double trX = 0.0, trY = 0.0, dist = 0.; //,trZ=0.0
char presse;
int anglex, angley, x, y, xold, yold;

vector<ColorPoint> list; // liste qui va contenir tous les point
vector<ColorPoint> convexe; // liste qui va contenir tous les point appartenant a l'enveloppe convexe

/* Prototype des fonctions */
void affichage(); //  procedure a modifier en fonction de la scene
void clavier(unsigned char touche, int x, int y);
void reshape(int x, int y);
void idle();
void mouse(int bouton, int etat, int x, int y);
void mousemotion(int x, int y);


//-************************************************************
//
//  Procedure avec mise en file des sommets des primitives
//
//-***********************************************************
void init();

int main(int argc, char **argv)
{
  /* initialisation de glut et creation de la fenetre */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("RQBC et conique.");
  /* Initialisation d'OpenGL */
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glColor3f(0.0, 0.0, 0.0);
  glPointSize(2.0);
  glEnable(GL_DEPTH_TEST);

  glColor3f(0.0, 0.0, 0.0);
  //glEdgeFlag(GL_FALSE);
  glEdgeFlag(GL_TRUE);
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  // glEnable(GL_LIGHTING);
  glDisable(GL_LIGHTING);

  /* enregistrement des fonctions de rappel */
  init();
  glutDisplayFunc(affichage);
  glutKeyboardFunc(clavier);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMotionFunc(mousemotion);

  /* Entree dans la boucle principale glut */
  glutMainLoop();
  return 0;
}

void clavier(unsigned char touche, int x, int y)
{
  switch (touche)
  {
  case 'q': /*la touche 'q' permet de quitter le programme */
    exit(0);
  case '+':
    dist += 0.5;
    Scal = Scal + 0.5;
    glutPostRedisplay();
    break;
  case '-':
    dist -= 0.5;
    Scal = Scal - 0.5;
    glutPostRedisplay();
    break;
  case '6':
    trX -= 0.25;
    glutPostRedisplay();
    break;
  case '4':
    trX += 0.25;
    glutPostRedisplay();
    break;
  case '8':
    trY += 0.25;
    glutPostRedisplay();
    break;
  case '2':
    trY -= 0.25;
    glutPostRedisplay();
    break;
  }
}

void reshape(int x, int y)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //taille de la scene
  double Ortho = -150;
  glOrtho(-Ortho, Ortho, -Ortho, Ortho, -Ortho, Ortho); // fenetre
  glMatrixMode(GL_MODELVIEW);
  glViewport(0, 0, x, y);
}

void mouse(int button, int state, int x, int y)
{
  /* si on appuie sur le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    presse = 1; /* le booleen presse passe a 1 (vrai) */
    xold = x;   /* on sauvegarde la position de la souris */
    yold = y;

    cout << "click" << endl;
  }
  /* si on relache le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    presse = 0; /* le booleen presse passe a 0 (faux) */
}

void mousemotion(int x, int y)
{
  if (presse) /* si le bouton gauche est presse */
  {
    /* on modifie les angles de rotation de l'objet
    en fonction de la position actuelle de la souris et de la derniere
    position sauvegardee */
    anglex = anglex + (x - xold);
    angley = angley + (y - yold);
    glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
  }

  xold = x; /* sauvegarde des valeurs courante de le position de la souris */
  yold = y;
}

/****************************************************************
 **                                                            **
 **                    Affichage de  la scene                  **
 **                                                            **
 ****************************************************************/

void openGL(ColorPoint p)
{
  glColor3f(p.getRed(), p.getGreen(), p.getBlue()); //initialisation de la couleur
  glPointSize(p.getSize());                         // initialisation de la taille
  glBegin(GL_POINTS);                               // on trace un point
  glVertex2f(p.getX(), p.getY());                   // coordonnees du point
  glEnd();                                          // fin de glBegin
}

void trace_segment(ColorPoint p1, ColorPoint p2, double red, double green, double blue, double size)
{
  glColor3f(red, green, blue);      //initialisation de la couleur
  glLineWidth(size);                // initialisation de la taille
  glBegin(GL_LINES);                // on trace un segment
  glVertex2f(p1.getX(), p1.getY()); // coordonnees du premier point
  glVertex2f(p2.getX(), p2.getY()); // coordonnees du dernier point
  glEnd();                          // fin de glBegin
}

//fonction ou les objets sont a definir
void init()
{
  srand(time(NULL));

  // list.push_back(ColorPoint(5., 4.));
  // list.push_back(ColorPoint(17., 12.));
  // list.push_back(ColorPoint(9., 12.));
  // list.push_back(ColorPoint(-7, 9, 3.));
  // list.push_back(ColorPoint(11., 22.));
  // list.push_back(ColorPoint(3., 16.));


       /********* fichier 2 sous geogebra **********/
  // list.push_back(ColorPoint(2.98, 5.89));
  // list.push_back(ColorPoint(6.73, 2.91));
  // list.push_back(ColorPoint(-3.05, 5.49));
  // list.push_back(ColorPoint(-1.93, 2.33));
  // list.push_back(ColorPoint(3, 2));
  // list.push_back(ColorPoint(0.98, 4.22));
  // list.push_back(ColorPoint(-4.26, 0.67));
  // list.push_back(ColorPoint(-2.1, -2.77));
  // list.push_back(ColorPoint(-0.32, -0.55));
  // list.push_back(ColorPoint(1.22, 0.99));
  // list.push_back(ColorPoint(5.94, -4.25));
  // list.push_back(ColorPoint(7.82, -1.35));
  // list.push_back(ColorPoint(2.68, -4.05));



     /********* cas de points colinaires (fichier 6 sous geo) **********/
  // list.push_back(ColorPoint(2.,1.));
  // list.push_back(ColorPoint(1.,1.));
  // list.push_back(ColorPoint(5.,3.));
  // list.push_back(ColorPoint(4.,1.));
  // list.push_back(ColorPoint(5.,1.));
  // list.push_back(ColorPoint(3.,1.));


    /*********  test (fichier 1 sous geo) **********/
  // list.push_back(ColorPoint(2,0));
  // list.push_back(ColorPoint(6,0));
  // list.push_back(ColorPoint(3,0));
  // list.push_back(ColorPoint(3,4));




  /********* fait BUGER SANS RAISON **********/
  // list.push_back(ColorPoint(1.,1.));
  // list.push_back(ColorPoint(4.,1.));
  // list.push_back(ColorPoint(3.,1.));
  // list.push_back(ColorPoint(2.,3.));


    /********* fichier 4 geogebra **********/
  // list.push_back(ColorPoint(-1,2));
  // list.push_back(ColorPoint(2,1));
  // list.push_back(ColorPoint(1,0));
  // list.push_back(ColorPoint(3,-1));
  // list.push_back(ColorPoint(1,-1));
  // list.push_back(ColorPoint(-1,1));
  // list.push_back(ColorPoint(-2,0)); // a ajouter pour fichier 4B_StartXMeme geogebra
  // list.push_back(ColorPoint(-2,-1));
  // list.push_back(ColorPoint(-1,-2));
  // list.push_back(ColorPoint(-1,-1));

  // list.push_back(ColorPoint(2,0));
  // list.push_back(ColorPoint(6,0));
  // list.push_back(ColorPoint(3,0));  // prend en compte les point colinaires
  // list.push_back(ColorPoint(2.,1.));
  // list.push_back(ColorPoint(3,4));

  float minCoords = -100.; //-50.; //-25.5;
  float maxCoords = 100.; //50.; //25.7;
  // 25
  for (int i = 0; i < 50; i++)
  {
    list.push_back(ColorPoint(Utility::getFlatRandNb(minCoords,maxCoords), Utility::getFlatRandNb(minCoords,maxCoords)));
  }

  
  if (list.size() > 0)
  {
    convexe = ConvexeHullAlgorithms::Jarvis(list);
  }else
  {
    cout << "Aucun point n'as été ajouté" << endl;
  }
  for (int i = 0; i < convexe.size(); i++)
  {
    cout << convexe.at(i) << endl;
  }

  Utility::writeConvexePointsToFIle(list);


  // double xO=0.,yO=0.,xI=1.,yI=0.,xJ=0.,yJ=1.;
  ColorPoint I(1., 0., 1., 0., 0., 10.);  // point I
  ColorPoint J(0., 1., 0., 0.5, 0., 10.); // point J
  ColorPoint O(0., 0., 0., 0., 1., 15.);  // point O

  glNewList(1, GL_COMPILE_AND_EXECUTE); //liste numero 1
    openGL(I);                            //I
    openGL(J);                            //J
    openGL(O);                            //O
  glEndList();

  glNewList(2, GL_COMPILE_AND_EXECUTE);     //liste numero 2
    trace_segment(O, I, 1.0, 0.0, 1.0, 2.0);  // on trace [OI]
    trace_segment(O, J, 1.0, 0.50, 0.0, 2.0); // on trace [OJ]
  glEndList();

  // afficher les points
  glNewList(4, GL_COMPILE_AND_EXECUTE); //liste numero 4
    if (list.size() > 0)
    {
      for (int i = 0; i < list.size(); i++)
      {
        openGL(list[i]);
        // cout << list[i] << endl; // affichier les point dans la console
      }
    }
  glEndList();

  // tracer les segements
  glNewList(5, GL_COMPILE_AND_EXECUTE); //liste numero 
    if (convexe.size() > 0)
    {
      for (int i = 0; i < convexe.size() - 1; i++)
      {
        trace_segment(convexe[i], convexe[i + 1], 1.0, 0.50, 0.0, 2.0);
      }
    }
  glEndList();

  glNewList(6, GL_COMPILE_AND_EXECUTE); //liste numero 6

  glEndList();

  cout << "\nVoila, c'est fini" << endl;
}

// fonction permettant d'afficher les objets en utilisant des listes
void affichage()
{
  cout << "fnc affichage appelé" << endl;
  
  /* effacement de l'image avec la couleur de fond */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();


  glTranslatef(0.0, 0.0, dist);
  // Pour la 3D
  // glRotatef(-angley,1.0,0.0,0.0);
  //  glRotatef(-anglex,0.0,1.0,0.0);
  // Pour la 2D
  glRotatef(-anglex + angley, 0.0, 0.0, 1.0);
  glScalef(Scal, Scal, Scal); // diminution de la vue de la scene
  glRotatef(180, 0.0, 1.0, 0.0);
  glRotatef(180, 1.0, 0.0, 0.0);
  glTranslatef(-trX, trY, 0.);
  glCallList(1); // appel de la liste numero 1
  glCallList(2); // appel de la liste numero 2
  glCallList(4); // appel de la liste numero 4
  glCallList(5);
  glCallList(6);
  glFlush();
  glutSwapBuffers(); // On echange les buffers
}
