#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
};
int orientation(point p1,point p2,point p3)
{
    int val=((p2.y-p1.y)*(p3.x-p2.x))-((p3.y-p2.y)*(p2.x-p1.x));
    if(val==0)return 0;
    if(val>0)return 1;
    else return 2;
}
bool validprojection(int a,int b,int c,int d)
{
    if(a>b)swap(a,b);
    if(c>d)swap(c,d);
    return max(a,c)<=min(b,d);
}
bool intersect(point a,point b,point c,point d)
{
    int o1=orientation(a,b,c);
    int o2=orientation(a,b,d);
    int o3=orientation(c,d,a);
    int o4=orientation(c,d,b);
    if(o1!=o2 && o2!=o3)return true;
    if(o1==0 && o4==0)
    {
        if(validprojection(a.x,b.x,c.x,d.x) && validprojection(a.y,b.y,c.y,d.y))
            return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    while(n--){
    point p1,p2,p3,p4;
    cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y;
    if(intersect(p1,p2,p3,p4)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    }
}