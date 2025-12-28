# Betserver

A simple betting server application built with C++ and vix.cpp framework.

## Features

- RESTful API for managing bets
- Built with vix.cpp web framework
- Containerized with Docker
- Easy deployment with docker-compose

## API Endpoints

- `GET /` - Health check
- `GET /api/bets` - Get all bets
- `POST /api/bets` - Create a new bet
- `GET /api/bets/:id` - Get bet by ID
- `PUT /api/bets/:id` - Update a bet
- `DELETE /api/bets/:id` - Delete a bet

## Prerequisites

### For Docker deployment:
- Docker
- Docker Compose

### For local development:
- CMake (>= 3.14)
- C++ compiler with C++20 support (GCC 10+, Clang 10+, or MSVC 2019+)
- Make
- Git
- OpenSSL development libraries

## Quick Start with Docker

The easiest way to run the betserver is using Docker:

```bash
# Build and start the server
docker compose up --build

# Or run in detached mode
docker compose up -d --build

# Stop the server
docker compose down
```

The server will be available at `http://localhost:8080`

## Building Locally

### Ubuntu 24.04 or later

Install dependencies:
```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake git libssl-dev \
    libboost-all-dev libspdlog-dev libsqlite3-dev nlohmann-json3-dev
```

Build the project:
```bash
mkdir build
cd build
cmake ..
make
```

Run the server:
```bash
./bin/betserver
```

### Ubuntu 22.04 or earlier

Note: Ubuntu 22.04 and earlier versions have Boost 1.74, but vix.cpp requires Boost >= 1.78. 
You will need to either:
1. Upgrade to Ubuntu 24.04 or later (recommended)
2. Build Boost from source
3. Use the Docker method which handles all dependencies automatically

### Other Linux distributions

Install the equivalent packages for your distribution:
- build-essential (GCC/G++)
- cmake (>= 3.14)
- git
- openssl development libraries
- boost development libraries (>= 1.78)
- spdlog development libraries
- sqlite3 development libraries
- nlohmann-json development libraries

Then follow the same build steps as above.

## Usage Examples

### Health Check
```bash
curl http://localhost:8080/
```

### Get All Bets
```bash
curl http://localhost:8080/api/bets
```

### Create a Bet
```bash
curl -X POST http://localhost:8080/api/bets \
  -H "Content-Type: application/json" \
  -d '{"amount": 100, "team": "TeamA"}'
```

### Get Bet by ID
```bash
curl http://localhost:8080/api/bets/1
```

### Update a Bet
```bash
curl -X PUT http://localhost:8080/api/bets/1 \
  -H "Content-Type: application/json" \
  -d '{"amount": 200, "team": "TeamB"}'
```

### Delete a Bet
```bash
curl -X DELETE http://localhost:8080/api/bets/1
```

## Project Structure

```
betserver/
├── main.cpp              # Main application file
├── CMakeLists.txt        # CMake build configuration
├── Dockerfile            # Docker image definition
├── docker-compose.yml    # Docker Compose configuration
├── .gitignore           # Git ignore rules
├── .dockerignore        # Docker ignore rules
└── README.md            # This file
```

## Dependencies

### Core Dependencies

- **vix.cpp**: Modern C++ web framework (automatically fetched by CMake from GitHub)
  - Version: latest from main branch
  - Repository: https://github.com/vixcpp/vix

### System Dependencies

The following system libraries are required:

- **Boost** (>= 1.78): Provides networking and filesystem functionality
  - Components: system, thread, filesystem
- **OpenSSL**: For SSL/TLS support
- **spdlog**: Fast C++ logging library (used by vix.cpp)
- **SQLite3**: For websocket message persistence (used by vix.cpp)
- **nlohmann-json**: JSON library for C++
- **libfmt**: Formatting library (used by spdlog)

All dependencies are automatically handled by the Docker build process.

## Development

The project uses CMake for build configuration. The CMakeLists.txt file:
- Automatically fetches vix.cpp from GitHub using FetchContent
- Sets up C++20 standard
- Links all required libraries
- Configures build output directories
- Disables optional vix.cpp features (ORM, examples) for faster builds

## License

This project is open source and available for use.
