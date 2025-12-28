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
- C++ compiler with C++17 support (GCC, Clang, or MSVC)
- Make
- Git
- OpenSSL development libraries

## Quick Start with Docker

The easiest way to run the betserver is using Docker:

```bash
# Build and start the server
docker-compose up --build

# Or run in detached mode
docker-compose up -d --build

# Stop the server
docker-compose down
```

The server will be available at `http://localhost:8080`

## Building Locally

### Ubuntu/Debian

Install dependencies:
```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake git libssl-dev
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

### Other Linux distributions

Install the equivalent packages for your distribution:
- build-essential (GCC/G++)
- cmake
- git
- openssl development libraries

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

- **vix.cpp**: Modern C++ web framework (automatically fetched by CMake)
- The project uses CMake's FetchContent to automatically download and build vix.cpp

## Development

The project uses CMake for build configuration. The CMakeLists.txt file:
- Automatically fetches vix.cpp from GitHub
- Sets up C++17 standard
- Links all required libraries
- Configures build output directories

## License

This project is open source and available for use.
