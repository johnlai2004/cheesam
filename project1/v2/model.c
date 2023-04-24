#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

extern void get_items() {
}

extern void get_item_by_id(int item_id) {
	// return a single object given the item_id
}

extern int add_item() {
	// return the id of the newly created item
	int item_id;
	item_id = 1;
	return item_id;
}

extern bool edit_item(int item_id) {
	// return false if failed, true if success
	return true;
}

extern bool delete_item(int item_id) {
	// return false if failed, true if success
	return true;
}
