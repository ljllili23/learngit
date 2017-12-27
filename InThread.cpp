typedef struct{
	int a, b;
	int w;
}Road;

Road road[maxSize];
int v[maxSize];
int getRoot(int a){
	while(a!=v[a])a=v[a];
	return a;
}

void Kruskal (Mgraph &g, int &sum, Road road){
	int i;
	int N,E,a,b;
	N=g.n;
	E=g.e;
	sum=0;
	for(i=0;i<N;++i) v[i]=i;
	sort(road,E);
	for(i=0;i<E;++i){
		a=road[i].a;
		b=road[i].b;
		if(getRoot(a)!=getRoot(b)){
			v[a]=b;
			sum+=road[i].w;
		}
	}
}

void Dijkstra(MGraph g, int v, int dist[], int path[]){
	int set[maxSize];
	int min, i,j,u;
	for(i=0;i<g.n;++i){
		
	}
}