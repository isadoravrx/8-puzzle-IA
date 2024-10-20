#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int> >ans(3,vector<int>(3));
bool b = false;
map<vector<vector<int> >, int>mp;

void swap(vector<vector<int> >&v, int i1, int j1, int i2, int j2){
    int temp = v[i1][j1];
    v[i1][j1] = v[i2][j2];
    v[i2][j2] = temp;
}

void dfs(vector<vector<int> >&v, int i, int j, int cont, int maxcont){
    if(mp.find(v) != mp.end()){
        return;
    }

    if(v == ans){
        b = true;
        return;
    }

    if(cont == maxcont){
        return;
    }

    mp[v] = 1;
    if(i > 0){//cima
        swap(v,i-1,j,i,j);
        dfs(v,i-1,j,cont+1,maxcont);
        swap(v,i,j,i-1,j);
    }

    if(i < ans.size() - 1){ //baixo
        swap(v,i+1,j,i,j);
        dfs(v,i+1,j,cont+1,maxcont);
        swap(v,i,j,i+1,j);
    }

    if(j > 0){//esq
        swap(v,i,j-1,i,j);
        dfs(v,i,j-1, cont+1, maxcont);
        swap(v,i,j,i,j-1);
    }

    if(j < ans[0].size() - 1){ //dir
        swap(v,i,j+1,i,j);
        dfs(v,i,j+1, cont+1, maxcont);
        swap(v,i,j,i,j+1);
    }
}

int main(){
    cout << "Enter the matrix numbers:" << endl;
    vector<vector<int> >v(3,vector<int>(3));

    int xindexzero = 0;
    int yindexzero = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int num;
            cin >> num;
            v[i][j] = num;
            
            if(num == 0){
                xindexzero = i;
                yindexzero = j;
            }
        }
    }

    
    int cont =  1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(cont == 9){
                cont = 0;
            }
            ans[i][j] = cont;
            cont++;
        }
    }

    
    for(int i = 0; i < 10e9; i++){
        dfs(v, xindexzero, yindexzero, 0, i);
        mp.clear();
        
        if(b){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cout << ans[i][j] << " ";
                }

                cout << endl;
            }
            break;
        }else{
            cout << "It does not have answer for l = "  << i << endl;
        }
    }
        
}