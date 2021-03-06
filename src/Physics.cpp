#include "Physics.h"
#include "Position.h"
#include "Engine.h"

PhysicsSystem::PhysicsSystem(): System(PHYSICS_PRIORITY, PHYSICS_NAME){}
PhysicsSystem::~PhysicsSystem(){}

bool PhysicsSystem::init(){
	return true;
}
void PhysicsSystem::update(unsigned int delay) {
	for(auto &p : physics)
	{
		p.second.positionCom->x = p.second.positionCom->x + p.second.xv*static_cast<double>(delay);
		p.second.positionCom->y = p.second.positionCom->y + p.second.yv*static_cast<double>(delay);
	}
}
void PhysicsSystem::cleanup(){}



PhysicsComponent* PhysicsSystem::getEntity(int EntityID){

	//insert
    auto i = physics.find(EntityID);
	if(i == physics.end()){
		physics[EntityID].positionCom = (PositionComponent*) Engine::instance().getSystem(POSITION_NAME)->getEntity(EntityID);
	}
	PhysicsComponent* retval = &(physics[EntityID]);
	return retval;
}



bool PhysicsSystem::removeEntity(int EntityID){
	bool retval;
	retval=((1==physics.erase(EntityID))?true:false);
	return retval;
}

void PhysicsSystem::loadEntity(int EntityID, const YAML::Node &node) {
    PhysicsComponent *c = getEntity(EntityID);
    node["xv"] >> c->xv;
    node["yv"] >> c->yv;
}