#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "SFMLRenderer.h"
#include <list>
#include "bloque.h"
#include "Ragadoll.h"
#include "Obstaculos.h"

using namespace sf;
class Game
{
private:
	// Propiedades de la ventana
	int alto;
	int ancho;
	Color clearColor;

	// Objetos de box2d
	
	SFMLRenderer *debugRender;

	//tiempo de frame
	float frameTime;
	int fps;

	// Cuerpo de box2d
	b2Body* controlBody;
	b2Body* wallBody;
	b2Body* dynamicObstacle;
	b2Body* cañonBody;
	Bloquee* _cañon;
	Obstaculos* _obstaculo1;
	Obstaculos* _obstaculo2;
	b2Body* staticObstacle;
	//cielo
	Sprite* _spritecielo;
	Texture* _imagencielo;

	Ragdoll* _ragdoll;
	bool circlecreated;
	b2Vec2 fuerza;
	b2MassData massData;
	b2MouseJointDef mouseJointDef;
	b2MouseJoint* mouseJoint;
	b2MouseJoint* mouseJ;
	int i;
	int j;
	bool click = false;

public:
    b2World *phyWorld;RenderWindow *wnd;
	// Constructores, destructores e inicializadores
	Game(int ancho, int alto,std::string titulo);
	void CheckCollitions();
	void CreateEnemy(int x, int y);
	~Game(void);
	void InitPhysics();
	void destroyJoint();

	// Main game loop
	void Loop();
	void DrawGame();
	void UpdatePhysics();
	void DoEvents();
	void SetZoom();
	void Cañon();
	void DrawSprite();
	void ActualizarPosicionBomba();
	void JointCañonRagdoll();
	float pixelsToMeters(float pixels);
};

