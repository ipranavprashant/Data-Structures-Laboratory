//using hashmaps
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
    int temp = k;
    int sum = 0;
    int ans[1000];
    int f = 0;
    int hashmap[1000];
    for (int i = 0; i < 1000; i++)
    {
        hashmap[i] = 0;
    }
    for (int i = 0; i <= n - k; i++)
    {
        int j = i;
        while (temp--)
        {
            hashmap[arr[j]] = 5;
            j++;
        }

        for (int m = 0; m < 1000; m++)
        {
            if (hashmap[m] == 5)
            {
                sum = sum + m;
            }
        }
        ans[f++] = sum;
        for (int n = 0; n < 1000; n++)
        {
            hashmap[n] = 0;
        }
        temp = k;
        sum = 0;
    }

    for (int i = 0; i < f; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
