#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
const int mod=1e9+7;

int n,m,q,h[N],ar[N];
int cnt[N],eq,present;
bool ans[N];

struct query{int l,r,id;} qq[N];
const int SZ=400;

void add(int &c){
      if(cnt[c]==h[c]) eq--;
      cnt[c]++;
      if(cnt[c]==h[c]) eq++;
      if(cnt[c]==1) present++;
}

void remove(int &c){
      if(cnt[c]==h[c]) eq--;
      cnt[c]--;
      if(cnt[c]==h[c]) eq++;
      if(!cnt[c]) present--;
}

bool comp(int a, int b){
      // should be actually l-1/SZ but since only comp! can work
      if(qq[a].l/SZ==qq[b].l/SZ) return qq[a].r<qq[b].r;
      return qq[a].l/SZ<qq[b].l/SZ;
}

void mos(){
      vector<int> qids;
      for(int i=0;i<q;i++) qids.push_back(i);
      sort(qids.begin(),qids.end(),comp);

      int mosl=1,mosr=0;
      for(auto &i:qids){
            // not guranteed that during the iteration mosl<mosr always!
            // but the end of the query it will be!
            while(mosl<qq[i].l) remove(ar[mosl++]);
            while(mosl>qq[i].l) add(ar[--mosl]);
            while(mosr<qq[i].r) add(ar[++mosr]);
            while(mosr>qq[i].r) remove(ar[mosr--]);
            ans[qq[i].id]=(eq==present);
      }
}

int main(){

      scanf("%d %d",&n,&m);
      for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
      for(int i=1;i<=m;i++) scanf("%d",&h[i]);

      scanf("%d",&q);
      for(int i=0;i<q;i++){
            scanf("%d %d",&qq[i].l,&qq[i].r);
            qq[i].id=i;
      }     
      mos();
      for(int i=0;i<q;i++) printf("%d\n",ans[i]);
      return 0;
}