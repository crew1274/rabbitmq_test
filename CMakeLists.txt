cmake_minimum_required (VERSION 3.2)
project(HTTPServer)
find_package(Poco REQUIRED COMPONENTS Data DataSQLite JSON Net NetSSL Util)
add_executable(HTTPServer src/HTTPServer.cpp)
target_link_libraries(HTTPServer PUBLIC Poco::Net Poco::Util Poco::JSON)