#include "Graph.h"

int main(int argc, char *argv[])
{
	std::ifstream in(argv[1]);
	std::ofstream out(argv[2]);

	int soDinh = 0;
	int dinhBatDau,
		dinhKetThuc;
	in >> soDinh;
	in >> dinhBatDau >> dinhKetThuc;

	//BFS tim duong di tu start to end
	Graph g(soDinh);
	g.bfs(dinhBatDau);
	g.result(out, dinhBatDau, dinhKetThuc);

	return 0;
}