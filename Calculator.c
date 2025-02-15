#include<stdio.h>

int add(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);
int rem(int,int);
double pwr(int,int);
int Min(int,int);//min fuction
int GCD(int,int);//to calculate GCD
int LCM(int,int);//to calculate LCM
int GCD3(int,int,int);//Greatest Common Divisor for 3 numbers
int LCM3(int,int,int);//Lowest Common Multiple for 3 numbers
int factorial(int);//factorial function
void Fibo(int);//to print numbers from fibonacci series upto n
int getUserChoice();//to get input
int execute(int);//to execute correct operation using switch case

int add(int a,int b){
    a+=b;
    return a;
}

int sub(int a,int b){
    a-=b;
    return a;
}

int mul(int a,int b){
    a*=b;
    return a;
}

int div(int a,int b){
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    a/=b;
    return a;
}

int rem(int a,int b){
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    a=a%b;
    return a;
}

double pwr(int a, int b) {
    if (a == 1 || b == 0) {
        return 1;
    }

    double result = 1.0;
    if (b > 0) {
        result = a;
        int i;
        for (i = 1; i < b; i++) {
            result *= a;
        }
    } else if (b < 0) {
        if (a == 0) {
            return 0;
        }
        result = 1.0 / a;
        int i;
        for (i = -1; i > b; i--) {
            result /= a;
        }

    }

    return result;
}

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

int getUserChoice(){
    int a;//Input
    printf("What operation do you want to perform\n"
        "Give input for corresponding operation:\n"
        "0 to Calculate GCD of 3 numbers\n"
        "1 to Calculate LCM of 3 numbers\n"
        "2 to Calculate Factorial of given number\n"
        "3 to Print numbers from Fibonacci series upto given number\n"
        "4 to Add 2 given numbers"
        "5 to Subtract second number from first"
        "6 to Multiply 2 given numbers"
        "7 to Give quotient for division of second number from first"
        "8 to Give remainder for division of second number from first"
        "9 to Calculate first input to the power second input");
    do{
        scanf("%d",&a);
    }
    while(a < 0 || a > 9);
    return a;
}

int execute(int choice){
    int x,y,z,ans;
    switch (choice)
    {
    case 0:
        printf("Enter the numbers to calculate GCD\n");
        
        scanf("%d %d %d",&x,&y,&z);
        ans=GCD3(x,y,z);
        printf("%d\n",ans);
        break;
    case 1:
        printf("Enter the numbers to calculate LCM\n");
        scanf("%d %d %d",&x,&y,&z);
        ans=LCM3(x,y,z);
        printf("%d\n",ans);
        break;
    case 2:
        printf("Enter the number to calculate it's factorial\n");
        scanf("%d",&x);
        ans=factorial(x);
        printf("%d\n",ans);
        break;
    case 3:
        printf("Enter the number to which numbers from Fibonnacci series should be printed\n");
        scanf("%d",&x);
        Fibo(x);
        break;
    case 4:
        printf("Enter the numbers to be added\n");
        scanf("%d %d",&x,&y);
        printf("%d\n",add(x,y));
        break;
    case 5:
        printf("Enter the first number\n");
        scanf("%d",&x);
        printf("Enter the second number\n");
        scanf("%d",&y);
        printf("%d\n",sub(x,y));
        break;
    case 6:
        printf("Enter the numbers to be multiplied\n");
        scanf("%d %d",&x,&y);
        printf("%d\n",mul(x,y));
        break;
    case 7:
        printf("Enter the divident\n");
        scanf("%d",&x);
        printf("Enter the divisor\n");
        scanf("%d",&y);
        printf("%d\n",div(x,y));
        break;
    case 8:
        printf("Enter the divident\n");
        scanf("%d",&x);
        printf("Enter the divisor\n");
        scanf("%d",&y);
        printf("%d\n",rem(x,y));
        break;
    case 9:
        printf("Enter the base\n");
        scanf("%d",&x);
        printf("Enter the power\n");
        scanf("%d",&y);
        printf("%f\n",pwr(x,y));
        break;
    default:
        printf("Error:Invalid input\n");
    }
}


void main(){
    int choice= getUserChoice();
    execute(choice);  
}
