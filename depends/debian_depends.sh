#!/bin/bash

echo -n "Debian apt repository update...	"
apt-get update -q -y 2>&1 1>>/dev/null || echo "[ERROR]"
echo "[OK]"

echo -n "Install dependencies...		"
apt-get install -q -y libssl-dev libconfig-dev liboping-dev libnet1-dev libpcap-dev libgeoip-dev libssh-dev build-essential automake autoconf libcurl4-openssl-dev liblld-dev binutils binutils-for-build lld libc++-dev libclang-dev clang libmbedtls-dev libc++abi-dev libbsd-dev libconfig++-dev libnet1-dev libnet-cpp-dev libnet1 liboping-dev liboping0 libtinyxml-dev libtinyxml2-dev libczmq-dev cppzmq-dev libzmq3-dev 2>&1 1>>/dev/null || echo "[ERROR]"
echo "[OK]"
#proposed
	# libcsv-dev

#if server
# mysql-server
# apache2

