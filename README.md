# The Can We Talk System

## Overview
The Can We Talk System is a multi-threaded client-server application that can support a maximum of 10 clients. Each clients is handled by a separate thread created by the server.
In the client side, the sending and receiving of messages is handled by two separate threads.

## Components
The system consists of two main components:
* Client - The client can sent messages with messages greater than 40 characters are parceled into two chunks. The maximum number of character a user can type is **80**. You can exit the client by typing `>>bye<<`
* Server - The server handles each client through each thread. It can support a maximum of 10 clients. The server broadcasts every message send by the client to every other client.

## Compiling
To run the Can We Talk System, follow these steps:
1. Compile the system using the following command
```bash
make all
```
2. If you compile the client or server separately, you can type `make` while in the `chat-client` or `chat-server` respectively

## Running the Can We Talk System
1. Open the terminal inside the `CHAT-SYSTEM` 
2. You can run the server using the following command
```bash
./chat-server/bin/server
```
2. You can run the client using the following command
```bash
./chat-client/bin/client -user<user_name> -server<server_name>
```
Where `<user_name>` can be user ID or a user name and `<server_name>` can be the hostname of the server or the IP of the server

## Cleaning the file structure
* You can clean the folder using 
```bash
make clean
```
* You can clean the log folder using
```bash
make clean_log
```

## File Structure
- `chat-client/`: Contains the files for the client
- `chat-server/`: Contains the files for the server.
- `common/`: Stores files use by both client and server
- `src/`: Contains the source code files
- `inc/`: Contains header files.
- `obj/`: Stores object files 
- `bin/`: Stores executable 
- `tmp/`: Contains the log files
- 
## License
This project is open-source and available under the MIT License.
