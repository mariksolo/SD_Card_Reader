#!/usr/bin/env bash
arduino-cli upload -p $1 --fqbn arduino:samd:nano_33_iot
sleep 0.77
stty -F $1 9600 raw -echo icrnl
cat $1
