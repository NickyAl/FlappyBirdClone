#include "tools.h"

void tools::intToScore(size_t num, char* score)
{
	char a[4] = { '\0' };
	if (num < 10)
	{
		score[0] = '0' + num;
	}
	else if (num < 100)
	{
		score[1] = '0' + (num % 10);
		score[0] = '0' + (num / 10);
	}
	else
	{
		score[2] = '0' + (num % 10);
		score[1] = '0' + ((num / 10) % 10);
		score[0] = '0' + (num / 100);
	}
}
