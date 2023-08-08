# Simple HTTP
A simple (or shitty) HTTP server written in C++. This is **not intended** to be used as an actual web server, but as an example on how one would write a server.
The server can serve static files.

# Configuration
The server expects a config.toml file in the same directory as the binary.

Example config.toml
```
# The port to listen on
port = 8080
# The directory of the static files to be served
serve = "./www/"
```
