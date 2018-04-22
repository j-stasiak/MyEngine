#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

enum class ActionType
{
	CLICKED,
	HOLD,
	NONE
};

/*!
	@class Action

	@brief Action represents input which user enters

	@detail Action can hold button (e.g. W) and type of it (e.g. Clicked, Hold). 
			It is used in ActionMap to bind name and funtion to.

	@see ActionMap

*/
class Action
{
public:
	///
	/// Default constructor
	///
	Action();

	///
	/// Default constructor
	///
	/// @param key Constant reference to key which will be in ActionMap (sf::Keyboard::Key)
	///
	explicit Action(const sf::Keyboard::Key &key);

	///
	/// Parametered constructor
	///
	/// @param key Constant reference to key which will be in ActionMap (sf::Keyboard::Key)
	/// @param type Constant reference to enum which contains type of action
	///
	explicit Action(const sf::Keyboard::Key &key, const ActionType &type);

	///
	/// Default destructor
	///
	~Action();

	///
	/// Method returns key which is bound to given action
	///
	/// @return Key bound to Action.
	///
	sf::Keyboard::Key getKey() const;

	///
	/// Method returns action type which is bound to given action
	///
	ActionType getActionType() const;

	friend bool operator < (const Action & lhs, const Action & rhs)
	{
		return rhs.getKey() < lhs.getKey();
	}

private:
	ActionType			m_type;
	sf::Keyboard::Key	m_key;
};

#endif //ACTION_H