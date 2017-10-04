#include <iostream>

#include <Bull/Core/Process.hpp>

int main(int argc, char* argv[])
{
    std::cout << "PID = " << Bull::Process::getCurrentPid() << std::endl;
    std::cout << "PPID = " << Bull::Process::getCurrentParentPid() << std::endl;

    std::cout << "Start mkdir" << std::endl;
    Bull::Process mkdir("mkdir foo");
    mkdir.start();

    if(mkdir.getExitCode(true) == Bull::Process::ExitCode::Ok)
    {
        std::cout << "foo directory created successfully" << std::endl;
    }
    else
    {
        std::cout << "Failed to create foo directory" << std::endl;
    }

    std::cout << "Start rmdir" << std::endl;
    Bull::Process rmdir("rmdir foo");
    rmdir.start();

    if(rmdir.getExitCode(true) == Bull::Process::ExitCode::Ok)
    {
        std::cout << "foo directory removed successfully" << std::endl;
    }
    else
    {
        std::cout << "Failed to remove foo directory" << std::endl;
    }

    return 0;
}