#include <boost/asio/executor_work_guard.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/strand.hpp>
#include <boost/asio/deadline_timer.hpp>


#include <amqpcpp.h>
#include <amqpcpp/libboostasio.h>

// g++ -std=c++14 src/main.cc -o main.out -lpthread -lboost_system -lamqpcpp
/**
 *  Main program
 *  @return int
 */
int main()
{

    // access to the boost asio handler
    // note: we suggest use of 2 threads - normally one is fin (we are simply demonstrating thread safety).
    boost::asio::io_service service(4);

    // handler for libev
    AMQP::LibBoostAsioHandler handler(service);
    
    // make a connection
    AMQP::TcpConnection connection(&handler, AMQP::Address("amqp://guest:guest@localhost/"));
    
    // we need a channel too
    AMQP::TcpChannel channel(&connection);
    
    for(uint i=0; i<10; i++)
    {
        channel.startTransaction();
        channel.publish("test", "test", "my first message test");
        channel.commitTransaction()
        .onSuccess([]()
        {
            // std::cout << "all messages were successfully published" << std::endl;
        })
        .onError([](const char *message)
        {
            // none of the messages were published
            // now we have to do it all over again
            // std::cerr << message << std::endl;
        });
    }
    
    connection.close();

    // boost::asio::io_service::work work(service);

    // service.run();
    // service.stop();
    // service.reset();

    return service.run();
}