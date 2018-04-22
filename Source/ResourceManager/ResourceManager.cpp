#include "ResourceManager.h"

ResourceManager::ResourceManager() :
	fonts("fonts/", ".ttf"),
	images("imgs/", ".png"),
	soundBuffers("sfx/", ".wav")
{
}

ResourceManager::~ResourceManager()
{
}

ResourceManager & ResourceManager::getInstance()
{
	static ResourceManager rmng;
	return rmng;
}