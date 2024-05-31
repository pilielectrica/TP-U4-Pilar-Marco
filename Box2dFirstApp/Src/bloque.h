#pragma once
#include "SFMLRenderer.h"
#include <tchar.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;
using namespace std;


class Bloquee
{

private:
	// Sprite y su imagen la para representaci�n gr�fica
	Sprite* _sprite;
	Texture* _image;
	RenderWindow* wnd;
	b2World* world;
	// Body para representaci�n f�sica
	b2Body* _body;
	bool downKeyPressed = false;
	//...
public:
	Bloquee(b2World* _world, RenderWindow* _wnd)
	{
		// Guardamos puntero a ventana para dibujar luego
		wnd = _wnd;
		_image = new Texture();
		_image->loadFromFile("ca�on.png");
		// Cargamos el sprite
		_sprite = new Sprite(*_image);
		_sprite->setScale(0.05, 0.05);

		// Definimos el body y lo creamo

		// Creamos su figura de colisi�n
		// en este caso suponemos que la figura de
		// colision es una caja cuadrada
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(20.0f, 20.0f);
		

		


		// Creamos el fixture, le seteamos
		// la figura de colision
		// y agregamos el fixture al body
	}
	// Metodo que posiciona el sprites
	// segun la posicion del body
	void ActualizarPosiciones(b2Body* _body)
	{
		b2Vec2 pos = _body->GetPosition();
		_sprite->setPosition(pos.x -10 , pos.y -15  );
		
	}

	// Metodo que dibuja el sprite
	void Dibujar()
	{
		wnd->draw(*_sprite);
	}
	void ActualizarRotacion()
	{ 
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			_sprite->rotate(+1);
			if (_sprite->getRotation() > 21 && _sprite->getRotation() <= 22)
			{
				_sprite->rotate(-1);
			}
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			_sprite->rotate(-1);
			if (_sprite->getRotation() > 351 && _sprite->getRotation() <= 353)
			{
				_sprite->rotate(+1);
			}
		}
		//if (_sprite->getRotation() <= 338) { _sprite->setRotation(338); }
		

	}
	Vector2f GetPosition()
	{
		return _sprite->getPosition();
	}
	float GetRotation()
	{
		return _sprite->getRotation();
	}
	


	// Otros metodos
	// relacionados al personaje
};		