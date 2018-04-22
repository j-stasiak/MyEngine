#ifndef EVENT_CONTEXT_MANAGER_H
#define EVENT_CONTEXT_MANAGER_H

#include <vector>
#include "../Context/EventContext.h"


/*!
	@class EventContextManager

	@brief Class used to manage event contexts. 

	@detail Holds references of every context, so when one changes in other file it is changed in the table aswell.
			Can aswell set event to be active (i.e. When you quit to menu).

	@see EventContext
*/
class EventContextManager
{
public:
	///
	/// Default constructor
	///
	EventContextManager();

	///
	/// Default destructor
	///
	~EventContextManager();

	///
	/// Registers EventContext
	///
	void registerEventContext(EventContext context);
	
	///
	/// Sets active context
	///
	/// @param name Name of event. (Constant reference to string object)
	///
	void setActiveEventContext(const std::string & name);

	///
	/// Returns active event context
	///
	/// @return context Currently active context. (EventContext object)
	///
	EventContext getActiveEventContext() const;

private:
	std::vector<EventContext>		 m_context_vector;
	std::size_t						 m_event_context_count;
};

#endif //EVENT_CONTEXT_MANAGER_H