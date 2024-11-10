/*
Disjoint Set Union (DSU) or Union-Find is a graph algorithm that is very useful in
 situations when you have to determine the connected components in a graph.
  It's also known as Union-Find
*/

int find(int A[],int x) {
       if(A[x] == x)
        return x;
        
        return A[x] = find(A, A[x]); //This is Path compression
}
void unionSet(int A[],int X,int Z){
	int x = find(A, X);
	int y = find(A, Z);
	
	if(x == y)
	    return;
	
	A[x] = y;
}