/*
 * IPConvertor class
 *
 * This class will take as an input an IP address and cidr value
 * ie 192.168.1.1/24
 *
 * From here conversions of
 * 		netmask
 * 		broadcast
 * 		wildcard
 * 		network
 * 		max host
 * 		min host
 * 		numbe of possible hosts
 * is computed.
 *
 * all variables are private and accessable in dotted, hex or binary format
 * get methods for each are provided and return a c++ string
 */

#pragma once

#include <iostream>
#include <string>
#include <arpa/inet.h> //for inet_aton(), htonl(), ntohl()
#include <sstream>
#include <cstdio>

using namespace std;

class IPConvertor{
private:
    struct in_addr ip;
    struct in_addr netmask;
    struct in_addr wildcard;
    struct in_addr broadcast;
    struct in_addr network;
    int maxhosts;
    struct in_addr hostmax;
    struct in_addr hostmin;

public:
    IPConvertor();
    void refresh(string address, int cidr);
    string toString();

    string getmaxhosts();

    string getip(){ return inet_ntoa(ip); };
    string getnetmask(){ return inet_ntoa(netmask); };
    string getwildcard(){ return inet_ntoa(wildcard); };
    string getbroadcast(){ return inet_ntoa(broadcast); };
    string getnetwork(){ return inet_ntoa(network); };
    string gethostmin(){ return inet_ntoa(hostmin); };
    string gethostmax(){ return inet_ntoa(hostmax); };

    string addr2hex(struct in_addr var);
    string h_getnetmask(){ return addr2hex(netmask); };
    string h_getwildcard(){ return addr2hex(wildcard); };
    string h_getnetwork(){ return addr2hex(network); };
    string h_getbroadcast(){ return addr2hex(broadcast); };
    string h_gethostmin(){ return addr2hex(hostmin); };
    string h_gethostmax(){ return addr2hex(hostmax); };

    string addr2bin(struct in_addr var);
    string b_getnetmask(){ return addr2bin(netmask); };
    string b_getwildcard(){ return addr2bin(wildcard); };
    string b_getnetwork(){ return addr2bin(network); }
    string b_getbroadcast(){ return addr2bin(broadcast); };
    string b_gethostmin(){ return addr2bin(hostmin); };
    string b_gethostmax(){ return addr2bin(hostmax); };

    friend ostream & operator<<(ostream & out, IPConvertor & ipv);
};
