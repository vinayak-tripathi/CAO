#include<stdio.h>
#include<math.h>

void add(int A[], int B[],int n){                //function to add the binary number
    int carry=0,res[n];
    for (int i=0;i<n;i++){
        res[i] =A[i] + B[i] + carry;
               if (res[i] >= 2){
                    carry = 1;
               }
               else{
                    carry= 0;
               }
               res[i] = res[i]%2;
    }
    for (int i=n-1;i>=0;i--){
        A[i]=res[i];
    }
}

void shift(int A[],int Q[],int *q,int n){        //function to arithmetic shift for the A, Q and q
    int temp=A[n-1], temp2=A[0], temp3=Q[0];
    *q=temp3;
    for (int i=1;i<n;i++){
        Q[i-1]=Q[i];
    }
    Q[n-1]=temp2;
    for (int i=1;i<n;i++){
        A[i-1]=A[i];
    }
    A[n-1]=temp;
}

int main(){
    int a, a1 ,b, b1, n, flag_a=0, flag_b=0;
    printf("Enter Bit size: ");
    scanf("%d", &n);                             //size of register or bitsize of number
    int r1=-1*pow(2,n-1),r2=pow(2,n-1)-1;        //Range of number for getting correct output
    printf("*Enter M and Q in range of %d and %d",r1,r2);
    printf("\n\nEnter M(multiplicand): ");
    scanf("%d", &a);                             //Multiplicand
    printf("Enter Q(multiplier): ");
    scanf("%d", &b);                             //Mltiplier
    if(a<0){                                     //Checking if multiplicand is negative
        a1=abs(a);
        flag_a=1;
    }
    else{
        a1=a;
    }
    if(b<0){                                      //Checking if multiplier is negative
        b1=abs(b);
        flag_b=1;
    }
    else{
        b1=b;
    }
    int M[n], Mcomp[n], Q[n], A[n], q=0;          //Array for Storing binary for the numbers
    for (int i=0;i<n;i++){                        //Converting to binary for the abs value of the numbers entered  
        M[i]=a1%2;
        Q[i]=b1%2;
        A[i]=0;
        a1=a1/2;
        b1=b1/2;
    }
    printf("\n");
    if (flag_b){                                  //If multiplier is negative make its twos compliment
        int carry=1;
        for(int i=0;i<n;i++){
            if (Q[i]==1){
                Q[i]=0;
            }
            else{
                Q[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if ((Q[i]==1)&&carry==1){
                Q[i]=0;
            }
            else if ((Q[i]==0)&&carry==1){
                Q[i]=1;
                carry=0;
            }
        }
    }
    int carry=1;                                  //Making twos compliment for the abs value of multiplicand
    for(int i=0;i<n;i++){
        if (M[i]==1){
            Mcomp[i]=0;
        }
        else{
            Mcomp[i]=1;
        }
    }
    for(int i=0;i<n;i++){
        if ((Mcomp[i]==1)&&carry==1){
            Mcomp[i]=0;
        }
        else if ((Mcomp[i]==0)&&carry==1){
            Mcomp[i]=1;
            carry=0;
        }
    }   
    if (flag_a){                                  //If multiplicand is negative the make approprite changes in the binary form
        int temp[n];
        for (int i=0;i<n;i++){
            temp[i]=M[i];
        }
        for (int i=0;i<n;i++){
            M[i]=Mcomp[i];
        }
        for (int i=0;i<n;i++){
            Mcomp[i]=temp[i];
        }
    }
    printf("Binary form of M: ");
    for (int i=n-1;i>=0;i--){
        printf("%d",M[i]);
    }
    printf("\nBinary form of Q: ");
    for (int i=n-1;i>=0;i--){
        printf("%d",Q[i]);
    }
    printf("\nBinary form of M': ");
    for (int i=n-1;i>=0;i--){
        printf("%d",Mcomp[i]);
    }
    printf("\nA: ");
    for (int i=n-1;i>=0;i--){
        printf("%d",A[i]);
    }
    printf("\t|");
    printf("Q: ");
    for (int i=n-1;i>=0;i--){
        printf("%d", Q[i]);
    }
    printf("\t|");
    printf("q: %d", q);
    printf("\t|");
    printf("M: ");
    for (int i=n-1;i>=0;i--){
        printf("%d", M[i]);
    }
    printf("\t|Initial Values");
    printf("\n");
    printf("\n");
    for (int i=0;i<n;i++){                        //Multiplication Algorithm
        if ((Q[0]==1)&&(q==0)){   
            add(A, Mcomp,n);                      //Subtracting A <-- A-M 
            printf("A: ");
            for (int i=n-1;i>=0;i--){
                printf("%d", A[i]);
            }
            printf("\t|");
            printf("Q: ");
            for (int i=n-1;i>=0;i--){
                printf("%d", Q[i]);
            }
            printf("\t|");
            printf("q: %d", q);
            printf("\t|");
            printf("M: ");
            for (int i=n-1;i>=0;i--){
                printf("%d", M[i]);
            }
            printf("\t|A <-- A-M\n");
        }
        else if ((Q[0]==0)&&(q==1)){
            add(A, M,n);                          //Adding A <-- A+M
            printf("A: ");
            for (int i=n-1;i>=0;i--){
                printf("%d", A[i]);
            }
            printf("\t|");
            printf("Q: ");
            for (int i=n-1;i>=0;i--){
                printf("%d", Q[i]);
            }
            printf("\t|");
            printf("q: %d", q);
            printf("\t|");
            printf("M: ");
            for (int i=n-1;i>=0;i--){
                printf("%d", M[i]);
            }
            printf("\t|A <-- A+M\n");
        }
        shift(A,Q,&q,n);                          //Arithmetic Shift
        printf("A: ");
        for (int i=n-1;i>=0;i--){
            printf("%d", A[i]);
        }
        printf("\t|");
        printf("Q: ");
        for (int i=n-1;i>=0;i--){
            printf("%d", Q[i]);
        }
        printf("\t|");
        printf("q: %d", q);
        printf("\t|");
        printf("M: ");
        for (int i=n-1;i>=0;i--){
            printf("%d", M[i]);
        }
        printf("\t|Shift");
        printf("\n\n");
    }
    int pro[2*n];
    for (int i=n-1;i>=0;i--){
        pro[i+n]=A[i];
    }
    for (int i=n-1;i>=0;i--){
        pro[i]=Q[i];
    }
    printf("\nProduct in Binary: ");
    for (int i=2*n-1;i>=0;i--){
        printf("%d",pro[i]);
    }
    int sign=1;
    if(pro[2*n-1]==1){
        for(int i=0;i<2*n;i++){
            if (pro[i]==1){
                pro[i]=0;
            }
            else{
                pro[i]=1;
            }
        }
        int carry=1;
        for(int i=0;i<2*n;i++){
            if ((pro[i]==1)&&carry==1){
                pro[i]=0;
            }
            else if ((pro[i]==0)&&carry==1){
                pro[i]=1;
                carry=0;
            }
        }
        sign=-1;
    }
    int ans=0;
    for(int i=2*n-1;i>=0;i--){
        ans+=pro[i]*pow(2,i);
    }
    ans*=sign;
    printf("\nProduct in Decimal: %d\n",ans);
    getch();
    return 0;
}