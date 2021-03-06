#ifndef ENGINE_H
#define ENGINE_H

#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <SDL.h>

//#include "System.h"

#define INITIAL_DELAY 5

class System;

class Engine {
	public:
		~Engine();

        static Engine& instance() {
            static Engine e;
            return e;
        }

        bool init();
        void cleanup();

		int createEntity();
		void deleteEntity(int EntityID);
		bool registerSystem(System *s);
		System* getSystem(std::string name);
	
		void run();

        bool running;

	private:
		std::map<std::string, System*> systemDecoder;
		std::vector<System*> systems;

        //Singleton design pattern
        Engine() {}
        Engine(Engine const&);
        void operator=(Engine const&);

		int nextEntity;
};

#endif //ENGINE_H
