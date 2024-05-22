#include <iostream>
#include <algorithm>
#include "argparse.hpp"
#include "server.hpp"


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
    if (port == nullptr){
        std::cerr << "Please enter the port!" << std::endl;
        return 1;
    }
    char* ip = getCmdOption(argv, argv + argc, "--ip");
    if(!is_server & !ip){
        std::cerr << "Please enter ip, to connect to server" << std::endl;
        return 1;
    }
    char* num_connections = getCmdOption(argv, argv + argc, "--players");
    if (!num_connections){
        std::cerr << "Please enter number of players" << std::endl;
        return 1;
    }
    else if (atoi(num_connections) > 4 || atoi(num_connections) < 0){
        std::cerr << "Please enter number of players between 2 and 4" << std::endl;
        return 1;
    }
    if (is_server){
        server_work(atoi(port), atoi(num_connections));
    }
    return 0;
}
