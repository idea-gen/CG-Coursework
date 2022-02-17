cmake_minimum_required(VERSION 3.21)
project(cg_coursework)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME}_lib
        inc/mathematics.h
        src/visual/Camera.cpp
        inc/visual/Camera.h
        src/visual/FieldOfView.cpp
        inc/visual/FieldOfView.h
        inc/Model.cpp
        inc/Model.h
        src/visual/Viewport.cpp
        inc/visual/Viewport.h
        src/VertexShader.cpp
        inc/VertexShader.h
        src/Renderer.cpp
        inc/Renderer.h
        src/IPixelReceiver.cpp
        inc/IPixelReceiver.h
        src/Renderable.cpp
        inc/Renderable.h
        src/Vertex.cpp
        inc/Vertex.h
        src/Scene.cpp
        inc/Scene.h
        src/PrimitiveSpecification.cpp
        inc/PrimitiveSpecification.h
        src/Primitive.cpp
        inc/Primitive.h
        src/PrimitiveAssembler.cpp
        inc/PrimitiveAssembler.h
        src/Clipper.cpp
        inc/Clipper.h
        src/Rasterizer.cpp
        inc/Rasterizer.h
        src/Fragment.cpp
        inc/Fragment.h
        src/FragmentShader.cpp
        inc/FragmentShader.h
        inc/Color.cpp
        inc/Color.h
        src/DepthBuffer.cpp
        inc/DepthBuffer.h
        src/Transform/PositionTransform.cpp
        inc/transform/PositionTransform.h
        src/Transform/RotationTransform.cpp
        inc/transform/RotationTransform.h
        src/Transform/ScaleTransform.cpp
        inc/transform/ScaleTransform.h
        inc/transform/DirectionTransform.h
        src/visual/View.cpp
        inc/visual/View.h
        src/VertexAssembler.cpp
        inc/VertexAssembler.h
        src/VertexSpecification.cpp
        inc/VertexSpecification.h
        src/Modeller.cpp
        inc/Modeller.h src/BackfaceCuller.cpp inc/BackfaceCuller.h)

target_include_directories(${PROJECT_NAME}_lib PUBLIC inc)

add_library(${PROJECT_NAME}_gui
        src/gui/GuiRunner.cpp
        inc/gui/GuiRunner.h
        src/gui/MainWindow.cpp
        inc/gui/MainWindow.h
        src/gui/PixelReceiver.cpp
        inc/gui/PixelReceiver.h)

target_include_directories(${PROJECT_NAME}_gui PUBLIC inc)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

target_link_libraries(${PROJECT_NAME}_gui PUBLIC ${PROJECT_NAME}_lib)

target_link_libraries(${PROJECT_NAME}_gui PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets)

add_executable(cg_coursework src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC inc)

target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_NAME}_gui)
