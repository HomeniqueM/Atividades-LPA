#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#include<vector>

using namespace std;


struct subway{
	int i, j, w;
	subway() {}
	subway( int I, int J, int W ): i(I), j(J), w(W) {}
	bool operator < ( const subway& e ) const {
		return w > e.w;
	}
};


map<string, int> id;
priority_queue<subway> priority;
vector<pair<int, int> > adj[405];

int n, s, p, x, subwarray[405];



int find( int X ){
	return subwarray[X] == -1 ? X : subwarray[X] = find( subwarray[X] );
}

int Kruskals(){
    
	n = s;
	
	if( s <= 1 ) return 0;
	int ans = 0;
	memset( subwarray, -1, sizeof subwarray );

	while( !priority.empty() ){
		int a = find( priority.top().i );
		int b = find( priority.top().j );
		if( a != b ){
			subwarray[a] = b;
			ans += priority.top().w;
			if( --s <= 1 ) return ans;

		}
		priority.pop();
	}
	return -1;
}


int main(){
    
string sub01,sub02;


	while( scanf("%d %d", &s, &p) == 2 && ( s || p ) ){
		id.clear();
		for( int i=0; i<s; ++i ){
			cin >>  sub01 ;
			id[sub01] = i;
		}
		priority = priority_queue<subway>();
		for( int i = 0 ; i< p ; ++i ){

			cin >> sub01>> sub02>> x ;
			int a = id[sub01];
			int b = id[sub02];
			priority.push( subway(a, b, x) );
		}
		cin >> sub01;
		int ans = Kruskals();

		if( ans == -1 ){
             puts("Impossible");
             }
		else{
			cout << ans << endl;
		}
	}
}