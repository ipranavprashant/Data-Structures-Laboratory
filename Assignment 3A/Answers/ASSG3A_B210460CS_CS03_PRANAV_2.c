#include<stdio.h>
int minheap(int a[],int beg,int end);
int heapsort(int a[],int size);
int minheapify(int a[],int f,int size);
int search(int a[],int size,int key);
int handlingSwap(int a[],int size,int key,int replaceWith);

int main()
{
    int arr[100000],k=0;
    char ch;
    int q;
    do{
        scanf("%c",&ch);
    switch(ch)
    {
        case 'i':scanf("%d",&q);
        arr[++k]=q;
        // k++;
        break;
        
        case 'p':minheap(arr,0,k);
        for(int i=1;i<=k;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");break;
        
        case 'x':for(int  i=1;i<=k-1;i++)   //k-1 since k-1+1=k
        {
            arr[i]=arr[i+1];
        }
        k--;
        minheap(arr,0,k);
        for(int i=1;i<=k;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
        break;
        
        case 'd':scanf("%d",&q);
        int index=search(arr,k,q);
        if(index==-1)
        printf("-1\n");
        else
        {
            printf("%d\n",arr[index]);
            for(int i=index;i<=k-1;i++)
            {
                arr[i]=arr[i+1];
            }
            k--;
        }
        break;
        
        case 'g':printf("%d\n",arr[1]);
        break;

        
        case 'r':int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        int ans=handlingSwap(arr,k,x,y);
        if(ans==-1)
        printf("-1\n");
        else
        {
            printf("%d\n",y);
        }
        break;
        
        case 'e':return 0;
        break;
    }
    }while(ch!='e');
    return 0;
}

int minheap(int a[], int beg, int end)
{
	for(int i = end/2; i>beg; i--)
	{
		minheapify(a, i, end);
	}
}

int minheapify(int a[], int f, int size)
{
	int min = f, l = f*2, r = f*2 +1, temp;
	if(l<=size && a[l]<a[min])
	{
		min = l;
	}
	if(r<=size && a[r]<a[min])
	{
		min = r;
	}
	if(f!=min)
	{
		temp = a[f];
		a[f] = a[min];
		a[min] = temp;
		minheapify(a, min, size);
	}
}

int search(int a[],int size,int key)
{
    for(int i=1;i<=size;i++)
    {
        if(a[i]==key)
        return i;
    }
    return -1;
}

int handlingSwap(int a[],int size,int key,int replaceWith)
{
    if(replaceWith>=key)
    return -1;
    else
    {
        int index1=search(a,size,key);
        a[index1]=replaceWith;
    }
}

