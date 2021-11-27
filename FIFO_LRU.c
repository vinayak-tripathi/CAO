#include<stdio.h>
int Hit(int data, int f, int frame[]){
    int hit=0;
    for(int j=0; j<f; j++)
    {
        if(frame[j]==data)
        {
            hit=1;
            break;
        }
 
    }
 
    return hit;
}
int start(int frame[], int f){
    for (int i=0;i<f;i++)
        frame[i]=-1;
}
void disp(int frame[], int f){
    for (int i=0;i<f;i++)
        if (frame[i]!=-1)
            printf("  %d", frame[i]); 
}
int main(){
    int f, n;
    printf("Enter length of reference string: ");
    scanf("%d", &n);
    printf("Enter frame size: ");
    scanf("%d", &f);
    int ref[n], frame[f], pagefault=0, pagehit=0;
    printf("Enter the page reference sequence: ");
    for(int i=0; i<n; i++)
        scanf("%d",&ref[i]);
    printf("\n*********FIFO Algorithm*********\n");
    start(frame, f);
    for(int i=0; i<n; i++){
        printf("\n%d |",ref[i]);
        if(Hit(ref[i],f,frame)==0){
            int k;
            for(k=0; k<f-1; k++)
                frame[k]=frame[k+1];
 
            frame[k]=ref[i];
            pagefault++;
            disp(frame,f);
        }
        else{
            printf("Hit");
            pagehit++;}
    }
    printf("\nPage Faults: %d\nPage Hits: %d",pagefault,pagehit);
    printf("\n*********LRU Algorithm*********\n");
    start(frame, f); 
    pagefault=0;
    pagehit=0;
    int least[50],j;
    for(int i=0; i<n; i++) {
        printf("\n%d |",ref[i]);
        if(Hit(ref[i],f,frame)==0){ 
            for(j=0; j<f; j++){
                int pg=frame[j];
                int found=0;
                for(int k=i-1; k>=0; k--){
                    if(pg==ref[k]){
                        least[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    least[j]=-1;
            }
            int min=10000;
            int repindex;
            for(j=0; j<f; j++)
            {
                if(least[j]<min)
                {
                    min=least[j];
                    repindex=j;
                }
            }
            frame[repindex]=ref[i];
            pagefault++;
            disp(frame,f);
        }
        else{
            printf("Hit");
            pagehit++;
        }
    }
    printf("\nPage Faults: %d\nPage Hits: %d",pagefault,pagehit);
    getch();
    return 0;
}