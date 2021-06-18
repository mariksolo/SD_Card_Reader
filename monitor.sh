#!/usr/bin/env bash
stty -F $1 9600 raw -echo icrnl
cat $1
