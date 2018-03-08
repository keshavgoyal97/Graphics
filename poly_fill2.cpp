//
//  main.cpp
//  Polyfill
//
//  Created by keshav goyal on 26/01/18.
//  Copyright © 2018 keshav goyal. All rights reserved.
//

/*
4
10 10
40 10
40 40
10 40
25 25
0 0 0

 */

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;
 int cx,cy;
float replace1[3];
int match[3];
 int x[1001],y[1001],n,lw,algo;
void linedraw(int cx1,int cy1,int cx2,int cy2)
{
    int b=0,z,temp,xtemp,ytemp,dx,dy,x,y;
    glColor3f(match[0], match[1], match[2]);
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
    //cout<<y<<endl;
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
            if(lw==2)
            glVertex2f(round(-1*xtemp),round(ytemp-1));
        }
        else if(z==3)
        {
            temp=xtemp;
            xtemp=-1*ytemp;
            ytemp=-1*temp;
            glVertex2f(round(xtemp),round(ytemp));
            if(lw==2)
            glVertex2f(round(xtemp),round(ytemp-1));
        }
        else if(z==4)
        {
            glVertex2f(round(xtemp),round(-1*ytemp));
            if(lw==2)
            glVertex2f(round(xtemp),round(-1*ytemp-1));
        }
        else
        {
            glVertex2f(round(xtemp),round(ytemp));
            if(lw==2)
            glVertex2f(round(xtemp),round(ytemp+1));
            //cout<<xtemp<<" "<<ytemp<<endl;;
        }
        
    }
    glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
     pair<int,int> top;
    int x1,y1,i;
    queue<pair<int,int> > q;
    unsigned char pick_col[3];
   // for(i=0;i<3;i++)
    //cout<<replace1[i]<<" ";
    //cout<<endl;
    for(i=1;i<n;i++)
    {
        linedraw(x[i], y[i], x[i+1], y[i+1]);
      //  cout<<x[i]<<" "<<y[i]<<" "<<x[i+1]<<" "<<y[i+1]<<endl;
    }
    linedraw(x[n], y[n], x[1], y[1]);
   // glReadPixels(x[1] , y[1] , 1 , 1 , GL_RGB , GL_UNSIGNED_BYTE , pick_col);
    //for(i=0;i<3;i++)
      //  match[i]=(int)pick_col[i];
    top.first=cx;
    top.second=cy;
    q.push(top);
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        x1=top.first;
        y1=top.second;
        glReadPixels(x1 , y1 , 1 , 1 , GL_RGB , GL_UNSIGNED_BYTE , pick_col);
        //for(i=0;i<3;i++)
        //cout<<(int)pick_col[i]<<" ";
        glBegin(GL_POINTS);
        glColor3f(replace1[0], replace1[1], replace1[2]);
        for(i=0;i<3;i++)
        {
            if((int)pick_col[i]==255)
            {
            }
            else
                break;
        }
        if(i==3)
        {
            glVertex2d(x1,y1);
            q.push(pair<int,int> (x1+1,y1));
            q.push(pair<int,int> (x1,y1+1));
            q.push(pair<int,int> (x1-1,y1));
            q.push(pair<int,int> (x1,y1-1));
            if(algo==8)
            {
                q.push(pair<int,int> (x1+1,y1+1));
                q.push(pair<int,int> (x1-1,y1+1));
                q.push(pair<int,int> (x1-1,y1-1));
                q.push(pair<int,int> (x1+1,y1-1));
            }
        }
        glEnd();
    }
    glFlush();
}
void init(void)
{
    //select clearing (background) color
    glClearColor(1.0, 1.0, 1.0, 0.0);
    //initialize viewing values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    
}
/*10 10
250 10
250 150
150 200
30 20*/
int main(int argc, char** argv)
{
    int i;
    glutInit(&argc, argv);
    //Set Display Mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    glutInitWindowSize(500,500);
    cout<<"No. of points"<<endl;
    cin>>n;
    cout<<"Enter the points"<<endl;
    for(i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    cout<<"Enter the node"<<endl;
    cin>>cx>>cy;
    cout<<"we cannot use 8 seed filling algorithm in all cases, so you can line width=2 to prevent it from occur"<<endl;
    cout<<"Enter the boundary line width"<<endl;
    cin>>lw;
    cout<<"Enter 4 for using 4 seedfill algorithm and 8 for using 8 fill algorithm"<<endl;
    cin>>algo;
    cout<<"Enter the filling colors"<<endl;
    for(i=0;i<3;i++)
        cin>>replace1[i];
    cout<<"Enter the boundary colors"<<endl;
    for(i=0;i<3;i++)
        cin>>match[i];
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
/*10 10
 250 10
 250 150
 100 180
 150 200
*/
