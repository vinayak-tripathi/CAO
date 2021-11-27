#include<stdio.h>
#include<math.h>

int main(){
    int n;
    printf("Enter the bit-size: ");
    scanf("%d",&n);
    int A[n], B[n], a, b, cin, s[n], g[n], p[n], sum=0;
    printf("Enter A: ");
    scanf("%d", &a);
    printf("Enter B: ");
    scanf("%d", &b);

    for (int i=0;i<n;i++){
        A[i]=a%2;
        B[i]=b%2;
        a=a/2;
        b=b/2;
    }
    printf("Binary form of A: ");
    for (int i=n-1;i>=0;i--){
        printf("%d",A[i]);
    }
    printf("\nBinary form of B: ");
    for (int i=n-1;i>=0;i--){
        printf("%d",B[i]);
    }
    printf("\n Addition process");
    cin=0;
    for (int i=0; i<=n-1; i++){
        printf("\n\nA[%d]=%d, B[%d]=%d",i,A[i],i,B[i]);
        s[i]=(A[i]^B[i])^cin;
        g[i]=A[i]&B[i];
        p[i]=A[i]^B[i];
        cin=g[i]|(p[i]&cin);
        printf("\nS=%d, g=%d, p=%d, cin=%d\n_______________________",s[i],g[i],p[i],cin);
    }
    printf("\n\n SUM in binary: ");

    for(int i=n-1;i>=0;i--)
    {
    printf("%d",s[i]);
    sum+=s[i]*pow(2,i);
    }
    sum=sum+cin*pow(2,n);
    printf("\n Carry :%d",cin);
    printf("\n\n SUM in decimal: %d", sum);
    getch();
    return 0;
}