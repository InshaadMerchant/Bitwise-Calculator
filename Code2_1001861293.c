// Inshaad Merchant 1001861293
#include<stdio.h>
#define BITS 16
void ConvertDecimalToBinary(int number, char MyArray[BITS])
{
    int i;
    int Temp[BITS];
    Temp[0]=number;
    for (i=1;i<BITS;i++)
    {
        Temp[i]=number>>1;
        number=Temp[i];
    }
    for(i=0;i<BITS;i++)
    {
        Temp[i]=Temp[i]&1;
    }
    for(i=0;i<BITS;i++)
    {
        MyArray[i]=Temp[BITS-1-i]+48;
    }
    printf("\n");
}
int main(void)
{
    int op1,op2,result;
    char oper[3];
    char abc[BITS]={};
    char fgh[BITS]={};
    char xyz[BITS+1]={};
    printf("Bitwise Calculator \t\n\n");
    printf("Enter two base 10 values with a bitwise operator to see the decimal result\n and the binary result.");
    printf("\tThe format is:\n\n");
    printf("FirstNumber BitwiseOperator SecondNumber\n\n");
    printf("For example, enter the expression\n\n");
    printf("2 & 3\n\n");
    printf("This calculator can used with &, |, ^, << and >>\n\n");
    printf("Please note that the spaces between numbers and operator is essential\n");
    printf("and the two entered values must be between 0 and 255\n\n");
    printf("Enter the expression:");
    scanf("%d %s%d",&op1,oper,&op2);
    while ((op1<0) || (op1>255) || (op2<0) || (op2>255))
    {
        printf("operands are out of bounds, please re enter:\n");
        printf("Enter the expression: ");
        scanf("%d %s%d",&op1,oper,&op2);
    }
    printf("In Base 10....\n");
    if(oper[0]=='&')
    {
        printf("%d %s %d = %d\n",op1,oper,op2,op1 & op2);
        result = op1 & op2;
    }
    else if(oper[0]=='|')
    {
        printf("%d %s %d = %d\n",op1,oper,op2,op1 | op2);
        result = op1 | op2;
    }
    else if(oper[0]=='^')
    {
        printf("%d %s %d = %d\n",op1,oper,op2,op1 ^ op2);
        result = op1 ^ op2;
    }
    else if(oper[0]=='>')
    {
        printf("%d %s %d = %d\n",op1,oper,op2,op1 >> op2);
        result = op1 >> op2;
        printf("In 8-bit base 2...\n");
        ConvertDecimalToBinary(op1,abc);
        printf("%s ",abc);
        printf("%c %d",oper[0],op2);
        ConvertDecimalToBinary(result,xyz);
        printf("========\n");
        printf("%s\n",xyz);
        return 0;
    }
    else if(oper[0]=='<')
    {
        printf("%d %s %d = %d\n",op1,oper,op2,op1 << op2);
        result = op1 << op2;
        printf("In 8-bit base 2...\n");
        ConvertDecimalToBinary(op1,abc);
        printf("%s ",abc);
        printf("%c %d",oper[0],op2);
        ConvertDecimalToBinary(result,xyz);
        printf("========\n");
        printf("%s\n",xyz);
        return 0;
    }
    else
    {
        printf("Invalid operator.");
        return 0;
    }
    printf("In 8-bit base 2...\n");
    ConvertDecimalToBinary(op1,abc);
    printf("%s\n",abc);
    printf("%c",oper[0]);
    ConvertDecimalToBinary(op2,fgh);
    printf("%s\n",fgh);
    ConvertDecimalToBinary(result,xyz);
    printf("========\n");
    printf("%s\n",xyz);
    
    return 0;
}