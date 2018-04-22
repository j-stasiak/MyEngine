#include "ActionMap.h"
#include "../../Utility/Log/Log.h"

ActionMap::ActionMap() :
	m_action_map(),
	m_event_map()
{
}

ActionMap::~ActionMap()
{
}

void ActionMap::bind(const std::string & eventName, const std::function<void()> & f)
{
	if (eventName.empty())
	{
		LOG_WARNING("Empty name of eventName. Event unregistered. Quitting ActionMap::bind function...");
		return;
	}

	m_event_map[m_action_map[eventName]] = f;
}

void ActionMap::bind(const std::string & eventName, const std::function<void()> && f)
{
	if (eventName.empty()) 
	{ 
		LOG_WARNING("Empty name of eventName. Event unregistered. Quitting ActionMap::bind method...");
		return; 
	}

	m_event_map[m_action_map[eventName]] = std::move(f);
}

void ActionMap::activateEvent(const std::string & eventName)
{
	try
	{
		std::invoke(m_event_map[m_action_map[eventName]]);
		LOG_DEBUG("Event " + eventName + " activated");
	}
	catch (const std::bad_function_call & err)
	{
		LOG_ERROR("No function under " + eventName + " event. \nCompiler message: " + err.what());
	}
}
