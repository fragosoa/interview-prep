import grpc

import greeter_pb2
import greeter_pb2_grpc


def run():
    with grpc.insecure_channel("localhost:50051") as channel:
        stub = greeter_pb2_grpc.GreeterStub(channel)

        # Unary RPC
        response = stub.SayHello(greeter_pb2.HelloRequest(name="World"))
        print(f"[client] Unary response: {response.message}")

        # Server-streaming RPC
        print("[client] Streaming responses:")
        for reply in stub.SayHelloStream(greeter_pb2.HelloRequest(name="World")):
            print(f"  {reply.message}")


if __name__ == "__main__":
    run()
