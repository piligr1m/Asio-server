//
//  client.hpp
//  s
//
//  Created by Stanislav Martynov on 06.01.2020.
//  Copyright © 2020 Stanislav Martynov. All rights reserved.
//

#pragma once

#include "log.hpp"
#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <boost/bind.hpp>

namespace ba = boost::asio;
namespace ip = boost::asio::ip;
class Client {
public:
    Client();
    Client(int x);
    Client(const Client& client);
    ~Client() = default;
    Client& operator=(const Client& client);
    void work();
    void login();
    void setUsername(const std::string& username);
    std::string getUsername();
    void listenToServer(std::string& message);
    void tellServer();
    void tellServer(const std::string& message);
    ip::tcp::socket& sock();
    void talkWithServer();
    void setIsTimeOut();
    bool isTimeOut();
    void setHasConsole();
    bool hasConsole();
private:
    std::shared_ptr<ip::tcp::socket> socket_;
    ip::tcp::endpoint endpoint_{ip::address::from_string("127.0.0.1"), 8080};
    std::string username_;
    bool hasConsole_ = false;
    bool isTimeOut_ = false;
    ba::io_service service_;
};
