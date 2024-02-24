#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main(int argc,char *argv[]){
  if(argc!=6){
    cout<<"Invalid length of arguments";
    return 0;
  }
  vector<vector<int> > result;
  int ans=0,ans1=0,ans2=0,ans3=0;
  for(int i=1;i<argc;i++){
    if(i==1){
    string s = argv[i];
    ifstream st(s);
    while(getline(st,s)){
      vector<int> a;
    //   int lr = 0;
      string s1;
      stringstream srt(s);
      while(srt>>s1){
        a.push_back(stoi(s1));
      }
      result.push_back(a);
    }
  }
  else{
    string f1=argv[i];
    if(f1=="Bt"){ans=1;}
    else if(f1=="Gt"){ans1=1;}
    else if(f1=="Ct"){ans2=1;}
    else if(f1=="Ft"){ans3=1;}
  }
}

  int barray[2]={0};
  int garray[2][2]={0};
  int carray[2]={0};
  int farray[2][2][2]={0};
  double bprob[2];
  double gprob[2][2];
  double cprob[2];
  double fprob[2][2][2];
  double tp[2][2][2][2];
  for(int l=0;l<result.size();l++){
    barray[result[l][0]]++;
    garray[result[l][0]][result[l][1]]++;

  }
  for(int l=0;l<result.size();l++){
    carray[result[l][2]]++;
  }
  for(int i=0;i<result.size();i++){
    farray[result[i][1]][result[i][2]][result[i][3]]++;
  }
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        gprob[i][j] = garray[i][j]/(float)barray[i];
    }
  }
    for(int i=0;i<2;i++){
      bprob[i] = barray[i]/(float)result.size();
    }
    for(int i=0;i<2;i++){
      cprob[i] = carray[i]/(float)result.size();
    }
      for(int j=0;j<2;j++){
        for(int k=0;k<2;k++){
        double ans=0;
        for(int l=0;l<2;l++){
          ans+=farray[j][k][l];
        }
        fprob[j][k][0] = farray[j][k][0]/ans;
        fprob[j][k][1] = farray[j][k][1]/ans;
    }
    }
    // cout<<ans<<ans1<<ans2<<ans3;
    int r=2;
    for(int i=0;i<r;i++){ for(int j=0;j<2;j++){for(int k=0;k<r;k++){
      for(int l=0;l<r;l++){tp[i][j][k][l] = bprob[i]*cprob[k]*gprob[i][j]*fprob[j][k][l];}
    }}}
    cout<<tp[ans][ans1][ans2][ans3];
    return 0;
}
