#include <string>

namespace NAME
{
	class Architect
	{
		
	public:
		std::string name;
		Architect();
		Architect(std::string);
		~Architect();
		void see();
		void init();
		std::string getName();
		void putName(std::string newName);
	};
}