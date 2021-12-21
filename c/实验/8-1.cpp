#include "TU.h"
int main(int argc, char const *argv[])
{
	TTUJZ a=CreateTUJZ();
	prtTUJZ(*a);
	printf("\n");
	TTUB b=CreateTUB();
	prtTUB(*b);
	printf("\n");
	return 0;
}
