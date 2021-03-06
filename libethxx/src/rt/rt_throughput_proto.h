#ifndef __RT_THROUGHPUT_PROTO_H__
#define __RT_THROUGHPUT_PROTO_H__

#include <stdint.h>
#include "rt_sync.h"
#include "rt.h"
#include "json.h"

struct rt_throughput_proto_list{
#define PATH_SIZE   128
    char path[PATH_SIZE];
    uint64_t router;
    uint64_t port;
    pthread_mutex_t  entries_mtx;
    struct rt_throughput_proto_entry *head, *tail;
    int count;

    /** for other routers */
    struct rt_throughput_proto_list * next, *prev;
};

struct rt_throughput_proto_mgmt{
#define PATH_SIZE   128
    char default_path[PATH_SIZE];
    struct rt_throughput_proto_list *cache;
    uint64_t flush_threshold;
    uint64_t sample_threshold;
};

extern void rt_throughput_proto_init();

extern int  rt_proto_throughput_query(uint64_t router ,
    uint64_t port ,
    uint64_t cmd_type ,
    uint64_t start_ts , uint64_t end_ts ,
    uint64_t interval , json_object *proto_array_obj);


#endif
