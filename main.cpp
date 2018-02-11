#include <iostream>
#include <chrono>

#include "wotpp/core.h"
#include "wotpp/utils.h"

#include "impl/ops.h"




// TODO:
// - Implement every operation for both chars and ints.




// USAGE MESSAGE
void usage() {
    std::cout << "usage: <file>\n";
}






int main(int argc, const char* argv[]) {
    // Load file.
    bool success;
    std::string code;

    // Make sure the correct number of arguments have been provided.
    if (argc != 2) {
        usage();
        return -1;
    }


    // Attempt to read a file and check if it was successful.
    std::tie(success, code) = wotpp::read_file(argv[1]);

    // If we cannot open the file, show an error.
    if (!success) {
        std::cerr << "Cannot open file!\n";
        usage();
        return -1;
    }





    // We succeeded in loading the file, now run it.
    // Setup the heap.
    wotpp::heap heap{4096};

    // Setup stacks.
    wotpp::stack_group stacks({
        wotpp::stack{1024},
        wotpp::stack{256},
        wotpp::stack{256},
        wotpp::stack{64},
        wotpp::stack{64},
        wotpp::stack{64},
        wotpp::stack{64},
        wotpp::stack{64},
    });


    // Create array for instructions.
    wotpp::op_group ops = make_ops();

    // Run the VM.
    // Use some chrono stuff for minor benchmarking.
    auto start = std::chrono::high_resolution_clock::now();
    wotpp::execute(stacks, heap, ops, code); // Run the code.
    auto end = std::chrono::high_resolution_clock::now();

    // Show us how quickly the function executed in NS.
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << std::endl;

    return 0;
}