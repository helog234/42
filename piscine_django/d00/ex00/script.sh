#!/bin/sh

# No checks are possible with the limit of curl, grep and cut
curl -sI "$1" | grep "Location:" | cut -d ' ' -f2


