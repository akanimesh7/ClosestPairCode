#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <float.h>
#include <time.h>
#include <iomanip>
using namespace std;

class pr
{
	double x,y;
public:
	
	double fx(){
		return x;
	}
	double fy(){		
		return y;
	}
	double sx(double a){
		x=a;
	}
	double sy(double b){
		y=b;
	}
	
	
};

double sqrt(double n){
	double k=1;
	 while((k*k - n) > 0.0001 || (n - k * k) > 0.0001){
             k = (k + n / k) / 2;
	}
     return k;
}

class ans_pair
 {
 	double x1,y1,x2,y2;
 public:
 	double dst(){
 		return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
 	}
 	void sv(double a,double b,double c,double d){

 		x1=a;y1=b;x2=c;y2=d;
 	}
 	double gx1(){return x1;}
 	double gy1(){return y1;}
 	double gx2(){return x2;}
 	double gy2(){return y2;}
 	
 	
 }; 



double dis(pr a,pr b){
		double x1=a.fx();
		double x2=b.fx();
		double y1=a.fy();
		double y2=b.fy();
		return(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
	}

class main
{
public:

	 void qsx(pr arr[],int l,int r){
	if(l<r){
	double pivot=arr[r].fx();
	double pivoty=arr[r].fy();
	int idx=l;
	for(int i=l;i<r;i++){
		if(arr[i].fx()<pivot){
			//swap(arr[i],arr[idx]);
			double tx=arr[i].fx();double ty=arr[i].fy();
			arr[i].sx(arr[idx].fx());
			arr[i].sy(arr[idx].fy());
			arr[idx].sx(tx);arr[idx].sy(ty);
			idx++;
		}else if(arr[i].fx() == pivot && arr[i].fy()<pivoty){
			double tx=arr[i].fx();double ty=arr[i].fy();
			arr[i].sx(arr[idx].fx());
			arr[i].sy(arr[idx].fy());
			arr[idx].sx(tx);arr[idx].sy(ty);
			idx++;
		}
	}
	//swap(arr[idx],arr[r]);
	double tx=arr[r].fx();double ty=arr[r].fy();
			arr[r].sx(arr[idx].fx());
			arr[r].sy(arr[idx].fy());
			arr[idx].sx(tx);arr[idx].sy(ty);

	qsx(arr,l,idx-1);
	qsx(arr,idx+1,r);
}
}


void qsy(pr arr[],int l,int r){
	if(l<r){
	double pivot=arr[r].fy();
	double pivotx=arr[r].fx();
	int idx=l;
	for(int i=l;i<r;i++){
		if(arr[i].fy()<pivot){
			//swap(arr[i],arr[idx]);
			double tx=arr[i].fx();double ty=arr[i].fy();
			arr[i].sx(arr[idx].fx());
			arr[i].sy(arr[idx].fy());
			arr[idx].sx(tx);arr[idx].sy(ty);
			idx++;
		}
		else if(arr[i].fy() == pivot && arr[i].fx()<pivotx){
			double tx=arr[i].fx();double ty=arr[i].fy();
			arr[i].sx(arr[idx].fx());
			arr[i].sy(arr[idx].fy());
			arr[idx].sx(tx);arr[idx].sy(ty);
			idx++;
		}
	}
	

	
	double tx=arr[r].fx();double ty=arr[r].fy();
			arr[r].sx(arr[idx].fx());
			arr[r].sy(arr[idx].fy());
			arr[idx].sx(tx);arr[idx].sy(ty);

	qsy(arr,l,idx-1);
	qsy(arr,idx+1,r);
}
}

	ans_pair solve(pr arrx[],int lo,int hi,pr arry[]){
	if(hi == lo+1){
		ans_pair final;
		final.sv(arry[0].fx(),arry[0].fy(),arry[1].fx(),arry[1].fy());
		return final;
	}
	else if(hi==lo){
		ans_pair final;
		final.sv(0,0,0,DBL_MAX);
		return final;
	}

	if(lo<hi){
	ans_pair final;
	int pvt=(lo+hi)/2;
	int lsize=pvt-lo+1;
	int rsize=hi-pvt;
	double pvtx=arrx[pvt].fx();
	pr ydl[lsize];pr ydr[rsize];
	pr yleft[lsize];pr yright[rsize];
	int cl=0;int cr=0;
	for(int i=0;i<(hi-lo+1);i++){
		if(arry[i].fx() <= pvtx  && cl<lsize){
			yleft[cl].sx(arry[i].fx());yleft[cl].sy(arry[i].fy());cl++;
			//cout<<"l "<<arry[i].fx()<<" "<<arry[i].fy()<<endl;
		}else if(arry[i].fx() <= pvtx  && cl==lsize){
			yright[cr].sx(arry[i].fx());yright[cr].sy(arry[i].fy());cr++;
			//cout<<"r "<<arry[i].fx()<<" "<<arry[i].fy()<<endl;
		}
		else{
			yright[cr].sx(arry[i].fx());yright[cr].sy(arry[i].fy());cr++;
			//cout<<"r "<<arry[i].fx()<<" "<<arry[i].fy()<<endl;
		}
	}
	ans_pair l=solve(arrx,lo,pvt,yleft);
	ans_pair r=solve(arrx,pvt+1,hi,yright);
	if(l.dst() < r.dst()){
		final=l;
	}else{
		final=r;
	}
	double del=min(l.dst(),r.dst());
	//cout<<del<<" "<<lo<<" "<<hi<<endl;
	int cdl=-1;int cdr=-1;
	//cout<<"ydl"<<endl;
	for(int i=0;i<lsize;i++){
		if((double)(-(double)yleft[i].fx() +(double)(((double)arrx[pvt].fx()+(double)arrx[pvt+1].fx())/2 )) <= del ){
			cdl++;
			ydl[cdl].sx(yleft[i].fx());ydl[cdl].sy(yleft[i].fy());
			//cout<<yleft[i].fx()<<" "<<yleft[i].fy()<<endl;
		}
	}//cout<<endl;
	//cout<<"ydr"<<endl;
	for(int i=0;i<rsize;i++){
		if((double)(+(double)yright[i].fx() -(double)(((double)arrx[pvt].fx()+(double)arrx[pvt+1].fx())/2 )) <= del ){
			cdr++;
			ydr[cdr].sx(yright[i].fx());ydr[cdr].sy(yright[i].fy());
			//cout<<yright[i].fx()<<" "<<yright[i].fy()<<endl;
		}
	}//cout<<endl;
	double dist=del;
	//cout<<cdl<<" "<<cdr<<endl<<endl<<endl;
	int mark=0;

	// left traversing
	for(int i=0;i<=cdl;i++){

		while(1){
			if((double)ydr[mark].fy() < (double)ydl[i].fy() - del && mark<=cdr){
				mark++;
			}else{
				break;
			}
		}

		for(int j=mark;j<mark+6 && j<=cdr;j++){
			if((double)ydr[j].fy() <= (double)ydl[i].fy() + del && (double)ydr[j].fy() >= (double)ydl[i].fy() - del){
					if( dis(ydl[i],ydr[j]) < dist){
					dist=dis(ydl[i],ydr[j]);//cout<<"updated"<<i<<" 2 "<<j<<" "<<dis(ydl[i],ydr[j])<<endl;
					final.sv(ydl[i].fx(),ydl[i].fy(),ydr[j].fx(),ydr[j].fy());
				}
				}else{
					break;
				}
		}
	}

	// right traversing
	mark=0;
	int i=0;
	while(i<=cdr){

		while(1){
			if((double)ydl[mark].fy() < (double)ydr[i].fy() - del && mark<=cdl){
				mark++;
			}else{
				break;
			}
		}

		for(int j=mark;j<mark+6 && j<=cdl;j++){
			if((double)ydl[j].fy() <= (double)ydr[i].fy() + del && (double)ydl[j].fy() >= (double)ydr[i].fy() - del){
					if( dis(ydl[j],ydr[i]) < dist){
					
					dist=dis(ydl[j],ydr[i]);//cout<<"updated "<<i<<" 1 "<<j<<" "<<dis(ydl[j],ydr[i])<<endl;
					final.sv(ydl[j].fx(),ydl[j].fy(),ydr[i].fx(),ydr[i].fy());
				}
				}else{
					break;
				}
		}
		i++;
	}

		return final;
		
}
}
	
	
};

class solution
{	int t;
	pr *arrx;pr *arry;
public:
	solution(int a,char c){
		t=a;
		arrx=new pr[t];
		arry=new pr[t];
		cout<<endl;
		for(int i=0;i<t;i++){
			arrx[i].sx(100*((double)rand()/RAND_MAX));
			arrx[i].sy(100*((double)rand()/RAND_MAX));
			arry[i].sx(arrx[i].fx());
			arry[i].sy(arrx[i].fy());
			if(c=='y'){
				cout<<arrx[i].fx()<<"    "<<arrx[i].fy()<<endl;
			}
		}
		main mn;
		mn.qsx(arrx,0,t-1);
		mn.qsy(arry,0,t-1);
		 
	ans_pair last=mn.solve(arrx,0,t-1,arry);
	cout<<endl<<"Closest points are: ("<<last.gx1()<<" , "<<last.gy1()<<") and ("<<last.gx2()<<" , "<<last.gy2()<<")"<<endl;
	cout<<endl<<"The distance between them is "<< last.dst()<<endl;

	}
	~solution(){
		delete[] arrx;
		delete[] arry;
	}
	
};
 
int main(){
	srand(time(NULL));
	cout<<"Enter the no. of points you want to generate randomly?"<<endl;
	int t;cin>>t;
	cout<<"Do You want to see the points randomly generated(y/n)?"<<endl;
	char c;cin>>c;
	
	clock_t start=clock();
	solution finalans(t,c);
	clock_t end=clock();
	cout<<endl<<"Time elapsed is "<<fixed<<setprecision(8)<<1000*((double)(end-start))/CLOCKS_PER_SEC<<" ms"<<endl<<endl;

return 0;
}
