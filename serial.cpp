#include <iostream>
#include <string>
#include <libserial/SerialPort.h>
#include <libserial/SerialStream.h>
#include <chrono>
#include <thread>


using namespace LibSerial;

std::string serial_port_name = "/dev/ttyACM0";

/*
SerialPort serial_port;
serial_port.Open( serial_port_name );
serial_port.SetBaudRate( BaudRate::BAUD_9600 );
*/


std::string sD1 = "001";
std::string sD2 = "011";
std::string sD3 = "111";
std::string sD4 = "000";

int w = 1500;
bool a = true;


int main(){


    SerialPort serial_port;

    try{
        serial_port.Open( serial_port_name );
    }
    catch(std::exception){
        std::cout << "\n" << serial_port_name << " Device Not Available !!!\n";
        //exit(1);
        a = false;
    }

    while( a ){
    serial_port.SetBaudRate( BaudRate::BAUD_9600 );


    serial_port.Write( sD1 );
    std::this_thread::sleep_for(std::chrono::milliseconds(w));

    serial_port.Write( sD2 );
    std::this_thread::sleep_for(std::chrono::milliseconds(w));

    serial_port.Write( sD3 );
    std::this_thread::sleep_for(std::chrono::milliseconds(w));

    serial_port.Write( sD2 );
    std::this_thread::sleep_for(std::chrono::milliseconds(w));
   
    serial_port.Write( sD1 );
    std::this_thread::sleep_for(std::chrono::milliseconds(w));
    
    serial_port.Write( sD4 );
    std::this_thread::sleep_for(std::chrono::milliseconds(w));

    std::cout << "\n Finished \n\n" ;
    exit(0);

    }
    
    while( !a ){
        std::cout << "\nProgram without Serial communication. \n\n";
        exit(0);
    }

    return 0;
}



