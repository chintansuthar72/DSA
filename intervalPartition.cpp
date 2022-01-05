#include<bits/stdc++.h>
using namespace std;

unsigned main(){
    int n,depth=0;
    cin >> n;
    vector<vector<int>> job(n);
    for(int i=0; i<n; ++i){
        int s,f;
        cin >> s >> f;
        p_job[i] = {s,f};
    } 
    sort(job.begin(),job.end());
    vector<stack<vector<int>>> part(n);
    part[0].push(job[0]);
    depth++;
    for(int i=1; i<n; ++i){
        int j = 0;
        for(; j<depth; ++j){
            vector<int> interval = part[j].top();
            if(isCompitable(interval,job[i])){
                
            }
        }
        if(j == depth){

        }
    }    
}