#include "EventContextManager.h"

#include "../../Utility/Log/Log.h"

EventContextManager::EventContextManager() :
	m_context_vector		(),
	m_event_context_count	(0)
{
}


EventContextManager::~EventContextManager()
{
}

void EventContextManager::registerEventContext(EventContext context)
{
	m_context_vector.erase(std::remove_if(m_context_vector.begin(), m_context_vector.end(), [context](EventContext ec) {
		return (ec.getName() == context.getName());
	}), m_context_vector.end());

	m_context_vector.push_back(context);
	++m_event_context_count;
	LOG_DEBUG("Event context: " + context.getName() + " registered");
}

void EventContextManager::setActiveEventContext(const std::string &name)
{
	std::size_t evCount = 0;
	for (auto & context : m_context_vector)
	{
		if (context.getName() == name)
		{
			context.activate(true);
			LOG_DEBUG("Context " + context.getName() + " is now set as active");
		}
		else
		{
			context.activate(false);
			++evCount;
		}

		if (evCount == m_event_context_count)
		{
			m_context_vector.at(0).activate(true);
			LOG_DEBUG("No context found with given name. So context " + context.getName() + " is now set as active");
		}
	}
}

EventContext EventContextManager::getActiveEventContext() const
{
	for (auto context : m_context_vector)
	{
		if (context.isActive())
		{
			return context;
		}
	}
}