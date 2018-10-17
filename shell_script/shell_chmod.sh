#!/bin/bash

# chmod u+x $(find $1 -name "*.sh")
# ls -1 $1/*.sh
find . -name "*.sh" -print -exec chmod u+x {} +
