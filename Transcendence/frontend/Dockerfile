# Step 1: Build frontend files
FROM node:18 AS build

WORKDIR /app

# Copy package.json and package-lock.json
COPY package*.json ./

# Clean npm cache
RUN npm cache clean --force

# Install dependencies
RUN npm install

# Copy all source code
COPY . .

# Build the project
RUN npm run build && echo "Build succeeded" || echo "Build failed"
RUN ls -l

CMD ["tail", "-f", "/dev/null"]
