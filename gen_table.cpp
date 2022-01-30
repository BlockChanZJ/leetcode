#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "LocalDebug.h"
#else
#define dbg(...) 42
#endif

using LL = long long;

int main() {
	int K = 1;
	int oldest = 1, newest = 4;
	string solved_bgcolor = "green";
	string unsolved_bgcolor = "gray";
	string font_color = "AntiqueWhite";
	auto get_bgcolor = [&](int id) {
		if (id <= newest)
			return solved_bgcolor;
		else 
			return unsolved_bgcolor;
	};
	for (int k = 0; k < K; k++) {
		printf("## %04d-%04d\n",k*100+1,k*100+100);
		int base = k * 100;
		printf("<table><tbody>\n");
		for (int i = 1; i <= 100; i++) {
			if (i % 10 == 1) {
				printf("<tr>\n");
				printf("  <td bgcolor=\"%s\"><font color=\"%s\">%04d<\/font></td>\n",get_bgcolor(base+i).c_str(),font_color.c_str(),base+i);
			} else if (i % 100 == 0) {
				printf("  <td bgcolor=\"%s\"><font color=\"%s\">%04d<\/font></td>\n",get_bgcolor(base+i).c_str(),font_color.c_str(),base+i);
				printf("<\/tr>\n");
			} else {
				printf("  <td bgcolor=\"%s\"><font color=\"%s\">%04d<\/font></td>\n",get_bgcolor(base+i).c_str(),font_color.c_str(),base+i);
			}
		}
		printf("<\/tbody><\/table>\n");
	}	
	return 0;
}
