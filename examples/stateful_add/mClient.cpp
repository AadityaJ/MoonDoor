#include "includes/mClient.h"
using namespace std;
int main(int argc, char const *argv[])
{
	while(1){
		Client c(90190);
		int a,b;
		cin>>a>>b;
		string snd=to_string(a)+","+to_string(b);
		c.Send(snd);
		cout<<c.receive()<<endl;
	}
	return 0;
}
