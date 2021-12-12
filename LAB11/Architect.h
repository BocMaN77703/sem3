#include <string>

namespace NAME
{
	class Architect
	{
		std::string name;
	public:
		Architect();
		Architect(std::string);
		~Architect();
		void see();
	};
}