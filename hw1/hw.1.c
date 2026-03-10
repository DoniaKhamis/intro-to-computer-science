/******************************************** *
Assignment number:1
Exercise number:
********************************************/
#include <stdio.h>
#define DUPLICATE 2
int main()
{
    double v,t,d,growth,num_double,result,calc4;
    int num, follow,result3;

    /*Q1*/
    printf("-------------------1-------------------\n");
    /*receiving inputs of the question and checking they are legal*/
    printf("Please enter the velocity in km/h:\n");
    result = scanf("%lf" ,&v);
    if(result<1 || v<0) return 1;
    printf("Please enter the time in minutes:\n");
    result = scanf("%lf" ,&t);
    if(result<1 || t<0) return 1;
    /*calculating and printing the result*/
    printf("The distance is %f km.\n" ,((t/60)*v));
    printf("---------------------------------------\n");

    /*Q2*/
    printf("-------------------2-------------------\n");
    /*receiving inputs of the question*/
    printf("Please enter the initial number of cells: \n");
    result = scanf("%d" ,&num);
    if(result<1 || num<0) return 1;
    /*using the defined value to calculate the result and print it*/
    printf("After 2 seconds there will be %d cells.\n" ,(DUPLICATE*DUPLICATE*num));
    printf("---------------------------------------\n");

    /*Q3*/
    printf("-------------------3-------------------\n");
    /*receiving inputs of the question*/
    printf("Please enter the current number of followers:\n");
    result = scanf("%d" ,&follow);
    if(result<1 ||follow<0) return 1;
    printf("Please enter the growth rate:\n");
    result = scanf("%lf" ,&growth);
    if(result<1 ||growth<0) return 1;
    /*printing and calculating the result*/
    result3=(growth+1)*(growth+1)*(growth+1)*(growth+1)*follow;
    printf("The number of followers after 4 months is %d.\n" ,result3);
    printf("---------------------------------------\n");

    /*Q4*/
    printf("-------------------4-------------------\n");
    /*receiving inputs of the question*/
    printf("Please enter the initial velocity in m/s :\n");
    result = scanf("%lf" ,&v);
    if(result<1 || v<0) return 1;
    printf("Please enter the distance in meters:\n");
    result = scanf("%lf" ,&d);
    if(result<1||d<0) return 1;
    printf("Please enter the time in seconds :\n");
    result = scanf("%lf" ,&t);
    if(result<1 ||t<0) return 1;
    /*calculating as requested*/
    calc4 = (d-v*t)*2/(t*t);
    /*printing the result as an output*/
    printf("The acceleration is %f m/s^2.\n" ,calc4);
    printf("---------------------------------------\n");

    /*Q5*/
    printf("-------------------5-------------------\n");
    /*receiving inputs of the question*/
    printf("Please enter a real number:\n");
    result = scanf("%lf" ,&num_double);
    if(result<1) return 1;
    /*saving the whole value that was received without the fraction*/
    num = num_double;

    if(num_double>0)
    {
         if((num_double-0.5) >= num) /*case 1 : the remainder is bigger than 0.5*/
        num = num_double+1;
        else {
                num = num_double; /*case 2 : the remainder is smaller than 0.5*/
            }
    }
    /*dealing with minus*/
    else
    {
        /*if the input is 0*/
        if(num_double==0)
        {
            printf("The rounded number is 0.\n");
            return 0;
        }

        if((num_double+0.5) >= num) /*case 1 : the remainder is bigger than 0.5*/
            num = num_double;
        else {
                num = num_double-1; /*case 2 : the remainder is smaller than 0.5*/
            }
    }
    /*printing the result as an output*/
    printf("The rounded number is %d.\n" ,num);
    printf("---------------------------------------\n");

    /*the code was done successfully*/
    return 0;
}

