/*Write a program in C++ to use map associative container. The keys will be the names of states 
and the values will be the populations of the states. When the program runs, the user is prompted 
to type the name of a state. The program then looks in the map, using the state name as an 
index and returns the population of the state
*/
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
typedef map<string, int> mapType;

mapType populationMap; //create an empty map
//insert elements in map
populationMap.insert(pair<string, long>("Maharashtra", 1231521145));
populationMap.insert(pair<string, long>("Gujrath", 5331521145));
populationMap.insert(pair<string, long>("Punjab", 7678552356));
populationMap.insert(pair<string, long>("Karnataka", 8955955854));
populationMap.insert(pair<string, long>("Tamilnadu", 564565465));

// iterator/index for map

mapType::iterator iter;

//Display the size of a map

cout<<"*** Population of states in India *****\n";
cout<< "\n *** Size of populationMap : "<< populationMap.size() << "\n";

//find will return an iterator to matching element if it is found
//or to the end of the map if the key is not found

string state_name;
cout<<"\n Enter state name : ";
cin>>state_name;

iter = populationMap.find(state_name);
if(iter != populationMap.end())
cout<<state_name<<"'s population is : "<<iter ->second;
else
cout<<"Key is not in populationMap"<<'\n';

// clear the entries of map using clear

populationMap.clear();

return 0;
}