#include <stdio.h>
#include <string>
#include <set>


int main()
{
	int N;
	std::set<std::string> names;

	scanf("%d", &N);
	while(N--) {
		char name[500];

		scanf("%s", &name);
		if(names.find(std::string(name)) == names.end()) {
			names.insert(name);
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}
