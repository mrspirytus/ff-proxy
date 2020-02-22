#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include "server.h"
#include "config.h"
#include "server.h"

static struct ff_config ff_global_config;

int main(int argc, char **argv)
{
    enum ff_action action = ff_parse_arguments(&ff_global_config, argc, argv);
    int ret = 0;

    switch (action)
    {
    case FF_ACTION_START_PROXY:
        ret = ff_start_proxy(&ff_global_config);
        break;

    case FF_ACTION_PRINT_VERSION:
        ff_print_version(stdout);
        ret = 0;
        break;

    case FF_ACTION_PRINT_USAGE:
        ff_print_usage(stdout);
        ret = 0;
        break;

    case FF_ACTION_INVALID_ARGS:
        ff_print_usage(stderr);
        ret = 1;
        break;
    }

    return ret;
}