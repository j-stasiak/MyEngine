#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "ResourceArray.h"
#include "../Utility/NonCopyable.h"
#include "../Utility/NonMovable.h"
#include "../Utility/Log/Log.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/*!
	@class ResourceManager

	@description Class template preloads all resources and holds them for further usage. 
				 Class is singleton, hence only one instance can be created at a time.

	//TODO Create resource manager for every type of resource (sfx, img, font). 
	//TODO Make it more specific - group sounds by sound type (music, hud, voice), so it can be changed in options.
*/
class ResourceManager : public NonCopyable, public NonMovable
{

public:

	static ResourceManager & getInstance();

	///
	/// Default destructor
	///
	~ResourceManager();

	ResourceArray<sf::Font> fonts;
	ResourceArray<sf::Texture> images;
	ResourceArray<sf::SoundBuffer> soundBuffers;

private:
	///
	/// Default constructor
	///
	ResourceManager();
	
};

#endif // RESOURCE_MANAGER_H