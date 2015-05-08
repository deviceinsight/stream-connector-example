SET(connector_SOURCES 
	Qt-Connector-Example.cpp 
	EventEmitter.cpp
	ConfigReader.cpp
	JsonUtil.cpp
	DatapointEmitter.cpp
	GeoPositionEmitter.cpp
	DummyReader.cpp
	)

SET(connector_HEADERS
	EventEmitter.h
	ConfigReader.h
	JsonUtil.h
	DatapointEmitter.h
	GeoPositionEmitter.h
	DummyReader.h
	)

qt4_automoc(${connector_SOURCES})
QT4_WRAP_CPP(connector_HEADERS_MOC ${connector_HEADERS})

add_executable(connector-qt-example ${connector_HEADERS_MOC} ${connector_SOURCES} )

SET(LIBRARIES 
	${QT_QTCORE_LIBRARY} 
	${QT_LIBRARIES}
	${QT_QTNETWORK_LIBRARY}
)

target_link_libraries(connector-qt-example ${LIBRARIES})
