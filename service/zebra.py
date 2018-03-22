#!/usr/bin/env python

import json

sink1 = {
    "sink": {
        "type": "stdout_sink_mt",
        "level": "trace"
        }
    }

sink2 = {
    "sink": {
        "type": "rotating_file_sink_mt",
        "file_name": "zebra.log",
        "max_file_size": 5000000,
        "max_files": 10
        }
    }

log = {
    "level": "trace",
    "sinks": [sink1, sink2]
    }

spy = {
    "device": "eth0",
    "snaplen": 65535,
    "promisc": 0,
    "timeout": 0,
    "nonblock": 0,
    "filter": ""
    }

zebra = {
    "queue_size": 4096,
    "packet_type": 99,
    "optimization": False,
    "pcap_file": "mixed.pcap"
    }

slash = {
    "instrus_filter": "",
    "speed_file": "slash_speed.data"
    }

cfg = {
    "slash": slash,
    "zebra": zebra,
    "spy": spy,
    "log": log
    }

with open('zebra.json', 'w') as f:
    json.dump(cfg, f, sort_keys=True, indent=4)
