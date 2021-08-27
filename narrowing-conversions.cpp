#include <string.h>
#include <stdint.h>
void narrow_conversions(void)
{
	uint32_t length = strnlen("test", 10);
}
