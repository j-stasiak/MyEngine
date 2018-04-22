#ifndef RESOURCE_ARRAY_H
#define RESOURCE_ARRAY_H

#include <unordered_map>
#include <memory>

template<typename R> 
class ResourceArray
{
public:
	ResourceArray(const std::string &folder, const std::string &extension) :
		m_folder	("res/" + folder),
		m_extension	(extension)
	{
	}

	~ResourceArray()
	{
	}

	void addResource(const std::string &name)
	{
		R res;
		if (!res.loadFromFile(getFullName(name)))
		{
			R resFail;
			resFail.loadFromFile(getFullName("fail"));
			m_resources.insert(std::make_pair(name, resFail));
		}
		else
		{
			res.loadFromFile(getFullName(name));
			m_resources.insert(std::make_pair(name, res));
		}
	}

	bool exists(const std::string &resName) const
	{
		return m_resources.find(resName) != m_resources.end();
	}

	R& get(const std::string &resName)
	{
		if (!exists(resName))
		{
			addResource(resName);
		}

		return m_resources.at(resName);
	}

private:
	std::string getFullName(const std::string &name)
	{
		return m_folder + name + m_extension;
	}

	std::unordered_map<std::string, R> m_resources;

	const std::string m_folder;
	const std::string m_extension;

};

#endif //RESOURCE_ARRAY_H