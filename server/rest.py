from thrift.transport import TSocket, TTransport
from thrift.protocol import TBinaryProtocol
from gen_py.task_service import TaskService
from gen_py.task_service.ttypes import Task

import sys

transport = TSocket.TSocket('localhost', 9090)
transport = TTransport.TBufferedTransport(transport)
protocol = TBinaryProtocol.TBinaryProtocol(transport)
client = TaskService.Client(protocol)

transport.open()

print("Sending new task...")
new_task = Task(title=sys.argv[1], description=sys.argv[2])
client.addTask(new_task)

transport.close()

