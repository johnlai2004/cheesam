#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

extern bool record_exists(int item_id) {
	// return true if record exists, false otherwise
	return true;
}

extern bool valid_new_object(item st) {

   if (st.itemprice < 1 || st.itemprice > 30) {
}
