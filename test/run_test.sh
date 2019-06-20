#!/bin/bash

PROJ_DIR=".."
SHARED_LIBDIR="${PROJ_DIR}/lib"

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${SHARED_LIBDIR}

ulimit -c unlimited

./test
