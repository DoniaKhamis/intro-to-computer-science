/******************************************** *
Student One (Donia Khamis + 212794630)
Student Two (Mohammad Diab + 212720841)
Assignment number:3
Exercise number:
********************************************/
#include <stdio.h>
#define MAX 100

/* Function decelerations here */
void printArr(int a[], int s, char name[]);
void printPoly(int a[], int s, char name[]);
/** Functions you have to implement **/
int getArray(int*,int,int);
void polynomialCalc(int,int,int*,int*);
void minPlusConv(int,int,int*,int*,int*);
int mod(int,int);
int power(int,int);

int main()
{
    int m[MAX]= {0};/*the array that has the coefficients*/
    int n[MAX]= {0};/*the array of the second exercise*/
    int a[MAX]= {0};
    int d, p;

    /*Get Input*/
    printf("Please enter degree of the polynomial:\n");
    if(scanf("%d", &d)<1) return 1;
    printf("Please enter p:\n");
    if(scanf("%d", &p)<1) return 1;
    printf("Please enter the coefficients of your polynomial:\n");
    if(!getArray(m,d,p)) return 1;
    printf("The given polynomial is:\n");
    printPoly(m,d+1,"m");

    /*Calculate Polynomial*/
    polynomialCalc(p,d,n,m);
    printf("\nThe result of m(x) on all 0<=x<p=%d is:\n",p);
    printArr(n,p,"n");

    /*Calculate Min Plus Convolution*/
    minPlusConv(p,d+1,n,m,a);
    printf("\nThe Minimum Plus Convolution of m and n is:\n");
    printArr(a,((d+1>p)?d+1:p),"a");

    return 0;
}

/*section 1*/
int getArray(int arr[],int len,int mod)
{
    int i;
    if(len<0 || mod<=0)/*case of invalid degree or modulu*/
    {
        printf("invalid input.\n");
        return 0;
    }
    /*receiving the coefficients into the cells*/
    for(i=0;i<=len;i++)
    {
        if(scanf("%d", &arr[i])<1)
            return 0;
    }
    return 1;/*success*/
}

/*section 2*/
void polynomialCalc(int p, int d, int n[], int m[])
{
    int i,k,tmp;
    for(k=0;k<p;k++)/*values from 0 to p-1*/
    {
        tmp = 0;/*saving the result of activating the polynomial function on current value*/
        for(i=0;i<=d;i++)/*calculating the result*/
        {
            tmp += m[i] * power(k,i);
        }
        n[k] = mod(tmp,p);/*updating the value into the result array*/
    }
}
/*assisting function 1 - calculates power*/
int power(int num,int pow)
{
    int i,multi=1;
    for(i=0;i<pow;i++)/*calculate num to the pow power*/
    {
        multi*=num;
    }
    return multi;
}
/*assisting function 2 - calculates modulo*/
int mod(int num ,int mod)
{
    if(num>= 0)/*case positive*/
        return (num%mod);
    return (num%mod)+mod;/*case negative*/
}

/*section 3*/
void minPlusConv(int p, int d, int n[], int m[],int a[])
{
    int tmp,min,i,j,k, r =(p>d)? p:d;/*the value of r as declared*/
    for (k=0;k<r;k++)/*putting values in the first r cells of the array*/
    {
        min = p-1;/*starter value - the maximum value possible*/
        for(i=0;i<p;i++)
        {
            for(j=0;j<d;j++)
            {
                if(i+j==k)
                {
                    tmp = mod(n[i]+m[j],p);/*calculate the current value of the indexes*/
                    min = tmp<min? tmp:min;/*saving the minimum value of the two*/
                }
            }
        }
        a[k] = min; /*putting final minimum result into correct place*/
    }
}

/** Don't touch!! - print functions **/
void printArr(int a[], int s, char name[])
{
    int i;
    printf("%s=[", name);
    for(i=0; i<s-1; i++)
    {

        printf("%d,", a[i]);
    }
    printf("%d]\n", a[i]);
}

void printPoly(int a[], int s, char name[])
{
    int i=0;
    if(s<1) return;
    printf("%s(x)=", name);
    printf("%d", a[i]);
    for(i=1; i<s; i++)
    {
        if(a[i]<0)
            printf("+(%d)x^%d", a[i], i);
        else
            printf("+%dx^%d", a[i], i);
    }
    printf("\n");
}
