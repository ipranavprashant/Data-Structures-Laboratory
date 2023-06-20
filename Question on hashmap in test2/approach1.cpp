//using just the arrays
//time complexity: O(n*k)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }
    int k;
    cin >> k;
    int sum = 0;
    int ans[1000];
    int f = 0;
    for (int i = 0; i <= n - k; i++)
    {
        sum = 0;
        for (int j = i; j < i + k; j++)
        {
            sum += arr[j];
        }
        ans[f++] = sum;
    }
    if (k > n)
    {
        cout << "The value of k is greater than n however the max we can sum up is till n and here is the max sum: " << total << endl;
        return 0;
    }
    for (int i = 0; i < f; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
