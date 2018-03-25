//
//  main.cpp
//  Polytrans
//
//  Created by keshav goyal on 31/01/18.
//  Copyright © 2018 keshav goyal. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;
#define width 300
#define height 200
#define PI 3.14159265
int cx,cy,x[1001],y[1001],n,ind,sx,sy,cx1,cy1;
double sin1,cos1,x1,y2,x0,x2;
int theta;
void display(void)
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
   // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_LINES);
    glColor3b(0, 0, 0);
    //glLineWidth(2);
    glColor3b(0, 0, 0);
    glVertex2d(-250, 0);
    glVertex2d(250, 0);
    glVertex2d(0, -250);
    glVertex2d(0, 250);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_LINES);
    glColor3b(0, 0, 0);
    for(i=1;i<n;i++)
    {
        glVertex2d(x[i], y[i]);
        glVertex2d(x[i+1], y[i+1]);
    }
    glVertex2d(x[n], y[n]);
    glVertex2d(x[1], y[1]);
    glEnd();
    if(ind==1)
    {
        cout<<"a";
        for(i=1;i<=n;i++)
        {
            x[i]=x[i]+cx;
            y[i]=y[i]+cy;
        }
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBegin(GL_POLYGON);
        glColor3b(0, 0, 0);
        for(i=1;i<n;i++)
        {
            glVertex2d(x[i], y[i]);
            glVertex2d(x[i+1], y[i+1]);
        }
        glVertex2d(x[n], y[n]);
        glVertex2d(x[1], y[1]);
        glEnd();
    }
    else if(ind==2)
    {
        sin1=(double)sin(theta*PI/180);
        cos1=(double)cos(theta*PI/180);
        cout<<sin1<<" "<<cos1<<endl;
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
        glBegin(GL_POLYGON);
        glColor3b(0, 0, 0);
        for(i=1;i<=n;i++)
        {
            x1=(double)(cos1*x[i]-1*y[i]*sin1);
            y2=(double)(sin1*x[i]+cos1*y[i]);
            if(i==1)
            {
                x0=x1;
                x2=y2;
            }
            glVertex2d(x1, y2);
             cout<<x1<<" "<<y2<<endl;
        }
        glVertex2d(x1, y2);
        glVertex2d(x0, x2);
      /*  for(i=1;i<n;i++)
        {
            glVertex2d(x[i], y[i]);
            glVertex2d(x[i+1], y[i+1]);
        }
        glVertex2d(x[n], y[n]);
        glVertex2d(x[1], y[1]);*/
        glEnd();
    }
    else if(ind==3)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
        glBegin(GL_POLYGON);
        glColor3b(0, 0, 0);
        for(i=1;i<n;i++)
        {
            glVertex2d(-1*x[i], y[i]);
            glVertex2d(-1*x[i+1], y[i+1]);
        }
        glVertex2d(-1*x[n], y[n]);
        glVertex2d(-1*x[1], y[1]);
        glEnd();
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            x[i]=sx*x[i]+cx*(1-sx);
            y[i]=y[i]*sy+cy*(1-sy);
           // cout<<x[i]<<" "<<y[i]<<endl;
        }
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
        glBegin(GL_POLYGON);
        glColor3b(0, 0, 0);
        for(i=1;i<n;i++)
        {
            glVertex2d(x[i], y[i]);
            glVertex2d(x[i+1], y[i+1]);
        }
        glVertex2d(x[n], y[n]);
        glVertex2d(x[1], y[1]);
        glEnd();
    }
    glFlush();
}
void init(void)
{
    //select clearing (background) color
    glClearColor(0.45, 0.34, 0.56, 1.0);
    //initialize viewing values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250,250, -250, 250);
    
}

int main(int argc, char ** argv)
{
    // insert code here...
    //std::cout << "Hello, World!\n";
    int i;
    glutInit(&argc, argv);
    cout<<"Degree of polygon"<<endl;
    cin>>n;
    cout<<"Enter the coordinates"<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    cout<<"Enter 1 for translation"<<endl;
    cout<<"Enter 2 for rotation"<<endl;
    cout<<"Enter 3 for reflection"<<endl;
    cout<<"Enter 4 for scailing"<<endl;
    cin>>ind;
    if(ind==4)
    {
        cout<<"Enter scailing factors"<<endl;
        cin>>sx>>sy;
        cout<<"Enter the reference points"<<endl;
        cin>>cx>>cy;
    }
    else if(ind==2)
    {
        cout<<"Enter the rotation angle"<<endl;
        cin>>theta;
    }
    else if(ind==1)
    {
        cout<<"Enter the reference points"<<endl;
        cin>>cx>>cy;
    }
    //Set Display Mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    
    glutInitWindowSize(500, 500);
    
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
    return 0;
}
