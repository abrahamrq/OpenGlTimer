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
#include <sstream>
#include <string>
#include <iostream>
// Tamaño inicial de la ventana
int tenthsOfASecond = 0;
bool paused = true;
bool started = false;
GLsizei winWidth = 600, winHeight = 300;
void init(void){
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}

void randomBackground(){
    glClearColor(rand() / (RAND_MAX + 1.), rand() / (RAND_MAX + 1.), rand() / (RAND_MAX + 1.), 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void randomGlColor3ub(){
    glColor3ub(rand() % 256, rand() % 256, rand() % 256);
}

std::string format(int tenthsOfASecond){
    std::ostringstream buffer;
    int seconds = tenthsOfASecond / 10;
    int tenths = tenthsOfASecond % 10;
    int minutes = seconds / 60;
    seconds %= 60;
    buffer << minutes;
    buffer << ':';
    if (seconds < 10){
        buffer << '0';
    }
    buffer << seconds;
    buffer << ':';
    buffer << tenths;
    return buffer.str();
}

void displayInstructions(){
    char start[10] = "S-Start";
    char pause[10] = "P-Pause";
    char reset[10] = "R-Reset";
    char esc[10] = "Esc-Exit";
    randomGlColor3ub();
    glRasterPos2f(20, 20);
    for(int k = 0; start[k] != '\0'; k++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, start[k]);
    }
    glRasterPos2f(45, 20);
    for(int k = 0; pause[k] != '\0'; k++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pause[k]);
    }
    glRasterPos2f(70, 20);
    for(int k = 0; reset[k] != '\0'; k++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, reset[k]);
    }
    glRasterPos2f(85, 5);
    for(int k = 0; esc[k] != '\0'; k++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, esc[k]);
    }
    
}

void timePassBy(int value){
    glutPostRedisplay();
    if (started) {
        tenthsOfASecond++;
    }
    if (!paused){
        glutTimerFunc(100, timePassBy, 0);
    }
}

void displayTime(){
    
    std::string time_formatted = format(tenthsOfASecond);
    glRasterPos2f(45, 50);
    
    glPushMatrix();
    glTranslatef(15, 50,1);
    glScalef(0.2f,0.2f,1);
    for (int i = 0; i < time_formatted.size(); i++){
        glutStrokeCharacter(GLUT_STROKE_ROMAN , time_formatted[i]);
        
        // glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, time_formatted[i]);
    }
    
    glPopMatrix();
    
    
}

void keyboardActions(unsigned char theKey, int mouseX, int mouseY)
{
    switch (theKey){
        case 's':
        case 'S':
            if (!started){
                started = true;
                paused = false;
                glutTimerFunc(100, timePassBy, 0);
            }
            break;
        case 'p':
        case 'P':
            if (started){
                if (paused){
                    glutTimerFunc(100, timePassBy, 0);
                }
                paused = !paused;
            }
            break;
        case 'r':
        case 'R':
            paused = true;
            started = false;
            tenthsOfASecond = 0;
            break;
        case 27:
            exit(0);
            break;
        default:
            break;// do nothing
    }
    glutPostRedisplay();
    
}

void timer(void){
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    displayInstructions();
    displayTime();
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
    glutKeyboardFunc(keyboardActions);
    glutMainLoop();
    return 0;
}