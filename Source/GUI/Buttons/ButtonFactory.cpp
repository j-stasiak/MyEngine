#include "ButtonFactory.h"

#include "SimpleButton.h"

ButtonFactory::ButtonFactory()
{
	
}


ButtonFactory::~ButtonFactory()
{
}

std::unique_ptr<SimpleButton> createButton(const std::function<void(void)>&& func, const std::string& text)
{
	auto tmpButton = std::make_unique<SimpleButton>(SimpleButton::ButtonWidth::WIDE);
	tmpButton->setFunction(std::move(func));
	tmpButton->setText(text);

	return std::move(tmpButton);
}
