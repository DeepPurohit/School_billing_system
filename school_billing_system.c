#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>


//global variable for total entries
static int t_total,s_total,prev_s_total,prev_t_total;
static int pgt_ttl,prt_ttl,tgt_ttl;
//function declarations
void t_menu();
void s_menu();

//teacher functions
void t_add();
void t_disp(int);
int gen_id(int);
void t_edit(int);
void t_data_delete(int);

//student functions
void s_add();
void s_disp(int);
void s_edit(int);
void s_data_delete(int);
int s_id_gen(int);


//structure declaration
struct teachers{

    char name[50];
    char gender;
    char address[200];
    int ID_no;
    char dsn[3];
    int salary;
    char contact_no[10];
	int status; //salary given or not status
	char marital_status;
};

struct student{
char name[50];
    char gender;
    char address[200];
    int s_class;
    char sec;
    char contact_no[10];
    int fees;
    int adm_no;
	int status; //fees paid or not status
};

struct teachers *ptr_t[0];
struct student *ptr_s[0];


//welcome function

void wlcm(){
	system("color 4b");
	printf("\n\t\t\t****************************************************************************************************************************\n");
	printf("\n\t\t\t\t\t                           ***********|||| WELCOME TO C PROGRAM ||||**************                                         \n\n");
	printf("\n\t\t\t\t\t                           ***********|||| SCHOOL BILLING SYSTEM ||||*************                                          \n\n");

	printf("\n\t\t\t******************************************************************************************************************************\n\n");

	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t                   DEVELOPED BY GROUP_6\n");

	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t                                1. ANAMIKA SHUKLA");

	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t                                2. DEEP PUROHIT");

	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t                                3. DEEPAK KUMAR SOAM");

	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t                                4. PRIYA PATEL");

	printf("\n\n\t\t\t---------------------------------------------------------------------------------------------------------------------------------\n\n");
	printf("\n\tIn this system we tried our best to reduce the documentation part for the school in the collection of fees\n");
	printf("\n\tof the students and salary distribution of teachers and staffs.\n");
	printf("\n\t|$|$|$|   FUNCTION USED TO EASE THE DOCUMENTATION   |$|$|$|\n");
	printf("\n\t1. Add Function\n");
	printf("\n\t2. Display Function\n");
	printf("\n\t3. Edit Function\n");
	printf("\n\t4. Delete Function\n");
	printf("\n\t5. Unique ID Generation Function\n");

	printf("\n\n\n\t\t ENTER ANY KEY TO CONTINUE....");

	getch();
}



//menu function

//stdent menu
void s_menu(){
	system("cls");
    printf("\n***************************************************************\n");
    printf("\n\t\tSelect your option\n");
    printf("\n\t1. Add Student's details\n\t2. Display Student's details\n\t3. Edit Details\n\t4. Delete Account\n\t5. Back\n\t6. Exit\n\n");
    printf("\n***************************************************************\n");
}


//teacher's menu
void t_menu(){
    system("cls");
    printf("\n***************************************************************\n");
    printf("\n\t\tSelect your option\n");
    printf("\n\t1. Add Teacher's details\n\t2. Display Teacher's details\n\t3. Edit Details\n\t4. Delete Account\n\t5. Back\n\t6. Exit\n\n");
    printf("\n***************************************************************\n");

}


//main function
int main(){
    system("cls");
    int s_op,t_op,m_op,num;
    char ch ;

	wlcm();

    start: //label

    		system("cls");
    		printf("\n\n\t*********************** Select Account Type ****************************\n");
        	printf("\t1. Student's Account\n\t2. Teacher's Account\n\t3. Exit\n");
        	printf("\t*****************************************************\n");
        	scanf("%d",&m_op);
        	while(m_op>=0 || m_op<0)
			                    {
			                    	if(m_op>=1 && m_op<=3)
			                    		break;
									else if(isalpha(m_op)){
										printf("\nplease enter numerals only : 1/2/3 \n");
			                             fflush(stdin);
			                    		scanf("%d",&m_op);
									}
			                    	else
			                    	{
			                    		printf("\nplease enter numerals only : 1/2/3 \n");
			                             fflush(stdin);
			                    		scanf("%d",&m_op);
									}
								}


    switch(m_op){
        	//student section
        	case 1:
        		system("color 3b");
        std_strt:	s_menu();
        			scanf("%d",&s_op);
        			while(s_op>=0 || s_op<0)
			                    {
			                    	if(s_op>=1 && s_op<=6)
			                    		break;
									else if(isalpha(s_op)){
										printf("\nplease enter numerals only : 1/2/3/4/5/6 \n");
			                             fflush(stdin);
			                    		scanf("%d",&s_op);
									}
			                    	else
			                    	{
			                    		printf("\nplease enter numerals only : 1/2/3/4/5/6 \n");
			                             fflush(stdin);
			                    		scanf("%d",&s_op);
									}
								}

        			switch(s_op){
    					case 1:
			                    fflush(stdin);
			                    s_add();
			                    s_op=0;
			                    goto std_strt;

			            case 2:
			                    s_disp(s_total);
			                    s_op=0;
			                    goto std_strt;

			            case 3:
			            		s_edit(s_total);
			            		s_op=0;
			            		goto std_strt;

						case 4:
								s_data_delete(s_total);
								s_op=0;
								goto std_strt;

						case 5 : goto start;

			            case 6: exit(0);
			            default: printf("Wrong option\n");

					}

        		break;

			//teacher section
        	case 2:system("color 5f");
        tchr_strt:	t_menu();
    				scanf("%d",&t_op);
    				while(t_op>=0 || t_op<0)
			                    {
			                    	if(t_op>=1 && t_op<=6)
			                    		break;
									else if(isalpha(t_op)){
										printf("\nplease enter numerals only : 1/2/3/4/5/6 \n");
			                             fflush(stdin);
			                    		scanf("%d",&t_op);
									}
			                    	else
			                    	{
			                    		printf("\nplease enter numerals only : 1/2/3/4/5/6 \n");

			                             fflush(stdin);
			                    		scanf("%d",&t_op);
									}
								}

    				switch(t_op){
    					case 1:
			                    fflush(stdin);
			                    t_add();
			                    t_op=0;
			                    goto tchr_strt;

			            case 2:
			                    t_disp(t_total);
			                    t_op=0;
			                    goto tchr_strt;

			            case 3:
			            		t_edit(t_total);
			            		t_op=0;
			            		goto tchr_strt;

						case 4:
								t_data_delete(t_total);
								t_op=0;
								goto tchr_strt;

						case 5: goto start;

			            case 6: exit(0);
			            default: printf("Wrong option\n");

					}

        		break;

        	case 3: exit(0);

        	default: printf("Wrong option\n");

            goto start;

        }



}


//function declarations

//Add teacher's details

void t_add(){
	int temp,k;
	int i=prev_t_total;

	t_total++;

        while(i<t_total)
        {
        	//printf("\nAllocating memory for i = %d when t_total = %d\n",i,t_total);
            ptr_t[i]=(struct teachers*)malloc(sizeof(struct teachers));



     fflush(stdin);
     system("cls");
     printf("******************* Enter details ************************\n\n");

    	printf("\n\tAdd Account %d\n",i+1);
    	fflush(stdin);
        printf("\n\tName : ");
        gets(ptr_t[i]->name);

        for(k=0;ptr_t[i]->name[k]!='\0';)
        {
        	if(isalpha(ptr_t[i]->name[k]) || ptr_t[i]->name[k]==' ')
        		k++;


        	else
        	{
        		k=0;
        		printf("\n\tPlease enter alphabets only\n");
        		fflush(stdin);
		        printf("\n\tName : ");
		        gets(ptr_t[i]->name);

			}
		}

		while(ptr_t[i]->name[0] =='\0'){
				printf("\n\tPlease enter Name\n");
        		fflush(stdin);
		        printf("\n\tName : ");
		        gets(ptr_t[i]->name);
			}


        fflush(stdin);
        printf("\n\tGender (M/F): ");
        scanf("%c",&ptr_t[i]->gender);

		while(ptr_t[i]->gender =='\0'){
				printf("\n\tPlease enter Gender\n");
        		fflush(stdin);
		        printf("\n\tGender : ");
		        scanf("%c",ptr_t[i]->gender);
			}

        while(ptr_t[i]->gender != 'm')
        {
            if(ptr_t[i]->gender=='M' ||ptr_t[i]->gender=='f' || ptr_t[i]->gender=='F')
                break;

            else
            {
            fflush(stdin);
            printf("\n\t**** PLEASE ENTER F/f FOR FEMALE AND M/m FOR MALE **** \n\t");
            scanf("%c",&ptr_t[i]->gender);
            }

        }

        printf("\n\tAddress : ");
        fflush(stdin);
        gets(ptr_t[i]->address);

        while(ptr_t[i]->address[0] == '\0' ){

				printf("\n\tPlease enter Address\n");
        		fflush(stdin);
		        printf("\n\tAddress : ");
		        gets(ptr_t[i]->address);

			}

        

        printf("\n\tDesignation (PRT/TGT/PGT): ");
        fflush(stdin);
        scanf("%s",&ptr_t[i]->dsn);

        while(ptr_t[i]->dsn[0] =='\0'){
				printf("\n\tPlease enter Designation\n");
        		fflush(stdin);
		        printf("\n\tDesignation : ");
		        gets(ptr_t[i]->dsn);
			}


        while(stricmp(ptr_t[i]->dsn,"PRT")!=0)
        {
            if(stricmp(ptr_t[i]->dsn,"PGT")==0||stricmp(ptr_t[i]->dsn,"TGT")==0)
            break;

            else {
            fflush(stdin);
            printf("\n\t**** PLEASE ENTER A 3 LETTER DESIGNATION:PRT , TGT , PGT **** \n");
            printf("\t");
            scanf("%s",&ptr_t[i]->dsn);
            }

        }

        printf("\n\tContact number : ");
        fflush(stdin);
        scanf("%s",&ptr_t[i]->contact_no);


               while(strlen(ptr_t[i]->contact_no)>10||strlen(ptr_t[i]->contact_no)<10)
        {

            printf("\n\tEnter a 10 digit mobile number only ! Please enter again ! ");
            printf("\n\tContact number : ");
            fflush(stdin);
            scanf("%s",&ptr_t[i]->contact_no);
            k=0;
        

		for(k=0;ptr_t[i]->contact_no[k]!='\0';)
        {
            if(isalpha(ptr_t[i]->contact_no[k]))
             {
                        k=0;
                        printf("\n\t**PLEASE ENTER NUMBERS ONLY. ALPHABETS ARE NOT ALLOWED**\n");
                        printf("\n\tContact number : ");
                        fflush(stdin);
                        scanf("%s",&ptr_t[i]->contact_no);


             }

            else
            {
                k++;

            }

        }
    }



        if(stricmp(ptr_t[i]->dsn,"PRT")==0){
        	prt_ttl++;
			ptr_t[i]->salary = 20000;
		}
		else if(stricmp(ptr_t[i]->dsn,"TGT")==0){
			tgt_ttl++;
			ptr_t[i]->salary = 30000;
		}
		else if(stricmp(ptr_t[i]->dsn,"PGT")==0){
			pgt_ttl++;
			ptr_t[i]->salary = 45000;
		}

		//salary status
		ptr_t[i]->status = 0;

        printf("\n\tMarital Status (Y/N): ");
        fflush(stdin);
        scanf("%c",&ptr_t[i]->marital_status);

		while(ptr_t[i]->marital_status =='\0'){
				printf("\n\tPlease enter Marital Status\n");
        		fflush(stdin);
		        printf("\n\tMarital Status : ");
		        scanf("%c",&ptr_t[i]->marital_status);
			}


        while(ptr_t[i]->marital_status!='y')
        {
            if(ptr_t[i]->marital_status=='n' || ptr_t[i]->marital_status=='N' || ptr_t[i]->marital_status=='Y' )
                break;

            else
            {
            fflush(stdin);
            printf("\n\t**** PLEASE ENTER Y IF MARRIED ELSE N **** \n");
            scanf("%c",&ptr_t[i]->marital_status);
            }

        }
        
        //to generate id
        temp=i+1;

        ptr_t[i]->ID_no = gen_id(temp);

         //converting lower case to upper case
         ptr_t[i]->marital_status=toupper(ptr_t[i]->marital_status);
        strcpy(ptr_t[i]->dsn,strupr(ptr_t[i]->dsn));
        ptr_t[i]->gender=toupper(ptr_t[i]->gender);


        printf("\n\n");
			i++;
			
			

}


	prev_t_total=t_total;

    printf("\n\n********* Press any key to continue ************\n");
    getch();

}



//function generate id

int gen_id(int ttl){

	int id = 1001000+ttl;
	int k;

	for(k=0;k<t_total;k++)
	{
		if(ptr_t[k]->ID_no==id)
		{
			k=0;
			id=id+1;
		}

	}

	return id;
}




//Display function

void t_disp(int ttl){
    int i=0,choice,count=1,tgt_count=1,prt_count=1,pgt_count=1;
    char *paid = "Paid";
    char *n_paid = "Not Paid";
    fflush(stdin);
    choose: //label
    system("cls");
    printf("\n\t********************* Select Option To Display ***************************\n\n");
    printf("\t1. PRT Teachers\n\t2. TGT Teachers\n\t3. PGT Teachers\n\t4. View all\n\t5. Salary Status - Not Paid\n\t6. Salary Status Paid\n\t7. Exit\n\n");
    scanf("%d",&choice);
    
    			while(choice>=0 || choice<0)
			                    {
			                    	if(choice>=1 && choice<=7)
			                    		break;
									else if(isalpha(choice)){
										printf("\nplease enter numerals only : 1/2/3/4/5/6/7 \n");
			                             fflush(stdin);
			                    		scanf("%d",&choice);
									}
			                    	else
			                    	{
			                    		printf("\nplease enter numerals only : 1/2/3/4/5/6/7 \n");

			                             fflush(stdin);
			                    		scanf("%d",&choice);
									}
								}
    
    
    switch(choice){
    	case 1:
    			printf("********************* Details of PRT Teachers **************************\n\n");
    			if(ttl==0)
					printf("\tNo record found\n");
				else{
    			for(i=0; i<ttl; i++){
				    	//details of prt teachers
				    	if(stricmp(ptr_t[i]->dsn,"PRT")==0){
				    		printf("\tID no.      		:%d\n",ptr_t[i]->ID_no);
				    		printf("\tName        		:%s\n",ptr_t[i]->name);
				    		printf("\tGender      		:%c\n",ptr_t[i]->gender);
				    		printf("\tContact no.     	:%s\n",ptr_t[i]->contact_no);
				    		printf("\tAddress      		:%s\n",ptr_t[i]->address);
				    		printf("\tSalary      		:%d\n",ptr_t[i]->salary);
				    		printf("\tMarital Status\t        :%c\n",ptr_t[i]->marital_status);
				    		if(ptr_t[i]->status==0)
				    		printf("\tSalary Status\t        :%s\n",n_paid);
				    		else
				    		printf("\tSalary Status\t        :%s\n",paid);
				    		printf("\n***********************************************************************\n");
				    		count++;
						}

					}
					if(count==0)
							printf("\tNo PRT teacher found in record\n");
						else
							count=0;
				}
				break;
		case 2:
				printf("********************* Details of TGT Teachers **************************\n\n");
				if(ttl==0)
					printf("\n\tNo record found\n");
				else{
    			for(i=0; i<ttl; i++){
				    	//details of tgt teachers
				    	if(stricmp(ptr_t[i]->dsn,"TGT")==0){
				    		printf("\tID no.      		:%d\n",ptr_t[i]->ID_no);
				    		printf("\tName        		:%s\n",ptr_t[i]->name);
				    		printf("\tGender      		:%c\n",ptr_t[i]->gender);
				    		printf("\tContact no.     	:%s\n",ptr_t[i]->contact_no);
				    		printf("\tAddress      		:%s\n",ptr_t[i]->address);
				    		printf("\tSalary      		:%d\n",ptr_t[i]->salary);
				    		printf("\tMarital Status\t        :%c\n",ptr_t[i]->marital_status);
				    		if(ptr_t[i]->status==0)
				    		printf("\tSalary Status\t        :%s\n",n_paid);
				    		else
				    		printf("\tSalary Status\t        :%s\n",paid);
				    		printf("\n***********************************************************************\n");
						count++;
						}

					}
					if(count==0)
							printf("\tNo TGT teacher found in record\n");
						else
							count=0;
				}
				break;
		case 3:
				printf("********************* Details of PGT Teachers **************************\n\n");
				if(ttl==0)
					printf("\tNo record found\n");
				else{
    			for(i=0; i<ttl; i++){
				    	//details of pgt teachers
				    	if(stricmp(ptr_t[i]->dsn,"PGT")==0){
				    		printf("\tID no.      		:%d\n",ptr_t[i]->ID_no);
				    		printf("\tName        		:%s\n",ptr_t[i]->name);
				    		printf("\tGender      		:%c\n",ptr_t[i]->gender);
				    		printf("\tContact no.     	:%s\n",ptr_t[i]->contact_no);
				    		printf("\tAddress      		:%s\n",ptr_t[i]->address);
				    		printf("\tSalary      		:%d\n",ptr_t[i]->salary);
				    		printf("\tMarital Status\t        :%c\n",ptr_t[i]->marital_status);
				    		if(ptr_t[i]->status==0)
				    		printf("\tSalary Status\t        :%s\n",n_paid);
				    		else
				    		printf("\tSalary Status\t        :%s\n",paid);
				    		printf("\n***********************************************************************\n");
							count++;
						}

					}
					if(count==0)
							printf("\tNo PGT teacher found in record\n");
						else
							count=0;
				}
				break;
		case 4:
				printf("********************* Details of All Teachers **************************\n\n");
				if(ttl==0)
					printf("\n\tNo record found\n");
				else{
    			for(i=0; i<ttl; i++){
				    		printf("\tID no.      		:%d\n",ptr_t[i]->ID_no);
				    		printf("\tName        		:%s\n",ptr_t[i]->name);
				    		printf("\tDesignation\t        :%s\n",ptr_t[i]->dsn);
				    		printf("\tGender      		:%c\n",ptr_t[i]->gender);
				    		printf("\tContact no.     	:%s\n",ptr_t[i]->contact_no);
				    		printf("\tAddress      		:%s\n",ptr_t[i]->address);
				    		printf("\tSalary      		:%d\n",ptr_t[i]->salary);
				    		printf("\tMarital Status\t        :%c\n",ptr_t[i]->marital_status);
				    		if(ptr_t[i]->status==0)
				    		printf("\tSalary Status\t        :%s\n",n_paid);
				    		else
				    		printf("\tSalary Status\t        :%s\n",paid);
				    		printf("\n***********************************************************************\n");
					}
				}
				break;
		case 5: printf("********************* Details of Teacher's Salary Not Paid **************************\n\n");
				tgt_count=1,prt_count=1,pgt_count=1;//initialising count
				if(ttl==0)
					printf("\n\tNo record found\n");

    				else{
    					if(pgt_ttl>0){
						printf("********************* Details of PGT Teacher's Salary Not Paid **************************\n\n");
					
									for(i=0; i<ttl; i++){
										if(stricmp(ptr_t[i]->dsn,"PGT")==0){
					
											if(ptr_t[i]->status==0){
									    		printf("\tID no.      		:%d\n",ptr_t[i]->ID_no);
									    		printf("\tName        		:%s\n",ptr_t[i]->name);
									    		printf("\n***********************************************************************\n");
									    	}
									    	else{
									    		pgt_count++;
											}
											if(pgt_count>pgt_ttl){
												printf("\tAll PGT teacher's salary has been paid\n\n");
											}
										}
									}
								}
						else{
							printf("********************* Details of PGT Teacher's Salary Not Paid **************************\n\n");
							printf("\tNo PGT teacher found in record\n");	
						}
								
					if(tgt_ttl>0){
						printf("********************* Details of TGT Teacher's Salary Not Paid **************************\n\n");
					
									for(i=0; i<ttl; i++){
										if(stricmp(ptr_t[i]->dsn,"TGT")==0){
					
											if(ptr_t[i]->status==0){
									    		printf("\tID no.      		:%d\n",ptr_t[i]->ID_no);
									    		printf("\tName        		:%s\n",ptr_t[i]->name);
									    		printf("\n***********************************************************************\n");
									    	}
									    	else{
									    		tgt_count++;
											}
											if(tgt_count>tgt_ttl){
												printf("\tAll TGT teacher's salary has been paid\n\n");												
											}
										}
									}
								}
						
						else{
							printf("********************* Details of TGT Teacher's Salary Not Paid **************************\n\n");
							printf("\tNo PGT teacher found in record\n");	
						}	
								
					if(prt_ttl>0){
						printf("********************* Details of PRT Teacher's Salary Not Paid **************************\n\n");
					
									for(i=0; i<ttl; i++){
										if(stricmp(ptr_t[i]->dsn,"PRT")==0){
					
											if(ptr_t[i]->status==0){
									    		printf("\tID no.      		:%d\n",ptr_t[i]->ID_no);
									    		printf("\tName        		:%s\n",ptr_t[i]->name);
									    		printf("\n***********************************************************************\n");
									    	}
									    	else{
									    		prt_count++;
											}
											if(prt_count>prt_ttl){
												printf("\tAll PRT teacher's salary has been paid\n\n");											
											}
										}
									}
								}		    				
					
						else{
							printf("********************* Details of PRT Teacher's Salary Not Paid **************************\n\n");
							printf("\tNo PRT teacher found in record\n");	
						}
					}	
				break;

		case 6: printf("********************* Details of Teacher's Salary Paid **************************\n\n");
			
				tgt_count=1,prt_count=1,pgt_count=1;//initialising count
				
				if(ttl==0)
					printf("\n\tNo record found\n");
				
				else{
					if(pgt_ttl>0){
						printf("********************* Details of PGT Teacher's Salary Paid **************************\n\n");
					
									for(i=0; i<ttl; i++){
										if(stricmp(ptr_t[i]->dsn,"PGT")==0){
					
											if(ptr_t[i]->status==1){
									    		printf("\tID no.      		:%d\n",ptr_t[i]->ID_no);
									    		printf("\tName        		:%s\n",ptr_t[i]->name);
									    		printf("\n***********************************************************************\n");
									    	}
									    	else{
									    		pgt_count++;
											}
										
											if(pgt_count>pgt_ttl){
												printf("\tAll PGT teacher's salary is remaining to be paid\n\n");
											}
										}
									}
								}
						else{
							printf("********************* Details of PGT Teacher's Salary Paid **************************\n\n");
							printf("\n\tNo PGT teacher found in record\n");	
						}
								
					if(tgt_ttl>0){
						printf("********************* Details of TGT Teacher's Salary Paid **************************\n\n");
					
									for(i=0; i<ttl; i++){
										if(stricmp(ptr_t[i]->dsn,"TGT")==0){
					
											if(ptr_t[i]->status==1){
									    		printf("\tID no.      		:%d\n",ptr_t[i]->ID_no);
									    		printf("\tName        		:%s\n",ptr_t[i]->name);
									    		printf("\n***********************************************************************\n");
									    	}
									    	else{
									    		tgt_count++;
											}
										
											if(tgt_count>tgt_ttl){
												printf("\tAll TGT teacher's salary remaining to be paid\n\n");
											}
										}
									}
								}
						
						else{
							printf("********************* Details of TGT Teacher's Salary Paid **************************\n\n");
							printf("\n\tNo TGT teacher found in record\n");	
						}	
								
					if(prt_ttl>0){
						printf("********************* Details of PRT Teacher's Salary Paid **************************\n\n");
					
									for(i=0; i<ttl; i++){
										if(stricmp(ptr_t[i]->dsn,"PRT")==0){
					
											if(ptr_t[i]->status==1){
									    		printf("\tID no.      		:%d\n",ptr_t[i]->ID_no);
									    		printf("\tName        		:%s\n",ptr_t[i]->name);
									    		printf("\n***********************************************************************\n");
									    	}
									    	else{
									    		prt_count++;
											}
										
											if(prt_count>prt_ttl){
												printf("\tAll PRT teacher's salary remaining to be paid\n\n");
											}
										}
									}
								}		    				
					
						else{
							printf("********************* Details of PRT Teacher's Salary Paid **************************\n\n");
							printf("\n\tNo PRT teacher found in record\n");	
						}
				}
    				
				break;
		case 7: return;
		default: {
				printf("\n***** Wrong option ******\n");
				Sleep(6);
				goto choose;
			}
	}
    printf("\n\n********* Press any key to continue ************\n");
    getch();
    goto choose;

}


//function to edit details

void t_edit(int ttl){
	int i=0,tmp_id=0;
	char option;
	char cnfrm;
	int count = 1,m_op=0;

	char *paid = "Paid";
    char *n_paid = "Not Paid";

	//temp variables
	char tmp_name[50];
	char tmp_address[200];
    char tmp_dsn[3];
    char tmp_contact_no[10];
    int tmp_salary,tmp_status;
    char tmp_marital_status;

    system("cls");

    if(ttl==0){
    	printf("\n***************************************************\n");
    	printf("\n\t\tNo record found\n");
    	printf("\n\n********* Press any key to continue ************\n");
    	getch();
    	return;
	}

	printf("\n\t************************************* Edit Details *********************************************\n");
	printf("\tEnter teacher's id:\t");
	scanf("%d",&tmp_id);
	printf("\n\tEnter teacher's name:\t");
	fflush(stdin);
	gets(tmp_name);
	//iteration
	for(i=0; i<ttl; i++){
		if(ptr_t[i]->ID_no==tmp_id && stricmp(ptr_t[i]->name,tmp_name)==0){

			//present data
			edit: //lable
					printf("\n\tID no.      		:%d\n",ptr_t[i]->ID_no);
				    printf("\tName        		:%s\n",ptr_t[i]->name);
				    printf("\tDesignation\t        :%s\n",ptr_t[i]->dsn);
				    printf("\tGender      		:%c\n",ptr_t[i]->gender);
				    printf("\tContact no.     	:%s\n",ptr_t[i]->contact_no);
				    printf("\tAddress      		:%s\n",ptr_t[i]->address);
				    printf("\tSalary      		:%d\n",ptr_t[i]->salary);
				    printf("\tMarital Status\t        :%c\n",ptr_t[i]->marital_status);
				    if(ptr_t[i]->status==0)
				    printf("\tSalary Status\t        :%s\n",n_paid);
				    else
				    printf("\tSalary Status\t        :%s\n",paid);
				    printf("\n***********************************************************************\n");

			//enter new data
			printf("\n\tChoose Option to EDIT Details\n");
			printf("\t1. Name\n\t2. Address\n\t3. Designation\n\t4. Phone number\n\t5. Marital Status\n\t6. Salary\n\t7. Salary Status\n\t8. Go Back\n\n");
			scanf("%d",&m_op);
			while(m_op>=0 || m_op<0)
			                    {
			                    	if(m_op>=1 && m_op<=8)
			                    		break;
									else if(isalpha(m_op)){
										printf("\nplease enter numerals only : 1/2/3/4/5/6/7/8 \n");
			                             fflush(stdin);
			                    		scanf("%d",&m_op);
									}
			                    	else
			                    	{
			                    		printf("\nplease enter numerals only : 1/2/3/4/5/6/7/8 \n");

			                             fflush(stdin);
			                    		scanf("%d",&m_op);
									}
								}
			switch(m_op){
				case 1:
						fflush(stdin);
				        printf("\n\tName : ");
				        gets(tmp_name);

				        //confirmng

				        printf("\n\tConfirm the edit to this account?(y/n):\t");
						fflush(stdin);
						scanf("%c",&cnfrm);

						while(cnfrm!='y')
	                        {
	                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
	                                break;

	                            else
	                            {
	                            fflush(stdin);
	                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
	                            scanf("%c",&cnfrm);
	                            }

	                        }
						if(cnfrm=='y' || cnfrm=='Y'){
	                     	printf("\n\n\t******** Changes saved **********\n\n");
	                     	strcpy(ptr_t[i]->name,tmp_name);
	                     }
	                    else
	                    	goto edit;
				    goto edit;

				case 2:
						fflush(stdin);
				        printf("\n\tAddress : ");
				        gets(tmp_address);


				       //confirmng

				        printf("\n\tConfirm the edit to this account?(y/n):\t");
						fflush(stdin);
						scanf("%c",&cnfrm);

						while(cnfrm!='y')
	                        {
	                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
	                                break;

	                            else
	                            {
	                            fflush(stdin);
	                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
	                            scanf("%c",&cnfrm);
	                            }

	                        }
						if(cnfrm=='y' || cnfrm=='Y'){
	                     	printf("\n\n\t******** Changes saved **********\n\n");
	                     	strcpy(ptr_t[i]->address,tmp_address);
	                     }
	                    else
	                    	goto edit;

				    goto edit;

				case 3:
						printf("\n\tDesignation : ");
					    fflush(stdin);

					    scanf("%s",&tmp_dsn);
                        while(stricmp(tmp_dsn,"PRT")!=0)
                        {
                            if(stricmp(tmp_dsn,"PGT")==0||stricmp(tmp_dsn,"TGT")==0)
                            break;

                            else {
                            fflush(stdin);
                            printf("\n\t**** PLEASE ENTER A 3 LETTER DESIGNATION:PRT/prt , TGT/tgt , PGT/pgt **** \n");
                            printf("\t");
                            scanf("%s",tmp_dsn);
                            }

                        }

                        //confirmng

				        printf("\n\tConfirm the edit to this account?(y/n):\t");
						fflush(stdin);
						scanf("%c",&cnfrm);

						while(cnfrm!='y')
	                        {
	                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
	                                break;

	                            else
	                            {
	                            fflush(stdin);
	                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
	                            scanf("%c",&cnfrm);
	                            }

	                        }
						if(cnfrm=='y' || cnfrm=='Y'){
	                     	printf("\n\n\t******** Changes saved **********\n\n");
	                     	strcpy(ptr_t[i]->dsn,tmp_dsn);

			                     	//updating salary
			                     	if(stricmp(ptr_t[i]->dsn,"PRT")==0){
		                                ptr_t[i]->salary = 20000;
		                        }
		                        else if(stricmp(ptr_t[i]->dsn,"TGT")==0){
		                                ptr_t[i]->salary = 30000;
		                    	}
		                        else if(stricmp(ptr_t[i]->dsn,"PGT")==0){
		                                ptr_t[i]->salary = 45000;
		                        }

	                     }
	                    else
	                    	goto edit;

					goto edit;

				case 4:
						printf("\n\tContact number : ");
				        fflush(stdin);
				        gets(tmp_contact_no);
				        int k;
                        for(k=0;tmp_contact_no[k]!='\0';)
                        {
                               while(strlen(tmp_contact_no)>10||strlen(tmp_contact_no)<10)
                        {

                            printf("\n\t***** Enter a 10 digit mobile number only ! Please enter again ! *****\n");
                            printf("\n\tContact number : ");
                            fflush(stdin);
                            scanf("%s",&tmp_contact_no);
                            k=0;
                        }

                            if(isalpha(tmp_contact_no[k]))
                             {
                                 k=0;
                                        printf("\n\t**** PLEASE ENTER NUMBERS ONLY. ALPHABETS ARE NOT ALLOWED ****\n");
                                        printf("\n\tContact number : ");
                                        fflush(stdin);
                                        scanf("%s",&tmp_contact_no);


                             }

                            else
                            {
                                k++;

                            }

                        }

                        //confirmng

				        printf("\n\tConfirm the edit to this account?(y/n):\t");
						fflush(stdin);
						scanf("%c",&cnfrm);

						while(cnfrm!='y')
	                        {
	                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
	                                break;

	                            else
	                            {
	                            fflush(stdin);
	                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
	                            scanf("%c",&cnfrm);
	                            }

	                        }
						if(cnfrm=='y' || cnfrm=='Y'){
	                     	printf("\n\n\t******** Changes saved **********\n\n");
	                     	strcpy(ptr_t[i]->contact_no,tmp_contact_no);
	                     }
	                    else
	                    	goto edit;

				    goto edit;

				case 5:
						printf("\n\tMarital Status (y/Y/n/N): ");
				        fflush(stdin);
				        scanf("%c",&tmp_marital_status);
				        while(tmp_marital_status!='y')
                        {
                            if(tmp_marital_status=='n' || tmp_marital_status=='N' || tmp_marital_status=='Y' )
                                break;

                            else
                            {
                            fflush(stdin);
                            printf("\n\t**** PLEASE ENTER Y/y IF MARRIED ELSE N/n **** \n");
                            scanf("%c",&tmp_marital_status);
                            }

                        }


                        //confirmng

				        printf("\n\tConfirm the edit to this account?(y/n):\t");
						fflush(stdin);
						scanf("%c",&cnfrm);

						while(cnfrm!='y')
	                        {
	                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
	                                break;

	                            else
	                            {
	                            fflush(stdin);
	                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
	                            scanf("%c",&cnfrm);
	                            }

	                        }
						if(cnfrm=='y' || cnfrm=='Y'){
	                     	printf("\n\n\t******** Changes saved **********\n\n");
	                     	ptr_t[i]->marital_status=tmp_marital_status;
	                     }
	                    else
	                    	goto edit;

				     goto edit;

				case 6:
						printf("\n\tEnter Salary:\t");
						scanf("%d",&tmp_salary);

						//confirmng

				        printf("\n\tConfirm the edit to this account?(y/n):\t");
						fflush(stdin);
						scanf("%c",&cnfrm);

						while(cnfrm!='y')
	                        {
	                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
	                                break;

	                            else
	                            {
	                            fflush(stdin);
	                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
	                            scanf("%c",&cnfrm);
	                            }

	                        }
						if(cnfrm=='y' || cnfrm=='Y'){
	                     	printf("\n\n\t******** Changes saved **********\n\n");
	                     	ptr_t[i]->salary=tmp_salary;
	                     }
	                    else
	                    	goto edit;

					goto edit;

				case 7:
						printf("\n\tSalary status (1=paid and 0=not paid):\t");
						scanf("%d",&tmp_status);
						while(tmp_status !=0)
                        {
                            if(tmp_status!=1)
                            {
                                printf("\n\t**** 0-NOT PAID , 1-PAID ****\n");
                                scanf("%d",&tmp_status);
                            }
                            else
                                break;
                        }

                        //confirmng

				        printf("\n\tConfirm the edit to this account?(y/n):\t");
						fflush(stdin);
						scanf("%c",&cnfrm);

						while(cnfrm!='y')
	                        {
	                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
	                                break;

	                            else
	                            {
	                            fflush(stdin);
	                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
	                            scanf("%c",&cnfrm);
	                            }

	                        }
						if(cnfrm=='y' || cnfrm=='Y'){
	                     	printf("\n\n\t******** Changes saved **********\n\n");
	                     	ptr_t[i]->status = tmp_status;
	                     }
	                    else
	                    	goto edit;

	                goto edit;

				case 8: return;

				default: printf("\n\t**** Please enter valid option ****\n");
						 goto edit;

			}


		}
		else
			count++;
	}
	if(count>ttl){
		printf("Wrong Id no. or Name\n");
	}

	printf("\n\n********* Press any key to continue ************\n");
    getch();

}


//function to delete account

void t_data_delete(int ttl){

        int i,j,k;

       	int tmp_ID_no;
       	int pos;
       	char tmp_name[50];
	   	char cnfrm;

	   	char *paid = "Paid";
       	char *n_paid = "Not Paid";

		system("cls");

			if(ttl==0){
				printf("\n***************************************************\n");
    			printf("\n\t\tNo record found\n");
				printf("\n\n********* Press any key to continue ************\n");
    			getch();
				return;
			}
		else{
        printf("\t****************************** DELETE THE DATA ******************************\n");
		printf("\n\tEnter teacher's name:\t");
		fflush(stdin);
		gets(tmp_name);
		printf("\n\n\tEnter ID no. of teacher :-");
        scanf("%d",&tmp_ID_no);

         for(i=0;i<ttl;i++)
             {
                if(tmp_ID_no==ptr_t[i]->ID_no && stricmp(ptr_t[i]->name,tmp_name)==0)

                  {
                     pos=i;

					printf("\tID no.      		:%d\n",ptr_t[i]->ID_no);
				    printf("\tName        		:%s\n",ptr_t[i]->name);
				    printf("\tDesignation\t        :%s\n",ptr_t[i]->dsn);
				    printf("\tGender      		:%c\n",ptr_t[i]->gender);
				    printf("\tContact no.     	:%s\n",ptr_t[i]->contact_no);
				    printf("\tAddress      		:%s\n",ptr_t[i]->address);
				    printf("\tSalary      		:%d\n",ptr_t[i]->salary);
				    printf("\tMarital Status\t        :%c\n",ptr_t[i]->marital_status);
				    if(ptr_t[i]->status==0)
				    printf("\tSalary Status\t        :%s\n",n_paid);
				    else
				    printf("\tSalary Status\t        :%s\n",paid);
				    printf("\n\t***********************************************************************\n");


					printf("\n\tAre you sure you want to delete this account?(y/n):\t");
					fflush(stdin);
					scanf("%c",&cnfrm);

					while(cnfrm!='y')
                        {
                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
                                break;

                            else
                            {
                            fflush(stdin);
                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
                            scanf("%c",&cnfrm);
                            }

                        }
					if(cnfrm=='y' || cnfrm=='Y')
                     	break;
                    else
                    	return;
                  }


				if(strcmp(ptr_t[i]->dsn,"PRT")==0){
		        	prt_ttl--;
				}
				else if(strcmp(ptr_t[i]->dsn,"TGT")==0){
					tgt_ttl--;
				}
				else if(strcmp(ptr_t[i]->dsn,"PGT")==0){
					pgt_ttl--;
				}

             }

                if(i==ttl){
             	printf("\n\t\tError\n");
             	printf("\tWrong ID no.\n");
             	prev_t_total=t_total;
             	sleep(4);
			 }

			 else if(ttl==1)
             {
                 *ptr_t=0;
                 t_total=t_total-1;
                 prev_t_total=t_total;
                printf("\n\t************ ACCOUNT DELETED **************\n");
             }

			else if(pos==t_total-1)
			{
				ptr_t[pos]=NULL;
				free(ptr_t[pos]);
				t_total=t_total-1;
				prev_t_total=t_total;
				printf("\n\t************ ACCOUNT DELETED **************\n");
			}
             else
             {

             	for(i=pos;i<t_total;i++)
				 {
				 	ptr_t[i]=ptr_t[i+1];
				 }

             	ptr_t[t_total-1]=NULL;
             	free(ptr_t[t_total-1]);

				 t_total=t_total-1;
				 prev_t_total=t_total;

				printf("\n\t************ ACCOUNT DELETED **************\n");
			 }


    printf("\n\n********* Press any key to continue ************\n");
    getch();
    return;
}



}





/*************************************************************************************************************************************************************************

                                                                       student part

*************************************************************************************************************************************************************************/


//student add function
void s_add(){
    int i=prev_s_total;
    int j,k;
    s_total = s_total + 1;
     
     system("cls");
     printf("**************** Enter details ************************\n\n");
   	
   	ptr_s[i]=(struct student*)malloc(sizeof(struct student));
   	if(ptr_s[i]==NULL)
   	{
   		printf("\nMEMORY NOT ALLOCATED\n");
   		return;
	   }
	   
	   else
	   {
    	printf("Add Account %d\n",i+1);
    	fflush(stdin);
        printf("\n\tName : ");
        gets(ptr_s[i]->name);
        for(k=0;ptr_s[i]->name[k]!='\0';)
        {
        	if(isalpha(ptr_s[i]->name[k]) || ptr_s[i]->name[k]==' ')
        		k++;
        	else
        	{
        		k=0;
        		printf("\n\tPlease enter alphabets only\n");
        		fflush(stdin);
		        printf("\n\tName : ");
		        gets(ptr_s[i]->name);

			}
		}

		while(ptr_s[i]->name[0] =='\0'){
				printf("\n\tPlease enter Name\n");
        		fflush(stdin);
		        printf("\n\tName : ");
		        gets(ptr_s[i]->name);
			}
        fflush(stdin);
        
        printf("\n\tGender (M/F): ");
		scanf("%c",&ptr_s[i]->gender);
		while(ptr_s[i]->gender=='\0'){
				printf("\n\tPlease enter gender\n");
        		fflush(stdin);
		        printf("\n\tGender (M/F): ");
		        scanf("%c",&ptr_s[i]->gender);
			}
		while(ptr_s[i]->gender != 'm')
        {
            if(ptr_s[i]->gender=='M' ||ptr_s[i]->gender=='f' || ptr_s[i]->gender=='F')
                break;

            else
            {
            fflush(stdin);
            printf("\n\t**PLEASE ENTER F FOR FEMALE AND M FOR MALE IN CAPITAL LETTERS ONLY** \n");
            scanf("%c",&ptr_s[i]->gender);
            }

        }
        
        printf("\n\tAddress : ");
        fflush(stdin);
        gets(ptr_s[i]->address);
		while(ptr_s[i]->address[0] =='\0'){
				printf("\n\tPlease enter Address\n");
        		fflush(stdin);
		        printf("\n\tAddress : ");
		        gets(ptr_s[i]->address);
			}
        fflush(stdin);
       

        printf("\n\tClass: (1-12) ");
        fflush(stdin);
        scanf("%d",&ptr_s[i]->s_class);
        
        while(ptr_s[i]->s_class!=0 || ptr_s[i]->s_class==0) 
        {
        	if(ptr_s[i]->s_class>=1 && ptr_s[i]->s_class<=12 )
        	{
        		break;
			}
			
			else
			{
				printf("\n\tEnter Again\nClass (1-12) : ");
		        fflush(stdin);
		        scanf("%d",&ptr_s[i]->s_class);
				
			}
		}


        printf("\n\tSection: ");
        fflush(stdin);
        scanf("%c",&ptr_s[i]->sec);
        while(ptr_s[i]->name[0] =='\0'){
				printf("\n\tPlease enter Section\n");
        		fflush(stdin);
		        printf("\n\tSection : ");
		        scanf("%s",&ptr_s[i]->sec);
			}
        fflush(stdin);
        
        while(isalpha(ptr_s[i]->sec)==0)
        {
            printf("\n\t**PLEASE ENTER SECTION (ALPHABET ONLY)**\n");
            scanf("%c",&ptr_s[i]->sec);
        }
        
        while(isalpha(ptr_s[i]->sec)>=0 ||isalpha(ptr_s[i]->sec)<0  )
        {
        	if(ptr_s[i]->sec !='A' && ptr_s[i]->sec !='B' && ptr_s[i]->sec !='C' && ptr_s[i]->sec !='D')
        	{
        	printf("\n\tEnter A , B , C , D \n");
        	printf("\n\tSection: ");
	        fflush(stdin);
	        scanf("%c",&ptr_s[i]->sec);
			}
			
			else
				break;
	        	
		}
        
                            /*printf("\n\tFees : ");
                            scanf("%d",&ptr_s[i]->fees);
                            while(ptr_s[i]->fees!=0 || ptr_s[i]->fees==0)
                            {
                            	if(ptr_s[i]->fees>0)
                            	{
                            		break;
								}
								
								else
								{
                            	printf("\nPlease enter Fees : ");
                                scanf("%d",&ptr_s[i]->fees);
                                }
                            	
							}

                            printf("\n\tFees Status (0-Not Paid , 1-Paid) : ");
                            scanf("%d",&ptr_s[i]->status);
                            
                            while(ptr_s[i]->status!=0)
                            {
                            	if(ptr_s[i]->status==1)
                            	{
                            		break;
								}
								
								else
									{
										printf("\nEnter Again \n Fees Status (0-Not Paid , 1-Paid) : ");
                            			scanf("%d",&ptr_s[i]->status);
										
									}
							}*/
							
							
							if(ptr_s[i]->s_class<=5)
                            	ptr_s[i]->fees=500;
                        	else if(ptr_s[i]->s_class>5 && ptr_s[i]->s_class<=10)
                            	ptr_s[i]->fees=800;
                        	else
                            	ptr_s[i]->fees=1200;
							
							if(i==0)
							{
								ptr_s[i]->adm_no=201001;
							}
							else
                             ptr_s[i]->adm_no=ptr_s[i-1]->adm_no+1;
                             

							
						
							
        printf("\n\tContact number : ");
        fflush(stdin);
        scanf("%s",ptr_s[i]->contact_no);
        while(strlen(ptr_s[i]->contact_no)>10||strlen(ptr_s[i]->contact_no)<10)
        {

            printf("\tEnter a 10 digit mobile number only ! Please enter again ! ");
            printf("\n\tContact number : ");
            fflush(stdin);
            scanf("%s",ptr_s[i]->contact_no);
            
                        for(k=0;ptr_s[i]->contact_no[k]!='\0';)
                        {
                               while(strlen(ptr_s[i]->contact_no)>10||strlen(ptr_s[i]->contact_no)<10)
                        {

                            printf("\tEnter a 10 digit mobile number only ! Please enter again ! ");
                            printf("\n\tContact number : ");
                            fflush(stdin);
                            scanf("%s",&ptr_s[i]->contact_no);
                            k=0;
                        }

                            if(isalpha(ptr_s[i]->contact_no[k]))
                             {
                                 k=0;
                                        printf("\n\t**PLEASE ENTER NUMBERS ONLY. ALPHABETS ARE NOT ALLOWED**\n");
                                        printf("\n\tContact number : ");
                                        fflush(stdin);
                                        scanf("%s",&ptr_s[i]->contact_no);


                             }

                            else
                            {
                                k++;

                            }

                        }
        }
        
        				ptr_s[i]->status=0;
        
        printf("\n\n");
	
    prev_s_total=s_total;
}
    printf("\n\n********* Press any key to continue ************\n");
    getch();

}



//student display function
void s_disp(int ttl){
	int i=0,s_cls,count=1;
	int choice,tmp_admno;
	char sec;

	char *paid = "Paid";
    char *n_paid = "Not Paid";

    fflush(stdin);
	choose: //lable
    system("cls");

    if(ttl==0){
    	printf("\n***************************************************\n");
    	printf("\n\t\tNo record found\n");
    	printf("\n\n********* Press any key to continue ************\n");
    	getch();
    	return;
	}

    printf("\n********************* Select Option To Display ***************************\n\n");
    		printf("\n\tSelect your option\n\n");
    		printf("\t1. Display Class Wise\n\t2. Display By Admission no.\n\t3. Go Back\n\n");
    		fflush(stdin);
    		scanf("%d",&choice);
    		
    				while(choice>=0 || choice<0)
			                    {
			                    	if(choice>=1 && choice<=3)
			                    		break;
									else if(isalpha(choice)){
										printf("\nplease enter numerals only : 1/2/3 \n");
			                             fflush(stdin);
			                    		scanf("%d",&choice);
									}
			                    	else
			                    	{
			                    		printf("\nplease enter numerals only : 1/2/3 \n");

			                             fflush(stdin);
			                    		scanf("%d",&choice);
									}
								}

    		switch(choice){

				case 1:
						printf("Enter Class\n\n");
					    scanf("%d",&s_cls);
			    		printf("Enter Section\n\n");
			    		fflush(stdin);
			    		scanf("%c",&sec);
			    		sec=toupper(sec);
			    			for(i=0; i<ttl; i++){

							    	if(ptr_s[i]->sec == sec && ptr_s[i]->s_class == s_cls){
							    		printf("\tName        		:%s\n",ptr_s[i]->name);
							    		printf("\tAdmission no.      	:%d\n",ptr_s[i]->adm_no);
							    		printf("\tClass               \t:%d\n",ptr_s[i]->s_class);
							    		printf("\tSection			:%c\n",ptr_s[i]->sec);
							    		printf("\tGender      		:%c\n",ptr_s[i]->gender);
							    		printf("\tContact no.     	:%s\n",ptr_s[i]->contact_no);
							    		printf("\tAddress      		:%s\n",ptr_s[i]->address);
							    		printf("\tFees      		:%d\n",ptr_s[i]->fees);
							    		if(ptr_s[i]->status==0)
							    		printf("\tFees Status\t        :%s\n",n_paid);
							    		else
							    		printf("\tFees Status\t        :%s\n",paid);
							    		printf("\n***********************************************************************\n");
									}

									else
										count++;
								}

								if(count>ttl)
								{
									printf("\n\tNO RECORD FOUND\n");
									count = 1;
								}
								break;


			case 2:
					printf("\n\tEnter admission no.:\t");
					scanf("%d",&tmp_admno);

						for(i=0; i<ttl; i++){

							    	if(ptr_s[i]->adm_no == tmp_admno){
							    		printf("\tName        		:%s\n",ptr_s[i]->name);
							    		printf("\tClass               \t:%d\n",ptr_s[i]->s_class);
							    		printf("\tSection			:%c\n",ptr_s[i]->sec);
							    		printf("\tGender      		:%c\n",ptr_s[i]->gender);
							    		printf("\tContact no.     	:%s\n",ptr_s[i]->contact_no);
							    		printf("\tAddress      		:%s\n",ptr_s[i]->address);
							    		printf("\tFees      		:%d\n",ptr_s[i]->fees);
							    		if(ptr_s[i]->status==0)
							    		printf("\tFees Status\t        :%s\n",n_paid);
							    		else
							    		printf("\tFees Status\t        :%s\n",paid);
							    		printf("\n***********************************************************************\n");
							    		printf("\n\n********* Press any key to continue ************\n");
    									getch();
							    		break;
									}

									else
										count++;
								}

								if(count>ttl)
								{
									printf("\n\tWrong Admission no.\n");
							        printf("\n\n***********PRESS ANY KEY TO CONTINUE***********\n");
							        count = 1;
									getch();
									goto choose;
								}
								else
									count = 1;
								goto choose;

			case 3: return;

			default:
						printf("\n\tWrong option...");
			              printf("\n Press any key to continue");
			              getch();
							 goto choose;

			}


    printf("\n\n********* Press any key to continue ************\n");
    getch();
	goto choose;
}


//student edit function
void s_edit(int ttl){
	int i,j,tmp_id=0,k;
	int count = 1,m_op=0;

	char *paid = "Paid";
    char *n_paid = "Not Paid";

	int option;
	char tmp_name[50],tmp_section,tmp_gender,tmp_contact_no[10],tmp_address[200],cnfrm;
	int tmp_class,tmp_status;

	main:
    system("cls");

    if(ttl==0){
			printf("\n***************************************************\n");
    		printf("\n\t\tNo record found\n");
			printf("\n\n********* Press any key to continue ************\n");
    		getch();
			return;
			}

    printf("\n\tSelect option to edit\n\n");
    printf("\t1. Edit Student Details\n\t2. Change Class Wise Fees Submission Status\n\t3. Go Back\n");
    scanf("%d",&option);
				
				while(option>=0 || option<0)
			                    {
			                    	if(option>=1 && option<=3)
			                    		break;
									else if(isalpha(option)){
										printf("\nplease enter numerals only : 1/2/3 \n");
			                             fflush(stdin);
			                    		scanf("%d",&option);
									}
			                    	else
			                    	{
			                    		printf("\nplease enter numerals only : 1/2/3 \n");

			                             fflush(stdin);
			                    		scanf("%d",&option);
									}
								}
				
				
				
    switch(option){
    	case 1:
    			printf("**************************** Edit Details *********************************************\n\n");
				printf("\n\tEnter the adm no of student:\t");
				scanf("%d",&tmp_id);
				printf("\n\tEnter name of student:\t");
				fflush(stdin);
				gets(tmp_name);

				for(k=0;tmp_name[k]!='\0';)
						{
							        	if(isalpha(tmp_name[k]) || tmp_name[k]==' ')
							        		k++;

							        	else
							        	{
							        		k=0;
							        		printf("\nPlease enter alphabets only\n");
							        		fflush(stdin);
									        printf("\nName : ");
									        scanf("%s",&tmp_name);

										}
									}

									while(tmp_name[0] =='\0'){
											printf("\n\tPlease enter Name\n");
							        		fflush(stdin);
									        printf("\n\tName : ");
									        gets(tmp_name);
										}

				//iteration
				for(i=0; i<ttl; i++){

					if(ptr_s[i]->adm_no==tmp_id && strcmp(ptr_s[i]->name,tmp_name)==0){

						//enter new data
						edit: //lable
									printf("\n\t%s's Present Details\n",ptr_s[i]->name);
							    	printf("\tAdmission no.      	:%d\n",ptr_s[i]->adm_no);
							    	printf("\tClass               \t:%d\n",ptr_s[i]->s_class);
							    	printf("\tSection			:%c\n",ptr_s[i]->sec);
							    	printf("\tGender      		:%c\n",ptr_s[i]->gender);
							    	printf("\tContact no.     	:%s\n",ptr_s[i]->contact_no);
							    	printf("\tAddress      		:%s\n",ptr_s[i]->address);
							    	printf("\tFees      		:%d\n",ptr_s[i]->fees);
							    	if(ptr_s[i]->status==0)
							    	printf("\tFees Status\t        :%s\n",n_paid);
							    	else
							    	printf("\tFees Status\t        :%s\n",paid);
							    	printf("\n********************************************************\n\n");

						//enter new data

						printf("\nChoose Option to EDIT Details\n");
						printf("\t1. Name\n\t2. Class\n\t3. Section\n\t4. Gender\n\t5. Phone number\n\t6. Address\n\t7. Fees Status\n\t8. Go back\n");
						scanf("%d",&m_op);
									
							while(m_op>=0 || m_op<0)
			                    {
			                    	if(m_op>=1 && m_op<=8)
			                    		break;
									else if(isalpha(m_op)){
										printf("\nplease enter numerals only : 1/2/3/4/5/6/7/8 \n");
			                             fflush(stdin);
			                    		scanf("%d",&m_op);
									}
			                    	else
			                    	{
			                    		printf("\nplease enter numerals only : 1/2/3/4/5/6/7/8 \n");

			                             fflush(stdin);
			                    		scanf("%d",&m_op);
									}
								}
									
						switch(m_op){
							case 1:
								    fflush(stdin);
							        printf("\n\tName : ");
							        gets(tmp_name);

							         for(k=0;tmp_name[k]!='\0';)
							        {
							        	if(isalpha(tmp_name[k]) || tmp_name[k]==' ')
							        		k++;

							        	else
							        	{
							        		k=0;
							        		printf("\nPlease enter alphabets only\n");
							        		fflush(stdin);
									        printf("\nName : ");
									        scanf("%s",&tmp_name);

										}
									}

									while(tmp_name[0] =='\0'){
											printf("\n\tPlease enter Name\n");
							        		fflush(stdin);
									        printf("\n\tName : ");
									        gets(tmp_name);
										}


							        //confirmng

							        printf("\n\tConfirm the edit to this account?(y/n):\t");
									fflush(stdin);
									scanf("%c",&cnfrm);

									while(cnfrm!='y')
				                        {
				                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
				                                break;

				                            else
				                            {
				                            fflush(stdin);
				                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
				                            scanf("%c",&cnfrm);
				                            }

				                        }
									if(cnfrm=='y' || cnfrm=='Y'){
				                     	printf("\n\n\t******** Changes saved **********\n\n");
				                     	strcpy(ptr_s[i]->name,tmp_name);
				                     }
				                    else
				                    	goto edit;
							    goto edit;

							case 2:
									printf("\n\tClass : ");
								    scanf("%d",&tmp_class);

								    while(tmp_class>=0 || tmp_class<0 )
							        {
							        	if(tmp_class >=1 && tmp_class<=12)
							        	{
							        		break;
										}

										else
										{
											printf("\nPLEASE ENTER CLASS IN BETWEEN 1 TO 12\n");
											printf("\nClass: ");
									        fflush(stdin);
									        scanf("%d",&tmp_class);

										}
									}

							        //confirmng

							        printf("\n\tConfirm the edit to this account?(y/n):\t");
									fflush(stdin);
									scanf("%c",&cnfrm);

									while(cnfrm!='y')
				                        {
				                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
				                                break;

				                            else
				                            {
				                            fflush(stdin);
				                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
				                            scanf("%c",&cnfrm);
				                            }

				                        }
									if(cnfrm=='y' || cnfrm=='Y'){
				                     	printf("\n\n\t******** Changes saved **********\n\n");
				                     	ptr_s[i]->s_class=tmp_class;
				                     	if(ptr_s[i]->s_class<=5)
			                            ptr_s[i]->fees=500;
			                        else if(ptr_s[i]->s_class>5 && ptr_s[i]->s_class<=10)
			                            ptr_s[i]->fees=800;
			                        else
			                            ptr_s[i]->fees=1200;
				                     }
				                    else
				                    	goto edit;
							    goto edit;

						    case 3:
								    fflush(stdin);
							        printf("\n\tSection : ");
							        scanf("%c",&tmp_section);
							        tmp_section=toupper(tmp_section);

							         while(isalpha(tmp_section)==0 || isalpha(tmp_section)!=0 )
							        {
							        	if(tmp_section<'A' || tmp_section>'D'){
							        		printf("\n\t** Please enter Sections A/B/C/D only**\n");
							        		printf("\n\tSection: ");
									        fflush(stdin);
									        scanf("%c",&tmp_section);

										}

							        	else if(isalpha(tmp_section)==0)
							        	{
								            printf("\n\t** PLEASE ENTER SECTION (ALPHABET ONLY) **\n");
								            scanf("%c",&tmp_section);
								        }

								        else
								        	break;
							        }

							        //confirmng

							        printf("\n\tConfirm the edit to this account?(y/n):\t");
									fflush(stdin);
									scanf("%c",&cnfrm);

									while(cnfrm!='y')
				                        {
				                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
				                                break;

				                            else
				                            {
				                            fflush(stdin);
				                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
				                            scanf("%c",&cnfrm);
				                            }

				                        }
									if(cnfrm=='y' || cnfrm=='Y'){
				                     	printf("\n\n\t******** Changes saved **********\n\n");
				                     	ptr_s[i]->sec=tmp_section;
				                     }
				                    else
				                    	goto edit;
							    goto edit;
						case 4:
								    fflush(stdin);
							        printf("\n\tGender : ");
							        scanf("%c",&tmp_gender);
							        	while(tmp_gender != 'm')
									        {
									            if(tmp_gender=='M' ||tmp_gender=='f' || tmp_gender=='F')
									                break;

									            else
									            {
									            fflush(stdin);
									            printf("\n\t**PLEASE ENTER F/f FOR FEMALE AND M/f FOR MALE ** \n");
									            scanf("%c",&tmp_gender);
									            }

									        }

							        //confirmng

							        printf("\n\tConfirm the edit to this account?(y/n):\t");
									fflush(stdin);
									scanf("%c",&cnfrm);

									while(cnfrm!='y')
				                        {
				                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
				                                break;

				                            else
				                            {
				                            fflush(stdin);
				                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
				                            scanf("%c",&cnfrm);
				                            }

				                        }
									if(cnfrm=='y' || cnfrm=='Y'){
				                     	printf("\n\n\t******** Changes saved **********\n\n");
				                     	ptr_s[i]->gender=tmp_gender;
				                     }
				                    else
				                    	goto edit;
							    goto edit;


							case 5:
									printf("\n\tContact number : ");
							        fflush(stdin);
							        scanf("%s",tmp_contact_no);
							        int k;
			                        for(k=0;tmp_contact_no[k]!='\0';)
			                        {
			                               while(strlen(tmp_contact_no)>10||strlen(tmp_contact_no)<10)
			                        {

			                            printf("\n\tEnter a 10 digit mobile number only ! Please enter again ! ");
			                            printf("\n\tContact number : ");
			                            fflush(stdin);
			                            scanf("%s",tmp_contact_no);
			                            k=0;
			                        }

			                            if(isalpha(tmp_contact_no[k]))
			                             {
			                                 k=0;
			                                        printf("\n\t**PLEASE ENTER NUMBERS ONLY. ALPHABETS ARE NOT ALLOWED**\n");
			                                        printf("\n\tContact number : ");
			                                        fflush(stdin);
			                                        scanf("%s",tmp_contact_no);


			                             }

			                            else
			                            {
			                                k++;

			                            }

			                        }

			                          //confirmng

							        printf("\n\tConfirm the edit to this account?(y/n):\t");
									fflush(stdin);
									scanf("%c",&cnfrm);

									while(cnfrm!='y')
				                        {
				                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
				                                break;

				                            else
				                            {
				                            fflush(stdin);
				                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
				                            scanf("%c",&cnfrm);
				                            }

				                        }
									if(cnfrm=='y' || cnfrm=='Y'){
				                     	printf("\n\n\t******** Changes saved **********\n\n");
				                     	strcpy(ptr_s[i]->contact_no,tmp_contact_no);
				                     }
				                    else
				                    	goto edit;
							    goto edit;

							case 6:
									fflush(stdin);
							        printf("\n\tAddress : ");
							        scanf("%s",&tmp_address);
							         //confirmng

							        printf("\n\tConfirm the edit to this account?(y/n):\t");
									fflush(stdin);
									scanf("%c",&cnfrm);

									while(cnfrm!='y')
				                        {
				                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
				                                break;

				                            else
				                            {
				                            fflush(stdin);
				                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
				                            scanf("%c",&cnfrm);
				                            }

				                        }
									if(cnfrm=='y' || cnfrm=='Y'){
				                     	printf("\n\n\t******** Changes saved **********\n\n");
				                     	strcpy(ptr_s[i]->address,tmp_address);
				                     }
				                    else
				                    	goto edit;
							    goto edit;


							case 7:
									printf("\n\tFees status (1=paid and 0=not paid):\t");
									scanf("%d",&tmp_status);
									while(tmp_status!=0)
			                        {
			                            if(tmp_status==1)
			                                break;
			                            else
			                            {
			                                printf("\n\t**0-NOT PAID , 1-PAID**\n");
			                                scanf("%d",&tmp_status);
			                            }
			                        }

			                        //confirmng

							        printf("\n\tConfirm the edit to this account?(y/n):\t");
									fflush(stdin);
									scanf("%c",&cnfrm);

									while(cnfrm!='y')
				                        {
				                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
				                                break;

				                            else
				                            {
				                            fflush(stdin);
				                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
				                            scanf("%c",&cnfrm);
				                            }

				                        }
									if(cnfrm=='y' || cnfrm=='Y'){
				                     	printf("\n\n\t******** Changes saved **********\n\n");
				                     	ptr_s[i]->status=tmp_status;
				                     }
				                    else
				                    	goto edit;
							    goto edit;

							    case 8 : return;

							default: printf("\n\tPlease enter valid option...\n");
									sleep(4);
									 goto edit;

						}



					}
					else
						count++;
				}

				if(count>ttl){
					printf("\tWrong Id no.\n");
					printf("\n\n********* Press any key to continue ************\n");
                	getch();
				}

    		goto main;


    	case 2:
    			printf("\n\tEnter Class and Section\n");
    			printf("\n\tClass:\t");
    			scanf("%d",&tmp_class);
    			fflush(stdin);
    			printf("\n\tSection:\t");
    			scanf("%c",&tmp_section);
				tmp_section = toupper(tmp_section);
    			int s_count=0;

    			for(i=0; i<ttl; i++){
					if(ptr_s[i]->s_class==tmp_class && ptr_s[i]->sec==tmp_section){
    					ptr_s[i]->status = 1;
    					s_count++;
					}
				}
				if(s_count==0){
					printf("\n\tNo student detail available\n");
					break;
				}
				else{
				   printf("\n\t\t%d students of class %d section %c fees status has been changed\n",s_count,tmp_class,tmp_section);
				   printf("\n\n********* Press any key to continue ************\n");
				    getch();
				    goto main;
				}

    		goto main;


    	case 3: return;


    	default:
    			printf("\nPlease enter valid option...\n");
				printf("\n\n********* Press any key to continue ************\n");
                getch();
				goto main;

	}




	printf("\n\n********* Press any key to continue ************\n");
    getch();
    goto main;
}


//student delete function
void s_data_delete(int ttl){

        int i,j,k;

       	int tmp_adm_no;
       	int pos;
       	char tmp_name[50];
	   	char cnfrm;

	   	char *paid = "Paid";
       	char *n_paid = "Not Paid";

		system("cls");

			if(ttl==0){
				printf("\n***************************************************\n");
    			printf("\n\t\tNo record found\n");
				printf("\n\n********* Press any key to continue ************\n");
    			getch();
				return;
			}
		else{
        printf("\t****************************** DELETE THE DATA ******************************\n");
		printf("\n\tEnter student's name:\t");
		fflush(stdin);
		gets(tmp_name);
		for(k=0;tmp_name[k]!='\0';)
							        {
							        	if(isalpha(tmp_name[k]) || tmp_name[k]==' ')
							        		k++;

							        	else
							        	{
							        		k=0;
							        		printf("\nPlease enter alphabets only\n");
							        		fflush(stdin);
									        printf("\nName : ");
									        scanf("%s",&tmp_name);

										}
									}

									while(tmp_name[0] =='\0'){
											printf("\n\tPlease enter Name\n");
							        		fflush(stdin);
									        printf("\n\tName : ");
									        gets(tmp_name);
										}
		printf("\n\n\tEnter adm no. of student :-");
        scanf("%d",&tmp_adm_no);

         for(i=0;i<ttl;i++)
             {
                if(tmp_adm_no==ptr_s[i]->adm_no && stricmp(ptr_s[i]->name,tmp_name)==0)

                  {
                     pos=i;

						    printf("\tName        		:%s\n",ptr_s[i]->name);
				    		printf("\tAdmission no.      	:%d\n",ptr_s[i]->adm_no);
				    		printf("\tClass               \t:%d\n",ptr_s[i]->s_class);
				    		printf("\tSection			:%c\n",ptr_s[i]->sec);
				    		printf("\tGender      		:%c\n",ptr_s[i]->gender);
				    		printf("\tContact no.     	:%s\n",ptr_s[i]->contact_no);
				    		printf("\tAddress      		:%s\n",ptr_s[i]->address);
				    		printf("\tFees      		:%d\n",ptr_s[i]->fees);
				    		printf("\tFees Status\t        :%d\n",ptr_s[i]->status);
				    		printf("\n***********************************************************************\n");


					printf("\n\tAre you sure you want to delete this account?(y/n):\t");
					fflush(stdin);
					scanf("%c",&cnfrm);

					while(cnfrm!='y')
                        {
                            if(cnfrm=='n' || cnfrm=='N' || cnfrm=='Y' )
                                break;

                            else
                            {
                            fflush(stdin);
                            printf("\n\t****** PLEASE ENTER y/Y/N/n ****** \n");
                            scanf("%c",&cnfrm);
                            }

                        }
					if(cnfrm=='y' || cnfrm=='Y')
                     	break;
                    else
                    	return;
                  }


             }

             if(i==ttl){
             	printf("\n\t\tError\n");
             	printf("\t\tWrong ID no.\n");
			 }

			 else if(ttl==1)
             {
                 *ptr_s=0;
                 s_total=s_total-1;
                 prev_s_total=s_total;
                 printf("\n\t************ ACCOUNT DELETED **************\n");
             }
             else if(pos==s_total-1)
             {
             	free(ptr_s[pos]);
             	ptr_s[pos]=NULL;
             	s_total--;
             	prev_s_total=s_total;
             	printf("\n\t************ ACCOUNT DELETED **************\n");
			 }

             else
             {

             	for(i=pos;i<s_total;i++)
				 {
				 	ptr_s[i]=ptr_s[i+1];
				 }


             	ptr_s[s_total-1]=NULL;
				free(ptr_s[s_total-1]);
				s_total=s_total-1;
			    prev_s_total=s_total;

				printf("\n\t************ ACCOUNT DELETED **************\n");
			 }

    printf("\n\n********* Press any key to continue ************\n");
    getch();
    return;

}
}

