#include "orchestator.h"

int main(int argc, const char* argv[]){
    Orchestator orchestator(argv[1], argv[2]);
    orchestator.init();
    orchestator.launch_threads();
    if (orchestator.distribute_materials() == ERROR)
        return ERROR;
    orchestator.join_threads();
    orchestator.print_results();
    return 0;
}
