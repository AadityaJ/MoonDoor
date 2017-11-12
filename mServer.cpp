#include "includes/mServer.h"
#include "includes/state.h"
#include <utility>
using namespace std;
class myClass{
public:
	int a;
	int b;
	myClass(int a,int b){
		this->a=a;
		this->b=b;
	}
	string to_str(){
		return to_string(this->a)+","+to_string(this->b);
	}
	int add(){
		return this->a+this->b;
	}
};
pair<string,string> split(string a){
	string temp1="",temp2="";
	int i=0;
	for(;a[i]!=',';i++){temp1.push_back(a[i]);}
	i++;
	for(;i!=a.length();i++){temp2.push_back(a[i]);}
	return make_pair(temp1,temp2);
}
int main(int argc , char *argv[]){
	Server s;
	state<myClass,int> st;
	s.listen_(90190);
	string val;
	while(1){
		int ans;
		val=s.receive();
		pair<string,string> pr=split(val);
		myClass mc(stoi(pr.first),stoi(pr.second));
		int ptr=st.seek(mc);
		if(ptr==NULL){
			//cout<<"Not in cache\n";
			ans=mc.add();
			st.add(mc,ans);
		}else{
			//cout<<"In cache\n";
			ans=ptr;
		}
		s.send_(to_string(ans));
	}
    return 0;
}
