#include "Game.h"
#include "Box2DHelper.h"
#include <iostream>
#include "bloque.h"
#include "Ragadoll.h"

using namespace sf;
using namespace std;


Game::Game(int ancho, int alto, std::string titulo)
{
	wnd = new RenderWindow(VideoMode(ancho, alto), titulo);
	
	wnd->setVisible(true);
	fps = 60;
	wnd->setFramerateLimit(fps);
	frameTime = 1.0f / fps;
	SetZoom();
	InitPhysics();
	i = 400; j = -400;
	circlecreated = false;
	_imagencielo = new Texture();
	_imagencielo->loadFromFile("sky.png");
	// Cargamos el sprite
	_spritecielo = new Sprite(*_imagencielo);
	_spritecielo->setScale(0.5, 0.6);
	_spritecielo->setPosition(0, 0);
	_ragdoll = new Ragdoll();
    _cañon = new Bloquee(phyWorld, wnd);
	_obstaculo1 = new Obstaculos(phyWorld, wnd);
	_obstaculo2 = new Obstaculos(phyWorld, wnd);

	
	
}



void Game::Loop()
{
	while (wnd->isOpen())
	{
		wnd->clear(sf::Color::White);
		wnd->draw(*_spritecielo);
		DoEvents();
		CheckCollitions();
		UpdatePhysics();

		_cañon->ActualizarPosiciones(cañonBody);		
		_obstaculo2->ActualizarPosicionesCajaEstatica(staticObstacle);
		_obstaculo1->ActualizarPosicionesCajaDinamica(dynamicObstacle);
	    _cañon->ActualizarRotacion();
			
		//if (click && mouseJ != nullptr) { destroyJoint(); }

		
		
		DrawSprite();
		//  Cañon();
		DrawGame();
		
      
		wnd->display();
		
		//cout << _cañon->GetRotation() << endl;
	
	}
}
void Game::DrawSprite()
{
	
	_cañon->Dibujar();
	_obstaculo1->DibujarCajaDinamica();
	_obstaculo2->DibujarCajaEstatica();


}

void Game::UpdatePhysics()
{
	phyWorld->Step(frameTime, 8, 8);
	phyWorld->ClearForces();
	phyWorld->DebugDraw();
	
}
void Game::DrawGame()
{ 
	// Dibujamos el suelo
	sf::RectangleShape groundShape(sf::Vector2f(500, 5));
	groundShape.setFillColor(sf::Color::Red);
	groundShape.setPosition(0, 95);
	wnd->draw(groundShape);

	// Dibujamos las paredes
	sf::RectangleShape leftWallShape(sf::Vector2f(10, alto)); // Alto de la ventana
	leftWallShape.setFillColor(sf::Color::Blue);
	leftWallShape.setPosition(100, 0); // X = 100 para que comience donde termina el suelo
	wnd->draw(leftWallShape);

	sf::RectangleShape rightWallShape(sf::Vector2f(10, alto)); // Alto de la ventana
	rightWallShape.setFillColor(sf::Color::Cyan);
	rightWallShape.setPosition(90, 0); // X = 90 para que comience donde termina el suelo
	wnd->draw(rightWallShape);


	sf::RectangleShape upWallShape(sf::Vector2f(500, 5)); // Alto de la ventana
	upWallShape.setFillColor(sf::Color::Red);
	upWallShape.setPosition(0, 0); // X = 90 para que comience donde termina el suelo
	wnd->draw(upWallShape);


}

void Game::DoEvents()
{
	Event evt;
	while(wnd->pollEvent(evt))
	{
		switch(evt.type)
		{
			case Event::Closed:
				wnd->close();
				break;
			case Event::MouseButtonPressed:
				/*b2Body* body = Box2DHelper::CreateTriangularDynamicBody(phyWorld, b2Vec2(0.0f, 0.0f), 10.0f, 1.0f, 4.0f, 0.1f);
				// Transformamos las coordenadas segun la vista activabody->SetTransform(b2Vec2(pos.x, pos.y), 0.0f);*/
				Vector2f pos = wnd->mapPixelToCoords(Vector2i(evt.mouseButton.x, evt.mouseButton.y));
				
				cout << pos.y << endl;
				//cout << "x :  " << pos.x << endl;
				click = true;
				_ragdoll->initRagdolls(phyWorld);
				//JointCañonRagdoll();
				//JointCañonRagdoll();
				//mouseJ->SetMaxForce(1000);
				/**/float fuerzay;
				float fuerzax;
				if (pos.x <= 30)
				{
					fuerzax = 0;
					fuerzay = 0;
					 cout << "debe caer" << endl;
			
				}
				else if (pos.x >= 31)
				{
                     fuerzax = (pos.x + 500) * 1000;
				}
				 	 
			    if (pos.y >= 53 && pos.y <= 60 && pos.x >= 31)
				{
					fuerzay = (pos.y + 100);
					fuerzax -= 100;
					cout << "mitad" << endl;

				}
				else if (pos.y >= 38 && pos.y <= 52 && pos.x >= 31)
				{
					fuerzay = (pos.y + 100);
					fuerzax = (pos.x + 500) * 1000;
					cout << "mas fuerza" << endl;

				}
				else if (pos.y >= 60 && pos.y <= 93)
				{
					fuerzay = (pos.y + 100);
					fuerzax = (pos.x + 500) * 100;
					cout << "menos fuerza" << endl;

				}
				else if (pos.x >= 31)
				{
					fuerzay = (pos.y + 100) * 7000;
					cout << "super fuerza" << endl;
				}
				
				b2Vec2 fuerza(fuerzax, -fuerzay);
				_ragdoll->getTronco()->ApplyForce(fuerza, _ragdoll->getTronco()->GetWorldCenter(), true);
			
		
				
				break;
		}
	}

	// Movemos el cuerpo
cañonBody->SetAwake(true);
staticObstacle->SetAwake(true);
dynamicObstacle->SetAwake(true);


}
void Game::destroyJoint()
{
	//cout << " x:  "<<_ragdoll->getTronco()->GetPosition().x << endl;
	//cout << " y:  "<<_ragdoll->getTronco()->GetPosition().x << endl;
     if (_ragdoll->getTronco()->GetPosition().x >= 85 || _ragdoll->getTronco()->GetPosition().y >= 85)
	{

		 phyWorld->DestroyJoint(mouseJ);
		 mouseJ = nullptr;
		
	}
	
}
float Game:: pixelsToMeters(float pixels) {
	// Ajusta el factor de conversión según tu escala
	return pixels / 30.0f;
}
void Game::JointCañonRagdoll()
{
	const float frec = 100.0f;
	const float dampRatio = 0.1f;
	mouseJ = Box2DHelper::CreateMouseJoint(phyWorld, _ragdoll->getTronco(), 1000, frec, dampRatio);
	mouseJ->SetTarget(b2Vec2(400.0f, 10.0f));

}

void Game::CheckCollitions()
{
	// Veremos mas adelante
}

// Definimos el area del mundo que veremos en nuestro juego
// Box2D tiene problemas para simular magnitudes muy grandes
void Game::SetZoom()
{
	View camara;
	// Posicion del view
	camara.setSize(100.0f, 100.0f);
	camara.setCenter(50.0f, 50.0f);
	wnd->setView(camara); //asignamos la camara
}


void Game::InitPhysics()
{
	// Inicializamos el mundo con la gravedad por defecto
	phyWorld = new b2World(b2Vec2(0.0f, 9.8f));

	//MyContactListener* l= new MyContactListener();
	//phyWorld->SetContactListener(l);
	// Creamos el renderer de debug y le seteamos las banderas para que dibuje TODO
	debugRender = new SFMLRenderer(wnd);
	debugRender->SetFlags(UINT_MAX);
	phyWorld->SetDebugDraw(debugRender);

	// Creamos un piso y paredes
	b2Body* groundBody = Box2DHelper::CreateRectangularStaticBody(phyWorld, 100, 10);
	groundBody->SetTransform(b2Vec2(50.0f, 100.0f), 0.0f);

	b2Body* leftWallBody = Box2DHelper::CreateRectangularStaticBody(phyWorld, 10, 100);
	leftWallBody->SetTransform(b2Vec2(0.0f, 50.0f), 0.0f);

	b2Body* rightWallBody = Box2DHelper::CreateRectangularStaticBody(phyWorld, 10, 100);
	rightWallBody->SetTransform(b2Vec2(100.0f, 50.0f), 0.0f);

	b2Body* upWallBody = Box2DHelper::CreateRectangularStaticBody(phyWorld, 100, 10);
	upWallBody->SetTransform(b2Vec2(50.0f, 0.0f), 0.0f);

	//obstaculo estatico
    staticObstacle = Box2DHelper::CreateRectangularStaticBody(phyWorld, 20, 20);
	staticObstacle->SetTransform(b2Vec2(50.0f, 40.0f), 0.0f);
	//obstaculo dinamico
	dynamicObstacle = Box2DHelper::CreateRectangularDynamicBody(phyWorld, 10, 10, 1, 0, 0);
	dynamicObstacle->SetTransform(b2Vec2(70.0f, 60.0f), 0.0f);
	//piso del obstaculo movil
	b2Body* staticObstacleFloor = Box2DHelper::CreateRectangularStaticBody(phyWorld, 15, 2);
	staticObstacleFloor->SetTransform(b2Vec2(70.0f, 65.0f), 0.0f);
	

	//cañon
	cañonBody = Box2DHelper::CreateCircularStaticBody(phyWorld, 5);
	cañonBody->SetTransform(b2Vec2(10.0f, 85.0f), 0.0f);

}

Game::~Game(void)
{ }