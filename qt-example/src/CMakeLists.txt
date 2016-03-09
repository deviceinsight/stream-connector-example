SET(connector_SOURCES 
	Qt-Connector-Example.cpp 
	EventEmitter.cpp
	DatapointEmitter.cpp
	GeoPositionEmitter.cpp
	DummyReader.cpp
	util/JsonUtil.cpp
    CommunicationHandler.cpp
    Configuration.cpp
    CommandProcessor.cpp
	)

SET(connector_HEADERS
	EventEmitter.h
	DatapointEmitter.h
	GeoPositionEmitter.h
	DummyReader.h
	util/JsonUtil.h
    CommunicationHandler.h
    Configuration.h
    CommandProcessor.h
	)

qt4_automoc(${connector_SOURCES})
QT4_WRAP_CPP(connector_HEADERS_MOC ${connector_HEADERS})

add_executable(connector-qt-example ${connector_HEADERS_MOC} ${connector_SOURCES} )

SET(LIBRARIES 
	${QT_QTCORE_LIBRARY} 
	${QT_LIBRARIES}
	${QT_QTNETWORK_LIBRARY}
	${QJSON_LIB}
)

target_link_libraries(connector-qt-example ${LIBRARIES})
