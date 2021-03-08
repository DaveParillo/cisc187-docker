# CISC187 docker image
A docker container with all the tools needed to
compile homework for CISC187 at SD Mesa College.

The image is fairly light, based on alpine linux.

The easiest way to get the image is from docker hub:

```
docker pull dparillo/cisc187
```

or clone this repository and build it yourself.

```
docker build -t dparillo/cisc187 .
```
  
# Running the container
The container is a means to run compile commands on your source repository stored
on your local filesystem.
The image defines a volume (`/mnt/cisc187`) where you can mount your source
and make it visible to the docker container.

Runestone also can serve books from a lightweight web server for local testing.
To test, you'll need to map the web server port.

To create a temporary image that will be removed after it closes that
mounts the local directory `code` to the reserved volume:

```
docker run --rm -it -v /full/path/to/my/code:/mnt/cisc187 dparillo/cisc187
```

Once running, the container will start an alpine shell.
 

