#include "quicksort.h"
#include <utility>

void quicksort(int* a, unsigned left, unsigned right)
{
	int l, r, c;
	l = left;
	r = right - 1;
	c = a[(l + r) / 2];
	while (l <= r) {
		while (l < static_cast<int>(right) - 1 && a[l] < c) l++;
		while (r > static_cast<int>(left) && a[r] > c) r--;
		if (l <= r) {
			std::swap(a[l], a[r]);
			l++;
			//if (r != 0) {
			r--;
			//}
		}
	}
	if (static_cast<int>(left) < r + 1) quicksort(a, left, r + 1);
	if (l < static_cast<int>(right)) quicksort(a, l, right);


}
