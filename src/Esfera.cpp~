// Esfera.cpp: implementation of the Esfera class.
//
//////////////////////////////////////////////////////////////////////

#include "Esfera.h"
#include "glut.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Esfera::Esfera()
{
	radio=0.5f;
	velocidad.x=3;
	velocidad.y=3;

	pulso=0.2f;
	radio_min=0.2f;
	radio_max=0.8f;
}

Esfera::~Esfera()
{

}

void Esfera::Dibuja()
{
	glColor3ub(255,255,0);
	glEnable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(centro.x,centro.y,0);
	glutSolidSphere(radio,15,15);
	glPopMatrix();
}

void Esfera::Mueve(float t)
{
	centro=centro+(velocidad*t);
}

void Esfera::MuevePulsante(float t)
{
	Esfera::Mueve(t);
	
	if(radio>radio_max) 
		pulso=(-pulso);

	if(radio<radio_min) 
		pulso=(-pulso);

	radio+=pulso*t;
}
