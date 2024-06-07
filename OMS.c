#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Struct the product class
struct Product{
	int quantity;
	char name[10];
	double price;
};

// Printing Alarm
void printmenu(){
	printf("\n");
	printf("\t.---------------------------------------------------.\n");
	printf("\tAvailable options:\n");
	printf("\tAdd a new product to the Store                    (1)\n");
	printf("\tUpdate price for a particular product             (2)\n");
	printf("\tA list of all available products in the Store     (3)\n");
	printf("\tSort all products by product price as ascending   (4)\n");
	printf("\tPrint information of all products                 (5)\n");
	printf("\tQuit the system                                   (6)\n");
	printf("\t.---------------------------------------------------.\n");
	printf("\tInput the number that equivalent to your desired option: ");
}

void invalidAlarm(){
	printf("\n\n");
	printf("\t._______________________________________.\n");
	printf("\t|The input is invaild, please try again!|\n");
	printf("\t.---------------------------------------.\n");
	printmenu();
}

/*Scanning procedure*/
void scan(struct Product *product, int *count){
	// Setup
	int i;
	int check1, check2;
	
	printf("\n\n");
	
	// Add name
	printf("\tThe product name is ");
	scanf("%s", product[*count].name);
	
    // Validation
	for (i = 0; i < strlen(product[*count].name); i++){
		// Upcasing for validation
		product[*count].name[i] = toupper(product[*count].name[i]);
	};
	
	// Add price
	input1: 
	printf("\tThe product price is ");
	check1 = scanf("%lf", &product[*count].price);

	// Validation
	if (check1 != 1, product[*count].price < 0){
		printf("\tThe price input is invalid!, try again\n");
		int ch1;
		while((ch1 = getchar()) != '\n');
		goto input1;	
	};
	
	// Add quantity
	input2:
	printf("\tThe product quantity is ");
	check2 = scanf("%d", &product[*count].quantity);
	
	// Validation

	if (check2 != 1, product[*count].quantity < 0){
		int ch2;
		while((ch2 = getchar()) != '\n');
		printf("\tThe quantity input is invalid!, try again\n");
		goto input2;	
	};
	
	// Increasing the existed
	if (count > 0){
		for (i = 0; i < *count; i++){
			if (strcmp(product[*count].name, product[i].name) == 0){
				
				// Increasing
				product[i].quantity += product[*count].quantity;
				printf("\n\n");
				printf("\t\tThe product existed, the price has been not changed!, quantity has been increased!\n");
				printf("\n\n");
				return;
			};
		};
    };
		
	// Setup
	(*count)++;
	printf("\n\n");
}

/*Printing procedure*/
void print(struct Product *product, int count){  // Pointer to point into the first name of product
	// Setup
	int i;
	printf("\n\n");
	printf("\t\t           The table list\n");
	printf("\t\t .---Name---.--Price---.-Quantity-.\n");
	
	// Printing process
	for (i = 0; i < count; i++){
		printf("\t\t |");
		printf("%10s", product[i].name);
		printf("|");
		printf("%10.2lf", product[i].price);
		printf("|");
		printf("%10d", product[i].quantity);
		printf("|");
		printf("\n");
	};
	
	// Setup
	printf("\t\t .----------.----------.----------.");
	printf("\n\n");
}

/*Printing Available Procedure*/
void printAvailable(struct Product product[], int count){
	// Setup
	int i;
	printf("\n\n");
	printf("\t\t   The table of available product\n");
	printf("\t\t .---Name---.--Price---.-Quantity-.\n");
	
	// Process
	for (i = 0; i < count; i++){
		if (product[i].quantity != 0){
			printf("\t\t |");
			printf("%10s", product[i].name);
			printf("|");
			printf("%10.2lf", product[i].price);
			printf("|");
			printf("%10d", product[i].quantity);
			printf("|");
			printf("\n");
		};
	};
	
	// Setup
	printf("\t\t .----------.----------.----------.");
	printf("\n\n");
}

/*Updating procedure*/
void update(struct Product product[], char Name[], int count){
	// Setup
	int i;
	printf("\n\n");
	
	// Process
		for (i = 0; i < count; i++){
			if (strcmp(Name, product[i].name) == 0){
				printf("\tThe price updated price is ");
				scanf("%lf", &product[i].price);
				printf("\n\n");
				printf("\t\tSuccessfully updated!\n");
				printf("\n\n");
				return;
			};
		};
		
	// Setup
	printf("\t\tThe product can not found!\n");
	printf("\n\n");
}
/*Swapping*/
void Swap(int a, int b, struct Product *product) {
    struct Product temp = product[a];
    product[a] = product[b];
    product[b] = temp;
}

/*Ascending Sorting*/
void AscendingSort(struct Product *product, int count){
	// Setup
	int i, j, max, a;
	int t;
	printf("\t\t ");

	// Process
	for (i = count - 1; i >= 0; i--){
		max = -1;
		for (j = 0; j <= i; j++){
			if (product[j].price > max){
				max = product[j].price;
				a = j;
			};
		};
		t = product[i].price;
		Swap(a, i, product);
	};
	
	// Printing
	printf("\n\n");
	printf("\t\tSorted!");
	print(product, count);
	
	// Setup
	printf("\n\n");
};

// Main
int main(){
	// Setup
	struct Product product[100];
	int option = 0;
	char Name[12];
	int count = 0;
	//menu	
	//Introduction
	printf("\t\tWelcome to the Order Management System\n");
	printf("\t\t         How can we help you?\n");
	printf("\t\t--------------------------------------\n");
	printf("\n\n");
	printf("\t\t                 MENU\n");
	
	do{
		switch(option){
			case 0:
				printmenu();
				int check;
				input:
				check = scanf("%d", &option);
				//validation the input option number
				if (1 > option || option > 6 || check != 1){
					invalidAlarm();
					int ch;
					while((ch = getchar()) != '\n');
					goto input;
				};
				break;
			case 1:
				scan(product, &count);
				printf("\tDo you have any other request? ");
				option = 0;
				break;
			case 2:
				printf("\n\n");
				printf("\tWhich product need to be updated? ");
				scanf("%s", Name);
				int i;
				for (i = 0; i < strlen(Name); i++){
					Name[i] = toupper(Name[i]);
				};
				update(product, Name, count);
				printf("\tDo you have any other request? ");
				option = 0;
				break;
			case 3:
				printAvailable(product, count);
				option = 0;
				break;
			case 4:
				AscendingSort(product, count);
				option = 0;
				break;
			case 5:
				print(product, count);
				printf("\tDo you have any other request? ");
				option = 0;
				break;
			};
		} while (option != 6);	
} 
