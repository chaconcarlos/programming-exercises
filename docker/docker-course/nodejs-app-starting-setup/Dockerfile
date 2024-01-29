# The name of the image to use as base.
FROM node

# Tells Docker that all comands from here will be executed in this directory.
WORKDIR /app

# Copies the files in the current folder (except the Dockerfile) to /app in the image.
COPY . /app

# Runs npm install in the WORKDIR (/app).
# Commands specified with RUN will run when setting up the image.
RUN npm install

# Exposes the port 80 outside the container. It's optional, to document that a process container
# will expose this port. You still need to run the container with the -p option.
EXPOSE 80

# Runs this command when a container based on this image is started.
CMD [ "node", "server.js" ]
