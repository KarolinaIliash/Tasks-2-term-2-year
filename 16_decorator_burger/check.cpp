#include"decorator.h"

bool Check::check_number(char* a) {
	int length;
	length = strlen(a);
	if (a[0] == '0' && length == 1)
		return 1;
	if (a[0] == '0' && length > 1)
		return 0;
	for (int i = 0; i < length; i++) {
		if ((a[i] > 47) && (a[i] < 58))
			continue;
		else
			return 0;
	}
	return 1;// if 0 - false; if 1 - it's ok
}
