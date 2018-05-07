#pragma once
#include <iostream>
#include <queue>
#include <fstream>

class Graph
{
private:
	int soDinh;
	bool *chuaxet;
	int *danhdauTruoc;
	int **dinh;
	std::queue<int> Q;

public:
	Graph(int);
	~Graph();
	void bfs(int);
	void result(std::ofstream&, int, int);
};

