#include "Floor.h"

namespace NAME
{
	class Flat
	{
		int roomNumber;
		Floor* floor;
	public:
		Flat();
		Flat(int, int);
		~Flat();
		void see();
	};
}