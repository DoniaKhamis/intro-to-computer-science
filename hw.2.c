/*********************************************
Student One (Donia Khamis + 212794630)
Student Two (Mohammad Diab + 212720841)
Assignment number:2
Exercise number:
********************************************/
#include <stdio.h>
int main()
{
    int X,Y,result_1,r,i,j,choice;
    double result_2,result_3,p,p_sum,x_case2,x_case3;

    while(1)
    {
        /*print menu*/
        printf("Menu:\n1. Multivariable function.\n2. Expected value.\n3. Ascending base with descending power.\n4. Exit\nEnter your choice:\n");
        if(scanf("%d",&choice)<1)return 1;/*receive the chosen number from the menu*/
        /*there is a value in the variable choice*/
        switch(choice)
        {
        case 1:
            result_1=0;/*starting the counter*/
            /*receive X*/
            printf("Please enter value of X:\n");
            if((scanf("%d",&X))<1) return 1;
            /*receive Y*/
            printf("Please enter value of Y:\n");
            if((scanf("%d",&Y))<1) return 1;
            /*calculate the result according to the given function*/
            if(X<Y)
                result_1 = (X*X)+Y;
            else if(Y == X || X == Y+7 || X == Y+8)
                result_1 = Y;
            else
                result_1 = (X+1)*(X-1);
            printf("f(X = %d, Y = %d) = %d.\n" ,X,Y,result_1);
            break;

        case 2:
            /*starting the counters for this round*/
            result_2=0;
            p_sum=0;
            while(p_sum<=1)/*probability sum not exceed 1*/
            {
                /*receive an x*/
                printf("Please enter value:\n");
                if(scanf("%lf",&x_case2)<1)return 1;
                /*receive a p*/
                printf("Please enter probability:\n");
                if(scanf("%lf",&p)<1)return 1;
                result_2 += x_case2*p;/*calculating the result according to the given function*/
                p_sum += p;/*summing the probabilities*/
            }
            /*remove excess probability*/
            result_2 -= x_case2*p;/*reduce the latest received value*/
            p = 1-(p_sum-p);/*change the p according to the function*/
            result_2 += x_case2*p;/*add the new changed value*/
            printf("E[X]=%.2f.\n",result_2);
            break;

        case 3:
            result_3=1;/*starting the counter*/
            /*receive x*/
            printf("Please enter value of x:\n");
            if(scanf("%lf",&x_case3)<1)return 1;
            /*receive r*/
            printf("Please enter value of r:\n");
            if(scanf("%d",&r)<1)return 1;
            /* calculating the result according to the given equation */
            for(i=1;i<=r;i++)/*repeating calculation for every value of i*/
            {
                for(j=1;j<=i;j++)/*to the power of i*/
                {
                    result_3 *= (x_case3 - 0.1*i);
                }
            }
            printf("P(x = %.2f, r = %d) = %.2f.\n", x_case3,r,result_3);
            break;

        case 4: /* fall through */
        default : /* case of receiving 4 or another int */
            printf("Homework 2, goodbye.\n");
            return 0;
        }
    }
return 0;
}
