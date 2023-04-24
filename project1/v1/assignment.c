#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

void edititem();
void additem();
void pmenu();
void searchitem();
void deleteproduct();
void readitem();
void report();
typedef struct {
		char itemcode[7], itemname[21];
		int itemqty, reorder, minlvl;
		double itemprice;
	}item;
	
	item st;
void main() {
	pmenu();
}

void pmenu() {
	int sel;
	do{
	printf("\n\t===== Product Manage System ====\t\n");
	printf("1.Add Item\n2.Edit Item\n3.Delete Product\n4.Search Item\n5.Display Item\n6.Report\n7.Exit\n");
	printf("Please Select One!=");
	rewind(stdin);
	scanf("%d", &sel);
		
		switch (sel)
	{
	case 1:
		additem();
		break;
	case 2:
		edititem();
		break;
	case 3:
		deleteproduct();
		break;
	case 4:
		searchitem();
		break;
	case 5:
		readitem();
		break;
	case 6:
		report();
		break;
	case 7:
		printf("System Exit!");
		break;
	default:
		printf("Select Again!");
		break;
	}
	} while (sel != 1 && sel != 2 && sel != 3 && sel != 4 && sel != 5 && sel != 6 && sel != 7);
	
}

void edititem() {
	FILE* edit, * editrd;
		char target[10],a=0,b=0,yes;
		edit = fopen("Item.txt","r");
		editrd=fopen("TempFile.txt","a");
		if (edit == NULL||editrd==NULL) {
			printf("File Not Function!");
			exit(-1);
		}
		printf("Enter Item Code That Need To Edit:\n");
		gets(target);
		int testcounter=0;
		while (fscanf(edit, "%[^#]# %[^#]# %lf %d %d %d", &st.itemcode, &st.itemname, &st.itemprice, &st.itemqty, &st.reorder, &st.minlvl) != EOF)
		{
			testcounter++;
			printf("%d. %s %s strcmp(target,st.itemcode) evaluates to %s ----\n", testcounter, target, st.itemcode, strcmp(target,st.itemcode)==0);
			if (strcmp(target,st.itemcode)==0) {
				printf("strcmp(target,st.itemcode)==0 is true");
				b = 1;
				printf("*****  Record Found  *****\n");
				printf("Item Name:%s\n Item Price:%.2lf\n Item Quantity:%d\n Item Reorder Quantity:%d\n Item Minimum Level:%d\n", st.itemname, st.itemprice, st.itemqty, st.reorder, st.minlvl);
				printf("*** New Record ***\n");
				do {
								printf("Enter New Item Name:");
								rewind(stdin);
								gets(st.itemname);
								if (strlen(st.itemname) >20) {
									printf("Item Name Over 20 Character!\n");
									printf("Please Try Again!\n");
									a = 1;
								}
								else {
									printf("Item Add Suceessfully!\n");
									a = 0;
								}
							} while (a);
							
							do {
								printf("Enter New Item Price[1-30]:");
								scanf("%lf", &st.itemprice);
								if (st.itemprice < 1 || st.itemprice > 30) {
									printf("Item Price Does Not Match!\n");
									printf("Please Try Again!\n");
									a = 1;
								}
								else
								{
									printf("Item Price Add Suceessfully!\n");
									a = 0;
								}
							} while (a);
							do {
								printf("Enter New Item Quantity[1-500]:");
								scanf("%d", &st.itemqty);
								if (st.itemqty < 1 || st.itemqty > 500) {
									printf("Item Quantity Does Not Less Thenn or Equal 1 and More Then Or Equal 500!\n");
									printf("Please Try Again!\n");
									a = 1;
								}
								else
								{
									printf("Item Quantity Add Suceessfully!\n");
									a = 0;
								}
							} while (a);
							do {
								printf("Enter New Reorder Quantity[50-300]:");
								scanf("%d", &st.reorder);
								if (st.reorder < 50 || st.reorder > 300) {
									printf("Item Reorder Quantity Does Not Match!\n");
									printf("Please Try Again!\n");
									a = 1;
								}
								else
								{
									printf("Item Reorder Quantity Add Suceessfully!\n");
									a = 0;
								}
							} while (a);
					
							do {
								printf("Enter New Minimum Level[20-200]:");
								scanf("%d", &st.minlvl);
								if (st.minlvl < 20 ||st.minlvl > 200) {
									printf("Item Reorder Quantity Does Not Match!\n");
									printf("Please Try Again!\n");
									a = 1;
								}
								else
								{
									printf("Item Minimum Level Add Suceessfully!\n");
									a = 0;
								}
	
							} while (a);
							fprintf(editrd, "%s# %s# %lf %d %d %d\n", st.itemcode, st.itemname, st.itemprice, st.itemqty, st.reorder, st.minlvl);
			}
			else {
				fprintf(editrd, "%s# %s# %lf %d %d %d\n", st.itemcode, st.itemname, st.itemprice, st.itemqty, st.reorder, st.minlvl);
			}
		}
		if (!b) {
			printf("\n\nTHIS PRODUCT DOESN'T EXIST!!!!");
		}
		fclose(edit);
		fclose(editrd);
		remove("Item.txt");
		rename("TempFile.txt", "Item.txt");
		pmenu();

}

void additem() {
	FILE* add;
		int id;
		char yes;
		int a, found = 0;
		add = fopen("Item.txt", "a");
		if (add == NULL) {
			printf("Cannot Open");
			exit(-1);
		}
		do {
			printf("=====Enter New Product Details=====\n");
			printf("Enter New Item Code:");
			rewind(stdin);
			gets(st.itemcode);
					
	
			do {
				printf("Enter New Item Name:");
				rewind(stdin);
				gets(st.itemname);
				if (strlen(st.itemname) >20) {
					printf("Item Name Over 20 Character!\n");
					printf("Please Try Again!\n");
					a = 1;
				}
				else {
					printf("Item Add Suceessfully!\n");
					a = 0;
				}
			} while (a);
			
			do {
				printf("Enter New Item Price[1-30]:");
				scanf("%lf", &st.itemprice);
				if (st.itemprice < 1 || st.itemprice > 30) {
					printf("Item Price Does Not Match!\n");
					printf("Please Try Again!\n");
					a = 1;
				}
				else
				{
					printf("Item Price Add Suceessfully!\n");
					a = 0;
				}
			} while (a);
			do {
				printf("Enter New Item Quantity[1-500]:");
				scanf("%d", &st.itemqty);
				if (st.itemqty < 1 || st.itemqty > 500) {
					printf("Item Quantity Does Not Less Thenn or Equal 1 and More Then Or Equal 500!\n");
					printf("Please Try Again!\n");
					a = 1;
				}
				else
				{
					printf("Item Quantity Add Suceessfully!\n");
					a = 0;
				}
			} while (a);
			do {
				printf("Enter New Reorder Quantity[50-300]:");
				scanf("%d", &st.reorder);
				if (st.reorder < 50 || st.reorder > 300) {
					printf("Item Reorder Quantity Does Not Match!\n");
					printf("Please Try Again!\n");
					a = 1;
				}
				else
				{
					printf("Item Reorder Quantity Add Suceessfully!\n");
					a = 0;
				}
			} while (a);
	
			do {
				printf("Enter New Minimum Level[20-200]:");
				scanf("%d", &st.minlvl);
				if (st.minlvl < 20 ||st.minlvl > 200) {
					printf("Item Reorder Quantity Does Not Match!\n");
					printf("Please Try Again!\n");
					a = 1;
				}
				else
				{
					printf("Item Minimum Level Add Suceessfully!\n");
					a = 0;
				}
			} while (a);
	
			fprintf(add, "%s# %s# %lf %d %d %d\n", st.itemcode, st.itemname, st.itemprice, st.itemqty, st.reorder, st.minlvl);
			printf("Anymore Item need to Add?(Y/N):");
			rewind(stdin);
			scanf("%c", &yes);
		} while (yes=='y'||yes=='y');
		fclose(add);
		pmenu();
}

void searchitem() {
	char target[7];
		int found=0;
		FILE* src;
		src = fopen("Item.txt", "r");
		if (src == NULL) {
			printf("File Cannot Open!\n");
			exit(-1);
		}
		printf("=============================\n");
		printf("|Enter Item Code to Search:|\n");
		printf("=============================\n");
		rewind(stdin);
		gets(target);
	    while (fscanf(src, "%[^#]# %[^#]# %lf %d %d %d", &st.itemcode, &st.itemname, &st.itemprice, &st.itemqty, &st.reorder, &st.minlvl)!=0) {
	        if (strcmp(st.itemcode, target) == 0) {
	            found = 1;
	            printf("Item Found!\n");
	            printf("Item Code: %s\n", st.itemcode);
	            printf("Item Name: %s\n", st.itemname);
	            printf("Item Quantity: %d\n", st.itemqty);
	            printf("Reorder Level: %d\n", st.reorder);
	            printf("Minimum Level: %d\n", st.minlvl);
	            printf("Item Price: %.2lf\n", st.itemprice);
	            break;
	        }else {
	            found;
	        printf("Item not found.\n");
	        break;
	    }
	    }
	    fclose(src);
		pmenu();
}

void deleteproduct() {
	FILE* temp, * ori;
		char code[7];
		int found=0,re;
		ori = fopen("Item.txt", "r");
		temp = fopen("TempFile.txt", "a");
		printf("Enter Item Code That Need To Be Delete:");
		rewind(stdin);
		gets(code);
		while (fscanf(ori, "%[^#]# %[^#]# %lf %d %d %d", &st.itemcode, &st.itemname, &st.itemprice, &st.itemqty, &st.reorder, &st.minlvl) != EOF) {
			if (strcmp(code,st.itemcode)==0) {
				found = 1;
				
			}
			else {
				fprintf(temp, "%s# %s# %lf %d %d %d\n", st.itemcode, st.itemname, st.itemprice, st.itemqty, st.reorder, st.minlvl);
				
			}
		}
	
		if (!found)
		{
			printf("Record not Found\n");
		}
		else
		{
			printf(" Record deleted\n");
		}
		fclose(ori);
		fclose(temp);
		remove("Item.txt");
		rename("TempFile.txt", "Item.txt");
		pmenu();
}

void readitem() {
	FILE* read;
	read = fopen("Item.txt", "r");
	if (read == NULL) {
		printf("File Cannot Open!\n");
		exit(-1);
	}
	printf("=============================================================================================================\n");
	printf("|Item Code\t|Item Name\t|Item Price\t|ItemQuantityt\t|Item Reorder Quantity\t|Item Minimum Level|\n");
	printf("=============================================================================================================\n");
	do {
		fscanf(read, "%[^#]# %[^#]# %lf %d %d %d", &st.itemcode, &st.itemname, &st.itemprice, &st.itemqty, &st.reorder, &st.minlvl);
		printf("%s\t\t %s\t\t %.2lf\t\t %d\t\t %d\t\t \t%d\n", st.itemcode, st.itemname, st.itemprice, st.itemqty, st.reorder, st.minlvl);
	} while (!feof(read));

	fclose(read);
	pmenu();
}
void report() {
	printf("1");
}
