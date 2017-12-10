/****************************************
* Project-2-Array-Manipulation
* It is a project which :
*  >>asks user if he wants to use array manipulation prog
*  >>reads req array elements from user
*  >>asks user to choose one of those operations :
*     -get max element
*	  -get min element
*	  -sort array
*	  -search an element in array
*  >>in case of getting maximum a new array will be created started with max then increased by one to the end
*  >>asks user to choose sorting algorithm:
*      -selection sort
*  	   -bubble sort
*  >>asks user to choose searching algorithm:
*      -linear search
*	   -binary search
*********************************************/

/*includes*/
#include<stdio.h>
#include<conio.h>
#include<string.h>

/*functions prototyping*/
int get_max(int[],int );
void get_min(int[],int );
void selection_sort(int[] ,int );
void bubble_sort(int[] , int );
void linear_search(int[] ,int ,int );
void binary_search(int[] ,int ,int );

/*main code*/
void main()
{
	char prog_on;          /*to check if user wants to ron array prog*/
	char choise;           /*to stor req operation from user*/
	char continue_search;  /*to check if user wants to repeat searching*/
	char sort_algorithm;   /*to store user's choise for sorting algorithm*/
	char search_algorithm; /*to store user's choise for search algorithm*/
	int array[4];          /*to store input array*/
	int search_element;    /*to store the input element to be searched*/
	int i;                 /*counter*/
	int max;
	
	/*welcome messages*/
	printf("\n********Welcome to manipulation array prog*********\n");
	printf("Do you want to use array prog??");
	
	/*read answer from user*/
	prog_on=getche();
	
	/*while answer=y do the following*/
	while(prog_on=='y')    
	{
		printf("\nEnter 4 array elements:\n");
		/*scan array elements from user*/
		for(i=0;i<4;i++)
		{
			scanf("%d",&array[i]);
		}
		printf("\nfor getting max press 'x'");
		printf("\nfor getting min press 'i'");
		printf("\nfor sorting array press 'r'");
		printf("\nfor searching an element press 's'  \n  ");
		
		/*read req operation from user*/
		choise=getche();
		
		switch(choise)
		{
			case 'x':
			max=get_max(array,4);     /*call get max fn*/
			
			/*fill the array with elements starts from max increasing by 1 to the end*/
			for(i=0;i<4;i++)
			{
				array[i]=max;
				max++;
			}
			/*display the updated array*/
			printf("\nnew array is: ");
			for(i=0;i<4;i++)
			{
				printf("\n%d",array[i]);
			}
			break;
			
			case 'i':
			get_min(array,4);     /*call get min fn*/
			break;
			
			case 'r':
			printf("\nfor selection sort algorithm press 's'");
			printf("\nfor bubble sort algorithm press 'b'");
			sort_algorithm=getche();  /*read user answer for asking about algorithm*/
			if(sort_algorithm=='s')
			{
				selection_sort(array,4);   /*call  selection sort fn*/
			}
			else if(sort_algorithm=='b')
			{
				bubble_sort(array,4);      /*call bubble sort fn*/
			}     
            else
			{
				printf("\nwrong answer");
			}				
			break;
			
			case 's':
			selection_sort(array,4);
			do
			{
                printf("\nEnter element to be searched:  ");
              	scanf("%d",&search_element);                 /*reads req element to be searched*/

				printf("\nfor linear search press 'l'");
    			printf("\nfor binary search algorithm press 'b'");
	    		search_algorithm=getche();                   /*read user answer for asking about algorithm*/
	    		if(search_algorithm=='l')
	    		{
	    			linear_search(array,4,search_element);   /*call  linear search fn*/
	    		}
	    		else if(search_algorithm=='b')
	    		{
	    			binary_search(array,4,search_element);    /*call binary search fn*/
		    	}     
                else
	    		{
    				printf("\nwrong answer");
	    		}				
				printf("\nwould you like to search another element?? ");
				continue_search=getche();   /*read user answer*/
			}
			while(continue_search=='y');    /*repeat searching in case of answer yes*/
			break;
			default:
			printf("\nwrong choise");
		}
		printf("\nDo you want to continue array program??: ");
		prog_on=getche();
	}
}
/***************************************************
* functions definitions
****************************************************/

/*function takes array and its size and displays the maximum of array elements*/
int get_max(int array[],int size)
{
	int max=array[0];      /*to store max value and initialized by first element in array*/
	int i;                 /*counter*/
	for(i=0;i<size;i++)
	{
		if(array[i]>max)   /*compare each element with max value*/
		{
			max=array[i];  /*update max value with this element if it is more than max*/
		}
	}
	printf("\n\n maximum is: %d\n",max);  /*display final result*/
	return max;
}

/*function takes array and its size and displays the minimum of array elements*/
void get_min(int array[],int size)
{
	int min=array[0];       /*to store min value and initialized by first element in array*/
	int i;                  /*counter*/
	for(i=0;i<size;i++)
	{
		if(array[i]<min)    /*compare each element with min value*/
		{
			min=array[i];   /*update min value with this element if it is less than min*/
		}
	}
	printf("\n\n minimum is: %d\n",min);  /*display final result*/
}

/***********************
* function takes array and its size 
* sorts it in ascending order then displays it 
* using selection sort algorithm
**************************/
void selection_sort(int array[],int size)
{
	int i;                         /*counter*/
	int j;                         /*counter*/
	int temp;                      /*temporary variable for swapping*/
	for(i=0; i<size-1; i++)        /*for loop passes on each element except thelast one*/
	{
		for(j=i+1; j<size; j++)    /*loop passes on each element starting from element after current i element */
		{
			if(array[j]<array[i])  /*compare all j elements after i with current i element*/ 
			{
				temp=array[i];     /*swap when finding lower element than current*/
				array[i]=array[j]; 
				array[j]=temp;
			}
		}
	}
	/*print new sorted array*/
	printf("\nsorted array is:");
	for(i=0;i<size;i++)
	{
		printf("\n%d",array[i]);
	}
}

/***********************
* function takes array and its size 
* sorts it in ascending order then displays it 
* using bubble sort algorithm
**************************/
void bubble_sort(int array[], int size)
{
	int i;                            /*counter*/
	int j;                            /*counter*/
	int temp;                         /*for swapping*/
	for(j=0;j<size-2;j++)             /*loop for repeating bubbling the max elements*/
	{
	    for(i=0;i<size-1;i++)         /*loop for bubbling the max element to the end */
	    {
		    if(array[i]>array[i+1])   /*compare each element with its adjacent*/
		    {
               /*swap 2 elements in case that current element is more than adjacent*/		  
			   temp=array[i];         
			   array[i]=array[i+1];
			   array[i+1]=temp;
		    } 
	    }		
	}
	/*print new sorted array*/
	printf("\nsorted array is:");
	for(i=0;i<size;i++)
	{
		printf("\n%d",array[i]);
	}
}
/****************************
* It is a function which takes a specific element 
* then search it in a given array
* then returns the index of this element
* using linear search   
*********************************/
void linear_search(int array[],int size,int element)
{
	int i;                                      /*counter*/
	int flag;                                   /*to be set when element exists*/
	for(i=0; i<size; i++)                       /*loop on all elements of array*/
	{
		if(array[i]==element)                   /*compare each array element with req one*/
		{
			printf("\n element %d is at index %d ",element,i); /*display index of searched element*/
			flag=1;                              /*set flag when element is found*/
		}
	}
	if(flag!=1)                                  /*after loop is done ,if flag is not set ,then element is not found*/ 
	{
		printf("\nelement doesn't exist");
	}
}

/****************************
* It is a function which takes a specific element 
* then search it in a given array
* then returns the index of this element
* using binary search   
*********************************/
void binary_search(int array[],int size,int element)
{
	int start=0;
	int end=size-1;
	int mid;
	int flag=0;                         /*to be set when element exists*/

	while(start<=end)                   /*loop untill start reaches end*/
	{
	    mid=(start+end)/2;              /*calculate the middle element index*/
	    if (array[mid]==element)        /*compare the middle element with req one*/
	    {
	    	printf("\n element %d is at index %d ",element,mid);
	    	flag=1;                      /*set flag when index of searched element is found*/
		    break;                       /*then break the loop */
	    }
    	else if(element<array[mid])
    	{
    		end=mid-1;                    /*go to left of the middle element*/
    	}
		else
		{
			start=mid+1;                  /*go to the right of the middle element*/ 
		}
	}
	if(flag!=1)                           /*after loop is done ,if flag is not set ,then element is not found*/ 
	{
		printf("\nelement doesn't exist");
	}
}
