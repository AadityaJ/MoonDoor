#include "includes/mServer.h"

using namespace std;
int main(int argc , char *argv[]){
	Server s;
	s.listen_(90190);
	int sum=0;
	int count_so_far=2;
	cout<<"Waiting for incoming connections...\n";
	string rec=s.receive();
	cout<<rec<<endl;
	s.send_("MOE DESU\n");
	s.close_();
	sleep(1);
    return 0;
}