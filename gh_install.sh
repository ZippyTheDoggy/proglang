#!/bin/bash
# Installs repos from GH
# Reqs:
#   - gh
#   - unzip

if [ ! -d "./libs" ]; then mkdir libs; fi

# Neargye/magic_enum
if [ -d "./magic_enum" ]; then rm -rf ./magic_enum; fi
gh release download -R Neargye/magic_enum --archive=zip -D ./magic_enum
TEMP=$(find ./magic_enum -maxdepth 1 -type f -name "*.zip")
unzip -q $TEMP -d ./magic_enum
TEMP=$(find ./magic_enum/ -maxdepth 1 -type d -name "magic_enum-*")
mv "$TEMP/include/magic_enum" "./libs/magic_enum"
rm magic_enum -rf

# 