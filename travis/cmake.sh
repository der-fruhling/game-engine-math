#!/bin/bash

cd "$TRAVIS_BUILD_DIR" || exit 1
cmake . && \
make && \
test/Matrix3D_test && \
test/Vector3D_test
