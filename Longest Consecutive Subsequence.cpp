/*
We use set here

sab kuch ek ek karke set me daalo
set me already sab kuch sorted hota hai
And set ke andar saari values unique hoti hai

ab check karna hai consequtive elements ke liye to apan check karenge ki konsi value ek starting point 
ban sakti hai

apan unordered set use karenge bcoz uska search time jo hai vo o(1) hai average and set ka search time o(logn) jaayga


*/


#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n)
{
	unordered_set<int> S;
    int ans = 0;
    
    //set ko bharo ab
    for (int i = 0; i < n; i++)
    {
    	S.insert(arr[i]);
	}
	
	//ab array ko iterate karo
	for (int i = 0; i < n; i++)
    {
    	//check karo ki kya current element se chota koi element set me present hai
    	
    	//agar nahi hai, iska matlab ye element starting point hoga ek consequtive sequence ka
    	if (S.find(arr[i] - 1) == S.end())
        {
        	//ab dekho ki baaki elements bhi hai kya set me
        	int element = arr[i];               //NOTE: j koi index nhi hai, ek element hai
            while (S.find(element) != S.end())  //loop us j pe tootega jispe S.find(j) == S.end() ho jaaaye
                element++;
            
            //length update karte jaao
            cout<<"\n j-arr[i] => "<<element - arr[i];
            ans = max(ans, element - arr[i]);
		}
		
}
return ans;

}

// Driver code
int main()
{
    int arr[] = { 1, 9, 3, 10, 4, 20, 2 };
    int n = sizeof arr / sizeof arr[0];
    cout << "\nLength of the Longest contiguous subsequence "
            "is "
         << findLongestConseqSubseq(arr, n);
    return 0;
}
