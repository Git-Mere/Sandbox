#include "mergesort.h"

void Merge_02(int* a, unsigned s1, unsigned s2) {
	int* tmp;
	unsigned i = 0, j = 0, k = 0;
	tmp = new int[s1 + s2];

	while (i < s1) {
		tmp[i] = a[i];
		i++;
	}

	j = s1 + s2 - 1;
	while (i < s1 + s2) {
		tmp[i++] = a[j--];
	}

	i = 0;
	j = s1 + s2 - 1;

	for (k = 0; k < s1 + s2; k++) {
		a[k] = (tmp[i] < tmp[j]) ? tmp[i++] : tmp[j--];
	}
	delete[] tmp;
}

void mergesort(int* a, unsigned p, unsigned r)
{
	if (r > 1) {
		int s1 = r / 2;
		int s2 = r - s1;

		mergesort(a, p, s1);
		mergesort(a + s1, s1, s2);
		Merge_02(a, s1, s2);
	}

}

