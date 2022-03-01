cmake_minimum_required(VERSION 3.21)
project(cg_coursework)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_library(${PROJECT_NAME}_lib
        inc/mathematics.h
        src/visual/Camera.cpp
        inc/visual/Camera.h
        src/visual/FieldOfView.cpp
        inc/visual/FieldOfView.h
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
        src/Color.cpp
        inc/Color.h
        src/DepthBuffer.cpp
        inc/DepthBuffer.h
        src/transform/PositionTransform.cpp
        inc/transform/PositionTransform.h
        src/transform/RotationTransform.cpp
        inc/transform/RotationTransform.h
        src/transform/ScaleTransform.cpp
        inc/transform/ScaleTransform.h
        inc/transform/DirectionTransform.h
        src/visual/View.cpp
        inc/visual/View.h
        src/VertexAssembler.cpp
        inc/VertexAssembler.h
        src/VertexSpecification.cpp
        inc/VertexSpecification.h
        src/Modeller.cpp
        inc/Modeller.h src/BackfaceCuller.cpp inc/BackfaceCuller.h src/light/DirectionalLight.cpp inc/light/DirectionalLight.h src/light/PointLight.cpp inc/light/PointLight.h src/light/SpotLight.cpp inc/light/SpotLight.h src/Lights.cpp inc/Lights.h src/BarycentricCalculator.cpp inc/BarycentricCalculator.h src/Material.cpp inc/Material.h src/SceneEntity.cpp inc/SceneEntity.h src/gui/ConvolutionFilter.cpp inc/ConvolutionFilter.h src/MaterialLibrary.cpp inc/MaterialLibrary.h)

target_include_directories(${PROJECT_NAME}_lib PUBLIC inc)

add_library(${PROJECT_NAME}_gui
        src/gui/GuiRunner.cpp
        inc/gui/GuiRunner.h
        src/gui/MainWindow.cpp
        inc/gui/MainWindow.h
        src/gui/PixelReceiver.cpp
        inc/gui/PixelReceiver.h
        src/gui/MoveFrame.cpp
        inc/gui/MoveFrame.h
        src/gui/PanelLabeledFrame.cpp
        inc/gui/PanelLabeledFrame.h src/gui/RotateFrame.cpp inc/gui/RotateFrame.h src/gui/GraphicsView.cpp inc/gui/GraphicsView.h src/gui/ModelTransformFrame.cpp inc/gui/ModelTransformFrame.h src/gui/VectorEdit.cpp inc/gui/VectorEdit.h src/gui/SceneManager.cpp inc/gui/SceneManager.h src/gui/AddModel.cpp inc/gui/AddModel.h src/gui/EditModel.cpp inc/gui/EditModel.h src/gui/AddDirect.cpp inc/gui/AddDirect.h src/gui/EditDirect.cpp inc/gui/EditDirect.h src/gui/EditPoint.cpp inc/gui/EditPoint.h src/gui/AddPoint.cpp inc/gui/AddPoint.h src/gui/AddSpot.cpp inc/gui/AddSpot.h src/gui/EditSpot.cpp inc/gui/EditSpot.h)

target_include_directories(${PROJECT_NAME}_gui PUBLIC inc)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

target_link_libraries(${PROJECT_NAME}_gui PUBLIC ${PROJECT_NAME}_lib)

target_link_libraries(${PROJECT_NAME}_gui PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets)

add_executable(cg_coursework src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC inc)

target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_NAME}_gui)
