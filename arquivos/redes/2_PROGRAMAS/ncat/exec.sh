#!/bin/bash
for ((;;)); do
  read REPLY;
  if [ "${REPLY:0:6}" == "GET / " ]; then
    /bin/echo -e "HTTP/1.1 200 OK\r\n";
    cat ncat.txt;
  else
    sleep 1;
  fi;
  REPLY="";
done
