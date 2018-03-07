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
        "file_name": "slash.log",
        "max_file_size": 5000000,
        "max_files": 10
        }
    }

log = {
    "level": "trace",
    "sinks": [sink1, sink2]
    }

smack = {
    "multi_ip": "233.54.1.100",
    "multi_port": 30100,
    "local_ip": "72.31.0.4"
    }

slash = {
    "instrus_filter": "cu1603",
    "speed_file": "slash_speed.data"
    }

cfg = {
    "slash": slash,
    "smack": smack,
    "log": log
    }

with open('slash.json', 'w') as f:
    json.dump(cfg, f, sort_keys=True, indent=4)
