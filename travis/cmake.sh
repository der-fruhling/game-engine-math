#!/bin/bash
cmake .
make
test/Matrix3D_test
test/Vector3D_test
