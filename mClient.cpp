#include "includes/mClient.h"

using namespace std;
int main(int argc, char const *argv[])
{
	Client c(90190);
	c.Send("abc");
	cout<<c.receive()<<endl;
	return 0;
}