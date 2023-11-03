#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_18
#endif // __APPLE__

#ifdef __linux__
#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // __linux__

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>         // OpenGL library we copied
#define _USE_MATH_DEFINES
#include <math.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // _WIN32
#include "interfaceElement.h"
#include "uiInteract.h"
#include "StorageElement.h"
#include "LogicElement.h"

//void Interface::input(UserInput input)
//{
//}
//
//void Interface::processing()
//{
//}
//
//void Interface::output()
//{
//}

void InterfaceElement::input(UserInput input, LogicMissile logic, StorageBullet storage) {};

void InterfaceElement::drawDot(const Position &point, double radius, double red, double green,
                               double blue) const {
   // Get ready, get set...
   glBegin(GL_TRIANGLE_FAN);
   glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);
   double r = radius / 2.0;

   // Go...
   glVertex2f((GLfloat)(point.getX() - r), (GLfloat)(point.getY() - r));
   glVertex2f((GLfloat)(point.getX() + r), (GLfloat)(point.getY() - r));
   glVertex2f((GLfloat)(point.getX() + r), (GLfloat)(point.getY() + r));
   glVertex2f((GLfloat)(point.getX() - r), (GLfloat)(point.getY() + r));

   // Done!  OK, that was a bit too dramatic
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
}

void InterfaceElement::drawLine(const Position &begin, const Position &end, double red, double green,
                                double blue) const {
   // Get ready...
   glBegin(GL_LINES);
   glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);

   // Draw the actual line
   glVertexPoint(begin);
   glVertexPoint(end);

   // Complete drawing
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
}

void InterfaceElement::drawDisk(const Position &center, double radius, double red, double green,
                                double blue) const {
   assert(radius > 1.0);
   const double increment = M_PI / radius;  // bigger the circle, the more increments

   // begin drawing
   glBegin(GL_TRIANGLES);
   glColor3f((GLfloat)red /* red % */, (GLfloat)green /* green % */, (GLfloat)blue /* blue % */);

   // three points: center, pt1, pt2
   Position pt1;
   pt1.setX(center.getX() + (radius * cos(0.0)));
   pt1.setY(center.getY() + (radius * sin(0.0)));
   Position pt2(pt1);

   // go around the circle
   for (double radians = increment;
        radians <= M_PI * 2.0 + .5;
        radians += increment)
   {
      pt2.setX(center.getX() + (radius * cos(radians)));
      pt2.setY(center.getY() + (radius * sin(radians)));

      glVertex2f((GLfloat)center.getX(), (GLfloat)center.getY());
      glVertex2f((GLfloat)pt1.getX(), (GLfloat)pt1.getY());
      glVertex2f((GLfloat)pt2.getX(), (GLfloat)pt2.getY());

      pt1 = pt2;
   }

   // complete drawing
   glEnd();
}

void InterfaceElement::glVertexPoint(const Position &point) const {
   glVertex2f((GLfloat)point.getX(), (GLfloat)point.getY());
}

void InterfacePellet::draw(StorageElement storage)
{
   if (!storage.getIsDead())
      drawDot(*storage.getPosition(), 1, 1, 1, 1);
}

void InterfaceMissle::draw(StorageElement storage)
{
   if (!storage.getIsDead())
   {
      // missile is a line with a dot at the end so it looks like fins.
      Position ptNext(*storage.getPosition());
      ptNext.add(*storage.getVelocity());
      drawLine(*storage.getPosition(), ptNext, 1.0, 1.0, 0.0);
      drawDot(*storage.getPosition(), 3.0, 1.0, 1.0, 1.0);
   }
}

void InterfaceMissle::input(UserInput input, LogicMissile logic, StorageBullet storage) {
   logic.input(storage, input.isUp(), input.isDown(), input.isB());
}

void InterfaceBomb::draw(StorageElement storage)
{
   if (!storage.getIsDead())
   {
      // Bomb actually has a gradient to cut out the harsh edges
      drawDot(*storage.getPosition(), storage.getRadius() + 2.0, 0.50, 0.50, 0.00);
      drawDot(*storage.getPosition(), storage.getRadius() + 1.0, 0.75, 0.75, 0.00);
      drawDot(*storage.getPosition(), storage.getRadius() + 0.0, 0.87, 0.87, 0.00);
      drawDot(*storage.getPosition(), storage.getRadius() - 1.0, 1.00, 1.00, 0.00);
   }
}

void InterfaceShrapnel::draw(StorageElement storage)
{
   if (!storage.getIsDead())
      drawDot(*storage.getPosition(), storage.getRadius(), 1.0, 1.0, 0.0);
}

void InterfaceFragment::draw(StorageElement storage)
{
   storage = dynamic_cast<StorageEffect&>(storage);
   // Do nothing if we are already dead
   if (storage.getIsDead())
      return;

   // Draw this sucker
   glBegin(GL_TRIANGLE_FAN);

   // the color is a function of age - fading to black
   glColor3f((GLfloat)storage.get, (GLfloat)age, (GLfloat)age);

   // draw the fragment
   glVertex2f((GLfloat)(pt.getX() - size), (GLfloat)(pt.getY() - size));
   glVertex2f((GLfloat)(pt.getX() + size), (GLfloat)(pt.getY() - size));
   glVertex2f((GLfloat)(pt.getX() + size), (GLfloat)(pt.getY() + size));
   glVertex2f((GLfloat)(pt.getX() - size), (GLfloat)(pt.getY() + size));
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
}

void InterfaceExhaust::draw(StorageElement storage)
{
}

void InterfaceStreek::draw(StorageElement storage)
{
}

void InterfaceStandard::draw(StorageElement storage)
{
}

void InterfaceSinker::draw(StorageElement storage)
{
}

void InterfaceFloater::draw(StorageElement storage)
{
}

void InterfaceCrazy::draw(StorageElement storage)
{
}
