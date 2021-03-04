#include <bits/stdc++.h> 
using namespace std; 
  
struct Point
{ 
    int x; 
    int y; 
};


bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 


int getLength(long long value) {
	int counter = 0;
	while (value != 0) {
		counter++;
		value /= 10;
	}
	return counter;
}

long multiply(long x, long y) {
	int xLength = getLength(x);
	int yLength = getLength(y);

	// the bigger of the two lengths
	int N = (int)(fmax(xLength, yLength));

	// if the max length is small it's faster to just flat out multiply the two nums
	if (N < 10)
		return x * y;

	//max length divided and rounded up
	N = (N/2) + (N%2);

	long multiplier = pow(10, N);

	long b = x/multiplier;
	long a = x - (b * multiplier);
	long d = y / multiplier;
	long c = y - (d * N);

	long z0 = multiply(a,c);
	long z1 = multiply(a + b, c + d);
	long z2 = multiply(b, d);


    return z0 + ((z1 - z0 - z2) * multiplier) + (z2 * (long)(pow(10, 2 * N)));

}

// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(Point p, Point q, Point r) 
{
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
    // General case 
    if (o1 != o2 && o3 != o4)
    {
        return true;
    }
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    // if (o1 == 0 && onSegment(p1, p2, q1)) return false; 
  
    // // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    // if (o2 == 0 && onSegment(p1, q2, q1)) return false;
  
    // // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    // if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
    //  // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    // if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
}


int main() 
{ 
    struct Point p1,q1,p2,q2; 
    long T=0,i=0,N=0,Q=0,x1=0,j=0,x2=0,y=0,count=0;
    cin>>T;
    while(T>0)
    {
        N=0,Q=0,x1=0,x2=0,y=0;
        cin>>N>>Q;
        long A[N];
        for(i=0;i<N;i++)
        {
            cin>>A[i];
        }
        for(i=0;i<Q;i++)
        {
            cin>>x1>>x2>>y;
            // count=0;
            for(j=0;j<N-1;j++)
            {
                p1 = {j+1,A[j]};
                q1 = {j+2,A[j+1]};
                p2 = {x1,y};
                q2 = {x2,y};
                if (doIntersect(p1, q1, p2, q2))
                    if ((p1.x!=q2.x || p1.y!=q2.y) && (p2.x!=q1.x || p2.y!=q1.y))
                        count++;
            }
            cout<<count<<"\n";
        }
        T--;
    }
    return 0; 
}