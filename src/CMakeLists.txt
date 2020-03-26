INCLUDE_DIRECTORIES("${PROJECT_INCLUDE_DIR}")

SET(COMMON_SRCS 
	
	Esfera.cpp
	Plano.cpp
	Raqueta.cpp
	Vector2D.cpp
	Disparo.cpp
	Socket.cpp)
	
ADD_EXECUTABLE(cliente cliente.cpp MundoCliente.cpp ${COMMON_SRCS})
ADD_EXECUTABLE(servidor servidor.cpp MundoServidor.cpp ${COMMON_SRCS})
ADD_EXECUTABLE(logger logger.cpp)
ADD_EXECUTABLE(bot bot.cpp)

TARGET_LINK_LIBRARIES(cliente glut GL GLU)
TARGET_LINK_LIBRARIES(servidor glut GL GLU)
TARGET_LINK_LIBRARIES(bot glut GL GLU)
FIND_PACKAGE(Threads REQUIRED)
TARGET_LINK_LIBRARIES(servidor ${CMAKE_THREAD_LIBS_INIT})
