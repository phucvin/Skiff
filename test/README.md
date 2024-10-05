cd ..
mvn test

source /workspaces/emsdk/emsdk_env.sh

emcc T01.c -sALLOW_MEMORY_GROWTH -Os -o T01.js
