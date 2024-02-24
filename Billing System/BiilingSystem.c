#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct items{
    char item[20];
    float price;
    int qty;
};

struct orders{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

//Function to generate bills
void generateBillHeader(char name[20],char date[30]){
printf("\n\n");
printf("\t   ADV. Restaurant");
printf("\n \t --------------------");
printf("\nDate :%s ",date);
printf("\nInvoice To: %s ", name);
printf("\n");
printf("-----------------------------------------\n");
printf("Items \t\t");
printf("Qty \t\t");
printf("Total \t\t");
printf("\n -----------------------------------------\n");
printf("\n\n");
}

void generateBillBody(char item [30], int qty,float price){
printf("%s \t\t", item);
printf("%d \t\t",qty);
printf("%.2f \t\t",qty*price);
printf("\n");
}

void generateBillFooter(float total){
printf("\n");
float dis = 0.1*total;
float netTotal = total-dis;
float cgst = 0.09*netTotal, grandTotal = netTotal+2*cgst;
printf("--------------------------------------------\n");
printf("Sub Total \t\t\t%.2f",total);
printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
printf("\n\t\t\t\t----------");
printf("\nNet Total\t\t\t%.2f",netTotal);
printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
printf("\n-------------------------------------------");
printf("\nGrand Total \t\t\t%.2f ", grandTotal);
printf("\n-------------------------------------------\n");
;
}

int main(){

   int opt,n; //option variable & no of iTems
   char saveBill = 'y', contFlag ='y';
   char name[50];
   FILE *fp; //Using the file system and defining the file pointer

   struct orders ord;
   struct orders order;

   while(contFlag = 'y'){
    system("cls");
    float total=0;
    int invoiceFound = 0; //For tracking
    //dashboard
    printf("============ADV. RESTAURANT ============ ");
    printf("\n\nPlease Select your preferred option: ");
    printf("\n\n1. Generate Invoice");
    printf("\n2. Show all Invoices");
    printf("\n3. Search Invoice");
    printf("\n4. Exit");
    printf("\n\n Your Choice:\t");

  
    scanf("%d",&opt);
    fgetc(stdin); //consumes the \n that is left by the scanf for it to work
    switch(opt){
       case 1:
       system("cls");
       printf("\nPlease Enter the name of the Customer: \t ");
       fgets(ord.customer,50,stdin); // gets string: the customer, max size & standard input
       ord.customer[strlen(ord.customer)-1]=0; //removes the /n after the previous line
       strcpy(ord.date,__DATE__); //gets the date and store it in the ord.date
       printf("\nPlease enter the number of items:\t");
       scanf("%d",&n);
       ord.numOfItems = n;
       

       for(int i=0; i<n; i++){
           fgetc(stdin);
           printf("\n\n");
           printf("Please Enter the Item %d:\t",i+1);
           fgets(ord.itm[i].item,20,stdin); // min 18:00
           ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
           printf("Please Enter the quantity: \t");
           scanf("%d",&ord.itm[i].qty);
           printf("Please Enter the unit price:\t");
           scanf("%f",&ord.itm[i].price);   
           total+= ord.itm[i].qty* ord.itm[i].price;
       }
       generateBillHeader(ord.customer,ord.date);
       for(int i=0; i<ord.numOfItems; i++){
          generateBillBody(ord.itm[i].item, ord.itm[i].qty,ord.itm[i].price);
       }
       generateBillFooter(total);
       printf("\nDo you want to save the Invoice: [y/n] \t");
       scanf("%s",&saveBill);

       if (saveBill == 'y'){
        fp = fopen("RestaurantBill.dat","a+"); //open the file: name of file, mode in which to open
        fwrite(&ord,sizeof(struct orders),1,fp); //min 29
        if(fwrite != 0){printf("\nSuccessfully Saved");}
        else {printf("\nSaved Failed");}
        fclose(fp);
       }
       break;

       case 2:
       system("cls");
       fp = fopen("RestaurantBill.dat","r"); //opening in read mode
       printf("\n ********Your Previous Invoicess**********\n");
       while(fread(&order,sizeof(struct orders),1,fp)){
         float tot = 0;
          generateBillHeader(order.customer,order.date);
           for(int i= 0;i<order.numOfItems;i++ ){
             generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price); 
             tot += order.itm [i].qty *order.itm[i].price;   
           }
           generateBillFooter(tot);
       }
       fclose(fp);
       break;

       case 3:
       printf("\nEnter the name of the customer:\t");
       //fgetc(stdin);
       fgets(name,50,stdin);
       name[strlen(name)-1] = 0;
       system("cls");
       fp = fopen("RestaurantBill.dat","r"); //opening in read mode
       printf("\t ********Invoice of %s **********\n",name);
       while(fread(&order,sizeof(struct orders),1,fp)){
         float tot = 0;

         if(!strcmp(order.customer,name)) {
          generateBillHeader(order.customer,order.date);
           for(int i= 0;i<order.numOfItems;i++ ){
             generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price); 
             tot += order.itm [i].qty *order.itm[i].price;   
           }
           generateBillFooter(tot);
           invoiceFound = 1;
         }

       }
       if(!invoiceFound){
         printf("\nSorry the invoice of %s does not exist.",name);

       }
       fclose(fp);
       break;

       case 4:
       printf("\n\t\t Bye Bye \n\n");
       exit(0); //exits from the program
       break;

       default:
       printf("Sorry Invalid Option");
       break;
    }
    printf("\nDo you want to perform another operation :[y/n]");
    scanf("%s",&contFlag);
   }
    printf("\n\n");
    printf("\n\t\t Bye Bye \n\n");
    return 0;

}