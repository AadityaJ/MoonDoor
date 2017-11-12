#include "../includes/mServer.h"
#include <unistd.h>
using namespace std;
int main(int argc, char const *argv[])
{
	Server s;
	s.listen_(8000);
	string str=s.receive();
	string cmd="g++ "+str;
	cout<<cmd<<endl;
	system(cmd.c_str());
	return 0;
}
