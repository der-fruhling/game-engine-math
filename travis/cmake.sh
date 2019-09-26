#!/bin/bash

cd "/usr/src/gtest" || exit 1
sudo cmake . && \
sudo make && \
sudo cp *.a /usr/lib/
cd "$TRAVIS_BUILD_DIR" || exit 1
cmake . && \
make
test/Matrix3D_test
test/Vector3D_test
./game_engine_math