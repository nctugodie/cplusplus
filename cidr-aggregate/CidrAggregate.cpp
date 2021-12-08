// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_ip_range(unsigned int ip_min, unsigned int ip_max)
{
    unsigned char bytes_ip_min[4];
    bytes_ip_min[0] = ip_min & 0xFF;
    bytes_ip_min[1] = (ip_min >> 8) & 0xFF;
    bytes_ip_min[2] = (ip_min >> 16) & 0xFF;
    bytes_ip_min[3] = (ip_min >> 24) & 0xFF;

    unsigned char bytes_ip_max[4];
    bytes_ip_max[0] = ip_max & 0xFF;
    bytes_ip_max[1] = (ip_max >> 8) & 0xFF;
    bytes_ip_max[2] = (ip_max >> 16) & 0xFF;
    bytes_ip_max[3] = (ip_max >> 24) & 0xFF;

    ::fprintf(stdout, "%d.%d.%d.%d,%d.%d.%d.%d\n"
        , bytes_ip_min[3], bytes_ip_min[2], bytes_ip_min[1], bytes_ip_min[0]
        , bytes_ip_max[3], bytes_ip_max[2], bytes_ip_max[1], bytes_ip_max[0]);
}

unsigned int convert_ip_string_to_number(const char* ip)
{
    unsigned int ip_number = 0;
    char* token = ::strtok(const_cast<char*>(ip), ".");
    while (token != NULL)
    {
        ip_number   = (ip_number << 8) + ::atoi(token);
        token       = ::strtok(NULL, ".");
    }

    return ip_number;
}

void convert_ip(const char* cidr, unsigned int& ip_min, unsigned int& ip_max, bool& is_mask_32)
{
    char* ip    = ::strtok(const_cast<char*>(cidr), "/");
    char* mask  = ::strtok(NULL, "/");

    unsigned int ip_number  = convert_ip_string_to_number(ip);
    int mask_integer        = ::atoi(mask);

    if (mask_integer != 32)
    {
        ip_min      = ip_number & (0xFFFFFFFF << (32 - mask_integer));
        ip_max      = ip_number | (0xFFFFFFFF >> mask_integer);
        is_mask_32  = false;
    }
    else
    {
        ip_min      = ip_number;
        ip_max      = 0;
        is_mask_32  = true;
    }
}

int main(int argc, char* argv[])
{
    char line [128] = {};
    unsigned int ip_min = 0;
    unsigned int ip_max = 0;
    unsigned int ip_min_previous = 0;
    unsigned int ip_max_previous = 0;
    bool is_mask_32 = false;
    bool is_mask_32_previous = false;

    while (1)
    {
        if (NULL == ::fgets(line, sizeof(line), stdin))
        {
            ::print_ip_range(ip_min_previous, ip_max_previous);
            break;
        }

        if (line[0] == ';' || line[0] == '$' || line[0] == '@')
            continue;

        char* cidr = ::strtok(line, ":");
        if (cidr != NULL)
        {
            ::convert_ip(cidr, ip_min, ip_max, is_mask_32);

            if (!is_mask_32_previous && is_mask_32)
            {
                if (ip_min == (ip_max_previous + 1))
                {
                    ip_max_previous = ip_min;
                }
                else
                {
                    if (ip_min_previous != 0 && ip_max_previous != 0)
                        ::print_ip_range(ip_min_previous, ip_max_previous);

                    ip_min_previous = ip_max_previous = ip_min;
                }
            }
            else if (is_mask_32_previous && is_mask_32)
            {
                if (ip_min == (ip_max_previous + 1))
                {
                    ip_max_previous = ip_min;
                }
                else
                {
                    if (ip_min_previous != 0 && ip_max_previous != 0)
                        ::print_ip_range(ip_min_previous, ip_max_previous);

                    ip_min_previous = ip_max_previous = ip_min;
                }
            }
            else
            {
                if (ip_min == (ip_max_previous + 1))
                {
                    ip_max_previous = ip_max;
                }
                else
                {
                    if (ip_min_previous != 0 && ip_max_previous != 0)
                        ::print_ip_range(ip_min_previous, ip_max_previous);

                    ip_min_previous = ip_min;
                    ip_max_previous = ip_max;
                }
            }

            is_mask_32_previous = is_mask_32;
        }
    }

    return 0;
}

