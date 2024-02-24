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
  if(argc>2 or argc==1){
    cout<<"Invalid length of arguments";
  }
  vector<vector<int> > result;
  for(int i=1;i<argc;i++){
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

  int barray[2]={0};
  int garray[2][2]={0};
  int carray[2]={0};
  int farray[2][2][2]={0};
  double bprob[2];
  double gprob[2][2];
  double cprob[2];
  double fprob[2][2][2];
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
    cout<<"B: "<<bprob[0]<<" "<<bprob[1]<<"\n";
    cout<<"G: "<<gprob[0][0]<<" "<<gprob[0][1]<<" "<<gprob[1][0]<<" "<<gprob[1][1]<<"\n";
    cout<<"C: "<<cprob[0]<<" "<<cprob[1]<<"\n";
    cout<<"F: ";
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        for(int k=0;k<2;k++){
          cout<<fprob[i][j][k]<<" ";
        }
        cout<<"\n";
      }
    }
    return 0;
}
