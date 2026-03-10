/******************************************** *
Student One (Donia Khamis + 212794630)
Student Two (Mohammad Diab + 212720841)
Assignment number:4
Exercise number:
********************************************/
#include <stdio.h>
#include <stdlib.h>
#define IMPLEMENT_ME -1

/*1*/
int checkIfPalindrome(int k, char str[], int n)
{
    if(k==0)/*the final iteration*/
        return 1;
    if(str[k-1]==str[n-k])
        return checkIfPalindrome(k-1,str,n);/*continue checking the rest of the substring*/
    /*the substring isn't a palindrome*/
    return IMPLEMENT_ME;
}

/*2*/
/*this function prints and calculate the dividers of the variable 'number' given from the shell function*/
void divCore(int num,int div)
{
    if(num<=0||div>num)
    {
        printf("\n");
        return;
    }
    if(num%div==0)
        printf("%d, ",div);
    divCore(num,div+1);
    return;
}
void dividorsOf(int number)
{
    int divid=1;
    divCore(number,divid);
    return;
}

/*3*/
/*this function swaps k chars in a string according to the question's request*/
void reverseString(char str[],int start,int end)
{
    char save;
    if(start>=end)/*stopping point*/
        {
            printf("%c",str[0]);/*printing current first char*/
            return;
        }
    /*swapping between k and 0*/
    save=str[start];
    str[start]=str[end];
    str[end]=save;
    /*recursion*/
    reverseString(str,++start,--end);
}
void manyKReverses(int k, char str[], int n)
{
    if(n<1) /*the main function doesn't protect this function from a wrong value of (n)*/
        return;
    if(n < k)/*stopping point*/
        {
            printf("%s\n",str);/*printing the rest of the string starts a new line*/
            return;
        }
    reverseString(str,0,k-1);/*calling other function to replace the characters accordingly*/
    manyKReverses(k,str+1,n-1);/*recursion*/
    return;
}

/*4*/
/*this function checks according to the term of the question*/
int checkZag(int arr[],int arrsize,int i)
{
    if(i==0)/*first cell*/
        {
            if(arrsize==1)/*case of one cell*/
                return 1;
            else /*continue to check the rest of the array*/
                return checkZag(arr,arrsize,i+1);
        }
    if(i == (arrsize-1))/*last cell*/
        {
            if(i%2==0)/*even index*/
            {
                if(arr[i]<=arr[i-1])
                    return 1;
                else
                    return 0;
            }
            else/*odd index*/
            {
                if(arr[i]>=arr[i-1])
                    return 1;
                else
                    return 0;
            }
        }
    if(i%2==0)/*even index*/
    {
        if(arr[i]<=arr[i-1] && arr[i]<=arr[i+1])
            return checkZag(arr,arrsize,i+1);
        else
            return 0;
    }
    else    /*odd index*/
    {
        if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1])
            return checkZag(arr,arrsize,i+1);
        else
            return 0;
    }
}
int isZigZag(int arr[], int _size)
{
    return checkZag(arr,_size,0);
}
/*5*/
/*this function searches for the minimum value of a current section of the array and returns the index of it*/
int indexMin(int arr[], int min, int i, int size)
{
    if(i == size)/*stopping sign*/
        return min;
    if(arr[i]<arr[min])/*found a smaller value than the current one saved in min*/
        min=i;
    /*recursion call*/
    return indexMin(arr,min,i+1,size);
}
/*this function searches for the maximum value of a current section of the array and returns the index to its place*/
int indexMax(int arr[], int max, int i, int size)
{
    if(i == size)/*stopping sign*/
        return max;
    if(arr[i]>arr[max])/*found a smaller value than the current one saved in min*/
        max=i;
    /*recursion call*/
    return indexMax(arr,max,i+1,size);
}

/*this function organize the given array to be a special array then at the end, prints the array*/
void printAsZigzag(int arr[], int arrsize)
{
    int min,max,current0,current1;
    if(arrsize == 0)/*stopping sign*/
        {
            printf("\n");
            return;
        }
    if(arrsize == 1)/*stopping sign - case number of cells is odd*/
        {
            printf("%d, \n",arr[0]);
            return;
        }
    /*finding the index of the smallest value of the current section of the array*/
    min = indexMin(arr,0,0,arrsize);
    /*swapping*/
    /*1st index*/
    current0=arr[0];
    arr[0]=arr[min];
    arr[min]=current0;
    /*finding the index of the largest value of the current section of the array*/
    max = indexMax(arr,0,0,arrsize);
    /*swapping*/
    /*2nd index*/
    current1=arr[1];
    arr[1]=arr[max];
    arr[max]=current1;
    printf("%d, %d, ", arr[0], arr[1]);/*print current cells*/
    /*recursion call*/
    printAsZigzag(arr+2,arrsize-2);
    return;
}

int main()
{
    int res, iszig;
    int k=-1, n=-1, number=-1, arrsize=-1, i;
    char c;
    char* str;
    int* arr;
    int question;
    printf("Which function should I test for you? ");
    scanf("%d", &question);

    printf("Before proceeding to check the function, please enter the following information:\n");
    printf("[[Note: Only relevant information for the specific function you choose to test will be used]].\n");
    printf("[[For example, if you chose to test function 1, only parameters k, str and n will be checked. all other inputs will be ignored]].\n");
    printf("Enter k:\n");
    scanf("%d", &k);
    printf("Enter string size:\n");
    scanf("%d", &n);
    printf("Enter string:\n");
    str = (char*)malloc((n + 1) * sizeof(char));
    /* read string */
    c = '#';
    i = 0;
    do
    {
        scanf(" %c", &c);
        if (c == '#') c = '\0';
        str[i] = c;
        i++;
    } while(c != '\0');

    printf("Enter number:\n");
    scanf("%d", &number);
    printf("Enter zigzag array size:\n");
    scanf("%d", &arrsize);
    arr = (int*)malloc(arrsize * sizeof(int));
    for(i = 0; i < arrsize; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        switch(question)
        {
        case 1:
            if (n < 2 || k < 0)
                printf("Skipping.\n");
            else
            {
                res = checkIfPalindrome(k, str, n);
                if (res == 1) printf("Yes, it is a palindrome.\n");
                else printf("No, it is not a palindrome.\n");
            }
            break;
        case 2:
            dividorsOf(number);
            break;
        case 3:
            if (n < 1)
                printf("Skipping.\n");
            manyKReverses(k, str, n);
            break;
        case 4:
            if (arrsize < 0 || arrsize > 1000)
            {
                printf("Skipping.\n");
                break;
            }
            iszig = isZigZag(arr, arrsize);
            if (iszig) printf("zigzag array!\n");
            else printf("NOT zigzag array!\n");
            break;
        case 5:
            if (arrsize < 0 || arrsize > 1000)
            {
                printf("Skipping.\n");
                break;
            }
            printAsZigzag(arr, arrsize);
            break;
        default:
            printf("No choice.\n");
        }
        printf("Which function to check next?");
        scanf("%d", &question);
    } while(question != -1);

    return 0;
}
