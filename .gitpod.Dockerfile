FROM gitpod/workspace-full-vnc

# install arangodb
RUN brew install arangodb

# install POCO C++ Library
RUN brew install poco

RUN docker run -i -t -d --restart=always --name rabbitmq -p 5672:5672 -p 15672:15672 rabbitmq:3.9-management
