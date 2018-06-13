#include <stdio.h>

/* make sure somethig as what we expect */
#if !defined(SHOULD_DEFINE_THIS)
static_assert(sizeof(off_t) == 4,
	"should define SHOULD_DEFINE_THIS");
#endif

int main(int argc, char *argv[])
{
	printf("%s, %d\n", __FUNCTION__, __LINE__);
	return 0;
}
