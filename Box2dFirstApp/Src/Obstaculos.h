#pragma once
#include "SFMLRenderer.h"
#include <tchar.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;
using namespace std;


class Obstaculos
{

private:
	// Sprite y su imagen la para representación gráfica
	Sprite* _cajametalsprite;
	Texture* _image;
	Sprite* _cajamaderasprite;
	Texture* _image2;
	RenderWindow* wnd;
	b2World* world;
	// Body para representación física
	b2Body* _body;
	b2Body* _body2;
	bool downKeyPressed = false;
	//...
public:
	Obstaculos(b2World* _world, RenderWindow* _wnd)
	{
		// Guardamos puntero a ventana para dibujar luego
		wnd = _wnd;
		_image = new Texture();
		_image->loadFromFile("Metal Box.png");
		// Cargamos el sprite
		_cajametalsprite = new Sprite(*_image);
		_cajametalsprite->setScale(0.04, 0.04);

		_image2 = new Texture();
		_image2->loadFromFile("RTS_Crate.png");
		// Cargamos el sprite
		_cajamaderasprite = new Sprite(*_image2);
		_cajamaderasprite->setScale(0.02, 0.02);


	}
	// Metodo que posiciona el sprites
	// segun la posicion del body
	void ActualizarPosicionesCajaEstatica(b2Body* _body)
	{
		b2Vec2 pos = _body->GetPosition();
		_cajametalsprite->setPosition(pos.x - 10, pos.y - 10);

	}
	void ActualizarPosicionesCajaDinamica(b2Body* _body2)
	{
		b2Vec2 pos = _body2->GetPosition();
		_cajamaderasprite->setPosition(pos.x - 5, pos.y - 5);

	}

	// Metodo que dibuja el sprite
	void DibujarCajaDinamica()
	{
		wnd->draw(*_cajamaderasprite);
	}
	void DibujarCajaEstatica()
	{
		wnd->draw(*_cajametalsprite);
	}

	/*void ActualizarRotacion()
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

*/

	// Otros metodos
	// relacionados al personaje
};