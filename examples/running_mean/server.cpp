#include "../../includes/mServer.h"
using namespace std;
int main(int argc, char const *argv[]) {
    Server s;
    s.listen_(8000);
    int run_sum=0,count=0;
    while(1){
        string val=s.receive();
        int num=stoi(val);
        run_sum+=num;
        count+=1;
        string avg=to_string(run_sum/count);
        s.send_(avg);
    }
    return 0;
}
