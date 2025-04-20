FROM amd64/ubuntu:20.04 AS base

#If you found this docker image helpful please donate MMM to the maintainer
LABEL maintainer="RV9zdNeUTQUToZUcRp9uNF8gwH5LzDFtan"

EXPOSE 8766/tcp
EXPOSE 8676/tcp

ENV DEBIAN_FRONTEND=noninteractive

#Install runtime dependencies
RUN apt-get update && \
	apt-get install -y --no-install-recommends \
	bash wget net-tools libminiupnpc17 \
	libevent-2.1 libevent-pthreads-2.1 \
	libboost-system1.71 libboost-filesystem1.71 libboost-chrono1.71 \
	libboost-program-options1.71 libboost-thread1.71 \
	libzmq5 && \
	apt-get clean

FROM base AS build

#Install build dependencies
RUN apt-get update && \
	apt-get install -y --no-install-recommends \
	bash net-tools build-essential libtool autotools-dev automake \
	pkg-config libssl-dev libevent-dev bsdmainutils python3 \
	libboost-system1.71-dev libboost-filesystem1.71-dev libboost-chrono1.71-dev \
	libboost-program-options1.71-dev libboost-test1.71-dev libboost-thread1.71-dev \
	libzmq3-dev libminiupnpc-dev && \
	apt-get clean

#Copy source dir
COPY . /home/memeium/build/Memeium/
WORKDIR /home/memeium/build/Memeium

#build db4 from source
WORKDIR /home/memeium/build/Memeium/contrib
RUN ./install_db4.sh ../../

# build Memeiumcore
WORKDIR /home/memeium/build/Memeium
RUN ./autogen.sh && ./configure --disable-tests BDB_LIBS="-L/home/memeium/build/db4/lib -ldb_cxx-4.8" BDB_CFLAGS="-I/home/memeium/build/db4/include" --with-gui=no  && make -j4

FROM base AS final

#Add our service account user
RUN useradd -ms /bin/bash memeium && \
	mkdir /var/lib/memeium && \
	chown memeium:memeium /var/lib/memeium && \
	ln -s /var/lib/memeium /home/memeium/.memeium && \
	chown -h memeium:memeium /home/memeium/.memeium

VOLUME /var/lib/memeium

#Copy the compiled binaries from the build
COPY --from=build /home/memeium/build/Memeium/src/memeiumd /usr/local/bin/memeiumd
COPY --from=build /home/memeium/build/Memeium/src/memeium-cli /usr/local/bin/memeium-cli

WORKDIR /home/memeium
USER memeium

CMD /usr/local/bin/memeiumd -datadir=/var/lib/memeium -printtoconsole -onlynet=ipv4
