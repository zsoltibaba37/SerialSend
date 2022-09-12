#include <iostream>
#include <string>
#include <libserial/SerialPort.h>
#include <chrono>
#include <thread>

using namespace LibSerial;

std::string serial_port_name = "/dev/ttyACM0";
std::vector<std::string> sD = {"001", "011", "111", "011", "001", "000"};
int w = 1500;               // wait before ....
bool a = true;

int main(){
    SerialPort serial_port;
    try{
        serial_port.Open( serial_port_name );
    }
    catch(std::exception){
        std::cout << "\n" << serial_port_name << " Device Not Available !!!\n";
        a = false;
    }
    while( a ){
    serial_port.SetBaudRate( BaudRate::BAUD_9600 );

    for ( std::string o : sD ){
        serial_port.Write( o );
        std::this_thread::sleep_for(std::chrono::milliseconds(w));
    }

    std::cout << "\n Finished \n\n" ;
    exit(0);

    }
    
    std::cout << "\nProgram without Serial communication. \n\n";
    exit(0);

    return 0;
}



