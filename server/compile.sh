thrift --gen py api.thrift
thrift --gen cpp api.thrift
mv gen-py/ gen_py/
rm -f gen-cpp/TaskService_server.skeleton.cpp
g++ -std=c++17 -I /usr/include/thrift main.cpp db.cpp gen-cpp/*.cpp -lthrift -o main -lmysqlcppconn
