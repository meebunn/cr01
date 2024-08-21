#include <bits/stdc++.h>
using namespace std;

int n,m,parentS[100100],rankS[100100];

vector<pair<int,int>> edges;
vector<int> edge_weights;
vector<pair<int,int>> Sortededges;


int findS(int u){
  if(parentS[u] == u) 
    return u;
  else 
    return findS(parentS[u]);
}


void UnionS(int pu, int pv)
{
  pu = findS(pu);
  pv = findS(pv);

  if(pu == pv)
    return;

  if(rankS[pv] > rankS[pu]) 
    parentS[pu] = pv;
  
  else if(rankS[pu] > rankS[pv]) 
    parentS[pv] = pu;
  
  else 
    parentS[pv] = pu;
    rankS[pu]++;
  
}


int main() {
    
    cin >> n >> m;
  

    for(int i=0; i<n; i++) {
      parentS[i] = i;
      rankS[i] =0;
    }
    
    for(int i=0; i<m; i++) {
        int a,b,w,connect;
        cin >> a >> b >> w >> connect;   a--; b--;

        edges.push_back(make_pair(a,b));

        if(!connect){

            Sortededges.push_back(make_pair(w,i));
        }
        else{
            if(findS(a) != findS(b)){
                UnionS(a,b) ; 
            }
        }
    }

    sort(Sortededges.begin(),Sortededges.end()) ;

    int sum= 0; 
    for(int i = 0 ; i<Sortededges.size(); i++){

        int e = Sortededges[i].second;
        int u = edges[e].first;
        int v = edges[e].second;
        int w = Sortededges[i].first;

        int pu = findS(u);
        int pv = findS(v);
        if(pu!=pv) {
            sum+= w ; 
            /// connect
            UnionS(pu,pv) ;
        }
    }

    cout << sum << endl;
}