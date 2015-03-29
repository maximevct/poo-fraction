#!/bin/sh

g++ main.cpp && ./a.out > actual && diff -y actual expected && rm actual
