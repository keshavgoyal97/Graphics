#include <iostream>
#include <string>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
using namespace std;
double x1,y1,x2,y2,x3,y3,x4,y4,r,r1,g,g1,b,b1;
string str;
void drawBitmapText(double x,double y)
{
    int len,i;
    len=str.size();
    glRasterPos2d(x, y);
    for (i=0; i<len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, str[i]);
    }
}

void display(void)
{
    //Clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);
    
    //draw white polygon (rectangle) with corners at
    // (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    //  glMatrixMode(GL_MODELVIEW);
    //  glLoadIdentity();
    //glPolygonMode(GL_FRONT, GL_LINE);
    glBegin(GL_POLYGON);
    glColor3f(r,g,b);
    glVertex2d(x1,y1);
    glVertex2d(x2,y2);
    glVertex2d(x3, y3);
    glVertex2d(x4, y4);
    
    glEnd();
    glPolygonMode(GL_FRONT, GL_LINE);
    
    glBegin(GL_POLYGON);
    glColor3f(r1,g1,b1);
    glVertex2d(x1,y1);
    glVertex2d(x2,y2);
    glVertex2d(x3, y3);
    glVertex2d(x4, y4);
    
    glEnd();
    glColor3f(0.8,0.7,0.2);
    double x=(x1+x3)/2;
    double y=(y1+y3)/2;
    
    drawBitmapText(x, y);
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


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    
    //Set Display Mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    cout<<"Enter Coordinates"<<endl;
    cout<<"Enter X1 and Y1"<<endl;
    cin>>x1>>y1;
    cout<<"Enter X2 and Y2"<<endl;
    cin>>x2>>y2;
    cout<<"Enter X3 and Y3"<<endl;
    cin>>x3>>y3;
    cout<<"Enter X4 and Y4"<<endl;
    cin>>x4>>y4;
    cout<<"Enter boundary colors"<<endl;
    cin>>r1>>g1>>b1;
    cout<<"Enter fill color"<<endl;
    cin>>r>>g>>b;
    cout<<"Enter the Text"<<endl;
    cin>>str;
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
    //render();
    glutMainLoop();
    
    return 0;
}

