#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
using namespace std;
int x1,x2,y1,y2;
void display(void)
{
    //Clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);
    
    //draw white polygon (rectangle) with corners at
    // (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    //   glVertex3f(0.75, 0.75, 0.0);
    // glVertex3f(0.25, 0.75, 0.0);
    glEnd();
    
    // Don't wait start processing buffered OpenGL routines
    glFlush();
}
void init(void)
{
    //select clearing (background) color
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    //initialize viewing values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    
}
/*void render(void)
 {
 glClear(GL_COLOR_BUFFER_BIT);
 glLoadIdentity();
 
 drawBitmapText("Osama Hosam's OpenGL Tutorials",200,200,0);
 glutSwapBuffers();
 }
 void drawBitmapText(char *string,float x,float y,float z)
 {
 char *c;
 glRasterPos3f(x, y,z);
 
 for (c=string; *c != ''; c++)
 {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
 }
 }*/
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    
    //Set Display Mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    cin>>x1>>y1>>x2>>y2;
    
    glutInitWindowSize(500,500);
    
    //Set the window position
    glutInitWindowPosition(100,100);
    
    //Create the window
    glutCreateWindow("A Simple OpenGL Windows Application with GLUT");
    
    //Call init (initialise GLUT
    init();
    
    //Call "display" function
    glutDisplayFunc(display);
    
    //Enter the GLUT event loop
    glutMainLoop();
    
    return 0;
}
