#include <iostream>
#include <fstream>
#define NMAX 100

using namespace std;

int adc[NMAX][NMAX];
int coada[NMAX];
bool viz[NMAX];
int n, m;

void citire()
{
	int i, a, b;
	ifstream fin("data.in");
	fin >> n >> m;
	for (i = 0; i < m; i++)
	{
		fin >> a >> b;
		adc[a][b] = 1;
		adc[b][a] = 1;
	}

	fin.close();
}

void DFS(int nod)
{
	int i;
	viz[nod] = true;
	for (i = 0; i < n; i++)
	{
		if (adc[nod][i] == 1 && viz[i] == false)
		{
			DFS(i);
		}
	}
	cout << nod << " ";
}

void BFS(int nod)
{
	int st = 0, fn = 1;
	int i;
	int nod_crt;
	coada[0] = nod;
	viz[nod] = 1;

	while (st < fn)
	{
		nod_crt = coada[st];
		st++;
		cout << nod_crt << ' ';
		for (i = 0; i < n; i++)
		{
			if (adc[nod_crt][i] && viz[i] == 0)
			{
				viz[i] = 1;
				coada[fn] = i;
				fn++;
			}
		}
	}
}

int main()
{
	cout << "PANDAAA" << endl;

	citire();
	DFS(0);
	cout << endl;
	memset(viz, 0, NMAX);
	BFS(0);

	return 0;
}