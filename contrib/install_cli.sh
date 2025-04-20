 #!/usr/bin/env bash

 # Execute this file to install the memeium cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%Memeium-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/Memeium-Qt.app/Contents/MacOS/memeiumd /usr/local/bin/memeiumd
 sudo ln -s ${LOCATION}/Memeium-Qt.app/Contents/MacOS/memeium-cli /usr/local/bin/memeium-cli
