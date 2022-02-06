#include <bits/stdc++.h>

using namespace std;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "LocalDebug.h"
#else
#define dbg(...) 42
#endif

using LL = long long;


set<int> solved_problems = {
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
	21, 22, 23, 24, 25, 
};

int main() {
	int K = 1;
	string solved_bgcolor = "green";
	string unsolved_bgcolor = "gray";
	string font_color = "AntiqueWhite";
	auto get_bgcolor = [&](int id) {
		if (solved_problems.count(id))
			return solved_bgcolor;
		else 
			return unsolved_bgcolor;
	};
	auto get_prob = [&](int id) {
		if (solved_problems.count(id)) {
			string s = ":heavy_check_mark:";
			return s;
		}
		else {
			string s;
			while (id) s.push_back(id%10+'0'), id/=10;
			while (s.size() < 4) s.push_back('0');
			reverse(s.begin(),s.end());
			return s;
		}
	};
	printf("# Leetcode\n");
	for (int k = 0; k < K; k++) {
		printf("## %04d-%04d\n",k*100+1,k*100+100);
		int base = k * 100;
		printf("<table><tbody>\n");
		for (int i = 1; i <= 100; i++) {
			if (i % 10 == 1) {
				printf("<tr>\n");
			}
			printf("  <td bgcolor=\"%s\"><font color=\"%s\">%s</font></td>\n",get_bgcolor(base+i).c_str(),font_color.c_str(),get_prob(base+i).c_str());
			if (i % 10 == 0) {
				printf("</tr>\n");
			}
		}
		printf("</tbody></table>\n");
	}	
	return 0;
}
