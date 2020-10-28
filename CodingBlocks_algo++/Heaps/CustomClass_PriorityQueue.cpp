#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Person{
	public:
		string name;
		int age;
		Person(string n,int age){
			name = n;
			this->age = age;
		}
};

class PersonCompare{
	public:
		bool operator()(Person A,Person B){
			return A.age<B.age;
		}
};

int main(){
   priority_queue<Person,vector<Person>,PersonCompare> pq;
   int n;
   cin>>n;
   while(n--){
      string name;
      int age;
      cin>>name>>age;
      Person p(name,age);
      pq.push(p);
   }
   int k = 3;
   while(k--){
       cout<<pq.top().name<<" "<<pq.top().age<<endl;
       pq.pop();
   }
   return 0;
}
