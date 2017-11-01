#include <iostream>
#include <stdint.h>

#define MAX 111000

long long nums[MAX];

long long tab[MAX][3];

void fill_row_rev(long long n, int row, size_t len)
{
	long long best_seen = nums[len-1];
	for(int i = len-1; i >= 0; i-- ) {
		if(n >= 0 ) {
			if(nums[i] > best_seen)
				best_seen = nums[i];
		} else {
			if(nums[i] < best_seen)
				best_seen = nums[i];
		}

		tab[i][row] = best_seen * n;
	}
}

void fill_row(int64_t n, int row, size_t len)
{
	long long best_seen = nums[0];
	for(int i = 0; i < len; i++ ) {
		if(n >= 0 ) {
			if(nums[i] > best_seen)
				best_seen = nums[i];
		} else {
			if(nums[i] < best_seen)
				best_seen = nums[i];
		}

		tab[i][row] = best_seen * n;
	}
}

int main()
{
	int p, q, r, N;
	long long max;

	
	//scanf("%d %d %d %d", &N, &p, &q, &r);
	std::cin >> N >> p >> q >> r;
	for(int i = 0; i < N; i++ ) {
		 std::cin >> nums[i];
	}

	fill_row(p, 0, N);
	fill_row_rev(r, 2, N);

	max = tab[0][2] + tab[0][0] + q*nums[0];

	for(int i = 0; i < N; i++) {
		long long curr = tab[i][0] + tab[i][2] + q*nums[i];	
		max = max > curr ? max : curr;
		//printf("%ld %ld \n", tab[i][0], tab[i][2]);
	}

	//printf("%lld\n", max);
	std::cout << max << std::endl;

	return 0;
}
