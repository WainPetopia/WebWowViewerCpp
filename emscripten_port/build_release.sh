 emconfigure cmake -DCMAKE_BUILD_TYPE=Release . && emmake make
 emcc libAWoWWebViewerJs.a ./A/libWoWViewerLib.a -s USE_GLFW=3 --preload-file glsl -O3 -s ALLOW_MEMORY_GROWTH=1 -s FETCH=1 -s WASM=1 -s USE_WEBGL2=1 -s FULL_ES3=1 -s "EXPORTED_FUNCTIONS=['_createWebJsScene', '_gameloop', '_createWoWScene', '_setScene', '_setSceneSize', '_setSceneFileDataId', '_setNewUrls']" -o project.js