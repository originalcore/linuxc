#include <stdio.h>
#include <assert.h>

/* 自定义一个签名用于识别该结构体 */
#define TARGET_MARKER_SIG	0xFAF32000

/*
 * simply a signature that uniquely represents our structure
 * 自识别结构体(Self-Identifying Structures)
 *
 * A self-identifying structure is a method
 * that mimics the concept of runtime type checking
 * present in strongly typed languages
 */
typedef struct {
	unsigned int signature; /* AKA runtime type identifier */
	unsigned int targetType;
	double       x, y, z;
} targetMarker_t;

#define INIT_TARGET_MARKER(ptr) \
	(((targetMarker_t *)ptr)->signature = TARGET_MARKER_SIG)
#define CHECK_TARGET_MARKER(ptr) \
	assert(((targetMarker_t *)ptr)->signature == \
			TARGET_MARKER_SIG)

void displayTarget(targetMarker_t *target)
{
	/* Pre-check of the target structure */
	CHECK_TARGET_MARKER(target);
	printf( "Target type is %d\n", target->targetType );

	return;
}

int main(int argc, char *argv[])
{
	void *object1, *object2;

	/* Create two objects */
	object1 = (void *)malloc(sizeof(targetMarker_t));
	assert(object1);
	object2 = (void *)malloc(sizeof(targetMarker_t));
	assert(object2);

	/* Init object1 as a target marker struct */
	INIT_TARGET_MARKER(object1);

	/* Try to display object1 */
	displayTarget((targetMarker_t *)object1);

	/* Try to display object2 */
	displayTarget((targetMarker_t *)object2);

	return 0;
}
