#include <wiringPi.h>
#include <stdlib.h>
int main (void)
{
	wiringPiSetup () ;
	pinMode (7, INPUT) ;
	for (;;)
	{
		printf( "%d\n", digitalRead (7) ) ; delay (500) ;
	}
	return 0 ;
}
