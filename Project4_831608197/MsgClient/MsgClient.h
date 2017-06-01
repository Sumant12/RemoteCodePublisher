/////////////////////////////////////////////////////////////////////
//  MsgClient.h -This file has all the classeS which can handle requests 
//  from the GUI.
//  ver 1.4                                                        //
//  Language:      Visual C++ 2015                                 //
//  Platform:      Dell XPS 8900, Windows 10                       //
//  Application:   Used to support parsing source code             //
//  Author:        Saisumanth Gopisetty							  //
//                 sgopiset@syr.edu								  //
// Maintainance History:										  //
// Created on: 28th April,2017                                    //
/////////////////////////////////////////////////////////////////////


#ifndef MSG_CLIENT_H
#define MSG_CLIENT_H

#include <string>
#include "../HttpMessage/HttpMessage.h"
#include "../Sockets/Sockets.h"
#include "../Cpp11-BlockingQueue/Cpp11-BlockingQueue.h"
using Message = std::string;
using namespace Async;
using BQueue = BlockingQueue<Message>;

using Show = Logging::StaticLogger<1>;  // use for demonstrations of processing
using namespace Utilities;
using namespace Async;
using BQueue = BlockingQueue<std::string>;
using Utils = StringHelper;

class ClientHandler
{
public:
	using Path = std::string;
public:
	ClientHandler(BlockingQueue<HttpMessage>& msgQ) : msgQ_(msgQ) {}
	void operator()(Socket socket);
	bool ProcessCommandLine();
	HttpMessage readMessageForPost(HttpMessage& msg, Socket& socket);
	HttpMessage readMessageForGet(HttpMessage& msg, Socket& socket);
private:
	bool connectionClosed_;
	HttpMessage readMessage(Socket& socket);
	bool readFile(const std::string& filename, size_t fileSize, const std::string& getDir, Socket& socket);
	bool acceptFileFromServer(HttpMessage &msg, Socket& socket);
	BlockingQueue<HttpMessage>& msgQ_;
	Path path_;
};
/////////////////////////////////////////////////////////////////////
// MsgClient class
// - The is a class which serves as backend to the Client GUI. 
//   
//
class MsgClient
{
public:
	using EndPoint = std::string;
	void startClient(BQueue &sharedQueue);
	void requestCodeAnaysis();
	void processUploadMessageFromClient(std::string filepath);
	void processGetCategoriesMessageFromClient();
	void processGetAllFilesFromRepoForAParticluarCategory(string msg);
	void processFileDownloadRequest(string msg);
	void processDeleteRequestFromClient(string msg);
	void processRunCodeAnalysisFromClient(string msg);
	HttpMessage makeMessage(size_t n, const std::string& msgBody, const EndPoint& ep);
	void sendMessage(HttpMessage& msg, Socket& socket);
	bool sendFile(const std::string& fqname, Socket& socket);
	void downloadScriptsOnStartUpOfClient();
};
#endif
