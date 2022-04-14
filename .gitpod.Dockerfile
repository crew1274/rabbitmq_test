FROM gitpod/workspace-full-vnc
# install vue-cli
RUN brew install vue-cli
# install arangodb
RUN brew install arangodb
RUN brew install poco