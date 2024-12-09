#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
using namespace std;

int main(){
  int n, nt;
  cout<<"Enter number of people: ";cin>> n;
  vector<string> people(n);
  string temp;
  cout<<"Enter names:\n";
  for(int i =0; i<n; i++){
    cin>>people[i];
  }
  cout<<"Enter total number of teams: ";cin>>nt;
  
  if(n/nt == 0){
    for (int i =0; i< people.size(); i++){
      cout<<people[i]<<"  ";
    }
    cout<<"\n";
    return 0;
  }
  int adder = 0, tadd = n%nt, npt = n/nt;
  if(tadd != 0){adder = 1;}
  cout<<"--> ";
  for(int i =0; i< (n/nt)+adder ; i=i+1){
    cout<< people[i]<<" ";
    people.erase(people.begin()+i);
  }
  cout<<"\n"; 
  nt--;tadd--;
  
  random_device rd;
  mt19937 gen(rd());
  shuffle(people.begin(), people.end(), gen);
  // for (int i =0; i< people.size(); i++){
  //   cout<<people[i]<<"  ";
  // }

  for (int i = 0; i < nt; i++) {
    cout<< "--> ";
    if(tadd <= 0){adder =0;}
    for(int k = 0; k< npt+adder; k++){
      cout<<people[0]<< " ";
      people.erase(people.begin());
      tadd--;
    }
    cout<<"\n";
  }
}
