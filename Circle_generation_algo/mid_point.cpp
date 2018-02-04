#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <cmath>
using namespace std;
int rad,xc,yc;
void display(void)
{
    int cx,cy,d;
    cx = 0;
    cy = rad;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    d = 1 - rad;
    while(cx<=cy)
    {
        glVertex2f(round(cx+xc),round(cy+yc));
        glVertex2f(round(cy+xc),round(cx+yc));
        glVertex2f(round(-1*cx+xc),round(cy+yc));
        glVertex2f(round(-1*cy+xc),round(cx+yc));
        glVertex2f(round(cx+xc),round(-1*cy+yc));
        glVertex2f(round(cy+xc),round(-1*cx+yc));
        glVertex2f(round(-1*cx+xc),round(-1*cy+yc));
        glVertex2f(round(-1*cy+xc),round(-1*cx+yc));
        cout<<cx<<" "<<cy<<endl;
        if( d < 0)
        {
            d = d + 2*cx +3;
        }
        else
        {
            d = d + 2*cx - 2*cy +5;
            cy--;
        }
        cx++;
    }
    glEnd();
    glFlush();
    
}
void init(void)
{
    //select clearing (background) color
    glClearColor(1.0, 1.0, 1.0, 1.0);
    //initialize viewing values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200,200,-200,200);
    
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    //Set Display Mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    cout<<"enter center"<<endl;
    cin>>xc>>yc;
    cin>>rad;
    glutInitWindowSize(500,500);
    
    //Set the window position
    glutInitWindowPosition(100,100);
    
    //Create the window
    //Create the window
    glutCreateWindow("A Simple OpenGL Windows Application with GLUT");
    
    //Call init (initialise GLUT
    init();
    
    //Call "display" function
    glutDisplayFunc(display);
    //Enter the GLUT event loop
    //render();
    glutMainLoop();
    
}
