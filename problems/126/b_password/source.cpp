#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX 10000000

//#undef DEBUG

char str [MAX];
size_t  nums[MAX];

void computeZ(const char* word, size_t* z, size_t len)
{
	size_t L, R;

	L = R = 0;

#ifdef DEBUG
	assert(word);
	assert(z);
#endif

	for(size_t i = 1; i < len; i++) {
		z[i] = 0;

		if(i > R) {
			L = R = i;
			while(R < len && word[R] == word[R-L])
				R++;
			R--;
			z[i] = R - i + 1;
		}
		else { // Somewhere exists match with at least one char
			size_t match = i - L;

			if(z[match] <= R - i) { // Nothing is happening
				z[i] = z[match];
			}
			else { // There is some new range
				L = R = i;
				while(R < len && word[R] == word[R-L])
					R++;
				R--;
				z[i] = R - i + 1;
			}
		}
	}
}

/*
 * Returns size of longest subsequnece, which is
 * 1. Prefix
 * 2. Suffix
 * 3. Neither prefix nor suffix
 */
size_t solve(const char* word, size_t len)
{
	size_t max = 0;

	computeZ(word, nums, len);
#ifdef DEBUG
	for(size_t i = 0; i < len; i++) {
		printf("%3ld,", nums[i]);
	}
	printf("\n");
#endif

	for(size_t i = 0; i < len; i++) {
		if(nums[i] == len - i && max >= len - i)
			return len - i;
		if(nums[i] > max)
			max = nums[i];
	}

	return 0;
}

int main()
{
	size_t suffix_len;

	scanf("%s", str);
	suffix_len = solve(str, strlen(str));

	if(suffix_len) {
		str[suffix_len] = '\0';
		printf("%s\n", str);
	} else {
		printf("Just a legend\n");
	}
	return 0;
}
