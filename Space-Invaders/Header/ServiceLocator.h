#pragma once
#include "GraphicService.h"
#include "EventService.h"

class ServiceLocator
{
private:
	GraphicService* graphic_service;
	EventService* event_service;

	ServiceLocator();
	~ServiceLocator();

	void createServices();
	void clearAllServices();

public:

	static ServiceLocator* getInstance();
	void initialize();
	void update();
	void render();

	GraphicService* getGraphicService();
	EventService* getEventService();
};
