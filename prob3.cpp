#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main(){
	int p,s;
	cin>>p>>s;
	vector< pair<int,int> > table[p];
	for(int i=0;i<p;i++){
		vector<int> score;
		vector<int> solved;
		for(int j=0;j<s;j++){
			int a;
			cin>>a;
			score.push_back(a);
		}
		for(int j=0;j<s;j++){
			int a;
			cin>>a;
			solved.push_back(a);
		}
		for(int j=0;j<s;j++){
			table[i].push_back(make_pair(score[j],solved[j]));
		}
	}
	for(int i=0;i<p;i++){
		sort(table[i].begin(),table[i].end());
	}
	vector<pair<int,int> > difficulty;
	for(int i=0;i<p;i++){
		int count = 0;
		for(int j=0;j<s-1;j++){
			if(table[i][j].second>table[i][j+1].second){
				count++;
			}
		}
		difficulty.push_back(make_pair(count,i));
	}
	sort(difficulty.begin(),difficulty.end(),sortbysec);
	stable_sort(difficulty.begin(),difficulty.end());
	for(int i=0;i<p;i++){
		cout<<difficulty[i].second+1<<"\n";
	}
}