#ifndef EVENT_CONTEXT_H
#define EVENT_CONTEXT_H

#include "../ActionMap/ActionMap.h"
#include <SFML/Graphics.hpp>
#include <string>
//#include <functional>

/*!
	@class EventContext
	
	@brief Class represents context in which specific events occur.

	@detail Change context to change map of actions. 
			(i.e. In game arrow-up will make hero go up, but in Menu arrow-up will highlight option above current one.)
*/
class EventContext
{
public:
	///
	/// Default constructor
	///
	EventContext();

	///
	/// Parameter constructor
	///
	/// @param actionMap Action map bound to given context
	///
	EventContext(const ActionMap &actionMap);

	///
	/// Default destructor
	///
	~EventContext();

	///
	/// Sets ActionMap for given context
	///
	void setActionMap(const ActionMap &map);

	///
	/// Sets name of event context
	///
	void setName(const std::string &name);

	///
	/// Returns name of event context
	/// 
	std::string getName() const;

	///
	/// Sets context as an active one
	///
	void activate(const bool &active);

	///
	/// Returns boolean whether this context is active or not
	///
	bool isActive() const;

	///
	/// Checks if any event occurs
	///
	void update(const sf::Event & ev);

private:
	ActionMap										m_map;
	std::string										m_name;
	bool											m_active;
};

#endif //EVENT_CONTEXT_G