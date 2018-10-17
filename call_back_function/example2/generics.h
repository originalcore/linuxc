#ifndef GENERICS_H
#define GENERICS_H

typedef int (*cmp_t) (void *, void *);
void *get_max_score(void *data[], int num, cmp_t cmp);
#endif
