#!/bin/bash

rm -rf test_package/build ~/.conan/data/ssge;
conan create . demo/testing;
