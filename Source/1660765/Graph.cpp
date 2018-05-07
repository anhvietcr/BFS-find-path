#include "Graph.h"


Graph::Graph(int _soDinh)
{
	//so dinh cua do thi
	this->soDinh = _soDinh;

	//init mang danh dau va chua xet
	this->chuaxet = new bool[this->soDinh];
	this->danhdauTruoc = new int[this->soDinh];
	for (int i = 0; i < this->soDinh; i++) {
		this->danhdauTruoc[i] = 0;
		this->chuaxet[i] = true;
	}

	//init matrix
	this->dinh = new int*[this->soDinh];
	for (int i = 0; i < this->soDinh; i++) {
		dinh[i] = new int[this->soDinh];
	}
}

Graph::~Graph()
{
}

void Graph::bfs(int start)
{
	Q.push(start);	//them dinh dau tien vao queue
	chuaxet[start] = false; //xet dinh dau tien la chua xet

	while (!Q.empty()) {
		//trong khi queue khong rong thi tiep tuc
		int u = Q.front(); Q.pop();
		
		//duyet qua tat ca cac canh ma u di qua
		for (int i = 0; i < soDinh; i++) {
			if (dinh[u][i] && chuaxet[i]) {
				Q.push(i);
				chuaxet[i] = false;
				danhdauTruoc[i] = u;
			}
		}
	}
}

void Graph::result(std::ofstream& out, int start, int end)
{
	if (0 == danhdauTruoc[end]) {
		out << "NULL";
		return;
	}
	out << end << " ";
	int t = end;
	while (danhdauTruoc[t] != start) {
		out << danhdauTruoc[t] << " ";
		t = danhdauTruoc[t];
	}

	out << start;
}