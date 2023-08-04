// Question: You are given two sorted arrays arr1 and arr2 in descending order. Your task is to merge these two arrays into a new array result using the merge sort technique, but Instead of merging the arrays in ascending order, you need to merge them in descending order to create the result array.
	 
// You cannot use stl sort function here
// Marks: 20



// Sample Input
// Sample Output
// 4
// 8 6 4 2	
// 4
// 7 5 3 1
// 8 7 6 5 4 3 2 1

#include<bits/stdc++.h>
using namespace std;


const int N=1e5+7;
int nums[N];

void merge(int l, int r, int mid)
{
	int left_size = mid-l+1;
	int L[left_size + 1];

	int right_size = r - mid;
	int R[right_size + 1];

	for(int i=l,j=0; i<=mid; i++,j++)
		L[j] = nums[i];

	for(int i=mid+1,j=0; i<=r; i++,j++)
		R[j] = nums[i];

	L[left_size] = INT_MIN; //infinity
	R[right_size] = INT_MIN;

	int lp=0,rp=0;
	for(int i=l; i<=r; i++)
	{
		if(R[rp] >= L[lp])
		{
			nums[i] = R[rp];
			rp++;
		}
		else
		{
			nums[i] = L[lp];
			lp++;
		}
	}
}


void mergesort(int l, int r)
{
	if(l==r)
		return;
	int mid = (l+r)/2;
	mergesort(l, mid);
	mergesort(mid+1, r);
	merge(l, r, mid);
}


int main(){
    int n;
    cin >> n;

    int arr1[n];

    for(int i=0;i<n;i++)
    {
    	cin >> arr1[i];
    }

    int m;
    cin >> m;

    int arr2[m];

    for(int i=0;i<m;i++)
    {
    	cin >> arr2[i];
    }

    for(int i=0;i<n;i++)
    {
    	nums[i] = arr1[i];
    }

    for(int i=0;i<m;i++)
    {
    	nums[n+i] = arr2[i];
    }

    mergesort(0, (n+m)-1);

    for(int i=0; i<n+m;i++)
    {
    	cout << nums[i] << " ";
    }
}