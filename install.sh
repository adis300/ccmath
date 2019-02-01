#! /bin/sh

# CCM library installation script
#   run this after successful compilation
#   should be run by the ROOT user from the distribution directory

cp ccmath.h /usr/include
cp tmp/libccm.a /usr/lib/libccm.a
cp tmp/libccm.so /lib/libccm.so
rm tmp/*
