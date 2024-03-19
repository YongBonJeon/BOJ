#include <stdio.h>
int main() {
	int cnt, n, m;
	int i, j, k;
	int arr[100] = { 0, };
 
	scanf("%d", &cnt);
 
	for (i = 0; i < cnt; i++)
	{
		scanf("%d %d", &n, &m);
		int ans = 1;
		int front = 0;
		int max = 0;
		for (j = 0; j < n; j++)
			scanf("%d", &arr[j]);
 
		while (1) 
		{
			for (k = 0; k < n; k++) {
				if (arr[k] > max) max = arr[k];
			}
 
			while (arr[front] != max)
				front = (front + 1) % n;
 
			if (front == m) break;
 
			arr[front] = 0;
			front = (front + 1) % n;
			max = 0;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}