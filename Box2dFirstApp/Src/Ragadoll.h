#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "SFMLRenderer.h"


class Ragdoll
{
	b2Body* tronco;
	b2Body* cabeza;
	b2Body* brazoderecho;
	b2Body* brazoizquierdo;
	b2Body* piernaizquierda;
	b2Body* piernaderecha;
	b2World* _phyWorld;
	//b2World* phyWorld;


public:

	void initRagdolls(b2World *_phyWorld);
	Ragdoll() {};
	b2Body* getTronco();
	void setRagdollsAwake();

};
