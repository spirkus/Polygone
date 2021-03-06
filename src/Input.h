#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include<iostream>
#include "Engine.h"
#include "System.h"

#include "Position.h"
#include "Physics.h"
#include "PlayerStatus.h"

#define INPUT_PRIORITY 3 //placeholder
#define INPUT_NAME "Input" //placeholder

class InputComponent : public Component
{
	public:
		PhysicsComponent* physicsCom;
		PositionComponent* positionCom;
		PlayerStatusComponent* player;
};

class InputSystem : public System
{
	private:
    std::map<int, InputComponent> input;
	bool mouseenabled;
	double *cameraX;

	public:
		InputSystem();
		~InputSystem();

        virtual bool init();
		virtual void update(unsigned int delay);
		virtual void cleanup();

		virtual InputComponent* getEntity(int EntityID);
        virtual void loadEntity(int EntityID, const YAML::Node &node);
		virtual bool removeEntity(int EntityID);

};
#endif