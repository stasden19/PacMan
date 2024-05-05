#include <iostream>
#include <algorithm>
#include "argparse.hpp"


int main(int argc, char *argv[])
{
    if(cmdOptionExists(argv, argv+argc, "--help"))
    {
      std::cout << "Usage:\n\t--server - if you server\n\t--port [port] - enter port(nessesary)\n\t--ip [ip] - enter ip(if client)\n\t--players [players]- enter players number(nessesary)\n"; 
      return 1;  
    }
    bool is_server = false;
    if(cmdOptionExists(argv, argv + argc, "--server")){
        is_server = true;
    }
    char* port = getCmdOption(argv, argv + argc, "--port");
    if (!port){
        std::cerr << "Please enter the port!" << std::endl;
        return 1;
    }
    char* ip = getCmdOption(argv, argv + argc, "--ip");
    if(!is_server & !ip){
        std::cerr << "Please enter ip, to connect to server" << std::endl;
        return 1;
    }
    return 0;
}
