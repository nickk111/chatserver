#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
using namespace muduo;
using namespace muduo::net;

//聊天服务器的主类
class ChatServer
{

public:
    //初始化聊天服务器对象
    ChatServer(EventLoop* loop,
               const InetAddress& listenAddr,
               const string& nameArg);
    //启动服务器
    void start();
private:
    void onConnection(const TcpConnectionPtr &conn);
    
    void onMessage(const TcpConnectionPtr& conn,
                         Buffer* buffer,
                         Timestamp time);

    TcpServer _server;  //组合的muduo库，实现服务器功能的类对象
    EventLoop *_loop;   //指向事件循环对象的指针
};
#endif