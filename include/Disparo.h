#pragma once


#include "Vector2D.h"


class Disparo
{
	public:

	float radio;

	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	//Vector2D origen;


	Disparo();
	virtual ~Disparo();
	
	void Dibuja();
	void Mueve(float t);
	void SetPos(float ix,float iy);
};

