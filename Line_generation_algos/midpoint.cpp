//
//  main3.cpp
//  Lab2
//
//  Created by keshav goyal on 21/01/18.
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
    int b=0,z,temp,xtemp,ytemp,dx,dy,x,y;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    z=0;
    if(cx2<=cx1&&cy2>=cy1)
    {
        cx1=-1*cx1;
        cx2=-1*cx2;
        z=2;
    }
    else if(cx2<=cx1&&cy2<=cy1)
    {
        temp=cx1;
        cx1=-1*cy1;
        cy1=-1*temp;
        temp=cx2;
        cx2=-1*cy2;
        cy2=-1*temp;
        z=3;
    }
    else if(cx2>=cx1&&cy1>=cy2)
    {
        cy1=-1*cy1;
        cy2=-1*cy2;
        z=4;
    }
    dy=cy2-cy1;
    dx=cx2-cx1;
    if(dy>dx)
    {
        b=1;
        temp=cx1;
        cx1=cy1;
        cy1=temp;
        temp=cx2;
        cx2=cy2;
        cy2=temp;
        dy=cy2-cy1;
        dx=cx2-cx1;
    }
    int d= dy-dx/2;
    x=cx1;
    y=cy1;
    cout<<y<<endl;
    while(x<cx2)
    {
        x++;
        if(d<0)
            d=d+dy;
        else
        {
            d=d+dy-dx;
            y++;
        }
        xtemp=x;
        ytemp=y;
        if(b==1)
        {
            temp=ytemp;
            ytemp=xtemp;
            xtemp=temp;
        }
        if(z==2)
        {
            glVertex2f(round(-1*xtemp),round(ytemp));
          //  cout<<-1*xtemp<<" "<<ytemp<<endl;
        }
        else if(z==3)
        {
            temp=xtemp;
            xtemp=-1*ytemp;
            ytemp=-1*temp;
            glVertex2f(round(xtemp),round(ytemp));
          //  cout<<xtemp<<" "<<ytemp<<endl;
        }
        else if(z==4)
        {
            glVertex2f(round(xtemp),round(-1*ytemp));
          //  cout<<xtemp<<" "<<-1*ytemp<<endl;
        }
        else
        {
            glVertex2f(round(xtemp),round(ytemp));
            //cout<<xtemp<<" "<<ytemp<<endl;;
        }

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
    gluOrtho2D(0,500,0,500);
    
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
