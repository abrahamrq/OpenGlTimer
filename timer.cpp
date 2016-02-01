//Oscar Abraham Rodriguez Quintanilla
//Tania Garrido Salido
#define _USE_MATH_DEFINES
#ifdef __APPLE__
#include <GLUT/glut.h>#D1EAF0
#else
#include <GL/glut.h>
#endif 

#include <stdlib.h>
#include <math.h>
// Tamaño inicial de la ventana
GLsizei winWidth =600, winHeight =600;
void init(void){
  glClearColor(1.0,1.0,1.0,1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

// void randomBackgroundWithViewport(int viewPortX, int viewPortY, int viewPortSize){
//   glScissor(viewPortX, viewPortY, viewPortSize, viewPortSize);
//   glEnable(GL_SCISSOR_TEST);
//   glClearColor(rand() / (RAND_MAX + 1.), rand() / (RAND_MAX + 1.), rand() / (RAND_MAX + 1.), 1.0);
//   glClear(GL_COLOR_BUFFER_BIT);
// }

void randomBackground(){
  glClearColor(rand() / (RAND_MAX + 1.), rand() / (RAND_MAX + 1.), rand() / (RAND_MAX + 1.), 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
}

void randomGlColor3ub(){
  glColor3ub(rand() % 256, rand() % 256, rand() % 256);
}

// void displayInstructions(){
//   glClear(GL_COLOR_BUFFER_BIT);
//   char name[200] = "Abraham Rodriguez";
//   char id[200] = "A01195653";
//   glColor3f(0.0, 0.0, 0.0);
//   glRasterPos2f(-4.7, 2.0);
//   for(int k = 0; name[k] != '\0'; k++){
//       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, name[k]);
//   }
//   glRasterPos2f(-3.0, -2.0);
//   for(int k = 0; id[k] != '\0'; k++){
//       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, id[k]);
//   }
// }

void timer(void){
  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
  randomBackground();
  glFlush();
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(winWidth,winHeight);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Timer");
  init();
  glutDisplayFunc(timer);
  glutMainLoop();
  return 0;
}