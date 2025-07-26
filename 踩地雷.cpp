#include <bits/stdc++.h>
#include <string>
using namespace std;
int dx[8]={-1,0,1,-1,1,-1,0,1};
int dy[8]={1,1,1,0,0,-1,-1,-1};
bool v[10][10]={0},vs[10][10]={false},vf[10][10]={false};
char m[10][10]={0};
queue<pair<int,int> >q;
int cf=0;
bool isnumber(string s){
    for(int i=0;i<s.size();i++){
        if(!isdigit(s[i]))
            return false;
    }
    return true;
}
void bfs(int x,int y){
    if(vf[x][y]){
        vf[x][y]=false;
        cf--;
        }
    v[x][y]=true;
    vs[x][y]=true;
    q.push({x,y});
    while(!q.empty()){
        int cx=q.front().first,cy=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nx=cx+dx[i],ny=cy+dy[i];
            if(nx<1||ny<1||nx>9||ny>9||m[nx][ny]=='X')
                continue;
            if(m[cx][cy]=='0'&&!v[nx][ny]){
                v[nx][ny]=true;
                vs[nx][ny]=true;
                q.push({nx,ny});
            }
        }

    }
}
int main(){
    srand(time(0));
    set<pair<int,int> > bomb;
    int a,b;
    string x1,y1,z;
    cout<<"��a�p"<<endl;
    cout<<"�@��10�T���u"<<endl;
    cout<<"�Ы��Ӯ榡��J�ux�y��(���ܥk1~9) y�y��(�U�ܤW1~9) �}�Ү�l(s)/�аO(f)/�����аO(c)�v"<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<"- ";
        }
        cout<<endl;
    }
    while(true){
        cin>>y1>>x1>>z;
        if(!isnumber(x1)||!isnumber(y1)){
            cout<<"��J���~"<<endl;
            continue;
        }
        int x=stoi( x1 ),y=stoi( y1 );
        if(x>9||x<1||y>9||y<1){
            cout<<"�W�X�d��"<<endl;
            continue;
        }
        if(z!="s"&&z!="f"&&z!="c"){
            cout<<"���O���~"<<endl;
            continue;
        }
        else break;
    }
    int x=stoi(x1),y=stoi(y1);
    int p=10-x,q=y;
    bomb.insert({p,q});
    while(bomb.size()<11){
        a=rand()%9+1;
        b=rand()%9+1;
        bomb.insert({a,b});
    }
    bomb.erase({p,q});
    for(auto i:bomb){
        m[i.first][i.second]='X';
    }
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            if(m[i][j]=='X')
            continue;
            int sum=0;
            for(int k=0;k<8;k++){
                int nx=i+dx[k],ny=j+dy[k];
                if(nx<1||ny<1||nx>9||ny>9)
                    continue;
                if(m[nx][ny]=='X')
                    sum++;
            }
            m[i][j]=sum+'0';
        }
    }
    do{
        if(!isnumber(y1)||!isnumber(x1)){
            cout<<"��J���~"<<endl;
            continue;
        }
        int x=stoi(x1),y=stoi(y1);
        x=10-x;
        if(x>9||x<=0||y>9||y<=0){
            cout<<"�W�X�d��"<<endl;
            continue;
        }
        if(z!="s"&&z!="f"&&z!="c"){
            cout<<"���O���~"<<endl;
            continue;
        }
        if(z=="s"){
            if(vs[x][y]==true){
                cout<<"���B�w�Q�}��"<<endl;
                continue;
            }
            if(m[x][y]=='X'){
                cout<<"Game Over"<<endl;
                for(int i=1;i<10;i++){
                   for(int j=1;j<10;j++){
                     cout<<m[i][j]<<" ";
                }
                   cout<<endl;
                 }
                return 0;
            }
            else if(m[x][y]=='0'){
                bfs(x,y);
            }
            else {
                v[x][y]=true,vs[x][y]=true;
                if(vf[x][y]){
                   vf[x][y]=false;
                   cf--;
                }
            }
        }
        else if(z=="f"){
            if(vf[x][y]){
                cout<<"���B�w�Q�аO"<<endl;
                continue;
            }
            if(vs[x][y]){
                cout<<"�L�k�b���B�аO"<<endl;
                continue;
            }
            cf++;
            vf[x][y]=true;
        }
        else if(z=="c"){
            if(!vf[x][y]){
                cout<<"�L�k�b���B�����аO"<<endl;
                continue;
            }
            cf--;
            vf[x][y]=false;
        }
        bool result=true;
        for(int i=1;i<10;i++){
            for(int j=1;j<10;j++){
                if(m[i][j] != 'X' && !vs[i][j]){
                    result=false;
                }
            }
        }

        if(result){
            cout<<"Win!!!"<<endl;
            for(int i=1;i<10;i++){
                   for(int j=1;j<10;j++){
                     cout<<m[i][j]<<" ";
                }
                   cout<<endl;
                 }
            return 0;
        }
        cout<<"f�аO�ƶq:"<<cf<<endl;
        for(int i=1;i<10;i++){
            for(int j=1;j<10;j++){
                if(vf[i][j]){
                    cout<<"f ";
                }
                else if(v[i][j]){
                    cout<<m[i][j]<<" ";
                }
                else cout<<"- ";
                }
                cout<<endl;
            }
        }while(cin>>y1>>x1>>z);
    }


