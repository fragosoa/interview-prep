#!/bin/bash
# Run from the grpc_example/ directory
pip install grpcio grpcio-tools

python -m grpc_tools.protoc \
  -I. \
  --python_out=. \
  --grpc_python_out=. \
  greeter.proto

echo "Generated: greeter_pb2.py and greeter_pb2_grpc.py"
