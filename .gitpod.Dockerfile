FROM gitpod/workspace-full-vnc

# install arangodb
RUN brew install arangodb

# install POCO C++ Library
RUN brew install poco
