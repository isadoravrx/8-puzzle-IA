#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int> >ans(3,vector<int>(3));
bool b = false;
map<vector<vector<int> >, int>mp;
vector<vector<int> >temp;

void swap(vector<vector<int> >&tempmatrix, int i1, int j1, int i2, int j2){
    int tempnumber = tempmatrix[i1][j1];
    tempmatrix[i1][j1] = tempmatrix[i2][j2];
    tempmatrix[i2][j2] = tempnumber;
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

    temp = v;
    
    if(i > 0){//cima
        swap(temp,i-1,j,i,j);
        dfs(temp,i-1,j,cont+1,maxcont);
        swap(temp,i,j,i-1,j);
    }

    if(i < ans.size() - 1){ //baixo
        swap(temp,i+1,j,i,j);
        dfs(temp,i+1,j,cont+1,maxcont);
        swap(temp,i,j,i+1,j);
    }

    if(j > 0){//esq
        swap(temp,i,j-1,i,j);
        dfs(temp,i,j-1, cont+1, maxcont);
        swap(temp,i,j,i,j-1);
    }

    if(j < ans[0].size() - 1){ //dir
        swap(temp,i,j+1,i,j);
        dfs(temp,i,j+1, cont+1, maxcont);
        swap(temp,i,j,i,j+1);
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