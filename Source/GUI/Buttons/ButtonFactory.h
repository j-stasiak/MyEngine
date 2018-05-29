#ifndef BUTTON_FACTORY_H
#define BUTTON_FACTORY_H

#include <memory>
#include <functional>

class SimpleButton;

/*!
	@class

	Class used to create buttons, so the code don't get messy.
*/

class ButtonFactory
{
public:
	ButtonFactory();
	~ButtonFactory();
	
	static std::unique_ptr<SimpleButton> createButton(const std::function<void(void)>&& func, const std::string& text);

};

#endif // !BUTTON_FACTORY_H