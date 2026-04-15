import time
import grpc
from concurrent import futures

import greeter_pb2
import greeter_pb2_grpc


class GreeterServicer(greeter_pb2_grpc.GreeterServicer):
    def SayHello(self, request, context):
        print(f"[server] SayHello called with name='{request.name}'")
        return greeter_pb2.HelloReply(message=f"Hello, {request.name}!")

    def SayHelloStream(self, request, context):
        print(f"[server] SayHelloStream called with name='{request.name}'")
        for i in range(1, 6):
            yield greeter_pb2.HelloReply(message=f"Hello #{i}, {request.name}!")
            time.sleep(0.5)


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    greeter_pb2_grpc.add_GreeterServicer_to_server(GreeterServicer(), server)
    server.add_insecure_port("[::]:50051")
    server.start()
    print("[server] Listening on port 50051...")
    server.wait_for_termination()


if __name__ == "__main__":
    serve()
