/* 
 * File:   main.cpp
 * Author: datbt
 *
 * Created on June 15, 2015, 10:07 AM
 */

#include <cstdlib>
#include "Counter.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include <Poco/AutoPtr.h>
#include <Poco/Util/Application.h>
#include <Poco/Util/Option.h>
#include <Poco/Util/OptionSet.h>
#include <Poco/Util/OptionCallback.h>
#include <Poco/Util/HelpFormatter.h>

#include <iostream>

using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::OptionCallback;
using Poco::Util::Application;
using Poco::Util::HelpFormatter;

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace counterService;
using namespace std;

/*
 * 
 */
class PocoClient: public Application{
private:
    int port;
    static const int TYPE_REG = 1;
    static const int TYPE_LOG = 2;
    bool _noop;
public:
    PocoClient(){
        //constructor
        port = 3333;
        _noop = true;
    }
    
protected:
    void initialize(Application& self){
        loadConfiguration();
        Application::initialize(self);
    }
    
    void uninitialize(){
        Application::uninitialize();
    }
    
    void reinitialize(Application& self){
        Application::reinitialize(self);
    }
    
    void defineOptions(OptionSet& options){
        Application::defineOptions(options);
        options.addOption(
            Option("help", "h", "display help information")
                .required(false)
                .repeatable(false)   
                .callback(OptionCallback<PocoClient>(this, &PocoClient::handleHelp)));
        
        options.addOption(
            Option("register", "r", "register user")
                .required(false)
                .repeatable(false)
                .argument("id")
                .callback(OptionCallback<PocoClient>(this, &PocoClient::handleConnect)));
        
        options.addOption(
            Option("login", "l", "login")
                .required(false)
                .repeatable(false)
                .argument("id")
                .callback(OptionCallback<PocoClient>(this, &PocoClient::handleConnect)));
        
        options.addOption(
            Option("gettotal", "G", "get total view")
                .required(false)
                .repeatable(false)
                .callback(OptionCallback<PocoClient>(this, &PocoClient::handleConnect)));
        
        options.addOption(
            Option("get", "g", "get view of a user")
                .required(false)
                .repeatable(false)
                .argument("id")
                .callback(OptionCallback<PocoClient>(this, &PocoClient::handleConnect)));
        
//        options.addOption(
//            Option("as","d", "sad")
//                .group("Das")
//        );
        
    }  
    
    void handleHelp(const std::string& name, const std::string& value){
        _noop = false;
        displayHelp();
        stopOptionsProcessing();
    }
    
    void displayHelp(){
        HelpFormatter helpFormatter(options());
        helpFormatter.setCommand(commandName());
        helpFormatter.setUsage("OPTIONS");
        helpFormatter.setHeader("View Count Client options");
        helpFormatter.format(std::cout);
    }
    
    void handleConnect(const std::string& name, const std::string& value){
        _noop = false;
        //connect to server
        boost::shared_ptr<TTransport> socket(new TSocket("localhost", port));
        boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
        boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
        CounterClient client(protocol);
        
        try {
            transport->open();
            
            if (name.compare("register") == 0 || name.compare("r") == 0){
                handleRegister(client, value);
            }
            else if (name.compare("login") == 0 || name.compare("l") == 0){
                handleLogin(client, value);
            }
            else if (name.compare("gettotal") == 0 || name.compare("G") == 0){
                handleGetTotal(client, value);
            }
            else if (name.compare("get") == 0 || name.compare("g") == 0){
                handleGet(client, value);
            }
            
            transport->close();
        }
        
        catch (TException e){
            cout<< "ERROR: "<<e.what()<<endl;
        }
    }
    
    void handleRegister(CounterClient client, const std::string& value){
        if (client.put(value, TYPE_REG)){
            cout <<"Register user \""<<value<<"\" successfully!"<<endl;
        }
        else {
            cout << "Register fails! User \""<<value<<"\" has been used!"<<endl;
        }
    }
    
    void handleLogin(CounterClient client, const std::string& value){
        if (client.put(value, TYPE_LOG)){
            cout <<"Log in with  user \""<<value<<"\" successfully!"<<endl;
        }
        else {
            cout << "Log in fails! User name incorrect!"<<endl;
        }
    }
    
    void handleGetTotal(CounterClient client, const std::string& value){
        
            int totalView = client.getTotal();
            cout << "Total view: "<<totalView<<endl;
        
    }
    
    void handleGet(CounterClient client, const std::string& value){
        int view = client.get(value);
        if (view != -1){
            cout << "View of user \""<<value<<"\": "<<view<<endl; 
        }
        else {
            cout << "ERROR: Wrong user name!"<<endl;
        }
    }
    
    int main(const std::vector<std::string>& args ){
        if (_noop)
            displayHelp();
        return Application::EXIT_OK;
    }
};

POCO_APP_MAIN(PocoClient)
