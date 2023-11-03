#include "gunInterface.h"

void GunInterface::display(GunStorage * storage) const
{
   drawRectangle(storage->getPosition(), M_PI_2 - storage->getAngle(), 10.0, 100.0, 1.0, 1.0, 1.0);
}

void drawRectangle(const Position& pt,
   double angle = 0.0,
   double width = 10.0,
   double height = 100.0,
   double red = 1.0,
   double green = 1.0,
   double blue = 1.0)
{
   // Get ready...
   glBegin(GL_QUADS);
   glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);

   // Draw the actual line
   glVertexPoint(rotate(pt, width / 2.0, height / 2.0, angle));
   glVertexPoint(rotate(pt, width / 2.0, -height / 2.0, angle));
   glVertexPoint(rotate(pt, -width / 2.0, -height / 2.0, angle));
   glVertexPoint(rotate(pt, -width / 2.0, height / 2.0, angle));
   glVertexPoint(rotate(pt, width / 2.0, height / 2.0, angle));

   // Complete drawing
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
}