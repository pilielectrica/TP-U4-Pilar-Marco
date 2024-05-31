#include "Box2DHelper.h"
#include "Ragadoll.h"

void Ragdoll::initRagdolls(b2World* phyWorld)
{
	_phyWorld = phyWorld;
	tronco = Box2DHelper::CreateRectangularDynamicBody(_phyWorld, 10, 10.0f,0.3,1,0.5);
	tronco->SetTransform(b2Vec2(20.0f, 50.0f), 0.0f);

	tronco->SetAwake(true);

	cabeza = Box2DHelper::CreateRectangularDynamicBody(_phyWorld, 7, 7.0f,0.3,1,0.5);
	cabeza->SetTransform(b2Vec2(20.0f, 40.0f), 0.0f);

	cabeza->SetAwake(true);

	brazoderecho = Box2DHelper::CreateRectangularDynamicBody(_phyWorld, 5, 10.0f, 0.3, 1, 0.5);
	brazoderecho->SetTransform(b2Vec2(25.0f, 55.0f), 0.0f);

	brazoderecho->SetAwake(true);

	brazoizquierdo = Box2DHelper::CreateRectangularDynamicBody(_phyWorld, 5, 10.0f, 0.3, 1, 0.5);
	brazoizquierdo->SetTransform(b2Vec2(15.0f, 55.0f), 0.0f);
	brazoizquierdo->SetAwake(true);

	piernaizquierda = Box2DHelper::CreateRectangularDynamicBody(_phyWorld, 4, 10.0f, 0.3, 1, 0.5);
	piernaizquierda->SetTransform(b2Vec2(18.0f, 62.0f), 0.0f);
	piernaizquierda->SetAwake(true);

	piernaderecha = Box2DHelper::CreateRectangularDynamicBody(_phyWorld, 4, 10.0f, 0.3, 1, 0.5);
	piernaderecha->SetTransform(b2Vec2(22.0f, 62.0f), 0.0f);
	piernaderecha->SetAwake(true);

	b2Vec2 verticetronco(24.0f, 46.0f);
	b2Vec2 verticetronco2(16.0f, 46.0f);
	b2Vec2 verticetronco3(20, 48);
	b2Vec2 verticetronco4(18, 53);
	b2Vec2 verticetronco5(22, 53);
	b2Vec2 verticepiernaizq(18.0f, 58);
	b2Vec2 verticepiernader(22.0f, 58);
	b2Vec2 verticecabeza(20, 46);
	b2Vec2 verticebrazoder(25.0f, 52);
	b2Vec2 verticebrazoizq(15.0f, 52);

	b2DistanceJointDef jointDef;
	jointDef.Initialize(tronco, brazoderecho, verticetronco, verticebrazoder);
	jointDef.collideConnected = true;
	b2LinearStiffness(jointDef.stiffness, jointDef.damping, 2.0f, 0.5f, tronco, brazoderecho);

	_phyWorld->CreateJoint(&jointDef);

	b2DistanceJointDef jointDef2;
	jointDef2.Initialize(tronco, brazoizquierdo, verticetronco2, verticebrazoizq);
	jointDef2.collideConnected = true;
	b2LinearStiffness(jointDef2.stiffness, jointDef2.damping, 2.0f, 0.5f, tronco, brazoizquierdo);

	_phyWorld->CreateJoint(&jointDef2);

	b2DistanceJointDef jointDef3;
	jointDef3.Initialize(tronco, cabeza, verticetronco3, verticecabeza);
	jointDef3.collideConnected = true;
	b2LinearStiffness(jointDef3.stiffness, jointDef3.damping, 2.0f, 0.5f, tronco, cabeza);

	_phyWorld->CreateJoint(&jointDef3);

	b2DistanceJointDef jointDef4;
	jointDef4.Initialize(tronco, piernaizquierda, verticetronco4, verticepiernaizq);
	jointDef4.collideConnected = true;
	b2LinearStiffness(jointDef4.stiffness, jointDef4.damping, 2.0f, 0.5f, tronco, piernaizquierda);

	_phyWorld->CreateJoint(&jointDef4);

	b2DistanceJointDef jointDef5;
	jointDef5.Initialize(tronco, piernaderecha, verticetronco5, verticepiernader);
	jointDef5.collideConnected = true;
	b2LinearStiffness(jointDef5.stiffness, jointDef5.damping, 2.0f, 0.5f, tronco, piernaderecha);

	_phyWorld->CreateJoint(&jointDef5);
}
b2Body* Ragdoll::getTronco()
{
	return tronco;
}
void Ragdoll::setRagdollsAwake()
{
	tronco->SetAwake(true);
	cabeza->SetAwake(true);
	brazoderecho->SetAwake(true);
	brazoizquierdo->SetAwake(true);
	piernaizquierda->SetAwake(true);
	piernaderecha->SetAwake(true);
}