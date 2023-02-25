#include <stdio.h>
#include <stdlib.h>
int lhash(int a, int i, int n){
	return (a+i)%n;
}
int qhash(int a, int i, int n){
	return (a + i*i)%n;
}
int isprime(int k){
	int i;
	for(i = 2; i<k; i++) if(k%i==0) return 0;
	return 1;
}
int maxprim(int p){
	int k = p-1, i;
	for(i = k; ; i--) if(isprime(i)) return i;
}
int dhash(int k, int i, int p, int n){
	return (k%n + i*(p- k%p))%n;
}
int lsearch(int a[], int p, int q){
	int i;
	for(i=0; i<q; i++) if(a[i]==p) return 1;
	return 0;
}
int min(int a, int b){
  if(a<b) return a;
  return b;
}
int main(){
	int n;
	scanf("%d", &n);
	int c = 0;
	int a[1000000];
	char b[1000000], t[10];
	scanf(" %[^\n]s", b);
	int i,le = 0;
	for(i = 0; b[i]!='\0'; i++) if(b[i]==' ') c++;
	c++;
	for(i = 0; i< c; i++){
	  int m = 0;
	  while(b[le]!=' ' && b[le]!='\0') t[m++] = b[le++];
	  t[m] = '\0';
	  le++;
	  int e = atoi(t);
	  a[i] = e;
	}
	int f = min(c, n);
	int l[f], q[f], d[f];
	for(i = 0; i<f; i++){
		l[i] = -1;
		q[i] = -1;
		d[i] = -1;
	}
	int cl = 0, il, cq = 0, iq, cd = 0, id;
	for(i = 0; i<f; i++){
		il = 0;
		l[i] = lhash(a[i], il, n);
		while(lsearch(l, l[i], i)!=0){
			il++;
			cl++;
			l[i] = lhash(a[i], il, n);
		}
	}
	for(i = 0; i<f; i++){ 
	  if(l[i]<0) printf("E ");
	  else printf("%d ", l[i]);
	}
	int p = c - n;
	for(i = 0; i<p; i++) printf("E ");
	printf("\n%d\n", cl);
	for(i = 0; i<f; i++){
		iq = 0;
		q[i] = qhash(a[i], iq, n);
		while(lsearch(q, q[i], i)!=0){
			iq++;
			cq++;
			q[i] = qhash(a[i], iq, n);
		}
	}
	for(i = 0; i<f; i++){
	  if(q[i]<0) printf("E ");
	  else printf("%d ", q[i]);
	}
	for(i = 0; i<p; i++) printf("E ");
	printf("\n%d\n", cq);
	int s = maxprim(n);
	for(i = 0; i<f; i++){
		id = 0;
		d[i] = dhash(a[i], id, s, n);
		while(lsearch(d, d[i], i)!=0){
			id++;
			cd++;
			d[i] = dhash(a[i], id, s, n);
		}
	}
	for(i = 0; i<f; i++){
	        if(d[i]<0) printf("E");
	        else printf("%d ", d[i]);
	}
	for(i = 0; i<p; i++) printf("E ");
	printf("\n%d\n", cd);
}
