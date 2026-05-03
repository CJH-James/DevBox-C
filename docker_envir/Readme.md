

### version info

```bash
    docker:27.4.1, build b9d17ea
       (must have `docker buildx`)
```


### Docker envir build

- Build Docker 
```bash
    docker build -t gcc_dev:1.3.0 \
                 -f ./docker_envir/Dockerfile . \
                 --build-arg USER_NAME=$(whoami) \
                 --build-arg USER_ID=$(id -u) \
                 --build-arg GROUP_ID=$(id -g) \
                 --build-arg WORKDIR=$(pwd)

```

- Build Dockerfile_multiplatform 
```bash
    docker buildx create --use --name NAME_YOUR_DOCKER_BUILDER
    docker buildx inspect --bootstrap
    # list your buildx
    docker buildx ls

    ### for arm64
    docker buildx build -t arm64-gcc:1.2.0 . \
                        -f ./docker_envir/Dockerfile_multiplatform \
                        --platform linux/arm64 \
                        --build-arg USER_NAME=$(whoami) \
                        --build-arg USER_ID=$(id -u) \
                        --build-arg GROUP_ID=$(id -g) \
                        --build-arg WORKDIR=$(pwd) \
                        --build-arg INSTALL_DEBUG=true \
                        --load

    #  --platform PLATFORM        PLATFORM options {linux/arm64, linux/amd64}
    #             
    #  -t IMAGE_NAME:VERION .     The image name and version (P.S. The dot in the end is necessary)
    #
    #  -f DOCKERFILE              Build with specific dockerfile 
    #
    #  --push --> push to remote(docker hub)
    #  --load --> load to local
```
- Remove build cache
``` bash

docker builder prune

```

### Docker run

- Run the Docker Container
```bash

    docker run -v /YOUR_PATH_TO_REPO/ProtocolToolBox:/ProtocolToolBox \
                  --name NAME_YOUR_CONTAINER -it THE_IMAGES_NAME_AND_VERSION
#---Example---#
    docker run -v /home/jameshuang/workspace/ProtocolToolBox:/home/jameshuang/workspace/ProtocolToolBox \
               --name ProtocolToolBox-dev -it gcc_dev:1.3.0
```

- Get into the Docker Container again
  - 1. Start the container (if it stop)
  - 2. Get into the container
```bash
    docker start YOUR_CONTAINER_NAME
    docker attach YOUR_CONTAINER_NAME

#---Example---#
    docker start ProtocolToolBox-dev
    docker attach ProtocolToolBox-dev

```


### Quick note for failure:
1. Docker Permission denied

```bash
ERROR: permission denied while trying to connect to the Docker daemon socket at unix:///var/run/docker.sock: Head "http://%2Fvar%2Frun%2Fdocker.sock/_ping": dial unix /var/run/docker.sock: connect: permission denied
```

solution:
```bash
    sudo groupadd docker
    sudo usermod -aG docker $USER
    reboot
```

2. Docker service not start

```bash
ERROR: Cannot connect to the Docker daemon at unix:///var/run/docker.sock. Is the docker daemon running?
```

solution:
```bash
    sudo service docker start
```

Some issue when you using `WSL2`
```
$ sudo service docker start
/etc/init.d/docker: 62: ulimit: error setting limit (Invalid argument)
```
solution:
```bash
sudo vim /etc/init.d/docker
--- Remove the "H" ---
change the line : ulimit -Hn 524288
become          : ulimit -n 524288

```

