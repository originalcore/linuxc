#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__
#include "klist.h"

LIST_HEAD(programer);
LIST_HEAD(good_man);

struct people {
	char name[20];
	struct list_head list1;
	struct list_head list2;
};
#endif
