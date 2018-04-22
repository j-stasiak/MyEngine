#include "EventContext.h"
#include "../../Utility/Log/Log.h"


EventContext::EventContext() :
	m_map(),
	m_name(""),
	m_active(false)
{
}

EventContext::EventContext(const ActionMap &actionMap) :
	m_map(actionMap),
	m_name(""),
	m_active(false)
{
}


EventContext::~EventContext()
{
}

void EventContext::setActionMap(const ActionMap &map)
{
	m_map = map;
}

void EventContext::setName(const std::string & name)
{
	m_name = name;
}

std::string EventContext::getName() const
{
	return m_name;
}

void EventContext::activate(const bool &active)
{
	m_active = active;
}

bool EventContext::isActive() const
{
	return m_active;
}

void EventContext::update(const sf::Event & ev)
{
	for (auto i = m_map.actionMapCBegin(); i != m_map.actionMapCEnd(); ++i)
	{
		if (i->second.getKey() != sf::Keyboard::Unknown && 
			//i->second.getActionType() != ActionType::NONE && 
			ev.type == ev.KeyReleased &&
			i->second.getKey() == ev.key.code)
		{
			m_map.activateEvent(i->first);
		}
	}
}