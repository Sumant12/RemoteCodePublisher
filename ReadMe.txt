This is new ReadMe file.
A Client-Server Application where multiple clients can connect to the remote code repository and work in collaboration.
1. Developed Publisher program that runs on the Repository Server which generates HTML web pages from the code uploaded by the Client. The HTML pages contain the information of all the Dependency files.
2.The web pages generated will have the facility to expand or collapse class bodies, methods, and global functions using JavaScript and CSS properties.
3.Clients can view various categories in the Repository and download one or multiple files under the selected categories.
4.Clients can upload files to the Repository from their local machine to save the status of their work.
5.Developed all the message-passing communication channels using Sockets and Http Style Asynchronous one-way messages.
6.Implemented Lazy loading strategy to download files. when a file is downloaded by the Client, All the dependent files are downloaded automatically.
7.The HTML pages are published to the IIS Server so that they can be accessed directly on the Server.
