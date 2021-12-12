#include "Flat.h"
#include "ArchitectualObject.h"
#include <string>

namespace NAME
{
	class House :public ArchitectualObject, public Flat
	{
		int peopleNumber;
		std::string street;
	public:
		House();
		House(int, std::string, int, int, int,Architect*, int, int);
		~House();
		void see();
	};
}
