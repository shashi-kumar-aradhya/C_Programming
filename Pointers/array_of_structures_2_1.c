#include <stdio.h>

#define NUMBER_OF_BANDS 5
#define NUMBER_OF_PORTS 4
#define NUMBER_OF_VALUES 2
typedef struct {
	int value1[NUMBER_OF_VALUES];
//	int value2;
}TEMP;
typedef struct {
	int bands[NUMBER_OF_BANDS];
	int ports[NUMBER_OF_PORTS][NUMBER_OF_BANDS];
	TEMP value[NUMBER_OF_BANDS];
}BANDS;

BANDS bands_4g = {.bands = {1, 2, 3, 4, 5}, .ports = {{1, 5, 9, 13, 17}, {2, 6, 10, 14, 18}, {3, 7, 11, 15, 19}, {4, 8, 12, 16, 20}}, .value = {{
      .value1 = {1, 2}}, {.value1 = {3, 4}}, {.value1 = {5, 6}}, {.value1 = {7, 8}}, {.value1 = {9, 10}}}};
int main()
{
	int band_index;
	int port_index;
	int value_index;
	
//	int port_value = 1;
//	int value_value = 1;
	
	for (band_index = 0; band_index < NUMBER_OF_BANDS; band_index++)
	{
//		bands_4g.bands[band_index] = band_index+1;
		printf("Index = %d\tBand = %d\n", band_index,bands_4g.bands[band_index]);
		for(port_index = 0; port_index < NUMBER_OF_PORTS; port_index++)
		{
//			bands_4g.ports[port_index][band_index] = port_value++;
			printf("bands_4g.ports[%d][%d]= %d\n", port_index,band_index,bands_4g.ports[port_index][band_index]);
		}
		for(value_index = 0; value_index < NUMBER_OF_VALUES; value_index++)
		{
//			bands_4g.value[band_index].value1[value_index] = value_value++;
			printf("bands_4g.value[%d].value1[%d]= %d\n", band_index,value_index,bands_4g.value[band_index].value1[value_index]);
		}
	}

	printf("\n\n");
	return 0;
}
