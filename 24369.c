#include<stdio.h>

int Min(int,int);//min fuction
int GCD(int,int);//to calculate GCD
int LCM(int,int);//to calculate LCM

int Min(int a,int b){
    int min=a;
    if(min>b){
        min=b;
    }
    return min;
}

int GCD(int a,int b){
    //utilizing Long Divison Method
    if(a>b){
        a+=b;
        b=a-b;
        a=a-b;
    }
    while(b%a!=0){
        int c=b%a;
        b=a;
        a=c;
    }
    return a;
}

int LCM(int a,int b){
    int ans=a*b/GCD(a,b);
    return ans;
}


int GCD3(int,int,int);//Greatest Common Divisor for 3 numbers
int LCM3(int,int,int);//Lowest Common Multiple for 3 numbers
int factorial(int);//factorial function
void Fibo(int);//to print numbers from fibonacci series upto n

int GCD3(int a,int b,int c){
    int ans= GCD(GCD(a,b),c);
    return ans;
}

int LCM3(int a,int b, int c){
    int ans=LCM(LCM(a,b),c);
    return ans;
}

int factorial(int a){
    int fact=1;
    while(a>0){
        fact= fact*a;
        a--;
    }
    return fact;
}

void Fibo(int n){
    int a=0;
    int b=1;
    printf("%d ",a);
    while(n>b){
        printf("%d ",b);
        int c=b;
        b+=a;
        a=c;
    }
    printf("\n");
}



void main(){
    int a;
    int ans;
    printf("What operation do you want to perform\n"
        "Give input for corresponding operation:\n"
        "0 to Calculate GCD of 3 numbers\n"
        "1 to Calculate LCM of 3 numbers\n"
        "2 to Calculate Factorial of given number\n"
        "3 to Print numbers from Fibonacci series upto given number\n");
    //Input
    do{
        scanf("%d",&a);
    }
    while(a!=0 && a!=1 && a!=2 && a!=3);
    int x,y,z;
    switch (a)
    {
    case 0:
        printf("Enter the numbers to calculate GCD\n");
        
        scanf("%d %d %d",&x,&y,&z);
        ans=GCD3(x,y,z);
        printf("%d",ans);
        break;
    case 1:
        printf("Enter the numbers to calculate LCM\n");
        scanf("%d %d %d",&x,&y,&z);
        ans=LCM3(x,y,z);
        printf("%d",ans);
        break;
    case 2:
        printf("Enter the number to calculate it's factorial\n");
        scanf("%d",&x);
        ans=factorial(x);
        printf("%d",ans);
        break;
    case 3:
        printf("Enter the number to which numbers from Fibonnacci series should be printed\n");
        scanf("%d",&x);
        Fibo(x);
        break;
    default:
        printf("Error:Invalid input\n");
    }
}