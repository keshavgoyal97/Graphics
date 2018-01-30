//
//  lab2.cpp
//  Grphics2
//
//  Created by keshav goyal on 17/01/18.
//  Copyright © 2018 keshav goyal. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <cmath>
using namespace std;
int cx1,cx2,cy1,cy2;
void display(void)
{
    int cx3,cy3,steps,i,dx,dy;
    double incx,incy;
    
    dx=cx2-cx1;
    dy=cy2-cy1;
    if(abs(dx)>abs(dy))
        steps=abs(dx);
    else
        steps=abs(dy);
    incx=(float)dx/steps;
    incy=(float)dy/steps;
     glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for(i=0;i<steps;i++)
    {
        cx2=cx1+i*incx;
        cy2=cy1+i*incy;
        cx3=round(cx2);
        cy3=round(cy2);
        cout<<cx3<<" "<<cy3<<endl;
        glVertex2d(cx3,cy3);
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
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    
    //Set Display Mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    cin>>cx1>>cy1>>cx2>>cy2;
    
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
