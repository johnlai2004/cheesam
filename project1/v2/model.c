#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

extern []item get_items() {

/*
   var newresults = [];
   filehandle = fopen(Item.txt)
   while(row = readrow(filehanle)) {
     array_add(newresults, row)
   }
   return newresults;
*/
}

extern item get_item_by_id(int item_id) {
	// return a single object given the item_id
  /*
   var allitems = get_items();
   c = 0;
   while(allitems){
   if(item_id == allitems[c])
   {
   return allitems[c];
   }
   c++;
}
   * *
}

extern int add_item(char[] itemname, int qty, ....) {
	// return the id of the newly created item
	var obj =char[] itemname, int qty, ....;
	ffile_add(obj);
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
