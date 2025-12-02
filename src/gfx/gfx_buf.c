#include <stdint.h>

uint16_t __attribute__((aligned(16384))) rgba16_buf[64 * 64];

/* Used for rescaling textures into pow2 dims */
uint16_t __attribute__((aligned(32))) scaled[64 * 64];

uint16_t __attribute__((aligned(32))) scaled2[256 * 128];