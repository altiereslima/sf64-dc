#include <stdint.h>
#include <stdlib.h>
#include <kos.h>
// more than enough for a 64 * 64 16-bit image; no overflow should happen at this point
uint16_t __attribute__((aligned(16384))) rgba16_buf[64 * 64];
//uint8_t __attribute__((aligned(32))) xform_buf[8192];

/* Used for rescaling textures into pow2 dims */
/* static */ uint16_t __attribute__((aligned(32))) scaled[64 * 64]; // 64*64*8*2

/* static */ uint16_t __attribute__((aligned(32))) scaled2[256 * 128];//64*64];
