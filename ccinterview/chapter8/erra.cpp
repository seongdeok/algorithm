#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <map>
typedef long long ll;
using namespace std;

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool iscounted(vector<int>& v, int num) {
    for (auto s : v) {
        if (num % s == 0)
            return true;
    }
    return false;
}
int getCount(int i, int n) {
    int num = 1;
    for (int a = 1; a < n; a++) {
        num *= i;
        if (num > n)
            return a - 1;
    }
}
int solve(int n, int k) {

    vector<int> v;
    for (int i = 2; i <= n; i++) {
        if (iscounted(v, i))
            continue;
        int cnt = getCount(i, n);
        if (k > cnt) {
            k -= cnt;
            v.push_back(i);
        } else {
            for (int j = i; j <= n; j += i) {
                if (!iscounted(v, j))
                    k--;
                if (k == 0) {
                    cout << j << endl;
                    return j;
                }
            }
        }
    }
    return -1;
}
int musik(int n, int k) {
    vector<int> v(n + 1, 0);
    int seq = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (v[j] == 0) {
                v[j] = 1;
                seq++;
                if (seq == k)
                    return j;
            }
        }
    }
}
struct LinkedList {
    int val;
    LinkedList* next;
};

int problem(int n, int k) {
    LinkedList* before = nullptr;
    LinkedList* head = nullptr;
    for (int i = 1; i <= n; i++) {
        LinkedList* cur = new LinkedList;
        cur->val = i;
        cur->next = nullptr;
        if (before)
            before->next = cur;
        else
            head = cur;
        before = cur;
    }
    int num = 2;
    while (k > 0) {
        LinkedList* temp = head;
        LinkedList* before = nullptr;
        while (temp) {
            if (temp->val % num == 0) {
                k--;
                if (k == 0)
                    return temp->val;

                before->next = temp->next;
                delete temp;
                temp = before->next;
            } else {
                before = temp;
                temp = temp->next;

            }
        }
        num++;
    }
}
bool prime[100001];
int solve2(int n, int k)
{
	int i,j;
	int cnt = 0;
	for (i = 2; i <= n; i++)
	{
		if (!prime[i])
		{
			prime[i] = true;
			cnt++;
			if (cnt == k)
			{
				printf("%d\n", i);
				return 0;
			}
			for (j = i + i; j <= n; j += i)
			{
				if (!prime[j]) 
				{
					prime[j] = true;
					cnt++;
					if (cnt == k)
					{
						printf("%d\n", j);
						return 0;
					}
				}
			}
		}
	}
}
int main() {
    //cin >> n >> k;
    //solve(n, k);
    for (int n = 100000; n <= 100000; n++) {
        for (int i = n-1; i < n; i++) {
            //int a = solve(n, i);
            //int b = musik(n, i);
//            problem(n, i);
solve2(n,i);
            //if (c != b)
            //    cout << "wrong" << i << "," << n << endl;
        }
    }
}

