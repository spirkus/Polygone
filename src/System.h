#ifndef SYSTEM_H
#define SYSTEM_H

class Engine;

class Component {
};

class System {
	public:
		System(Engine* e);
		~System();

		virtual void init() = 0;
		virtual void update(unsigned int delay) = 0;
		virtual void cleanup() = 0;

		virtual Component* getEntity(int EntityID) = 0;
		virtual bool removeEntity(int EntityID) = 0;

        const std::string name;
        const int priority;

	protected:
		Engine* e;
};

#include "Engine.h"

#endif //SYSTEM_H
