cmake_minimum_required(VERSION 2.8.12)
project(DICOM)

if(ITK_SOURCE_DIR)
  itk_module_impl()
else()
  find_package(ITK 4.10 REQUIRED)
  list(APPEND CMAKE_MODULE_PATH ${ITK_CMAKE_DIR})
  include(ITKModuleExternal)
endif()
