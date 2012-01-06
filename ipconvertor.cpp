/*
 * IPConvertor.cpp
 * handles the conversion of ip/cidr to netmask, wildcard mask, broadcast, network, hostmin, and host max address
 * also has methods for displaying them in dotted notation, hex, and binary
 */

#include "IPConvertor.h"

IPConvertor::IPConvertor()
{
    refresh("192.168.1.1", 24);
}

string IPConvertor::getmaxhosts()
{
    stringstream in;
    in << maxhosts;
    return in.str();
}

void IPConvertor::refresh(string address, int cidr)
{
    int res;
    if( (res = inet_aton(address.c_str(), &ip)) != 1) // check if valid IP address
        return;

    /* verify cidr */
    if(cidr < 0 || cidr > 32)
        return;

    /* you have a valid IP address and a valid cidr
     * start converting ip/cidr to other network fields
     */
    netmask.s_addr = htonl(~((1 << (32 - cidr)) - 1));
    wildcard.s_addr = ~netmask.s_addr;
    broadcast.s_addr = ip.s_addr | ~netmask.s_addr;
    network.s_addr = ip.s_addr & netmask.s_addr;
    maxhosts = ntohl(broadcast.s_addr) - ntohl(network.s_addr) - 1;
    hostmax.s_addr = htonl(ntohl(broadcast.s_addr) - 1);
    hostmin.s_addr = htonl(ntohl(network.s_addr) + 1);

    /* verify the overflow and set 31 and 32 bit masks to their proper
     * number of valid hosts
     */
    if(cidr == 32)
        maxhosts = 1;
    if(cidr == 31)
        maxhosts = 2;
}

string IPConvertor::toString()
{
    string ret;

    ret.append("netmask: " + getnetmask() + " " + h_getnetmask() + " " + b_getnetmask() + "\n");
    ret.append("wildcard: " + getwildcard() + " " + h_getwildcard() + " " + b_getwildcard() + "\n");
    ret.append("broadcast: " + getbroadcast() + " " + h_getbroadcast() + " " + b_getbroadcast() + "\n");
    ret.append("network: " + getnetwork() + " " + h_getnetwork() + " " + b_getnetwork() + "\n");
    ret.append("hostmin: " + gethostmin() + " " + h_gethostmin() + " " + b_gethostmin() + "\n");
    ret.append("hostmax: " + gethostmax() + " " + h_gethostmax() + " " + b_gethostmax() + "\n");

    return ret;

}

string IPConvertor::addr2bin(struct in_addr var)
{
    /* I know...
     * This loops through each of the four bytes in the address.
     * for each byte, start at the end (little endian) and work
     * backwards through each bit in the byte.
     *
     * check if the byte is 1 or 0 and set that character in the
     * array in its proper value for human readability
     */
    char bin[32];
    int k = 0;
    for(int i=7; i<32; i+= 8)
    {
        for(int j=0; j<8; j++)
        {
            if( var.s_addr & (1 << k) ){
                bin[i-j] = '1';
            }else{
                bin[i-j] = '0';
            }
            k++;
        }
    }

    /* conver to c string for easier addition of '.' */
    string ret = bin;

    ret.insert(8,".");
    ret.insert(17,".");
    ret.insert(26, ".");
    return ret.substr(0,35);
}

string IPConvertor::addr2hex(struct in_addr var)
{
    char str[14];
    unsigned char *hex = (unsigned char *)&var.s_addr;
    sprintf(str, "%02X:%02X:%02X:%02X", *hex, *(hex + 1), *(hex + 2), *(hex + 3));
    return str;
}
