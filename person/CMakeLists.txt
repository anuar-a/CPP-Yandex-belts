cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)  # ��������� C++ 17

find_package(Protobuf REQUIRED) # ������� ������� ���� � ����������� protoc � ���������� libprotobuf
include_directories(${Protobuf_INCLUDE_DIRS}) # ��������� � include path ���� � ���������� protobuf
include_directories(${CMAKE_CURRENT_BINARY_DIR}) # � ${CMAKE_CURRENT_BINARY_DIR} ����� �����, ��������������� ������������ proto�, ���� � ��� ���� �������� � include path

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS person.proto) # ����� ���� ����������� ��� ���� .proto-�����
add_executable(main main.cpp ${PROTO_SRCS} ${PROTO_HDRS}) # ����� ���� ����������� ��� ���� .cpp-�����, � ��� ����� � ��������������� protoc'��
target_link_libraries(main ${Protobuf_LIBRARIES}) # ��������� ��� ����������� ���� � ����������� libprotobuf 
