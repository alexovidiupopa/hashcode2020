
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <fstream>

using namespace std;

typedef struct library {
	int n, t, m;
	vector<int> bookIds;
	int libraryId;
	int signupdone;
};

typedef struct aiabuna {
	int k, y;
	vector<int> chestii;
};
int b, L, d;
vector<int> bookScores;
vector<library*> libraries;
unordered_map<int, bool> markedBooks;
int startday;
int a;
int k;
int y;
vector<aiabuna*> deprintat;
int main()
{
	ifstream f("f.txt");
	ofstream g("f1.txt");
	f >> b >> L >> d;
	vector<int> freq(b);
	for (int i = 0; i < b; i++) {
		int s;
		f >> s;
		freq[i] = 0;
		bookScores.push_back(s);
	}	
	for (int i = 0; i < L; i++) {
		library* lib = new library();
		int n, t, m;
		f >> n >> t >> m;
		lib->n = n;
		lib->t = t;
		lib->m = m;
		lib->libraryId = i;
		for (int j = 0; j < n; j++) {
			int id;
			f >> id;
			lib->bookIds.push_back(id);
			freq[id]++;
		}
		sort(lib->bookIds.begin(), lib->bookIds.end(),
			[](int b1, int b2) {
			return bookScores[b1] > bookScores[b2];
		});
		libraries.push_back(lib);
	}
	sort(libraries.begin(), libraries.end(), [](library* l1, library* l2) {
		/*if (l1->t == l2->t) {
			if(l1->m==l2->m)
				return l1->n > l2->n;
			return l1->m > l2->m;
		}*/
		return l1->t < l2->t;	
	});


	for (auto lib : libraries) {
		startday += lib->t;
		lib->signupdone = startday;
	}
	for (auto lib : libraries) {
		y = lib->libraryId;
		int howmany = (d - lib->signupdone)*lib->m;
		if (howmany < 0)
			k = lib->n;
		else
			k = min(howmany, lib->n);
		vector<int> toPrintSimplu;
		for (int j = 0, i = 0; j < lib->n && i < k; j++)
		{
			int id = lib->bookIds[j];
			if (markedBooks.find(id) == markedBooks.end() || !markedBooks[id]) {
				toPrintSimplu.push_back(id);
				markedBooks[id] = true;
				i++;
			}

		}
		k = toPrintSimplu.size();
		if (k > 0 && lib->signupdone <= d)
		{
			aiabuna* ceva = new aiabuna();
			ceva->chestii = toPrintSimplu;
			ceva->k = k;
			ceva->y = y;
			deprintat.push_back(ceva);
		}
		else break;


	}
	g << deprintat.size() << endl; 
	for (auto print : deprintat) {
		g << print->y << " " << print->k << endl;
		for (auto x : print->chestii)
			g << x << " ";
		g << endl;
	}

	return 0;
}
