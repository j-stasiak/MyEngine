#include "Action.h"

Action::Action() :
	m_type(ActionType::NONE),
	m_key(sf::Keyboard::Unknown)
{

}

Action::Action(const sf::Keyboard::Key &key) :
	m_type	(ActionType::NONE),
	m_key	(key)

{
}

Action::Action(const sf::Keyboard::Key & key, const ActionType & type) :
	m_type	(type),
	m_key	(key)
{
}


Action::~Action()
{
}

sf::Keyboard::Key Action::getKey() const
{
	return m_key;
}

ActionType Action::getActionType() const
{
	return m_type;
}