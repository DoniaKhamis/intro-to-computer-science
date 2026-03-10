/******************************************** *
Student One (Donia Khamis + 212794630)
Student Two (Maya atwan + 314813494)
Assignment number:7
********************************************/
#include <stdio.h>
#include <stdlib.h>

/*Node Declaration*/
typedef struct cellNode{
    int cell;
    struct cellNode* next;
} Node;

/*Matrix Declaration*/
typedef struct {
    int numRows;
    int numColumns;
    Node** rows; /*a pointer; used as a 1D array of size numRows.
                    rows[i]= the list which describes row i.*/
} Matrix;

/*Functions Declaration*/
/*function1*/
int firstOcuurence(int*,int,int);
/*function2*/
void MultiplyMatrices(Matrix*,Matrix*,Matrix*);
int colRow(Node*,Node**,int,int);
/*function3*/
void cpyM(Matrix*,Matrix*);
void fibFiller(Matrix*);
int matFib(int);
/*common helper funciton*/
void buildMatt(Matrix*);
void freeMatt(Matrix*);
/*main*/
void printMatt(Node**,int,int);

/*MAIN FUNCTION*/
int main()
{
    /*variables for case 1*/
    int choice, num,arrLen,*sortedArr,i,func1;
    /*variables for case 2*/
    int n,m,k,j,val;
    Node *pt;
    Matrix *A,*B,*C;
    /*variables for case 3*/
    int fibIndex, ansr=0;
    /*ask user which case it wants*/
    printf("Please choose function (1 or 2 or 3): ");
    if(scanf("%d", &choice)<1) return 1;
    /*using switch to differ each case of input*/
    switch (choice)
    {
    case 1:
        {
            printf("Enter num: ");
            if(scanf("%d", &num)<1) return 1;
            printf("Enter n: ");
            if(scanf("%d", &arrLen)<1) return 1;
            /*create the array at the given length*/
            if((sortedArr = (int*)malloc(arrLen * sizeof(int)))==NULL)
                return 1;
            /*receive and put values in the new array*/
            for(i=0; i<arrLen; i++)
            {
                if(scanf("%d", &(sortedArr[i]))<1) return 1;
            }
            func1 = firstOcuurence(sortedArr,arrLen,num);
            if(func1 == -1)
                printf("Does not exist.\n");
            else
                printf("Found at: %d.\n", func1);
            /*freeing the array used*/
            free(sortedArr);
            break;
        }
    case 2:
        {
            printf("Please enter n: ");
            if(scanf("%d", &n)<1) return 1;
            printf("Please enter m: ");
            if(scanf("%d", &m)<1) return 1;
            printf("Please enter k: ");
            if(scanf("%d", &k)<1) return 1;
            /*build both matrices*/
            A = (Matrix*)malloc(sizeof(Matrix));
            A->numRows=n;
            A->numColumns=m;
            buildMatt(A);
            B = (Matrix*)malloc(sizeof(Matrix));
            B->numRows=m;
            B->numColumns=k;
            buildMatt(B);
            /*now we receive and put the values of A in it*/
            printf("Please insert values for matrix A:\n");
            for(i=0; i<A->numRows; i++)
            {
                pt=A->rows[i];
                printf("Enter row %d data\n",i);
                for(j=0; j<A->numColumns; j++)
                {
                    if(scanf("%d", &val)<1) return 1;
                    pt->cell=val;
                    pt=pt->next;
                }
            }
            /*now we receive and put the values of B in it*/
            printf("Please insert values for matrix B:\n");
            for(i=0; i< B->numRows; i++)
            {
                printf("Enter row %d data\n",i);
                pt=B->rows[i];
                for(j=0; j< B->numColumns; j++)
                {
                    if(scanf("%d", &val)<1) return 1;
                    pt->cell=val;
                    pt=pt->next;
                }
            }
            /*now we print the matrices*/
            printf("Matrix A:\n");
            printMatt(A->rows,A->numRows,A->numColumns);
            printf("Matrix B:\n");
            printMatt(B->rows,B->numRows,B->numColumns);
            /*onto printing the matrix A*B*/
            /*first we create the matrix C*/
            C = (Matrix*)malloc(sizeof(Matrix));
            C->numRows=n;
            C->numColumns=k;
            buildMatt(C);
            /*then we'll apply the function 3 created*/
            MultiplyMatrices(A,B,C);
            /*now we print the final C*/
            printf("Matrix C:\n");
            printMatt(C->rows,C->numRows,C->numColumns);
            /*since we built the matrices we have to free them*/
            /*first, we free the matrix inside the struct*/
            freeMatt(A);
            freeMatt(B);
            freeMatt(C);
            break;
        }
    case 3:
        {
            printf("Please enter fib index:\n");
            if(scanf("%d", &fibIndex)<1) return 1;
            /*using the function 3 we created, we calculate the Fibonacci index*/
            ansr = matFib(fibIndex);
            printf("The fib value is: %d", ansr);
            break;
        }
    }
    return 0;
}
/*HELPER FUNCTIONS FOR MAIN*/
/*this function prints a given matrix by the guides in the question*/
void printMatt(Node **A, int rows, int cols)
{
    int i;
    Node *ptr;
    for(i=0;i<rows;i++)
    {
        ptr=A[i];
        printf("[%d",(ptr->cell));
        ptr=ptr->next;
        while(ptr->next != NULL && ptr != NULL)
        {
            printf(", %d",(ptr->cell));
            ptr=ptr->next;
        }
        printf(", %d]\n",ptr->cell);
    }
}
/*FUNCTION 1*/
/*returns the index of the first appearance of the number num in the array*/
int firstOcuurence(int *arr, int n, int num)
{
    int low=0, high=n-1, mid;
    /*using Binary search*/
    while(low<=high)
    {
        mid=(low+high)/2;
        if((arr[mid]==num && mid==0) || (arr[mid]==num && num>arr[mid-1]))/*found the right index*/
            return mid;
        if(arr[mid]>=num)
            high=mid-1;
        else
            low=mid+1;
    }
    /*case: num isn't in the array*/
    return -1;
}

/*FUNCTION 2*/
/*calculate the multiplication of the Matrices A and B and puts the results in Matrix C*/
void MultiplyMatrices(Matrix *A, Matrix *B, Matrix *C)
{
    int i,j,val;
    Node* ptr;
    for(i=0; i< C->numRows;  i++)
    {
        ptr = C->rows[i];
        for(j=0; j<C->numColumns; j++)
        {
            val = colRow(A->rows[i], B->rows, j,A->numRows);
            ptr->cell=val;
            /*updating pointer*/
            ptr=ptr->next;
        }
    }
}
/*HELPER function for the 2nd function*/
/*calculates the current result of C[i][j]*/
int colRow (Node* A, Node** B, int col, int row)
{
    int result=0 ,j, i;
    Node *ptrB,*ptrA;
    ptrA=A;
    for(i=0; i<row; i++)
    {
        ptrB=B[i];
        /*arrive at the right column*/
        for(j=0; j<col; j++)
            {ptrB=ptrB->next;}
        /*calculation*/
        result += ((ptrA->cell)*(ptrB->cell));
        /*updating pointers*/
        ptrA=ptrA->next;
    }
    return result;
}
/*FUNCTION 3*/
/*finds the n element of the Fibonacci sequence*/
int matFib(int index)
{
    int i;
    Matrix *fib, *result;
    Node *ptrResult;
    /*building the matrices well use*/
    fib =(Matrix*)malloc(sizeof(Matrix));
    fib->numColumns=2;
    fib->numRows=2;
    buildMatt(fib);
    fibFiller(fib);

    result =(Matrix*)malloc(sizeof(Matrix));
    result->numColumns=2;
    result->numRows=2;
    buildMatt(result);
    /*case 1; if the element asked was the first one*/
    if(index == 1)
        return 1;
    /*case 2; if the element was an EVEN number*/
    for(i=index; i>1; i=i/2)/*we repeat this loop log(n) times*/
    {
        /*use the 2nd function made*/
        MultiplyMatrices(fib,fib,result);
        /*prepare for next round of the loop*/
        cpyM(fib,result);
    }
    /*returning the result of fib[0][1] which is fib(n)*/
    ptrResult= result->rows[1];
    i = ptrResult->cell;
    /*freeing the used matrices*/
    freeMatt(fib);
    freeMatt(result);
    return i;
}
/*this function copys the matrix B into A*/
void cpyM(Matrix *A, Matrix*B)
{
    int i;
    Node *ptrA,*ptrB;
    /*1st row*/
    ptrA=A->rows[0];
    ptrB=B->rows[0];
    ptrA->cell=ptrB->cell;
    ptrA->next->cell=ptrB->next->cell;
    /*2nd row*/
    ptrA=A->rows[1];
    ptrB=B->rows[1];
    ptrA->cell=ptrB->cell;
    ptrA->next->cell=ptrB->next->cell;
}
/*this function helps fill the Fibonacci Matrix to it's starter values*/
void fibFiller(Matrix* mat)
{
    Node *ptr;
    ptr = mat->rows[0];/*filling the first row*/
    ptr->cell = 1;
    ptr->next->cell = 1;
    ptr = mat->rows[1];/*filling the second row*/
    ptr->cell = 1;
    ptr->next->cell = 0;
}
/*HELPER FUNCTIONS*/
/*this function builds all members of a matrix*/
void buildMatt(Matrix *A)
{
    int i,j;
    Node *ptr,*pMoving,*head=NULL;
    /*creating the list*/
    if( (A->rows = (Node**)malloc(sizeof(Node*)*A->numRows)) == NULL ) exit(1);
    /*make the columns*/
    for(i=0; i< A->numRows; i++)
    {
        for(j=0; j< A->numColumns; j++)
        {
            if( (ptr = (Node*)malloc(sizeof(Node))) == NULL) exit(1);
            if(head==NULL)
            {
                head=ptr;
                pMoving=ptr;
                head->next=NULL;
            }
            else
            {
                pMoving->next=ptr;
                pMoving=ptr;
                pMoving->next=NULL;
            }
        }
        A->rows[i]=head;
        head=NULL;
    }
}

/*freeing a matrix*/
void freeMatt(Matrix *Matt)
{
    int i;
    Node *pnext,*p;
    for(i=0;i<Matt->numRows; i++)
    {
        p=(Matt->rows)[i];
        while(p->next != NULL)
        {
            pnext=p->next;/*save a pointer to the rest of the list*/
            free(p);
            p=pnext;/*updating the pointer*/
        }
        free(pnext);
    }
    free(Matt);
}
