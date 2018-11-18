#include <stdio.h>

#define NUMBER_OF_BANDS 5
#define NUMBER_OF_PORTS 4

typedef struct {
	int bands[NUMBER_OF_BANDS];
	int ports[NUMBER_OF_PORTS][NUMBER_OF_BANDS];
}BANDS;

BANDS bands_4g;
int main()
{
	int band_index;
	int port_index;
	
	int port_value = 1;
	
	for (band_index = 0; band_index < NUMBER_OF_BANDS; band_index++)
	{
		bands_4g.bands[band_index] = band_index+1;
		printf("Index = %d\tBand = %d\n", band_index,bands_4g.bands[band_index]);
		for(port_index = 0; port_index < NUMBER_OF_PORTS; port_index++)
		{
			bands_4g.ports[port_index][band_index] = port_value++;
			printf("bands_4g.ports[%d][%d]= %d\n", port_index,band_index,bands_4g.ports[port_index][band_index]);
		}
	}

	printf("\n\n");
	return 0;
}
