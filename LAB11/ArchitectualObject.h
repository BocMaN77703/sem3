#include "Coordinate.h"
#include "Architect.h"

namespace NAME
{
	class ArchitectualObject
	{
		int year;
		Coordinate* coordinates;
		Architect* architect;
	public:
		ArchitectualObject();
		ArchitectualObject(int, int, int, Architect*);
		~ArchitectualObject();
		void see();
	};
}