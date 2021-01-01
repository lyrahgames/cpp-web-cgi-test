FROM lyrahgames/ubuntu-gcc-build2:20.10-10-0.13 as builder
# Install GNU CGI library for C++.
RUN \
  apt update && apt install -y \
    libcgicc-dev \
  && \
  rm -rf /var/lib/apt/lists/*
# Compile CGI scripts.
COPY cgi-bin/ /cgi-bin/
WORKDIR cgi-bin
RUN b config.cxx=g++-10 "config.cxx.coptions=-O3 -march=native"

FROM httpd
# Enable CGI module.
RUN sed -i 's/#\(LoadModule cgid_module modules\/mod_cgid.so\)/\1/' conf/httpd.conf
# Install GNU CGI library for C++.
RUN \
  apt update && apt install -y \
    libcgicc-dev \
  && \
  rm -rf /var/lib/apt/lists/*
# Copy project content into container.
COPY index.html /usr/local/apache2/htdocs/
COPY style.css /usr/local/apache2/htdocs/
COPY --from=builder /cgi-bin/*.cgi /usr/local/apache2/cgi-bin/