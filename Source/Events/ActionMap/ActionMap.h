#ifndef ACTIONMAP_H
#define ACTIONMAP_H

#include <map>
#include <functional>
#include <SFML\Graphics.hpp>
#include "../Action/Action.h"

/*!
	@class ActionMap

	@brief Class used to connect user defined action with keyboard key.

	@detail 
*/
class ActionMap
{
public:
	///
	/// Default ctor
	///
	ActionMap();

	///
	/// Default dtor
	///
	~ActionMap();

	///
	/// Overloading [] operator
	///
	Action & operator[](const std::string & eventName)
	{
		return m_action_map[eventName];
	}

	///
	/// Binds function to an existing action
	///
	/// @param eventName Name of an event that function would be bound to. (constant reference to string object)
	/// @param f Function to be triggered when named event occurs. (std::function object)
	///
	void bind(const std::string & eventName, const std::function<void()> & f);

	///
	/// Binds function to an existing action
	///
	/// @param eventName Name of an event that function would be bound to. (constant right-side reference to string object)
	/// @param f Function to be triggered when named event occurs. (std::function object)
	///
	void bind(const std::string & eventName, const std::function<void()> && f);

	///
	/// Activates action with given name
	///
	/// @param eventName Name of an event to be activated. (constant reference to string object)
	///
	void activateEvent(const std::string & eventName);

	///
	/// Returns iterator at the begin of the Action Map which holds names of events and keys bound to it.
	///
	std::map< std::string, Action>::iterator actionMapBegin()
	{
		return m_action_map.begin();
	}

	///
	/// Returns iterator at the end of the Action Map which holds names of events and keys bound to it.
	///
	std::map< std::string, Action>::iterator actionMapEnd()
	{
		return m_action_map.end();
	}

	///
	/// Returns constant iterator at the end of the Action map which holds names of events and keys bound to it.
	///
	std::map< std::string, Action>::const_iterator actionMapCBegin()
	{
		return m_action_map.cbegin();
	}

	///
	/// Returns iterator the end of a Action Map which holds name of event and key bound to it.
	///
	std::map< std::string, Action>::const_iterator actionMapCEnd()
	{
		return m_action_map.cend();
	}

private:
	std::map< std::string, Action >						m_action_map;
	std::map< Action, std::function<void()> >			m_event_map;
};



#endif //ACTIONMAP_H