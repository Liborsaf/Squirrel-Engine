#pragma once
#include "Actor.h"
#include "UniformDesc.h"
#include "FurStore.h"

class Actor;

class ActorComponent
{
private:
	Actor* parent;

public:
	ActorComponent()
	{
	};

	virtual void BeginPlay() = 0;
	virtual void Update() = 0;
	virtual void setup() = 0;
	Uniforms* uniforms;
public:
	template <typename T>
	T* getComponentInParent();

	inline Actor* getParent() { return parent; }
	inline void setParent(Actor* _parent) { this->parent = _parent; }
};

template <typename T>
T* ActorComponent::getComponentInParent() { 
	return dynamic_cast<T*>(parent->componentList.at(typeid(T*).name())); 
}