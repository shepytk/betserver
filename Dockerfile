# Build stage
FROM ubuntu:24.04 AS builder

# Avoid prompts from apt
ENV DEBIAN_FRONTEND=noninteractive

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libssl-dev \
    libboost-all-dev \
    libspdlog-dev \
    libsqlite3-dev \
    wget \
    ca-certificates \
    && update-ca-certificates \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy source files
COPY . .

# Create build directory and build the project
RUN mkdir -p build && cd build && \
    GIT_SSL_NO_VERIFY=true cmake .. && \
    make -j$(nproc)

# Runtime stage
FROM ubuntu:24.04

# Install runtime dependencies
RUN apt-get update && apt-get install -y \
    libssl3t64 \
    libboost-system1.83.0 \
    libboost-thread1.83.0 \
    libboost-filesystem1.83.0 \
    libsqlite3-0 \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy the built executable from builder stage
COPY --from=builder /app/build/bin/betserver /app/betserver

# Expose the port
EXPOSE 8080

# Run the application
CMD ["./betserver"]
